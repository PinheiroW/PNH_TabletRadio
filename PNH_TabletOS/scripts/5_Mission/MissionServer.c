modded class MissionServer extends MissionBase
{
	override void OnInit()
	{
		super.OnInit();
		// Inicializa o sistema centralizado no arranque do servidor
		GetDiPSystemCore();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		
        // Envia as configurações do servidor para o tablet do jogador que acabou de ligar
        if (GetDiPSystemCore() && GetDiPSystemCore().m_ConfigSettingsClient)
        {
            DiPRPC_SendSettings(identity, GetDiPSystemCore().m_ConfigSettingsClient);
        }
	}
};