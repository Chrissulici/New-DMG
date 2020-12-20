///search:
					ch->SetRandomHP((ch->GetLevel()-1) * number(JobInitialPoints[job].hp_per_lv_begin, JobInitialPoints[job].hp_per_lv_end));

///replace:
#ifdef ENABLE_DUEL_OPTIONS
					ch->SetRandomHP((ch->GetLevel()-1) * JobInitialPoints[job].hp_per_lv_end);
#else
					ch->SetRandomHP((ch->GetLevel()-1) * number(JobInitialPoints[job].hp_per_lv_begin, JobInitialPoints[job].hp_per_lv_end));
#endif

