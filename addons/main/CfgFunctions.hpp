class CfgFunction {
    class PREFIX {
        class COMPONENT {
            class vanquish {
                description = "Initialize global state for Vanquish.";
                file = "\x\vanquish\addons\main\fnc_vanquish.sqf";
                RECOMPILE;
            };

            class mismatch {
                description = "Alerts players to mod version mismatch.";
                file = "\x\vanquish\addons\main\fnc_mismatch.sqf";
                RECOMPILE;
            };
        };
    };
};