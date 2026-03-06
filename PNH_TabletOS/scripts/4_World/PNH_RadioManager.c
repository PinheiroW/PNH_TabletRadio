class PNH_RadioManager
{
    private static ref PNH_RadioManager m_Instance;
    private AbstractWave m_CurrentSound;
    private int m_CurrentStationIndex = -1;
    private float m_Volume = 0.5; // Volume inicial (50%)

    static PNH_RadioManager GetInstance()
    {
        if (!m_Instance)
            m_Instance = new PNH_RadioManager;
        return m_Instance;
    }

    void PlayStation(int index)
    {
        // Se já estiver a tocar esta rádio, não fazemos nada
        if (m_CurrentStationIndex == index && m_CurrentSound && m_CurrentSound.IsPlaying())
            return;

        Stop(); // Para qualquer som anterior

        array<ref PNH_RadioStation> stations = PNH_Radio_Database.GetStations();
        if (index < 0 || index >= stations.Count()) return;

        PNH_RadioStation target = stations.Get(index);
        
        SoundParams params = new SoundParams(target.m_SoundName);
        SoundObjectBuilder builder = new SoundObjectBuilder(params);
        SoundObject soundObj = builder.BuildSoundObject();
        
        if (soundObj)
        {
            // Criamos o som 2D para o Tablet
            m_CurrentSound = GetGame().GetSoundScene().Play2D(soundObj, builder);
            if (m_CurrentSound)
            {
                m_CurrentSound.SetVolume(m_Volume);
                m_CurrentSound.Loop(target.m_IsLoop);
                m_CurrentSound.Play(); // Garante o início da reprodução
                
                m_CurrentStationIndex = index;
                Print("[PNH_Radio] A tocar agora: " + target.m_DisplayName);
            }
        }
    }

    void Stop()
    {
        if (m_CurrentSound)
        {
            m_CurrentSound.Stop();
            m_CurrentSound = null;
        }
        m_CurrentStationIndex = -1;
    }

    void SetVolume(float vol)
    {
        m_Volume = vol;
        if (m_CurrentSound)
        {
            m_CurrentSound.SetVolume(m_Volume);
        }
    }

    int GetCurrentStationIndex()
    {
        return m_CurrentStationIndex;
    }

    bool IsPlaying()
    {
        return (m_CurrentSound != null && m_CurrentSound.IsPlaying());
    }
}