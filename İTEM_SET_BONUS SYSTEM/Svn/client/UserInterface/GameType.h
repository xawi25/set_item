//ara
void SetGuildSymbolPath(const char * c_szPathName);
const char * GetGuildSymbolFileName(DWORD dwGuildID);
BYTE SlotTypeToInvenType(BYTE bSlotType);
//altına ekle
#if defined(ENABLE_SET_ITEM)
BYTE ApplyTypeToPointType(BYTE bApplyType);
BYTE PointTypeToApplyType(BYTE bPointType);
#endif