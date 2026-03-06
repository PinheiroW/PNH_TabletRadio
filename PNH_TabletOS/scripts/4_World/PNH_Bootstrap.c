// --- DEFINIÇÕES DE CLASSE ---
class DiPSystemCore
{
    ref ConfigSettingsClient m_ConfigSettingsClient;

    void DiPSystemCore()
    {
        m_ConfigSettingsClient = new ConfigSettingsClient;
        if (GetGame().IsServer())
        {
            DiPSettings settings = DiPSettings.Load();
            m_ConfigSettingsClient.TransformToSendableConfig(settings);
        }
    }
}

class DiPLogger
{
    void LogInfo(string msg) { Print("[PNH_Tablet] " + msg); }
}

class DiPHelpers
{
    // Funções de suporte geral
}

// --- INSTÂNCIAS GLOBAIS ---
static ref DiPSystemCore g_PNH_Core;
static ref DiPLogger     g_PNH_Logger;
static ref DiPHelpers    g_PNH_Helpers;

// --- FUNÇÕES DE ACESSO ---
static DiPSystemCore GetDiPSystemCore()
{
    if (!g_PNH_Core) g_PNH_Core = new DiPSystemCore;
    return g_PNH_Core;
}

static DiPLogger GetDiPLogger()
{
    if (!g_PNH_Logger) g_PNH_Logger = new DiPLogger;
    return g_PNH_Logger;
}

static DiPHelpers GetDiPHelpers()
{
    if (!g_PNH_Helpers) g_PNH_Helpers = new DiPHelpers;
    return g_PNH_Helpers;
}

static ConfigSettingsClient GetDiPConfigClient()
{
    return GetDiPSystemCore().m_ConfigSettingsClient;
}

// Limpeza de logs (FIX-ME) removendo 'ref' dos argumentos
static void SetDiPConfigClient(ConfigSettingsClient config)
{
    GetDiPSystemCore().m_ConfigSettingsClient = config;
}