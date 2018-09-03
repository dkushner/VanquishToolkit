#include <\x\vanquish\addons\main\component.hpp>
SCRIPT(vanquish);

/* ----------------------------------------------------------------------------
Function: VAN_fnc_vanquishInit
Description: Initializes server-side configuration and state.

Parameters:
_logic - Reference to module. [Object, module instance]
_sync - Units synchronized to module. [Array, defaults to []]

Returns:
Nil

---------------------------------------------------------------------------- */

#define SUPERCLASS VAN_fnc_baseClass
#define MAINCLASS VAN_fnc_vanquish
#define ALIVE_LATCH ALiVE_eventLog

params [
	["_logic", objNull, [objNull]]
];

if (isNil "_logic") then {
	if (isServer) then {
		if !(isNil QMOD(master)) then {
			ERROR("Attempted to initialize Vanquish with an existing mastermind.");
		} else {
			_logic = (createGroup sideLogic) createUnit [QMOD(master), [0, 0], [], 0, "NONE"];
			MOD(master) = _logic;
		};

		// Sync mastermind instance with clients.
		publicVariable QMOD(master);
	};

	TRACE("Waiting for mastermind to initialize...");
	waitUntil { !isNil QMOD(master) };
	TRACE("Mastermind successfully initialized!");

	// All participants assign local value to the server-initialized value.
	_logic = MOD(master);
};

// Check that our module instance has not already been initialized.
if !(isNil { _logic getVariable "initialized" }) then {
	exitWith { 
		ERROR("Attempted to initialize a mastermind module that was already initialized.");
	}
};

// Track local initialization. Set up pseudo-inheritance.
_logic setVariable ["_initialized", false];
_logic setVariable ["super", SUPERCLASS];
_logic setVariable ["class", MAINCLASS];
_logic setVariable ["moduleType", QMOD(master)];
_logic setVariable ["startupComplete", false];

MOD(master) = _logic;

// Wait for ALiVE to finish loading.
waitUntil { !isNil ALIVE_LATCH };

TRACE_1("vanquish::initialized", _this);

if (isServer) then {
	_logic setVariable ["startupComplete", true, true];
};

// Do submodule initialization.