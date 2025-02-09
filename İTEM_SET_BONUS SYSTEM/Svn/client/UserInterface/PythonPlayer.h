//ara
		SAutoPotionInfo			m_kAutoPotionInfo[AUTO_POTION_TYPE_NUM];

	protected:
		float					MOVABLE_GROUND_DISTANCE;

	private:
		std::map<DWORD, DWORD> m_kMap_dwAffectIndexToSkillIndex;

//altına ekle
#if defined(ENABLE_SET_ITEM)
	public:
		void AddAffect(DWORD dwType, TPacketAffectElement elem);
		void RemoveAffect(DWORD dwType, DWORD dwApplyOn);

		int GetAffectDataIndex(DWORD dwType, DWORD dwApplyOn);
		long GetAffectDuration(DWORD dwType);

		using TAffectDataVector = std::vector<TPacketAffectElement>;
		TAffectDataVector GetAffectDataVector(DWORD dwType);

	protected:
		TAffectDataVector m_vecAffectData;
#endif