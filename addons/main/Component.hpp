/**
 * This stock file sets up defines used subsequently by CBA macros.
 * The structure of this file and the related preprocessor files this
 * references are based on the structure of the ALiVE mod.
 */
#define COMPONENT main
#include <\x\vanquish\addons\main\Mod.hpp>

#ifdef DEBUG_ENABLED_MAIN
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_MAIN
    #define DEBUG_SETTINGS DEBUG_SETTINGS_MAIN
#endif

#include <\x\cba\addons\main\script_macros.hpp>