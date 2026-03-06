// 1. DEFINIÇÃO DAS CLASSES (O compilador aprende o que elas são aqui)
class DiPSystemCore
{
    ref ConfigSettingsClient m_ConfigSettingsClient;
    void DiPSystemCore() {
        m_ConfigSettingsClient = new ConfigSettingsClient;
        if (GetGame().IsServer()) {
            DiPSettings m_DiPSettings = DiPSettings.Load();
            m_ConfigSettingsClient.TransformToSendableConfig(m_DiPSettings);
        }
    }
}

class DiPLogger { 
    void LogInfo(string msg) { Print("[PNH_Tablet] INFO: " + msg); } 
}

class DiPHelpers {
    // Lógica de ajuda aqui
}

// 2. ACESSO GLOBAL (Variáveis estáticas)
static ref DiPSystemCore g_PNH_Core;
static ref DiPLogger     g_PNH_Logger;
static ref DiPHelpers    g_PNH_Helpers;

// 3. FUNÇÕES GLOBAIS (Otimizadas e sem 'ref' nos argumentos para limpar o log)
static DiPSystemCore GetDiPSystemCore() {
    if (!g_PNH_Core) g_PNH_Core = new DiPSystemCore;
    return g_PNH_Core;
}

static DiPLogger GetDiPLogger() {
    if (!g_PNH_Logger) g_PNH_Logger = new DiPLogger;
    return g_PNH_Logger;
}

static DiPHelpers GetDiPHelpers() {
    if (!g_PNH_Helpers) g_PNH_Helpers = new DiPHelpers;
    return g_PNH_Helpers;
}

static ConfigSettingsClient GetDiPConfigClient() {
    return GetDiPSystemCore().m_ConfigSettingsClient;
}