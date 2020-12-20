///search:
					if (number(1, 100) <= iCriticalPct)

///replace x2:
#ifdef ENABLE_DUEL_OPTIONS
					if (number(1, 100) <= iCriticalPct && !CPVPManager::instance().IsSpecialDuel(pAttacker, this))
#else
					if (number(1, 100) <= iCriticalPct)
#endif

///search:
				if (number(1, 100) <= iPenetratePct)

///replace x2:
#ifdef ENABLE_DUEL_OPTIONS
				if (number(1, 100) <= iPenetratePct && !CPVPManager::instance().IsSpecialDuel(pAttacker, this))
#else
				if (number(1, 100) <= iPenetratePct)
#endif

///search:
			if (GetPoint(POINT_BLOCK) && number(1, 100) <= GetPoint(POINT_BLOCK))

///replace:
#ifdef ENABLE_DUEL_OPTIONS
			if (GetPoint(POINT_BLOCK) && number(1, 100) <= GetPoint(POINT_BLOCK) && !CPVPManager::instance().IsSpecialDuel(pAttacker, this))
#else
			if (GetPoint(POINT_BLOCK) && number(1, 100) <= GetPoint(POINT_BLOCK))
#endif

///search:
			if (GetPoint(POINT_DODGE) && number(1, 100) <= GetPoint(POINT_DODGE))

///replace:
#ifdef ENABLE_DUEL_OPTIONS
			if (GetPoint(POINT_DODGE) && number(1, 100) <= GetPoint(POINT_DODGE) && !CPVPManager::instance().IsSpecialDuel(pAttacker, this))
#else
			if (GetPoint(POINT_DODGE) && number(1, 100) <= GetPoint(POINT_DODGE))
#endif

///search:
			if (pAttacker->GetPoint(POINT_HIT_HP_RECOVERY) && number(0, 4) > 0)

///replace:
#ifdef ENABLE_DUEL_OPTIONS
			if (pAttacker->GetPoint(POINT_HIT_HP_RECOVERY) && number(0, 4) > 0 && !CPVPManager::instance().IsSpecialDuel(pAttacker, this))
#else
			if (pAttacker->GetPoint(POINT_HIT_HP_RECOVERY) && number(0, 4) > 0)
#endif

///search:
			dam = dam * (100 - MIN(99, GetPoint(POINT_NORMAL_HIT_DEFEND_BONUS))) / 100;

///replace:
#ifdef ENABLE_DUEL_OPTIONS
			if (!CPVPManager::instance().IsSpecialDuel(pAttacker, this))
				dam = dam * (100 - MIN(99, GetPoint(POINT_NORMAL_HIT_DEFEND_BONUS))) / 100;
			else
				dam = dam * (100 - GetPoint(POINT_NORMAL_HIT_DEFEND_BONUS)) / 100;
#else
			dam = dam * (100 - MIN(99, GetPoint(POINT_NORMAL_HIT_DEFEND_BONUS))) / 100;
#endif

///search:
			dam = dam * (100 - MIN(99, GetPoint(POINT_SKILL_DEFEND_BONUS))) / 100;

///replace:
#ifdef ENABLE_DUEL_OPTIONS
			if (!CPVPManager::instance().IsSpecialDuel(pAttacker, this))
				dam = dam * (100 - MIN(99, GetPoint(POINT_SKILL_DEFEND_BONUS))) / 100;
			else
				dam = dam * (100 - GetPoint(POINT_NORMAL_HIT_DEFEND_BONUS)) / 100;
#else
			dam = dam * (100 - MIN(99, GetPoint(POINT_SKILL_DEFEND_BONUS))) / 100;
#endif

