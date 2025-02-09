//ara
void initPlayer()

//üstüne ekle
#if defined(ENABLE_SET_ITEM)
PyObject* playerGetSetItemEffect(PyObject* poSelf, PyObject* poArgs)
{
	int iAffectType;
	if (!PyTuple_GetInteger(poArgs, 0, &iAffectType))
		return Py_BadArgument();

	PyObject* poDict = PyDict_New();
	for (const auto& it : CPythonPlayer::Instance().GetAffectDataVector(iAffectType))
		PyDict_SetItem(poDict, Py_BuildValue("i", PointTypeToApplyType(it.bPointIdxApplyOn)), Py_BuildValue("i", it.lApplyValue));

	return Py_BuildValue("O", poDict);
}

PyObject* playerEmptySetItemEffect(PyObject* poSelf, PyObject* poArgs)
{
	int iAffectType;
	if (!PyTuple_GetInteger(poArgs, 0, &iAffectType))
		return Py_BadArgument();

	return Py_BuildValue("b", CPythonPlayer::Instance().GetAffectDataIndex(iAffectType, 0) == -1);
}
#endif

//ara
		{ NULL,							NULL,								NULL },

//üstüne ekle
#if defined(ENABLE_SET_ITEM)
		{ "GetSetItemEffect", playerGetSetItemEffect, METH_VARARGS },
		{ "EmptySetItemEffect", playerEmptySetItemEffect, METH_VARARGS },
#endif