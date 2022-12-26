#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <Preferences.h>
#include "global.h"

struct WifiSettings {    
    String ssid = "";
    String password = "";
    String hostname = "";
};

struct KNXSettings {    
    String door1_ga = "";
    String door2_ga = "";
    String led_ga = "";
    String touch_ga = "";

    String knx_pa = "";    
};

struct AppSettings {
    uint16_t tpScans = 5;
    String mqttServer = "";
    String mqttUsername = "";
    String mqttPassword = "";
    uint16_t mqttPort = 11883;
    String mqttRootTopic = "fingerprintDoorbell";
    String ntpServer = "pool.ntp.org";    
    String sensorPin = "00000000";
    String sensorPairingCode = "";
    bool   sensorPairingValid = false;
};

class SettingsManager {       
  private:
    WifiSettings wifiSettings;
    AppSettings appSettings;
    KNXSettings knxSettings;

    void saveWifiSettings();
    void saveAppSettings();
    void saveKNXSettings();

  public:
    bool loadWifiSettings();
    bool loadAppSettings();
    bool loadKNXSettings();

    WifiSettings getWifiSettings();
    void saveWifiSettings(WifiSettings newSettings);
    
    AppSettings getAppSettings();
    void saveAppSettings(AppSettings newSettings);

    KNXSettings getKNXSettings();
    void saveKNXSettings(KNXSettings newSettings);

    bool isWifiConfigured();
    bool isKNXConfigured();

    bool deleteAppSettings();
    bool deleteWifiSettings();
    bool deleteKNXSettings();

    String generateNewPairingCode();

};

#endif