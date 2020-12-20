/*
 Navicat Premium Data Transfer

 Source Server         : Ysera2 - vps
 Source Server Type    : MySQL
 Source Server Version : 50533
 Source Host           : 188.212.103.105:3306
 Source Schema         : player

 Target Server Type    : MySQL
 Target Server Version : 50533
 File Encoding         : 65001

 Date: 21/12/2020 00:15:30
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for skill_proto
-- ----------------------------
DROP TABLE IF EXISTS `skill_proto`;
CREATE TABLE `skill_proto`  (
  `dwVnum` int(11) NOT NULL DEFAULT 0,
  `szName` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `bType` tinyint(4) NOT NULL DEFAULT 0,
  `bLevelStep` tinyint(4) NOT NULL DEFAULT 0,
  `bMaxLevel` tinyint(4) NOT NULL DEFAULT 0,
  `bLevelLimit` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `szPointOn` enum('NONE','MAX_HP','MAX_SP','HP_REGEN','SP_REGEN','BLOCK','HP','SP','ATT_GRADE','DEF_GRADE','MAGIC_ATT_GRADE','MAGIC_DEF_GRADE','BOW_DISTANCE','MOV_SPEED','ATT_SPEED','POISON_PCT','RESIST_RANGE','RESIST_MELEE','CASTING_SPEED','REFLECT_MELEE','ATT_BONUS','DEF_BONUS','RESIST_NORMAL','DODGE','KILL_HP_RECOVER','KILL_SP_RECOVER','HIT_HP_RECOVER','HIT_SP_RECOVER','CRITICAL','MANASHIELD','SKILL_DAMAGE_BONUS','NORMAL_HIT_DAMAGE_BONUS') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'NONE',
  `szPointPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szSPCostPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szDurationPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szDurationSPCostPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szCooldownPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szMasterBonusPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szAttackGradePoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `setFlag` set('ATTACK','USE_MELEE_DAMAGE','COMPUTE_ATTGRADE','SELFONLY','USE_MAGIC_DAMAGE','USE_HP_AS_COST','COMPUTE_MAGIC_DAMAGE','SPLASH','GIVE_PENALTY','USE_ARROW_DAMAGE','PENETRATE','IGNORE_TARGET_RATING','ATTACK_SLOW','ATTACK_STUN','HP_ABSORB','SP_ABSORB','ATTACK_FIRE_CONT','REMOVE_BAD_AFFECT','REMOVE_GOOD_AFFECT','CRUSH','ATTACK_POISON','TOGGLE','DISABLE_BY_POINT_UP','CRUSH_LONG','ATTACK_WIND','ATTACK_ELEC','ATTACK_FIRE','PARTY') CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT '',
  `setAffectFlag` enum('YMIR','INVISIBILITY','SPAWN','POISON','SLOW','STUN','DUNGEON_READY','DUNGEON_UNIQUE','BUILDING_CONSTRUCTION_SMALL','BUILDING_CONSTRUCTION_LARGE','BUILDING_UPGRADE','MOV_SPEED_POTION','ATT_SPEED_POTION','FISH_MIND','JEONGWIHON','GEOMGYEONG','CHEONGEUN','GYEONGGONG','EUNHYUNG','GWIGUM','TERROR','JUMAGAP','HOSIN','BOHO','KWAESOK','MANASHIELD','MUYEONG','REVIVE_INVISIBLE','FIRE','GICHEON','JEUNGRYEOK','TANHWAN_DASH','PABEOP','CHEONGEUN_WITH_FALL','POLYMORPH','WAR_FLAG1','WAR_FLAG2','WAR_FLAG3','CHINA_FIREWORK','HAIR','GERMANY','RAMADAN_RING','BLEEDING','RED_POSSESSION','BLUE_POSSESSION') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'YMIR',
  `szPointOn2` enum('NONE','MAX_HP','MAX_SP','HP_REGEN','SP_REGEN','BLOCK','HP','SP','ATT_GRADE','DEF_GRADE','MAGIC_ATT_GRADE','MAGIC_DEF_GRADE','BOW_DISTANCE','MOV_SPEED','ATT_SPEED','POISON_PCT','RESIST_RANGE','RESIST_MELEE','CASTING_SPEED','REFLECT_MELEE','ATT_BONUS','DEF_BONUS','RESIST_NORMAL','DODGE','KILL_HP_RECOVER','KILL_SP_RECOVER','HIT_HP_RECOVER','HIT_SP_RECOVER','CRITICAL','MANASHIELD','SKILL_DAMAGE_BONUS','NORMAL_HIT_DAMAGE_BONUS') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'NONE',
  `szPointPoly2` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szDurationPoly2` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `setAffectFlag2` enum('YMIR','INVISIBILITY','SPAWN','POISON','SLOW','STUN','DUNGEON_READY','DUNGEON_UNIQUE','BUILDING_CONSTRUCTION_SMALL','BUILDING_CONSTRUCTION_LARGE','BUILDING_UPGRADE','MOV_SPEED_POTION','ATT_SPEED_POTION','FISH_MIND','JEONGWIHON','GEOMGYEONG','CHEONGEUN','GYEONGGONG','EUNHYUNG','GWIGUM','TERROR','JUMAGAP','HOSIN','BOHO','KWAESOK','MANASHIELD','MUYEONG','REVIVE_INVISIBLE','FIRE','GICHEON','JEUNGRYEOK','TANHWAN_DASH','PABEOP','CHEONGEUN_WITH_FALL','POLYMORPH','WAR_FLAG1','WAR_FLAG2','WAR_FLAG3','CHINA_FIREWORK','HAIR','GERMANY','RAMADAN_RING','BLEEDING','RED_POSSESSION','BLUE_POSSESSION') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'YMIR',
  `szPointOn3` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'NONE',
  `szPointPoly3` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szDurationPoly3` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szGrandMasterAddSPCostPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `prerequisiteSkillVnum` int(11) NOT NULL DEFAULT 0,
  `prerequisiteSkillLevel` int(11) NOT NULL DEFAULT 0,
  `eSkillType` enum('NORMAL','MELEE','RANGE','MAGIC') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'NORMAL',
  `iMaxHit` tinyint(4) NOT NULL DEFAULT 0,
  `szSplashAroundDamageAdjustPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '1',
  `dwTargetRange` int(11) NOT NULL DEFAULT 1000,
  `dwSplashRange` int(10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`dwVnum`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of skill_proto
-- ----------------------------
INSERT INTO `skill_proto` VALUES (1, 'Shaolin Stance', 1, 1, 1, 0, 'HP', '-( 1.1*atk + (0.5*atk +  1.5 * str)*k)', '0', '', '', '12', '-( 0.7*atk + (0.5*atk +  1.5 * str)*k)', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'NONE', '', '', '', '', '', '', '40+100*k', 0, 0, 'MELEE', 5, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (2, 'Whirlwind', 1, 1, 1, 0, 'HP', '-(3*atk + (0.8*atk + str*5 + dex*3 +con)*k)', '0', '', '', '15', '-(1.0*atk + (0.8*atk + str*5 + dex*3 +con)*k)', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'NONE', '', '', '', '', '', '', '50+130*k', 0, 0, 'MELEE', 12, '1', 0, 200);
INSERT INTO `skill_proto` VALUES (3, 'Berserk	Fury', 1, 1, 1, 0, 'ATT_SPEED', '50*k', '0', '31557600*k', '', '0', '50*k', '', 'SELFONLY,TOGGLE', 'JEONGWIHON', 'MOV_SPEED', '20*k', '60+90*k', '', '', '', '', '50+140*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (4, 'Aura of Sword', 1, 1, 1, 0, 'ATT_GRADE', '(100 + str + lv * 3)*k', '0', '31557600*k', '', '0', ' (100 + str + lv * 5)*k', '', 'SELFONLY,TOGGLE', 'GEOMGYEONG', 'NONE', '', '', '', '', '', '', '100+200*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (5, 'Charge', 1, 1, 1, 0, 'HP', '-(2*atk + (atk + dex*3 + str*7 + con)*k)', '0', '', '', '12', '-(0.1*atk + (atk + dex*3 + str*7 + con)*k)', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,CRUSH', '', 'MOV_SPEED', '150', '3', '', '', '', '', '60+120*k', 0, 0, 'MELEE', 4, '1', 0, 200);
INSERT INTO `skill_proto` VALUES (6, 'Volontà di vivere', 1, 1, 1, 0, 'HP', '-(3*atk+(atk+1.5*str)*k)*1.07', '0', '', '', '60', '-(3*atk+(atk+1.5*str)*k)*1.07', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'NONE', '', '', '', '', '', '', '300+150*k', 0, 0, 'MELEE', 5, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (16, 'Spirit Strike', 1, 1, 1, 0, 'HP', '-(2.3*atk + (4*atk  + str*4 + con)*k)', '0', '', '', '15', '-((2.4*atk  + str*4 + con)*k)', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'NONE', '', '', '', '', '', '', '60+120*k', 0, 0, 'MELEE', 4, '1', 0, 100);
INSERT INTO `skill_proto` VALUES (17, 'Tiger Bash', 1, 1, 1, 0, 'HP', '-(2.3*atk + (3*atk + str*4 + con*3)*k)', '0', '', '', '15', '-((2.1*atk + str*4 + con*3)*k)', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'NONE', '', '', '', '', '', '', '60+150*k', 0, 0, 'MELEE', 8, '1', 0, 200);
INSERT INTO `skill_proto` VALUES (18, 'Lion Stomp', 1, 1, 1, 0, 'HP', '-(2*atk + (2*atk + 2*dex + 2*con + str*4)*k)', '0', '', '', '25', '-((1.5*atk + 2*dex + 2*con + str*4)*k)', '', 'ATTACK,USE_MELEE_DAMAGE,SELFONLY,SPLASH,ATTACK_STUN', '', 'NONE', '100+k*1000/6', '2', '', '', '', '', '50+140*k', 0, 0, 'MELEE', 10, '1', 0, 400);
INSERT INTO `skill_proto` VALUES (19, 'Taichi', 1, 1, 1, 0, 'DEF_GRADE', '(200 + str*0.2 + con*0.5 ) *k', '0', '31557600*k', '', '10', '(200 + str*0.2 + con*0.5 ) *k', '', 'SELFONLY', 'CHEONGEUN', 'MOV_SPEED', '-(1+9*k)', '60+90*k', '', '', '', '', '80+220*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (20, 'Sword Strike', 1, 1, 1, 0, 'HP', '-(2*atk + (atk + dex*3 + str*5 + con)*k)', '0', '', '', '20', '-((atk + dex*3 + str*5 + con)*k)', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,CRUSH', '', 'NONE', '', '', '', '', '', '', '40+120*k', 0, 0, 'MELEE', 10, '0.5', 1200, 200);
INSERT INTO `skill_proto` VALUES (21, 'Orb della spada', 1, 1, 1, 0, 'HP', '-(2*atk+(2*atk+2*dex+2*con+str*4)*k)*1.1', '0', '', '', '60', '-(2*atk+(2*atk+2*dex+2*con+str*4)*k)*1.1', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'NONE', '', '', '', '', '', '', '300+180*k', 0, 0, 'MELEE', 10, '1', 0, 400);
INSERT INTO `skill_proto` VALUES (31, 'Ghost Attack', 2, 1, 1, 0, 'HP', '-(atk + (1.2 * atk + number(500, 700) + dex*4+ str*4 )*k)', '0', '', '', '15', '-(atk + (0.3 * atk + dex*3+ str*3 )*k)', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'NONE', '', '', '', '', '', '', '40+160*k', 0, 0, 'MELEE', 6, '0.8', 0, 0);
INSERT INTO `skill_proto` VALUES (32, 'Fatal Strike', 2, 1, 1, 0, 'HP', '-(atk + (1.6* atk + number(200,300) + dex*7 + str*7)*k)', '0', '', '', '20', '-(atk + (0.3* atk + number(200,300) + dex*7 + str*7)*k)', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'NONE', '', '', '', '', '', '', '40+160*k', 0, 0, 'MELEE', 6, '0.8', 800, 0);
INSERT INTO `skill_proto` VALUES (33, 'Spinning Dagger', 2, 1, 1, 0, 'HP', '-(2*atk + (0.5*atk + dex*9 + str*7)*k)', '0', '', '', '25', '-(0.5*atk + (0.5*atk + dex*9 + str*7)*k)', '', 'ATTACK,USE_MELEE_DAMAGE,ATTACK_POISON', '', 'NONE', '40*k', '', '', '', '', '', '50+140*k', 0, 0, 'MELEE', 12, '0.8', 0, 0);
INSERT INTO `skill_proto` VALUES (34, 'Stealth', 2, 1, 1, 0, 'NONE', '', '0', '15+30*k', '', '60', '', '', 'SELFONLY', 'EUNHYUNG', 'NONE', '', '', '', '', '', '', '30+60*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (35, 'Poisonous Cloud', 2, 1, 1, 0, 'HP', '-(lv*2+(atk + str*3 + dex*18)*k)', '0', '', '', '25', '-(lv*2+(0.9*atk + str*3 + dex*18)*k)', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,ATTACK_POISON', '', 'NONE', '60*k', '5+25*k', '', '', '', '', '40+130*k', 0, 0, 'MAGIC', 0, '0.5', 800, 200);
INSERT INTO `skill_proto` VALUES (36, 'Veleno insidioso', 2, 1, 1, 0, 'HP', '-((lv*2+(atk+str*3+dex*18)*k)*1.1)', '0', '', '', '60', '-((lv*2+(atk+str*3+dex*18)*k)*1.1)', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,ATTACK_POISON', '', 'NONE', '60*k', '5+25*k', '', '', '', '', '300+180*k', 0, 0, 'MELEE', 6, '0.5', 800, 0);
INSERT INTO `skill_proto` VALUES (46, 'Repetition Shot', 2, 1, 1, 0, 'HP', '-(atk + 0.3*atk*floor(2+k*6)+ (0.8*atk+dex*8*ar) *k)', '0', '', '', '15', '-(atk + 0.1*atk*floor(2+k*0.3)+ (0.5*atk+dex*5*ar) *k)', '', 'ATTACK,USE_ARROW_DAMAGE', '', 'NONE', '', '', '', '', '', '', '40+130*k', 0, 0, 'RANGE', 1, '1', 2500, 0);
INSERT INTO `skill_proto` VALUES (47, 'Arrow Shower', 2, 1, 1, 0, 'HP', '-(atk + (1.9*atk + dex*2+ str*2)*k)', '0', '', '', '12', '-(atk + (0.3*atk + dex*2+ str*2)*k)', '', 'ATTACK,USE_ARROW_DAMAGE', '', 'NONE', '', '', '', '', '', '', '30+130*k', 0, 0, 'RANGE', 8, '1', 2500, 0);
INSERT INTO `skill_proto` VALUES (48, 'Flaming Arrow', 2, 1, 1, 0, 'HP', '-(1.5*atk + (2.8*atk + number(100, 300))*k)', '0', '', '', '25', '-((1.7*atk + number(100, 300))*k)', '', 'ATTACK,SPLASH,USE_ARROW_DAMAGE', '', 'NONE', '', '', '', '', '', '', '50+130*k', 0, 0, 'RANGE', 12, '0.6', 2500, 300);
INSERT INTO `skill_proto` VALUES (49, 'Swiftness', 2, 1, 1, 0, 'MOV_SPEED', '60*k', '0', '31557600*k', '', '0', '60*k', '', 'SELFONLY,TOGGLE', 'GYEONGGONG', 'NONE', '', '', '', '', '', '', '30+40*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (50, 'Toxic Arrow', 2, 1, 1, 0, 'HP', '-(atk + (1.5*atk + number(100, 200)+dex*6+str*2)*k)', '0', '', '', '25', '-(atk + (0.1*atk + number(100, 200)+dex*5+str*2)*k)', '', 'ATTACK,SPLASH,USE_ARROW_DAMAGE,CRUSH,ATTACK_POISON', '', 'NONE', '80*k', '15+30*k', '', '', '', '', '40+160*k', 0, 0, 'RANGE', 12, '0.5', 2500, 300);
INSERT INTO `skill_proto` VALUES (51, 'Colpo sfavillante', 2, 1, 1, 0, 'HP', '-((atk+(1.2*atk+number(100,200)+dex*6+str*2)*k)*1.1)', '0', '', '', '60', '-((atk+(1.2*atk+number(100,200)+dex*6+str*2)*k)*1.1)', '', 'ATTACK,SPLASH,USE_ARROW_DAMAGE,CRUSH,ATTACK_POISON', '', 'NONE', '80*k', '15+30*k', '', '', '', '', '200+200*k', 0, 0, 'NORMAL', 5, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (61, 'Rupture	Bursting', 3, 1, 1, 0, 'HP', '-(atk + 2*lv + iq*2 + ( 2*atk + str*4 + iq*14) * k)', '0', '', '', '10', '-(atk + 1*lv + iq*1 + ( 0.7*atk + str*3 + iq*11) * k)', '', 'ATTACK,USE_MELEE_DAMAGE,PENETRATE', '', 'NONE', '', '', '', '', '', '', '30+140*k', 0, 0, 'MELEE', 4, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (62, 'Dark Twister', 3, 1, 1, 0, 'HP', '-(1.1 * atk + 2*lv + iq*2+(1.5*atk + str + iq*12) * k)', '0', '', '', '15', '-(0.1 * atk + 2*lv + iq*2+(1.2*atk + str + iq*12) * k)', '', 'ATTACK,USE_MELEE_DAMAGE,SELFONLY,SPLASH,IGNORE_TARGET_RATING', '', 'NONE', '', '', '', '', '', '', '50+150*k', 0, 0, 'MELEE', 12, '1', 0, 500);
INSERT INTO `skill_proto` VALUES (63, 'Enchanted Blade', 3, 1, 1, 0, 'ATT_GRADE', '(3 * iq + 2 * lv)*k', '0', '31557600*k', '0', '0', '(4 * iq + 3 * lv)*k', '', 'SELFONLY,TOGGLE', 'GWIGUM', 'HIT_HP_RECOVER', '10*k', '50+80*k', '', '', '', '', '20+240*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (64, 'Fear', 3, 1, 1, 0, 'DODGE', '1 + 29 * k', '0', '31557600*k', '', '0', '1 + 29 * k', '', 'SELFONLY,TOGGLE', 'TERROR', 'NONE', '', '', '', '', '', '', '60+120*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (65, 'Dark Shield', 3, 1, 1, 0, 'DEF_GRADE', '(iq+30)*k', '0', '31557600*k', '', '0', '(iq+30)*k', '', 'SELFONLY,TOGGLE', 'JUMAGAP', 'REFLECT_MELEE', '(iq/4+10)*k', '30+120*k', '', '', '', '', '70+170*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (66, 'Remove Magic', 3, 1, 1, 0, 'HP', '-(40 +5*lv + 2*iq+(10*iq + 7*mwep + number(50,100) )*ar*k)', '0', '', '', '12', '-(40 +4*lv + 1*iq+(15*iq + 5*mwep )*ar*k)', '', 'ATTACK,COMPUTE_MAGIC_DAMAGE,SPLASH,REMOVE_GOOD_AFFECT', '', 'NONE', '10+40*k', '7+23*k', '', '', '', '', '30+120*k', 0, 0, 'NORMAL', 5, '0.6', 1800, 200);
INSERT INTO `skill_proto` VALUES (76, 'Dark Strike', 3, 1, 1, 0, 'HP', '-(40 +5*lv + 2*iq +(13*iq + 6*mwep + number(50,100) )*ar*k)', '0', '', '', '7', '-(40 +7*lv + 5*iq +(20*iq + 10*mwep )*ar*k)', '', 'ATTACK,COMPUTE_MAGIC_DAMAGE,SPLASH', '', 'NONE', '', '', '', '', '', '', '30+140*k', 0, 0, 'MAGIC', 5, '0.6', 1500, 200);
INSERT INTO `skill_proto` VALUES (77, 'Flame Strike', 3, 1, 1, 0, 'HP', '-(5*lv + 2*iq+(10*iq + 6*mwep + str*4 + con*2 + number(180,200) )*k)', '0', '', '', '12', '-(5*lv + 5*iq+(17*iq + 9*mwep + str*4 + con*2 )*k)', '', 'ATTACK,SELFONLY,COMPUTE_MAGIC_DAMAGE,SPLASH', '', 'NONE', '', '', '', '', '', '', '60+140*k', 0, 0, 'MAGIC', 15, '0.8', 0, 500);
INSERT INTO `skill_proto` VALUES (78, 'Ritual of Doom', 3, 1, 1, 0, 'HP', '-(30+ 2*lv + 2*iq+(7*iq + 6*mwep + number(200,500))*ar*k)', '0', '31557600*k', '', '0', '-(50+ 5*lv + 5*iq+(14*iq + 14*mwep)*ar*k)', '', 'ATTACK,COMPUTE_MAGIC_DAMAGE,SPLASH,TOGGLE', '', 'NONE', '', '', '', '', '', '', '20+30*k', 0, 0, 'MAGIC', 1, '1', 800, 0);
INSERT INTO `skill_proto` VALUES (79, 'Aphotic Shield', 3, 1, 1, 0, 'DEF_GRADE', '(0.5*iq+15)*k', '0', '31557600*k', '', '0', '(0.5*iq+15)*k', '', 'SELFONLY,TOGGLE', 'MANASHIELD', 'MANASHIELD', '100-((iq*0.84)*k)', '60+10*k', '', '', '', '', '20+30*k', 0, 0, 'MAGIC', 1, '0.8', 0, 0);
INSERT INTO `skill_proto` VALUES (80, 'Spirit Entangle', 3, 1, 1, 0, 'HP', '-(40 + 2* lv + 2*iq +(2 * con + 2 * dex + 13*iq + 6*mwep + number(180, 200))*ar*k)', '0', '', '', '12', '-(50 + 7* lv + 7*iq +(2 * con + 2 * dex + 15*iq + 9*mwep)*ar*k)', '', 'ATTACK,COMPUTE_MAGIC_DAMAGE,SPLASH,ATTACK_SLOW', '', 'NONE', '333+300*k', '10+10*k', '', '', '', '', '40+120*k', 0, 0, 'MAGIC', 9, '0.8', 1200, 400);
INSERT INTO `skill_proto` VALUES (81, 'Dark Orb', 3, 1, 1, 0, 'HP', '-(120 + 6*lv + (5 * con + 5 * dex + 29*iq + 9*mwep)*ar*k)', '0', '', '', '24', '-(120 + 6*lv + (5 * con + 5 * dex + 29*iq + 9*mwep)*ar*k)', '', 'ATTACK,COMPUTE_MAGIC_DAMAGE,SPLASH', '', 'NONE', '', '', '', '', '', '', '80+220*k', 0, 0, 'MAGIC', 9, '0.4', 1500, 200);
INSERT INTO `skill_proto` VALUES (91, 'Flying Talisman', 4, 1, 1, 0, 'HP', '-(70 + 4*lv + (20*iq+5*mwep+50)*ar*k)', '0', '', '', '7', '-(70 + 5*lv + (35*iq+7*mwep+50)*ar*k)', '', 'ATTACK,COMPUTE_MAGIC_DAMAGE,SPLASH', '', 'NONE', '', '', '', '', '', '', '30+160*k', 0, 0, 'MAGIC', 5, '0.5', 1800, 201);
INSERT INTO `skill_proto` VALUES (92, 'Inferno', 4, 1, 1, 0, 'HP', '-(60 + 5*lv + (18*iq + 6*mwep + 120)*ar*k)', '0', '', '', '8', '-(60 + 5*lv + (32*iq + 7*mwep + 120)*ar*k)', '', 'ATTACK,ATTACK_FIRE_CONT', '', 'NONE', 'lv+5*iq *k', 'iq*0.2*k', '', '', '', '', '50+160*k', 0, 0, 'MAGIC', 10, '0.8', 0, 0);
INSERT INTO `skill_proto` VALUES (93, 'Dragon Roar', 4, 1, 1, 0, 'HP', '-(80 + 6*lv + (20*iq+14*mwep+120)*ar*k)', '0', '', '', '20', '-(80 + 6*lv + (40*iq+16*mwep+120)*ar*k)', '', 'ATTACK,SELFONLY,SPLASH,ATTACK_FIRE_CONT', '', 'NONE', 'lv+5*iq *k', 'iq*0.2*k', '', '', '', '', '50+160*k', 0, 0, 'MAGIC', 15, '0.8', 0, 500);
INSERT INTO `skill_proto` VALUES (94, 'Blessing Spell', 4, 1, 1, 0, 'RESIST_NORMAL', '(iq*0.3+5)*(2*k+0.5)/(k+1.5)', '0', '60+200*k', '', '10', '(iq*0.3+5)*(2*k+0.5)/(k+1.5)', '', 'PARTY', 'HOSIN', 'NONE', '', '', '', '', '', '', '40+160*k', 0, 0, 'NORMAL', 1, '1', 800, 0);
INSERT INTO `skill_proto` VALUES (95, 'Reflect Damage', 4, 1, 1, 0, 'REFLECT_MELEE', '5+(iq*0.3 + 5)*k', '0', '60+200*k', '', '10', '5+(iq*0.3 + 5)*k', '', 'PARTY', 'BOHO', 'NONE', '', '', '', '', '', '', '40+160*k', 0, 0, 'NORMAL', 1, '1', 1000, 0);
INSERT INTO `skill_proto` VALUES (96, 'Enchant Damage', 4, 1, 1, 0, 'CRITICAL', '(iq*0.3+5)*(2*k+0.5)/(k+1.5)', '0', '60+100*k', '', '10', '(iq*0.3+5)*(2*k+0.5)/(k+1.5)', '', 'PARTY', 'GICHEON', 'NONE', '', '', '', '', '', '', '40+160*k', 0, 0, 'NORMAL', 1, '1', 1000, 0);
INSERT INTO `skill_proto` VALUES (106, 'Lightning Strike', 4, 1, 1, 0, 'HP', '-(60 + 4*lv + (7*iq+8*mwep+number(iq*5,iq*15))*ar*k)', '0', '', '', '7', '-(30 + 3*lv + (33*iq+7*mwep+number(iq*3,iq*8))*ar*k)', '', 'ATTACK,SPLASH', '', 'NONE', '', '', '', '', '', '', '30+150*k', 0, 0, 'MAGIC', 5, '0.6', 1800, 200);
INSERT INTO `skill_proto` VALUES (107, 'Thunder Bolt', 4, 1, 1, 0, 'HP', '-(40 + 4*lv + (13*iq+7*mwep+number(iq*5,iq*16))*ar*k)', '0', '', '', '15', '-(20+ 2*lv + (40*iq+3*mwep+number(iq*5,iq*13))*ar*k)', '', 'ATTACK,SPLASH,ATTACK_STUN', '', 'NONE', '50+1000*k/6', '5', '', '', '', '', '50+150*k', 0, 0, 'MAGIC', 15, '0.8', 1500, 400);
INSERT INTO `skill_proto` VALUES (108, 'Lightning Claw', 4, 1, 1, 0, 'HP', '-(50 + 5*lv + (6*iq+6*mwep+number(1,800))*ar*k) * (1-chain*0.13)', '0', '', '', '10', '-(50 + 5*lv + (32*iq+5*mwep)*ar*k) * (1-chain*0.13)', '', 'ATTACK', '', 'NONE', '', '', '', '', '', '', '40+180*k', 0, 0, 'MAGIC', 7, '0.8', 2500, 0);
INSERT INTO `skill_proto` VALUES (109, 'Cure', 4, 1, 1, 0, 'HP', '200+7*lv+(30*iq+6*mwep+600)*k', '0', '', '', '10', '100+4*lv+(20*iq+3*mwep+400)*k', '', 'REMOVE_BAD_AFFECT', '', 'NONE', '20+80*k', '0', '', '', '', '', '40+200*k', 0, 0, 'NORMAL', 1, '1', 1000, 0);
INSERT INTO `skill_proto` VALUES (110, 'Dance with Wind', 4, 1, 1, 0, 'MOV_SPEED', '5 + 35*k', '0', '60+100*k', '', '10', '5 + 35*k', '', 'PARTY', 'KWAESOK', 'CASTING_SPEED', '3+33*k', '60+100*k', '', '', '', '', '60+120*k', 0, 0, 'NORMAL', 1, '1', 1000, 0);
INSERT INTO `skill_proto` VALUES (111, 'Natures Enchantment', 4, 1, 1, 0, 'ATT_GRADE', '10+(iq*0.4 +20)*k', '0', '60+100*k', '', '10', '10+(iq*0.4 +30)*k', '', 'PARTY', 'JEUNGRYEOK', 'NONE', '', '', '', '', '', '', '60+120*k', 0, 0, 'NORMAL', 1, '1', 1000, 0);
INSERT INTO `skill_proto` VALUES (112, 'NONAME_112', 0, 1, 40, 0, 'NONE', '20*k', '', '', '', '', '', '', NULL, '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (113, 'NONAME_113', 0, 1, 40, 0, 'NONE', '20*k', '', '', '', '', '', '', NULL, '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (114, 'NONAME_114', 0, 1, 40, 0, 'NONE', '20*k', '', '', '', '', '', '', NULL, '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (115, 'NONAME_115', 0, 1, 40, 0, 'NONE', '20*k', '', '', '', '', '', '', NULL, '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (116, 'NONAME_116', 0, 1, 40, 0, 'NONE', '20*k', '', '', '', '', '', '', NULL, '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (117, 'NONAME_117', 0, 1, 40, 0, 'NONE', '20*k', '', '', '', '', '', '', NULL, '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (118, 'NONAME_118', 0, 1, 40, 0, 'NONE', '20*k', '', '', '', '', '', '', NULL, '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (119, 'NONAME_119', 0, 1, 40, 0, 'NONE', '20*k', '', '', '', '', '', '', NULL, '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (121, 'Leadership', 0, 1, 40, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (122, 'Combo', 0, 1, 2, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (124, 'Mining', 0, 1, 40, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (125, 'Blacksmithing', 0, 1, 40, 0, 'NONE', '', '', '10+1000*k', '', '', '', '', 'DISABLE_BY_POINT_UP', 'YMIR', 'NONE', '', '', 'YMIR', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 1000, 0);
INSERT INTO `skill_proto` VALUES (126, 'Shinsoo', 0, 1, 20, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (127, 'Chunjo', 0, 1, 20, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (128, 'Jinno', 0, 1, 20, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (129, 'Polymorph', 0, 1, 40, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', 'NONE', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (130, 'Horse Riding', 0, 1, 1, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (131, 'Summon Horse', 0, 1, 10, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (137, 'Horseback Slash', 5, 1, 1, 50, 'HP', '-(atk+(2*atk*k))', '0', '', '', '5-(4*k)', '', '', 'ATTACK,USE_MELEE_DAMAGE,CRUSH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'MELEE', 10, '1', 300, 0);
INSERT INTO `skill_proto` VALUES (138, 'Horse Stomp', 5, 1, 1, 52, 'HP', '-(2.4*(200+1.5*lv)+(3*200*k))', '0', '', '', '15', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,CRUSH_LONG', '', 'MOV_SPEED', '50', '5', '', '', '', '', '', 0, 0, 'MELEE', 6, '1', 400, 100);
INSERT INTO `skill_proto` VALUES (139, 'Power Wave', 5, 1, 1, 55, 'HP', '-(2*(200+1.5*lv)+(3*200*k))', '0', '', '', '20', '', '', 'ATTACK,USE_MELEE_DAMAGE,SELFONLY,SPLASH,CRUSH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'MELEE', 12, '1', 400, 250);
INSERT INTO `skill_proto` VALUES (140, 'Arrow Storm', 5, 1, 1, 50, 'HP', '-(atk+(2*atk*k))', '0', '', '', '10', '', '', 'ATTACK,USE_ARROW_DAMAGE,CRUSH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, '', 5, '1', 2500, 0);
INSERT INTO `skill_proto` VALUES (141, 'Heart of the Dragon', 0, 1, 40, 0, 'NONE', '1333.3*k', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (142, 'Dragon Claw', 0, 1, 40, 0, 'NONE', '20*k', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (151, 'Dragon Eyes', 0, 1, 7, 0, 'NONE', '', '', '', '', '', '', '', NULL, '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (152, 'Blood of Dragon God', 0, 1, 7, 0, 'MAX_HP', 'maxhp*0.2*k', '0', '300', '', '600', '', '', NULL, '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (153, 'Benediction of Dragon God', 0, 1, 7, 0, 'MAX_SP', 'maxsp*0.2*k', '0', '300', '', '600', '', '', NULL, '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (154, 'Holy Armour', 0, 1, 7, 0, 'DEF_GRADE', 'odef*0.1*k', '0', '180', '', '480', '', '', NULL, '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (155, 'Acceleration', 0, 1, 7, 0, 'MOV_SPEED', '15*k', '0', '180', '', '480', '', '', NULL, '', 'ATT_SPEED', '15*k', '180', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (156, 'Rage of Dragon God', 0, 1, 7, 0, 'CRITICAL', '50*k', '0', '180', '', '480', '', '', 'SELFONLY', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (157, 'Casting Aid', 0, 1, 7, 0, 'CASTING_SPEED', '50*k', '0', '180', '', '480', '', '', 'SELFONLY', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (158, 'PASSIVANONAME2', 0, 1, 3, 0, 'NONE', '', '', '', '', '', '', '', 'SELFONLY', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (159, 'PASSIVANONAME3', 0, 1, 5, 0, 'NONE', '', '', '', '', '', '', '', 'SELFONLY', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (160, 'PASSIVANONAME4', 0, 1, 5, 0, 'NONE', '3*k', '80-12*k', '300', '', '', '', '', 'SELFONLY', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (161, 'PASSIVANONAME5', 0, 1, 2, 0, 'NONE', '', '50', '', '', '', '', '', NULL, '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (162, 'PASSIVANONAME6', 0, 1, 2, 0, 'NONE', '', '20', '', '', '', '', '', NULL, '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (170, 'Dilania', 7, 1, 1, 0, 'HP', '-(1.1*atk+(0.3*atk+1.5*str)*k)', '40+100*k', '', '', '12', '-(1.1*atk+(0.3*atk+1.5*str)*k)', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH', '', 'NONE', '60*k', '5+25*k', '', '', '', '', '40+100*k', 0, 0, 'MELEE', 5, '1', 300, 200);
INSERT INTO `skill_proto` VALUES (171, 'Respiro del lupo', 7, 1, 1, 0, 'HP', '-(2*atk+(atk+dex*3+str*5+con)*k)', '40+120*k', '', '', '20', '-(2*atk+(atk+dex*3+str*5+con)*k)', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,ATTACK_STUN,CRUSH', '', 'NONE', '100+k*1000/6', '2', '', '', '', '', '40+120*k', 0, 0, 'MELEE', 10, '0.5', 1000, 200);
INSERT INTO `skill_proto` VALUES (172, 'Salto del lupo', 7, 1, 1, 0, 'HP', '-(atk+(1.6*atk+200+dex*7+str*7)*k)', '40+100*k', '', '', '12', '-(atk+(1.6*atk+200+dex*7+str*7)*k)', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'NONE', '', '', '', '', '', '', '40+100*k', 0, 0, 'MELEE', 5, '1', 800, 100);
INSERT INTO `skill_proto` VALUES (173, 'Artiglio di lupo', 7, 1, 1, 0, 'HP', '-(3*atk+(0.8*atk+str*6+dex*2+con)*k)', '40+100*k', '', '', '12', '-(3*atk+(0.8*atk+str*6+dex*2+con)*k)', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'DEF_GRADE', '-30*k', '5', '', '', '', '', '40+100*k', 0, 0, 'MELEE', 10, '1', 800, 100);
INSERT INTO `skill_proto` VALUES (174, 'Anima del lupo purpureo', 7, 1, 1, 0, 'ATT_GRADE', '7+(5*iq+13)*k', '20+240*k', '50+100*k', '2+23*k', '2', '7+(5*iq+13)*k', '', 'SELFONLY,TOGGLE', 'RED_POSSESSION', 'DEF_GRADE', '-30*k', '50+100*k', '', '', '', '', '20+240*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (175, 'Anima del lupo indaco', 7, 1, 1, 0, 'ATT_SPEED', '20*k', '80+220*k', '200', '', '300', '20*k', '', 'PARTY', 'BLUE_POSSESSION', 'DODGE', '1+10*k', '200', '', '', '', '', '80+220*k', 0, 0, 'NORMAL', 1, '1', 1000, 0);
INSERT INTO `skill_proto` VALUES (256, 'AbilitàSchiaccia200', 0, 1, 1, 0, 'HP', '-5*k*atk', '', '', '', '4', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,CRUSH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'MELEE', 0, '1', 0, 300);
INSERT INTO `skill_proto` VALUES (257, 'AbilitàGenerali350', 0, 1, 1, 0, 'HP', '-5*k*atk', '', '', '', '6', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'MELEE', 0, '1', 0, 525);
INSERT INTO `skill_proto` VALUES (258, 'AbilitàSchiaccia300', 0, 1, 1, 0, 'HP', '-5*k*atk', '', '', '', '8', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,CRUSH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'MELEE', 0, '1', 0, 450);
INSERT INTO `skill_proto` VALUES (259, 'AbilitàNormali200', 0, 1, 1, 0, 'HP', '-5*k*atk', '', '', '', '10', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'MELEE', 0, '1', 0, 300);
INSERT INTO `skill_proto` VALUES (260, 'AbilitàSchiaccia400', 0, 1, 1, 0, 'HP', '-5*k*atk', '', '', '', '12', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,CRUSH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'MELEE', 0, '1', 0, 600);
INSERT INTO `skill_proto` VALUES (261, 'AbilitàVeleno250', 0, 1, 1, 0, 'HP', '-5*k*atk', '', '', '', '10', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,ATTACK_POISON', '', 'NONE', '80', '', '', '', '', '', '', 0, 0, 'MELEE', 0, '1', 0, 375);
INSERT INTO `skill_proto` VALUES (262, 'AbilitàRallenta300', 0, 1, 1, 0, 'HP', '-5*k*atk', '', '', '', '14', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH', '', 'MOV_SPEED', '-20', '10', '', '', '', '', '', 0, 0, 'MELEE', 0, '1', 0, 450);

SET FOREIGN_KEY_CHECKS = 1;
