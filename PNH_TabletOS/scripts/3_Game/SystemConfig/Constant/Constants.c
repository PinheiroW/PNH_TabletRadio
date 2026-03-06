// Caminhos de Configuração
const string DIP_CONFIG_ROOT_SERVER = "$profile:PNH_TabletOS";
const string DIP_CONFIG_ROOT_SERVER_FILE = "$profile:PNH_TabletOS/TabletConfig.json";

// Caminho de Logs (A variável que faltava)
const string DIP_LOGGER_DIR_SERVER = "$profile:PNH_TabletOS/Logs";
const string DIP_CONFIG_DIR_SERVER = DIP_CONFIG_ROOT_SERVER + "Config\\";

// O ficheiro JSON vai chamar-se TabletConfig.json
const string DIP_CONFIG = DIP_CONFIG_DIR_SERVER + "TabletConfig.json";
const string DIP_CONFIG_CLIENT = DIP_CONFIG_DIR_SERVER + "DoNotEdit.json";

static const int DIP_PANEL  =   69420;