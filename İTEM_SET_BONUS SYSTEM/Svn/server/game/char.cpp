//ara
void CHARACTER::RestartAtSamePos()
{
	if (m_bIsObserver)
		return;

//alt©¥na ekle
#if defined(__SET_ITEM__)
	RefreshItemSetBonus();
#endif

//dosya sonuna ekle
#if defined(__SET_ITEM__)
void CHARACTER::RefreshItemSetBonus()
{
	RemoveAffect(AFFECT_SET_ITEM);

	bool bSetBonus = false;
	for (const auto& [bSetValue, vItems] : ITEM_MANAGER::Instance().GetItemSetItemMap())
	{
		BYTE bWearCount = 0;

		const auto& rkItemSetValueMap = ITEM_MANAGER::Instance().GetItemSetValueMap();
		if (rkItemSetValueMap.empty())
			break;

		const auto& ItemSetValueMap = rkItemSetValueMap.find(bSetValue);
		if (ItemSetValueMap == rkItemSetValueMap.end())
			continue;

		for (const auto& [bSetType, kItemTuple] : vItems)
		{
			LPITEM pItem = nullptr;
			LPITEM pUnique1 = nullptr;
			LPITEM pUnique2 = nullptr;

			switch (bSetType)
			{
				case SET_ITEM_COSTUME_BODY:
					pItem = GetWear(WEAR_COSTUME_BODY);
					break;

				case SET_ITEM_COSTUME_HAIR:
					pItem = GetWear(WEAR_COSTUME_HAIR);
					break;

				case SET_ITEM_COSTUME_MOUNT:
					pItem = GetWear(WEAR_COSTUME_MOUNT);
					break;

				case SET_ITEM_COSTUME_ACCE:
					pItem = GetWear(WEAR_COSTUME_ACCE);
					break;

				case SET_ITEM_COSTUME_WEAPON:
					pItem = GetWear(WEAR_COSTUME_WEAPON);
					break;

				case SET_ITEM_UNIQUE:
					pUnique1 = GetWear(WEAR_UNIQUE1);
					pUnique2 = GetWear(WEAR_UNIQUE2);
					break;
			}

			const auto& [dwMinVnum, dwMaxVnum, bRange] = kItemTuple;

			if (pUnique1 && CHECK_VNUM_RANGE(pUnique1->GetVnum(), dwMinVnum, dwMaxVnum, bRange))
				++bWearCount;

			if (pUnique2 && CHECK_VNUM_RANGE(pUnique2->GetVnum(), dwMinVnum, dwMaxVnum, bRange))
				++bWearCount;

			if (pItem && CHECK_VNUM_RANGE(pItem->GetVnum(), dwMinVnum, dwMaxVnum, bRange))
				++bWearCount;

			for (const auto& [bCount, vSetBonus] : ItemSetValueMap->second)
			{
				if (bWearCount != bCount)
				{
					bSetBonus = false;
					continue;
				}

				for (const auto& [wApplyType, lApplyValue] : vSetBonus)
				{
					AddAffect(AFFECT_SET_ITEM, aApplyInfo[wApplyType].bPointType, lApplyValue, 0, INFINITE_AFFECT_DURATION, 0, true, true);
					bSetBonus = true;
				}
			}
		}

		if (bSetBonus)
			break;
	}
}
#endif