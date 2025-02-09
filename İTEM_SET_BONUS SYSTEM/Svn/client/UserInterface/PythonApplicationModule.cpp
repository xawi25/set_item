//ara
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

//altına ekle
#if defined(ENABLE_SET_ITEM)
	PyModule_AddIntConstant(poModule, "ENABLE_SET_ITEM", true);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_SET_ITEM", false);
#endif