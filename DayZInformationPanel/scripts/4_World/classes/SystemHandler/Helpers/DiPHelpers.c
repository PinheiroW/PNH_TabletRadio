static ref DiPLogger g_DiPLogger;
static DiPLogger GetDiPLogger(){
	if (!g_DiPLogger) {
		g_DiPLogger = new DiPLogger();
	}
	return g_DiPLogger;
}

/*Class that deals with my core class, where config, client and server part of my code are created*/
static ref DiPSystemCore m_DiPSystemCore;
static DiPSystemCore GetDiPSystemCore() {
	if ( !m_DiPSystemCore ) {
		m_DiPSystemCore = new DiPSystemCore;
	}
	return m_DiPSystemCore;
}

/*class that allows to access config on server side everywhere*/
static ref DiPSettings GetDiPConfigServer()	{
	return GetDiPSystemCore().m_DiPSettings;
}

/*class that allows to access config on client side everywhere*/
static ref ConfigSettingsClient GetDiPConfigClient()	{
	return GetDiPSystemCore().m_ConfigSettingsClient;
}

/*Function that allows to get the player variable from its identity => used for RPC*/
static PlayerBase DiPGetPlayerByIdentity(PlayerIdentity sender)
{
	int	low	 =	0;
	int	high =	0;
	GetGame().GetPlayerNetworkIDByIdentityID( sender.GetPlayerId(), low, high );
	return PlayerBase.Cast( GetGame().GetObjectByNetworkId(low, high ));
}
