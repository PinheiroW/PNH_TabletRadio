class DiPSystemCore
{
	ref DiPSettings     						m_DiPSettings;
	ref ConfigSettingsClient 				m_ConfigSettingsServerClient;
	ref ConfigSettingsClient 				m_ConfigSettingsClient;

  ref DiPServer 									m_DiPServer;

	void DiPSystemCore()
  {
		#ifdef DIPDEBUG
		GetDiPLogger().LogInfo("System Core Started | Searching For System Config!");
		#endif

		/*We load every config, class that will run on server side here*/
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			//LOADING CONFIG FILES...
			m_DiPSettings = m_DiPSettings.Load();
			GetDiPLogger().LogInfo("Config Files Found | Loading..");

			m_ConfigSettingsServerClient = new ref ConfigSettingsClient;
			m_ConfigSettingsServerClient.TransformToSendableConfig(m_DiPSettings);
			JsonFileLoader<ConfigSettingsClient>.JsonSaveFile(DIP_CONFIG_CLIENT, m_ConfigSettingsServerClient);

			//Creating server side part
			m_DiPServer = new ref DiPServer;
		}
		else
		{
			/*Then we run every config and class that will run on client only*/
			m_ConfigSettingsClient = new ref ConfigSettingsClient;
		}
		//we call our function that will initiaze our NPC
		InitRPC();
  }

	void ~DiPSystemCore(){
  }

	void InitRPC()
		{
			if (GetGame().IsServer())
			{
				//Server calls

			}
			else
			{
				//Client calls
				GetRPCManager().AddRPC("DiP", "GetDiPClientConfig", this, SingeplayerExecutionType.Server);
			}
		}


		void TransferDiPConfigToClient(ref PlayerIdentity sender = NULL)
		{
				#ifdef DIPDEBUG
	      GetDiPLogger().LogInfo("Transferring Useable Config To Client!");
	      #endif
				GetRPCManager().SendRPC("DiP", "GetDiPClientConfig",  new Param1<ref ConfigSettingsClient>(m_ConfigSettingsServerClient), true, sender);
		}

		/*RPC Function called on client*/
		void GetDiPClientConfig(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
		{
			if(!GetGame().IsClient())return;

			Param1<ref ConfigSettingsClient> data;
	     if (!ctx.Read(data))
	       return;

			#ifdef DIPDEBUG
	 		GetDiPLogger().LogInfo("Loading Client Config!");
	 		#endif

			m_ConfigSettingsClient = data.param1;
		}
	};
