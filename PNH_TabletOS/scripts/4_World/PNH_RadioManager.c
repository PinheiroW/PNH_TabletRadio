class PNH_RadioManager
{
    private static ref PNH_RadioManager m_Instance;
    private ref AbstractWave m_CurrentSound; // Mantém a referência para o som tocar
    private int m_CurrentStationIndex = -1;

    static PNH_RadioManager GetInstance()
    {
        if (!m_Instance) m_Instance = new PNH_RadioManager;
        return m_Instance;
    }

    void PlayStation(int index)
    {
        if (m_CurrentStationIndex == index && m_CurrentSound) return;

        Stop();

        array<ref PNH_RadioStation> stations = PNH_Radio_Database.GetStations();
        if (index < 0 || index >= stations.Count()) return;

        PNH_RadioStation target = stations.Get(index);
        SoundParams params = new SoundParams(target.m_SoundName);
        SoundObjectBuilder builder = new SoundObjectBuilder(params);
        SoundObject soundObj = builder.BuildSoundObject();
        
        if (soundObj)
        {
            m_CurrentSound = GetGame().GetSoundScene().Play2D(soundObj, builder);
            if (m_CurrentSound)
            {
                m_CurrentSound.SetVolume(0.8);
                m_CurrentSound.Loop(target.m_IsLoop);
                m_CurrentSound.Play();
                m_CurrentStationIndex = index;
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
}