///search:
		DWORD 	GetCRC() { return m_dwCRC; }

///add:
#ifdef ENABLE_DUEL_OPTIONS
		void	SetSpecialDuelStatus(bool bStatus) { m_bIsSpecialDuel = bStatus; }
		bool	IsSpecialDuel() { return m_bIsSpecialDuel; }
		bool	IsRevenge() { return m_bRevenge; }
#endif

///search:
		bool	m_bRevenge;

///add:
#ifdef ENABLE_DUEL_OPTIONS
		bool	m_bIsSpecialDuel;
#endif

///search:
		void			Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim);

///replace:
#ifdef ENABLE_DUEL_OPTIONS
		void			Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim, bool bSpecialDuelStatus);
		bool 			IsSpecialDuel(LPCHARACTER pkChr, LPCHARACTER pkVictim);
		bool			IsFightingSpecial(LPCHARACTER pkChr);
		bool			IsFightingSpecial(DWORD dwPID);
#else
		void			Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim);
#endif

