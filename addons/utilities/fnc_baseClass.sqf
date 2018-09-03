#include <\x\vanquish\utilities\component.hpp>
SCRIPT(baseClass);

/* ----------------------------------------------------------------------------
Function: VAN_fnc_baseClass
Description: 
	Constructs a pseudoclass proxy. This functions similarly to the way Javascript handles class "inheritance." All pseudoclasses "inherit" from this base in that they delegate unmatched operations to this class.

Parameters:
	_logic - Reference to bound object. If Nil, will create a new instance. [Object or Nil]
	_operation - String identifier of invoked function. [String]
	_arguments - Array of arguments to pass to the invoked function. [Array]

Returns:
	Result of the method invocation.

Attributes:
	create - Create a pseudoclass instance.
	destroy - Destroy a pseudoclass instance.

Examples:
	(begin example)
	// Create a pseudoclass instance.
	_instance = [nil, "create"] call VAN_fnc_baseClass;

	// Destroy a pseudoclass instance.
	[_instance, "destroy"] call VAN_fnc_baseClass;
	(end)
---------------------------------------------------------------------------- */

private ["_result"];

if (
	isNil "_this" || 
	{ typeName _this != "ARRAY" } || 
	{ count _this == 0 } || 
	{ typeName (_this select 0) != "OBJECT" }
) then {
	_this = [objNull, "create"];
};

TRACE_1("baseClass::invoke", _this);

params [
	["_logic", objNull, [objNull]],
	["_operation", "", [""]],
	["_arguments", objNull, [objNull, [], "", 0, true, false]]
];

_result = true;

switch (_operation) do {
	default {
		ERROR_2("Class ""%1"" does not support operation ""%2"".", _logic, _operation);
	};
	case "create": {
		// Agent is a cheap "vehicle" instance.
		_logic = createAgent ["LOGIC", [0, 0], [], 0, "NONE"];
		_logic setVariable ["class", VAN_fnc_baseClass];
		_logic enableSimulation false;
		_result = _logic;
	};
	case "destroy": {
		_logic setVariable ["class", nil];
		deleteVehicle _logic;
	};
};

TRACE_1("baseClass::return", _result);

_result;