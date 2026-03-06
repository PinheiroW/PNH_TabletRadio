modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();
        // Inicializa o Core e carrega o JSON
        GetDiPSystemCore(); 
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);
        
        if (identity && player)
        {
            DiPSystemCore core = GetDiPSystemCore();
            
            // Verificação de segurança: O servidor tem os dados para enviar?
            if (core && core.m_ConfigSettingsClient)
            {
                // Envia as configurações para o tablet do jogador
                DiPRPC_SendSettings(identity, core.m_ConfigSettingsClient);
                Print("[PNH_Tablet] Sucesso: Configurações enviadas para " + identity.GetName());
            }
            else
            {
                Print("[PNH_Tablet] Erro Crítico: Tentativa de envio falhou pois m_ConfigSettingsClient está nulo!");
            }
        }
    }
}