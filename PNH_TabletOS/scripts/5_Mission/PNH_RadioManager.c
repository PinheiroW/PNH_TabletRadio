#ifndef SERVER
// Este arquivo só existe para o Cliente (Jogador)
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

        string targetSoundSet = stations.Get(index).m_SoundName + "_SoundSet";

        if (m_CurrentStationIndex == index && m_SoundPlaying) return;

        Stop();

        // SEffectManager.PlaySoundSet é o padrão profissional para som 3D
        m_SoundPlaying = SEffectManager.PlaySoundSet(m_SoundPlaying, targetSoundSet, 0, 0);
        
        if (m_SoundPlaying) {
            m_SoundPlaying.SetSoundLoop(stations.Get(index).m_IsLoop);
            m_SoundPlaying.SetSoundAutodestroy(true);
            m_CurrentStationIndex = index;
            Print("[PNH_Radio] Som iniciado: " + targetSoundSet);
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
// Skeleton para o Servidor não dar erro de compilação em outros scripts
class PNH_RadioManager {
    static ref PNH_RadioManager m_Instance;
    static PNH_RadioManager GetInstance() { return null; }
    void PlayStation(int index) {}
    void Stop() {}
}
#endif