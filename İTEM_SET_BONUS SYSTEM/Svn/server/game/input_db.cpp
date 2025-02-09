//ara
	char szDragonSoulTableFileName[FILE_NAME_LEN];

//alt©¥na ekle
#if defined(__SET_ITEM__)
	char szSetItemTableFileName[FILE_NAME_LEN];
#endif

//ara
	snprintf(szDragonSoulTableFileName, sizeof(szDragonSoulTableFileName),
			"%s/dragon_soul_table.txt", LocaleService_GetBasePath().c_str());

//alt©¥na ekle
#if defined(__SET_ITEM__)
	snprintf(szSetItemTableFileName, sizeof(szSetItemTableFileName),
		"%s/set_item_table.txt", LocaleService_GetBasePath().c_str());
#endif
//ara
	sys_log(0, "LoadLocaleFile: DragonSoulTable: %s", szDragonSoulTableFileName);
	if (!DSManager::instance().ReadDragonSoulTableFile(szDragonSoulTableFileName))
	{
		sys_err("cannot load DragonSoulTable: %s", szDragonSoulTableFileName);
		//thecore_shutdown();
		//return;
	}
	// END_OF_LOCALE_SERVICE

//alt©¥na ekle
#if defined(__SET_ITEM__)
	sys_log(0, "LoadLocaleFile: SetItemTable: %s", szSetItemTableFileName);
	if (!ITEM_MANAGER::instance().LoadSetItemTable(szSetItemTableFileName))
	{
		sys_err("LoadLocaleFile: Cannot load SetItemTable: %s", szSetItemTableFileName);
		// thecore_shutdown();
		// return;
	}
#endif

//ara
void CInputDB::AffectLoad(LPDESC d, const char * c_pData)

//alt©¥nda bul
	ch->LoadAffect(dwCount, (TPacketAffectElement *) c_pData);


//alt©¥na ekle
#if defined(__SET_ITEM__)
	ch->RefreshItemSetBonus();
#endif