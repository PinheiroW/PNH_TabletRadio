modded class DayZInformationPanelUI extends UIScriptedMenu
{
    // Adicionamos referências para os widgets da lista de rádio
    protected TextListboxWidget m_RadioListbox;
    protected ButtonWidget      m_BtnStopRadio;

    override Widget Init()
    {
        layoutRoot = super.Init();
        
        // Buscamos os widgets originais (Aba 2 usa o scroll e a lista padrão)
        // Se o seu layout tiver um TextListbox específico para rádio, use o nome dele aqui
        m_RadioListbox = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("Tab2_Listbox")); // Exemplo de nome
        m_BtnStopRadio = ButtonWidget.Cast(layoutRoot.FindAnyWidget("Tab2_StopBtn"));      // Botão de Parar

        return layoutRoot;
    }

    // Esta função controla o que aparece quando mudamos de aba
    override void UpdateTab(int tabIndex)
    {
        super.UpdateTab(tabIndex);

        // Se o jogador clicar na Aba 2 (Rádio)
        if (tabIndex == 2)
        {
            SetupRadioTab();
        }
    }

    // Configura a visualização da lista de rádios
    void SetupRadioTab()
    {
        // Se estivermos a usar o TextListbox padrão para mostrar as rádios:
        TextListboxWidget radioList = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("m_Tab2_Info_Text")); // Adaptado ao seu layout original
        if (!radioList) return;

        radioList.ClearItems();
        
        auto stations = PNH_Radio_Database.GetStations();
        for (int i = 0; i < stations.Count(); i++)
        {
            radioList.AddItem(stations.Get(i).m_DisplayName, NULL, 0);
        }
    }

    // Gerencia os cliques nos botões e na lista
    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (super.OnClick(w, x, y, button)) return true;

        // Clique na lista de rádios (Para dar Play)
        if (w.GetName() == "m_Tab2_Info_Text")
        {
            int selectedRow = TextListboxWidget.Cast(w).GetSelectedRow();
            if (selectedRow != -1)
            {
                PNH_RadioManager.GetInstance().PlayStation(selectedRow);
                return true;
            }
        }

        // Se o seu layout tiver um botão de STOP dedicado
        if (w.GetName() == "StopRadioBtn") 
        {
            PNH_RadioManager.GetInstance().Stop();
            return true;
        }

        return false;
    }

    // Segurança: Se fechar o tablet, decidimos se o som para ou continua
    override void OnHide()
    {
        super.OnHide();
        // Se quiser que a música pare ao fechar o tablet, descomente a linha abaixo:
        // PNH_RadioManager.GetInstance().Stop();
    }
};