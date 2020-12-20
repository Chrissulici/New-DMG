///search:
					pAttacker->Damage(this, reflectDamage, DAMAGE_TYPE_SPECIAL);

///add before:
					int getBoostHitPvpWarJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_war_job0");
					int getBoostHitPvpWarJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_war_job1");
					
					int getBoostHitPvpAssJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_ass_job0");
					int getBoostHitPvpAssJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_ass_job1");
					
					int getBoostHitPvpSuraJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_sura_job0");
					int getBoostHitPvpSuraJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_sura_job1");
					
					int getBoostHitPvpShamJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_sham_job0");
					int getBoostHitPvpShamJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_sham_job1");
					
					if (getBoostHitPvpWarJob0 > 0)
						reflectDamage -= getBoostHitPvpWarJob0;
					else if (getBoostHitPvpWarJob1 > 0)
						reflectDamage -= getBoostHitPvpWarJob1;
					else if (getBoostHitPvpAssJob0 > 0)
						reflectDamage -= getBoostHitPvpAssJob0;
					else if (getBoostHitPvpAssJob1 > 0)
						reflectDamage -= getBoostHitPvpAssJob1;
					else if (getBoostHitPvpSuraJob0 > 0)
						reflectDamage -= getBoostHitPvpSuraJob0;
					else if (getBoostHitPvpSuraJob1 > 0)
						reflectDamage -= getBoostHitPvpSuraJob1;
					else if (getBoostHitPvpShamJob0 > 0)
						reflectDamage -= getBoostHitPvpShamJob0;
					else if (getBoostHitPvpShamJob1 > 0)
						reflectDamage -= getBoostHitPvpShamJob1;

///search:
	if (type == DAMAGE_TYPE_POISON)
	{
		if (GetHP() - dam <= 0)
			dam = GetHP() - 1;
	}

///add:
#ifdef ENABLE_DUEL_OPTIONS
	if (pAttacker && pAttacker->IsPC() && !CPVPManager::instance().IsSpecialDuel(pAttacker, this) && type != DAMAGE_TYPE_POISON && !IsMonster() && !IsStone())
#else
	if (pAttacker && pAttacker->IsPC() && type != DAMAGE_TYPE_POISON && !IsMonster() && !IsStone())
#endif
	{
		int getBoostHitPvpWarJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_war_job0");
		int getBoostHitPvpWarJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_war_job1");
		int getBoostSkillPvpWarJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_war_job0");
		int getBoostSkillPvpWarJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_war_job1");

		int getBoostHitPvpAssJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_ass_job0");
		int getBoostHitPvpAssJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_ass_job1");
		int getBoostSkillPvpAssJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_ass_job0");
		int getBoostSkillPvpAssJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_ass_job1");

		int getBoostHitPvpSuraJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_sura_job0");
		int getBoostHitPvpSuraJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_sura_job1");
		int getBoostSkillPvpSuraJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_sura_job0");
		int getBoostSkillPvpSuraJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_sura_job1");

		int getBoostHitPvpShamJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_sham_job0");
		int getBoostHitPvpShamJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_sham_job1");
		int getBoostSkillPvpShamJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_sham_job0");
		int getBoostSkillPvpShamJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_sham_job1");

		if (type == DAMAGE_TYPE_MELEE || type == DAMAGE_TYPE_RANGE || type == DAMAGE_TYPE_MAGIC)
		{
			if (pAttacker->GetSkillGroup() == 1)
			{
				if (pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_M || pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_W)
					dam += getBoostSkillPvpWarJob0;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_W || pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_M)
					dam += getBoostSkillPvpAssJob0;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SURA_M || pAttacker->GetRaceNum() == MAIN_RACE_SURA_W)
					dam += getBoostSkillPvpSuraJob0;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_W || pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_M)
					dam += getBoostSkillPvpShamJob0;
			}
			else if (pAttacker->GetSkillGroup() == 2)
			{
				if (pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_M || pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_W)
					dam += getBoostSkillPvpWarJob1;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_W || pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_M)
					dam += getBoostSkillPvpAssJob1;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SURA_M || pAttacker->GetRaceNum() == MAIN_RACE_SURA_W)
					dam += getBoostSkillPvpSuraJob1;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_W || pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_M)
					dam += getBoostSkillPvpShamJob1;
			}
		}
		else
		{
			if (pAttacker->GetSkillGroup() == 1)
			{
				if (pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_M || pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_W)
					dam += getBoostHitPvpWarJob0;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_W || pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_M)
					dam += getBoostHitPvpAssJob0;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SURA_M || pAttacker->GetRaceNum() == MAIN_RACE_SURA_W)
					dam += getBoostHitPvpSuraJob0;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_W || pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_M)
					dam += getBoostHitPvpShamJob0;
			}
			else if (pAttacker->GetSkillGroup() == 2)
			{
				if (pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_M || pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_W)
					dam += getBoostHitPvpWarJob1;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_W || pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_M)
					dam += getBoostHitPvpAssJob1;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SURA_M || pAttacker->GetRaceNum() == MAIN_RACE_SURA_W)
					dam += getBoostHitPvpSuraJob1;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_W || pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_M)
					dam += getBoostHitPvpShamJob1;
			}
		}
	}
	else if (pAttacker && (IsMonster() || IsStone()) && type != DAMAGE_TYPE_POISON)
	{
		int getBoostHitPvmWarJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_war_job0");
		int getBoostHitPvmWarJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_war_job1");
		int getBoostSkillPvmWarJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_war_job0");
		int getBoostSkillPvmWarJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_war_job1");
		
		int getBoostHitPvmAssJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_ass_job0");
		int getBoostHitPvmAssJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_ass_job1");
		int getBoostSkillPvmAssJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_ass_job0");
		int getBoostSkillPvmAssJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_ass_job1");
		
		int getBoostHitPvmSuraJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_sura_job0");
		int getBoostHitPvmSuraJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_sura_job1");
		int getBoostSkillPvmSuraJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_sura_job0");
		int getBoostSkillPvmSuraJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_sura_job1");
		
		int getBoostHitPvmShamJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_sham_job0");
		int getBoostHitPvmShamJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_sham_job1");
		int getBoostSkillPvmShamJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_sham_job0");
		int getBoostSkillPvmShamJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_sham_job1");
		
		if (type == DAMAGE_TYPE_MELEE || type == DAMAGE_TYPE_RANGE || type == DAMAGE_TYPE_MAGIC)
		{
			if (pAttacker->GetSkillGroup() == 1)
			{
				if (pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_M || pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_W)
					dam += getBoostSkillPvmWarJob0;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_W || pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_M)
					dam += getBoostSkillPvmAssJob0;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SURA_M || pAttacker->GetRaceNum() == MAIN_RACE_SURA_W)
					dam += getBoostSkillPvmSuraJob0;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_W || pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_M)
					dam += getBoostSkillPvmShamJob0;
			}
			else if (pAttacker->GetSkillGroup() == 2)
			{
				if (pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_M || pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_W)
					dam += getBoostSkillPvmWarJob1;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_W || pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_M)
					dam += getBoostSkillPvmAssJob1;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SURA_M || pAttacker->GetRaceNum() == MAIN_RACE_SURA_W)
					dam += getBoostSkillPvmSuraJob1;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_W || pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_M)
					dam += getBoostSkillPvmShamJob1;
			}
		}
		else
		{
			if (pAttacker->GetSkillGroup() == 1)
			{
				if (pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_M || pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_W)
					dam += getBoostHitPvmWarJob0;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_W || pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_M)
					dam += getBoostHitPvmAssJob0;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SURA_M || pAttacker->GetRaceNum() == MAIN_RACE_SURA_W)
					dam += getBoostHitPvmSuraJob0;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_W || pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_M)
					dam += getBoostHitPvmShamJob0;
			}
			else if (pAttacker->GetSkillGroup() == 2)
			{
				if (pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_M || pAttacker->GetRaceNum() == MAIN_RACE_WARRIOR_W)
					dam += getBoostHitPvmWarJob1;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_W || pAttacker->GetRaceNum() == MAIN_RACE_ASSASSIN_M)
					dam += getBoostHitPvmAssJob1;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SURA_M || pAttacker->GetRaceNum() == MAIN_RACE_SURA_W)
					dam += getBoostHitPvmSuraJob1;
				else if (pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_W || pAttacker->GetRaceNum() == MAIN_RACE_SHAMAN_M)
					dam += getBoostHitPvmShamJob1;
			}
		}
	}