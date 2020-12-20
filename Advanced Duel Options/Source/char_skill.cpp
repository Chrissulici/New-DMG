///search:
				if (IS_SET(m_pkSk->dwFlag, SKILL_FLAG_STUN))

///replace:
				if (IS_SET(m_pkSk->dwFlag, SKILL_FLAG_STUN)
#ifdef ENABLE_DUEL_OPTIONS
					&& !CPVPManager::instance().IsSpecialDuel(m_pkChr, pkChrVictim)
#endif	
				)

///search:
				else if (IS_SET(m_pkSk->dwFlag, SKILL_FLAG_SLOW)
#ifdef ENABLE_DUEL_OPTIONS
					&& !CPVPManager::instance().IsSpecialDuel(m_pkChr, pkChrVictim)
#endif
				)

///replace:
				else if (IS_SET(m_pkSk->dwFlag, SKILL_FLAG_SLOW))

