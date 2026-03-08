#ifndef _AUDIOHW_DURO_H_
#define _AUDIOHW_DURO_H_

/* Duro audio hardware capabilities */
/* Duro supports basic audio features via WAV codec */
#define AUDIOHW_HAVE_BASS
#define AUDIOHW_HAVE_TREBLE

/* Define audio hardware settings for Duro */
AUDIOHW_SETTING(VOLUME,      "dB", 0, 1, -74,  6, -25)
AUDIOHW_SETTING(BALANCE,     "dB", 0, 1, -74, 74,   0)
AUDIOHW_SETTING(CHANNELS,      "",  0, 1,   0,  5,   0)
AUDIOHW_SETTING(STEREO_WIDTH,  "",  0, 1,   0,255, 100)
AUDIOHW_SETTING(BASS,        "dB", 0, 1,  -6,  9,   0)
AUDIOHW_SETTING(TREBLE,      "dB", 0, 1,  -6,  9,   0)

#endif