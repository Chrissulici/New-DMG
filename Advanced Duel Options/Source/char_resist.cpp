///search:
void CHARACTER::AttackedByFire(LPCHARACTER pkAttacker, int amount, int count)
{
	if (m_pkFireEvent)
		return;

///add:
#ifdef ENABLE_DUEL_OPTIONS
	if (CPVPManager::instance().IsSpecialDuel(pkAttacker, this))
		return;
#endif

///search:
void CHARACTER::AttackedByPoison(LPCHARACTER pkAttacker)
{
	if (m_pkPoisonEvent)
		return;

///add:
#ifdef ENABLE_DUEL_OPTIONS
	if (CPVPManager::instance().IsSpecialDuel(pkAttacker, this))
		return;
#endif

