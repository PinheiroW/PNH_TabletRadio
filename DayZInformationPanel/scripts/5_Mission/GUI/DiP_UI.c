class DayZInformationPanelUI extends UIScriptedMenu
{
  private bool                      m_Initialized;
  private bool                      m_IsMenuOpen;

  private ButtonWidget 						  m_btn_Discord;
  private ButtonWidget 						  m_btn_Donate;
  private ButtonWidget 						  m_btn_Tab1;
  private ButtonWidget 						  m_btn_Tab2;
  private ButtonWidget 						  m_btn_Tab3;
  private ButtonWidget 						  m_btn_Tab4;

  protected TextWidget 						  m_IPServerName;
  protected TextWidget 						  m_IPServerTime;
  protected TextWidget 						  m_txt_Tab1;
  protected TextWidget 						  m_txt_Tab2;
  protected TextWidget 						  m_txt_Tab3;
  protected TextWidget 						  m_txt_Tab4;

  private Widget                    m_Panel_Tab1;
  private Widget                    m_Panel_Tab2;
  private Widget                    m_Panel_Tab3;
  private Widget                    m_Panel_Tab4;

  // private RichTextWidget            m_txt_Info_Tab1;
  // private RichTextWidget            m_txt_Info_Tab2;
  // private RichTextWidget            m_txt_Info_Tab3;
  // private RichTextWidget            m_txt_Info_Tab4;
  private TextListboxWidget 					m_Tab1List;
	private TextListboxWidget 					m_Tab2List;
	private TextListboxWidget 					m_Tab3List;
	private TextListboxWidget 					m_Tab4List;



  private string                    m_Link1, m_Link2;
  private   bool                    m_InfoPanelIsVisible;

  private ScrollWidget              m_Tab1Scroll;

  void DayZInformationPanelUI()
  {

  }

  void ~DayZInformationPanelUI()
   {
       PPEffects.SetBlurMenu( 0 );
       GetGame().GetUIManager().Back();
       g_Game.GetUIManager().ShowCursor(true);
       g_Game.GetUIManager().ShowUICursor(false);
       GetGame().GetInput().ResetGameFocus();
       GetGame().GetMission().PlayerControlEnable(false);
       GetGame().GetMission().GetHud().Show( true );

       //Destroy root widget and all its children
       if ( layoutRoot )
         layoutRoot.Unlink();
   }


  //after show
    override void OnShow()
    {
        super.OnShow();
        PPEffects.SetBlurMenu( 0.5 ); //Add blurr effect
        UIHandle();
    }

    //after hide
    override void OnHide()
    {
        super.OnHide();
        PPEffects.SetBlurMenu( 0 ); //Remove blurr effect

        //Unlock controls, this also happens in missionGameplay.c however including it here will assure control is gained back incase that method is not invoked.
        //That can occur when other mods / scripts force a menu on screen illegally
        g_Game.GetUIManager().ShowCursor(true);
        g_Game.GetUIManager().ShowUICursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetMission().GetHud().Show( true );
        GetGame ().GetCallQueue (CALL_CATEGORY_GUI).Remove(IPServerTime);
    }


	override Widget Init()
  {
    if (!m_Initialized) //Only draw and init widgets if not already done that, since this function is called each time you do ( ShowScriptedMenu() )
    {
      layoutRoot            = GetGame().GetWorkspace().CreateWidgets("DayZInformationPanel/GUI/InfoPanel1.layout");

      m_IPServerName 			  =	TextWidget.Cast( layoutRoot.FindAnyWidget( "txt_IPServerName" ));
      m_IPServerTime 			  =	TextWidget.Cast( layoutRoot.FindAnyWidget( "txt_IPServerTime" ));

      m_btn_Discord					=	ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_Discord" ));
      m_btn_Donate					=	ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_Donate" ));

      //Tab1
      m_btn_Tab1					  =	ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_Tab1" ));
      m_Panel_Tab1          =	Widget.Cast( layoutRoot.FindAnyWidget( "Panel_Tab1" ));
      m_txt_Tab1					  =	TextWidget.Cast( layoutRoot.FindAnyWidget( "txt_Tab1" ));
      m_Tab1List 						=	TextListboxWidget.Cast( layoutRoot.FindAnyWidget( "lstbox_Tab1" ));
      // m_txt_Info_Tab1       =	RichTextWidget.Cast( layoutRoot.FindAnyWidget( "txt_Info_Tab1" ));

      //Tab2
      m_btn_Tab2				    =	ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_Tab2" ));
      m_Panel_Tab2          =	Widget.Cast( layoutRoot.FindAnyWidget( "Panel_Tab2" ));
      m_txt_Tab2					  =	TextWidget.Cast( layoutRoot.FindAnyWidget( "txt_Tab2" ));
      m_Tab2List 						=	TextListboxWidget.Cast( layoutRoot.FindAnyWidget( "lstbox_Tab2" ));
      // m_txt_Info_Tab2       =	RichTextWidget.Cast( layoutRoot.FindAnyWidget( "txt_Info_Tab2" ));

      //Tab3
      m_btn_Tab3					  =	ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_Tab3" ));
      m_Panel_Tab3          =	Widget.Cast( layoutRoot.FindAnyWidget( "Panel_Tab3" ));
      m_txt_Tab3					  =	TextWidget.Cast( layoutRoot.FindAnyWidget( "txt_Tab3" ));
      m_Tab3List 						=	TextListboxWidget.Cast( layoutRoot.FindAnyWidget( "lstbox_Tab3" ));
      // m_txt_Info_Tab3       =	RichTextWidget.Cast( layoutRoot.FindAnyWidget( "txt_Info_Tab3" ));

      //Tab4
      m_btn_Tab4					  =	ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_Tab4" ));
      m_Panel_Tab4          =	Widget.Cast( layoutRoot.FindAnyWidget( "Panel_Tab4" ));
      m_txt_Tab4					  =	TextWidget.Cast( layoutRoot.FindAnyWidget( "txt_Tab4" ));
      m_Tab4List 						=	TextListboxWidget.Cast( layoutRoot.FindAnyWidget( "lstbox_Tab4" ));
      // m_txt_Info_Tab4       =	RichTextWidget.Cast( layoutRoot.FindAnyWidget( "txt_Info_Tab4" ));

      // layoutRoot.Show(false);
      m_Initialized = true;
    }
      return layoutRoot;
  }

  //Called on each frame, this will be paused when the menu is hidden or missiongameplay callqueue is frozen / paused
    override void Update(float timeslice)
    {
        super.Update(timeslice);

    }

	void UIHandle()
  {
    PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

    m_Link1 = GetDiPConfigClient().DiscordLink;
    m_Link2 = GetDiPConfigClient().DonateLink;
    m_IPServerName.SetText(GetDiPConfigClient().ServerName);

    m_Panel_Tab1.Show(true);
    m_Panel_Tab2.Show(false);
    m_Panel_Tab3.Show(false);
    m_Panel_Tab4.Show(false);

    string tab_1_info = "";
    m_txt_Tab1.SetText(GetDiPConfigClient().Tab1_Header);
    m_Tab1List.ClearItems();
    for (int i = 0; i < GetDiPConfigClient().Tab1_Info.Count(); i++)
		m_Tab1List.AddItem(" " + GetDiPConfigClient().Tab1_Info[i], NULL, 0);
    // for(int k=0;k<GetDiPConfigClient().Tab1_Info.Count();k++)
    // {
    //   tab_1_info += GetDiPConfigClient().Tab1_Info[k] + "<br/>";
    // }
    // m_txt_Info_Tab1.SetText(tab_1_info);

    string tab_2_info = "";
    m_txt_Tab2.SetText(GetDiPConfigClient().Tab2_Header);
    m_Tab2List.ClearItems();
		for (int j = 0; j < GetDiPConfigClient().Tab2_Info.Count(); j++)
		m_Tab2List.AddItem(" " + GetDiPConfigClient().Tab2_Info[j], NULL, 0);
    // for(int j=0;j<GetDiPConfigClient().Tab2_Info.Count();j++)
    // {
    //   tab_2_info += GetDiPConfigClient().Tab2_Info[j] + "<br/>";
    // }
    // m_txt_Info_Tab2.SetText(tab_2_info);

    string tab_3_info = "";
    m_txt_Tab3.SetText(GetDiPConfigClient().Tab3_Header);
    m_Tab3List.ClearItems();
		for (int k = 0; k < GetDiPConfigClient().Tab3_Info.Count(); k++)
		m_Tab3List.AddItem(" " + GetDiPConfigClient().Tab3_Info[k], NULL, 0);
    // for(int n=0;n<GetDiPConfigClient().Tab3_Info.Count();n++)
    // {
    //   tab_3_info += GetDiPConfigClient().Tab3_Info[n] + "<br/>";
    // }
    // m_txt_Info_Tab3.SetText(tab_3_info);

    string tab_4_info = "";
    m_txt_Tab4.SetText(GetDiPConfigClient().Tab4_Header);
    m_Tab4List.ClearItems();
		for (int l = 0; l < GetDiPConfigClient().Tab4_Info.Count(); l++)
		m_Tab4List.AddItem(" " + GetDiPConfigClient().Tab4_Info[l], NULL, 0);
    // for(int q=0;q<GetDiPConfigClient().Tab4_Info.Count();q++)
    // {
    //   tab_4_info += GetDiPConfigClient().Tab4_Info[q] + "<br/>";
    // }
    // m_txt_Info_Tab4.SetText(tab_4_info);



    GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(IPServerTime, 1000, true);
		m_InfoPanelIsVisible = true;
  }

  bool IsMenuOpen()
  {
      return m_IsMenuOpen;
  }

  void SetMenuOpen(bool isMenuOpen)
  {
      m_IsMenuOpen = isMenuOpen;
      if (m_IsMenuOpen)
          PPEffects.SetBlurMenu( 0.5 );
      else
          PPEffects.SetBlurMenu( 0 );
  }




  override bool OnClick( Widget w, int x, int y, int button )	{
		super.OnClick(w, x, y, button);

		switch (w)	{

		case m_btn_Discord:
			return OnDiscordBtnClick();

		case m_btn_Donate:
			return OnDonateBtnClick();

    case m_btn_Tab1:
  		return OnTab1BtnClick();

    case m_btn_Tab2:
  	 return OnTab2BtnClick();

  	case m_btn_Tab3:
  		return OnTab3BtnClick();

    case m_btn_Tab4:
    	return OnTab4BtnClick();

		default:
			break;
		}
		return true;
	}

  protected bool OnDiscordBtnClick()	{
    GetGame().OpenURL(m_Link1);
    return true;
  }

	protected bool OnDonateBtnClick()	{
		GetGame().OpenURL(m_Link2);
		return true;
	}

  protected bool OnTab1BtnClick()
  {
    m_Panel_Tab1.Show(true);
    m_Panel_Tab2.Show(false);
    m_Panel_Tab3.Show(false);
    m_Panel_Tab4.Show(false);
		return true;
	}

  protected bool OnTab2BtnClick()
  {
    m_Panel_Tab1.Show(false);
    m_Panel_Tab2.Show(true);
    m_Panel_Tab3.Show(false);
    m_Panel_Tab4.Show(false);
		return true;
	}

  protected bool OnTab3BtnClick()
  {
    m_Panel_Tab1.Show(false);
    m_Panel_Tab2.Show(false);
    m_Panel_Tab3.Show(true);
    m_Panel_Tab4.Show(false);
		return true;
	}

  protected bool OnTab4BtnClick()
  {
    m_Panel_Tab1.Show(false);
    m_Panel_Tab2.Show(false);
    m_Panel_Tab3.Show(false);
    m_Panel_Tab4.Show(true);
		return true;
	}

  private void IPServerTime()
  {
		int m_year, m_month, m_day, m_hour, m_minute;
		GetGame().GetWorld().GetDate(m_year, m_month, m_day, m_hour, m_minute);
		string serverTime = "" + m_hour + ":" + m_minute;
		m_IPServerTime.SetText(serverTime);
	}
};
