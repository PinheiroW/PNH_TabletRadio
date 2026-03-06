modded class MissionBase
{
    override UIScriptedMenu CreateScriptedMenu(int id)
    {
        UIScriptedMenu menu = NULL;
        menu = super.CreateScriptedMenu(id);
        if (!menu)
        {
            switch (id)
            {
              case DIP_PANEL:
                menu = new DayZInformationPanelUI;
                break;
            }
            if (menu)
            {
                menu.SetID(id);
            }
        }
        return menu;
    }
};
