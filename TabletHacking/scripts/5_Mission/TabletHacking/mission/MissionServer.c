modded class MissionServer extends MissionBase
{
	override void OnInit()
	{
		super.OnInit();
		Print("[TabletHacking] OnInit");
		GetTabletHackingConfig();
		GetRPCManager().AddRPC( "HACK", "RPCTabletHackingSettings", this, SingeplayerExecutionType.Both );
	}
	
	
	void RPCTabletHackingSettings( CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target )
	{
		PlayerIdentity RequestedBy = PlayerIdentity.Cast(sender);
		if (RequestedBy){
			GetRPCManager().SendRPC("HACK", "RPCTabletHackingSettings", new Param1< TabletHackingConfig >( GetTabletHackingConfig() ), true, RequestedBy);
		}
	}
	
}


