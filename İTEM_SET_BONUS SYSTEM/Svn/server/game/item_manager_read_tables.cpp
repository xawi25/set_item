//dosya sonuna ekle

#if defined(__SET_ITEM__)
bool ITEM_MANAGER::LoadSetItemTable(const char* szFileName)
{
	CTextFileLoader TextFileLoader;
	if (!TextFileLoader.Load(szFileName))
	{
		sys_err("LoadSetItemTable : Load file error %s", szFileName);
		return false;
	}

	m_ItemSetValueMap.clear();
	m_ItemSetItemMap.clear();

	std::string stNodeName = "";
	for (DWORD dwNodeIndex = 0; dwNodeIndex < TextFileLoader.GetChildNodeCount(); ++dwNodeIndex)
	{
		TextFileLoader.SetChildNode(dwNodeIndex);
		TextFileLoader.GetCurrentNodeName(&stNodeName);

		int iSetValue;
		if (!TextFileLoader.GetTokenInteger("set_value", &iSetValue))
		{
			sys_err("LoadSetItemTable : Syntax error in %s, Node %s : No `SET_VALUE`", szFileName, stNodeName.c_str());
			TextFileLoader.SetParentNode();
			continue;
		}

		ItemSetItemVnumVector vItemSetItemVnum;
		if (iSetValue >= 100)
		{
			TTokenVector* pToken = nullptr;
			if (TextFileLoader.GetTokenVector("set_item_costume_body", &pToken))
			{
				if (pToken->size() == 3)
					vItemSetItemVnum.push_back({ SET_ITEM_COSTUME_BODY, { atoi(pToken->at(0).c_str()), atoi(pToken->at(1).c_str()), atoi(pToken->at(2).c_str()) } });
				else
					sys_err("LoadSetItemTable : Syntax error in %s, Node %s : Incorrect set item `SET_ITEM_COSTUME_BODY` format, must contain min. max. and range values.",
						szFileName, stNodeName.c_str());
			}

			if (TextFileLoader.GetTokenVector("set_item_costume_hair", &pToken))
			{
				if (pToken->size() == 3)
					vItemSetItemVnum.push_back({ SET_ITEM_COSTUME_HAIR, { atoi(pToken->at(0).c_str()), atoi(pToken->at(1).c_str()), atoi(pToken->at(2).c_str()) } });
				else
					sys_err("LoadSetItemTable : Syntax error in %s, Node %s : Incorrect set item `SET_ITEM_COSTUME_HAIR` format, must contain min. max. and range values.",
						szFileName, stNodeName.c_str());
			}

			if (TextFileLoader.GetTokenVector("set_item_costume_mount", &pToken))
			{
				if (pToken->size() == 3)
					vItemSetItemVnum.push_back({ SET_ITEM_COSTUME_MOUNT, { atoi(pToken->at(0).c_str()), atoi(pToken->at(1).c_str()), atoi(pToken->at(2).c_str()) } });
				else
					sys_err("LoadSetItemTable : Syntax error in %s, Node %s : Incorrect `SET_ITEM_COSTUME_MOUNT` format, must contain min. max. and range values.",
						szFileName, stNodeName.c_str());
			}

			if (TextFileLoader.GetTokenVector("set_item_costume_acce", &pToken))
			{
				if (pToken->size() == 3)
					vItemSetItemVnum.push_back({ SET_ITEM_COSTUME_ACCE, { atoi(pToken->at(0).c_str()), atoi(pToken->at(1).c_str()), atoi(pToken->at(2).c_str()) } });
				else
					sys_err("LoadSetItemTable : Syntax error in %s, Node %s : Incorrect `SET_ITEM_COSTUME_ACCE` format, must contain min. max. and range values.",
						szFileName, stNodeName.c_str());
			}

			if (TextFileLoader.GetTokenVector("set_item_costume_weapon", &pToken))
			{
				if (pToken->size() == 3)
					vItemSetItemVnum.push_back({ SET_ITEM_COSTUME_WEAPON, { atoi(pToken->at(0).c_str()), atoi(pToken->at(1).c_str()), atoi(pToken->at(2).c_str()) } });
				else
					sys_err("LoadSetItemTable : Syntax error in %s, Node %s : Incorrect `SET_ITEM_COSTUME_WEAPON` format, must contain min. max. and range values.",
						szFileName, stNodeName.c_str());
			}

			if (TextFileLoader.GetTokenVector("set_item_unique", &pToken))
			{
				if (pToken->size() == 3)
					vItemSetItemVnum.push_back({ SET_ITEM_UNIQUE, { atoi(pToken->at(0).c_str()), atoi(pToken->at(1).c_str()), atoi(pToken->at(2).c_str()) } });
				else
					sys_err("LoadSetItemTable : Syntax error in %s, Node %s : Incorrect `SET_ITEM_UNIQUE` format, must contain min. max. and range values.",
						szFileName, stNodeName.c_str());
			}

			m_ItemSetItemMap.emplace(std::make_pair(iSetValue, vItemSetItemVnum));
		}

		ItemSetCountMap mItemSetCountMap;
		TTokenVector* pTokenVector = nullptr;
		for (int iRowIndex = 1; iRowIndex < 256; ++iRowIndex)
		{
			if (!TextFileLoader.GetTokenVector(std::to_string(iRowIndex), &pTokenVector))
				break;

			if (pTokenVector->size() != 3)
			{
				sys_err("LoadSetItemTable : Syntax error in %s, Node %s : Incorrect format, use `Index` `Count` `ApplyType` `ApplyValue`",
					szFileName, stNodeName.c_str());
				continue;
			}

			int iSetCount = 0, iApplyType = 0, iApplyValue = 0;
			str_to_number(iSetCount, pTokenVector->at(0).c_str());

			if (iSetCount == 0)
			{
				sys_err("LoadSetItemTable : Value error in %s, Node %s : Cannot set count value %d",
					szFileName, stNodeName.c_str(), iSetCount);
				continue;
			}

			if (!(iApplyType = FN_get_apply_type(pTokenVector->at(1).c_str())))
			{
				sys_err("LoadSetItemTable : ApplyType error in %s, Node %s : Cannot find ApplyType %s",
					szFileName, stNodeName.c_str(), pTokenVector->at(1).c_str());
				continue;
			}

			str_to_number(iApplyValue, pTokenVector->at(2).c_str());

			bool bApplyExists = false;
			for (auto& kApplyPair : mItemSetCountMap[iSetCount])
			{
				if (kApplyPair.first == iApplyType)
				{
					sys_log(0, "LoadSetItemTable : ApplyType warning in %s, Node %s : %s already exists.",
						szFileName, stNodeName.c_str(), pTokenVector->at(1).c_str());
					bApplyExists = true;
					break;
				}
			}

			if (!bApplyExists)
				mItemSetCountMap[iSetCount].push_back({ iApplyType, iApplyValue });
		}

		m_ItemSetValueMap.emplace(std::make_pair(iSetValue, mItemSetCountMap));
		TextFileLoader.SetParentNode();
	}

	return true;
}

const ITEM_MANAGER::ItemSetValueMap& ITEM_MANAGER::GetItemSetValueMap() const
{
	return m_ItemSetValueMap;
}

const ITEM_MANAGER::ItemSetItemMap& ITEM_MANAGER::GetItemSetItemMap() const
{
	return m_ItemSetItemMap;
}
#endif