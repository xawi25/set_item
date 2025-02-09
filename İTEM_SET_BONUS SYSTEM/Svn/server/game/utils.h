//include ların altına ekle 
//varsa eklemene gerek yok.

#if defined(__SET_ITEM__)
#define CHECK_VNUM_RANGE(vnum, min, max, range) \
	(range ? \
		((max > 0 && (vnum >= min && vnum <= max)) || \
		(max == 0 && vnum == min)) \
	: \
		((max > 0 && (vnum == min || vnum == max)) || \
		(max == 0 && vnum == min)))
#endif