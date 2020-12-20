///add at the end:
ACMD(do_boost)
{
	const char *line;
	char arg1[256], arg2[256], arg3[256], arg4[256], arg5[256], arg6[256];
	line = one_argument(two_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2)), arg3, sizeof(arg3));
	one_argument(two_arguments(line, arg4, sizeof(arg4), arg5, sizeof(arg5)), arg6, sizeof(arg6));

	if (!*arg1)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Usage: boost <type (set/get/reset)>");
		return;
	}
	
	std::string strArg1(arg1);
	std::string strArg2(arg2);
	std::string strArg3(arg3);
	std::string strArg4(arg4);
	
	int job = 0;
	str_to_number(job, arg5);
	
	int dmg = 0;
	str_to_number(dmg, arg6);

	if (!strArg1.compare(0, 3, "set"))
	{
		if (!*arg2 || !*arg3 || !*arg4 || !*arg5 || !*arg6)
		{
			ch->ChatPacket(CHAT_TYPE_INFO, "Usage: boost <type (set)> <type2 (hit/skill)> <type3 (pvp/pvm)> <race (war/ass/sura/sham) or (all)> <job (0/1)> <value>");
			return;
		}

		if (!strArg4.compare(0, 3, "war"))
		{
			if (!strArg3.compare(0, 3, "pvp"))
			{
				if (!strArg2.compare(0, 3, "hit"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_war_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_war_job1", dmg);
				}
				else if (!strArg2.compare(0, 5, "skill"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_war_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_war_job1", dmg);
				}
			}
			else if (!strArg3.compare(0, 3, "pvm"))
			{
				if (!strArg2.compare(0, 3, "hit"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_war_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_war_job1", dmg);
				}
				else if (!strArg2.compare(0, 5, "skill"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_war_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_war_job1", dmg);
				}
			}
		}
		else if (!strArg4.compare(0, 3, "ass"))
		{
			if (!strArg3.compare(0, 3, "pvp"))
			{
				if (!strArg2.compare(0, 3, "hit"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_ass_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_ass_job1", dmg);
				}
				else if (!strArg2.compare(0, 5, "skill"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_ass_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_ass_job1", dmg);
				}
			}
			else if (!strArg3.compare(0, 3, "pvm"))
			{
				if (!strArg2.compare(0, 3, "hit"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_ass_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_ass_job1", dmg);
				}
				else if (!strArg2.compare(0, 5, "skill"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_ass_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_ass_job1", dmg);
				}
			}
		}
		else if (!strArg4.compare(0, 4, "sura"))
		{
			if (!strArg3.compare(0, 3, "pvp"))
			{
				if (!strArg2.compare(0, 3, "hit"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sura_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sura_job1", dmg);
				}
				else if (!strArg2.compare(0, 5, "skill"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sura_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sura_job1", dmg);
				}
			}
			else if (!strArg3.compare(0, 3, "pvm"))
			{
				if (!strArg2.compare(0, 3, "hit"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sura_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sura_job1", dmg);
				}
				else if (!strArg2.compare(0, 5, "skill"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sura_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sura_job1", dmg);
				}
			}
		}
		else if (!strArg4.compare(0, 4, "sham"))
		{
			if (!strArg3.compare(0, 3, "pvp"))
			{
				if (!strArg2.compare(0, 3, "hit"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sham_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sham_job1", dmg);
				}
				else if (!strArg2.compare(0, 5, "skill"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sham_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sham_job1", dmg);
				}
			}
			else if (!strArg3.compare(0, 3, "pvm"))
			{
				if (!strArg2.compare(0, 3, "hit"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sham_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sham_job1", dmg);
				}
				else if (!strArg2.compare(0, 5, "skill"))
				{
					if (job == 0)
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sham_job0", dmg);
					else
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sham_job1", dmg);
				}
			}
		}
		else if (!strArg4.compare(0, 3, "all"))
		{
			if (!strArg3.compare(0, 3, "pvp"))
			{
				if (!strArg2.compare(0, 3, "hit"))
				{
					if (job == 0)
					{
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_war_job0", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_ass_job0", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sura_job0", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sham_job0", dmg);
					}
					else
					{
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_war_job1", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_ass_job1", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sura_job1", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sham_job1", dmg);
					}
				}
				else if (!strArg2.compare(0, 5, "skill"))
				{
					if (job == 0)
					{
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_war_job0", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_ass_job0", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sura_job0", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sham_job0", dmg);
					}
					else
					{
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_war_job1", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_ass_job1", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sura_job1", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sham_job1", dmg);
					}
				}
			}
			else if (!strArg3.compare(0, 3, "pvm"))
			{
				if (!strArg2.compare(0, 3, "hit"))
				{
					if (job == 0)
					{
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sham_job0", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sham_job0", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sham_job0", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sham_job0", dmg);
					}
					else
					{
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sham_job1", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sham_job1", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sham_job1", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sham_job1", dmg);
					}
				}
				else if (!strArg2.compare(0, 5, "skill"))
				{
					if (job == 0)
					{
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sham_job0", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sham_job0", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sham_job0", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sham_job0", dmg);
					}
					else
					{
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sham_job1", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sham_job1", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sham_job1", dmg);
						quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sham_job1", dmg);
					}
				}
			}
		}
		
		ch->ChatPacket(CHAT_TYPE_INFO, "You have successfully set the boost dmg %d in %s for %s, with race %s and job %d", dmg, arg3, arg2, arg4, job);
	}
	else if (!strArg1.compare(0, 3, "get"))
	{
		int getBoostHitPvpWarJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_war_job0");
		int getBoostHitPvpWarJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_war_job1");
		int getBoostSkillPvpWarJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_war_job0");
		int getBoostSkillPvpWarJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_war_job1");
		int getBoostHitPvmWarJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_war_job0");
		int getBoostHitPvmWarJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_war_job1");
		int getBoostSkillPvmWarJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_war_job0");
		int getBoostSkillPvmWarJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_war_job1");
		
		int getBoostHitPvpAssJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_ass_job0");
		int getBoostHitPvpAssJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_ass_job1");
		int getBoostSkillPvpAssJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_ass_job0");
		int getBoostSkillPvpAssJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_ass_job1");
		int getBoostHitPvmAssJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_ass_job0");
		int getBoostHitPvmAssJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_ass_job1");
		int getBoostSkillPvmAssJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_ass_job0");
		int getBoostSkillPvmAssJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_ass_job1");
		
		int getBoostHitPvpSuraJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_sura_job0");
		int getBoostHitPvpSuraJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_sura_job1");
		int getBoostSkillPvpSuraJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_sura_job0");
		int getBoostSkillPvpSuraJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_sura_job1");
		int getBoostHitPvmSuraJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_sura_job0");
		int getBoostHitPvmSuraJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_sura_job1");
		int getBoostSkillPvmSuraJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_sura_job0");
		int getBoostSkillPvmSuraJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_sura_job1");
		
		int getBoostHitPvpShamJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_sham_job0");
		int getBoostHitPvpShamJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvp_sham_job1");
		int getBoostSkillPvpShamJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_sham_job0");
		int getBoostSkillPvpShamJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvp_sham_job1");
		int getBoostHitPvmShamJob0 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_sham_job0");
		int getBoostHitPvmShamJob1 = quest::CQuestManager::instance().GetEventFlag("boost_hit_pvm_sham_job1");
		int getBoostSkillPvmShamJob0 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_sham_job0");
		int getBoostSkillPvmShamJob1 = quest::CQuestManager::instance().GetEventFlag("boost_skill_pvm_sham_job1");

		ch->ChatPacket(CHAT_TYPE_INFO, "Boost DMG: ");
		ch->ChatPacket(CHAT_TYPE_INFO, "");
		ch->ChatPacket(CHAT_TYPE_INFO, "***PVP***");
		ch->ChatPacket(CHAT_TYPE_INFO, "");
		ch->ChatPacket(CHAT_TYPE_INFO, "	*War ");
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job0: %d ", getBoostHitPvpWarJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job1: %d ", getBoostHitPvpWarJob1);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job0: %d ", getBoostSkillPvpWarJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job1: %d ", getBoostSkillPvpWarJob1);
		ch->ChatPacket(CHAT_TYPE_INFO, "");
		ch->ChatPacket(CHAT_TYPE_INFO, "	*Assassin ");
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job0: %d ", getBoostHitPvpAssJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job1: %d ", getBoostHitPvpAssJob1);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job0: %d ", getBoostSkillPvpAssJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job1: %d ", getBoostSkillPvpAssJob1);
		ch->ChatPacket(CHAT_TYPE_INFO, "");
		ch->ChatPacket(CHAT_TYPE_INFO, "	*Sura ");
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job0: %d ", getBoostHitPvpSuraJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job1: %d ", getBoostHitPvpSuraJob1);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job0: %d ", getBoostSkillPvpSuraJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job1: %d ", getBoostSkillPvpSuraJob1);
		ch->ChatPacket(CHAT_TYPE_INFO, "");
		ch->ChatPacket(CHAT_TYPE_INFO, "	*Shaman ");
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job0: %d ", getBoostHitPvpShamJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job1: %d ", getBoostHitPvpShamJob1);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job0: %d ", getBoostSkillPvpShamJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job1: %d ", getBoostSkillPvpShamJob1);
		ch->ChatPacket(CHAT_TYPE_INFO, "");
		ch->ChatPacket(CHAT_TYPE_INFO, "***PVM***");
		ch->ChatPacket(CHAT_TYPE_INFO, "");
		ch->ChatPacket(CHAT_TYPE_INFO, "	*War ");
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job0: %d ", getBoostHitPvmWarJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job1: %d ", getBoostHitPvmWarJob1);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job0: %d ", getBoostSkillPvmWarJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job1: %d ", getBoostSkillPvmWarJob1);
		ch->ChatPacket(CHAT_TYPE_INFO, "");
		ch->ChatPacket(CHAT_TYPE_INFO, "	*Assassin ");
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job0: %d ", getBoostHitPvmAssJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job1: %d ", getBoostHitPvmAssJob1);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job0: %d ", getBoostSkillPvmAssJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job1: %d ", getBoostSkillPvmAssJob1);
		ch->ChatPacket(CHAT_TYPE_INFO, "");
		ch->ChatPacket(CHAT_TYPE_INFO, "	*Sura ");
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job0: %d ", getBoostHitPvmSuraJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job1: %d ", getBoostHitPvmSuraJob1);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job0: %d ", getBoostSkillPvmSuraJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job1: %d ", getBoostSkillPvmSuraJob1);
		ch->ChatPacket(CHAT_TYPE_INFO, "");
		ch->ChatPacket(CHAT_TYPE_INFO, "	*Shaman ");
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job0: %d ", getBoostHitPvmShamJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		HIT		- Job1: %d ", getBoostHitPvmShamJob1);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job0: %d ", getBoostSkillPvmShamJob0);
		ch->ChatPacket(CHAT_TYPE_INFO, "		SKILL	- Job1: %d ", getBoostSkillPvmShamJob1);
	}
	else if (!strArg1.compare(0, 5, "reset"))
	{
		if (!*arg2)
		{
			ch->ChatPacket(CHAT_TYPE_INFO, "Usage: boost <type (reset)> <type2 (pvp/pvm/all)>");
			return;
		}

		if (!strArg2.compare(0, 3, "pvp"))
		{
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_war_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_ass_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sura_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sham_job0", 0);

			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_war_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_ass_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sura_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sham_job1", 0);

			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_war_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_ass_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sura_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sham_job0", 0);

			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_war_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_ass_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sura_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sham_job1", 0);
		}
		else if (!strArg2.compare(0, 3, "pvm"))
		{
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_war_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_ass_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sura_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sham_job0", 0);

			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_war_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_ass_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sura_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sham_job1", 0);

			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_war_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_ass_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sura_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sham_job0", 0);

			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_war_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_ass_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sura_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sham_job1", 0);
		}
		else if (!strArg2.compare(0, 3, "all"))
		{
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_war_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_ass_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sura_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sham_job0", 0);

			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_war_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_ass_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sura_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvp_sham_job1", 0);

			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_war_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_ass_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sura_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sham_job0", 0);

			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_war_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_ass_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sura_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvp_sham_job1", 0);

			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_war_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_ass_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sura_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sham_job0", 0);

			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_war_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_ass_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sura_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_hit_pvm_sham_job1", 0);

			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_war_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_ass_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sura_job0", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sham_job0", 0);

			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_war_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_ass_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sura_job1", 0);
			quest::CQuestManager::instance().RequestSetEventFlag("boost_skill_pvm_sham_job1", 0);
		}
		
		ch->ChatPacket(CHAT_TYPE_INFO, "You have successfully reset the boost dmg in %s", arg2);
	}
}

