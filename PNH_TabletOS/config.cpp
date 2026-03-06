class CfgPatches {
    class PNH_TabletOS {
        units[]={}; weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]={"DZ_Data","DZ_Scripts","DZ_Sounds_Effects"};
    };
};

class CfgSoundShaders {
    class PNH_Radio_Base_SoundShader {
        volume = 1;
        range = 25;
    };
    class PNH_Radio_Zombie_SoundShader: PNH_Radio_Base_SoundShader {
        samples[] = {{"PNH_TabletOS\sounds\zombie_broadcast", 1}};
    };
    class PNH_Radio_Jax_SoundShader: PNH_Radio_Base_SoundShader {
        samples[] = {{"PNH_TabletOS\sounds\jax_broadcast", 1}};
    };
    class PNH_Radio_Ezra_SoundShader: PNH_Radio_Base_SoundShader {
        samples[] = {{"PNH_TabletOS\sounds\ezra_broadcast", 1}};
    };
};

class CfgSoundSets {
    class PNH_Radio_Base_SoundSet {
        soundShaders[] = {};
        volumeCurve = "InverseSquare2Curve";
        spatial = 1;
        doppler = 0;
        loop = 0;
    };
    class PNH_Radio_Zombie_SoundSet: PNH_Radio_Base_SoundSet {
        soundShaders[] = {"PNH_Radio_Zombie_SoundShader"};
    };
    class PNH_Radio_Jax_SoundSet: PNH_Radio_Base_SoundSet {
        soundShaders[] = {"PNH_Radio_Jax_SoundShader"};
    };
    class PNH_Radio_Ezra_SoundSet: PNH_Radio_Base_SoundSet {
        soundShaders[] = {"PNH_Radio_Ezra_SoundShader"};
    };
};

class CfgMods {
    class PNH_TabletOS {
        dir = "PNH_TabletOS";
        name = "PNH Tablet OS";
        author = "Pinheiro";
        version = "1.2";
        type = "mod";
        dependencies[] = {"Game", "World", "Mission"};
        class defs {
            class gameScriptModule {
                value = "";
                files[] = {"PNH_TabletOS/scripts/3_Game"};
            };
            class worldScriptModule {
                value = "";
                files[] = {"PNH_TabletOS/scripts/4_World"};
            };
            class missionScriptModule {
                value = "";
                files[] = {"PNH_TabletOS/scripts/5_Mission"};
            };
        };
    };
};