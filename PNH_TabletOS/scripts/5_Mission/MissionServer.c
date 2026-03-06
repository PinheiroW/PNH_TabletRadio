modded class MissionServer extends MissionBase
{
	private ref DayZInformationPanelUI m_DiPMenu;
	void MissionServer()
	{
		m_DiPSystemCore = NULL;
		GetDiPSystemCore();
	}

	void ~MissionServer() {
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		player.DiPSteamUID = player.GetIdentity().GetPlainId();
		GetDiPSystemCore().TransferDiPConfigToClient(identity);

		super.InvokeOnConnect(player,identity);
	}
};
