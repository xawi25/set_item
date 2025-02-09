//ara

	PyModule_AddIntConstant(poModule, "NEW_AFFECT_DRAGON_SOUL_DECK1",		CInstanceBase::NEW_AFFECT_DRAGON_SOUL_DECK1);
	PyModule_AddIntConstant(poModule, "NEW_AFFECT_DRAGON_SOUL_DECK2",		CInstanceBase::NEW_AFFECT_DRAGON_SOUL_DECK2);

//altına ekle

#if defined(ENABLE_SET_ITEM)
	PyModule_AddIntConstant(poModule, "NEW_AFFECT_SET_ITEM", CInstanceBase::NEW_AFFECT_SET_ITEM);
#endif