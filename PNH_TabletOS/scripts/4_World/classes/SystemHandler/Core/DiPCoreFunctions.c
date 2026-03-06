// Este ficheiro agora apenas lida com Logs e Helpers para não causar erro de carregamento
static ref DiPLogger m_PNH_Logger;
static ref DiPHelpers m_PNH_Helpers;

static DiPLogger GetDiPLogger()
{
	if (!m_PNH_Logger) m_PNH_Logger = new DiPLogger;
	return m_PNH_Logger;
}

static DiPHelpers GetDiPHelpers()
{
	if (!m_PNH_Helpers) m_PNH_Helpers = new DiPHelpers;
	return m_PNH_Helpers;
}

#ifdef DAYZINFOPANEL
// Função de rede (RPC)
static void DiPRPC_SendSettings(PlayerIdentity identity, ConfigSettingsClient config)
{
    GetRPCManager().SendRPC("PNH_TabletOS", "DiPRPC_ReceiveSettings", new Param1<ConfigSettingsClient>(config), true, identity);
}
#endif