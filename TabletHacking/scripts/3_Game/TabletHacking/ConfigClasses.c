class TabletHackingConfig
{ 
	private static string PROFILE = "$profile:Paragon_Storage";
	private static string CONFIG = PROFILE + "/TabletHacking.json";
	//Default Values
	string ConfigVersion = "1";
	// 0 - Native Notification
	// 1 - Chat Notification
	// 2 - BuiltIn Notification
	int Notification = 2; 
	ref array<ref HackableItem> HackableItems = new array<ref HackableItem>;
	bool ScriptLogging = false;
		
	
	// Load config file or create default file if config doesn't exsit
	void Load(){
		if (GetGame().IsServer()){

			if ( !FileExist(PROFILE) )
				MakeDirectory(PROFILE);


			if (FileExist(CONFIG)){ //If config exist load File
				JsonFileLoader<TabletHackingConfig>.JsonLoadFile(CONFIG, this);
			}else{ //File does not exist create file
				HackableItems.Insert( new HackableItem("tent", 30, 120, 1));
				HackableItems.Insert( new HackableItem("Paragon_BigSafe_Black", 30, 240, 5));
				HackableItems.Insert( new HackableItem("Paragon_BigSafe_Grey", 30, 240, 5));
				HackableItems.Insert( new HackableItem("Paragon_BigSafe_Rainbow", 30, 240, 5));
				HackableItems.Insert( new HackableItem("Paragon_Safe_Black", 30, 180, 3));
				HackableItems.Insert( new HackableItem("Paragon_Safe_Grey", 30, 180, 3));
				HackableItems.Insert( new HackableItem("Paragon_Safe_White", 30, 180, 3));
				HackableItems.Insert( new HackableItem("Paragon_Safe_Green", 30, 180, 3));
				HackableItems.Insert( new HackableItem("Paragon_Safe_Blue", 30, 180, 3));
				HackableItems.Insert( new HackableItem("Paragon_Safe_Gold", 30, 180, 3));
				HackableItems.Insert( new HackableItem("Paragon_Safe_Rainbow", 30, 180, 3));
				HackableItems.Insert( new HackableItem("Paragon_SmallSafe_Black", 30, 120, 2));
				HackableItems.Insert( new HackableItem("Paragon_SmallSafe_Grey", 30, 120, 2));
				HackableItems.Insert( new HackableItem("Paragon_SmallSafe_White", 30, 120, 2));
				HackableItems.Insert( new HackableItem("Paragon_SmallSafe_Green", 30, 120, 2));
				HackableItems.Insert( new HackableItem("Paragon_SmallSafe_Blue", 30, 120, 2));
				HackableItems.Insert( new HackableItem("Paragon_SmallSafe_Gold", 30, 120, 2));
				HackableItems.Insert( new HackableItem("Paragon_SmallSafe_Rainbow", 30, 120, 2));
				HackableItems.Insert( new HackableItem("Paragon_Rdoor_Black", 30, 180, 3));
				HackableItems.Insert( new HackableItem("Paragon_Rdoor_Green", 30, 180, 3));
				HackableItems.Insert( new HackableItem("Paragon_Adoor_Black", 30, 240, 5));
				HackableItems.Insert( new HackableItem("Paragon_Adoor_Green", 30, 240, 5));
				HackableItems.Insert( new HackableItem("Paragon_Adoor_Blue", 30, 240, 5));
				HackableItems.Insert( new HackableItem("Paragon_Adoor_Gold", 30, 240, 5));
				HackableItems.Insert( new HackableItem("Paragon_Adoor_Rainbow", 30, 240, 5));
				HackableItems.Insert( new HackableItem("Paragon_DGunCase_Brown", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_DGunCase_Grey", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_DGunCase_Cherry", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_GunCase_Brown", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_GunCase_Grey", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_GunCase_Cherry", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_GearStandC_B", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_GearStandC_G", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_GearStandC_C", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_MiliCrate_Black", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_MiliCrate_Grey", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_MiliCrate_Tan", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_MiliCrate_Green", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_MiliCrate_Blue", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Mlocker_Black", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Mlocker_Grey", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Mlocker_Green", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Mlocker_Tan", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Mlocker_Blue", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Locker_Black", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Locker_Blue", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Locker_Green", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Locker_Purple", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Locker_Red", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Locker_White", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Locker_Yellow", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Container_Black", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Container_Grey", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Container_Tan", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Container_Green", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Container_Blue", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Container_Red", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_BigTent_Black", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_BigTent_White", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_BigTent_Green", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Bdoor", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Wlocker_Black", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Wlocker_Grey", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Wlocker_Green", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Wlocker_Tan", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Wlocker_Blue", 25, 100, 1));
				HackableItems.Insert( new HackableItem("Paragon_Compound_Gate", 25, 100, 1));
				
				Save();
			}
		} else {
			Print("[TabletHacking] Trying to load settings before they were received by the server.");
		}
	}
	
	void Save(){
		JsonFileLoader<TabletHackingConfig>.JsonSaveFile(CONFIG, this);
	}
	
	bool CanHack(string ItemType, int Batteries){
		HackableItem target = GetHackableItem( ItemType );
		if ( target.Type != ""){
			if (Batteries >= target.Batteries){
				return true;
			}
		}
		return false;
	}
	
	float GetStartTime(string ItemType){
		return GetHackableItem(ItemType).StartTime;
	}
	
	
	float GetHackTime(string ItemType){
		return GetHackableItem(ItemType).HackingTime;
	}
	
	HackableItem GetHackableItem( string ItemType){
		string itemType = ItemType;
		itemType.ToLower();		
		for (int i = 0; i < HackableItems.Count(); i++){
			string toFind = HackableItems.Get(i).Type;
			toFind.ToLower();
			if (itemType.Contains(toFind)){
				return HackableItems.Get(i);
			}
		}
		return new HackableItem();
	}
	
	bool NewSetup(){
		return false;
	}
	
	void SetupComplete(){
		//Save();
	}
};



class HackableItem {
	string Type = "";
	float StartTime = 30;
	float HackingTime = 120;
	int Batteries = 3;
	float TabletDamage = 15;
	float ChanceOfInterrupt = 0.0;
	
	void HackableItem( string type = "", float start = 60, float time = 600, int bat = 1)
	{
		Type = type;
		StartTime = start;
		HackingTime = time;
		Batteries = bat;
	}
};

ref TabletHackingConfig m_TabletHackingConfig;

//Helper function to return Config
static TabletHackingConfig GetTabletHackingConfig()
{
	if (!m_TabletHackingConfig)
	{
		Print("[TabletHacking] Init");
		m_TabletHackingConfig = new TabletHackingConfig;
		m_TabletHackingConfig.Load();
	}
	return m_TabletHackingConfig;
};

