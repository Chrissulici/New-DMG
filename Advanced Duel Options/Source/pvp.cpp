///search:
	m_bRevenge = false;

///add:
#ifdef ENABLE_DUEL_OPTIONS
	m_bIsSpecialDuel = 0;
#endif

///search:
	m_bRevenge = k.m_bRevenge;

///add:
#ifdef ENABLE_DUEL_OPTIONS
	m_bIsSpecialDuel = k.m_bIsSpecialDuel;
#endif

///search:
void CPVPManager::Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim)

///replace:
#ifdef ENABLE_DUEL_OPTIONS
void CPVPManager::Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim, bool bSpecialDuelStatus)
#else
void CPVPManager::Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim)
#endif

///search:
		if (pkPVP->Agree(pkChr->GetPlayerID()))
		{
			pkVictim->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("The duel with %s has begun!"), pkChr->GetName());
			pkChr->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("The duel with %s has begun!"), pkVictim->GetName());
		}
		return;

///replace:
		if (pkPVP->Agree(pkChr->GetPlayerID()))
		{
#ifdef ENABLE_DUEL_OPTIONS
			if (pkPVP->IsRevenge())
				pkPVP->SetSpecialDuelStatus(bSpecialDuelStatus);
			else
				bSpecialDuelStatus = pkPVP->IsSpecialDuel();
			
			if (bSpecialDuelStatus == true)
			{
				pkVictim->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("[Tactic] The duel with %s has begun! (without critical, penetrate, poision, fire, chance to avoid arrows, slowing, hp regen and miss)"), pkChr->GetName());
				pkChr->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("[Tactic] The duel with %s has begun! (without critical, penetrate, poision, fire, chance to avoid arrows, slowing, hp regen and miss)"), pkVictim->GetName());
			}
			else
			{
				pkVictim->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("[Normal] The duel with %s has begun!"), pkChr->GetName());
				pkChr->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("[Normal] The duel with %s has begun!"), pkVictim->GetName());
			}
#else
			pkVictim->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("The duel with %s has begun!"), pkChr->GetName());
			pkChr->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("The duel with %s has begun!"), pkVictim->GetName());
#endif
		}
		return;

///search:
	m_map_pkPVPSetByID[pkVictim->GetPlayerID()].insert(pkPVP);

///add:
#ifdef ENABLE_DUEL_OPTIONS
	pkPVP->SetSpecialDuelStatus(bSpecialDuelStatus);
#endif

///search:
	pkPVP->Packet();
	char msg[CHAT_MAX_LEN + 1];
	snprintf(msg, sizeof(msg), LC_TEXT("%s challenged you for a duel!"), pkChr->GetName());
	pkVictim->ChatPacket(CHAT_TYPE_INFO, msg);
	pkChr->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You challenged %s for a battle."), pkVictim->GetName());
	LPDESC pkVictimDesc = pkVictim->GetDesc();

///replace:
	pkPVP->Packet();
	char msg[CHAT_MAX_LEN + 1];
	
#ifdef ENABLE_DUEL_OPTIONS
	if(bSpecialDuelStatus == true)
		snprintf(msg, sizeof(msg), LC_TEXT("[Tactic] %s challenged you for a duel without critical, penetrate, poision, fire, chance to avoid arrows, slowing, hp regen and miss!"), pkChr->GetName());
	else
		snprintf(msg, sizeof(msg), LC_TEXT("[Normal] %s challenged you for a duel!"), pkChr->GetName());
#else
	snprintf(msg, sizeof(msg), LC_TEXT("%s challenged you for a duel!"), pkChr->GetName());
#endif

	pkVictim->ChatPacket(CHAT_TYPE_INFO, msg);
	pkChr->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You challenged %s for a battle."), pkVictim->GetName());
	LPDESC pkVictimDesc = pkVictim->GetDesc();


///search:
void CPVPManager::ConnectEx(LPCHARACTER pkChr, bool bDisconnect)

///add before:
#ifdef ENABLE_DUEL_OPTIONS
bool CPVPManager::IsSpecialDuel(LPCHARACTER pkChr, LPCHARACTER pkVictim)
{
	if(!pkChr || !pkVictim)
		return false;
	
	if (pkChr == pkVictim)
		return false;
	
	if (!pkChr->IsPC() || !pkVictim->IsPC())
		return false;
	
	CPVPSetMap::iterator it = m_map_pkPVPSetByID.find(pkChr->GetPlayerID());

	if (it == m_map_pkPVPSetByID.end())
		return false;

	bool isSpecialDuel = false;

	TR1_NS::unordered_set<CPVP*>::iterator itSecond = it->second.begin();

	while (itSecond != it->second.end())
	{
		CPVP * pkPVP = *itSecond++;

		DWORD dwCompanionPID = pkPVP->m_players[0].dwPID == pkChr->GetPlayerID() ? pkPVP->m_players[1].dwPID : pkPVP->m_players[0].dwPID;

		if (dwCompanionPID == pkVictim->GetPlayerID())
		{
			if (pkPVP->IsFight() && pkPVP->IsSpecialDuel())
			{
				isSpecialDuel = true;
				break;
			}
		}
	}

	return isSpecialDuel;
}
#endif

///add at the end:
bool CPVPManager::IsFightingSpecial(LPCHARACTER pkChr)
{
	if (!pkChr)
		return false;

	return IsFightingSpecial(pkChr->GetPlayerID());
}

bool CPVPManager::IsFightingSpecial(DWORD dwPID)
{
	CPVPSetMap::iterator it = m_map_pkPVPSetByID.find(dwPID);

	if (it == m_map_pkPVPSetByID.end())
		return false;

	TR1_NS::unordered_set<CPVP*>::iterator it2 = it->second.begin();

	while (it2 != it->second.end())
	{
		CPVP * pkPVP = *it2++;
		if (pkPVP->IsFight() && pkPVP->IsSpecialDuel())
			return true;
	}

	return false;
}

