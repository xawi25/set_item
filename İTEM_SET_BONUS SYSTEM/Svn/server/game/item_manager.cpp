//ara
void ITEM_MANAGER::Destroy()

//altýna bul
	m_VIDMap.clear();

//altýna ekle
#if defined(__SET_ITEM__)
	m_ItemSetValueMap.clear();
	m_ItemSetItemMap.clear();
#endif