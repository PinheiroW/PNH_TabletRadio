class ConfigSettingsClient
{
	string 			ConfigVersion;
	string 			ServerName;
	string 			DiscordLink;
	string 			DonateLink;

    // As variáveis a serem enviadas para o jogador
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

	void ConfigSettingsClient()
	{
		Tab1_Info 	= new array<string>;
		Tab2_Info 	= new array<string>;
		Tab3_Info 	= new array<string>;
		Tab4_Info 	= new array<string>;
	}

	void TransformToSendableConfig(DiPSettings m_DiPSettings)
	{
		#ifdef DIPDEBUG
		GetDiPLogger().LogInfo("Creating Useable Client Config!");
		#endif

		ConfigVersion				 	= m_DiPSettings.ConfigVersion;
		ServerName					 	= m_DiPSettings.ServerName;
		DiscordLink 				 	= m_DiPSettings.DiscordLink;
		DonateLink 					 	= m_DiPSettings.DonateLink;
        
        // Passando a informação do servidor para o cliente
		AllowUseWhileDriving 			= m_DiPSettings.AllowUseWhileDriving;
		AllowUseWhileBleeding 			= m_DiPSettings.AllowUseWhileBleeding;

		Tab1_Header				 		= m_DiPSettings.Tab1_Header;
		Tab2_Header				 		= m_DiPSettings.Tab2_Header;
		Tab3_Header				 		= m_DiPSettings.Tab3_Header;
		Tab4_Header			 			= m_DiPSettings.Tab4_Header;

		for(int o=0;o< m_DiPSettings.Tab1_Info.Count();o++) Tab1_Info.Insert(m_DiPSettings.Tab1_Info.Get(o));
		for(int f=0;f< m_DiPSettings.Tab2_Info.Count();f++) Tab2_Info.Insert(m_DiPSettings.Tab2_Info.Get(f));
		for(int l=0;l< m_DiPSettings.Tab3_Info.Count();l++) Tab3_Info.Insert(m_DiPSettings.Tab3_Info.Get(l));
		for(int b=0;b< m_DiPSettings.Tab4_Info.Count();b++) Tab4_Info.Insert(m_DiPSettings.Tab4_Info.Get(b));
	}
};