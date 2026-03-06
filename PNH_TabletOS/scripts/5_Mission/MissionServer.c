modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();
        // Inicializa o sistema central. No servidor, isso dispara a criação do JSON.
        GetDiPSystemCore(); 
        Print("[PNH_Tablet] Sistema inicializado no Servidor.");
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);
        if (identity)
        {
            // Envia as configurações do JSON para o tablet do jogador
            DiPRPC_SendSettings(identity, GetDiPSystemCore().m_ConfigSettingsClient);
        }
    }
}