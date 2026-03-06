class PNH_RadioManager
{
    private static ref PNH_RadioManager m_Instance;
    protected EffectSound m_SoundPlaying; // Referência persistente como no original
    private int m_CurrentStationIndex = -1;
    private string m_CurrentSoundSet = "";

    static PNH_RadioManager GetInstance()
    {
        if (!m_Instance) m_Instance = new PNH_RadioManager;
        return m_Instance;
    }

    void PlayStation(int index)
    {
        array<ref PNH_RadioStation> stations = PNH_Radio_Database.GetStations();
        if (index < 0 || index >= stations.Count()) return;

        string targetSoundSet = stations.Get(index).m_SoundName + "_SoundSet";

        // Se já está tocando esta rádio, não faz nada
        if (m_CurrentStationIndex == index && m_SoundPlaying) return;

        Stop();

        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (!player) return;

        // O SEffectManager.PlaySoundSet toca o som vinculado ao jogador (3D)
        // Isso imita o comportamento do rádio original preso ao item
        m_SoundPlaying = SEffectManager.PlaySoundSet(m_SoundPlaying, targetSoundSet, 0, 0);
        
        if (m_SoundPlaying) {
            m_SoundPlaying.SetSoundLoop(stations.Get(index).m_IsLoop);
            m_SoundPlaying.SetSoundAutodestroy(true);
            m_CurrentStationIndex = index;
            m_CurrentSoundSet = targetSoundSet;
            Print("[PNH_Radio] Sucesso: Iniciando SoundSet " + targetSoundSet);
        }
    }

    void Stop()
    {
        if (m_SoundPlaying) {
            m_SoundPlaying.SoundStop();
            m_SoundPlaying = null;
        }
        m_CurrentStationIndex = -1;
        m_CurrentSoundSet = "";
    }
}