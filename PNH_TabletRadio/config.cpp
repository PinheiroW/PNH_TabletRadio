class CfgPatches
{
	class PNH_TabletRadio
	{
        // Registamos a nova classe do nosso item
		units[]={"PNH_TabletRadio_Black"};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Characters",
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};

class CfgMods
{
	class PNH_TabletRadio
	{
		dir="PNH_TabletRadio";
		hideName=0;
		hidePicture=1;
		name="PNH Tablet Radio";
		author="PNH Team";
		type="mod";
		dependencies[]={"Game","World","Mission"};
		
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]={"PNH_TabletRadio/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={"PNH_TabletRadio/scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]={"PNH_TabletRadio/scripts/5_Mission"};
			};
		};
	};
};

// ==========================================
// HERANÇA DO DI_PUBLICRADIO (ÁUDIO)
// ==========================================
class CfgSoundShaders
{
	class PublicRadio_SoundShader_Base
	{
		volume=1;
		range=50;
	};
	class PublicRadio_Dummy_SoundShader: PublicRadio_SoundShader_Base
	{
		samples[]={ {"dummy_soundset", 1} };
		volume=1;
		range=1;
	};
	class PublicRadio_Ezra_SoundShader: PublicRadio_SoundShader_Base
	{
        // CAMINHO ATUALIZADO PARA O NOVO MOD
		samples[]={ {"PNH_TabletRadio\sounds\ezra_broadcast", 1} };
	};
	class PublicRadio_Jax_SoundShader: PublicRadio_SoundShader_Base
	{
		samples[]={ {"PNH_TabletRadio\sounds\jax_broadcast", 1} };
	};
	class PublicRadio_Static_SoundShader: PublicRadio_SoundShader_Base
	{
		samples[]={ {"PNH_TabletRadio\sounds\jax_broadcast", 1} };
		volume=0.5;
	};
};

class CfgSoundSets
{
	class PublicRadio_SoundSet_Base
	{
		volumeCurve="InverseSquare2Curve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class PublicRadio_Dummy_SoundSet: PublicRadio_SoundSet_Base
	{
		soundShaders[]={"PublicRadio_Dummy_SoundShader"};
	};
	class PublicRadio_Ezra_SoundSet: PublicRadio_SoundSet_Base
	{
		soundShaders[]={"PublicRadio_Ezra_SoundShader"};
	};
	class PublicRadio_Jax_SoundSet: PublicRadio_SoundSet_Base
	{
		soundShaders[]={"PublicRadio_Jax_SoundShader"};
	};
};

// ==========================================
// HERANÇA DO GPS_TABLET (ITEM FÍSICO)
// ==========================================
class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base {};
	
	class PNH_TabletRadio_ColorBase: Clothing
	{
		scope=0;
		displayName="Tablet Tatico PNH";
		descriptionShort="Hub Tatico com sintonizador de radio FM integrado.";
		
        // CAMINHOS ATUALIZADOS PARA A NOVA PASTA
		model="\PNH_TabletRadio\data\tab2_g.p3d";
		inventorySlot[]={"Armband"};
		itemInfo[]={"Clothing","Armband"};
		animClass="ItemPDA";
		rotationFlags=34;
		weight=500;
		itemSize[]={2,3};
		attachments[]={"BatteryD"}; // Exige Bateria para ligar
		
		class ClothingTypes
		{
			male="\PNH_TabletRadio\data\tab2_m.p3d";
			female="\PNH_TabletRadio\data\tab2_f.p3d";
		};
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOff=1;
			energyUsagePerSecond=0.0099999998;
			plugType=1;
			attachmentAction=1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem { soundSet="Shirt_pickup_SoundSet"; id=797; };
				class drop { soundset="Shirt_drop_SoundSet"; id=898; };
			};
		};
	};
	
	class PNH_TabletRadio_Black: PNH_TabletRadio_ColorBase
	{
		scope=2; // Permite spawnar no jogo
		hiddenSelections[]={"lcd_1","lcd_2","zbytek"};
        
        // Usamos os .paa originais do tablet para garantir que a textura aparece
		hiddenSelectionsTextures[]=
		{
			"PNH_TabletRadio\data\textures\lcd_co.paa",
			"PNH_TabletRadio\data\textures\lcd_co.paa",
			"PNH_TabletRadio\data\textures\tab2_co.paa"
		};
	};
};