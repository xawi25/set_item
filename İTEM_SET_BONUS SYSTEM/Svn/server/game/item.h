//ara
		int			GetWindowInventoryEx();

//varsa eklemene gerek yok.
//altına ekle 
#if defined(__SET_ITEM__)
		bool IsUnique() { return GetType() == ITEM_UNIQUE; }
		bool IsCostume() { return GetType() == ITEM_COSTUME; }
#endif