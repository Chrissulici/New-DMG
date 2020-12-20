///search:
	*pdamMax = pkItem->GetValue(4);

///replace:
#ifdef ENABLE_NEW_DMG
	*pdamMax = pkItem->GetValue(3);
#else
	*pdamMax = pkItem->GetValue(4);
#endif

///search:
	if (pWeapon)
		iAtk += pWeapon->GetValue(5) * 2;

///replace:
#ifndef ENABLE_NEW_DMG
	if (pWeapon)
		iAtk += pWeapon->GetValue(5) * 2;
#endif

///search:
	int iPercent = 100 - (iGap * 5);

///replace:
#ifdef ENABLE_NEW_DMG
	int iPercent = 100 - (iGap * 2);
#else
	int iPercent = 100 - (iGap * 5);
#endif

///search:
	iDam = number(pkBow->GetValue(3), pkBow->GetValue(4)) * 2 + pkArrow->GetValue(3);

///replace:
#ifdef ENABLE_NEW_DMG
	iDam = pkBow->GetValue(3) * 2 + pkArrow->GetValue(3);
#else
	iDam = number(pkBow->GetValue(3), pkBow->GetValue(4)) * 2 + pkArrow->GetValue(3);
#endif

///search:
	iAtk += pkBow->GetValue(5) * 2;

///replace:
#ifndef ENABLE_NEW_DMG
	iAtk += pkBow->GetValue(5) * 2;
#endif

