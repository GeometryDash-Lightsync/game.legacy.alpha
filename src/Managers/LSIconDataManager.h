#pragma once
#include "../lightsync.h"

class LSIconDataManager
{
public:
    struct IconData
    {
        int Id;
        IconType type;
    };

    std::map<int, IconData> m_exlusiveIcons;
    std::map<std::string, int> m_storeIcons;
    std::vector<std::string> m_iconAuthors;
    std::vector<std::string> m_identifiersArray;
    std::vector<IconData> m_loginFreeIcons;

    bool init() { return true; }
    static LSIconDataManager *sharedState();

    int getCompletedAchivements()
    {
        int total = 0;
        for (int i = 0; i < m_identifiersArray.size(); i++)
        {
            if (
                AchievementManager::sharedState()
                    ->percentForAchievement(
                        m_identifiersArray[i].c_str()) == 100)
                total++;
        }
        return total;
    }

    std::string getArtistName(int offset)
    {
        std::vector<std::string> arr =
            {
                "RadleyMCT",      // 0
                "DSprint",        // 1
                "RetroAdvance64", // 2
                "NHJ",            // 3
                "Dibbj",          // 4
                "Axel996",        // 5
                "GhostPower13",   // 6
                "ZetkutGD",       // 7
                "TaMaLiToUwU",    // 8
                "redwn",          // 9
                "DaferSilver",    // 10
                "aruXD",          // 11
                "Djoxy",          // 12
                "hallymallybubu", // 13
                "Ic3Fir3",        // 14
                "ItsJavi2504x",   // 15
                "LaZye",          // 16
                "Last67706",      // 17
                "shacal",         // 18
                "TriaScarlix",    // 19
                "KingTony",       // 20
                "Aleck08",        // 21
                "luisilloRS",     // 22
                "NeXuS Gamer",    // 23
                "Rob Buck",       // 24
                "Meikyu",         // 25
                "Terron",         // 26
                "CygnusGD",       // 27
                "Deraklich",      // 28
                "Edialex",        // 29
                "litexotic",      // 30
                "checho623",      // 31
                "AutoNick",       // 32
                "Ighby",          // 33
                "InsaneJohnson",  // 34
                "Yoshibros64",    // 35
                "Aleiz21",        // 36
                "ML500",          // 37
                "Lake",           // 38
                "flash",          // 39
                "Querez",         // 40
                "airiLmao",       // 41
                "AlexanderX1ta",  // 42
                "TriStorm",       // 43
                "Th3ih4g0GMD",    // 44
                "SupremeOrange",  // 45
                "Subwoofer",      // 46
                "Danke",          // 47
                "para",           // 48
                "KyNutZ",         // 49
                "Play Dash",      // 50
                "maxgreenevsky",  // 51
                "Zigma",          // 52
                "rafer",          // 53
                "xXLOCOXx",       // 54
                "ElGab",          // 55
                "Keoiki",         // 56
                "TamTixx",        // 57
                "DarkFireDrago",  // 58
                "ScorchVx",       // 59
                "Seadawg02",      // 60
                "xVexis",         // 61
                "Splons",         // 62
                "k3vo5ky",        // 63
                "Mariolego320",   // 64
                "Blitzer",        // 65
                "SpaceSyrup",     // 66
                "Arachnus",       // 67
                "CyverMast",      // 68
                "lordwerthers",   // 69
                "Jntx231",        // 70
                "dracthedragon",  // 71
                "DaRealDazzer",   // 72
                "Revanty",        // 73
                "Alex PG",        // 74
                "Plazda",         // 75
                "RagnokGD",       // 76
                "The Railgunner", // 77
                "samuraivi13",    // 78
                "haoN",           // 79
                "Gelt",           // 80
                "CHRISTIAN",      // 81
                "ITSSUNSET",      // 82
                "VIRUS METAL",    // 83
                "Danky",          // 84
                "Mino",           // 85
                "Raster",         // 86
                "Namix",          // 87
                "AngeloToons",    // 88
                "Astren",         // 89
                "Flushii",        // 90
                "DylanXD",        // 91
                "MatiasLA"        // 92

            };

        return arr[offset];
    }

    int remakeIDForIcon(int id, UnlockType unlock)
    {
        std::map<std::pair<int, UnlockType>, int> map;

        map[std::make_pair(508, UnlockType::kCube)] = 6;
        map[std::make_pair(513, UnlockType::kCube)] = 87;
        map[std::make_pair(514, UnlockType::kCube)] = 87;
        map[std::make_pair(515, UnlockType::kCube)] = 87;

        map[std::make_pair(120, UnlockType::kBall)] = 87;

        map[std::make_pair(44, UnlockType::kSwing)] = 6;
        map[std::make_pair(45, UnlockType::kSwing)] = 6;
        map[std::make_pair(46, UnlockType::kSwing)] = 6;
        map[std::make_pair(47, UnlockType::kSwing)] = 6;
        map[std::make_pair(48, UnlockType::kSwing)] = 6;
        map[std::make_pair(49, UnlockType::kSwing)] = 6;

        auto var = std::make_pair(id, unlock);

        if (map.find(var) != map.end())
        {
            return map[var];
        }
        else
            return -1;
    }

    int artistIDForIcon(int id, UnlockType unlock)
    {
        std::map<std::pair<int, UnlockType>, int> map;

        map[std::make_pair(117, UnlockType::kCube)] = 21;
        map[std::make_pair(118, UnlockType::kCube)] = 11;
        map[std::make_pair(119, UnlockType::kCube)] = 0;
        map[std::make_pair(120, UnlockType::kCube)] = 12;
        map[std::make_pair(121, UnlockType::kCube)] = 6;
        map[std::make_pair(122, UnlockType::kCube)] = 13;
        map[std::make_pair(123, UnlockType::kCube)] = 14;
        map[std::make_pair(124, UnlockType::kCube)] = 15;
        map[std::make_pair(125, UnlockType::kCube)] = 16;
        map[std::make_pair(126, UnlockType::kCube)] = 17;
        map[std::make_pair(127, UnlockType::kCube)] = 22;
        map[std::make_pair(128, UnlockType::kCube)] = 22;
        map[std::make_pair(129, UnlockType::kCube)] = 23;
        map[std::make_pair(130, UnlockType::kCube)] = 24;
        map[std::make_pair(131, UnlockType::kCube)] = 24;
        map[std::make_pair(132, UnlockType::kCube)] = 24;
        map[std::make_pair(133, UnlockType::kCube)] = 25;
        map[std::make_pair(134, UnlockType::kCube)] = 25;
        map[std::make_pair(135, UnlockType::kCube)] = 26;
        map[std::make_pair(249, UnlockType::kCube)] = 65;
        map[std::make_pair(250, UnlockType::kCube)] = 41;
        map[std::make_pair(251, UnlockType::kCube)] = 36;
        map[std::make_pair(252, UnlockType::kCube)] = 36;
        map[std::make_pair(253, UnlockType::kCube)] = 32;
        map[std::make_pair(254, UnlockType::kCube)] = 5;
        map[std::make_pair(255, UnlockType::kCube)] = 5;
        map[std::make_pair(256, UnlockType::kCube)] = 5;
        map[std::make_pair(257, UnlockType::kCube)] = 5;
        map[std::make_pair(258, UnlockType::kCube)] = 5;
        map[std::make_pair(259, UnlockType::kCube)] = 55;
        map[std::make_pair(260, UnlockType::kCube)] = 56;
        map[std::make_pair(261, UnlockType::kCube)] = 56;
        map[std::make_pair(262, UnlockType::kCube)] = 57;
        map[std::make_pair(263, UnlockType::kCube)] = 44;
        map[std::make_pair(264, UnlockType::kCube)] = 45;
        map[std::make_pair(265, UnlockType::kCube)] = 45;
        map[std::make_pair(266, UnlockType::kCube)] = 34;
        map[std::make_pair(267, UnlockType::kCube)] = 37;
        map[std::make_pair(268, UnlockType::kCube)] = 46;
        map[std::make_pair(269, UnlockType::kCube)] = 50;
        map[std::make_pair(270, UnlockType::kCube)] = 51;
        map[std::make_pair(271, UnlockType::kCube)] = 6;
        map[std::make_pair(272, UnlockType::kCube)] = 6;
        map[std::make_pair(273, UnlockType::kCube)] = 20;
        map[std::make_pair(274, UnlockType::kCube)] = 1;
        map[std::make_pair(275, UnlockType::kCube)] = 37;
        map[std::make_pair(276, UnlockType::kCube)] = 52;
        map[std::make_pair(277, UnlockType::kCube)] = 8;
        map[std::make_pair(278, UnlockType::kCube)] = 0;
        map[std::make_pair(279, UnlockType::kCube)] = 2;
        map[std::make_pair(280, UnlockType::kCube)] = 3;
        map[std::make_pair(281, UnlockType::kCube)] = 53;
        map[std::make_pair(282, UnlockType::kCube)] = 54;
        map[std::make_pair(283, UnlockType::kCube)] = 25;
        map[std::make_pair(284, UnlockType::kCube)] = 25;
        map[std::make_pair(285, UnlockType::kCube)] = 25;
        map[std::make_pair(286, UnlockType::kCube)] = 25;
        map[std::make_pair(287, UnlockType::kCube)] = 40;
        map[std::make_pair(288, UnlockType::kCube)] = 25;
        map[std::make_pair(289, UnlockType::kCube)] = 37;
        map[std::make_pair(290, UnlockType::kCube)] = 37;
        map[std::make_pair(291, UnlockType::kCube)] = 37;
        map[std::make_pair(292, UnlockType::kCube)] = 37;
        map[std::make_pair(293, UnlockType::kCube)] = 37;
        map[std::make_pair(294, UnlockType::kCube)] = 37;
        map[std::make_pair(295, UnlockType::kCube)] = 37;
        map[std::make_pair(296, UnlockType::kCube)] = 37;
        for (int i = 297; i < 405; i++)
        {
            map[std::make_pair(i, UnlockType::kCube)] = 2;
        }
        map[std::make_pair(405, UnlockType::kCube)] = 37;
        map[std::make_pair(406, UnlockType::kCube)] = 37;
        for (int i = 407; i < 442; i++)
        {
            map[std::make_pair(i, UnlockType::kCube)] = 0;
        }
        map[std::make_pair(442, UnlockType::kCube)] = 7;
        map[std::make_pair(443, UnlockType::kCube)] = 7;
        map[std::make_pair(444, UnlockType::kCube)] = 7;
        map[std::make_pair(445, UnlockType::kCube)] = 7;
        map[std::make_pair(446, UnlockType::kCube)] = 7;
        map[std::make_pair(447, UnlockType::kCube)] = 7;
        map[std::make_pair(448, UnlockType::kCube)] = 7;
        map[std::make_pair(449, UnlockType::kCube)] = 7;
        map[std::make_pair(450, UnlockType::kCube)] = 7;
        map[std::make_pair(451, UnlockType::kCube)] = 7;
        map[std::make_pair(452, UnlockType::kCube)] = 7;
        map[std::make_pair(453, UnlockType::kCube)] = 8;
        map[std::make_pair(454, UnlockType::kCube)] = 8;
        map[std::make_pair(455, UnlockType::kCube)] = 8;
        map[std::make_pair(456, UnlockType::kCube)] = 8;
        map[std::make_pair(457, UnlockType::kCube)] = 8;
        map[std::make_pair(458, UnlockType::kCube)] = 8;
        map[std::make_pair(459, UnlockType::kCube)] = 80;
        map[std::make_pair(460, UnlockType::kCube)] = 8;
        map[std::make_pair(461, UnlockType::kCube)] = 1;
        map[std::make_pair(462, UnlockType::kCube)] = 1;
        map[std::make_pair(463, UnlockType::kCube)] = 1;
        map[std::make_pair(464, UnlockType::kCube)] = 1;
        map[std::make_pair(465, UnlockType::kCube)] = 1;
        map[std::make_pair(466, UnlockType::kCube)] = 1;
        map[std::make_pair(467, UnlockType::kCube)] = 1;
        map[std::make_pair(468, UnlockType::kCube)] = 1;
        map[std::make_pair(469, UnlockType::kCube)] = 1;
        map[std::make_pair(470, UnlockType::kCube)] = 20;
        map[std::make_pair(471, UnlockType::kCube)] = 20;
        map[std::make_pair(472, UnlockType::kCube)] = 20;
        map[std::make_pair(473, UnlockType::kCube)] = 20;
        map[std::make_pair(474, UnlockType::kCube)] = 20;
        map[std::make_pair(475, UnlockType::kCube)] = 38;
        map[std::make_pair(476, UnlockType::kCube)] = 38;
        map[std::make_pair(477, UnlockType::kCube)] = 9;
        map[std::make_pair(478, UnlockType::kCube)] = 9;
        map[std::make_pair(479, UnlockType::kCube)] = 9;
        map[std::make_pair(480, UnlockType::kCube)] = 33;
        map[std::make_pair(481, UnlockType::kCube)] = 25;
        map[std::make_pair(483, UnlockType::kCube)] = 47;
        map[std::make_pair(485, UnlockType::kCube)] = 84;
        map[std::make_pair(486, UnlockType::kCube)] = 86;
        map[std::make_pair(487, UnlockType::kCube)] = 84;
        map[std::make_pair(488, UnlockType::kCube)] = 84;
        map[std::make_pair(489, UnlockType::kCube)] = 84;
        map[std::make_pair(490, UnlockType::kCube)] = 84;
        map[std::make_pair(491, UnlockType::kCube)] = 84;
        map[std::make_pair(492, UnlockType::kCube)] = 84;
        map[std::make_pair(493, UnlockType::kCube)] = 84;
        map[std::make_pair(494, UnlockType::kCube)] = 84;
        map[std::make_pair(495, UnlockType::kCube)] = 84;
        map[std::make_pair(496, UnlockType::kCube)] = 84;
        map[std::make_pair(497, UnlockType::kCube)] = 84;
        map[std::make_pair(498, UnlockType::kCube)] = 88;
        map[std::make_pair(499, UnlockType::kCube)] = 84;
        map[std::make_pair(500, UnlockType::kCube)] = 88;
        map[std::make_pair(501, UnlockType::kCube)] = 88;
        map[std::make_pair(503, UnlockType::kCube)] = 86;
        map[std::make_pair(504, UnlockType::kCube)] = 84;
        map[std::make_pair(505, UnlockType::kCube)] = 84;
        map[std::make_pair(506, UnlockType::kCube)] = 86;
        map[std::make_pair(507, UnlockType::kCube)] = 84;
        map[std::make_pair(508, UnlockType::kCube)] = 89;
        map[std::make_pair(509, UnlockType::kCube)] = 85;
        map[std::make_pair(510, UnlockType::kCube)] = 86;
        map[std::make_pair(511, UnlockType::kCube)] = 86;
        map[std::make_pair(512, UnlockType::kCube)] = 86;
        map[std::make_pair(516, UnlockType::kCube)] = 85;
        map[std::make_pair(517, UnlockType::kCube)] = 85;

        map[std::make_pair(36, UnlockType::kShip)] = 21;
        map[std::make_pair(37, UnlockType::kShip)] = 74;
        map[std::make_pair(38, UnlockType::kShip)] = 29;
        map[std::make_pair(39, UnlockType::kShip)] = 82;
        map[std::make_pair(40, UnlockType::kShip)] = 22;
        map[std::make_pair(41, UnlockType::kShip)] = 22;
        map[std::make_pair(42, UnlockType::kShip)] = 23;
        map[std::make_pair(43, UnlockType::kShip)] = 75;
        map[std::make_pair(44, UnlockType::kShip)] = 76;
        map[std::make_pair(45, UnlockType::kShip)] = 77;
        map[std::make_pair(46, UnlockType::kShip)] = 24;
        map[std::make_pair(47, UnlockType::kShip)] = 59;
        map[std::make_pair(48, UnlockType::kShip)] = 83;
        map[std::make_pair(80, UnlockType::kShip)] = 39;
        map[std::make_pair(81, UnlockType::kShip)] = 6;
        map[std::make_pair(82, UnlockType::kShip)] = 6;
        map[std::make_pair(83, UnlockType::kShip)] = 33;
        map[std::make_pair(84, UnlockType::kShip)] = 33;
        map[std::make_pair(85, UnlockType::kShip)] = 33;
        map[std::make_pair(86, UnlockType::kShip)] = 4;
        map[std::make_pair(87, UnlockType::kShip)] = 40;
        map[std::make_pair(88, UnlockType::kShip)] = 25;
        map[std::make_pair(89, UnlockType::kShip)] = 25;
        map[std::make_pair(90, UnlockType::kShip)] = 25;
        for (int i = 91; i < 136; i++)
        {
            map[std::make_pair(i, UnlockType::kShip)] = 2;
        }
        map[std::make_pair(136, UnlockType::kShip)] = 7;
        map[std::make_pair(137, UnlockType::kShip)] = 7;
        map[std::make_pair(138, UnlockType::kShip)] = 4;
        map[std::make_pair(139, UnlockType::kShip)] = 4;
        map[std::make_pair(140, UnlockType::kShip)] = 4;
        map[std::make_pair(141, UnlockType::kShip)] = 4;
        map[std::make_pair(142, UnlockType::kShip)] = 4;
        map[std::make_pair(143, UnlockType::kShip)] = 4;
        map[std::make_pair(144, UnlockType::kShip)] = 1;
        map[std::make_pair(145, UnlockType::kShip)] = 1;
        map[std::make_pair(146, UnlockType::kShip)] = 1;
        map[std::make_pair(147, UnlockType::kShip)] = 1;
        map[std::make_pair(148, UnlockType::kShip)] = 1;
        map[std::make_pair(149, UnlockType::kShip)] = 1;
        map[std::make_pair(150, UnlockType::kShip)] = 1;
        map[std::make_pair(151, UnlockType::kShip)] = 1;
        map[std::make_pair(152, UnlockType::kShip)] = 1;
        map[std::make_pair(153, UnlockType::kShip)] = 1;
        map[std::make_pair(154, UnlockType::kShip)] = 1;
        map[std::make_pair(155, UnlockType::kShip)] = 0;
        map[std::make_pair(156, UnlockType::kShip)] = 0;
        map[std::make_pair(157, UnlockType::kShip)] = 0;
        map[std::make_pair(158, UnlockType::kShip)] = 0;
        map[std::make_pair(159, UnlockType::kShip)] = 0;
        map[std::make_pair(160, UnlockType::kShip)] = 0;
        map[std::make_pair(161, UnlockType::kShip)] = 0;
        map[std::make_pair(162, UnlockType::kShip)] = 0;
        map[std::make_pair(163, UnlockType::kShip)] = 0;
        map[std::make_pair(164, UnlockType::kShip)] = 0;
        map[std::make_pair(166, UnlockType::kShip)] = 37;
        map[std::make_pair(167, UnlockType::kShip)] = 37;
        map[std::make_pair(168, UnlockType::kShip)] = 37;
        map[std::make_pair(169, UnlockType::kShip)] = 37;

        map[std::make_pair(30, UnlockType::kBall)] = 27;
        map[std::make_pair(31, UnlockType::kBall)] = 81;
        map[std::make_pair(32, UnlockType::kBall)] = 28;
        map[std::make_pair(33, UnlockType::kBall)] = 71;
        map[std::make_pair(34, UnlockType::kBall)] = 72;
        map[std::make_pair(35, UnlockType::kBall)] = 64;
        map[std::make_pair(36, UnlockType::kBall)] = 64;
        map[std::make_pair(37, UnlockType::kBall)] = 73;
        map[std::make_pair(38, UnlockType::kBall)] = 31;
        map[std::make_pair(54, UnlockType::kBall)] = 41;
        map[std::make_pair(55, UnlockType::kBall)] = 41;
        map[std::make_pair(56, UnlockType::kBall)] = 42;
        map[std::make_pair(57, UnlockType::kBall)] = 42;
        map[std::make_pair(58, UnlockType::kBall)] = 42;
        map[std::make_pair(59, UnlockType::kBall)] = 42;
        map[std::make_pair(60, UnlockType::kBall)] = 5;
        map[std::make_pair(61, UnlockType::kBall)] = 5;
        map[std::make_pair(62, UnlockType::kBall)] = 43;
        map[std::make_pair(63, UnlockType::kBall)] = 44;
        map[std::make_pair(64, UnlockType::kBall)] = 45;
        map[std::make_pair(65, UnlockType::kBall)] = 34;
        map[std::make_pair(66, UnlockType::kBall)] = 39;
        map[std::make_pair(67, UnlockType::kBall)] = 39;
        map[std::make_pair(68, UnlockType::kBall)] = 46;
        map[std::make_pair(69, UnlockType::kBall)] = 2;
        map[std::make_pair(70, UnlockType::kBall)] = 33;
        map[std::make_pair(71, UnlockType::kBall)] = 33;
        map[std::make_pair(72, UnlockType::kBall)] = 33;
        map[std::make_pair(73, UnlockType::kBall)] = 2;
        map[std::make_pair(74, UnlockType::kBall)] = 2;
        map[std::make_pair(75, UnlockType::kBall)] = 2;
        map[std::make_pair(76, UnlockType::kBall)] = 2;
        map[std::make_pair(77, UnlockType::kBall)] = 2;
        map[std::make_pair(78, UnlockType::kBall)] = 2;
        map[std::make_pair(79, UnlockType::kBall)] = 2;
        map[std::make_pair(80, UnlockType::kBall)] = 2;
        map[std::make_pair(81, UnlockType::kBall)] = 2;
        map[std::make_pair(82, UnlockType::kBall)] = 2;
        map[std::make_pair(83, UnlockType::kBall)] = 2;
        map[std::make_pair(84, UnlockType::kBall)] = 2;
        map[std::make_pair(85, UnlockType::kBall)] = 2;
        map[std::make_pair(86, UnlockType::kBall)] = 2;
        map[std::make_pair(87, UnlockType::kBall)] = 2;
        map[std::make_pair(88, UnlockType::kBall)] = 2;
        map[std::make_pair(89, UnlockType::kBall)] = 2;
        map[std::make_pair(90, UnlockType::kBall)] = 2;
        map[std::make_pair(91, UnlockType::kBall)] = 2;
        map[std::make_pair(92, UnlockType::kBall)] = 2;
        map[std::make_pair(93, UnlockType::kBall)] = 0;
        map[std::make_pair(94, UnlockType::kBall)] = 0;
        map[std::make_pair(95, UnlockType::kBall)] = 0;
        map[std::make_pair(96, UnlockType::kBall)] = 0;
        map[std::make_pair(97, UnlockType::kBall)] = 0;
        map[std::make_pair(98, UnlockType::kBall)] = 0;
        map[std::make_pair(99, UnlockType::kBall)] = 0;
        map[std::make_pair(100, UnlockType::kBall)] = 0;
        map[std::make_pair(101, UnlockType::kBall)] = 0;
        map[std::make_pair(102, UnlockType::kBall)] = 0;
        map[std::make_pair(103, UnlockType::kBall)] = 0;
        map[std::make_pair(104, UnlockType::kBall)] = 0;
        map[std::make_pair(105, UnlockType::kBall)] = 0;
        map[std::make_pair(106, UnlockType::kBall)] = 0;
        map[std::make_pair(107, UnlockType::kBall)] = 0;
        map[std::make_pair(108, UnlockType::kBall)] = 0;
        map[std::make_pair(109, UnlockType::kBall)] = 0;
        map[std::make_pair(110, UnlockType::kBall)] = 9;
        map[std::make_pair(111, UnlockType::kBall)] = 1;
        map[std::make_pair(112, UnlockType::kBall)] = 1;
        map[std::make_pair(113, UnlockType::kBall)] = 1;
        map[std::make_pair(114, UnlockType::kBall)] = 4;
        map[std::make_pair(118, UnlockType::kBall)] = 2;
        map[std::make_pair(119, UnlockType::kBall)] = 84;
        map[std::make_pair(120, UnlockType::kBall)] = 91;
        map[std::make_pair(121, UnlockType::kBall)] = 84;
        map[std::make_pair(122, UnlockType::kBall)] = 84;
        map[std::make_pair(123, UnlockType::kBall)] = 84;
        map[std::make_pair(124, UnlockType::kBall)] = 84;
        map[std::make_pair(125, UnlockType::kBall)] = 84;
        map[std::make_pair(127, UnlockType::kBall)] = 85;
        map[std::make_pair(128, UnlockType::kBall)] = 85;
        map[std::make_pair(129, UnlockType::kBall)] = 85;

        map[std::make_pair(29, UnlockType::kUfo)] = 10;
        map[std::make_pair(30, UnlockType::kUfo)] = 78;
        map[std::make_pair(31, UnlockType::kUfo)] = 79;
        map[std::make_pair(32, UnlockType::kUfo)] = 22;
        map[std::make_pair(33, UnlockType::kUfo)] = 59;
        map[std::make_pair(34, UnlockType::kUfo)] = 59;
        map[std::make_pair(35, UnlockType::kUfo)] = 59;
        map[std::make_pair(52, UnlockType::kUfo)] = 5;
        map[std::make_pair(53, UnlockType::kUfo)] = 5;
        map[std::make_pair(54, UnlockType::kUfo)] = 5;
        map[std::make_pair(55, UnlockType::kUfo)] = 5;
        map[std::make_pair(56, UnlockType::kUfo)] = 5;
        map[std::make_pair(57, UnlockType::kUfo)] = 6;
        map[std::make_pair(58, UnlockType::kUfo)] = 7;
        for (int i = 59; i < 95; i++)
        {
            map[std::make_pair(i, UnlockType::kUfo)] = 2;
        }
        map[std::make_pair(95, UnlockType::kUfo)] = 7;
        map[std::make_pair(96, UnlockType::kUfo)] = 7;
        map[std::make_pair(97, UnlockType::kUfo)] = 7;
        map[std::make_pair(98, UnlockType::kUfo)] = 4;
        map[std::make_pair(99, UnlockType::kUfo)] = 4;
        for (int i = 100; i < 116; i++)
        {
            map[std::make_pair(i, UnlockType::kUfo)] = 1;
        }
        for (int i = 116; i < 138; i++)
        {
            map[std::make_pair(i, UnlockType::kUfo)] = 0;
        }
        map[std::make_pair(138, UnlockType::kUfo)] = 6;
        map[std::make_pair(139, UnlockType::kUfo)] = 6;
        map[std::make_pair(140, UnlockType::kUfo)] = 38;
        map[std::make_pair(141, UnlockType::kUfo)] = 38;
        map[std::make_pair(142, UnlockType::kUfo)] = 33;
        map[std::make_pair(143, UnlockType::kUfo)] = 33;
        map[std::make_pair(144, UnlockType::kUfo)] = 33;
        map[std::make_pair(145, UnlockType::kUfo)] = 33;
        map[std::make_pair(146, UnlockType::kUfo)] = 33;
        map[std::make_pair(147, UnlockType::kUfo)] = 2;
        map[std::make_pair(148, UnlockType::kUfo)] = 37;
        map[std::make_pair(149, UnlockType::kUfo)] = 2;
        map[std::make_pair(150, UnlockType::kUfo)] = 86;
        map[std::make_pair(151, UnlockType::kUfo)] = 86;

        map[std::make_pair(24, UnlockType::kWave)] = 66;
        map[std::make_pair(25, UnlockType::kWave)] = 67;
        map[std::make_pair(26, UnlockType::kWave)] = 68;
        map[std::make_pair(27, UnlockType::kWave)] = 69;
        map[std::make_pair(28, UnlockType::kWave)] = 70;
        map[std::make_pair(29, UnlockType::kWave)] = 24;
        map[std::make_pair(30, UnlockType::kWave)] = 58;
        map[std::make_pair(31, UnlockType::kWave)] = 59;
        map[std::make_pair(32, UnlockType::kWave)] = 60;
        map[std::make_pair(33, UnlockType::kWave)] = 61;
        map[std::make_pair(36, UnlockType::kWave)] = 41;
        map[std::make_pair(37, UnlockType::kWave)] = 36;
        map[std::make_pair(38, UnlockType::kWave)] = 5;
        map[std::make_pair(39, UnlockType::kWave)] = 5;
        map[std::make_pair(40, UnlockType::kWave)] = 5;
        map[std::make_pair(41, UnlockType::kWave)] = 47;
        map[std::make_pair(42, UnlockType::kWave)] = 48;
        map[std::make_pair(43, UnlockType::kWave)] = 49;
        map[std::make_pair(44, UnlockType::kWave)] = 6;
        map[std::make_pair(45, UnlockType::kWave)] = 33;
        map[std::make_pair(46, UnlockType::kWave)] = 38;
        for (int i = 48; i < 73; i++)
        {
            map[std::make_pair(i, UnlockType::kWave)] = 2;
        }
        map[std::make_pair(73, UnlockType::kWave)] = 7;
        map[std::make_pair(74, UnlockType::kWave)] = 4;
        map[std::make_pair(75, UnlockType::kWave)] = 4;
        map[std::make_pair(76, UnlockType::kWave)] = 4;
        for (int i = 77; i < 91; i++)
        {
            map[std::make_pair(i, UnlockType::kWave)] = 1;
        }
        map[std::make_pair(91, UnlockType::kWave)] = 0;
        map[std::make_pair(92, UnlockType::kWave)] = 0;
        map[std::make_pair(93, UnlockType::kWave)] = 0;
        map[std::make_pair(94, UnlockType::kWave)] = 0;
        map[std::make_pair(95, UnlockType::kWave)] = 0;
        map[std::make_pair(96, UnlockType::kWave)] = 0;

        map[std::make_pair(18, UnlockType::kRobot)] = 62;
        map[std::make_pair(19, UnlockType::kRobot)] = 63;
        map[std::make_pair(20, UnlockType::kRobot)] = 22;
        map[std::make_pair(21, UnlockType::kRobot)] = 64;
        map[std::make_pair(22, UnlockType::kRobot)] = 59;
        map[std::make_pair(23, UnlockType::kRobot)] = 59;
        map[std::make_pair(24, UnlockType::kRobot)] = 18;
        map[std::make_pair(25, UnlockType::kRobot)] = 19;
        map[std::make_pair(27, UnlockType::kRobot)] = 5;
        map[std::make_pair(28, UnlockType::kRobot)] = 5;
        map[std::make_pair(29, UnlockType::kRobot)] = 25;
        for (int i = 30; i < 60; i++)
        {
            map[std::make_pair(i, UnlockType::kRobot)] = 2;
        }
        map[std::make_pair(60, UnlockType::kRobot)] = 1;
        map[std::make_pair(61, UnlockType::kRobot)] = 1;
        map[std::make_pair(62, UnlockType::kRobot)] = 1;
        map[std::make_pair(63, UnlockType::kRobot)] = 1;
        map[std::make_pair(64, UnlockType::kRobot)] = 1;
        map[std::make_pair(65, UnlockType::kRobot)] = 0;
        map[std::make_pair(66, UnlockType::kRobot)] = 33;
        map[std::make_pair(67, UnlockType::kRobot)] = 33;
        map[std::make_pair(68, UnlockType::kRobot)] = 33;

        map[std::make_pair(11, UnlockType::kSpider)] = 10;
        map[std::make_pair(12, UnlockType::kSpider)] = 29;
        map[std::make_pair(13, UnlockType::kSpider)] = 29;
        map[std::make_pair(14, UnlockType::kSpider)] = 30;
        map[std::make_pair(15, UnlockType::kSpider)] = 59;
        map[std::make_pair(16, UnlockType::kSpider)] = 31;
        map[std::make_pair(18, UnlockType::kSpider)] = 36;
        map[std::make_pair(19, UnlockType::kSpider)] = 36;
        map[std::make_pair(20, UnlockType::kSpider)] = 5;
        map[std::make_pair(21, UnlockType::kSpider)] = 5;
        map[std::make_pair(22, UnlockType::kSpider)] = 5;
        map[std::make_pair(23, UnlockType::kSpider)] = 35;
        for (int i = 24; i < 58; i++)
        {
            map[std::make_pair(i, UnlockType::kSpider)] = 2;
        }
        map[std::make_pair(58, UnlockType::kSpider)] = 1;
        map[std::make_pair(59, UnlockType::kSpider)] = 1;
        map[std::make_pair(60, UnlockType::kSpider)] = 1;
        map[std::make_pair(61, UnlockType::kSpider)] = 1;
        map[std::make_pair(62, UnlockType::kSpider)] = 1;
        map[std::make_pair(63, UnlockType::kSpider)] = 1;
        map[std::make_pair(64, UnlockType::kSpider)] = 1;
        map[std::make_pair(65, UnlockType::kSpider)] = 1;
        map[std::make_pair(66, UnlockType::kSpider)] = 0;
        map[std::make_pair(67, UnlockType::kSpider)] = 0;
        map[std::make_pair(68, UnlockType::kSpider)] = 0;
        map[std::make_pair(69, UnlockType::kSpider)] = 33;

        map[std::make_pair(2, UnlockType::kSwing)] = 5;
        map[std::make_pair(4, UnlockType::kSwing)] = 5;
        map[std::make_pair(5, UnlockType::kSwing)] = 5;
        map[std::make_pair(6, UnlockType::kSwing)] = 34;
        map[std::make_pair(7, UnlockType::kSwing)] = 6;
        map[std::make_pair(8, UnlockType::kSwing)] = 6;
        map[std::make_pair(9, UnlockType::kSwing)] = 33;
        map[std::make_pair(10, UnlockType::kSwing)] = 9;
        map[std::make_pair(11, UnlockType::kSwing)] = 3;
        map[std::make_pair(12, UnlockType::kSwing)] = 3;
        map[std::make_pair(13, UnlockType::kSwing)] = 3;
        for (int i = 14; i < 24; i++)
        {
            map[std::make_pair(i, UnlockType::kSwing)] = 2;
        }
        for (int i = 24; i < 32; i++)
        {
            map[std::make_pair(i, UnlockType::kSwing)] = 1;
        }
        map[std::make_pair(32, UnlockType::kSwing)] = 0;
        map[std::make_pair(33, UnlockType::kSwing)] = 0;
        for (int i = 34; i < 41; i++)
        {
            map[std::make_pair(i, UnlockType::kSwing)] = 2;
        }
        map[std::make_pair(41, UnlockType::kSwing)] = 29;
        map[std::make_pair(42, UnlockType::kSwing)] = 22;
        map[std::make_pair(43, UnlockType::kSwing)] = 22;
        map[std::make_pair(44, UnlockType::kSwing)] = 35;
        map[std::make_pair(45, UnlockType::kSwing)] = 22;
        map[std::make_pair(46, UnlockType::kSwing)] = 29;
        map[std::make_pair(47, UnlockType::kSwing)] = 90;
        map[std::make_pair(48, UnlockType::kSwing)] = 24;
        map[std::make_pair(49, UnlockType::kSwing)] = 92;
        map[std::make_pair(50, UnlockType::kSwing)] = 85;

        map[std::make_pair(2, UnlockType::kJetPack)] = 2;
        map[std::make_pair(3, UnlockType::kJetPack)] = 32;
        map[std::make_pair(4, UnlockType::kJetPack)] = 2;
        map[std::make_pair(5, UnlockType::kJetPack)] = 32;

        map[std::make_pair(8, UnlockType::kSpecial)] = 87;
        map[std::make_pair(10, UnlockType::kSpecial)] = 86;

        auto var = std::make_pair(id, unlock);

        if (map.find(var) != map.end())
        {
            return map[var];
        }
        else
            return -1;
    }

    void createAchievement(int id, UnlockType type, std::string title, std::string description, std::string completed, std::string identifier, int category)
    {

        auto key = gm->iconIdentifier(id, type);

        AchievementManager::sharedState()->addAchievement(identifier, title, description, completed, key, 1);

        AchievementManager::sharedState()->m_achievementUnlocks->setObject(CCString::create(identifier.c_str()), key);

        m_identifiersArray.push_back(identifier);
    }

    void setIconExlusive(int id, IconType type, int accountID)
    {
        this->m_exlusiveIcons.emplace(accountID, IconData{id, type});
    }

    void addStoreItemInfo(int id, UnlockType type, int shop)
    {
        auto key = gm->iconIdentifier(id, type);
        this->m_storeIcons.emplace(key, shop + 1);
    }

    void addStoreItemInfo(int articleID, unsigned int id, unsigned int type, int price, int shop)
    {
        auto eType = static_cast<UnlockType>(type);
        auto itemID = static_cast<int>(id);

        this->addStoreItemInfo(id, eType, shop);
    }

    void addStoreItem(int articleID, int ID, UnlockType itemType, int price, int shop)
    {
        auto sm = GameStatsManager::sharedState();
        sm->addStoreItem(articleID, ID, itemType, price, shop);
        this->addStoreItemInfo(ID, itemType, shop);
    }

    PathType rewardToPathType(const std::string &path)
    {
        std::map<std::string, PathType> map;

        map["pr_1"] = PathType::Fire;
        map["pr_2"] = PathType::Ice;
        map["pr_3"] = PathType::Posion;
        map["pr_4"] = PathType::Shadow;
        map["pr_5"] = PathType::Lava;
        map["pr_6"] = PathType::Earth;
        map["pr_7"] = PathType::Blood;
        map["pr_8"] = PathType::Metal;
        map["pr_9"] = PathType::Light;
        map["pr_10"] = PathType::Soul;

        return map[path];
    }

    void removeGDAchievements()
    {
        AchievementManager::sharedState()->m_platformAchievements->removeAllObjects();
        AchievementManager::sharedState()->m_achievementUnlocks->removeAllObjects();
    }

    void removeSpecialChestRewards()
    {
        auto gs = GameStatsManager::sharedState();

        std::vector<std::string> arr =
            {
                "151_1",
                "152_1",
                "153_1",
                "52_4",
                "52_3",
                "53_4",
                "85_2",
                "36_6",
                "44_5"};

        for (int i = 0; i < arr.size(); i++)
        {
            GameStatsManager::sharedState()->m_allSpecialChestItems->removeObjectForKey(arr[i]);
        }
    }

    void setData()
    {
        this->addStoreItems();
        this->setAllAchievements();

        this->setIconExlusive(509, IconType::Cube, 74);

        m_loginFreeIcons = {
            {502, IconType::Cube},
            {126, IconType::Ball},
            {45, IconType::Swing},
            {10, IconType::Special}
            };
    }
    void addStoreItems()
    {
        // 1 cube
        // 2 col 1
        // 3 col 2
        // 4 ship
        // 5 ball
        // 6 ufo
        // 7 wave
        // 8 robot
        // 9 spider
        // 10 special
        // 11 death
        // 12 item
        // 13 swing

        this->addStoreItemInfo(34, 0x4Fu, 1u, 500, 0);
        this->addStoreItemInfo(1, 0x4Du, 1u, 1000, 0);
        this->addStoreItemInfo(2, 0x56u, 1u, 1000, 0);
        this->addStoreItemInfo(3, 0x49u, 1u, 1000, 0);
        this->addStoreItemInfo(4, 0x66u, 1u, 1000, 0);
        this->addStoreItemInfo(5, 0x6Bu, 1u, 1000, 0);
        this->addStoreItemInfo(6, 0x1Bu, 4u, 2000, 0);
        this->addStoreItemInfo(7, 0x19u, 6u, 2000, 0);
        this->addStoreItemInfo(8, 0x17u, 6u, 2500, 0);
        this->addStoreItemInfo(9, 0x14u, 5u, 1000, 0);
        this->addStoreItemInfo(10, 0x13u, 5u, 1500, 0);
        this->addStoreItemInfo(11, 0x15u, 7u, 500, 0);
        this->addStoreItemInfo(12, 2u, 9u, 2000, 0);
        this->addStoreItemInfo(13, 0xCu, 8u, 3000, 0);
        this->addStoreItemInfo(14, 8u, 0xBu, 7000, 0);
        this->addStoreItemInfo(15, 0xBu, 0xBu, 7000, 0);
        this->addStoreItemInfo(16, 0x12u, 7u, 2000, 1);
        this->addStoreItemInfo(17, 0x5Eu, 1u, 3000, 1);
        this->addStoreItemInfo(18, 0x55u, 1u, 2500, 1);
        this->addStoreItemInfo(19, 0x60u, 1u, 2000, 1);
        this->addStoreItemInfo(20, 4u, 0xCu, 1000, 1);
        this->addStoreItemInfo(21, 0xEu, 8u, 3000, 1);
        this->addStoreItemInfo(22, 0x15u, 6u, 4000, 1);
        this->addStoreItemInfo(23, 3u, 9u, 3000, 1);
        this->addStoreItemInfo(24, 0x19u, 5u, 2000, 1);
        this->addStoreItemInfo(25, 0xDu, 0xBu, 10000, 1);
        this->addStoreItemInfo(26, 0x23u, 2u, 1000, 0);
        this->addStoreItemInfo(27, 0x24u, 2u, 1000, 0);
        this->addStoreItemInfo(28, 0x27u, 2u, 1000, 1);
        this->addStoreItemInfo(29, 0x28u, 2u, 1000, 1);
        this->addStoreItemInfo(30, 0x27u, 3u, 1000, 0);
        this->addStoreItemInfo(32, 0x20u, 3u, 1000, 1);
        this->addStoreItemInfo(33, 0x29u, 3u, 1000, 1);
        this->addStoreItemInfo(35, 5u, 0xAu, 4000, 0);
        this->addStoreItemInfo(36, 6u, 0xAu, 4000, 0);
        this->addStoreItemInfo(37, 7u, 0xAu, 4000, 1);
        this->addStoreItemInfo(38, 0x75u, 1u, 4000, 2);
        this->addStoreItemInfo(39, 0x76u, 1u, 2000, 2);
        this->addStoreItemInfo(40, 0x77u, 1u, 2000, 2);
        this->addStoreItemInfo(41, 0x78u, 1u, 4000, 2);
        this->addStoreItemInfo(42, 0x79u, 1u, 2000, 2);
        this->addStoreItemInfo(43, 0x7Au, 1u, 2000, 2);
        this->addStoreItemInfo(44, 0x7Bu, 1u, 6000, 2);
        this->addStoreItemInfo(45, 0x7Cu, 1u, 8000, 2);
        this->addStoreItemInfo(46, 0x7Du, 1u, 4000, 2);
        this->addStoreItemInfo(47, 0x7Eu, 1u, 2000, 2);
        this->addStoreItemInfo(48, 0x7Fu, 1u, 6000, 2);
        this->addStoreItemInfo(49, 0x80u, 1u, 8000, 2);
        this->addStoreItemInfo(50, 0x81u, 1u, 6000, 2);
        this->addStoreItemInfo(51, 0x82u, 1u, 4000, 2);
        this->addStoreItemInfo(52, 0x83u, 1u, 4000, 2);
        this->addStoreItemInfo(53, 0x84u, 1u, 4000, 2);
        this->addStoreItemInfo(54, 0x85u, 1u, 8000, 2);
        this->addStoreItemInfo(55, 0x86u, 1u, 6000, 2);
        this->addStoreItemInfo(56, 0x87u, 1u, 6000, 2);
        this->addStoreItemInfo(57, 0x1Eu, 5u, 4000, 2);
        this->addStoreItemInfo(58, 0x1Fu, 5u, 6000, 2);
        this->addStoreItemInfo(59, 0x20u, 5u, 6000, 2);
        this->addStoreItemInfo(60, 0x21u, 5u, 2000, 2);
        this->addStoreItemInfo(61, 0x22u, 5u, 4000, 2);
        this->addStoreItemInfo(62, 0x23u, 5u, 8000, 2);
        this->addStoreItemInfo(63, 0x24u, 5u, 6000, 2);
        this->addStoreItemInfo(64, 0x25u, 5u, 2000, 2);
        this->addStoreItemInfo(65, 0x26u, 5u, 2000, 2);
        this->addStoreItemInfo(66, 0x24u, 4u, 2000, 2);
        this->addStoreItemInfo(67, 0x25u, 4u, 2000, 2);
        this->addStoreItemInfo(68, 0x26u, 4u, 6000, 2);
        this->addStoreItemInfo(69, 0x27u, 4u, 2000, 2);
        this->addStoreItemInfo(70, 0x28u, 4u, 4000, 2);
        this->addStoreItemInfo(71, 0x29u, 4u, 4000, 2);
        this->addStoreItemInfo(72, 0x2Au, 4u, 6000, 2);
        this->addStoreItemInfo(73, 0x2Bu, 4u, 2000, 2);
        this->addStoreItemInfo(74, 0x2Cu, 4u, 6000, 2);
        this->addStoreItemInfo(75, 0x2Du, 4u, 8000, 2);
        this->addStoreItemInfo(76, 0x2Eu, 4u, 4000, 2);
        this->addStoreItemInfo(77, 0x2Fu, 4u, 6000, 2);
        this->addStoreItemInfo(78, 0x30u, 4u, 4000, 2);
        this->addStoreItemInfo(79, 0x1Du, 6u, 6000, 2);
        this->addStoreItemInfo(80, 0x1Eu, 6u, 6000, 2);
        this->addStoreItemInfo(81, 0x1Fu, 6u, 4000, 2);
        this->addStoreItemInfo(82, 0x20u, 6u, 6000, 2);
        this->addStoreItemInfo(83, 0x21u, 6u, 4000, 2);
        this->addStoreItemInfo(84, 0x22u, 6u, 2000, 2);
        this->addStoreItemInfo(85, 0x23u, 6u, 2000, 2);
        this->addStoreItemInfo(86, 0x18u, 7u, 2000, 2);
        this->addStoreItemInfo(87, 0x19u, 7u, 4000, 2);
        this->addStoreItemInfo(88, 0x1Au, 7u, 2000, 2);
        this->addStoreItemInfo(89, 0x1Bu, 7u, 2000, 2);
        this->addStoreItemInfo(90, 0x1Cu, 7u, 6000, 2);
        this->addStoreItemInfo(91, 0x1Du, 7u, 6000, 2);
        this->addStoreItemInfo(92, 0x1Eu, 7u, 4000, 2);
        this->addStoreItemInfo(93, 0x1Fu, 7u, 6000, 2);
        this->addStoreItemInfo(94, 0x20u, 7u, 2000, 2);
        this->addStoreItemInfo(95, 0x21u, 7u, 6000, 2);
        this->addStoreItemInfo(96, 0x12u, 8u, 2000, 2);
        this->addStoreItemInfo(97, 0x13u, 8u, 6000, 2);
        this->addStoreItemInfo(98, 0x14u, 8u, 2000, 2);
        this->addStoreItemInfo(99, 0x15u, 8u, 4000, 2);
        this->addStoreItemInfo(100, 0x16u, 8u, 6000, 2);
        this->addStoreItemInfo(101, 0x17u, 8u, 2000, 2);
        this->addStoreItemInfo(102, 0x18u, 8u, 6000, 2);
        this->addStoreItemInfo(103, 0x19u, 8u, 4000, 2);
        this->addStoreItemInfo(104, 0xBu, 9u, 4000, 2);
        this->addStoreItemInfo(105, 0xCu, 9u, 6000, 2);
        this->addStoreItemInfo(106, 0xDu, 9u, 4000, 2);
        this->addStoreItemInfo(107, 0xEu, 9u, 8000, 2);
        this->addStoreItemInfo(108, 0xFu, 9u, 2000, 2);
        this->addStoreItemInfo(109, 0x10u, 9u, 6000, 2);
        this->addStoreItemInfo(111, 0x8Cu, 1u, 3000, 0);
        this->addStoreItemInfo(112, 0x6Du, 1u, 4000, 0);
        this->addStoreItemInfo(113, 0x71u, 1u, 4000, 0);
        this->addStoreItemInfo(114, 0x28u, 5u, 4000, 0);
        this->addStoreItemInfo(115, 0x23u, 7u, 4000, 0);
        this->addStoreItemInfo(116, 0x21u, 2u, 1000, 0);
        this->addStoreItemInfo(117, 0x1Cu, 3u, 1000, 0);
        this->addStoreItemInfo(118, 0x88u, 1u, 5000, 1);
        this->addStoreItemInfo(119, 0x6Eu, 1u, 5000, 1);
        this->addStoreItemInfo(120, 0x10u, 0xBu, 15000, 1);
        this->addStoreItemInfo(121, 6u, 0xCu, 25000, 5);
        this->addStoreItemInfo(122, 7u, 0xCu, 25000, 5);
        this->addStoreItemInfo(123, 8u, 0xCu, 25000, 5);
        this->addStoreItemInfo(124, 9u, 0xCu, 25000, 5);
        this->addStoreItemInfo(125, 0xAu, 0xCu, 25000, 5);
        this->addStoreItemInfo(126, 0xBu, 0xCu, 25000, 5);
        this->addStoreItemInfo(127, 0xCu, 0xCu, 25000, 5);
        this->addStoreItemInfo(128, 0xDu, 0xCu, 25000, 5);
        this->addStoreItemInfo(129, 0xEu, 0xCu, 25000, 5);
        this->addStoreItemInfo(130, 0xFu, 0xCu, 25000, 5);
        this->addStoreItemInfo(131, 0xA2u, 1u, 3000, 0);
        this->addStoreItemInfo(132, 0x28u, 6u, 3500, 0);
        this->addStoreItemInfo(133, 0x54u, 2u, 1500, 0);
        this->addStoreItemInfo(134, 0x68u, 3u, 2000, 0);
        this->addStoreItemInfo(135, 7u, 0xDu, 5000, 0);
        this->addStoreItemInfo(136, 0x61u, 2u, 2500, 0);
        this->addStoreItemInfo(137, 0x21u, 8u, 3500, 0);
        this->addStoreItemInfo(138, 0x12u, 9u, 4000, 0);
        this->addStoreItemInfo(139, 0x39u, 5u, 3000, 0);
        this->addStoreItemInfo(140, 0x31u, 3u, 2500, 0);
        this->addStoreItemInfo(141, 0x26u, 7u, 5000, 0);
        this->addStoreItemInfo(142, 0xBFu, 1u, 3000, 0);
        this->addStoreItemInfo(143, 0x63u, 2u, 1500, 0);
        this->addStoreItemInfo(144, 0x58u, 3u, 2000, 0);
        this->addStoreItemInfo(145, 0xE5u, 1u, 5000, 1);
        this->addStoreItemInfo(146, 0x56u, 3u, 1500, 1);
        this->addStoreItemInfo(147, 0x3Au, 4u, 4000, 1);
        this->addStoreItemInfo(148, 0x53u, 6u, 3000, 1);
        this->addStoreItemInfo(149, 0x2Du, 8u, 3500, 1);
        this->addStoreItemInfo(150, 0xCu, 0xDu, 6000, 1);
        this->addStoreItemInfo(151, 0xCEu, 1u, 2000, 1);
        this->addStoreItemInfo(152, 0x5Eu, 2u, 1000, 1);
        this->addStoreItemInfo(153, 0x3Cu, 5u, 2500, 1);
        this->addStoreItemInfo(154, 0x6Bu, 5u, 3000, 1);
        this->addStoreItemInfo(155, 0x45u, 9u, 5000, 1);
        this->addStoreItemInfo(156, 0x4Du, 4u, 4000, 1);
        this->addStoreItemInfo(157, 0x31u, 2u, 1000, 1);
        this->addStoreItemInfo(158, 0x46u, 3u, 1000, 1);
        this->addStoreItemInfo(159, 0x89u, 4u, 4000, 1);
        this->addStoreItemInfo(160, 0x1Bu, 0xDu, 6000, 1);
        this->addStoreItemInfo(161, 0xE1u, 1u, 3000, 1);
        this->addStoreItemInfo(162, 0x55u, 3u, 1500, 1);
        this->addStoreItemInfo(163, 0x4Eu, 7u, 2500, 1);
        this->addStoreItemInfo(164, 0x3Au, 9u, 3500, 1);
        this->addStoreItemInfo(165, 0x68u, 6u, 2500, 1);
        this->addStoreItemInfo(166, 0xA8u, 1u, 5000, 3);
        this->addStoreItemInfo(167, 0xE6u, 1u, 6000, 3);
        this->addStoreItemInfo(168, 0xFDu, 1u, 7000, 3);
        this->addStoreItemInfo(169, 0x166u, 1u, 6000, 3);
        this->addStoreItemInfo(170, 0x7Eu, 4u, 7000, 3);
        this->addStoreItemInfo(171, 0x6Fu, 4u, 6000, 3);
        this->addStoreItemInfo(172, 0x90u, 4u, 5000, 3);
        this->addStoreItemInfo(173, 0xA4u, 4u, 7000, 3);
        this->addStoreItemInfo(174, 0x40u, 5u, 5000, 3);
        this->addStoreItemInfo(175, 0x31u, 5u, 6000, 3);
        this->addStoreItemInfo(176, 0x6Bu, 6u, 6000, 3);
        this->addStoreItemInfo(177, 0x88u, 6u, 5000, 3);
        this->addStoreItemInfo(178, 0x56u, 6u, 7000, 3);
        this->addStoreItemInfo(179, 0x4Du, 7u, 7000, 3);
        this->addStoreItemInfo(180, 0x55u, 7u, 6000, 3);
        this->addStoreItemInfo(181, 0x44u, 7u, 5000, 3);
        this->addStoreItemInfo(182, 0x34u, 8u, 6000, 3);
        this->addStoreItemInfo(183, 0x44u, 8u, 7000, 3);
        this->addStoreItemInfo(184, 0x32u, 9u, 6000, 3);
        this->addStoreItemInfo(185, 0x38u, 9u, 6000, 3);
        this->addStoreItemInfo(186, 6u, 0xDu, 6000, 3);
        this->addStoreItemInfo(187, 0x10u, 0xCu, 40000, 3);
        this->addStoreItemInfo(188, 0x11u, 0xCu, 2000, 4);
        this->addStoreItemInfo(189, 0xB5u, 1u, 300, 4);
        this->addStoreItemInfo(190, 0xBAu, 1u, 500, 4);
        this->addStoreItemInfo(191, 0xC4u, 1u, 400, 4);
        this->addStoreItemInfo(192, 0xCBu, 1u, 600, 4);
        this->addStoreItemInfo(193, 0xFAu, 1u, 300, 4);
        this->addStoreItemInfo(194, 0x107u, 1u, 600, 4);
        this->addStoreItemInfo(195, 0x13Au, 1u, 400, 4);
        this->addStoreItemInfo(196, 0x1A5u, 1u, 500, 4);
        this->addStoreItemInfo(197, 0x1BBu, 1u, 600, 4);
        this->addStoreItemInfo(198, 0x1C2u, 1u, 500, 4);
        this->addStoreItemInfo(199, 0x1D7u, 1u, 400, 4);
        this->addStoreItemInfo(200, 0x42u, 4u, 500, 4);
        this->addStoreItemInfo(201, 0x51u, 4u, 600, 4);
        this->addStoreItemInfo(202, 0x7Du, 4u, 500, 4);
        this->addStoreItemInfo(203, 0x81u, 4u, 400, 4);
        this->addStoreItemInfo(204, 0x83u, 4u, 500, 4);
        this->addStoreItemInfo(205, 0xA8u, 4u, 600, 4);
        this->addStoreItemInfo(206, 0x35u, 5u, 600, 4);
        this->addStoreItemInfo(207, 0x62u, 5u, 300, 4);
        this->addStoreItemInfo(208, 0x70u, 5u, 500, 4);
        this->addStoreItemInfo(209, 0x71u, 5u, 400, 4);
        this->addStoreItemInfo(210, 0x74u, 5u, 500, 4);
        this->addStoreItemInfo(211, 0x2Du, 6u, 500, 4);
        this->addStoreItemInfo(212, 0x34u, 6u, 500, 4);
        this->addStoreItemInfo(213, 0x64u, 6u, 600, 4);
        this->addStoreItemInfo(214, 0x8Cu, 6u, 600, 4);
        this->addStoreItemInfo(215, 0x95u, 6u, 600, 4);
        this->addStoreItemInfo(216, 0x38u, 7u, 400, 4);
        this->addStoreItemInfo(217, 0x41u, 7u, 300, 4);
        this->addStoreItemInfo(218, 0x4Bu, 7u, 500, 4);
        this->addStoreItemInfo(219, 0x57u, 7u, 400, 4);
        this->addStoreItemInfo(220, 0x22u, 8u, 500, 4);
        this->addStoreItemInfo(221, 0x33u, 8u, 500, 4);
        this->addStoreItemInfo(222, 0x3Fu, 8u, 600, 4);
        this->addStoreItemInfo(223, 0x37u, 5u, 300, 4);
        this->addStoreItemInfo(224, 0x1Du, 9u, 500, 4);
        this->addStoreItemInfo(225, 0x36u, 9u, 300, 4);
        this->addStoreItemInfo(226, 0x3Cu, 9u, 400, 4);
        this->addStoreItemInfo(227, 0x41u, 9u, 300, 4);
        this->addStoreItemInfo(228, 0xAu, 0xDu, 500, 4);
        this->addStoreItemInfo(229, 0x1Eu, 0xDu, 500, 4);
        this->addStoreItemInfo(230, 0x28u, 0xDu, 600, 4);
        this->addStoreItemInfo(231, 5u, 0xEu, 600, 4);
        this->addStoreItemInfo(232, 0x4Du, 2u, 100, 4);
        this->addStoreItemInfo(233, 0x47u, 2u, 100, 4);
        this->addStoreItemInfo(234, 0x40u, 2u, 100, 4);
        this->addStoreItemInfo(235, 0x64u, 2u, 100, 4);
        this->addStoreItemInfo(236, 0x59u, 3u, 100, 4);
        this->addStoreItemInfo(237, 0x6Au, 3u, 100, 4);
        this->addStoreItemInfo(238, 0x2Bu, 3u, 100, 4);
        this->addStoreItemInfo(239, 0x48u, 3u, 100, 4);
        this->addStoreItemInfo(240, 0x62u, 2u, 100, 4);
        this->addStoreItemInfo(241, 0x4Du, 3u, 100, 4);
        this->addStoreItemInfo(242, 0x4Au, 2u, 100, 4);
        this->addStoreItemInfo(243, 0x3Bu, 3u, 100, 4);
        this->addStoreItemInfo(244, 0x12u, 0xCu, 15000, 3);
        this->addStoreItemInfo(245, 0x13u, 0xCu, 15000, 3);
        this->addStoreItemInfo(246, 0x14u, 0xCu, 15000, 3);
        this->addStoreItemInfo(247, 2u, 0xFu, 20000, 3);
        this->addStoreItemInfo(248, 3u, 0xFu, 20000, 3);
        this->addStoreItemInfo(249, 4u, 0xFu, 20000, 3);
        this->addStoreItemInfo(250, 5u, 0xFu, 20000, 3);
        this->addStoreItemInfo(251, 6u, 0xFu, 20000, 3);
        this->addStoreItemInfo(252, 0x12u, 0xBu, 1500, 4);
        this->addStoreItemInfo(253, 0x13u, 0xBu, 15000, 3);
        this->addStoreItemInfo(254, 0x1D1u, 1u, 400, 4);
        this->addStoreItemInfo(255, 0x3Eu, 4u, 500, 4);
        this->addStoreItemInfo(256, 0x3Fu, 4u, 300, 4);
        this->addStoreItemInfo(257, 0x51u, 5u, 500, 4);
        this->addStoreItemInfo(258, 0x4Eu, 6u, 300, 4);
        this->addStoreItemInfo(259, 0x50u, 6u, 400, 4);
        this->addStoreItemInfo(260, 0x50u, 7u, 300, 4);
        this->addStoreItemInfo(261, 0x52u, 7u, 500, 4);
        this->addStoreItemInfo(262, 0x31u, 8u, 500, 4);
        this->addStoreItemInfo(263, 0x3Eu, 8u, 300, 4);
        this->addStoreItemInfo(264, 0x40u, 9u, 500, 4);
        this->addStoreItemInfo(265, 0x42u, 9u, 500, 4);
        this->addStoreItemInfo(266, 0x29u, 0xDu, 400, 4);
        this->addStoreItemInfo(267, 0x2Au, 0xDu, 500, 4);
        this->addStoreItemInfo(268, 0x1CFu, 1u, 400, 4);
        this->addStoreItemInfo(269, 0x1D0u, 1u, 500, 4);
        this->addStoreItemInfo(270, 0xB9u, 1u, 6000, 3);
        this->addStoreItemInfo(271, 0xBEu, 1u, 5000, 3);
        this->addStoreItemInfo(272, 0x41u, 5u, 5000, 3);
        this->addStoreItemInfo(273, 0x36u, 5u, 5000, 3);
        this->addStoreItemInfo(274, 0x5Fu, 6u, 7000, 3);
        this->addStoreItemInfo(275, 0x8Du, 6u, 500, 4);
        this->addStoreItemInfo(276, 0x16u, 9u, 400, 4);
        this->addStoreItemInfo(277, 0x122u, 1u, 400, 4);
        this->addStoreItemInfo(278, 0x168u, 1u, 6000, 3);
        this->addStoreItemInfo(279, 0x50u, 4u, 6000, 3);
        this->addStoreItemInfo(280, 0x57u, 4u, 400, 4);
        this->addStoreItemInfo(281, 0x1C8u, 1u, 400, 4);
        this->addStoreItemInfo(282, 0x1E0u, 1u, 5000, 3);
        this->addStoreItemInfo(283, 0x84u, 6u, 6000, 3);
        this->addStoreItemInfo(284, 0x1DEu, 1u, 400, 4);
        this->addStoreItemInfo(285, 0x1DAu, 1u, 300, 4);

        this->addStoreItem(100000, 486, UnlockType::kCube, 1000, 0);
        this->addStoreItem(100001, 488, UnlockType::kCube, 1500, 0);
        this->addStoreItem(100002, 492, UnlockType::kCube, 2000, 0);
        this->addStoreItem(100003, 503, UnlockType::kCube, 1500, 0);
        this->addStoreItem(100004, 506, UnlockType::kCube, 1500, 0);
        this->addStoreItem(100005, 511, UnlockType::kCube, 1000, 0);
        this->addStoreItem(100006, 512, UnlockType::kCube, 1000, 0);
        this->addStoreItem(100007, 123, UnlockType::kBall, 1500, 0);
        this->addStoreItem(100008, 125, UnlockType::kBall, 3000, 0);

        this->addStoreItem(100010, 9, UnlockType::kSpecial, 15000, 3);
        this->addStoreItem(100011, 507, UnlockType::kCube, 5000, 3);
        this->addStoreItem(100012, 48, UnlockType::kSwing, 5000, 3);

        this->addStoreItem(100013, 45, UnlockType::kSwing, 600, 4);
        this->addStoreItem(100014, 46, UnlockType::kSwing, 6000, 1);
        this->addStoreItem(100015, 47, UnlockType::kSwing, 3000, 1);
        this->addStoreItem(100016, 49, UnlockType::kSwing, 500, 4);

        this->addStoreItem(100017, 151, UnlockType::kUfo, 4000, 1);

        this->addStoreItem(100018, 487, UnlockType::kCube, 3000, 1);
        this->addStoreItem(100019, 489, UnlockType::kCube, 500, 4);
        this->addStoreItem(100020, 490, UnlockType::kCube, 300, 4);
        this->addStoreItem(100021, 491, UnlockType::kCube, 4000, 1);
        this->addStoreItem(100022, 493, UnlockType::kCube, 2500, 1);

        this->addStoreItem(100023, 494, UnlockType::kCube, 5000, 3);
        this->addStoreItem(100024, 495, UnlockType::kCube, 700, 4);
        this->addStoreItem(100025, 496, UnlockType::kCube, 500, 4);
        this->addStoreItem(100026, 497, UnlockType::kCube, 2000, 1);

        this->addStoreItem(100027, 498, UnlockType::kCube, 700, 4);
        this->addStoreItem(100028, 499, UnlockType::kCube, 700, 4);

        this->addStoreItem(100029, 500, UnlockType::kCube, 3500, 1);

        this->addStoreItem(100030, 122, UnlockType::kBall, 700, 4);

        this->addStoreItem(100031, 8, UnlockType::kSpecial, 2500, 1);
        this->addStoreItem(100032, 10, UnlockType::kSpecial, 1000, 4);

        this->addStoreItem(100033, 501, UnlockType::kCube, 6000, 3);

        this->addStoreItem(100034, 504, UnlockType::kCube, 500, 4);

        this->addStoreItem(100035, 505, UnlockType::kCube, 3000, 1);

        this->addStoreItem(100036, 508, UnlockType::kCube, 5000, 1);

        this->addStoreItem(100037, 510, UnlockType::kCube, 2500, 1);

        this->addStoreItem(100038, 120, UnlockType::kBall, 3000, 1);
        this->addStoreItem(100039, 121, UnlockType::kBall, 4000, 1);
        this->addStoreItem(100040, 124, UnlockType::kBall, 3000, 1);

        this->addStoreItem(100041, 50, UnlockType::kSwing, 6000, 3);

        this->addStoreItem(100042, 517, UnlockType::kCube, 3000, 1);
        this->addStoreItem(100043, 516, UnlockType::kCube, 700, 4);

        this->addStoreItem(100044, 127, UnlockType::kBall, 7000, 3);
        this->addStoreItem(100045, 128, UnlockType::kBall, 500, 4);
        this->addStoreItem(100009, 129, UnlockType::kBall, 3500, 1);

        this->addStoreItem(100046, 485, UnlockType::kCube, 700, 4);
        this->addStoreItem(100047, 44, UnlockType::kSwing, 2500, 0);
        this->addStoreItem(100048, 150, UnlockType::kUfo, 5000, 1);
        this->addStoreItem(100049, 119, UnlockType::kBall, 4000, 1);

        this->addStoreItem(100050, 513, UnlockType::kCube, 500, 0);
        this->addStoreItem(100051, 514, UnlockType::kCube, 500, 0);
        this->addStoreItem(100052, 515, UnlockType::kCube, 500, 0);

        this->addStoreItem(100053, 126, UnlockType::kBall, 500, 4);
        this->addStoreItem(100054, 502, UnlockType::kCube, 500, 4);
    }

    void setAllAchievements()
    {
        this->createAchievement(
            4, UnlockType::kColor1,
            "Cheating",
            "Complete 'Cheat Codes' in Practice mode",
            "Completed 'Cheat Codes' in Practice mode",
            "geometry.ach.level01a",
            1);

        this->createAchievement(
            5, UnlockType::kCube,
            "Cheat Codes!",
            "Complete 'Cheat Codes' in Normal mode",
            "Completed 'Cheat Codes' in Normal mode",
            "geometry.ach.level01b",
            1);

        this->createAchievement(
            5, UnlockType::kColor1,
            "In a what?",
            "Complete 'Death of Night' in Practice mode",
            "Completed 'Death of Night' in Practice mode",
            "geometry.ach.level02a",
            1);

        this->createAchievement(
            6, UnlockType::kCube,
            "Death of Night!",
            "Complete 'Death of Night' in Normal mode",
            "Completed 'Death of Night' in Normal mode",
            "geometry.ach.level02b",
            1);

        this->createAchievement(
            6, UnlockType::kColor1,
            "Stay a while...",
            "Complete 'Secrets' in Practice mode",
            "Completed 'Secrets' in Practice mode",
            "geometry.ach.level03a",
            1);

        this->createAchievement(
            7, UnlockType::kCube,
            "Secrets!",
            "Complete 'Secrets' in Normal mode",
            "Completed 'Secrets' in Normal mode",
            "geometry.ach.level03b",
            1);

        this->createAchievement(
            7, UnlockType::kColor1,
            "Shaking",
            "Complete 'Earthsplitter' in Practice mode",
            "Completed 'Earthsplitter' in Practice mode",
            "geometry.ach.level04a",
            1);

        this->createAchievement(
            8, UnlockType::kCube,
            "Earthsplitter!",
            "Complete 'Earthsplitter' in Normal mode",
            "Completed 'Earthsplitter' in Normal mode",
            "geometry.ach.level04b",
            1);

        this->createAchievement(
            8, UnlockType::kColor1,
            "A A A A A A A",
            "Complete 'Falling' in Practice mode",
            "Completed 'Falling' in Practice mode",
            "geometry.ach.level05a",
            1);

        this->createAchievement(
            9, UnlockType::kCube,
            "Falling!",
            "Complete 'Falling' in Normal mode",
            "Completed 'Falling' in Normal mode",
            "geometry.ach.level05b",
            1);

        this->createAchievement(
            151, UnlockType::kCube,
            "Ultimate Falling",
            "Collect all 3 Secret Coins on 'Falling'",
            "Collected all 3 Secret Coins on 'Falling'",
            "geometry.ach.lightsync.ultimate01",
            1);

        this->createAchievement(
            105, UnlockType::kUfo,
            "Is this a challenge?",
            "...",
            "Completed the secret level in Normal mode",
            "geometry.ach.lightsync.challenge01",
            1);

        /*
         *
         * Steamrolling
         *
         */

        this->createAchievement(
            47, UnlockType::kCube,
            "Lighted!",
            "Complete level 1-3 in Normal mode",
            "Completed level 1-3 in Normal mode",
            "geometry.ach.steam01",
            1);

        /*
         *
         * Tower
         *
         */

        this->createAchievement(
            240, UnlockType::kCube,
            "The Tower",
            "Complete Tower level 1",
            "Completed Tower level 1",
            "geometry.ach.tower01",
            1);

        this->createAchievement(
            75, UnlockType::kShip,
            "The Sewers",
            "Complete Tower level 2",
            "Completed Tower level 2",
            "geometry.ach.tower02",
            1);

        this->createAchievement(
            222, UnlockType::kCube,
            "The Cellar",
            "Complete Tower level 3",
            "Completed Tower level 3",
            "geometry.ach.tower03",
            1);

        this->createAchievement(
            2, UnlockType::kJetPack,
            "The Secret Hollow",
            "Complete Tower level 4",
            "Completed Tower level 4",
            "geometry.ach.tower04",
            1);

        this->createAchievement(
            233, UnlockType::kCube,
            "I See You",
            "Collect all 3 Secret Coins on Tower level 1",
            "Collected all 3 Secret Coins on Tower level 1",
            "geometry.ach.tower01Coin",
            1);

        this->createAchievement(
            31, UnlockType::kRobot,
            "Ahar, matey!",
            "Collect all 3 Secret Coins on Tower level 2",
            "Collected all 3 Secret Coins on Tower level 2",
            "geometry.ach.tower02Coin",
            1);

        this->createAchievement(
            104, UnlockType::kBall,
            "Well Met!",
            "Collect all 3 Secret Coins on Tower level 3",
            "Collected all 3 Secret Coins on Tower level 3",
            "geometry.ach.tower03Coin",
            1);

        this->createAchievement(
            205, UnlockType::kCube,
            "INTRUSION DETECTED",
            "Collect all 3 Secret Coins on Tower level 4",
            "Collected all 3 Secret Coins on Tower level 4",
            "geometry.ach.tower04Coin",
            1);

        this->createAchievement(
            19, UnlockType::kCube,
            "Reflex Champion",
            "Complete a Demon difficulty level in Normal mode",
            "Completed a Demon difficulty level in Normal mode",
            "geometry.ach.demon01",
            2);

        this->createAchievement(
            20, UnlockType::kCube,
            "Demon Chaser",
            "Complete 2 Demon difficulty levels in Normal mode",
            "Completed 2 Demon difficulty levels in Normal mode",
            "geometry.ach.demon02",
            2);

        this->createAchievement(
            21, UnlockType::kCube,
            "The One",
            "Complete 3 Demon difficulty levels in Normal mode",
            "Completed 3 Demon difficulty levels in Normal mode",
            "geometry.ach.demon03",
            2);

        this->createAchievement(
            22, UnlockType::kCube,
            "Demon Master",
            "Complete 4 Demon difficulty levels in Normal mode",
            "Completed 4 Demon difficulty levels in Normal mode",
            "geometry.ach.demon04",
            2);

        this->createAchievement(
            3, UnlockType::kShip,
            "Demonic Guardian",
            "Complete 5 Demon difficulty levels in Normal mode",
            "Completed 5 Demon difficulty levels in Normal mode",
            "geometry.ach.demon05",
            2);

        this->createAchievement(
            6, UnlockType::kShip,
            "Demonic Overmind",
            "Complete 10 Demon difficulty levels in Normal mode",
            "Completed 10 Demon difficulty levels in Normal mode",
            "geometry.ach.demon06",
            2);

        this->createAchievement(
            8, UnlockType::kShip,
            "Master of Timing",
            "Complete 15 Demon difficulty levels in Normal mode",
            "Completed 15 Demon difficulty levels in Normal mode",
            "geometry.ach.demon07",
            2);

        this->createAchievement(
            5, UnlockType::kBall,
            "Unstoppable!",
            "Complete 20 Demon difficulty levels in Normal mode",
            "Completed 20 Demon difficulty levels in Normal mode",
            "geometry.ach.demon08",
            2);

        this->createAchievement(
            37, UnlockType::kCube,
            "Demolicious!",
            "Complete 30 Demon difficulty levels in Normal mode",
            "Completed 30 Demon difficulty levels in Normal mode",
            "geometry.ach.demon09",
            2);

        this->createAchievement(
            10, UnlockType::kBall,
            "Give me a CHALLENGE!",
            "Complete 40 Demon difficulty levels in Normal mode",
            "Completed 40 Demon difficulty levels in Normal mode",
            "geometry.ach.demon10",
            2);

        this->createAchievement(
            15, UnlockType::kUfo,
            "Grim Reaper",
            "Complete 50 Demon difficulty levels in Normal mode",
            "Completed 50 Demon difficulty levels in Normal mode",
            "geometry.ach.demon11",
            2);

        this->createAchievement(
            35, UnlockType::kUfo,
            "You fear nothing",
            "Complete 60 Demon difficulty levels in Normal mode",
            "Completed 60 Demon difficulty levels in Normal mode",
            "geometry.ach.demon12",
            2);

        this->createAchievement(
            28, UnlockType::kRobot,
            "Like the devil",
            "Complete 70 Demon difficulty levels in Normal mode",
            "Completed 70 Demon difficulty levels in Normal mode",
            "geometry.ach.demon13",
            2);

        this->createAchievement(
            53, UnlockType::kColor1,
            "Speed Demon",
            "Complete 80 Demon difficulty levels in Normal mode",
            "Completed 80 Demon difficulty levels in Normal mode",
            "geometry.ach.demon14",
            2);

        this->createAchievement(
            64, UnlockType::kWave,
            "9 circles of hell",
            "Complete 90 Demon difficulty levels in Normal mode",
            "Completed 90 Demon difficulty levels in Normal mode",
            "geometry.ach.demon15",
            2);

        this->createAchievement(
            45, UnlockType::kBall,
            "Is it over yet?",
            "Complete 100 Demon difficulty levels in Normal mode",
            "Completed 100 Demon difficulty levels in Normal mode",
            "geometry.ach.demon16",
            2);

        this->createAchievement(
            3, UnlockType::kSwing,
            "Supersonic speed",
            "Complete 120 Demon difficulty levels in Normal mode",
            "Completed 120 Demon difficulty levels in Normal mode",
            "geometry.ach.demon17",
            2);

        this->createAchievement(
            62, UnlockType::kColor1,
            "Straight fly master",
            "Complete 140 Demon difficulty levels in Normal mode",
            "Completed 140 Demon difficulty levels in Normal mode",
            "geometry.ach.demon18",
            2);

        this->createAchievement(
            65, UnlockType::kRobot,
            "RIP AND TEAR",
            "Complete 160 Demon difficulty levels in Normal mode",
            "Completed 160 Demon difficulty levels in Normal mode",
            "geometry.ach.demon19",
            2);

        this->createAchievement(
            446, UnlockType::kCube,
            "Gotta beat them all",
            "Complete 180 Demon difficulty levels in Normal mode",
            "Completed 180 Demon difficulty levels in Normal mode",
            "geometry.ach.demon20",
            2);

        this->createAchievement(
            53, UnlockType::kRobot,
            "Deal with the devil",
            "Complete 200 Demon difficulty levels in Normal mode",
            "Completed 200 Demon difficulty levels in Normal mode",
            "geometry.ach.demon21",
            2);

        this->createAchievement(
            270, UnlockType::kCube,
            "This is a nightmare",
            "Complete 225 Demon difficulty levels in Normal mode",
            "Completed 225 Demon difficulty levels in Normal mode",
            "geometry.ach.demon22",
            2);

        this->createAchievement(
            46, UnlockType::kSpider,
            "The Chosen One",
            "Complete 250 Demon difficulty levels in Normal mode",
            "Completed 250 Demon difficulty levels in Normal mode",
            "geometry.ach.demon23",
            2);

        this->createAchievement(
            308, UnlockType::kCube,
            "What a bloodbath",
            "Complete 300 Demon difficulty levels in Normal mode",
            "Completed 300 Demon difficulty levels in Normal mode",
            "geometry.ach.demon24",
            2);

        this->createAchievement(
            123, UnlockType::kShip,
            "Tarsorado Demon",
            "Complete 350 Demon difficulty levels in Normal mode",
            "Completed 350 Demon difficulty levels in Normal mode",
            "geometry.ach.demon25",
            2);

        this->createAchievement(
            37, UnlockType::kWave,
            "Insatiable bloodlust",
            "Complete 400 Demon difficulty levels in Normal mode",
            "Completed 400 Demon difficulty levels in Normal mode",
            "geometry.ach.demon26",
            2);

        this->createAchievement(
            459, UnlockType::kCube,
            "GG! :)",
            "Complete 500 Demon difficulty levels in Normal mode",
            "Completed 500 Demon difficulty levels in Normal mode",
            "geometry.ach.demon27",
            2);

        this->createAchievement(
            23, UnlockType::kCube,
            "Oh, Shiny!",
            "Collect 100 Stars",
            "Collected 100 Stars",
            "geometry.ach.stars01",
            2);

        this->createAchievement(
            24, UnlockType::kCube,
            "More Stars!",
            "Collect 200 Stars",
            "Collected 200 Stars",
            "geometry.ach.stars02",
            2);

        this->createAchievement(
            25, UnlockType::kCube,
            "Star Maniac",
            "Collect 300 Stars",
            "Collected 300 Stars",
            "geometry.ach.stars03",
            2);

        this->createAchievement(
            26, UnlockType::kCube,
            "Master Collector",
            "Collect 400 Stars",
            "Collected 400 Stars",
            "geometry.ach.stars04",
            2);

        this->createAchievement(
            4, UnlockType::kShip,
            "Master Collector",
            "Collect 500 Stars",
            "Collected 500 Stars",
            "geometry.ach.stars05",
            2);

        this->createAchievement(
            5, UnlockType::kShip,
            "Epic Master Collector",
            "Collect 600 Stars",
            "Collected 600 Stars",
            "geometry.ach.stars06",
            2);

        this->createAchievement(
            7, UnlockType::kShip,
            "Star Factory",
            "Collect 700 Stars",
            "Collected 700 Stars",
            "geometry.ach.stars07",
            2);

        this->createAchievement(
            28, UnlockType::kCube,
            "Starshine",
            "Collect 800 Stars",
            "Collected 800 Stars",
            "geometry.ach.stars08",
            2);

        this->createAchievement(
            29, UnlockType::kCube,
            "All MINE!",
            "Collect 900 Stars",
            "Collected 900 Stars",
            "geometry.ach.stars09",
            2);

        this->createAchievement(
            30, UnlockType::kCube,
            "MORE SHINY!!!",
            "Collect 1000 Stars",
            "Collected 1000 Stars",
            "geometry.ach.stars10",
            2);

        this->createAchievement(
            18, UnlockType::kShip,
            "Was that all of them?",
            "Collect 1500 Stars",
            "Collected 1500 Stars",
            "geometry.ach.stars11",
            2);

        this->createAchievement(
            9, UnlockType::kBall,
            "Knock knock. Who's there? STARS!",
            "Collect 2000 Stars",
            "Collected 2000 Stars",
            "geometry.ach.stars12",
            2);

        this->createAchievement(
            12, UnlockType::kWave,
            "These are pretty warm...",
            "Collect 2500 Stars",
            "Collected 2500 Stars",
            "geometry.ach.stars13",
            2);

        this->createAchievement(
            61, UnlockType::kCube,
            "They are REALLY warm!",
            "Collect 3000 Stars",
            "Collected 3000 Stars",
            "geometry.ach.stars14",
            2);

        this->createAchievement(
            19, UnlockType::kShip,
            "IT BURNS!!",
            "Collect 3500 Stars",
            "Collected 3500 Stars",
            "geometry.ach.stars15",
            2);

        this->createAchievement(
            9, UnlockType::kWave,
            "GAAAAAAAAAH!",
            "Collect 4000 Stars",
            "Collected 4000 Stars",
            "geometry.ach.stars16",
            2);

        this->createAchievement(
            15, UnlockType::kWave,
            "More Star Achievements?",
            "Collect 4500 Stars",
            "Collected 4500 Stars",
            "geometry.ach.stars17",
            2);

        this->createAchievement(
            28, UnlockType::kColor1,
            "You want me to collect 5000!?",
            "Collect 5000 Stars",
            "Collected 5000 Stars",
            "geometry.ach.stars18",
            2);

        this->createAchievement(
            82, UnlockType::kCube,
            "I should sell these",
            "Collect 5500 Stars",
            "Collected 5500 Stars",
            "geometry.ach.stars19",
            2);

        this->createAchievement(
            27, UnlockType::kBall,
            "Why so many?",
            "Collect 6000 Stars",
            "Collected 6000 Stars",
            "geometry.ach.stars20",
            2);

        this->createAchievement(
            34, UnlockType::kColor1,
            "No Stars for You!",
            "Collect 6500 Stars",
            "Collected 6500 Stars",
            "geometry.ach.stars21",
            2);

        this->createAchievement(
            30, UnlockType::kShip,
            "All Stars Are My Stars",
            "Collect 7000 Stars",
            "Collected 7000 Stars",
            "geometry.ach.stars22",
            2);

        this->createAchievement(
            100, UnlockType::kCube,
            "This is the Last Star Achievement",
            "Collect 7500 Stars",
            "Collected 7500 Stars",
            "geometry.ach.stars23",
            2);

        this->createAchievement(
            4, UnlockType::kSpider,
            "Just Kidding, There Are More",
            "Collect 8000 Stars",
            "Collected 8000 Stars",
            "geometry.ach.stars24",
            2);

        this->createAchievement(
            83, UnlockType::kCube,
            "I Think I Got All the Stars",
            "Collect 9000 Stars",
            "Collected 9000 Stars",
            "geometry.ach.stars25",
            2);

        this->createAchievement(
            8, UnlockType::kRobot,
            "Nope, Found More Over There",
            "Collect 10000 Stars",
            "Collected 10000 Stars",
            "geometry.ach.stars26",
            2);

        this->createAchievement(
            18, UnlockType::kSwing,
            "But Wait, There's Even More!",
            "Collect 12000 Stars",
            "Collected 12000 Stars",
            "geometry.ach.stars27",
            2);

        this->createAchievement(
            51, UnlockType::kWave,
            "PLEASE NO MORE!!!!!",
            "Collect 14000 Stars",
            "Collected 14000 Stars",
            "geometry.ach.stars28",
            2);

        this->createAchievement(
            80, UnlockType::kBall,
            "There's Always More, My Friend",
            "Collect 16000 Stars",
            "Collected 16000 Stars",
            "geometry.ach.stars29",
            2);

        this->createAchievement(
            37, UnlockType::kSwing,
            "Aim for the stars",
            "Collect 18000 Stars",
            "Collected 18000 Stars",
            "geometry.ach.stars30",
            2);

        this->createAchievement(
            19, UnlockType::kSpider,
            "Wish Come True!",
            "Collect 20000 Stars",
            "Collected 20000 Stars",
            "geometry.ach.stars31",
            2);

        this->createAchievement(
            122, UnlockType::kShip,
            "The Stars Align",
            "Collect 22500 Stars",
            "Collected 22500 Stars",
            "geometry.ach.stars32",
            2);

        this->createAchievement(
            73, UnlockType::kUfo,
            "SUPERSTAR",
            "Collect 25000 Stars",
            "Collected 25000 Stars",
            "geometry.ach.stars33",
            2);

        this->createAchievement(
            26, UnlockType::kSwing,
            "One small step for player",
            "Collect 100 Moons",
            "Collected 100 Moons",
            "geometry.ach.moons01",
            2);

        this->createAchievement(
            3, UnlockType::kJetPack,
            "Houston, we have a problem",
            "Collect 200 Moons",
            "Collected 200 Moons",
            "geometry.ach.moons02",
            2);

        this->createAchievement(
            86, UnlockType::kColor1,
            "Is this the moon?",
            "Collect 300 Moons",
            "Collected 300 Moons",
            "geometry.ach.moons03",
            2);

        this->createAchievement(
            207, UnlockType::kCube,
            "This is the moon alright",
            "Collect 400 Moons",
            "Collected 400 Moons",
            "geometry.ach.moons04",
            2);

        this->createAchievement(
            38, UnlockType::kUfo,
            "Dark side of the moon?",
            "Collect 500 Moons",
            "Collected 500 Moons",
            "geometry.ach.moons05",
            2);

        this->createAchievement(
            111, UnlockType::kBall,
            "Nope, just the moon",
            "Collect 600 Moons",
            "Collected 600 Moons",
            "geometry.ach.moons06",
            2);

        this->createAchievement(
            65, UnlockType::kColor2,
            "Moons are like this?",
            "Collect 700 Moons",
            "Collected 700 Moons",
            "geometry.ach.moons07",
            2);

        this->createAchievement(
            158, UnlockType::kCube,
            "They told me it was made of cheese",
            "Collect 800 Moons",
            "Collected 800 Moons",
            "geometry.ach.moons08",
            2);

        this->createAchievement(
            38, UnlockType::kRobot,
            "Fly me to the moon",
            "Collect 900 Moons",
            "Collected 900 Moons",
            "geometry.ach.moons09",
            2);

        this->createAchievement(
            21, UnlockType::kSwing,
            "You're too used to stars",
            "Collect 1000 Moons",
            "Collected 1000 Moons",
            "geometry.ach.moons10",
            2);

        this->createAchievement(
            199, UnlockType::kCube,
            "Maybe I like stars more",
            "Collect 1500 Moons",
            "Collected 1500 Moons",
            "geometry.ach.moons11",
            2);

        this->createAchievement(
            94, UnlockType::kBall,
            "Okay, when do you not get stars?",
            "Collect 2000 Moons",
            "Collected 2000 Moons",
            "geometry.ach.moons12",
            2);

        this->createAchievement(
            4, UnlockType::kJetPack,
            "Once in a blue moon",
            "Collect 2500 Moons",
            "Collected 2500 Moons",
            "geometry.ach.moons13",
            2);

        this->createAchievement(
            91, UnlockType::kColor1,
            "Or on a full moon",
            "Collect 3000 Moons",
            "Collected 3000 Moons",
            "geometry.ach.moons14",
            2);

        this->createAchievement(
            70, UnlockType::kShip,
            "The werewolves are out",
            "Collect 3500 Moons",
            "Collected 3500 Moons",
            "geometry.ach.moons15",
            2);

        this->createAchievement(
            268, UnlockType::kCube,
            "So moons are the new thing",
            "Collect 4000 Moons",
            "Collected 4000 Moons",
            "geometry.ach.moons16",
            2);

        this->createAchievement(
            41, UnlockType::kWave,
            "I've heard of a moon before",
            "Collect 4500 Moons",
            "Collected 4500 Moons",
            "geometry.ach.moons17",
            2);

        this->createAchievement(
            39, UnlockType::kSpider,
            "Death Moon",
            "Collect 5000 Moons",
            "Collected 5000 Moons",
            "geometry.ach.moons18",
            2);

        this->createAchievement(
            144, UnlockType::kUfo,
            "It's gotta be Platformer",
            "Collect 5500 Moons",
            "Collected 5500 Moons",
            "geometry.ach.moons19",
            2);

        this->createAchievement(
            63, UnlockType::kColor1,
            "Yeah, Platformer is my thing",
            "Collect 6000 Moons",
            "Collected 6000 Moons",
            "geometry.ach.moons20",
            2);

        this->createAchievement(
            457, UnlockType::kCube,
            "Moons are kinda neat",
            "Collect 6500 Moons",
            "Collected 6500 Moons",
            "geometry.ach.moons21",
            2);

        this->createAchievement(
            75, UnlockType::kUfo,
            "I like moons",
            "Collect 7000 Moons",
            "Collected 7000 Moons",
            "geometry.ach.moons22",
            2);

        this->createAchievement(
            118, UnlockType::kBall,
            "Moons > Stars",
            "Collect 7500 Moons",
            "Collected 7500 Moons",
            "geometry.ach.moons23",
            2);

        this->createAchievement(
            105, UnlockType::kShip,
            "I love moons!",
            "Collect 8000 Moons",
            "Collected 8000 Moons",
            "geometry.ach.moons24",
            2);

        this->createAchievement(
            38, UnlockType::kSwing,
            "We are going to steal the moon",
            "Collect 9000 Moons",
            "Collected 9000 Moons",
            "geometry.ach.moons25",
            2);

        this->createAchievement(
            62, UnlockType::kBall,
            "One giant leap for mankind",
            "Collect 10000 Moons",
            "Collected 10000 Moons",
            "geometry.ach.moons26",
            2);

        /*
         *
         * Secret Coins
         *
         */

        this->createAchievement(
            31, UnlockType::kCube,
            "Coins?!",
            "Collect 5 Secret Coins",
            "Collected 5 Secret Coins",
            "geometry.ach.coins01",
            2);

        this->createAchievement(
            2, UnlockType::kBall,
            "Maybe behind that block?",
            "Collect 10 Secret Coins",
            "Collected 10 Secret Coins",
            "geometry.ach.coins02",
            2);

        this->createAchievement(
            16, UnlockType::kColor2,
            "I.. Need... MORE!",
            "Collect 15 Secret Coins",
            "Collected 15 Secret Coins",
            "geometry.ach.coins03",
            2);

        this->createAchievement(
            3, UnlockType::kUfo,
            "We wants it!",
            "Collect 20 Secret Coins",
            "Collected 20 Secret Coins",
            "geometry.ach.coins04",
            2);

        this->createAchievement(
            32, UnlockType::kCube,
            "We needs it!",
            "Collect 25 Secret Coins",
            "Collected 25 Secret Coins",
            "geometry.ach.coins05",
            2);

        this->createAchievement(
            15, UnlockType::kColor1,
            "Must have the precious",
            "Collect 30 Secret Coins",
            "Collected 30 Secret Coins",
            "geometry.ach.coins06",
            2);

        /*
         *
         * User Coins
         *
         */

        this->createAchievement(
            2, UnlockType::kWave,
            "What are those!?",
            "Collect 1 User Coins",
            "Collected your first User Coin!",
            "geometry.ach.usercoins01",
            2);

        this->createAchievement(
            49, UnlockType::kCube,
            "The journey begins...",
            "Collect 10 User Coins",
            "Collected 10 User Coins",
            "geometry.ach.usercoins02",
            2);

        this->createAchievement(
            4, UnlockType::kWave,
            "I can't stop!",
            "Collect 20 User Coins",
            "Collected 20 User Coins",
            "geometry.ach.usercoins03",
            2);

        this->createAchievement(
            25, UnlockType::kShip,
            "Mom, get the camera!!!",
            "Collect 30 User Coins",
            "Collected 30 User Coins",
            "geometry.ach.usercoins04",
            2);

        this->createAchievement(
            16, UnlockType::kBall,
            "I feel rich!",
            "Collect 40 User Coins",
            "Collected 40 User Coins",
            "geometry.ach.usercoins05",
            2);

        this->createAchievement(
            13, UnlockType::kUfo,
            "What to buy...",
            "Collect 50 User Coins",
            "Collected 50 User Coins",
            "geometry.ach.usercoins06",
            2);

        this->createAchievement(
            53, UnlockType::kCube,
            "i'll get that for you",
            "Collect 60 User Coins",
            "Collected 60 User Coins",
            "geometry.ach.usercoins07",
            2);

        this->createAchievement(
            6, UnlockType::kWave,
            "Piece of cake",
            "Collect 70 User Coins",
            "Collected 70 User Coins",
            "geometry.ach.usercoins08",
            2);

        this->createAchievement(
            23, UnlockType::kShip,
            "We're gonna need a bigger boat",
            "Collect 80 User Coins",
            "Collected 80 User Coins",
            "geometry.ach.usercoins09",
            2);

        this->createAchievement(
            17, UnlockType::kBall,
            "Got coins?",
            "Collect 90 User Coins",
            "Collected 90 User Coins",
            "geometry.ach.usercoins10",
            2);
        this->createAchievement(
            6, UnlockType::kRobot,
            "So... greed much?",
            "Collect 100 User Coins",
            "Collected 100 User Coins",
            "geometry.ach.usercoins11",
            2);

        this->createAchievement(
            54, UnlockType::kCube,
            "MAX COINS!",
            "Collect 110 User Coins",
            "Collected 110 User Coins",
            "geometry.ach.usercoins12",
            2);

        this->createAchievement(
            7, UnlockType::kWave,
            "Just kidding...",
            "Collect 120 User Coins",
            "Collected 120 User Coins",
            "geometry.ach.usercoins13",
            2);

        this->createAchievement(
            21, UnlockType::kShip,
            "I think there's one left",
            "Collect 130 User Coins",
            "Collected 130 User Coins",
            "geometry.ach.usercoins14",
            2);

        this->createAchievement(
            11, UnlockType::kBall,
            "Where did you get those?",
            "Collect 140 User Coins",
            "Collected 140 User Coins",
            "geometry.ach.usercoins15",
            2);

        this->createAchievement(
            52, UnlockType::kBall,
            "So many shinies...",
            "Collect 150 User Coins",
            "Collected 150 User Coins",
            "geometry.ach.usercoins16",
            2);

        this->createAchievement(
            17, UnlockType::kUfo,
            "Power level increasing",
            "Collect 160 User Coins",
            "Collected 160 User Coins",
            "geometry.ach.usercoins17",
            2);

        this->createAchievement(
            10, UnlockType::kWave,
            "Ultra mega coin catcher",
            "Collect 170 User Coins",
            "Collected 170 User Coins",
            "geometry.ach.usercoins18",
            2);

        this->createAchievement(
            22, UnlockType::kShip,
            "Something that rhymes with coin",
            "Collect 180 User Coins",
            "Collected 180 User Coins",
            "geometry.ach.usercoins19",
            2);

        this->createAchievement(
            18, UnlockType::kBall,
            "Will you ever be satisfied?",
            "Collect 190 User Coins",
            "Collected 190 User Coins",
            "geometry.ach.usercoins20",
            2);

        this->createAchievement(
            4, UnlockType::kRobot,
            "Level up! Ultra Greedy...",
            "Collect 200 User Coins",
            "Collected 200 User Coins",
            "geometry.ach.usercoins21",
            2);

        this->createAchievement(
            99, UnlockType::kCube,
            "Something funny about coins",
            "Collect 225 User Coins",
            "Collected 225 User Coins",
            "geometry.ach.usercoins22",
            2);

        this->createAchievement(
            30, UnlockType::kColor1,
            "Who makes these?",
            "Collect 250 User Coins",
            "Collected 250 User Coins",
            "geometry.ach.usercoins23",
            2);

        this->createAchievement(
            8, UnlockType::kSpider,
            "More coins, give reward",
            "Collect 300 User Coins",
            "Collected 300 User Coins",
            "geometry.ach.usercoins24",
            2);

        this->createAchievement(
            32, UnlockType::kColor1,
            "Much coin, very wow",
            "Collect 350 User Coins",
            "Collected 350 User Coins",
            "geometry.ach.usercoins25",
            2);

        this->createAchievement(
            29, UnlockType::kBall,
            "Who has this many coins?",
            "Collect 425 User Coins",
            "Collected 425 User Coins",
            "geometry.ach.usercoins26",
            2);

        this->createAchievement(
            93, UnlockType::kCube,
            "Enough is enough",
            "Collect 500 User Coins",
            "Collected 500 User Coins",
            "geometry.ach.usercoins27",
            2);

        this->createAchievement(
            22, UnlockType::kWave,
            "Stop collecting coins",
            "Collect 600 User Coins",
            "Collected 600 User Coins",
            "geometry.ach.usercoins28",
            2);

        this->createAchievement(
            15, UnlockType::kRobot,
            "Y u take all coin?",
            "Collect 700 User Coins",
            "Collected 700 User Coins",
            "geometry.ach.usercoins29",
            2);

        this->createAchievement(
            33, UnlockType::kShip,
            "Can I have some?",
            "Collect 800 User Coins",
            "Collected 800 User Coins",
            "geometry.ach.usercoins30",
            2);

        this->createAchievement(
            28, UnlockType::kBall,
            "Congratulations, you have them all!",
            "Collect 900 User Coins",
            "Collected 900 User Coins",
            "geometry.ach.usercoins31",
            2);

        this->createAchievement(
            28, UnlockType::kUfo,
            "You have them all again! :O",
            "Collect 1000 User Coins",
            "Collected 1000 User Coins",
            "geometry.ach.usercoins32",
            2);

        this->createAchievement(
            25, UnlockType::kSwing,
            "Just kidding again!",
            "Collect 1200 User Coins",
            "Collected 1200 User Coins",
            "geometry.ach.usercoins33",
            2);

        this->createAchievement(
            59, UnlockType::kColor1,
            "The other side of the coin",
            "Collect 1400 User Coins",
            "Collected 1400 User Coins",
            "geometry.ach.usercoins34",
            2);

        this->createAchievement(
            325, UnlockType::kCube,
            "Just a coin toss away",
            "Collect 1600 User Coins",
            "Collected 1600 User Coins",
            "geometry.ach.usercoins35",
            2);

        this->createAchievement(
            66, UnlockType::kWave,
            "Almighty dollar",
            "Collect 1800 User Coins",
            "Collected 1800 User Coins",
            "geometry.ach.usercoins36",
            2);

        this->createAchievement(
            134, UnlockType::kShip,
            "Have fun, kid!",
            "Collect 2000 User Coins",
            "Collected 2000 User Coins",
            "geometry.ach.usercoins37",
            2);

        this->createAchievement(
            284, UnlockType::kCube,
            "Nickel and dime",
            "Collect 2300 User Coins",
            "Collected 2300 User Coins",
            "geometry.ach.usercoins38",
            2);

        this->createAchievement(
            21, UnlockType::kSpider,
            "Heads or tails",
            "Collect 2600 User Coins",
            "Collected 2600 User Coins",
            "geometry.ach.usercoins39",
            2);

        this->createAchievement(
            41, UnlockType::kRobot,
            "Swag",
            "Collect 3000 User Coins",
            "Collected 3000 User Coins",
            "geometry.ach.usercoins40",
            2);

        /*
         *
         * Map Packs
         *
         */

        /*
         *
         * Gauntlets
         *
         */

        /*
         *
         * Daily Levels
         *
         */

        this->createAchievement(
            267, UnlockType::kCube,
            "What a day...",
            "Complete a Daily level in Normal mode",
            "Completed a Daily level in Normal mode",
            "geometry.ach.daily01",
            1);

        this->createAchievement(
            22, UnlockType::kSwing,
            "Dashing on a daily basis",
            "Complete 25 Daily levels in Normal mode",
            "Completed 25 Daily levels in Normal mode",
            "geometry.ach.daily02",
            1);

        this->createAchievement(
            58, UnlockType::kColor1,
            "My daily bread",
            "Complete 50 Daily levels in Normal mode",
            "Completed 50 Daily levels in Normal mode",
            "geometry.ach.daily03",
            1);

        this->createAchievement(
            403, UnlockType::kCube,
            "A level a day keeps the doctor away",
            "Complete 100 Daily levels in Normal mode",
            "Completed 100 Daily levels in Normal mode",
            "geometry.ach.daily04",
            1);

        this->createAchievement(
            43, UnlockType::kSpider,
            "Hello daily chat",
            "Complete 150 Daily levels in Normal mode",
            "Completed 150 Daily levels in Normal mode",
            "geometry.ach.daily05",
            1);

        this->createAchievement(
            91, UnlockType::kUfo,
            "Do you sleep?",
            "Complete 250 Daily levels in Normal mode",
            "Completed 250 Daily levels in Normal mode",
            "geometry.ach.daily06",
            1);

        this->createAchievement(
            396, UnlockType::kCube,
            "Happy New Year!",
            "Complete 365 Daily levels in Normal mode",
            "Completed 365 Daily levels in Normal mode",
            "geometry.ach.daily07",
            1);

        /*
         *
         * Diamonds
         *
         */

        this->createAchievement(
            31, UnlockType::kColor1,
            "New shinies!?!",
            "Collect 100 Diamonds",
            "Collected 100 Diamonds",
            "geometry.ach.diamonds01",
            2);

        this->createAchievement(
            87, UnlockType::kCube,
            "Sparkle sparkle",
            "Collect 250 Diamonds",
            "Collected 250 Diamonds",
            "geometry.ach.diamonds02",
            2);

        this->createAchievement(
            11, UnlockType::kRobot,
            "This is addictive",
            "Collect 500 Diamonds",
            "Collected 500 Diamonds",
            "geometry.ach.diamonds03",
            2);

        this->createAchievement(
            38, UnlockType::kColor1,
            "DIAMONDS",
            "Collect 1000 Diamonds",
            "Collected 1000 Diamonds",
            "geometry.ach.diamonds04",
            2);

        this->createAchievement(
            19, UnlockType::kWave,
            "Can't stop my shine",
            "Collect 1500 Diamonds",
            "Collected 1500 Diamonds",
            "geometry.ach.diamonds05",
            2);

        this->createAchievement(
            101, UnlockType::kCube,
            "One for you, ten for me",
            "Collect 2000 Diamonds",
            "Collected 2000 Diamonds",
            "geometry.ach.diamonds06",
            2);

        this->createAchievement(
            32, UnlockType::kShip,
            "How many can I carry?",
            "Collect 2500 Diamonds",
            "Collected 2500 Diamonds",
            "geometry.ach.diamonds07",
            2);

        this->createAchievement(
            24, UnlockType::kUfo,
            "House of Diamonds",
            "Collect 3000 Diamonds",
            "Collected 3000 Diamonds",
            "geometry.ach.diamonds08",
            2);

        this->createAchievement(
            17, UnlockType::kWave,
            "Diamond Castle",
            "Collect 4000 Diamonds",
            "Collected 4000 Diamonds",
            "geometry.ach.diamonds09",
            2);

        this->createAchievement(
            10, UnlockType::kDeathEffect,
            "Diamond Master",
            "Collect 5000 Diamonds",
            "Collected 5000 Diamonds",
            "geometry.ach.diamonds10",
            2);

        this->createAchievement(
            159, UnlockType::kCube,
            "Diamond Grandmaster",
            "Collect 6000 Diamonds",
            "Collected 6000 Diamonds",
            "geometry.ach.diamonds11",
            2);

        this->createAchievement(
            82, UnlockType::kColor1,
            "Diamond MVP",
            "Collect 7000 Diamonds",
            "Collected 7000 Diamonds",
            "geometry.ach.diamonds12",
            2);

        this->createAchievement(
            319, UnlockType::kCube,
            "Diamond Legend",
            "Collect 9000 Diamonds",
            "Collected 9000 Diamonds",
            "geometry.ach.diamonds13",
            2);

        this->createAchievement(
            103, UnlockType::kShip,
            "The Diamond GOAT",
            "Collect 11000 Diamonds",
            "Collected 11000 Diamonds",
            "geometry.ach.diamonds14",
            2);

        this->createAchievement(
            52, UnlockType::kColor1,
            "I'ma buy a diamond ring for you",
            "Collect 14000 Diamonds",
            "Collected 14000 Diamonds",
            "geometry.ach.diamonds15",
            2);

        this->createAchievement(
            226, UnlockType::kCube,
            "Iron pickaxe not required",
            "Collect 17000 Diamonds",
            "Collected 17000 Diamonds",
            "geometry.ach.diamonds16",
            2);

        this->createAchievement(
            52, UnlockType::kWave,
            "Shine bright like a diamond",
            "Collect 20000 Diamonds",
            "Collected 20000 Diamonds",
            "geometry.ach.diamonds17",
            2);

        this->createAchievement(
            58, UnlockType::kRobot,
            "Diamond Is Unbreakable",
            "Collect 25000 Diamonds",
            "Collected 25000 Diamonds",
            "geometry.ach.diamonds18",
            2);

        /*
         *
         * lists
         *
         */

        this->createAchievement(
            50, UnlockType::kColor1,
            "Lists?!",
            "Claim a List Reward",
            "Claimed a list reward",
            "geometry.ach.lists01",
            1);

        this->createAchievement(
            173, UnlockType::kCube,
            "I'm Listening",
            "Claim 10 list rewards",
            "Claimed 10 list rewards",
            "geometry.ach.lists02",
            1);

        this->createAchievement(
            52, UnlockType::kBall,
            "List-avaganza!",
            "Claim 25 list rewards",
            "Claimed 25 list rewards",
            "geometry.ach.lists03",
            1);

        this->createAchievement(
            140, UnlockType::kShip,
            "Listen to me!",
            "Claim 50 list rewards",
            "Claimed 50 list rewards",
            "geometry.ach.lists04",
            1);

        this->createAchievement(
            96, UnlockType::kBall,
            "Lists! Lists everywhere!",
            "Claim 100 list rewards",
            "Claimed 100 list rewards",
            "geometry.ach.lists05",
            1);

        this->createAchievement(
            89, UnlockType::kWave,
            "List Whisperer",
            "Claim 150 list rewards",
            "Claimed 150 list rewards",
            "geometry.ach.lists06",
            1);

        this->createAchievement(
            39, UnlockType::kSwing,
            "200 Lists, 1 Legend",
            "Claim 200 list rewards",
            "Claimed 200 list rewards",
            "geometry.ach.lists07",
            1);

        /*
         *
         * online levels
         *
         */

        this->createAchievement(
            11, UnlockType::kColor1,
            "Challenger",
            "Complete a user created level in Normal mode",
            "Completed a user created level in Normal mode",
            "geometry.ach.custom01",
            1);

        this->createAchievement(
            12, UnlockType::kCube,
            "Master",
            "Complete 10 user created levels in Normal mode",
            "Completed 10 user created levels in Normal mode",
            "geometry.ach.custom02",
            1);

        this->createAchievement(
            36, UnlockType::kCube,
            "The Gamer",
            "Complete 50 user created levels in Normal mode",
            "Completed 50 user created levels in Normal mode",
            "geometry.ach.custom03",
            1);

        this->createAchievement(
            13, UnlockType::kShip,
            "Geometrician",
            "Complete 100 user created levels in Normal mode",
            "Completed 100 user created levels in Normal mode",
            "geometry.ach.custom04",
            1);

        this->createAchievement(
            19, UnlockType::kColor1,
            "Spike dodger",
            "Complete 200 user created levels in Normal mode",
            "Completed 200 user created levels in Normal mode",
            "geometry.ach.custom05",
            1);

        this->createAchievement(
            40, UnlockType::kCube,
            "No match for me!",
            "Complete 300 user created levels in Normal mode",
            "Completed 300 user created levels in Normal mode",
            "geometry.ach.custom06",
            1);

        this->createAchievement(
            15, UnlockType::kShip,
            "Bring me their heads!",
            "Complete 500 user created levels in Normal mode",
            "Completed 500 user created levels in Normal mode",
            "geometry.ach.custom07",
            1);

        this->createAchievement(
            17, UnlockType::kShip,
            "Tonight, we dine in GEOMETRY DASH!",
            "Complete 1000 user created levels in Normal mode",
            "Completed 1000 user created levels in Normal mode",
            "geometry.ach.custom08",
            1);

        this->createAchievement(
            148, UnlockType::kShip,
            "Keep going...",
            "Complete 1500 user created levels in Normal mode",
            "Completed 1500 user created levels in Normal mode",
            "geometry.ach.custom09",
            1);

        this->createAchievement(
            164, UnlockType::kCube,
            "No Title!",
            "Complete 2000 user created levels in Normal mode",
            "Completed 2000 user created levels in Normal mode",
            "geometry.ach.custom10",
            1);

        this->createAchievement(
            60, UnlockType::kColor1,
            "You beat them all",
            "Complete 2500 user created levels in Normal mode",
            "Completed 2500 user created levels in Normal mode",
            "geometry.ach.custom11",
            1);

        this->createAchievement(
            161, UnlockType::kCube,
            "Ultimate Dasher",
            "Complete 3000 user created levels in Normal mode",
            "Completed 3000 user created levels in Normal mode",
            "geometry.ach.custom12",
            1);

        this->createAchievement(
            200, UnlockType::kCube,
            "Secret Way!",
            "Complete 4000 user created levels in Normal mode",
            "Completed 4000 user created levels in Normal mode",
            "geometry.ach.custom13",
            1);

        this->createAchievement(
            108, UnlockType::kUfo,
            "Look yonder, kid",
            "Complete 5000 user created levels in Normal mode",
            "Completed 5000 user created levels in Normal mode",
            "geometry.ach.custom14",
            1);

        /*
         *
         * custom
         *
         */

        this->createAchievement(
            13, UnlockType::kCube,
            "Supporter",
            "Have fun :)",
            "You are playing 'Geometry Dash', thanks!",
            "geometry.ach.rate",
            4);

        /*
         *
         * jumps
         *
         */

        this->createAchievement(
            5, UnlockType::kColor2,
            "Bounce",
            "Jump 1000 times",
            "Jumped 1000 times",
            "geometry.ach.jump01",
            3);

        this->createAchievement(
            11, UnlockType::kColor2,
            "I like jumping",
            "Jump 10000 times",
            "Jumped 10000 times",
            "geometry.ach.jump02",
            3);

        this->createAchievement(
            12, UnlockType::kColor2,
            "You jump like a pro!",
            "Jump 20000 times",
            "Jumped 20000 times",
            "geometry.ach.jump03",
            3);

        this->createAchievement(
            5, UnlockType::kUfo,
            "Hop Hop Hop",
            "Jump 50000 times",
            "Jumped 50000 times",
            "geometry.ach.jump04",
            3);

        this->createAchievement(
            13, UnlockType::kBall,
            "Can't stop jumping!!!",
            "Jump 100000 times",
            "Jumped 100000 times",
            "geometry.ach.jump05",
            3);

        this->createAchievement(
            56, UnlockType::kColor1,
            "Jumper",
            "Jump 200000 times",
            "Jumped 200000 times",
            "geometry.ach.jump06",
            3);

        this->createAchievement(
            371, UnlockType::kCube,
            "You need to rest...",
            "Jump 300000 times",
            "Jumped 300000 times",
            "geometry.ach.jump07",
            3);

        this->createAchievement(
            93, UnlockType::kWave,
            "Jumpman",
            "Jump 400000 times",
            "Jumped 400000 times",
            "geometry.ach.jump08",
            3);

        this->createAchievement(
            365, UnlockType::kCube,
            "One hop this time!",
            "Jump 500000 times",
            "Jumped 500000 times",
            "geometry.ach.jump09",
            3);

        this->createAchievement(
            45, UnlockType::kWave,
            "Leaps and bounds",
            "Jump 750000 times",
            "Jumped 750000 times",
            "geometry.ach.jump10",
            3);

        this->createAchievement(
            32, UnlockType::kSwing,
            "Jump King",
            "Jump 1000000 times",
            "Jumped 1000000 times",
            "geometry.ach.jump11",
            3);

        /*
         *
         * Crash
         *
         */

        this->createAchievement(
            6, UnlockType::kColor2,
            "Trial and error",
            "Do 100 attempts",
            "Did 100 attempts",
            "geometry.ach.attempt01",
            3);

        this->createAchievement(
            7, UnlockType::kColor2,
            "Crash Tester",
            "Do 500 attempts",
            "Did 500 attempts",
            "geometry.ach.attempt02",
            3);

        this->createAchievement(
            14, UnlockType::kColor2,
            "You Shall Not Pass!",
            "Do 2000 attempts",
            "Did 2000 attempts",
            "geometry.ach.attempt03",
            3);

        this->createAchievement(
            17, UnlockType::kColor2,
            "Ouch...",
            "Do 10000 attempts",
            "Did 10000 attempts",
            "geometry.ach.attempt04",
            3);

        this->createAchievement(
            3, UnlockType::kWave,
            "That hurts!",
            "Do 20000 attempts",
            "Did 20000 attempts",
            "geometry.ach.attempt05",
            3);

        this->createAchievement(
            341, UnlockType::kCube,
            "Never Give Up",
            "Do 30000 attempts",
            "Did 30000 attempts",
            "geometry.ach.attempt06",
            3);

        this->createAchievement(
            96, UnlockType::kCube,
            "Never Surrender",
            "Do 40000 attempts",
            "Did 40000 attempts",
            "geometry.ach.attempt07",
            3);

        this->createAchievement(
            161, UnlockType::kShip,
            "Mom said it's my turn",
            "Do 60000 attempts",
            "Did 60000 attempts",
            "geometry.ach.attempt08",
            3);

        this->createAchievement(
            407, UnlockType::kCube,
            "If at first you don't succeed",
            "Do 80000 attempts",
            "Did 80000 attempts",
            "geometry.ach.attempt09",
            3);

        this->createAchievement(
            9, UnlockType::kSwing,
            "Stop Trying",
            "Do 100000 attempts",
            "Did 100000 attempts",
            "geometry.ach.attempt10",
            3);

        this->createAchievement(
            117, UnlockType::kBall,
            "This could become a meme",
            "Do 135000 attempts",
            "Did 135000 attempts",
            "geometry.ach.attempt11",
            3);

        this->createAchievement(
            46, UnlockType::kBall,
            "Take a break!",
            "Do 185000 attempts",
            "Did 185000 attempts",
            "geometry.ach.attempt12",
            3);

        this->createAchievement(
            65, UnlockType::kShip,
            "Made an attempt",
            "Do 250000 attempts",
            "Did 250000 attempts",
            "geometry.ach.attempt13",
            3);

        this->createAchievement(
            368, UnlockType::kCube,
            "This is the one",
            "Do 300000 attempts",
            "Did 300000 attempts",
            "geometry.ach.attempt14",
            3);

        /*
         *
         * Likes
         *
         */

        this->createAchievement(
            8, UnlockType::kColor2,
            "Helper",
            "Like an online level",
            "Liked an online level",
            "geometry.ach.like",
            3);

        this->createAchievement(
            23, UnlockType::kColor2,
            "Cleric",
            "Like or Dislike 100 online levels",
            "Liked or Disliked 100 online levels",
            "geometry.ach.like02",
            3);

        this->createAchievement(
            26, UnlockType::kColor2,
            "Watcher",
            "Like or Dislike 500 online levels",
            "Liked or Disliked 500 online levels",
            "geometry.ach.like02b",
            3);

        this->createAchievement(
            22, UnlockType::kColor1,
            "Spymaster",
            "Like or Dislike 1000 online levels",
            "Liked or Disliked 1000 online levels",
            "geometry.ach.like03",
            3);

        this->createAchievement(
            3, UnlockType::kSpecial,
            "The Happy One",
            "Like or Dislike 2000 online levels",
            "Liked or Disliked 2000 online levels",
            "geometry.ach.like04",
            3);

        this->createAchievement(
            271, UnlockType::kCube,
            "Your vote matters!",
            "Like or Dislike 3000 online levels",
            "Liked or Disliked 3000 online levels",
            "geometry.ach.like05",
            3);

        this->createAchievement(
            70, UnlockType::kBall,
            "Critic",
            "Like or Dislike 4000 online levels",
            "Liked or Disliked 4000 online levels",
            "geometry.ach.like06",
            3);

        /*
         *
         * Rate stars
         *
         */

        this->createAchievement(
            9, UnlockType::kColor2,
            "Guide",
            "Rate the stars of an online level",
            "Rated the stars of an online level",
            "geometry.ach.rateDiff",
            3);

        this->createAchievement(
            22, UnlockType::kColor2,
            "Visionary",
            "Rate the stars of 100 online levels",
            "Rated the stars of 100 online levels",
            "geometry.ach.rateDiff02",
            3);

        this->createAchievement(
            5, UnlockType::kWave,
            "Organizer",
            "Rate the stars of 500 online levels",
            "Rated the stars of 500 online levels",
            "geometry.ach.rateDiff02b",
            3);

        this->createAchievement(
            23, UnlockType::kColor1,
            "Guiding Light",
            "Rate the stars of 1000 online levels",
            "Rated the stars of 1000 online levels",
            "geometry.ach.rateDiff03",
            3);

        this->createAchievement(
            57, UnlockType::kCube,
            "Justice!",
            "Rate the stars of 2000 online levels",
            "Rated the stars of 2000 online levels",
            "geometry.ach.rateDiff04",
            3);

        /*
         *
         * Follow creators
         *
         */

        this->createAchievement(
            25, UnlockType::kColor2,
            "Geometry Dash is Love",
            "Follow a creator",
            "Followed a creator!",
            "geometry.ach.followCreator",
            4);

        this->createAchievement(
            24, UnlockType::kColor2,
            "Geometry Dasher",
            "Follow 10 creators",
            "Followed 10 creators!",
            "geometry.ach.followCreator02",
            4);

        this->createAchievement(
            344, UnlockType::kCube,
            "Life is dash",
            "Follow 25 creators",
            "Followed 25 creators!",
            "geometry.ach.followCreator03",
            4);

        this->createAchievement(
            75, UnlockType::kBall,
            "Geometry is me",
            "Follow 50 creators",
            "Followed 50 creators!",
            "geometry.ach.followCreator04",
            4);

        /*
         *
         * Friends
         *
         */
        this->createAchievement(
            26, UnlockType::kColor2,
            "No longer lonely",
            "Add a friend",
            "You added a friend!",
            "geometry.ach.friends01",
            4);

        this->createAchievement(
            27, UnlockType::kColor1,
            "I'm popular!",
            "Add 10 friends",
            "You added 10 friends!",
            "geometry.ach.friends02",
            4);

        this->createAchievement(
            296, UnlockType::kCube,
            "Friends? What friends?",
            "Add 25 friends",
            "You added 25 friends!",
            "geometry.ach.friends03",
            4);

        this->createAchievement(
            272, UnlockType::kColor1,
            "Touched grass",
            "Add 50 friends",
            "You added 50 friends!",
            "geometry.ach.friends04",
            4);

        /*
         *
         * Upload a Level
         *
         */

        this->createAchievement(
            10, UnlockType::kColor2,
            "Creator",
            "Create and submit a custom level",
            "Created and submitted a custom level",
            "geometry.ach.submit",
            4);

        /*
         *
         * Stars in a Level
         *
         */

        this->createAchievement(
            16, UnlockType::kUfo,
            "Geometry Star",
            "Get a star rated level",
            "Got a star rated level",
            "geometry.ach.creator02",
            3);

        /*
         *
         * Have likes
         *
         */

        this->createAchievement(
            63, UnlockType::kCube,
            "Geometry Mechanic",
            "Get 50 Likes on a created level",
            "Got 50 Likes on a created level",
            "geometry.ach.creator03",
            3);

        this->createAchievement(
            46, UnlockType::kCube,
            "Geometry Mechanic",
            "Get 100 Likes on a created level",
            "Got 100 Likes on a created level",
            "geometry.ach.creator01",
            3);

        this->createAchievement(
            72, UnlockType::kBall,
            "Geometry Knower",
            "Get 250 Likes on a created level",
            "Got 250 Likes on a created level",
            "geometry.ach.creator04",
            3);

        this->createAchievement(
            238, UnlockType::kCube,
            "Geometry Influencer",
            "Get 500 Likes on a created level",
            "Got 500 Likes on a created level",
            "geometry.ach.creator05",
            3);

        this->createAchievement(
            275, UnlockType::kCube,
            "Geometry Genius",
            "Get 1000 Likes on a created level",
            "Got 1000 Likes on a created level",
            "geometry.ach.creator06",
            3);

        /*
         *
         * GD Social Media
         *
         */

        this->createAchievement(
            13, UnlockType::kColor2,
            "Number one fan!",
            "Like Geometry Dash on Facebook",
            "Liked Geometry Dash on Facebook",
            "geometry.ach.facebook",
            4);

        this->createAchievement(
            20, UnlockType::kColor2,
            "GeometryTube",
            "Subscribe to RobTop Games on YouTube",
            "Subscribed to RobTop Games on YouTube",
            "geometry.ach.youtube",
            4);

        this->createAchievement(
            31, UnlockType::kColor2,
            "Geometry Bird!",
            "Follow RobTop Games on Twitter",
            "Followed RobTop Games on Twitter",
            "geometry.ach.twitter",
            4);

        /*
         *
         * Player Crashed
         *
         */

        this->createAchievement(
            18, UnlockType::kColor2,
            "So Close",
            "Crash at over 95% on a main level in normal mode",
            "Crashed at over 95%",
            "geometry.ach.special01",
            3);

        /*
         *
         * Players Destroyed
         *
         */

        this->createAchievement(
            19, UnlockType::kColor2,
            "Rampage!",
            "A secret is required",
            "Destroyed a player",
            "geometry.ach.secret01",
            5);

        this->createAchievement(
            41, UnlockType::kCube,
            "Dominating!",
            "A secret is required",
            "Destroyed 50 players",
            "geometry.ach.secret02",
            5);

        this->createAchievement(
            27, UnlockType::kColor2,
            "Ultrakill!",
            "A secret is required",
            "Destroyed 100 players",
            "geometry.ach.secret02b",
            5);

        this->createAchievement(
            39, UnlockType::kCube,
            "Godlike!",
            "A secret is required",
            "Destroyed 200 players",
            "geometry.ach.secret03",
            5);

        this->createAchievement(
            12, UnlockType::kBall,
            "Wickedsick!",
            "A secret is required",
            "Destroyed 500 players",
            "geometry.ach.secret03b",
            5);

        this->createAchievement(
            71, UnlockType::kBall,
            "KILLAMANJARO",
            "A secret is required",
            "Destroyed 750 players",
            "geometry.ach.secret18",
            5);

        /*
         *
         * Secrets
         *
         */

        this->createAchievement(
            21, UnlockType::kColor2,
            "Master Detective",
            "A hidden treasure is required",
            "Found the hidden coin",
            "geometry.ach.secret04",
            5);

        this->createAchievement(
            62, UnlockType::kCube,
            "Oh no...",
            "A secret is required",
            "Found the secret",
            "geometry.ach.secret05",
            5);

        this->createAchievement(
            0, UnlockType::kUnknown,
            "Thief!",
            "A secret is required",
            "Stole the Vault Keepers coin",
            "geometry.ach.secret06",
            5);

        this->createAchievement(
            51, UnlockType::kCube,
            "Thief! Thief!",
            "A secret is required",
            "Found the secret",
            "geometry.ach.secret07",
            5);

        this->createAchievement(
            11, UnlockType::kUfo,
            "Decrypter",
            "A secret is required",
            "Found the secret",
            "geometry.ach.secret08",
            5);

        this->createAchievement(
            2, UnlockType::kRobot,
            "The Unknown",
            "A secret is required",
            "Found the secret",
            "geometry.ach.secret09",
            5);

        this->createAchievement(
            8, UnlockType::kWave,
            "The Unseen",
            "A secret is required",
            "Found the secret",
            "geometry.ach.secret10",
            5);

        this->createAchievement(
            55, UnlockType::kCube,
            "Catch them all!",
            "A secret is required",
            "Found the secret",
            "geometry.ach.secret11",
            5);

        this->createAchievement(
            50, UnlockType::kCube,
            "Nice shot!",
            "A secret is required",
            "Found the secret",
            "geometry.ach.secret12",
            5);

        this->createAchievement(
            20, UnlockType::kShip,
            "Revealing...",
            "A secret is required",
            "Found the secret",
            "geometry.ach.secret13",
            5);

        this->createAchievement(
            12, UnlockType::kUfo,
            "Third eye open...",
            "A secret is required",
            "Found the secret",
            "geometry.ach.secret14",
            5);

        this->createAchievement(
            4, UnlockType::kSpecial,
            "Very clever...",
            "A secret is required",
            "Found the secret",
            "geometry.ach.secret15",
            5);

        this->createAchievement(
            13, UnlockType::kWave,
            "Doomed us all!",
            "A secret is required",
            "Found the secret",
            "geometry.ach.secret16",
            5);

        this->createAchievement(
            64, UnlockType::kCube,
            "Nothing is hidden",
            "A secret is required",
            "Found the secret",
            "geometry.ach.secret17",
            5);

        this->createAchievement(
            2, UnlockType::kSwing,
            "A true memer",
            "A secret is required",
            "Found the secret",
            "geometry.ach.secret19",
            5);

        this->createAchievement(
            80, UnlockType::kCube,
            "Ultimate Energy",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v2.secret01",
            5);

        this->createAchievement(
            78, UnlockType::kCube,
            "Uber Hacker",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v2.secret02",
            5);

        this->createAchievement(
            0, UnlockType::kUnknown,
            "Cold as Ice",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v2.secret03",
            5);

        this->createAchievement(
            81, UnlockType::kCube,
            "Sneaky Sneak",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v2.secret04",
            5);

        this->createAchievement(
            76, UnlockType::kCube,
            "I can count!",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v2.secret05",
            5);

        this->createAchievement(
            108, UnlockType::kCube,
            "Cant be fooled",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v2.secret06",
            5);

        this->createAchievement(
            37, UnlockType::kColor1,
            "Paintbucket",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v2.secret07",
            5);

        this->createAchievement(
            33, UnlockType::kColor2,
            "Burnt Chicken",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v2.secret08",
            5);

        this->createAchievement(
            466, UnlockType::kCube,
            "Nostalgia",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v2.secret09",
            5);

        this->createAchievement(
            163, UnlockType::kShip,
            "Cooked",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v2.secret10",
            5);

        this->createAchievement(
            91, UnlockType::kCube,
            "Gatekeepers Riddle",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v3.secret01",
            5);

        this->createAchievement(
            89, UnlockType::kCube,
            "Gatekeepers Query",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v3.secret02",
            5);

        this->createAchievement(
            38, UnlockType::kColor2,
            "Gatekeepers Code",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v3.secret03",
            5);

        this->createAchievement(
            90, UnlockType::kCube,
            "Gatekeepers Curse",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v3.secret04",
            5);

        this->createAchievement(
            23, UnlockType::kWave,
            "Gatekeepers Vision",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v3.secret05",
            5);

        this->createAchievement(
            26, UnlockType::kSpider,
            "Gatekeepers Enigma",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v3.secret06",
            5);

        this->createAchievement(
            46, UnlockType::kRobot,
            "Gatekeepers Cipher",
            "A secret is required",
            "Found the secret",
            "geometry.ach.v3.secret07",
            5);

        /*
         *
         * Shards
         *
         */

        this->createAchievement(
            95, UnlockType::kCube,
            "Fire Recruit",
            "Collect 5 Fire Shards",
            "Collected 5 Fire Shards",
            "geometry.ach.shardFire01",
            6);

        this->createAchievement(
            24, UnlockType::kBall,
            "Fire Apprentice",
            "Collect 15 Fire Shards",
            "Collected 15 Fire Shards",
            "geometry.ach.shardFire02",
            6);

        this->createAchievement(
            9, UnlockType::kRobot,
            "Fire Guardian",
            "Collect 35 Fire Shards",
            "Collected 35 Fire Shards",
            "geometry.ach.shardFire03",
            6);

        this->createAchievement(
            29, UnlockType::kShip,
            "Fire Champion",
            "Collect 65 Fire Shards",
            "Collected 65 Fire Shards",
            "geometry.ach.shardFire04",
            6);

        this->createAchievement(
            2, UnlockType::kDeathEffect,
            "Fire Master",
            "Collect 100 Fire Shards",
            "Collected 100 Fire Shards",
            "geometry.ach.shardFire05",
            6);

        ///////////////////////////////////////////

        this->createAchievement(
            84, UnlockType::kCube,
            "Ice Recruit",
            "Collect 5 Ice Shards",
            "Collected 5 Ice Shards",
            "geometry.ach.shardIce01",
            6);

        this->createAchievement(
            26, UnlockType::kBall,
            "Ice Apprentice",
            "Collect 15 Ice Shards",
            "Collected 15 Ice Shards",
            "geometry.ach.shardIce02",
            6);

        this->createAchievement(
            6, UnlockType::kSpider,
            "Ice Guardian",
            "Collect 35 Ice Shards",
            "Collected 35 Ice Shards",
            "geometry.ach.shardIce03",
            6);

        this->createAchievement(
            31, UnlockType::kShip,
            "Ice Champion",
            "Collect 65 Ice Shards",
            "Collected 65 Ice Shards",
            "geometry.ach.shardIce04",
            6);

        this->createAchievement(
            9, UnlockType::kDeathEffect,
            "Ice Master",
            "Collect 100 Ice Shards",
            "Collected 100 Ice Shards",
            "geometry.ach.shardIce05",
            6);

        ///////////////////////////////////////////

        this->createAchievement(
            22, UnlockType::kBall,
            "Poison Recruit",
            "Collect 5 Poison Shards",
            "Collected 5 Poison Shards",
            "geometry.ach.shardPoison01",
            6);

        this->createAchievement(
            20, UnlockType::kUfo,
            "Poison Apprentice",
            "Collect 15 Poison Shards",
            "Collected 15 Poison Shards",
            "geometry.ach.shardPoison02",
            6);

        this->createAchievement(
            105, UnlockType::kCube,
            "Poison Guardian",
            "Collect 35 Poison Shards",
            "Collected 35 Poison Shards",
            "geometry.ach.shardPoison03",
            6);

        this->createAchievement(
            5, UnlockType::kSpider,
            "Poison Champion",
            "Collect 65 Poison Shards",
            "Collected 65 Poison Shards",
            "geometry.ach.shardPoison04",
            6);

        this->createAchievement(
            4, UnlockType::kDeathEffect,
            "Poison Master",
            "Collect 100 Poison Shards",
            "Collected 100 Poison Shards",
            "geometry.ach.shardPoison05",
            6);

        ///////////////////////////////////////////

        this->createAchievement(
            20, UnlockType::kWave,
            "Shadow Recruit",
            "Collect 5 Shadow Shards",
            "Collected 5 Shadow Shards",
            "geometry.ach.shardShadow01",
            6);

        this->createAchievement(
            28, UnlockType::kShip,
            "Shadow Apprentice",
            "Collect 15 Shadow Shards",
            "Collected 15 Shadow Shards",
            "geometry.ach.shardShadow02",
            6);

        this->createAchievement(
            26, UnlockType::kUfo,
            "Shadow Guardian",
            "Collect 35 Shadow Shards",
            "Collected 35 Shadow Shards",
            "geometry.ach.shardShadow03",
            6);

        this->createAchievement(
            17, UnlockType::kRobot,
            "Shadow Champion",
            "Collect 65 Shadow Shards",
            "Collected 65 Shadow Shards",
            "geometry.ach.shardShadow04",
            6);

        this->createAchievement(
            5, UnlockType::kDeathEffect,
            "Shadow Master",
            "Collect 100 Shadow Shards",
            "Collected 100 Shadow Shards",
            "geometry.ach.shardShadow05",
            6);

        ///////////////////////////////////////////

        this->createAchievement(
            14, UnlockType::kWave,
            "Lava Recruit",
            "Collect 5 Lava Shards",
            "Collected 5 Lava Shards",
            "geometry.ach.shardLava01",
            6);

        this->createAchievement(
            92, UnlockType::kCube,
            "Lava Apprentice",
            "Collect 15 Lava Shards",
            "Collected 15 Lava Shards",
            "geometry.ach.shardLava02",
            6);

        this->createAchievement(
            7, UnlockType::kRobot,
            "Lava Guardian",
            "Collect 35 Lava Shards",
            "Collected 35 Lava Shards",
            "geometry.ach.shardLava03",
            6);

        this->createAchievement(
            9, UnlockType::kSpider,
            "Lava Champion",
            "Collect 65 Lava Shards",
            "Collected 65 Lava Shards",
            "geometry.ach.shardLava04",
            6);

        this->createAchievement(
            6, UnlockType::kDeathEffect,
            "Lava Master",
            "Collect 100 Lava Shards",
            "Collected 100 Lava Shards",
            "geometry.ach.shardLava05",
            6);

        ///////////////////////////////////////////

        this->createAchievement(
            98, UnlockType::kCube,
            "Bonus Recruit",
            "Collect 5 of each Tier 1 Shard",
            "Collected 5 of each Tier 1 Shard",
            "geometry.ach.shardBonus01",
            6);

        this->createAchievement(
            22, UnlockType::kUfo,
            "Bonus Apprentice",
            "Collect 15 of each Tier 1 Shard",
            "Collected 15 of each Tier 1 Shard",
            "geometry.ach.shardBonus02",
            6);

        this->createAchievement(
            34, UnlockType::kShip,
            "Bonus Guardian",
            "Collect 35 of each Tier 1 Shard",
            "Collected 35 of each Tier 1 Shard",
            "geometry.ach.shardBonus03",
            6);

        this->createAchievement(
            13, UnlockType::kRobot,
            "Bonus Champion",
            "Collect 65 of each Tier 1 Shard",
            "Collected 65 of each Tier 1 Shard",
            "geometry.ach.shardBonus04",
            6);

        this->createAchievement(
            7, UnlockType::kDeathEffect,
            "Bonus Master",
            "Collect 100 of each Tier 1 Shard",
            "Collected 100 of each Tier 1 Shard",
            "geometry.ach.shardBonus05",
            6);

        ///////////////////////////////////////////

        this->createAchievement(
            32, UnlockType::kSpider,
            "Earth Recruit",
            "Collect 5 Earth Shards",
            "Collected 5 Earth Shards",
            "geometry.ach.shardEarth01",
            6);

        this->createAchievement(
            352, UnlockType::kCube,
            "Earth Apprentice",
            "Collect 15 Earth Shards",
            "Collected 15 Earth Shards",
            "geometry.ach.shardEarth02",
            6);

        this->createAchievement(
            43, UnlockType::kWave,
            "Earth Guardian",
            "Collect 35 Earth Shards",
            "Collected 35 Earth Shards",
            "geometry.ach.shardEarth03",
            6);

        this->createAchievement(
            156, UnlockType::kShip,
            "Earth Champion",
            "Collect 65 Earth Shards",
            "Collected 65 Earth Shards",
            "geometry.ach.shardEarth04",
            6);

        this->createAchievement(
            54, UnlockType::kRobot,
            "Earth Master",
            "Collect 100 Earth Shards",
            "Collected 100 Earth Shards",
            "geometry.ach.shardEarth05",
            6);

        ///////////////////////////////////////////

        this->createAchievement(
            165, UnlockType::kCube,
            "Blood Recruit",
            "Collect 5 Blood Shards",
            "Collected 5 Blood Shards",
            "geometry.ach.shardBlood01",
            6);

        this->createAchievement(
            43, UnlockType::kRobot,
            "Blood Apprentice",
            "Collect 15 Blood Shards",
            "Collected 15 Blood Shards",
            "geometry.ach.shardBlood02",
            6);

        this->createAchievement(
            15, UnlockType::kSwing,
            "Blood Guardian",
            "Collect 35 Blood Shards",
            "Collected 35 Blood Shards",
            "geometry.ach.shardBlood03",
            6);

        this->createAchievement(
            59, UnlockType::kWave,
            "Blood Champion",
            "Collect 65 Blood Shards",
            "Collected 65 Blood Shards",
            "geometry.ach.shardBlood04",
            6);

        this->createAchievement(
            45, UnlockType::kSpider,
            "Blood Master",
            "Collect 100 Blood Shards",
            "Collected 100 Blood Shards",
            "geometry.ach.shardBlood05",
            6);

        ///////////////////////////////////////////

        this->createAchievement(
            235, UnlockType::kCube,
            "Metal Recruit",
            "Collect 5 Metal Shards",
            "Collected 5 Metal Shards",
            "geometry.ach.shardMetal01",
            6);

        this->createAchievement(
            50, UnlockType::kWave,
            "Metal Apprentice",
            "Collect 15 Metal Shards",
            "Collected 15 Metal Shards",
            "geometry.ach.shardMetal02",
            6);

        this->createAchievement(
            108, UnlockType::kShip,
            "Metal Guardian",
            "Collect 35 Metal Shards",
            "Collected 35 Metal Shards",
            "geometry.ach.shardMetal03",
            6);

        this->createAchievement(
            117, UnlockType::kUfo,
            "Metal Champion",
            "Collect 65 Metal Shards",
            "Collected 65 Metal Shards",
            "geometry.ach.shardMetal04",
            6);

        this->createAchievement(
            25, UnlockType::kSpider,
            "Metal Master",
            "Collect 100 Metal Shards",
            "Collected 100 Metal Shards",
            "geometry.ach.shardMetal05",
            6);

        ///////////////////////////////////////////

        this->createAchievement(
            74, UnlockType::kUfo,
            "Light Recruit",
            "Collect 5 Light Shards",
            "Collected 5 Light Shards",
            "geometry.ach.shardLight01",
            6);

        this->createAchievement(
            57, UnlockType::kRobot,
            "Light Apprentice",
            "Collect 15 Light Shards",
            "Collected 15 Light Shards",
            "geometry.ach.shardLight02",
            6);

        this->createAchievement(
            55, UnlockType::kSpider,
            "Light Guardian",
            "Collect 35 Light Shards",
            "Collected 35 Light Shards",
            "geometry.ach.shardLight03",
            6);

        this->createAchievement(
            438, UnlockType::kCube,
            "Light Champion",
            "Collect 65 Light Shards",
            "Collected 65 Light Shards",
            "geometry.ach.shardLight04",
            6);

        this->createAchievement(
            102, UnlockType::kBall,
            "Light Master",
            "Collect 100 Light Shards",
            "Collected 100 Light Shards",
            "geometry.ach.shardLight05",
            6);

        ///////////////////////////////////////////

        this->createAchievement(
            78, UnlockType::kShip,
            "Soul Recruit",
            "Collect 5 Soul Shards",
            "Collected 5 Soul Shards",
            "geometry.ach.shardSoul01",
            6);

        this->createAchievement(
            78, UnlockType::kBall,
            "Soul Apprentice",
            "Collect 15 Soul Shards",
            "Collected 15 Soul Shards",
            "geometry.ach.shardSoul02",
            6);

        this->createAchievement(
            35, UnlockType::kSpider,
            "Soul Guardian",
            "Collect 35 Soul Shards",
            "Collected 35 Soul Shards",
            "geometry.ach.shardSoul03",
            6);

        this->createAchievement(
            395, UnlockType::kCube,
            "Soul Champion",
            "Collect 65 Soul Shards",
            "Collected 65 Soul Shards",
            "geometry.ach.shardSoul04",
            6);

        this->createAchievement(
            148, UnlockType::kUfo,
            "Soul Master",
            "Collect 100 Soul Shards",
            "Collected 100 Soul Shards",
            "geometry.ach.shardSoul05",
            6);

        ///////////////////////////////////////////

        this->createAchievement(
            388, UnlockType::kCube,
            "Bonus Initiate",
            "Collect 5 of each Tier 2 Shard",
            "Collected 5 of each Tier 2 Shard",
            "geometry.ach.shardBonusB01",
            6);

        this->createAchievement(
            106, UnlockType::kBall,
            "Bonus Novice",
            "Collect 15 of each Tier 2 Shard",
            "Collected 15 of each Tier 2 Shard",
            "geometry.ach.shardBonusB02",
            6);

        this->createAchievement(
            62, UnlockType::kWave,
            "Bonus Adept",
            "Collect 35 of each Tier 2 Shard",
            "Collected 35 of each Tier 2 Shard",
            "geometry.ach.shardBonusB03",
            6);

        this->createAchievement(
            84, UnlockType::kUfo,
            "Bonus Sage",
            "Collect 65 of each Tier 2 Shard",
            "Collected 65 of each Tier 2 Shard",
            "geometry.ach.shardBonusB04",
            6);

        this->createAchievement(
            20, UnlockType::kDeathEffect,
            "Bonus Paragon",
            "Collect 100 of each Tier 2 Shard",
            "Collected 100 of each Tier 2 Shard",
            "geometry.ach.shardBonusB05",
            6);

        /*
         *
         * Paths
         *
         */

        this->createAchievement(
            213, UnlockType::kCube,
            "Path of Fire",
            "Unlock the Path of Fire",
            "Unlocked the Path of Fire",
            "geometry.ach.path01.00",
            6);

        this->createAchievement(
            48, UnlockType::kColor1,
            "Flame Initiate",
            "Reach Path of Fire Rank 1",
            "Reached Path of Fire Rank 1",
            "geometry.ach.path01.01",
            6);

        this->createAchievement(
            236, UnlockType::kCube,
            "Blaze Adept",
            "Reach Path of Fire Rank 2",
            "Reached Path of Fire Rank 2",
            "geometry.ach.path01.02",
            6);

        this->createAchievement(
            54, UnlockType::kColor1,
            "Firestarter",
            "Reach Path of Fire Rank 3",
            "Reached Path of Fire Rank 3",
            "geometry.ach.path01.03",
            6);

        this->createAchievement(
            60, UnlockType::kWave,
            "Torch Bearer",
            "Reach Path of Fire Rank 4",
            "Reached Path of Fire Rank 4",
            "geometry.ach.path01.04",
            6);

        this->createAchievement(
            51, UnlockType::kColor2,
            "Flame Wielder",
            "Reach Path of Fire Rank 5",
            "Reached Path of Fire Rank 5",
            "geometry.ach.path01.05",
            6);

        this->createAchievement(
            35, UnlockType::kRobot,
            "Fire Conductor",
            "Reach Path of Fire Rank 6",
            "Reached Path of Fire Rank 6",
            "geometry.ach.path01.06",
            6);

        this->createAchievement(
            143, UnlockType::kShip,
            "Inferno Crafter",
            "Reach Path of Fire Rank 7",
            "Reached Path of Fire Rank 7",
            "geometry.ach.path01.07",
            6);

        this->createAchievement(
            46, UnlockType::kWave,
            "Flame Enchanter",
            "Reach Path of Fire Rank 8",
            "Reached Path of Fire Rank 8",
            "geometry.ach.path01.08",
            6);

        this->createAchievement(
            55, UnlockType::kRobot,
            "Firestorm Summoner",
            "Reach Path of Fire Rank 9",
            "Reached Path of Fire Rank 9",
            "geometry.ach.path01.09",
            6);

        this->createAchievement(
            79, UnlockType::kUfo,
            "Flame Master",
            "Reach Path of Fire Rank 10",
            "Reached Path of Fire Rank 10",
            "geometry.ach.path01.10",
            6);

        //////////////////////////

        this->createAchievement(
            49, UnlockType::kSpider,
            "Path of Ice",
            "Unlock the Path of Ice",
            "Unlocked the Path of Ice",
            "geometry.ach.path02.00",
            6);

        this->createAchievement(
            47, UnlockType::kColor2,
            "Frost Novice",
            "Reach Path of Ice Rank 1",
            "Reached Path of Ice Rank 1",
            "geometry.ach.path02.01",
            6);

        this->createAchievement(
            394, UnlockType::kCube,
            "Ice Apprentice",
            "Reach Path of Ice Rank 2",
            "Reached Path of Ice Rank 2",
            "geometry.ach.path02.02",
            6);

        this->createAchievement(
            44, UnlockType::kColor1,
            "Snow Tracker",
            "Reach Path of Ice Rank 3",
            "Reached Path of Ice Rank 3",
            "geometry.ach.path02.03",
            6);

        this->createAchievement(
            66, UnlockType::kBall,
            "Winter Wanderer",
            "Reach Path of Ice Rank 4",
            "Reached Path of Ice Rank 4",
            "geometry.ach.path02.04",
            6);

        this->createAchievement(
            106, UnlockType::kColor1,
            "Frost Forger",
            "Reach Path of Ice Rank 5",
            "Reached Path of Ice Rank 5",
            "geometry.ach.path02.05",
            6);

        this->createAchievement(
            130, UnlockType::kShip,
            "Blizzard Navigator",
            "Reach Path of Ice Rank 6",
            "Reached Path of Ice Rank 6",
            "geometry.ach.path02.06",
            6);

        this->createAchievement(
            135, UnlockType::kUfo,
            "Hailstorm Harbinger",
            "Reach Path of Ice Rank 7",
            "Reached Path of Ice Rank 7",
            "geometry.ach.path02.07",
            6);

        this->createAchievement(
            29, UnlockType::kRobot,
            "Frostbite Guardian",
            "Reach Path of Ice Rank 8",
            "Reached Path of Ice Rank 8",
            "geometry.ach.path02.08",
            6);

        this->createAchievement(
            76, UnlockType::kBall,
            "Arctic Conqueror",
            "Reach Path of Ice Rank 9",
            "Reached Path of Ice Rank 9",
            "geometry.ach.path02.09",
            6);

        this->createAchievement(
            99, UnlockType::kShip,
            "Icebound Master",
            "Reach Path of Ice Rank 10",
            "Reached Path of Ice Rank 10",
            "geometry.ach.path02.10",
            6);

        //////////////////////////

        this->createAchievement(
            274, UnlockType::kCube,
            "Path of Poison",
            "Unlock the Path of Poison",
            "Unlocked the Path of Poison",
            "geometry.ach.path03.00",
            6);

        this->createAchievement(
            73, UnlockType::kColor2,
            "Venom Apprentice",
            "Reach Path of Poison Rank 1",
            "Reached Path of Poison Rank 1",
            "geometry.ach.path03.01",
            6);

        this->createAchievement(
            42, UnlockType::kRobot,
            "Toxin Courier",
            "Reach Path of Poison Rank 2",
            "Reached Path of Poison Rank 2",
            "geometry.ach.path03.02",
            6);

        this->createAchievement(
            79, UnlockType::kColor2,
            "Pestilence Seeker",
            "Reach Path of Poison Rank 3",
            "Reached Path of Poison Rank 3",
            "geometry.ach.path03.03",
            6);

        this->createAchievement(
            8, UnlockType::kSwing,
            "Noxious Nomad",
            "Reach Path of Poison Rank 4",
            "Reached Path of Poison Rank 4",
            "geometry.ach.path03.04",
            6);

        this->createAchievement(
            80, UnlockType::kColor1,
            "Poison Pioneer",
            "Reach Path of Poison Rank 5",
            "Reached Path of Poison Rank 5",
            "geometry.ach.path03.05",
            6);

        this->createAchievement(
            276, UnlockType::kCube,
            "Plague Prodigy",
            "Reach Path of Poison Rank 6",
            "Reached Path of Poison Rank 6",
            "geometry.ach.path03.06",
            6);

        this->createAchievement(
            57, UnlockType::kSpider,
            "Venom Vanguard",
            "Reach Path of Poison Rank 7",
            "Reached Path of Poison Rank 7",
            "geometry.ach.path03.07",
            6);

        this->createAchievement(
            121, UnlockType::kUfo,
            "Toxic Tyrant",
            "Reach Path of Poison Rank 8",
            "Reached Path of Poison Rank 8",
            "geometry.ach.path03.08",
            6);

        this->createAchievement(
            110, UnlockType::kBall,
            "Plague Overlord",
            "Reach Path of Poison Rank 9",
            "Reached Path of Poison Rank 9",
            "geometry.ach.path03.09",
            6);

        this->createAchievement(
            342, UnlockType::kCube,
            "Venomous Master",
            "Reach Path of Poison Rank 10",
            "Reached Path of Poison Rank 10",
            "geometry.ach.path03.10",
            6);

        //////////////////////////

        this->createAchievement(
            188, UnlockType::kCube,
            "Path of Shadow",
            "Unlock the Path of Shadow",
            "Unlocked the Path of Shadow",
            "geometry.ach.path04.00",
            6);

        this->createAchievement(
            93, UnlockType::kColor1,
            "Shadow Initiate",
            "Reach Path of Shadow Rank 1",
            "Reached Path of Shadow Rank 1",
            "geometry.ach.path04.01",
            6);

        this->createAchievement(
            232, UnlockType::kCube,
            "Obscure Apprentice",
            "Reach Path of Shadow Rank 2",
            "Reached Path of Shadow Rank 2",
            "geometry.ach.path04.02",
            6);

        this->createAchievement(
            99, UnlockType::kColor2,
            "Twilight Treader",
            "Reach Path of Shadow Rank 3",
            "Reached Path of Shadow Rank 3",
            "geometry.ach.path04.03",
            6);

        this->createAchievement(
            36, UnlockType::kSpider,
            "Mystic Shade",
            "Reach Path of Shadow Rank 4",
            "Reached Path of Shadow Rank 4",
            "geometry.ach.path04.04",
            6);

        this->createAchievement(
            96, UnlockType::kColor2,
            "Nocturnal Nomad",
            "Reach Path of Shadow Rank 5",
            "Reached Path of Shadow Rank 5",
            "geometry.ach.path04.05",
            6);

        this->createAchievement(
            141, UnlockType::kShip,
            "Veil Wanderer",
            "Reach Path of Shadow Rank 6",
            "Reached Path of Shadow Rank 6",
            "geometry.ach.path04.06",
            6);

        this->createAchievement(
            72, UnlockType::kWave,
            "Ethereal Emissary",
            "Reach Path of Shadow Rank 7",
            "Reached Path of Shadow Rank 7",
            "geometry.ach.path04.07",
            6);

        this->createAchievement(
            61, UnlockType::kBall,
            "Nightfall Navigator",
            "Reach Path of Shadow Rank 8",
            "Reached Path of Shadow Rank 8",
            "geometry.ach.path04.08",
            6);

        this->createAchievement(
            385, UnlockType::kCube,
            "Shadow Sovereign",
            "Reach Path of Shadow Rank 9",
            "Reached Path of Shadow Rank 9",
            "geometry.ach.path04.09",
            6);

        this->createAchievement(
            127, UnlockType::kShip,
            "Darkness Master",
            "Reach Path of Shadow Rank 10",
            "Reached Path of Shadow Rank 10",
            "geometry.ach.path04.10",
            6);

        //////////////////////////

        this->createAchievement(
            60, UnlockType::kShip,
            "Path of Lava",
            "Unlock the Path of Lava",
            "Unlocked the Path of Lava",
            "geometry.ach.path05.00",
            6);

        this->createAchievement(
            56, UnlockType::kColor2,
            "Cinder Seeker",
            "Reach Path of Lava Rank 1",
            "Reached Path of Lava Rank 1",
            "geometry.ach.path05.01",
            6);

        this->createAchievement(
            239, UnlockType::kCube,
            "Crust Breaker",
            "Reach Path of Lava Rank 2",
            "Reached Path of Lava Rank 2",
            "geometry.ach.path05.02",
            6);

        this->createAchievement(
            51, UnlockType::kColor1,
            "Lava Walker",
            "Reach Path of Lava Rank 3",
            "Reached Path of Lava Rank 3",
            "geometry.ach.path05.03",
            6);

        this->createAchievement(
            47, UnlockType::kUfo,
            "Sulfur Sage",
            "Reach Path of Lava Rank 4",
            "Reached Path of Lava Rank 4",
            "geometry.ach.path05.04",
            6);

        this->createAchievement(
            57, UnlockType::kColor1,
            "Brimstone Bridger",
            "Reach Path of Lava Rank 5",
            "Reached Path of Lava Rank 5",
            "geometry.ach.path05.05",
            6);

        this->createAchievement(
            429, UnlockType::kCube,
            "Molten Marauder",
            "Reach Path of Lava Rank 6",
            "Reached Path of Lava Rank 6",
            "geometry.ach.path05.06",
            6);

        this->createAchievement(
            47, UnlockType::kRobot,
            "Volcanic Vanguard",
            "Reach Path of Lava Rank 7",
            "Reached Path of Lava Rank 7",
            "geometry.ach.path05.07",
            6);

        this->createAchievement(
            79, UnlockType::kBall,
            "Ash Ascendant",
            "Reach Path of Lava Rank 8",
            "Reached Path of Lava Rank 8",
            "geometry.ach.path05.08",
            6);

        this->createAchievement(
            221, UnlockType::kCube,
            "Magma Monarch",
            "Reach Path of Lava Rank 9",
            "Reached Path of Lava Rank 9",
            "geometry.ach.path05.09",
            6);

        this->createAchievement(
            28, UnlockType::kSpider,
            "Volcano Master",
            "Reach Path of Lava Rank 10",
            "Reached Path of Lava Rank 10",
            "geometry.ach.path05.10",
            6);

        //////////////////////////

        this->createAchievement(
            227, UnlockType::kCube,
            "Path of Earth",
            "Unlock the Path of Earth",
            "Unlocked the Path of Earth",
            "geometry.ach.path06.00",
            6);

        this->createAchievement(
            65, UnlockType::kColor1,
            "Nature's Novice",
            "Reach Path of Earth Rank 1",
            "Reached Path of Earth Rank 1",
            "geometry.ach.path06.01",
            6);

        this->createAchievement(
            79, UnlockType::kShip,
            "Sprout Whisperer",
            "Reach Path of Earth Rank 2",
            "Reached Path of Earth Rank 2",
            "geometry.ach.path06.02",
            6);

        this->createAchievement(
            68, UnlockType::kColor2,
            "Sapling Sage",
            "Reach Path of Earth Rank 3",
            "Reached Path of Earth Rank 3",
            "geometry.ach.path06.03",
            6);

        this->createAchievement(
            102, UnlockType::kUfo,
            "Terra Tamer",
            "Reach Path of Earth Rank 4",
            "Reached Path of Earth Rank 4",
            "geometry.ach.path06.04",
            6);

        this->createAchievement(
            45, UnlockType::kColor1,
            "Herbal Harbinger",
            "Reach Path of Earth Rank 5",
            "Reached Path of Earth Rank 5",
            "geometry.ach.path06.05",
            6);

        this->createAchievement(
            32, UnlockType::kRobot,
            "Woodland Warden",
            "Reach Path of Earth Rank 6",
            "Reached Path of Earth Rank 6",
            "geometry.ach.path06.06",
            6);

        this->createAchievement(
            53, UnlockType::kWave,
            "Grove Guardian",
            "Reach Path of Earth Rank 7",
            "Reached Path of Earth Rank 7",
            "geometry.ach.path06.07",
            6);

        this->createAchievement(
            77, UnlockType::kBall,
            "Terrain Tempest",
            "Reach Path of Earth Rank 8",
            "Reached Path of Earth Rank 8",
            "geometry.ach.path06.08",
            6);

        this->createAchievement(
            23, UnlockType::kSpider,
            "Earthbound Elder",
            "Reach Path of Earth Rank 9",
            "Reached Path of Earth Rank 9",
            "geometry.ach.path06.09",
            6);

        this->createAchievement(
            247, UnlockType::kCube,
            "Elemental Master",
            "Reach Path of Earth Rank 10",
            "Reached Path of Earth Rank 10",
            "geometry.ach.path06.10",
            6);

        //////////////////////////

        this->createAchievement(
            431, UnlockType::kCube,
            "Path of Blood",
            "Unlock the Path of Blood",
            "Unlocked the Path of Blood",
            "geometry.ach.path07.00",
            6);

        this->createAchievement(
            54, UnlockType::kColor2,
            "Crimson Initiate",
            "Reach Path of Blood Rank 1",
            "Reached Path of Blood Rank 1",
            "geometry.ach.path07.01",
            6);

        this->createAchievement(
            92, UnlockType::kBall,
            "Blood Novice",
            "Reach Path of Blood Rank 2",
            "Reached Path of Blood Rank 2",
            "geometry.ach.path07.02",
            6);

        this->createAchievement(
            53, UnlockType::kColor2,
            "Scarlet Seeker",
            "Reach Path of Blood Rank 3",
            "Reached Path of Blood Rank 3",
            "geometry.ach.path07.03",
            6);

        this->createAchievement(
            23, UnlockType::kSwing,
            "Rouge Ranger",
            "Reach Path of Blood Rank 4",
            "Reached Path of Blood Rank 4",
            "geometry.ach.path07.04",
            6);

        this->createAchievement(
            57, UnlockType::kColor2,
            "Bloodline Baron",
            "Reach Path of Blood Rank 5",
            "Reached Path of Blood Rank 5",
            "geometry.ach.path07.05",
            6);

        this->createAchievement(
            81, UnlockType::kWave,
            "Vein Vanquisher",
            "Reach Path of Blood Rank 6",
            "Reached Path of Blood Rank 6",
            "geometry.ach.path07.06",
            6);

        this->createAchievement(
            53, UnlockType::kSpider,
            "Vampiric Vanguard",
            "Reach Path of Blood Rank 7",
            "Reached Path of Blood Rank 7",
            "geometry.ach.path07.07",
            6);

        this->createAchievement(
            127, UnlockType::kUfo,
            "Crimson King",
            "Reach Path of Blood Rank 8",
            "Reached Path of Blood Rank 8",
            "geometry.ach.path07.08",
            6);

        this->createAchievement(
            237, UnlockType::kCube,
            "Eternal Emperor",
            "Reach Path of Blood Rank 9",
            "Reached Path of Blood Rank 9",
            "geometry.ach.path07.09",
            6);

        this->createAchievement(
            83, UnlockType::kBall,
            "Path of Blood Master",
            "Reach Path of Blood Rank 10",
            "Reached Path of Blood Rank 10",
            "geometry.ach.path07.10",
            6);

        //////////////////////////

        this->createAchievement(
            217, UnlockType::kCube,
            "Path of Metal",
            "Unlock the Path of Metal",
            "Unlocked the Path of Metal",
            "geometry.ach.path08.00",
            6);

        this->createAchievement(
            102, UnlockType::kColor1,
            "Iron Initiate",
            "Reach Path of Metal Rank 1",
            "Reached Path of Metal Rank 1",
            "geometry.ach.path08.01",
            6);

        this->createAchievement(
            51, UnlockType::kSpider,
            "Copper Cadet",
            "Reach Path of Metal Rank 2",
            "Reached Path of Metal Rank 2",
            "geometry.ach.path08.02",
            6);

        this->createAchievement(
            94, UnlockType::kColor2,
            "Silver Seeker",
            "Reach Path of Metal Rank 3",
            "Reached Path of Metal Rank 3",
            "geometry.ach.path08.03",
            6);

        this->createAchievement(
            105, UnlockType::kBall,
            "Cast Crusader",
            "Reach Path of Metal Rank 4",
            "Reached Path of Metal Rank 4",
            "geometry.ach.path08.04",
            6);

        this->createAchievement(
            91, UnlockType::kColor2,
            "Bronze Baron",
            "Reach Path of Metal Rank 5",
            "Reached Path of Metal Rank 5",
            "geometry.ach.path08.05",
            6);

        this->createAchievement(
            150, UnlockType::kShip,
            "Metalwork Maestro",
            "Reach Path of Metal Rank 6",
            "Reached Path of Metal Rank 6",
            "geometry.ach.path08.06",
            6);

        this->createAchievement(
            85, UnlockType::kUfo,
            "Steel Scion",
            "Reach Path of Metal Rank 7",
            "Reached Path of Metal Rank 7",
            "geometry.ach.path08.07",
            6);

        this->createAchievement(
            299, UnlockType::kCube,
            "Titanium Titan",
            "Reach Path of Metal Rank 8",
            "Reached Path of Metal Rank 8",
            "geometry.ach.path08.08",
            6);

        this->createAchievement(
            56, UnlockType::kRobot,
            "Mithril Monarch",
            "Reach Path of Metal Rank 9",
            "Reached Path of Metal Rank 9",
            "geometry.ach.path08.09",
            6);

        this->createAchievement(
            44, UnlockType::kSpider,
            "Path of Metal Master",
            "Reach Path of Metal Rank 10",
            "Reached Path of Metal Rank 10",
            "geometry.ach.path08.10",
            6);

        //////////////////////////

        this->createAchievement(
            93, UnlockType::kBall,
            "Path of Light",
            "Unlock the Path of Light",
            "Unlocked the Path of Light",
            "geometry.ach.path09.00",
            6);

        this->createAchievement(
            71, UnlockType::kColor2,
            "Luminary Learner",
            "Reach Path of Light Rank 1",
            "Reached Path of Light Rank 1",
            "geometry.ach.path09.01",
            6);

        this->createAchievement(
            415, UnlockType::kCube,
            "Shine Seeker",
            "Reach Path of Light Rank 2",
            "Reached Path of Light Rank 2",
            "geometry.ach.path09.02",
            6);

        this->createAchievement(
            105, UnlockType::kColor1,
            "Daylight Dreamer",
            "Reach Path of Light Rank 3",
            "Reached Path of Light Rank 3",
            "geometry.ach.path09.03",
            6);

        this->createAchievement(
            20, UnlockType::kSpider,
            "Shimmering Sage",
            "Reach Path of Light Rank 4",
            "Reached Path of Light Rank 4",
            "geometry.ach.path09.04",
            6);

        this->createAchievement(
            62, UnlockType::kColor2,
            "Heavenly Herald",
            "Reach Path of Light Rank 5",
            "Reached Path of Light Rank 5",
            "geometry.ach.path09.05",
            6);

        this->createAchievement(
            162, UnlockType::kShip,
            "Celestial Champion",
            "Reach Path of Light Rank 6",
            "Reached Path of Light Rank 6",
            "geometry.ach.path09.06",
            6);

        this->createAchievement(
            84, UnlockType::kWave,
            "Aurora Archon",
            "Reach Path of Light Rank 7",
            "Reached Path of Light Rank 7",
            "geometry.ach.path09.07",
            6);

        this->createAchievement(
            42, UnlockType::kSpider,
            "Luminous Lord",
            "Reach Path of Light Rank 8",
            "Reached Path of Light Rank 8",
            "geometry.ach.path09.08",
            6);

        this->createAchievement(
            329, UnlockType::kCube,
            "Divine Dawnbringer",
            "Reach Path of Light Rank 9",
            "Reached Path of Light Rank 9",
            "geometry.ach.path09.09",
            6);

        this->createAchievement(
            114, UnlockType::kShip,
            "Path of Light Master",
            "Reach Path of Light Rank 10",
            "Reached Path of Light Rank 10",
            "geometry.ach.path09.10",
            6);

        //////////////////////////

        this->createAchievement(
            172, UnlockType::kCube,
            "Path of Souls",
            "Unlock the Path of Souls",
            "Unlocked the Path of Souls",
            "geometry.ach.path10.00",
            6);

        this->createAchievement(
            95, UnlockType::kColor1,
            "Ethereal Initiate",
            "Reach Path of Souls Rank 1",
            "Reached Path of Souls Rank 1",
            "geometry.ach.path10.01",
            6);

        this->createAchievement(
            60, UnlockType::kRobot,
            "Spectral Student",
            "Reach Path of Souls Rank 2",
            "Reached Path of Souls Rank 2",
            "geometry.ach.path10.02",
            6);

        this->createAchievement(
            100, UnlockType::kColor2,
            "Soul Seeker",
            "Reach Path of Souls Rank 3",
            "Reached Path of Souls Rank 3",
            "geometry.ach.path10.03",
            6);

        this->createAchievement(
            178, UnlockType::kCube,
            "Spirit Scholar",
            "Reach Path of Souls Rank 4",
            "Reached Path of Souls Rank 4",
            "geometry.ach.path10.04",
            6);

        this->createAchievement(
            103, UnlockType::kColor1,
            "Abyssal Arbitrator",
            "Reach Path of Souls Rank 5",
            "Reached Path of Souls Rank 5",
            "geometry.ach.path10.05",
            6);

        this->createAchievement(
            39, UnlockType::kRobot,
            "Nether Knight",
            "Reach Path of Souls Rank 6",
            "Reached Path of Souls Rank 6",
            "geometry.ach.path10.06",
            6);

        this->createAchievement(
            58, UnlockType::kWave,
            "Phantom Protector",
            "Reach Path of Souls Rank 7",
            "Reached Path of Souls Rank 7",
            "geometry.ach.path10.07",
            6);

        this->createAchievement(
            93, UnlockType::kUfo,
            "Spiritual Sentinel",
            "Reach Path of Souls Rank 8",
            "Reached Path of Souls Rank 8",
            "geometry.ach.path10.08",
            6);

        this->createAchievement(
            68, UnlockType::kBall,
            "Soul Commander",
            "Reach Path of Souls Rank 9",
            "Reached Path of Souls Rank 9",
            "geometry.ach.path10.09",
            6);

        this->createAchievement(
            24, UnlockType::kSpider,
            "Path of Souls Master",
            "Reach Path of Souls Rank 10",
            "Reached Path of Souls Rank 10",
            "geometry.ach.path10.10",
            6);
    }
};

LSIconDataManager* sharedDataManager = nullptr;

LSIconDataManager* LSIconDataManager::sharedState() {
	if (!sharedDataManager)
	{
		sharedDataManager = new LSIconDataManager();
		sharedDataManager->init();
	}
	return sharedDataManager;
};