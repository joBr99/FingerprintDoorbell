#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <Preferences.h>
#include "global.h"

struct WifiSettings
{
  String ssid = "";
  String password = "";
  String hostname = "";
};

struct KNXSettings
{
  String door1_ga = "1/3/90";
  String door2_ga = "1/3/90";
  String doorbell_ga = "1/3/90";
  String message_ga = "1/3/90";
  String led_ga = "";
  String touch_ga = "";
  String door1_list = "";
  String door2_list = "";

  String knx_pa = "1.1.1";
};

struct AppSettings
{
  uint16_t tpScans = 5;
  String mqttServer = "";
  String mqttUsername = "";
  String mqttPassword = "";
  uint16_t mqttPort = 11883;
  String mqttRootTopic = "fingerprintDoorbell";
  String ntpServer = "pool.ntp.org";
  String sensorPin = "00000000";
  String sensorPairingCode = "";
  bool sensorPairingValid = false;
};

class SettingsManager
{
private:
  WifiSettings wifiSettings;
  AppSettings appSettings;

  void saveWifiSettings();
  void saveAppSettings();

public:
  bool loadWifiSettings();
  bool loadAppSettings();

  WifiSettings getWifiSettings();
  void saveWifiSettings(WifiSettings newSettings);

  AppSettings getAppSettings();
  void saveAppSettings(AppSettings newSettings);

  bool isWifiConfigured();

  bool deleteAppSettings();
  bool deleteWifiSettings();

  String generateNewPairingCode();
};

#endif