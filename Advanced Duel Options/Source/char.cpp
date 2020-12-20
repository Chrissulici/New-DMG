///search:
		ch->PointChange(POINT_HP, iAmount, false);

///replace:
#ifdef ENABLE_DUEL_OPTIONS
		if (!CPVPManager::instance().IsFightingSpecial(ch->GetPlayerID()))
#endif
			ch->PointChange(POINT_HP, iAmount, false);

