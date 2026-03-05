/**
 * MOD: PNH_TabletRadio
 * FILE: PNH_TabletRadio_Item.c
 */

class PNH_TabletRadio_ColorBase : Clothing
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
            SetObjectTexture(0, "PNH_TabletRadio/data/textures/Screen_Upit ready.paa");
            SetObjectTexture(1, "PNH_TabletRadio/data/textures/Screen_Upit ready.paa");
        }
    }

    override void OnWorkStop()
    {
        super.OnWorkStop();
        if (GetGame().IsServer() || !GetGame().IsMultiplayer())
        {
            SetObjectTexture(0, "PNH_TabletRadio/data/textures/lcd_co.paa");
            SetObjectTexture(1, "PNH_TabletRadio/data/textures/lcd_co.paa");
        }
    }
}

class PNH_TabletRadio_Black : PNH_TabletRadio_ColorBase {};