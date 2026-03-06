modded class MissionGameplay extends MissionBase
{
	private ref DayZInformationPanelUI m_DiPMenu;

	void MissionGameplay()
	{
		m_DiPSystemCore = NULL;
		GetDiPSystemCore();
	}

	void ~MissionGameplay()
  {

  }

	override void OnInit()
	{
		super.OnInit();

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

				if ( !player.IsInVehicle() /*not in car*/ && !player.GetBleedingManagerRemote().GetBleedingSourceCountRemote() /*not bleeding*/ && !GetUIManager().GetMenu() /*no other menu open*/ && input.LocalPress("UAOpenInformationPanel", false) )
        {
            if ( m_DiPMenu ) {
                if (m_DiPMenu.IsMenuOpen()) {
                    //Hide Menu
                    m_DiPMenu.SetMenuOpen(false);
                    GetGame().GetUIManager().HideScriptedMenu(m_DiPMenu);
                    UnlockControls();
                } else if (GetGame().GetUIManager().GetMenu() == NULL) {
                    //Show Menu
                    GetGame().GetUIManager().ShowScriptedMenu(m_DiPMenu, NULL);
                    m_DiPMenu.SetMenuOpen(true);
                    LockControls();
                }
            } else if (GetGame().GetUIManager().GetMenu() == NULL && m_DiPMenu == null) {
                //Create Menu
                LockControls();
                m_DiPMenu = DayZInformationPanelUI.Cast(GetUIManager().EnterScriptedMenu(DIP_PANEL, null));
                m_DiPMenu.SetMenuOpen(true);
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
