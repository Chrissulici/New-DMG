///search:
			int iWep = number(pkWeapon->GetValue(3), pkWeapon->GetValue(4));
			iWep += pkWeapon->GetValue(5);
		
			int iMtk = number(pkWeapon->GetValue(1), pkWeapon->GetValue(2));
			iMtk += pkWeapon->GetValue(5);

///replace:
#ifdef ENABLE_NEW_DMG
			int iWep = pkWeapon->GetValue(3);
			int iMtk = pkWeapon->GetValue(1);
#else
			int iWep = number(pkWeapon->GetValue(3), pkWeapon->GetValue(4));
			iWep += pkWeapon->GetValue(5);
		
			int iMtk = number(pkWeapon->GetValue(1), pkWeapon->GetValue(2));
			iMtk += pkWeapon->GetValue(5);
#endif

///search:
			if (fDelta < 35.0f)
			{
				adjust = 1.5f;

				if (bUnderEunhyung)
					adjust += 0.5f;

				if (m_pkChr->GetWear(WEAR_WEAPON) && m_pkChr->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)
					adjust += 0.5f;
			}
			else

///replace:
#ifndef ENABLE_NEW_DMG
			if (fDelta < 35.0f)
			{
				adjust = 1.5f;

				if (bUnderEunhyung)
					adjust += 0.5f;

				if (m_pkChr->GetWear(WEAR_WEAPON) && m_pkChr->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)
					adjust += 0.5f;
			}
			else
#endif

///search:
				if (bUnderEunhyung)
					adjust += 0.5f;

				if (m_pkChr->GetWear(WEAR_WEAPON) && m_pkChr->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)
					adjust += 0.5f;

///replace:
#ifndef ENABLE_NEW_DMG
				if (bUnderEunhyung)
					adjust += 0.5f;

				if (m_pkChr->GetWear(WEAR_WEAPON) && m_pkChr->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)
					adjust += 0.5f;
#endif

