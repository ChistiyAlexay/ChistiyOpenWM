#include "ChistiyOpenWM.h"
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>

ChistiyOpenWM::ChistiyOpenWM()
    : _apiKey(""), _cityID("") {
    clearData();
}

ChistiyOpenWM::ChistiyOpenWM(const String& apiKey, const String& cityID)
    : _apiKey(apiKey), _cityID(cityID) {
    clearData();
}

void ChistiyOpenWM::begin(const String& apiKey, const String& cityID) {
    _apiKey = apiKey;
    _cityID = cityID;
    clearData();
}

bool ChistiyOpenWM::updateData() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi not connected");
        return false;
    }

    if (_apiKey.length() == 0 || _cityID.length() == 0) {
        Serial.println("API key or City ID not set");
        return false;
    }

    HTTPClient http;
    String url = "http://api.openweathermap.org/data/2.5/weather?id=" + _cityID + "&appid=" + _apiKey + "&units=metric&lang=en";
    WiFiClient client;
    http.begin(client, url);

    int httpCode = http.GET();

    if (httpCode != HTTP_CODE_OK) {
        Serial.printf("HTTP GET failed, code: %d\n", httpCode);
        http.end();
        return false;
    }

    String payload = http.getString();
    http.end();

    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, payload);

    if (error) {
        Serial.print("JSON parse error: ");
        Serial.println(error.c_str());
        return false;
    }

    // Парсим данные
    location = doc["name"].as<String>();
    country = doc["sys"]["country"].as<String>();
    temperature = doc["main"]["temp"].as<float>();
    humidity = doc["main"]["humidity"].as<float>();
    pressure = doc["main"]["pressure"].as<float>();
    weatherDescription = doc["weather"][0]["description"].as<String>();
    windSpeed = doc["wind"]["speed"].as<float>();

    return true;
}

void ChistiyOpenWM::clearData() {
    location = "";
    country = "";
    temperature = 0.0;
    humidity = 0.0;
    pressure = 0.0;
    weatherDescription = "";
    windSpeed = 0.0;
}

String ChistiyOpenWM::getLocation() const {
    return location;
}

String ChistiyOpenWM::getCountry() const {
    return country;
}

float ChistiyOpenWM::getTemperature() const {
    return temperature;
}

float ChistiyOpenWM::getHumidity() const {
    return humidity;
}

float ChistiyOpenWM::getPressure() const {
    return pressure  * 0.75;
}

String ChistiyOpenWM::getWeatherDescription() const {
    return weatherDescription;
}

float ChistiyOpenWM::getWindSpeed() const {
    return windSpeed;
}
