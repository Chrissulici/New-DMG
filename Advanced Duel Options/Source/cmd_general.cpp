///search ACMD(do_pvp):
	char arg1[256];
	one_argument(argument, arg1, sizeof(arg1));
	DWORD vid = 0;
	str_to_number(vid, arg1);

///replace:
#ifdef ENABLE_DUEL_OPTIONS
	char arg1[256], arg2[256];
	two_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2));
	
	DWORD vid = 0;
	BYTE bIsSpecial = 0;
	str_to_number(vid, arg1);
	str_to_number(bIsSpecial, arg2);
#else
	char arg1[256];
	one_argument(argument, arg1, sizeof(arg1));
	DWORD vid = 0;
	str_to_number(vid, arg1);
#endif

///search ACMD(do_pvp):
	CPVPManager::instance().Insert(ch, pkVictim);

///replace:
#ifdef ENABLE_DUEL_OPTIONS
	CPVPManager::instance().Insert(ch, pkVictim, bIsSpecial ? true : false);
#else
	CPVPManager::instance().Insert(ch, pkVictim);
#endif

