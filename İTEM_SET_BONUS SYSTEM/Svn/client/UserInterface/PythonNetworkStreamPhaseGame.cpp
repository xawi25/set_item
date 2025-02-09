//ara
bool CPythonNetworkStream::RecvAffectAddPacket()
{
	TPacketGCAffectAdd kAffectAdd;
	if (!Recv(sizeof(kAffectAdd), &kAffectAdd))
		return false;

	TPacketAffectElement & rkElement = kAffectAdd.elem;

//altına ekle
#if defined(ENABLE_SET_ITEM)
	CPythonPlayer::Instance().AddAffect(rkElement.dwType, kAffectAdd.elem);
#endif

//ara
bool CPythonNetworkStream::RecvAffectRemovePacket()
{
	TPacketGCAffectRemove kAffectRemove;
	if (!Recv(sizeof(kAffectRemove), &kAffectRemove))
		return false;


//altına ekle
#if defined(ENABLE_SET_ITEM)
	CPythonPlayer::instance().RemoveAffect(kAffectRemove.dwType, kAffectRemove.bApplyOn);
#endif