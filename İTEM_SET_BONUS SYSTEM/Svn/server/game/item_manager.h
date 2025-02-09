//ara
	protected:
		int                     RealNumber(DWORD vnum);

//üstüne ekle
#if defined(__SET_ITEM__)
	public:
		bool LoadSetItemTable(const char* szFileName);

		using ItemSetApplyVector = std::vector<std::pair<WORD, long>>;
		using ItemSetCountMap = std::unordered_map<BYTE, ItemSetApplyVector>;

		using ItemSetValueMap = std::unordered_map<BYTE, ItemSetCountMap>;

		using ItemSetItemVnumVector = std::vector<std::pair<BYTE, std::tuple<DWORD, DWORD, bool>>>;
		using ItemSetItemMap = std::unordered_map<BYTE, ItemSetItemVnumVector>;

		const ItemSetValueMap& GetItemSetValueMap() const;
		const ItemSetItemMap& GetItemSetItemMap() const;

	protected:
		ItemSetValueMap m_ItemSetValueMap;
		ItemSetItemMap m_ItemSetItemMap;
#endif