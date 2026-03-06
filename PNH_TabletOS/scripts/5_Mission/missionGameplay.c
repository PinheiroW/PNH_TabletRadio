modded class MissionGameplay extends MissionBase
{
	private ref DayZInformationPanelUI m_DiPMenu;

	void MissionGameplay()
	{
		// O sistema inicializa-se através da função global centralizada
		GetDiPSystemCore();
	}

	override void OnUpdate(float timeslice)
	{
        super.OnUpdate(timeslice);
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        Input input = GetGame().GetInput();

        if (input.LocalPress("UAUIBack", false))
        {
            if (m_DiPMenu != NULL && GetGame().GetUIManager().GetMenu() == m_DiPMenu) {
                m_DiPMenu.SetMenuOpen(false);
                GetGame().GetUIManager().HideScriptedMenu(m_DiPMenu);
                UnlockControls();
            }
        }

		if (input.LocalPress("UAPNHTablet", false))
        {
            bool canOpen = true;

            if (GetUIManager().GetMenu() && (m_DiPMenu == null || !m_DiPMenu.IsMenuOpen()))
                canOpen = false;

            // Verificação usando o novo Core centralizado
            if (GetDiPSystemCore() && GetDiPSystemCore().m_ConfigSettingsClient)
            {
                if (GetDiPSystemCore().m_ConfigSettingsClient.AllowUseWhileDriving == 0 && player.IsInVehicle())
                    canOpen = false;

                if (GetDiPSystemCore().m_ConfigSettingsClient.AllowUseWhileBleeding == 0 && player.GetBleedingManagerRemote() && player.GetBleedingManagerRemote().GetBleedingSourceCountRemote() > 0)
                    canOpen = false;
            }

            if (canOpen)
            {
                if ( m_DiPMenu ) {
                    if (m_DiPMenu.IsMenuOpen()) {
                        m_DiPMenu.SetMenuOpen(false);
                        GetGame().GetUIManager().HideScriptedMenu(m_DiPMenu);
                        UnlockControls();
                    } else if (GetGame().GetUIManager().GetMenu() == NULL) {
                        GetGame().GetUIManager().ShowScriptedMenu(m_DiPMenu, NULL);
                        m_DiPMenu.SetMenuOpen(true);
                        LockControls();
                    }
                } else if (GetGame().GetUIManager().GetMenu() == NULL && m_DiPMenu == null) {
                    LockControls();
                    m_DiPMenu = DayZInformationPanelUI.Cast(GetUIManager().EnterScriptedMenu(DIP_PANEL, null));
                    m_DiPMenu.SetMenuOpen(true);
                }
            }
        }
    }

    private void LockControls()
    {
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowUICursor( true );
        GetGame().GetMission().GetHud().Show( false );
    }

    private void UnlockControls()
    {
        GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetUIManager().ShowUICursor( false );
        GetGame().GetMission().GetHud().Show( true );
    }
};