class CfgPatches
{
	class PNH_TabletOS
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};

class CfgMods
{
	class PNH_TabletOS
	{
	    dir="PNH_TabletOS";
	    picture="";
	    action="";
	    hideName=1;
	    hidePicture=1;
	    name="PNH Tablet OS";
	    credits="Pinheiro";
	    author="Pinheiro";
	    authorID="0";
	    version="1.0";
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
                    "PNH_TabletOS/scripts/Common",
                    "PNH_TabletOS/scripts/3_Game"
                };
            };
            class worldScriptModule
            {
                value="";
                files[]=
                {
                    "PNH_TabletOS/scripts/Common",
                    "PNH_TabletOS/scripts/4_World"
                };
            };
            class missionScriptModule
            {
                value="";
                files[]=
                {
                    "PNH_TabletOS/scripts/Common",
                    "PNH_TabletOS/scripts/5_Mission"
                };
            };
        };
    };
};