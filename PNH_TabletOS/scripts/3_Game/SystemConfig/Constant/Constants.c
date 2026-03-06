// Agora o mod vai criar a pasta "PNH_TabletOS" dentro da pasta profiles do servidor
const string DIP_CONFIG_ROOT_SERVER = "$profile:PNH_TabletOS\\";
const string DIP_LOGGER_DIR_SERVER = DIP_CONFIG_ROOT_SERVER + "Logs\\";

// Os logs de erro vão ter o seu prefixo
const string DIP_LOGGER_PREFIX_SERVER = "PNH_Tablet_";
const string DIP_CONFIG_DIR_SERVER = DIP_CONFIG_ROOT_SERVER + "Config\\";

// O ficheiro JSON vai chamar-se TabletConfig.json
const string DIP_CONFIG = DIP_CONFIG_DIR_SERVER + "TabletConfig.json";
const string DIP_CONFIG_CLIENT = DIP_CONFIG_DIR_SERVER + "DoNotEdit.json";

static const int DIP_PANEL  =   69420;