class DiPSettings
{
	string 			ConfigVersion;
	string 			ServerName;
	string 			DiscordLink;
	string 			DonateLink;

    // As variáveis para o JSON (1 = Sim, 0 = Não)
	int 			AllowUseWhileDriving;
	int 			AllowUseWhileBleeding;

	string 			Tab1_Header;
	ref array<string> Tab1_Info;
	string 			Tab2_Header;
	ref array<string> Tab2_Info;
	string 			Tab3_Header;
	ref array<string> Tab3_Info;
	string 			Tab4_Header;
	ref array<string> Tab4_Info;

	void DiPSettings()
	{
		Tab1_Info 	= new array<string>;
		Tab2_Info 	= new array<string>;
		Tab3_Info 	= new array<string>;
		Tab4_Info 	= new array<string>;
	}

	void DiPDefaultSettings()
	{
		ConfigVersion				 	= "1.2"; 
		ServerName					 	= "YourServerNameHere";
		DiscordLink 				 	= "https://discord.gg/SEDuZWSSpe";
		DonateLink 					 	= "https://www.paypal.me/ApocalypticChaosDayZ";
        
        // Valores padrão ao criar o JSON
		AllowUseWhileDriving 			= 1; 
		AllowUseWhileBleeding 			= 1;

		Tab1_Header				 		= "Tab_1_Text";
		Tab2_Header				 		= "Tab_2_Text";
		Tab3_Header				 		= "Tab_3_Text";
		Tab4_Header				 		= "Tab_4_Text";

		for (int i = 0; i < 10; i++)	{
			Tab1_Info.Insert("Write your desired Tab 1 info here " + i);
			Tab2_Info.Insert("Write your desired Tab 2 info here " + i);
			Tab3_Info.Insert("Write your desired Tab 3 info here " + i);
			Tab4_Info.Insert("Write your desired Tab 4 info here " + i);
		}

		JsonFileLoader<DiPSettings>.JsonSaveFile(DIP_CONFIG, this);
		Print("!~!~! PNH_Tablet Config Padrão Criada !~!~!");
	}

	static ref DiPSettings Load()
	{
		DiPSettings settings = new DiPSettings();

		if ( !FileExist( DIP_CONFIG_ROOT_SERVER ) )
		{
			MakeDirectory( DIP_CONFIG_ROOT_SERVER );
			if ( !FileExist( DIP_CONFIG_DIR_SERVER ) ) MakeDirectory( DIP_CONFIG_DIR_SERVER );
			if ( !FileExist( DIP_LOGGER_DIR_SERVER ) ) MakeDirectory( DIP_LOGGER_DIR_SERVER );
		}

		if (FileExist(DIP_CONFIG)) {
			JsonFileLoader<DiPSettings>.JsonLoadFile(DIP_CONFIG, settings);
			// A alteração que solicitou está aqui:
			Print("!~!~! PNH_Tablet Config Carregadas !~!~!");
		}
		else {
			settings.DiPDefaultSettings();
			Print("!~!~! PNH_Tablet Config Padrão Carregada !~!~!");
		}

		return settings;
	}
};