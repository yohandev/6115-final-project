// Origin mesh: /Users/yohan/Downloads/monke.ply
// Converted using scripts/meshgen.py
#include "num.h"
#include "mesh.h"

static const fixed16 VERTICES[] = {
    560, 210, 980,
    -560, 210, 980,
    640, 120, 880,
    -640, 120, 880,
    700, 70, 740,
    -700, 70, 740,
    450, -30, 790,
    -450, -30, 790,
    450, 40, 920,
    -450, 40, 920,
    450, 170, 1000,
    -450, 170, 1000,
    350, 210, 1020,
    -350, 210, 1020,
    260, 120, 950,
    -260, 120, 950,
    200, 70, 830,
    -200, 70, 830,
    100, 310, 840,
    -100, 310, 840,
    180, 310, 950,
    -180, 310, 950,
    310, 310, 1020,
    -310, 310, 1020,
    350, 420, 1020,
    -350, 420, 1020,
    260, 500, 950,
    -260, 500, 950,
    200, 560, 830,
    -200, 560, 830,
    450, 660, 790,
    -450, 660, 790,
    450, 580, 920,
    -450, 580, 920,
    450, 460, 1000,
    -450, 460, 1000,
    560, 420, 980,
    -560, 420, 980,
    640, 500, 880,
    -640, 500, 880,
    700, 560, 740,
    -700, 560, 740,
    800, 310, 720,
    -800, 310, 720,
    720, 310, 860,
    -720, 310, 860,
    600, 310, 970,
    -600, 310, 970,
    610, 310, 990,
    -610, 310, 990,
    570, 430, 1000,
    -570, 430, 1000,
    450, 480, 1030,
    -450, 480, 1030,
    340, 430, 1050,
    -340, 430, 1050,
    290, 310, 1050,
    -290, 310, 1050,
    340, 200, 1050,
    -340, 200, 1050,
    450, 310, 1060,
    -450, 310, 1060,
    450, 150, 1030,
    -450, 150, 1030,
    570, 200, 1000,
    -570, 200, 1000,
    0, 550, 950,
    0, 450, 1050,
    0, -870, 940,
    0, -410, 1000,
    0, -240, 1020,
    0, -990, 920,
    0, 520, 770,
    0, 730, 730,
    0, 1150, -700,
    0, 720, -1090,
    0, 90, -1060,
    0, -490, -450,
    260, -240, 720,
    -260, -240, 720,
    400, -560, 730,
    -400, -560, 730,
    450, -890, 730,
    -450, -890, 730,
    470, -1140, 680,
    -470, -1140, 680,
    420, -1210, 670,
    -420, -1210, 670,
    230, -1240, 710,
    -230, -1240, 710,
    0, -1260, 740,
    560, -180, 680,
    -560, -180, 680,
    810, -50, 690,
    -810, -50, 690,
    1060, 190, 570,
    -1060, 190, 570,
    1100, 550, 760,
    -1100, 550, 760,
    910, 620, 800,
    -910, 620, 800,
    630, 770, 880,
    -630, 770, 880,
    410, 970, 940,
    -410, 970, 940,
    200, 920, 970,
    -200, 920, 970,
    80, 630, 960,
    -80, 630, 960,
    210, 530, 990,
    -210, 530, 990,
    160, 390, 980,
    -160, 390, 980,
    260, 120, 950,
    -260, 120, 950,
    480, 20, 900,
    -480, 20, 900,
    630, 80, 860,
    -630, 80, 860,
    800, 240, 830,
    -800, 240, 830,
    820, 380, 830,
    -820, 380, 830,
    770, 480, 850,
    -770, 480, 850,
    550, 560, 920,
    -550, 560, 920,
    320, 600, 970,
    -320, 600, 970,
    0, -980, 940,
    140, -920, 940,
    -140, -920, 940,
    150, -1070, 910,
    -150, -1070, 910,
    80, -1130, 890,
    -80, -1130, 890,
    0, -1140, 880,
    0, -250, 960,
    0, -180, 950,
    130, -190, 950,
    -130, -190, 950,
    160, -290, 960,
    -160, -290, 960,
    110, -370, 950,
    -110, -370, 950,
    510, -60, 860,
    -510, -60, 860,
    790, 70, 800,
    -790, 70, 800,
    930, 260, 770,
    -930, 260, 770,
    950, 480, 840,
    -950, 480, 840,
    880, 530, 930,
    -880, 530, 930,
    560, 700, 1020,
    -560, 700, 1020,
    400, 820, 1070,
    -400, 820, 1070,
    260, 790, 1090,
    -260, 790, 1090,
    130, 550, 1080,
    -130, 550, 1080,
    160, -130, 1040,
    -160, -130, 1040,
    270, -570, 910,
    -270, -570, 910,
    320, -900, 880,
    -320, -900, 880,
    340, -1050, 850,
    -340, -1050, 850,
    300, -1170, 810,
    -300, -1170, 810,
    210, -1190, 810,
    -210, -1190, 810,
    0, -1210, 820,
    0, 60, 930,
    0, 270, 980,
    420, 610, 950,
    -420, 610, 950,
    210, 180, 960,
    -210, 180, 960,
    170, 270, 970,
    -170, 270, 970,
    150, -880, 940,
    -150, -880, 940,
    100, -570, 960,
    -100, -570, 960,
    0, -570, 960,
    0, -420, 950,
    120, -350, 1000,
    -120, -350, 1000,
    170, -290, 1020,
    -170, -290, 1020,
    140, -170, 1000,
    -140, -170, 1000,
    50, -160, 1000,
    -50, -160, 1000,
    0, -260, 1060,
    60, -190, 1040,
    -60, -190, 1040,
    120, -200, 1040,
    -120, -200, 1040,
    140, -290, 1060,
    -140, -290, 1060,
    100, -320, 1030,
    -100, -320, 1030,
    0, -370, 1030,
    330, -400, 710,
    -330, -400, 710,
    210, -310, 910,
    -210, -310, 910,
    230, -400, 910,
    -230, -400, 910,
    300, -320, 710,
    -300, -320, 710,
    0, -1120, 880,
    60, -1110, 880,
    -60, -1110, 880,
    120, -1050, 910,
    -120, -1050, 910,
    120, -950, 930,
    -120, -950, 930,
    0, -1000, 840,
    120, -960, 850,
    -120, -960, 850,
    120, -1040, 820,
    -120, -1040, 820,
    60, -1090, 810,
    -60, -1090, 810,
    0, -1100, 810,
    220, 280, 1000,
    -220, 280, 1000,
    240, 200, 990,
    -240, 200, 990,
    430, 550, 970,
    -430, 550, 970,
    350, 540, 990,
    -350, 540, 990,
    540, 510, 990,
    -540, 510, 990,
    720, 450, 890,
    -720, 450, 890,
    750, 370, 880,
    -750, 370, 880,
    740, 250, 870,
    -740, 250, 870,
    610, 130, 920,
    -610, 130, 920,
    480, 80, 950,
    -480, 80, 950,
    290, 140, 1000,
    -290, 140, 1000,
    230, 380, 1000,
    -230, 380, 1000,
    270, 480, 1000,
    -270, 480, 1000,
    300, 460, 970,
    -300, 460, 970,
    250, 380, 970,
    -250, 380, 970,
    310, 160, 970,
    -310, 160, 970,
    480, 110, 930,
    -480, 110, 930,
    590, 150, 900,
    -590, 150, 900,
    700, 270, 860,
    -700, 270, 860,
    710, 360, 860,
    -710, 360, 860,
    680, 430, 870,
    -680, 430, 870,
    530, 500, 960,
    -530, 500, 960,
    360, 510, 980,
    -360, 510, 980,
    430, 520, 960,
    -430, 520, 960,
    260, 220, 960,
    -260, 220, 960,
    250, 290, 960,
    -250, 290, 960,
    140, 590, 780,
    -140, 590, 780,
    250, 850, 790,
    -250, 850, 790,
    430, 880, 760,
    -430, 880, 760,
    620, 710, 710,
    -620, 710, 710,
    870, 580, 630,
    -870, 580, 630,
    1020, 520, 590,
    -1020, 520, 590,
    990, 210, 480,
    -990, 210, 480,
    770, 0, 530,
    -770, 0, 530,
    560, -120, 600,
    -560, -120, 600,
    0, 1150, 370,
    0, 1260, -100,
    0, -250, -860,
    0, -590, 240,
    0, -1250, 590,
    0, -1030, 440,
    0, -730, 410,
    0, -620, 360,
    1090, 300, 70,
    -1090, 300, 70,
    1100, 410, -60,
    -1100, 410, -60,
    990, 340, -560,
    -990, 340, -560,
    590, 560, -900,
    -590, 560, -900,
    940, -60, 90,
    -940, -60, 90,
    760, -160, -210,
    -760, -160, -210,
    820, -10, -550,
    -820, -10, -550,
    430, 70, -850,
    -430, 70, -850,
    300, -450, 520,
    -300, -450, 520,
    230, -530, 330,
    -230, -530, 330,
    370, -910, 490,
    -370, -910, 490,
    320, -640, 500,
    -320, -640, 500,
    420, -1170, 510,
    -420, -1170, 510,
    180, -970, 470,
    -180, -970, 470,
    160, -690, 460,
    -160, -690, 460,
    210, -1210, 560,
    -210, -1210, 560,
    280, -360, 550,
    -280, -360, 550,
    270, -290, 600,
    -270, -290, 600,
    260, -220, 640,
    -260, -220, 640,
    270, -500, 210,
    -270, -500, 210,
    380, -400, -340,
    -380, -400, -340,
    440, -190, -690,
    -440, -190, -690,
    580, 1110, -490,
    -580, 1110, -490,
    580, 1190, -90,
    -580, 1190, -90,
    580, 1090, 300,
    -580, 1090, 300,
    590, 670, 550,
    -590, 670, 550,
    930, 520, 430,
    -930, 520, 430,
    810, 580, 360,
    -810, 580, 360,
    820, 900, 70,
    -820, 900, 70,
    1020, 720, 160,
    -1020, 720, 160,
    1020, 790, -150,
    -1020, 790, -150,
    820, 960, -250,
    -820, 960, -250,
    820, 870, -570,
    -820, 870, -570,
    1020, 690, -460,
    -1020, 690, -460,
    790, 420, -750,
    -790, 420, -750,
    620, 30, -700,
    -620, 30, -700,
    1050, 420, -260,
    -1050, 420, -260,
    520, -220, 190,
    -520, -220, 190,
    550, -250, -270,
    -550, -250, -270,
    1140, 520, -300,
    -1140, 520, -300,
    990, -180, -160,
    -990, -180, -160,
    1330, -130, -420,
    -1330, -130, -420,
    1640, 70, -550,
    -1640, 70, -550,
    1730, 410, -540,
    -1730, 410, -540,
    1580, 650, -540,
    -1580, 650, -540,
    1310, 610, -400,
    -1310, 610, -400,
    1300, 530, -370,
    -1300, 530, -370,
    1520, 560, -500,
    -1520, 560, -500,
    1620, 370, -520,
    -1620, 370, -520,
    1550, 100, -520,
    -1550, 100, -520,
    1320, -50, -390,
    -1320, -50, -390,
    1060, -90, -170,
    -1060, -90, -170,
    1180, 460, -280,
    -1180, 460, -280,
    1210, 390, -370,
    -1210, 390, -370,
    1130, -30, -270,
    -1130, -30, -270,
    1330, 0, -470,
    -1330, 0, -470,
    1520, 120, -570,
    -1520, 120, -570,
    1580, 320, -570,
    -1580, 320, -570,
    1500, 460, -560,
    -1500, 460, -560,
    1310, 440, -460,
    -1310, 440, -460,
    1080, 370, -270,
    -1080, 370, -270,
    1070, 220, -350,
    -1070, 220, -350,
    970, 120, -350,
    -970, 120, -350,
    1050, 110, -350,
    -1050, 110, -350,
    1080, 20, -350,
    -1080, 20, -350,
    1040, -20, -350,
    -1040, -20, -350,
    930, 0, -90,
    -930, 0, -90,
    920, -30, -220,
    -920, -30, -220,
    920, 50, -240,
    -920, 50, -240,
    1020, 260, -270,
    -1020, 260, -270,
    1140, 310, -340,
    -1140, 310, -340,
    1140, 300, -410,
    -1140, 300, -410,
    1040, -20, -410,
    -1040, -20, -410,
    1090, 20, -410,
    -1090, 20, -410,
    1060, 100, -410,
    -1060, 100, -410,
    980, 120, -410,
    -980, 120, -410,
    1080, 220, -410,
    -1080, 220, -410,
    1330, 420, -530,
    -1330, 420, -530,
    1520, 440, -620,
    -1520, 440, -620,
    1610, 310, -630,
    -1610, 310, -630,
    1550, 110, -620,
    -1550, 110, -620,
    1340, 0, -540,
    -1340, 0, -540,
    1130, -20, -340,
    -1130, -20, -340,
    1220, 370, -440,
    -1220, 370, -440,
    1140, 140, -420,
    -1140, 140, -420,
    1200, 80, -430,
    -1200, 80, -430,
    1280, 160, -470,
    -1280, 160, -470,
    1230, 220, -450,
    -1230, 220, -450,
    1300, 300, -480,
    -1300, 300, -480,
    1350, 240, -490,
    -1350, 240, -490,
    1420, 270, -500,
    -1420, 270, -500,
    1390, 350, -500,
    -1390, 350, -500,
    1310, 560, -620,
    -1310, 560, -620,
    1600, 600, -700,
    -1600, 600, -700,
    1750, 380, -640,
    -1750, 380, -640,
    1680, 70, -680,
    -1680, 70, -680,
    1330, -110, -630,
    -1330, -110, -630,
    1010, -160, -420,
    -1010, -160, -420,
    1100, 490, -490,
    -1100, 490, -490,
};

static const u16 INDICES[] = {
    46, 2, 44,
    3, 47, 45,
    44, 4, 42,
    5, 45, 43,
    2, 6, 4,
    7, 3, 5,
    0, 8, 2,
    9, 1, 3,
    10, 14, 8,
    15, 11, 9,
    8, 16, 6,
    17, 9, 7,
    20, 16, 14,
    21, 17, 19,
    12, 20, 14,
    21, 13, 15,
    22, 26, 20,
    27, 23, 21,
    26, 18, 20,
    27, 19, 29,
    32, 28, 26,
    33, 29, 31,
    34, 26, 24,
    35, 27, 33,
    36, 32, 34,
    37, 33, 39,
    38, 30, 32,
    39, 31, 41,
    44, 40, 38,
    45, 41, 43,
    46, 38, 36,
    47, 39, 45,
    36, 48, 46,
    37, 49, 51,
    34, 50, 36,
    35, 51, 53,
    24, 52, 34,
    25, 53, 55,
    22, 54, 24,
    23, 55, 57,
    22, 58, 56,
    59, 23, 57,
    12, 62, 58,
    63, 13, 59,
    10, 64, 62,
    65, 11, 63,
    0, 48, 64,
    49, 1, 65,
    60, 64, 48,
    49, 65, 61,
    62, 64, 60,
    61, 65, 63,
    60, 58, 62,
    63, 59, 61,
    60, 56, 58,
    59, 57, 61,
    60, 54, 56,
    57, 55, 61,
    60, 52, 54,
    55, 53, 61,
    60, 50, 52,
    53, 51, 61,
    60, 48, 50,
    51, 49, 61,
    173, 90, 88,
    174, 90, 175,
    171, 88, 86,
    172, 89, 174,
    84, 171, 86,
    172, 85, 87,
    82, 169, 84,
    170, 83, 85,
    80, 167, 82,
    168, 81, 83,
    78, 145, 163,
    146, 79, 164,
    93, 145, 91,
    94, 146, 148,
    93, 149, 147,
    150, 94, 148,
    97, 149, 95,
    98, 150, 152,
    99, 151, 97,
    100, 152, 154,
    101, 153, 99,
    102, 154, 156,
    101, 157, 155,
    158, 102, 156,
    105, 157, 103,
    106, 158, 160,
    107, 159, 105,
    108, 160, 162,
    66, 161, 107,
    66, 162, 67,
    127, 161, 109,
    128, 162, 160,
    127, 157, 159,
    158, 128, 160,
    155, 178, 125,
    156, 179, 158,
    153, 125, 123,
    154, 126, 156,
    151, 123, 121,
    152, 124, 154,
    149, 121, 119,
    150, 122, 152,
    147, 119, 117,
    148, 120, 150,
    145, 117, 115,
    146, 118, 148,
    163, 115, 113,
    164, 116, 146,
    113, 176, 163,
    176, 114, 164,
    161, 111, 109,
    162, 112, 67,
    111, 177, 182,
    177, 112, 183,
    180, 177, 176,
    181, 177, 183,
    134, 175, 173,
    175, 135, 174,
    132, 173, 171,
    174, 133, 172,
    132, 169, 130,
    133, 170, 172,
    165, 184, 167,
    185, 166, 168,
    130, 167, 184,
    168, 131, 185,
    189, 186, 143,
    189, 187, 188,
    186, 68, 184,
    187, 68, 188,
    130, 68, 129,
    131, 68, 185,
    141, 190, 143,
    191, 142, 144,
    139, 192, 141,
    193, 140, 142,
    196, 139, 138,
    197, 140, 195,
    70, 138, 137,
    70, 138, 197,
    143, 69, 189,
    144, 69, 191,
    190, 207, 69,
    191, 207, 206,
    70, 199, 196,
    200, 70, 197,
    196, 201, 194,
    202, 197, 195,
    201, 192, 194,
    202, 193, 204,
    192, 205, 190,
    206, 193, 191,
    203, 199, 198,
    204, 200, 202,
    198, 205, 203,
    206, 198, 204,
    138, 163, 176,
    164, 138, 176,
    139, 210, 163,
    211, 140, 164,
    143, 210, 141,
    144, 211, 213,
    186, 212, 143,
    187, 213, 166,
    208, 165, 80,
    209, 166, 213,
    214, 212, 208,
    215, 213, 211,
    78, 210, 214,
    211, 79, 215,
    129, 221, 130,
    129, 222, 71,
    132, 221, 219,
    222, 133, 220,
    134, 219, 217,
    220, 135, 218,
    136, 217, 216,
    218, 136, 216,
    217, 230, 216,
    218, 230, 229,
    217, 226, 228,
    227, 218, 229,
    219, 224, 226,
    225, 220, 227,
    71, 224, 221,
    71, 225, 223,
    223, 228, 224,
    229, 223, 225,
    224, 228, 226,
    227, 229, 225,
    182, 233, 231,
    234, 183, 232,
    111, 231, 253,
    232, 112, 254,
    111, 255, 109,
    112, 256, 254,
    113, 233, 180,
    114, 234, 252,
    113, 249, 251,
    250, 114, 252,
    115, 247, 249,
    248, 116, 250,
    117, 245, 247,
    246, 118, 248,
    119, 243, 245,
    244, 120, 246,
    123, 243, 121,
    124, 244, 242,
    125, 241, 123,
    126, 242, 240,
    125, 235, 239,
    236, 126, 240,
    178, 237, 235,
    238, 179, 236,
    127, 255, 237,
    256, 128, 238,
    255, 275, 237,
    256, 276, 258,
    235, 275, 277,
    276, 236, 278,
    235, 273, 239,
    236, 274, 278,
    239, 271, 241,
    240, 272, 274,
    243, 271, 269,
    272, 244, 270,
    243, 267, 245,
    244, 268, 270,
    247, 267, 265,
    268, 248, 266,
    247, 263, 249,
    248, 264, 266,
    249, 261, 251,
    250, 262, 264,
    233, 261, 279,
    262, 234, 280,
    255, 259, 257,
    260, 256, 258,
    253, 281, 259,
    282, 254, 260,
    231, 279, 281,
    280, 232, 282,
    66, 283, 72,
    284, 66, 72,
    107, 285, 283,
    286, 108, 284,
    103, 285, 105,
    104, 286, 288,
    101, 287, 103,
    102, 288, 290,
    99, 289, 101,
    100, 290, 292,
    99, 293, 291,
    294, 100, 292,
    95, 293, 97,
    96, 294, 296,
    95, 297, 295,
    298, 96, 296,
    93, 299, 297,
    300, 94, 298,
    308, 337, 307,
    308, 338, 328,
    307, 335, 306,
    307, 336, 338,
    306, 339, 305,
    306, 340, 336,
    88, 305, 339,
    305, 89, 340,
    86, 339, 333,
    340, 87, 334,
    84, 333, 329,
    334, 85, 330,
    82, 329, 331,
    330, 83, 332,
    329, 337, 331,
    338, 330, 332,
    333, 335, 329,
    334, 336, 340,
    331, 327, 325,
    332, 328, 338,
    80, 331, 325,
    332, 81, 326,
    341, 214, 208,
    342, 215, 344,
    325, 208, 80,
    326, 209, 342,
    214, 345, 78,
    215, 346, 344,
    345, 91, 78,
    346, 92, 300,
    323, 303, 76,
    324, 303, 352,
    351, 77, 303,
    352, 77, 350,
    77, 347, 304,
    348, 77, 304,
    304, 327, 308,
    328, 304, 308,
    327, 341, 325,
    328, 342, 348,
    295, 317, 309,
    318, 296, 310,
    315, 76, 75,
    316, 76, 324,
    357, 302, 301,
    358, 302, 356,
    302, 353, 74,
    354, 302, 74,
    74, 315, 75,
    316, 74, 75,
    291, 361, 363,
    362, 292, 364,
    363, 367, 365,
    368, 364, 366,
    365, 369, 371,
    370, 366, 372,
    371, 375, 373,
    376, 372, 374,
    377, 375, 313,
    378, 376, 374,
    315, 373, 377,
    374, 316, 378,
    353, 371, 373,
    372, 354, 374,
    355, 365, 371,
    366, 356, 372,
    357, 363, 365,
    364, 358, 366,
    291, 359, 289,
    292, 360, 364,
    359, 301, 73,
    360, 301, 358,
    283, 287, 289,
    288, 284, 290,
    283, 359, 73,
    360, 284, 73,
    72, 283, 73,
    73, 284, 72,
    295, 361, 293,
    296, 362, 310,
    309, 367, 361,
    368, 310, 362,
    311, 369, 367,
    370, 312, 368,
    375, 381, 313,
    376, 382, 370,
    349, 383, 347,
    350, 384, 386,
    383, 319, 317,
    384, 320, 386,
    297, 383, 317,
    384, 298, 318,
    299, 341, 383,
    342, 300, 384,
    341, 347, 383,
    384, 348, 342,
    299, 345, 343,
    344, 346, 300,
    321, 377, 313,
    322, 378, 380,
    377, 323, 315,
    378, 324, 380,
    385, 321, 319,
    386, 322, 380,
    351, 385, 349,
    352, 386, 380,
    323, 379, 351,
    352, 380, 324,
    387, 401, 399,
    388, 402, 414,
    399, 403, 397,
    404, 400, 398,
    403, 395, 397,
    404, 396, 406,
    405, 393, 395,
    406, 394, 408,
    407, 391, 393,
    408, 392, 410,
    391, 411, 389,
    412, 392, 390,
    409, 417, 411,
    418, 410, 412,
    407, 419, 409,
    420, 408, 410,
    423, 407, 405,
    424, 408, 422,
    425, 405, 403,
    426, 406, 424,
    427, 403, 401,
    428, 404, 426,
    401, 415, 427,
    416, 402, 428,
    319, 441, 317,
    320, 442, 444,
    389, 443, 319,
    390, 444, 412,
    309, 441, 311,
    442, 310, 312,
    381, 413, 387,
    414, 382, 388,
    411, 439, 443,
    440, 412, 444,
    445, 439, 437,
    446, 440, 444,
    433, 437, 435,
    438, 434, 436,
    447, 433, 431,
    448, 434, 446,
    447, 449, 429,
    448, 450, 432,
    429, 415, 413,
    430, 416, 450,
    311, 429, 381,
    430, 312, 382,
    441, 447, 311,
    442, 448, 446,
    441, 443, 445,
    446, 444, 442,
    415, 451, 475,
    452, 416, 476,
    431, 451, 449,
    432, 452, 462,
    431, 459, 461,
    460, 432, 462,
    435, 459, 433,
    436, 460, 458,
    437, 457, 435,
    438, 458, 456,
    437, 453, 455,
    454, 438, 456,
    439, 473, 453,
    474, 440, 454,
    427, 475, 463,
    476, 428, 464,
    425, 463, 465,
    464, 426, 466,
    423, 465, 467,
    466, 424, 468,
    423, 469, 421,
    424, 470, 468,
    421, 471, 419,
    422, 472, 470,
    419, 473, 417,
    420, 474, 472,
    455, 477, 457,
    456, 478, 480,
    479, 483, 477,
    480, 484, 482,
    483, 487, 485,
    488, 484, 486,
    487, 491, 485,
    488, 492, 490,
    463, 485, 491,
    486, 464, 492,
    483, 475, 451,
    484, 476, 486,
    461, 483, 451,
    462, 484, 478,
    457, 461, 459,
    462, 458, 460,
    473, 455, 453,
    474, 456, 480,
    471, 479, 473,
    480, 472, 474,
    487, 471, 469,
    488, 472, 482,
    489, 469, 467,
    490, 470, 488,
    465, 489, 467,
    490, 466, 468,
    463, 491, 465,
    466, 492, 464,
    391, 503, 501,
    504, 392, 502,
    393, 501, 499,
    502, 394, 500,
    393, 497, 395,
    394, 498, 500,
    395, 495, 397,
    396, 496, 498,
    397, 493, 399,
    398, 494, 496,
    399, 505, 387,
    400, 506, 494,
    501, 505, 493,
    502, 506, 504,
    493, 499, 501,
    500, 494, 502,
    495, 497, 499,
    500, 498, 496,
    381, 505, 313,
    382, 506, 388,
    313, 503, 321,
    504, 314, 322,
    319, 503, 389,
    504, 320, 390,
    46, 0, 2,
    3, 1, 47,
    44, 2, 4,
    5, 3, 45,
    2, 8, 6,
    7, 9, 3,
    0, 10, 8,
    9, 11, 1,
    10, 12, 14,
    15, 13, 11,
    8, 14, 16,
    17, 15, 9,
    20, 18, 16,
    21, 15, 17,
    12, 22, 20,
    21, 23, 13,
    22, 24, 26,
    27, 25, 23,
    26, 28, 18,
    27, 21, 19,
    32, 30, 28,
    33, 27, 29,
    34, 32, 26,
    35, 25, 27,
    36, 38, 32,
    37, 35, 33,
    38, 40, 30,
    39, 33, 31,
    44, 42, 40,
    45, 39, 41,
    46, 44, 38,
    47, 37, 39,
    36, 50, 48,
    37, 47, 49,
    34, 52, 50,
    35, 37, 51,
    24, 54, 52,
    25, 35, 53,
    22, 56, 54,
    23, 25, 55,
    22, 12, 58,
    59, 13, 23,
    12, 10, 62,
    63, 11, 13,
    10, 0, 64,
    65, 1, 11,
    0, 46, 48,
    49, 47, 1,
    173, 175, 90,
    174, 89, 90,
    171, 173, 88,
    172, 87, 89,
    84, 169, 171,
    172, 170, 85,
    82, 167, 169,
    170, 168, 83,
    80, 165, 167,
    168, 166, 81,
    78, 91, 145,
    146, 92, 79,
    93, 147, 145,
    94, 92, 146,
    93, 95, 149,
    150, 96, 94,
    97, 151, 149,
    98, 96, 150,
    99, 153, 151,
    100, 98, 152,
    101, 155, 153,
    102, 100, 154,
    101, 103, 157,
    158, 104, 102,
    105, 159, 157,
    106, 104, 158,
    107, 161, 159,
    108, 106, 160,
    66, 67, 161,
    66, 108, 162,
    127, 159, 161,
    128, 110, 162,
    127, 178, 157,
    158, 179, 128,
    155, 157, 178,
    156, 126, 179,
    153, 155, 125,
    154, 124, 126,
    151, 153, 123,
    152, 122, 124,
    149, 151, 121,
    150, 120, 122,
    147, 149, 119,
    148, 118, 120,
    145, 147, 117,
    146, 116, 118,
    163, 145, 115,
    164, 114, 116,
    113, 180, 176,
    176, 181, 114,
    161, 67, 111,
    162, 110, 112,
    111, 67, 177,
    177, 67, 112,
    180, 182, 177,
    181, 176, 177,
    134, 136, 175,
    175, 136, 135,
    132, 134, 173,
    174, 135, 133,
    132, 171, 169,
    133, 131, 170,
    165, 186, 184,
    185, 187, 166,
    130, 169, 167,
    168, 170, 131,
    189, 188, 186,
    189, 144, 187,
    186, 188, 68,
    187, 185, 68,
    130, 184, 68,
    131, 129, 68,
    141, 192, 190,
    191, 193, 142,
    139, 194, 192,
    193, 195, 140,
    196, 194, 139,
    197, 138, 140,
    70, 196, 138,
    143, 190, 69,
    144, 189, 69,
    190, 205, 207,
    191, 69, 207,
    70, 198, 199,
    200, 198, 70,
    196, 199, 201,
    202, 200, 197,
    201, 203, 192,
    202, 195, 193,
    192, 203, 205,
    206, 204, 193,
    203, 201, 199,
    204, 198, 200,
    198, 207, 205,
    206, 207, 198,
    138, 139, 163,
    164, 140, 138,
    139, 141, 210,
    211, 142, 140,
    143, 212, 210,
    144, 142, 211,
    186, 165, 212,
    187, 144, 213,
    208, 212, 165,
    209, 81, 166,
    214, 210, 212,
    215, 209, 213,
    78, 163, 210,
    211, 164, 79,
    129, 71, 221,
    129, 131, 222,
    132, 130, 221,
    222, 131, 133,
    134, 132, 219,
    220, 133, 135,
    136, 134, 217,
    218, 135, 136,
    217, 228, 230,
    218, 216, 230,
    217, 219, 226,
    227, 220, 218,
    219, 221, 224,
    225, 222, 220,
    71, 223, 224,
    71, 222, 225,
    223, 230, 228,
    229, 230, 223,
    182, 180, 233,
    234, 181, 183,
    111, 182, 231,
    232, 183, 112,
    111, 253, 255,
    112, 110, 256,
    113, 251, 233,
    114, 181, 234,
    113, 115, 249,
    250, 116, 114,
    115, 117, 247,
    248, 118, 116,
    117, 119, 245,
    246, 120, 118,
    119, 121, 243,
    244, 122, 120,
    123, 241, 243,
    124, 122, 244,
    125, 239, 241,
    126, 124, 242,
    125, 178, 235,
    236, 179, 126,
    178, 127, 237,
    238, 128, 179,
    127, 109, 255,
    256, 110, 128,
    255, 257, 275,
    256, 238, 276,
    235, 237, 275,
    276, 238, 236,
    235, 277, 273,
    236, 240, 274,
    239, 273, 271,
    240, 242, 272,
    243, 241, 271,
    272, 242, 244,
    243, 269, 267,
    244, 246, 268,
    247, 245, 267,
    268, 246, 248,
    247, 265, 263,
    248, 250, 264,
    249, 263, 261,
    250, 252, 262,
    233, 251, 261,
    262, 252, 234,
    255, 253, 259,
    260, 254, 256,
    253, 231, 281,
    282, 232, 254,
    231, 233, 279,
    280, 234, 232,
    66, 107, 283,
    284, 108, 66,
    107, 105, 285,
    286, 106, 108,
    103, 287, 285,
    104, 106, 286,
    101, 289, 287,
    102, 104, 288,
    99, 291, 289,
    100, 102, 290,
    99, 97, 293,
    294, 98, 100,
    95, 295, 293,
    96, 98, 294,
    95, 93, 297,
    298, 94, 96,
    93, 91, 299,
    300, 92, 94,
    308, 327, 337,
    308, 307, 338,
    307, 337, 335,
    307, 306, 336,
    306, 335, 339,
    306, 305, 340,
    88, 90, 305,
    305, 90, 89,
    86, 88, 339,
    340, 89, 87,
    84, 86, 333,
    334, 87, 85,
    82, 84, 329,
    330, 85, 83,
    329, 335, 337,
    338, 336, 330,
    333, 339, 335,
    334, 330, 336,
    331, 337, 327,
    332, 326, 328,
    80, 82, 331,
    332, 83, 81,
    341, 343, 214,
    342, 209, 215,
    325, 341, 208,
    326, 81, 209,
    214, 343, 345,
    215, 79, 346,
    345, 299, 91,
    346, 79, 92,
    323, 351, 303,
    324, 76, 303,
    351, 349, 77,
    352, 303, 77,
    77, 349, 347,
    348, 350, 77,
    304, 347, 327,
    328, 348, 304,
    327, 347, 341,
    328, 326, 342,
    295, 297, 317,
    318, 298, 296,
    315, 323, 76,
    316, 75, 76,
    357, 355, 302,
    358, 301, 302,
    302, 355, 353,
    354, 356, 302,
    74, 353, 315,
    316, 354, 74,
    291, 293, 361,
    362, 294, 292,
    363, 361, 367,
    368, 362, 364,
    365, 367, 369,
    370, 368, 366,
    371, 369, 375,
    376, 370, 372,
    377, 373, 375,
    378, 314, 376,
    315, 353, 373,
    374, 354, 316,
    353, 355, 371,
    372, 356, 354,
    355, 357, 365,
    366, 358, 356,
    357, 359, 363,
    364, 360, 358,
    291, 363, 359,
    292, 290, 360,
    359, 357, 301,
    360, 73, 301,
    283, 285, 287,
    288, 286, 284,
    283, 289, 359,
    360, 290, 284,
    295, 309, 361,
    296, 294, 362,
    309, 311, 367,
    368, 312, 310,
    311, 381, 369,
    370, 382, 312,
    375, 369, 381,
    376, 314, 382,
    349, 385, 383,
    350, 348, 384,
    383, 385, 319,
    384, 318, 320,
    297, 299, 383,
    384, 300, 298,
    299, 343, 341,
    342, 344, 300,
    321, 379, 377,
    322, 314, 378,
    377, 379, 323,
    378, 316, 324,
    385, 379, 321,
    386, 320, 322,
    351, 379, 385,
    352, 350, 386,
    387, 413, 401,
    388, 400, 402,
    399, 401, 403,
    404, 402, 400,
    403, 405, 395,
    404, 398, 396,
    405, 407, 393,
    406, 396, 394,
    407, 409, 391,
    408, 394, 392,
    391, 409, 411,
    412, 410, 392,
    409, 419, 417,
    418, 420, 410,
    407, 421, 419,
    420, 422, 408,
    423, 421, 407,
    424, 406, 408,
    425, 423, 405,
    426, 404, 406,
    427, 425, 403,
    428, 402, 404,
    401, 413, 415,
    416, 414, 402,
    319, 443, 441,
    320, 318, 442,
    389, 411, 443,
    390, 320, 444,
    309, 317, 441,
    442, 318, 310,
    381, 429, 413,
    414, 430, 382,
    411, 417, 439,
    440, 418, 412,
    445, 443, 439,
    446, 438, 440,
    433, 445, 437,
    438, 446, 434,
    447, 445, 433,
    448, 432, 434,
    447, 431, 449,
    448, 430, 450,
    429, 449, 415,
    430, 414, 416,
    311, 447, 429,
    430, 448, 312,
    441, 445, 447,
    442, 312, 448,
    415, 449, 451,
    452, 450, 416,
    431, 461, 451,
    432, 450, 452,
    431, 433, 459,
    460, 434, 432,
    435, 457, 459,
    436, 434, 460,
    437, 455, 457,
    438, 436, 458,
    437, 439, 453,
    454, 440, 438,
    439, 417, 473,
    474, 418, 440,
    427, 415, 475,
    476, 416, 428,
    425, 427, 463,
    464, 428, 426,
    423, 425, 465,
    466, 426, 424,
    423, 467, 469,
    424, 422, 470,
    421, 469, 471,
    422, 420, 472,
    419, 471, 473,
    420, 418, 474,
    455, 479, 477,
    456, 458, 478,
    479, 481, 483,
    480, 478, 484,
    483, 481, 487,
    488, 482, 484,
    487, 489, 491,
    488, 486, 492,
    463, 475, 485,
    486, 476, 464,
    483, 485, 475,
    484, 452, 476,
    461, 477, 483,
    462, 452, 484,
    457, 477, 461,
    462, 478, 458,
    473, 479, 455,
    474, 454, 456,
    471, 481, 479,
    480, 482, 472,
    487, 481, 471,
    488, 470, 472,
    489, 487, 469,
    490, 468, 470,
    465, 491, 489,
    490, 492, 466,
    391, 389, 503,
    504, 390, 392,
    393, 391, 501,
    502, 392, 394,
    393, 499, 497,
    394, 396, 498,
    395, 497, 495,
    396, 398, 496,
    397, 495, 493,
    398, 400, 494,
    399, 493, 505,
    400, 388, 506,
    501, 503, 505,
    502, 494, 506,
    493, 495, 499,
    500, 496, 494,
    381, 387, 505,
    382, 314, 506,
    313, 505, 503,
    504, 506, 314,
    319, 321, 503,
    504, 322, 320,
};

static const struct ColorRange COLORS[] = {
    { 0, 0 },
};

const struct Mesh HMMM_MONKE = {
    .vertices = VERTICES,
    .indices = INDICES,
    .colors = COLORS,

    .num_vertices = 507,
    .num_faces = 967,
    .num_colors = 1,
};