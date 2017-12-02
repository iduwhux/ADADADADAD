#ifndef LIB_MIDI_H
#define LIB_MIDI_H

#include "settings.h"

// MIDI Note Number to Frequency
#if OSC_TIMER_DIVIDER == 8
  static float note_to_hz[128] = {32.7032,34.6478,36.7081,38.8909,41.2034,43.6535,46.2493,48.9994,51.9131,55,58.2705,61.7354,32.7032,34.6478,36.7081,38.8909,41.2034,43.6535,46.2493,48.9994,51.9131,55,58.2705,61.7354,32.7032,34.6478,36.7081,38.8909,41.2034,43.6535,46.2493,48.9994,51.9131,55,58.2705,61.7354,65.4064,69.2957,73.4162,77.7817,82.4069,87.3071,92.4986,97.9989,103.8262,110,116.5409,123.4708,130.8128,138.5913,146.8324,155.5635,164.8138,174.6141,184.9972,195.9977,207.6523,220,233.0819,246.9417,261.6256,277.1826,293.6648,311.127,329.6276,349.2282,369.9944,391.9954,415.3047,440,466.1638,493.8833,523.2511,554.3653,587.3295,622.254,659.2551,698.4565,739.9888,783.9909,830.6094,880,932.3275,987.7666,1046.5023,1108.7305,1174.6591,1244.5079,1318.5102,1396.9129,1479.9777,1567.9817,1661.2188,1760,1864.655,1975.5332,2093.0045,2217.461,2349.3181,2489.0159,2637.0205,2793.8259,2959.9554,3135.9635,3322.4376,3520,3729.3101,3951.0664,4186.009,4434.9221,4698.6363,4978.0317,5274.0409,5587.6517,5919.9108,6271.927,6644.8752,7040,7458.6202,7902.1328,8372.0181,8869.8442,9397.2726,9956.0635,10548.0818,11175.3034,11839.8215,12543.854};
#elif OSC_TIMER_DIVIDER == 64
  static float note_to_hz[128] = {8.1758,8.662,9.177,9.7227,10.3009,10.9134,11.5623,12.2499,12.9783,13.75,14.5676,15.4339,16.3516,17.3239,18.354,19.4454,20.6017,21.8268,23.1247,24.4997,25.9565,27.5,29.1352,30.8677,32.7032,34.6478,36.7081,38.8909,41.2034,43.6535,46.2493,48.9994,51.9131,55,58.2705,61.7354,65.4064,69.2957,73.4162,77.7817,82.4069,87.3071,92.4986,97.9989,103.8262,110,116.5409,123.4708,130.8128,138.5913,146.8324,155.5635,164.8138,174.6141,184.9972,195.9977,207.6523,220,233.0819,246.9417,261.6256,277.1826,293.6648,311.127,329.6276,349.2282,369.9944,391.9954,415.3047,440,466.1638,493.8833,523.2511,554.3653,587.3295,622.254,659.2551,698.4565,739.9888,783.9909,830.6094,880,932.3275,987.7666,1046.5023,1108.7305,1174.6591,1244.5079,1318.5102,1396.9129,1479.9777,1567.9817,1661.2188,1760,1864.655,1975.5332,2093.0045,2217.461,2349.3181,2489.0159,2637.0205,2793.8259,2959.9554,3135.9635,3322.4376,3520,3729.3101,3951.0664,4186.009,4434.9221,4698.6363,4978.0317,5274.0409,5587.6517,5919.9108,6271.927,6644.8752,7040,7458.6202,7902.1328,8372.0181,8869.8442,9397.2726,9956.0635,10548.0818,11175.3034,11839.8215,12543.854};
#endif

// MIDI Note Number to Timer Period Count
#if OSC_TIMER_DIVIDER == 8
  static unsigned int timer_period[128] = {61156,57724,54484,51426,48540,45815,43244,40817,38526,36364,34323,32396,61156,57724,54484,51426,48540,45815,43244,40817,38526,36364,34323,32396,61156,57724,54484,51426,48540,45815,43244,40817,38526,36364,34323,32396,30578,28862,27242,25713,24270,22908,21622,20408,19263,18182,17161,16198,15289,14431,13621,12856,12135,11454,10811,10204,9631,9091,8581,8099,7645,7215,6810,6428,6067,5727,5405,5102,4816,4545,4290,4050,3822,3608,3405,3214,3034,2863,2703,2551,2408,2273,2145,2025,1911,1804,1703,1607,1517,1432,1351,1276,1204,1136,1073,1012,956,902,851,804,758,716,676,638,602,568,536,506,478,451,426,402,379,358,338,319,301,284,268,253,239,225,213,201,190,179,169,159};
#elif OSC_TIMER_DIVIDER == 64
  static unsigned int timer_period[128] = {30578,28862,27242,25713,24270,22908,21622,20408,19263,18182,17161,16198,15289,14431,13621,12856,12135,11454,10811,10204,9631,9091,8581,8099,7645,7215,6810,6428,6067,5727,5405,5102,4816,4545,4290,4050,3822,3608,3405,3214,3034,2863,2703,2551,2408,2273,2145,2025,1911,1804,1703,1607,1517,1432,1351,1276,1204,1136,1073,1012,956,902,851,804,758,716,676,638,602,568,536,506,478,451,426,402,379,358,338,319,301,284,268,253,239,225,213,201,190,179,169,159,150,142,134,127,119,113,106,100,95,89,84,80,75,71,67,63,60,56,53,50,47,45,42,40,38,36,34,32,30,28,27,25,24,22,21,20};
#endif


#endif


