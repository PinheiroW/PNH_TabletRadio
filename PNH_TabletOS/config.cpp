class CfgPatches
{
	class DIP_Scripts
	{
		requiredAddons[]=
		{
			"DZ_Data"
		};
		units[]={};
		weapons[]={};
	};
};
class CfgMods
{
	class DayZInformationPanel
	{
		dir="DayZInformationPanel";
		name="DayZInformationPanel";
		credits="";
		author="Chubby";
		type="mod";
		inputs="DayZInformationPanel/scripts/3_Game/inputs.xml";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"DayZInformationPanel/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"DayZInformationPanel/scripts/Common",
					"DayZInformationPanel/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"DayZInformationPanel/scripts/Common",
					"DayZInformationPanel/scripts/5_Mission"
				};
			};
		};
	};
};
