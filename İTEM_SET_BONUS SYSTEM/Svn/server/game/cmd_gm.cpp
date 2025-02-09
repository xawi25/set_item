//ara

ACMD(do_reload)
{
	char arg1[256];
	one_argument(argument, arg1, sizeof(arg1));

	if (*arg1)
	{


//de?i?tir
ACMD(do_reload)
{
	char arg1[256];
	one_argument(argument, arg1, sizeof(arg1));
#if defined(__SET_ITEM__)
	const int FILE_NAME_LEN = 256;
#endif
	if (*arg1)
	{
#if defined(__SET_ITEM__)
		if (strstr(arg1, "set_item"))
		{
			char szSetItemTableFileName[FILE_NAME_LEN];
			snprintf(szSetItemTableFileName, sizeof(szSetItemTableFileName),
				"%s/set_item_table.txt", LocaleService_GetBasePath().c_str());
			if (ITEM_MANAGER::instance().LoadSetItemTable(szSetItemTableFileName))
				ch->ChatPacket(CHAT_TYPE_INFO, "Reloading SetItemTable.");
			else
				ch->ChatPacket(CHAT_TYPE_INFO, "Cannot reload SetItemTable.");
			return;
		}
#endif