class CfgPatches
{
	class PNH_TabletOS
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data","DZ_Scripts"};
	};
};

class CfgMods
{
	class PNH_TabletOS
	{
	    dir="PNH_TabletOS";
	    hideName=1;
	    name="PNH Tablet OS";
	    author="Pinheiro";
	    version="1.0";
	    type="mod";
	    inputs="PNH_TabletOS/scripts/3_Game/inputs.xml";
	    
	    dependencies[]={"Game","World","Mission"};
	    
	    class defs
	    {
			class gameScriptModule
            {
                value="";
                files[]={"PNH_TabletOS/scripts/Common","PNH_TabletOS/scripts/3_Game"};
            };
            class worldScriptModule
            {
                value="";
                files[]={"PNH_TabletOS/scripts/Common","PNH_TabletOS/scripts/4_World"};
            };
            class missionScriptModule
            {
                value="";
                files[]={"PNH_TabletOS/scripts/Common","PNH_TabletOS/scripts/5_Mission"};
            };
        };
    };
};