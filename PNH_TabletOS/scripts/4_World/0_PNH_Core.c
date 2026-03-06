// --- 1. CLASSES DE LOG E SUPORTE ---
class DiPLogger {
    void LogInfo(string msg) { Print("[PNH_Tablet] " + msg); }
}

class DiPHelpers { }

// --- 2. CONFIGURAÇÃO DO CLIENTE ---
class ConfigSettingsClient {
    string ConfigVersion, ServerName, DiscordLink, DonateLink;
    int AllowUseWhileDriving, AllowUseWhileBleeding;
    string Tab1_Header, Tab2_Header, Tab3_Header, Tab4_Header;
    ref array<string> Tab1_Info = new array<string>;
    ref array<string> Tab2_Info = new array<string>;
    ref array<string> Tab3_Info = new array<string>;
    ref array<string> Tab4_Info = new array<string>;

    void TransformToSendableConfig(DiPSettings settings) {
        ConfigVersion = settings.ConfigVersion;
        ServerName = settings.ServerName;
        DiscordLink = settings.DiscordLink;
        DonateLink = settings.DonateLink;
        AllowUseWhileDriving = settings.AllowUseWhileDriving;
        AllowUseWhileBleeding = settings.AllowUseWhileBleeding;
        Tab1_Header = settings.Tab1_Header;
        Tab2_Header = settings.Tab2_Header;
        Tab3_Header = settings.Tab3_Header;
        Tab4_Header = settings.Tab4_Header;
        
        Tab1_Info.Clear();
        Tab2_Info.Clear();
        Tab3_Info.Clear();
        Tab4_Info.Clear();

        for(int i=0; i<settings.Tab1_Info.Count(); i++) Tab1_Info.Insert(settings.Tab1_Info[i]);
        for(int j=0; j<settings.Tab2_Info.Count(); j++) Tab2_Info.Insert(settings.Tab2_Info[j]);
        for(int k=0; k<settings.Tab3_Info.Count(); k++) Tab3_Info.Insert(settings.Tab3_Info[k]);
        for(int l=0; l<settings.Tab4_Info.Count(); l++) Tab4_Info.Insert(settings.Tab4_Info[l]);
    }
}

// --- 3. SISTEMA CORE ---
class DiPSystemCore {
    ref ConfigSettingsClient m_ConfigSettingsClient;

    void DiPSystemCore() {
        m_ConfigSettingsClient = new ConfigSettingsClient;
        
        if (GetGame().IsServer()) {
            DiPSettings settings = DiPSettings.Load();
            m_ConfigSettingsClient.TransformToSendableConfig(settings);
        } else {
            // Regista o recetor no Cliente
            GetRPCManager().AddRPC("PNH_TabletOS", "DiPRPC_ReceiveSettings", this, SingleplayerExecutionType.Both);
        }
    }

    // FIX-ME REMOVIDO: Retirados os 'ref' dos argumentos para limpar o log
    void DiPRPC_ReceiveSettings(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target) {
        Param1<ConfigSettingsClient> data;
        if (!ctx.Read(data)) return;
        
        m_ConfigSettingsClient = data.param1;
        Print("[PNH_Tablet] DADOS RECEBIDOS: Tablet populado com sucesso!");
    }
}

// --- 4. ACESSO GLOBAL ---
static ref DiPSystemCore g_PNH_Core;

static DiPSystemCore GetDiPSystemCore() {
    if (!g_PNH_Core) g_PNH_Core = new DiPSystemCore;
    return g_PNH_Core;
}

static ConfigSettingsClient GetDiPConfigClient() {
    return GetDiPSystemCore().m_ConfigSettingsClient;
}

// Função para o Servidor enviar dados (Removido 'ref' do argumento identity)
static void DiPRPC_SendSettings(PlayerIdentity identity, ConfigSettingsClient config) {
    GetRPCManager().SendRPC("PNH_TabletOS", "DiPRPC_ReceiveSettings", new Param1<ConfigSettingsClient>(config), true, identity);
}