class DayZInformationPanelUI extends UIScriptedMenu
{
    protected Widget m_PanelTab1, m_PanelTab2, m_PanelTab3, m_PanelTab4;
    protected TextWidget m_HeaderTab1, m_HeaderTab2, m_HeaderTab3, m_HeaderTab4, m_ServerName, m_ServerTime;
    protected TextListboxWidget m_ListBox1, m_ListBox2, m_ListBox3, m_ListBox4;
    protected bool m_MenuOpen = false;

    override Widget Init()
    {
        layoutRoot = GetGame().GetWorkspace().CreateWidgets("PNH_TabletOS/GUI/InfoPanel1.layout");
        
        m_ServerName = TextWidget.Cast(layoutRoot.FindAnyWidget("txt_IPServerName"));
        m_ServerTime = TextWidget.Cast(layoutRoot.FindAnyWidget("txt_IPServerTime"));
        
        m_PanelTab1 = layoutRoot.FindAnyWidget("Panel_Tab1");
        m_PanelTab2 = layoutRoot.FindAnyWidget("Panel_Tab2");
        m_PanelTab3 = layoutRoot.FindAnyWidget("Panel_Tab3");
        m_PanelTab4 = layoutRoot.FindAnyWidget("Panel_Tab4");

        m_ListBox1 = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("lstbox_Tab1"));
        m_ListBox2 = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("lstbox_Tab2"));
        m_ListBox3 = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("lstbox_Tab3"));
        m_ListBox4 = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("lstbox_Tab4"));

        m_HeaderTab1 = TextWidget.Cast(layoutRoot.FindAnyWidget("txt_Tab1"));
        m_HeaderTab2 = TextWidget.Cast(layoutRoot.FindAnyWidget("txt_Tab2"));
        m_HeaderTab3 = TextWidget.Cast(layoutRoot.FindAnyWidget("txt_Tab3"));
        m_HeaderTab4 = TextWidget.Cast(layoutRoot.FindAnyWidget("txt_Tab4"));

        UpdateTab(1);
        return layoutRoot;
    }

    void SetMenuOpen(bool open) { m_MenuOpen = open; }
    bool IsMenuOpen() { return m_MenuOpen; }

    void UpdateTab(int tabIndex)
    {
        ConfigSettingsClient config = GetDiPConfigClient();
        if (!config) return;

        if (m_ServerName) m_ServerName.SetText(config.ServerName);

        m_PanelTab1.Show(tabIndex == 1);
        m_PanelTab2.Show(tabIndex == 2);
        m_PanelTab3.Show(tabIndex == 3);
        m_PanelTab4.Show(tabIndex == 4);

        m_HeaderTab1.SetText(config.Tab1_Header);
        m_HeaderTab2.SetText(config.Tab2_Header);
        m_HeaderTab3.SetText(config.Tab3_Header);
        m_HeaderTab4.SetText(config.Tab4_Header);

        if (tabIndex == 2) {
            m_ListBox2.ClearItems();
            auto stations = PNH_Radio_Database.GetStations();
            for (int i = 0; i < stations.Count(); i++) {
                m_ListBox2.AddItem(stations.Get(i).m_DisplayName, NULL, 0);
            }
        } else {
            array<string> info;
            TextListboxWidget currentBox;
            if (tabIndex == 1) { info = config.Tab1_Info; currentBox = m_ListBox1; }
            if (tabIndex == 3) { info = config.Tab3_Info; currentBox = m_ListBox3; }
            if (tabIndex == 4) { info = config.Tab4_Info; currentBox = m_ListBox4; }

            if (info && currentBox) {
                currentBox.ClearItems();
                for (int j = 0; j < info.Count(); j++) {
                    currentBox.AddItem(info.Get(j), NULL, 0);
                }
            }
        }
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
        string name = w.GetName();

        // Navegação das abas
        if (name == "btn_Tab1") { UpdateTab(1); return true; }
        if (name == "btn_Tab2") { UpdateTab(2); return true; }
        if (name == "btn_Tab3") { UpdateTab(3); return true; }
        if (name == "btn_Tab4") { UpdateTab(4); return true; }

        // Links
        if (name == "btn_Discord") { GetGame().OpenURL(GetDiPConfigClient().DiscordLink); return true; }
        if (name == "btn_Donate") { GetGame().OpenURL(GetDiPConfigClient().DonateLink); return true; }

        // O seu clique original diretamente na lista
        if (name == "lstbox_Tab2") {
            int row = m_ListBox2.GetSelectedRow();
            if (row != -1) {
                PNH_RadioManager.GetInstance().PlayStation(row);
            }
            return true;
        }

        return false;
    }

    override void Update(float timeslice)
    {
        super.Update(timeslice);
        if (m_ServerTime) {
            int year, month, day, hour, minute;
            GetHourMinuteSecond(hour, minute, year);
            string time = hour.ToStringLen(2) + ":" + minute.ToStringLen(2);
            m_ServerTime.SetText(time);
        }
    }
};