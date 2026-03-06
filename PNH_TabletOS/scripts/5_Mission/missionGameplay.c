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

        // Fechar Menu com botão "Voltar/ESC"
        if (input.LocalPress("UAUIBack", false))
        {
            if (m_DiPMenu != NULL && GetGame().GetUIManager().GetMenu() == m_DiPMenu) {
                m_DiPMenu.SetMenuOpen(false);
                GetGame().GetUIManager().HideScriptedMenu(m_DiPMenu);
                UnlockControls();
            }
        }

        // Tenta abrir ou fechar o Tablet ao pressionar "M"
		if (input.LocalPress("UAPNHTablet", false))
        {
            bool canOpen = true;

            // REGRA FIXA: Nunca abrir por cima do inventário do jogador (Para não bugar a tela)
            if (GetUIManager().GetMenu() && (m_DiPMenu == null || !m_DiPMenu.IsMenuOpen()))
            {
                canOpen = false;
            }

            // APLICAR AS REGRAS DO ARQUIVO JSON
            if (GetDiPSystemCore() && GetDiPSystemCore().m_ConfigSettingsClient)
            {
                // Se o JSON está configurado como 0 (Não), e o jogador está no veículo, não abre.
                if (GetDiPSystemCore().m_ConfigSettingsClient.AllowUseWhileDriving == 0 && player.IsInVehicle())
                {
                    canOpen = false;
                }

                // Se o JSON está configurado como 0 (Não), e o jogador está sangrando, não abre.
                if (GetDiPSystemCore().m_ConfigSettingsClient.AllowUseWhileBleeding == 0 && player.GetBleedingManagerRemote() && player.GetBleedingManagerRemote().GetBleedingSourceCountRemote() > 0)
                {
                    canOpen = false;
                }
            }

            // SE TUDO FOR PERMITIDO, ABRE OU FECHA A TELA!
            if (canOpen)
            {
                if ( m_DiPMenu ) {
                    if (m_DiPMenu.IsMenuOpen()) {
                        // Ocultar Menu
                        m_DiPMenu.SetMenuOpen(false);
                        GetGame().GetUIManager().HideScriptedMenu(m_DiPMenu);
                        UnlockControls();
                    } else if (GetGame().GetUIManager().GetMenu() == NULL) {
                        // Mostrar Menu
                        GetGame().GetUIManager().ShowScriptedMenu(m_DiPMenu, NULL);
                        m_DiPMenu.SetMenuOpen(true);
                        LockControls();
                    }
                } else if (GetGame().GetUIManager().GetMenu() == NULL && m_DiPMenu == null) {
                    // Criar Menu a primeira vez
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