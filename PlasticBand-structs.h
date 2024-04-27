#pragma once
#include <stdint.h>

__pragma(pack(push, 1))
typedef struct _GipGuitarState {
    bool sync : 1;
    bool unused : 1;
    bool menu : 1;
    bool view : 1;

    bool greenFlag : 1;
    bool redFlag : 1;
    bool blueFlag : 1;
    bool yellowFlag : 1;

    bool dpadStrumUp : 1;
    bool dpadStrumDown : 1;
    bool dpadLeft : 1;
    bool dpadRight : 1;

    bool orangeFlag : 1;
    bool : 1;
    bool soloFlag : 1;
    bool : 1;

    uint8_t tilt;
    uint8_t whammy;
    uint8_t pickup;

    bool green : 1;
    bool red : 1;
    bool yellow : 1;
    bool blue : 1;
    bool orange : 1;
    bool : 3;

    bool soloGreen : 1;
    bool soloRed : 1;
    bool soloYellow : 1;
    bool soloBlue : 1;
    bool soloOrange : 1;
    bool : 3;

    uint8_t unknown[3];
    uint8_t unknown2[4];
} GipGuitarState;

typedef struct _PS3RockBandGuitarState {
    bool blue : 1;
    bool green : 1;
    bool red : 1;
    bool yellow : 1;

    bool orange : 1;
    bool tilt : 1;
    bool solo : 1;
    bool : 1;

    bool select : 1;
    bool start : 1;
    bool : 1;
    bool : 1;

    bool ps : 1;
    uint8_t : 3;

    //     0
    //   7   1
    // 6   8   2
    //   5   3
    //     4
    uint8_t dpad_strum;

    uint8_t unused1[2];
    uint8_t whammy;
    uint8_t pickup;

    uint8_t unused2[12];
    int16_t unused3[4];
} PS3RockBandGuitarState;

typedef struct _PS3GuitarHeroGuitarState {
    bool yellow : 1;
    bool green : 1;
    bool red : 1;
    bool blue : 1;

    bool orange : 1;
    bool spPedal : 1;
    bool : 1;
    bool : 1;

    bool select : 1;
    bool start : 1;
    bool : 1;
    bool : 1;

    bool ps : 1;
    uint8_t : 3;

    //      0
    //   7     1
    // 6    31   2
    //   5     3
    //      4
    uint8_t dpad_strum;

    uint8_t unused1[2];
    uint8_t whammy;
    uint8_t slider;

    uint8_t pressure_dpadRight_yellow;
    uint8_t pressure_dpadLeft;
    uint8_t pressure_dpadUp_green;
    uint8_t pressure_dpadDown_orange;
    uint8_t pressure_blue;
    uint8_t pressure_red;
    uint8_t unused2[6];

    // Reminder that these values are 10-bit in range
    int16_t tilt_accelX;
    int16_t accelZ;
    int16_t accelY;
    int16_t unused3;
} PS3GuitarHeroGuitarState;

typedef struct _SantrollerRockBandGuitarState {
    uint8_t reportId;

    bool green : 1;
    bool red : 1;
    bool yellow : 1;
    bool blue : 1;

    bool orange : 1;
    bool soloGreen : 1;
    bool soloRed : 1;
    bool soloYellow : 1;

    bool soloBlue : 1;
    bool soloOrange : 1;
    bool select : 1;
    bool start : 1;

    bool home : 1;
    uint8_t : 3;

    //     0
    //   7   1
    // 6   8   2
    //   5   3
    //     4
    uint8_t dpad_strum;

    uint8_t whammy;
    uint8_t pickup;
    uint8_t tilt;
} SantrollerRockBandGuitarState;

typedef struct _SantrollerGuitarHeroGuitarState {
    uint8_t reportId;

    bool green : 1;
    bool red : 1;
    bool yellow : 1;
    bool blue : 1;

    bool orange : 1;
    bool spPedal : 1;
    bool select : 1;
    bool start : 1;

    bool home : 1;
    uint8_t : 7;

    //     0
    //   7   1
    // 6   8   2
    //   5   3
    //     4
    uint8_t dpad_strum;

    uint8_t whammy;
    uint8_t tapBar;
    uint8_t tilt;
} SantrollerGuitarHeroGuitarState;

typedef struct _PS4RockBandGuitarState {
    uint8_t reportId;

    uint8_t joystickX;
    uint8_t joystickY;
    uint8_t unused1[2];

    //     0
    //   7   1
    // 6   8   2
    //   5   3
    //     4
    uint8_t dpad_strum : 4;
    bool blueFlag : 1;
    bool greenFlag : 1;
    bool redFlag : 1;
    bool yellowFlag : 1;

    bool orangeFlag : 1;
    uint8_t : 3;
    bool share : 1;
    bool options : 1;
    bool soloFlag : 1;
    bool p1 : 1;
    bool ps : 1;
    uint8_t : 7;

    uint8_t unused2[22];

    uint8_t powerLevel : 4;
    uint8_t : 4;

    uint8_t unused4[12];

    uint8_t pickup;
    uint8_t whammy;
    uint8_t tilt;

    bool green : 1;
    bool red : 1;
    bool yellow : 1;
    bool blue : 1;
    bool orange : 1;
    bool : 3;

    bool soloGreen : 1;
    bool soloRed : 1;
    bool soloYellow : 1;
    bool soloBlue : 1;
    bool soloOrange : 1;
    bool : 3;

    uint8_t unused5[26];
    uint32_t crc32;
} PS4RockBandGuitarState;

typedef struct _XInputRockBandGuitarState
{
    bool dpadStrumUp : 1;
    bool dpadStrumDown : 1;
    bool dpadLeft : 1;
    bool dpadRight : 1;

    bool start : 1;
    bool back : 1;
    bool soloFlag : 1;
    bool : 1;

    bool orange : 1;
    bool : 1;
    bool guide : 1;
    bool : 1;

    bool green : 1;
    bool red : 1;
    bool blue : 1;
    bool yellow : 1;

    uint8_t pickupSwitch;
    uint8_t unused1;
    int16_t calibrationSensor;
    int16_t unused2;
    int16_t whammy;
    int16_t tilt;
} XInputRockBandGuitarState;

typedef struct _XInputGuitarHeroGuitarState
{
    bool dpadStrumUp : 1;
    bool dpadStrumDown : 1;
    bool dpadLeft : 1;
    bool dpadRight : 1;

    bool start : 1;
    bool back : 1;
    bool : 1;
    bool : 1;

    bool orange : 1;
    bool pedal : 1;
    bool guide : 1;
    bool : 1;

    bool green : 1;
    bool red : 1;
    bool blue : 1;
    bool yellow : 1;

    uint8_t accelZ;
    uint8_t accelX;
    int16_t touchBar;
    int16_t unused;
    int16_t whammy;
    int16_t tilt_accelY;
} XInputGuitarHeroGuitarState;

__pragma(pack(pop))