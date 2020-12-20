///search:
	iPureDam = (iPureDam * iPercent) / 100;

///add:
#ifdef ENABLE_DUEL_OPTIONS
	if (CPVPManager::instance().IsSpecialDuel(pkAttacker, pkVictim))
		iPureDam = (iPureDam * 100) / 100;
	else
		iPureDam = (iPureDam * iPercent) / 100;
#else
	iPureDam = (iPureDam * iPercent) / 100;
#endif

///search:
	AttackAffect(pkAttacker, pkVictim, POINT_STUN_PCT, IMMUNE_STUN,  AFFECT_STUN, POINT_NONE,        0, AFF_STUN, iStunDuration, "STUN");
	AttackAffect(pkAttacker, pkVictim, POINT_SLOW_PCT, IMMUNE_SLOW,  AFFECT_SLOW, POINT_MOV_SPEED, -30, AFF_SLOW, 20,		"SLOW");

///replace:
#ifdef ENABLE_DUEL_OPTIONS
	if (!CPVPManager::instance().IsSpecialDuel(pkAttacker, pkVictim))
#endif
	{
		AttackAffect(pkAttacker, pkVictim, POINT_STUN_PCT, IMMUNE_STUN,  AFFECT_STUN, POINT_NONE,        0, AFF_STUN, iStunDuration, "STUN");
		AttackAffect(pkAttacker, pkVictim, POINT_SLOW_PCT, IMMUNE_SLOW,  AFFECT_SLOW, POINT_MOV_SPEED, -30, AFF_SLOW, 20,		"SLOW");
	}

