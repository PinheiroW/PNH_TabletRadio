// Classe que define o que é uma Estação de Rádio
class PNH_RadioStation
{
    string m_DisplayName; // O nome que aparece no Tablet
    string m_SoundName;   // O nome da classe no config.cpp (CfgSounds)
    bool   m_IsLoop;      // Se a música deve recomeçar sozinha

    void PNH_RadioStation(string name, string sound, bool loop = true)
    {
        m_DisplayName = name;
        m_SoundName = sound;
        m_IsLoop = loop;
    }
}

// Gerenciador de Dados do Rádio (3_Game - Acessível por todas as camadas)
class PNH_Radio_Database
{
    static ref array<ref PNH_RadioStation> m_Stations;

    // Esta função prepara a lista de rádios
    static void Init()
    {
        if (!m_Stations)
        {
            m_Stations = new array<ref PNH_RadioStation>;

            // --- CADASTRO DAS SUAS ESTAÇÕES ---
            // O segundo parâmetro deve ser IGUAL ao nome que colocamos no config.cpp
            m_Stations.Insert(new PNH_RadioStation("Zombie Broadcast", "PNH_Radio_Zombie"));
            m_Stations.Insert(new PNH_RadioStation("Jax Radio Station", "PNH_Radio_Jax"));
            m_Stations.Insert(new PNH_RadioStation("Ezra Survivor Mix", "PNH_Radio_Ezra"));
            
            Print("[PNH_Radio] Database: " + m_Stations.Count() + " estações carregadas com sucesso.");
        }
    }

    static array<ref PNH_RadioStation> GetStations()
    {
        if (!m_Stations) Init();
        return m_Stations;
    }
}