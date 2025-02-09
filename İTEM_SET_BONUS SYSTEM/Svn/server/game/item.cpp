//ara
bool CItem::EquipTo(LPCHARACTER ch, BYTE bWearCell)

//alt©¥nda bul
	ch->BuffOnAttr_AddBuffsFromItem(this);

//alt©¥na ekle
#if defined(__SET_ITEM__)
	if (IsCostume() || IsUnique())
		m_pOwner->RefreshItemSetBonus();
#endif


//ara
bool CItem::Unequip()

//alt©¥nda bul
	m_pOwner->SetImmuneFlag(dwImmuneFlag);

//alt©¥na ekle
#if defined(__SET_ITEM__)
	if (IsCostume() || IsUnique())
		m_pOwner->RefreshItemSetBonus();
#endif