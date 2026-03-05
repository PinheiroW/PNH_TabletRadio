class CfgPatches
{
	class PNH_Tablet
	{
		units[]={"PNH_Tablet_Black"};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Characters","DZ_Data","DZ_Scripts"};
	};
};

class CfgMods
{
	class PNH_Tablet
	{
		dir="PNH_Tablet";
		hideName=0;
		hidePicture=1;
		name="PNH Tablet OS";
		author="PNH Team";
		type="mod";
		dependencies[]={"Game","World","Mission"};
		
		class defs
		{
			class gameScriptModule { value=""; files[]={"PNH_Tablet/scripts/3_Game"}; };
			class worldScriptModule { value=""; files[]={"PNH_Tablet/scripts/4_World"}; };
			class missionScriptModule { value=""; files[]={"PNH_Tablet/scripts/5_Mission"}; };
		};
	};
};

class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base {};
	
	class PNH_Tablet_ColorBase: Clothing
	{
		scope=0;
		displayName="Tablet Tatico PNH";
		descriptionShort="Dispositivo tatico multifuncional.";
		model="PNH_Tablet\GPS_Tablet\data\tab2_g.p3d";
		inventorySlot[]={"Armband"};
		itemInfo[]={"Clothing","Armband"};
		animClass="ItemPDA";
		rotationFlags=34;
		weight=500;
		itemSize[]={2,3};
		attachments[]={"BatteryD"};
		
		class ClothingTypes
		{
			male="PNH_Tablet\GPS_Tablet\data\tab2_m.p3d";
			female="PNH_Tablet\GPS_Tablet\data\tab2_f.p3d";
		};
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOff=1;
			energyUsagePerSecond=0.01;
			plugType=1;
			attachmentAction=1;
		};
	};
	
	class PNH_Tablet_Black: PNH_Tablet_ColorBase
	{
		scope=2;
		hiddenSelections[]={"lcd_1","lcd_2","zbytek"};
		hiddenSelectionsTextures[]=
		{
			"PNH_Tablet\GPS_Tablet\data\textures\lcd_co.paa",
			"PNH_Tablet\GPS_Tablet\data\textures\lcd_co.paa",
			"PNH_Tablet\GPS_Tablet\data\textures\tab2_co.paa"
		};
        hiddenSelectionsMaterials[]=
        {
            "PNH_Tablet\GPS_Tablet\data\textures\lcd_mat.rvmat",
            "PNH_Tablet\GPS_Tablet\data\textures\lcd_mat.rvmat",
            "PNH_Tablet\GPS_Tablet\data\textures\tab2.rvmat"
        };
	};
};