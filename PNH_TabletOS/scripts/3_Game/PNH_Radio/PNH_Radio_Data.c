class PNH_RadioStation {
    string m_DisplayName, m_SoundName;
    bool m_IsLoop;
    void PNH_RadioStation(string name, string sound, bool loop = true) {
        m_DisplayName = name; m_SoundName = sound; m_IsLoop = loop;
    }
}

class PNH_Radio_Database {
    static ref array<ref PNH_RadioStation> m_Stations;
    static void Init() {
        if (!m_Stations) {
            m_Stations = new array<ref PNH_RadioStation>;
            m_Stations.Insert(new PNH_RadioStation("Zombie Broadcast", "PNH_Radio_Zombie"));
            m_Stations.Insert(new PNH_RadioStation("Jax Radio Station", "PNH_Radio_Jax"));
            m_Stations.Insert(new PNH_RadioStation("Ezra Survivor Mix", "PNH_Radio_Ezra"));
        }
    }
    static array<ref PNH_RadioStation> GetStations() {
        if (!m_Stations) Init();
        return m_Stations;
    }
}