class PNH_TabletUI extends UIScriptedMenu
{
    private Widget m_PanelTab1, m_PanelTab2, m_PanelTab3, m_PanelTab4;
    private TextWidget m_TimeText, m_ServerNameText;
    private TextWidget m_TitleTab1, m_TitleTab2, m_TitleTab3, m_TitleTab4;

    override Widget Init()
    {
        layoutRoot = GetGame().GetWorkspace().CreateWidgets("PNH_Tablet/GUI/InfoPanel1.layout");

        m_PanelTab1 = layoutRoot.FindAnyWidget("Panel_Tab1");
        m_PanelTab2 = layoutRoot.FindAnyWidget("Panel_Tab2");
        m_PanelTab3 = layoutRoot.FindAnyWidget("Panel_Tab3");
        m_PanelTab4 = layoutRoot.FindAnyWidget("Panel_Tab4");

        m_TitleTab1 = TextWidget.Cast(layoutRoot.FindAnyWidget("txt_Tab1"));
        m_TitleTab2 = TextWidget.Cast(layoutRoot.FindAnyWidget("txt_Tab2"));
        m_TitleTab3 = TextWidget.Cast(layoutRoot.FindAnyWidget("txt_Tab3"));
        m_TitleTab4 = TextWidget.Cast(layoutRoot.FindAnyWidget("txt_Tab4"));

        m_TimeText = TextWidget.Cast(layoutRoot.FindAnyWidget("txt_IPServerTime"));
        m_ServerNameText = TextWidget.Cast(layoutRoot.FindAnyWidget("txt_IPServerName"));

        if (m_ServerNameText) m_ServerNameText.SetText("PNH TACTICAL OS - USER: PINHEIRO");
        
        if (m_TitleTab1) m_TitleTab1.SetText("INÍCIO");
        if (m_TitleTab2) m_TitleTab2.SetText("MAPA SATÉLITE");
        if (m_TitleTab3) m_TitleTab3.SetText("SINTONIZADOR FM");
        if (m_TitleTab4) m_TitleTab4.SetText("SISTEMA DE EMERGÊNCIA (SOS)");

        ShowTab(1);

        return layoutRoot;
    }

    override void OnShow()
    {
        super.OnShow();
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetInput().ChangeGameFocus(1);
        
        GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(UpdateTime, 1000, true);
        UpdateTime();
    }

    override void OnHide()
    {
        super.OnHide();
        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(UpdateTime);
    }

    void UpdateTime()
    {
        if (m_TimeText)
        {
            int year, month, day, hour, minute;
            GetGame().GetWorld().GetDate(year, month, day, hour, minute);
            
            string minStr = minute.ToString();
            if (minute < 10) minStr = "0" + minStr;
            
            string hrStr = hour.ToString();
            if (hour < 10) hrStr = "0" + hrStr;
            
            m_TimeText.SetText(hrStr + ":" + minStr);
        }
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
        string name = w.GetName();

        if (name == "btn_Tab1") { ShowTab(1); return true; }
        if (name == "btn_Tab2") { ShowTab(2); return true; }
        if (name == "btn_Tab3") { ShowTab(3); return true; }
        if (name == "btn_Tab4") { ShowTab(4); return true; }

        return super.OnClick(w, x, y, button);
    }

    void ShowTab(int tabIndex)
    {
        if (m_PanelTab1) m_PanelTab1.Show(false);
        if (m_PanelTab2) m_PanelTab2.Show(false);
        if (m_PanelTab3) m_PanelTab3.Show(false);
        if (m_PanelTab4) m_PanelTab4.Show(false);

        if (tabIndex == 1 && m_PanelTab1) m_PanelTab1.Show(true);
        if (tabIndex == 2 && m_PanelTab2) m_PanelTab2.Show(true);
        if (tabIndex == 3 && m_PanelTab3) m_PanelTab3.Show(true);
        if (tabIndex == 4 && m_PanelTab4) m_PanelTab4.Show(true);
        
        // CORREÇÃO DO CRASH: Usando o gestor de efeitos sonoros correto da Engine.
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player)
        {
            SEffectManager.PlaySound("Battery_Insert_SoundSet", player.GetPosition()); 
        }
    }
}