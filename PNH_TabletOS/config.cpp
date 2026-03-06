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

class CfgSounds
{
	// Definição das trilhas de rádio
	class PNH_Radio_Zombie
	{
		sound[] = {"PNH_TabletOS\sounds\zombie_broadcast.ogg", 1.0, 1};
	};
	class PNH_Radio_Jax
	{
		sound[] = {"PNH_TabletOS\sounds\jax_broadcast.ogg", 1.0, 1};
	};
	class PNH_Radio_Ezra
	{
		sound[] = {"PNH_TabletOS\sounds\ezra_broadcast.ogg", 1.0, 1};
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
	    
	    // Link para o arquivo de inputs que organizamos na aba PNH
	    inputs="PNH_TabletOS/scripts/3_Game/inputs.xml";
	    
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