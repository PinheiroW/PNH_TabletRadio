modded class MissionGameplay
{
    override UIScriptedMenu CreateScriptedMenu(int id)
    {
        UIScriptedMenu menu = NULL;
        menu = super.CreateScriptedMenu(id);
        if (menu) return menu;
        
        if (id == PNH_UI_TABLET_OS)
        {
            menu = new PNH_TabletUI;
            menu.SetID(id);
        }
        return menu;
    }

    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);
        
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (!player) return;

        // Verifica se o jogador tem o tablet nas mãos
        PNH_Tablet_Black tablet = PNH_Tablet_Black.Cast(player.GetHumanInventory().GetEntityInHands());
        UIScriptedMenu currentMenu = GetGame().GetUIManager().GetMenu();

        // Se o tablet estiver nas mãos e LIGADO (com bateria)
        if (tablet && tablet.GetCompEM() && tablet.GetCompEM().IsWorking())
        {
            // Abre a interface gráfica
            if (!currentMenu)
            {
                GetGame().GetUIManager().EnterScriptedMenu(PNH_UI_TABLET_OS, null);
            }
        }
        else
        {
            // Se ele desligar, guardar ou a bateria acabar, fecha a tela sozinho
            if (currentMenu && currentMenu.GetID() == PNH_UI_TABLET_OS)
            {
                currentMenu.Close();
            }
        }
    }
}