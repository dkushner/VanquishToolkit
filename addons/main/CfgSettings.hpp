class CfgSettings {
    class CBA {
        class Versioning {
            class ADDON {
                main_addon = "VAN_main";
                handler = "VAN_fnc_mismatch";

                class Dependencies {
                    CBA[] = { "cba_main", { 1, 0, 0 }, "true" };
                    XEH[] = { "cba_xeh", { 1, 0, 0 }, "true" };
                };
            };
        };
    };

    class ADDON { };
};