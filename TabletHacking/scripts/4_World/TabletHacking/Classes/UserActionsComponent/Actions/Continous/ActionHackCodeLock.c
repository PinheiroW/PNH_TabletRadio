class ActionHackCodeLockCB extends ActionContinuousBaseCB {
    override void CreateActionComponent() {
		float circleTime = 60; 
		if (m_ActionData)
		{		
			if (m_ActionData.m_Target){
				ItemBase hacking_target;
				if (Class.CastTo(hacking_target, m_ActionData.m_Target.GetObject()) || Class.CastTo(hacking_target, m_ActionData.m_Target.GetParent()) ){
					circleTime = GetTabletHackingConfig().GetStartTime(hacking_target.GetType());
				}
			}
		}
      	m_ActionData.m_ActionComponent = new CAContinuousRepeat(circleTime);
    }
};

class ActionHackCodeLock : ActionContinuousBase {

	bool continueHack = false;
    void ActionHackCodeLock() {
        m_CallbackClass = ActionHackCodeLockCB;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
        m_FullBody = true;
    }

    override void CreateConditionComponents() {
        m_ConditionItem = new CCINonRuined();
        m_ConditionTarget = new CCTNone();
    }

    override string GetText() {
		if (continueHack){
			return "Resume Hacking";
		}
        return "Hack Codelock";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		HackingTablet tablet = HackingTablet.Cast(item);
		if (!tablet){
			return false;
		}

   		ItemBase hacking_target;
		if (!Class.CastTo(hacking_target, target.GetObject()) && !Class.CastTo(hacking_target, target.GetParent()) ){
			return false;
		}

		#ifdef CodeLock
		CodeLock codelock = CodeLock.Cast(hacking_target.GetAttachmentByConfigTypeName("CodeLock"));
		if (!codelock || !codelock.GetLockState()){
			return false;
		}

		if (tablet.WasHackingInterrupted() && tablet.GetHackID() != 0 && tablet.GetHackID() == hacking_target.GetHackID()) {
			continueHack = true;
			if ( GetTabletHackingConfig().CanHack( hacking_target.GetType(), tablet.CountBatteries()) ) {
				return true;
			}
		} else if (!tablet.HasHackingStarted() || tablet.WasHackingInterrupted()) {
			continueHack = false;
			if ( GetTabletHackingConfig().CanHack( hacking_target.GetType(), tablet.CountBatteries()) ) {
				return true;
			}
		}
		#endif

		#ifdef RA_BASEBUILDING
		if (!hacking_target.IsCodeLocked()) {
			return false;
		}

		if (tablet.WasHackingInterrupted() && tablet.GetHackID() != 0 && tablet.GetHackID() == hacking_target.GetHackID()) {
			continueHack = true;
			if ( GetTabletHackingConfig().CanHack( hacking_target.GetType(), tablet.CountBatteries()) ) {
				return true;
			}
		} else if (!tablet.HasHackingStarted() || tablet.WasHackingInterrupted()) {
			continueHack = false;
			if ( GetTabletHackingConfig().CanHack( hacking_target.GetType(), tablet.CountBatteries()) ) {
				return true;
			}
		}
		#endif

        return false;
    }

    override void OnFinishProgressServer(ActionData action_data) {

   		ItemBase hacking_target;
		if (!Class.CastTo(hacking_target, action_data.m_Target.GetObject()) && !Class.CastTo(hacking_target, action_data.m_Target.GetParent()) ){
			return;
		}

		HackingTablet tablet = HackingTablet.Cast(action_data.m_MainItem);
		PlayerBase sourcePlayer = PlayerBase.Cast(action_data.m_Player);
		if (tablet && sourcePlayer && hacking_target) {
			tablet.StartHackServer(hacking_target, sourcePlayer);
		}
    }
	
	override protected void OnFinishProgressClient( ActionData action_data )
	{  
		HackingTablet tablet = HackingTablet.Cast(action_data.m_MainItem);

        if (tablet) {
            tablet.StartHackClient();
        }
	}
};