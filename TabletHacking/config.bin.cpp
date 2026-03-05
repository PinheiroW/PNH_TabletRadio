class CfgPatches
{
	class TabletHacking
	{
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
		units[]=
		{
			"HackingTablet",
			"HackingBattery"
		};
		weapons[]={};
	};
};
class CfgMods
{
	class TabletHacking
	{
		dir="";
		name="";
		credits="NightMare.Exe";
		author="NightMare.Exe";
		authorID="0";
		version="0.1";
		extra=0;
		type="mod";
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
					"TabletHacking/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"TabletHacking/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"TabletHacking/scripts/5_Mission"
				};
			};
		};
	};
};
class CfgSlots
{
	class Slot_Att_HackingBattery_1
	{
		name="Att_HackingBattery_1";
		displayName="Hacking Battery";
		selection="att_HackingBattery";
		ghostIcon="set:Storage_Slots image:Storage_Battery";
	};
	class Slot_Att_HackingBattery_2
	{
		name="Att_HackingBattery_2";
		displayName="Hacking Battery";
		selection="att_HackingBattery";
		ghostIcon="set:Storage_Slots image:Storage_Battery";
	};
	class Slot_Att_HackingBattery_3
	{
		name="Att_HackingBattery_3";
		displayName="Hacking Battery";
		selection="att_HackingBattery";
		ghostIcon="set:Storage_Slots image:Storage_Battery";
	};
	class Slot_Att_HackingBattery_4
	{
		name="Att_HackingBattery_4";
		displayName="Hacking Battery";
		selection="att_HackingBattery";
		ghostIcon="set:Storage_Slots image:Storage_Battery";
	};
	class Slot_Att_HackingBattery_5
	{
		name="Att_HackingBattery_5";
		displayName="Hacking Battery";
		selection="att_HackingBattery";
		ghostIcon="set:Storage_Slots image:Storage_Battery";
	};
};
class CfgVehicles
{
	class Container_Base;
	class CombinationLock;
	class Inventory_Base;
	class Battery9V;
	class HackingTablet: Inventory_Base
	{
		scope=2;
		displayName="Hackering Tablet";
		descriptionShort="A Tablet Used for hacking Paragon Storage.";
		model="ParagonStorage\Tablet\Tablet.p3d";
		itemSize[]={4,3};
		weight=800;
		rotationFlags=1;
		hiddenSelections[]=
		{
			"Camo"
		};
		hiddenSelectionsTextures[]=
		{
			"ParagonStorage\Tablet\data\Tablet_Black.paa"
		};
		attachments[]=
		{
			"Att_HackingBattery_1",
			"Att_HackingBattery_2",
			"Att_HackingBattery_3",
			"Att_HackingBattery_4",
			"Att_HackingBattery_5"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"ParagonStorage\Tablet\data\Tablet.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"ParagonStorage\Tablet\data\Tablet.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"ParagonStorage\Tablet\data\Tablet_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"ParagonStorage\Tablet\data\Tablet_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"ParagonStorage\Tablet\data\Tablet_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimationSources
		{
			class top
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
		};
	};
	class HackingBattery: Battery9V
	{
		scope=2;
		displayName="Hacking Tablet Battery";
		descriptionShort="A Battery use for Hacking Tablets";
		model="ParagonStorage\Battery\Battery.p3d";
		itemSize[]={1,1};
		weight=100;
		rotationFlags=1;
		inventorySlot[]=
		{
			"Att_HackingBattery_1",
			"Att_HackingBattery_2",
			"Att_HackingBattery_3",
			"Att_HackingBattery_4",
			"Att_HackingBattery_5"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=20;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"ParagonStorage\Battery\data\Battery1.rvmat",
								"ParagonStorage\Battery\data\Battery1.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"ParagonStorage\Battery\data\Battery1.rvmat",
								"ParagonStorage\Battery\data\Battery1.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"ParagonStorage\Battery\data\Battery1_damage.rvmat",
								"ParagonStorage\Battery\data\Battery1_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"ParagonStorage\Battery\data\Battery1_damage.rvmat",
								"ParagonStorage\Battery\data\Battery1_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"ParagonStorage\Battery\data\Battery1_destruct.rvmat",
								"ParagonStorage\Battery\data\Battery1_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
};
