class DiPSystemCore
{
	ref ConfigSettingsClient m_ConfigSettingsClient;

	void DiPSystemCore()
	{
		if (GetGame().IsServer())
		{
			// O servidor carrega as configurações
			DiPSettings m_DiPSettings = DiPSettings.Load();
			m_ConfigSettingsClient = new ConfigSettingsClient;
			m_ConfigSettingsClient.TransformToSendableConfig(m_DiPSettings);
		}
		else
		{
			// O cliente aguarda o recebimento via RPC
			m_ConfigSettingsClient = new ConfigSettingsClient;
		}
	}
}

// --- FUNÇÕES DE ACESSO GLOBAL (Movidas para aqui para evitar o Crash) ---

static ref DiPSystemCore g_PNH_Core;

static DiPSystemCore GetDiPSystemCore()
{
	if (!g_PNH_Core) g_PNH_Core = new DiPSystemCore;
	return g_PNH_Core;
}

static ConfigSettingsClient GetDiPConfigClient()
{
	return GetDiPSystemCore().m_ConfigSettingsClient;
}