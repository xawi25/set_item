//dosya sonuna ekle

#if defined(ENABLE_AUTO_SYSTEM) || defined(ENABLE_FLOWER_EVENT) || defined(ENABLE_SET_ITEM)
void CPythonPlayer::AddAffect(DWORD dwType, TPacketAffectElement elem)
{
	int iAffIndex = GetAffectDataIndex(dwType, elem.bPointIdxApplyOn);
	if (iAffIndex != -1)
		m_vecAffectData.at(iAffIndex) = elem;
	else
		m_vecAffectData.emplace_back(elem);
}

void CPythonPlayer::RemoveAffect(DWORD dwType, DWORD dwApplyOn)
{
	TAffectDataVector::iterator it = m_vecAffectData.begin();
	for (; it != m_vecAffectData.end(); ++it)
	{
		TPacketAffectElement elem = *it;
		if (elem.dwType == dwType && (dwApplyOn == 0 || dwApplyOn == elem.bPointIdxApplyOn))
		{
			m_vecAffectData.erase(it);
			break;
		}
	}
}

int CPythonPlayer::GetAffectDataIndex(DWORD dwType, DWORD dwApplyOn)
{
	int ret = -1, i = 0;
	TAffectDataVector::iterator it = m_vecAffectData.begin();
	for (; it != m_vecAffectData.end(); ++it, ++i)
	{
		TPacketAffectElement elem = *it;
		if (elem.dwType == dwType && (dwApplyOn == 0 || dwApplyOn == elem.bPointIdxApplyOn))
		{
			ret = i;
			break;
		}
	}
	return ret;
}

long CPythonPlayer::GetAffectDuration(DWORD dwType)
{
	TAffectDataVector::iterator it = m_vecAffectData.begin();
	for (; it != m_vecAffectData.end(); ++it)
	{
		TPacketAffectElement elem = *it;
		if (elem.dwType == dwType)
			return elem.lDuration;
	}
	return 0;
}

CPythonPlayer::TAffectDataVector CPythonPlayer::GetAffectDataVector(DWORD dwType)
{
	TAffectDataVector vAffect;
	TAffectDataVector::iterator it = m_vecAffectData.begin();
	for (; it != m_vecAffectData.end(); ++it)
	{
		const TPacketAffectElement elem = *it;
		if (elem.dwType == dwType)
			vAffect.push_back(elem);
	}
	return vAffect;
}
#endif