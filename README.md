# ChistiyOpenWM - библиотека для быстрой работы с OpenWeatherMap
Используется для быстрого получения текущих погодных данных с сервиса OpenWeatherMap по ID города.  
<br>

<div style="border: 2px solid #333; padding: 10px; display: inline-block;">

![Пример вывода](https://github.com/ChistiyAlexay/ChistiyOpenWM/blob/main/ChistiyOpenWM/Images/Img.jpg?raw=true)  
<br>
Вывод в консоль из примера

</div>  

<br>

API ключ берётся с сайта openweathermap. Можно самому, можно по видео с интернета. ID города так-же берётся с openweather map.
<br>
Так-же предварительно следует установить ArduinoJson 7.4.1, ESP8266WiFi и ESP8266HTTPClient

  
  
Инициализация библиотеки:  
```cpp
const String apiKey = "API ключ";  
const String cityID = "480060";  
  
ChistiyOpenWM weather(apiKey, cityID);  
```

Запрос погоды происходит так: 
```cpp
if (weather.updateData()) {  
    Serial.println(weather.getTemperature());  
}
```

Подробнее в примере библиотеки:
```cpp
#include <ESP8266WiFi.h> //Библиотека 
#include <ChistiyOpenWM.h> //Импорт библиотеки
const char* ssid = "SSID"; //SSID вашего wifi
const char* password = "PASSWORD"; //пароль от wifi
const String apiKey = "Ваш API ключ с openweathermap";
const String cityID = "480060"; //ID города (Тверь)

ChistiyOpenWM weather(apiKey, cityID); //Инициализация библиотеки (менять только переменные, не эту строчку)

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.print("Connecting to WiFi"); //Подключение к wifi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  if (weather.updateData()) { //Получение данных
    Serial.println("Weather data:");
    Serial.print("Location: ");
    Serial.print(weather.getLocation()); //Город
    Serial.print(", ");
    Serial.println(weather.getCountry()); //Страна

    Serial.print("Temperature: ");
    Serial.print(weather.getTemperature()); //Температура
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(weather.getHumidity()); //Влажность
    Serial.println(" %");

    Serial.print("Pressure: ");
    Serial.print(weather.getPressure()); //Давление
    Serial.println(" mmHg");

    Serial.print("Weather: ");
    Serial.println(weather.getWeatherDescription()); //Текстовое описание погоды

    Serial.print("Wind speed: ");
    Serial.print(weather.getWindSpeed()); //Скорость ветра
    Serial.println(" m/s");
  } else {
    Serial.println("Failed to get weather data");
  }
}

void loop() {
}
