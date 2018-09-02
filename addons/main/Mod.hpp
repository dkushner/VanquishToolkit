#define PREFIX VAN

#define MAJOR 1
#define MINOR 0
#define PATCHLVL 0

#define BUILD 0000000

#define VERSION MAJOR.MINOR.PATCHLVL.BUILD
#define VERSION_AR MAJOR,MINOR,PATCHLVL,BUILD

#define REQUIRED_VERSION 1.70

// Alias CBA module-level global variable accessors.
#define MOD(vname) GVARMAIN(vname)
#define QMOD(vname) QUOTE(GVARMAIN(vname))

#ifdef RECOMPILE
    #undef RECOMPILE
#endif

#define RECOMPILE recompile = 1
#define MODULE_AUTHOR QUOTE(Vanquish Dev Team)