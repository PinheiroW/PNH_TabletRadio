class PNH_Tablet_ColorBase : Clothing
{
    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionTurnOnWhileInHands);
        AddAction(ActionTurnOffWhileInHands);
    }

    override void OnWorkStart()
    {
        super.OnWorkStart();
        if (GetGame().IsServer() || !GetGame().IsMultiplayer())
        {
            SetObjectTexture(0, "PNH_Tablet/GPS_Tablet/data/textures/Screen_Upit ready.paa");
            SetObjectTexture(1, "PNH_Tablet/GPS_Tablet/data/textures/Screen_Upit ready.paa");
        }
    }

    override void OnWorkStop()
    {
        super.OnWorkStop();
        if (GetGame().IsServer() || !GetGame().IsMultiplayer())
        {
            SetObjectTexture(0, "PNH_Tablet/GPS_Tablet/data/textures/lcd_co.paa");
            SetObjectTexture(1, "PNH_Tablet/GPS_Tablet/data/textures/lcd_co.paa");
        }
    }
}
class PNH_Tablet_Black : PNH_Tablet_ColorBase {};