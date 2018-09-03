#define MODULE_NAME VAN_master
#define MVAR(var) DOUBLES(MODULE_NAME, var)

class CfgFactionClasses {
    class Vanquish {
        displayName = "Vanquish Mastermind";
        priority = 0;
        side = 7;
    };
};

/*
 * Copy ALiVE's custom 3DEN UI component that implements a nice little
 * sub-header for each attribute window.
 */
class Cfg3DEN {
    class Attributes {
        class Default;
        class TitleWide: Default {
            class Controls {
                class Title;
            };
        };

        class VAN_ModuleSubtitle: TitleWide {
            class Controls: Controls {
                class Title: Title {
                    style = 2;
                    colorText[] = { 1, 1, 1, 0.4 };
                };
            };
        };
    };
};

class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class ArgumentsBaseUnits {
            class Units;
        };

        class AttributesBase {
            class Default;
            class Edit;
            class Combo;
            class Checkbox;
            class CheckboxNumber;
            class ModuleDescription;
        };

        class ModuleDescription {
            class AnyBrain;
        };
    };

    /**
     * Create a logical module base class with protected access.
     */
    class ModuleVanquishBase: Module_F {
        scope = 1;
        displayName = "EditorVanquishBase";
        category = "Vanquish";

        class AttributesBase: AttributesBase {
            class VAN_ModuleSubtitle: Default {
                control = "VAN_ModuleSubtitle";
                defaultValue = "''";
            };
        };
    };

    class VAN_master: ModuleVanquishBase {
        scope = 2;
        displayName = "Vanquish Mastermind";
        icon = "x\vanquish\addons\main\icon-mastermind.paa";
        picture = "x\vanquish\addons\main\icon-mastermind.paa";
        functionPriority = 40;
        isGlobal = 2;
        function = "VAN_fnc_vanquish";
        author = MODULE_AUTHOR;

        class Attributes: AttributesBase {
            class VAN_Debug: Combo {
                property = MVAR(VAN_Debug);
                displayName = "Enable Debugging?";
                tooltip = "Enables debug logging for Vanquish systems.";
                defaultValue = """false""";

                class Values {
                    class Yes {
                        name = "Yes";
                        value = "true";
                    };

                    class No {
                        name = "No";
                        value = "false";
                    };
                };
            };

            class ModuleDescription: ModuleDescription { };
        };

        class ModuleDescription: ModuleDescription {
            description[] = {
                "Vanquish Mastermind",
                "",
                "Manages game state across multiple game sessions."
            };
        };
    };
};
