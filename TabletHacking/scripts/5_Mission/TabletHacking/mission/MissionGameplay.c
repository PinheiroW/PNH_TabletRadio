modded class MissionGameplay extends MissionBase
{

	protected ref array<ref TabletHackingNotificationWidget> HackingNotifications = new array<ref TabletHackingNotificationWidget>;
	
	void MissionGameplay(){
		GetRPCManager().AddRPC( "HACK", "RPCTabletHackingSettings", this, SingeplayerExecutionType.Both );
		GetRPCManager().AddRPC( "HACK", "RPCTabletHackingNotifcation", this, SingeplayerExecutionType.Both );
	}
	
	override void OnMissionStart(){
		super.OnMissionStart();
		Print("[TabletHacking][Client] Requesting Settings From Server");
		GetRPCManager().SendRPC("HACK", "RPCTabletHackingSettings", new Param1< TabletHackingConfig >( NULL ), true, NULL);
	}
	
	
	void RPCTabletHackingSettings( CallType type,  ParamsReadContext ctx, PlayerIdentity sender, Object target )
	{
		Param1< TabletHackingConfig > data  //Player ID, Icon
		if ( !ctx.Read( data ) ) return;
		m_TabletHackingConfig = data.param1;
		Print("[TabletHacking][Client] Settings Received");
		//m_TabletHackingConfig.HackableItems.Debug();
	}
	
	void RPCTabletHackingNotifcation( CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target )
	{
		Param3< string, string, float > data  //Player ID, Icon
		if ( !ctx.Read( data ) ) return;
		string Heading = data.param1;
		string Message = data.param2;
		float MessageTime = data.param3;
		if (GetTabletHackingConfig().Notification == 1) {
			GetGame().Chat( Message, "colorAction");
		} else if (GetTabletHackingConfig().Notification == 2) {
			int LastIndex = HackingNotifications.Count() - 1;
			if (HackingNotifications.Count() > 1) {
				HackingNotifications.Get(LastIndex).EarlyProccess();
			}
			int nextIndex = HackingNotifications.Count();
			HackingNotifications.Insert(new TabletHackingNotificationWidget());
			HackingNotifications.Get(nextIndex).Init(Heading, Message, "TabletHacking/GUI/Images/hacking.paa", MessageTime);
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.DeleteNotification, MessageTime * 1500, false);
		}
	}
		
	void DeleteNotification(){
		if ( HackingNotifications.Count() > 0 ){
			HackingNotifications.RemoveOrdered(0);
		}
	}
}