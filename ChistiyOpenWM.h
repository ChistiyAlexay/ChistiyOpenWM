#ifndef CHISTIYOPENWM_H
#define CHISTIYOPENWM_H

#include <Arduino.h>

class ChistiyOpenWM {
public:
    ChistiyOpenWM();
    ChistiyOpenWM(const String& apiKey, const String& cityID);

    void begin(const String& apiKey, const String& cityID); // можно инициализировать позже
    bool updateData();

    // Геттеры для данных
    String getLocation() const;
    String getCountry() const;
    float getTemperature() const;
    float getHumidity() const;
    float getPressure() const;
    String getWeatherDescription() const;
    float getWindSpeed() const;

private:
    String _apiKey;
    String _cityID;

    String location;
    String country;
    float temperature;
    float humidity;
    float pressure;
    String weatherDescription;
    float windSpeed;

    void clearData();
};

#endif
