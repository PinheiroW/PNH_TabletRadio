modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();
        // Chama o sistema central. No servidor, isso executa a criação do diretório e do JSON.
        GetDiPSystemCore(); 
        Print("[PNH_Tablet] Servidor inicializado. Pasta de config verificada.");
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);
        if (identity)
        {
            DiPRPC_SendSettings(identity, GetDiPSystemCore().m_ConfigSettingsClient);
        }
    }
}