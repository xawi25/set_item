//ara
void ITEM_MANAGER::Destroy()

//alt�na bul
	m_VIDMap.clear();

//alt�na ekle
#if defined(__SET_ITEM__)
	m_ItemSetValueMap.clear();
	m_ItemSetItemMap.clear();
#endif