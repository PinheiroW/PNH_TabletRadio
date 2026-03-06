#ifndef SERVER
class PNH_RadioManager
{
    private static ref PNH_RadioManager m_Instance;
    protected EffectSound m_SoundPlaying; 
    private int m_CurrentStationIndex = -1;

    static PNH_RadioManager GetInstance()
    {
        if (!m_Instance) m_Instance = new PNH_RadioManager;
        return m_Instance;
    }

    void PlayStation(int index)
    {
        array<ref PNH_RadioStation> stations = PNH_Radio_Database.GetStations();
        if (index < 0 || index >= stations.Count()) return;

        // Se o jogador clicar na mesma rádio que já está tocando, o som desliga.
        if (m_CurrentStationIndex == index && m_SoundPlaying) {
            Stop();
            Print("[PNH_Radio] Rádio parada pelo clique duplo.");
            return;
        }

        string targetSoundSet = stations.Get(index).m_SoundName + "_SoundSet";
        Stop();

        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        
        if (player) {
            m_SoundPlaying = SEffectManager.PlaySoundOnObject(targetSoundSet, player);
            if (m_SoundPlaying) {
                m_SoundPlaying.SetSoundLoop(stations.Get(index).m_IsLoop);
                m_SoundPlaying.SetSoundAutodestroy(true);
                m_CurrentStationIndex = index;
            }
        }
    }

    void Stop()
    {
        if (m_SoundPlaying) {
            m_SoundPlaying.SoundStop();
            m_SoundPlaying = null;
        }
        m_CurrentStationIndex = -1;
    }
}
#else
class PNH_RadioManager {
    static ref PNH_RadioManager m_Instance;
    static PNH_RadioManager GetInstance() { return null; }
    void PlayStation(int index) {}
    void Stop() {}
}
#endif