# ChistiyOpenWM
Библиотека для получения текущих погодных данных с сервиса OpenWeatherMap по ID города и парсить JSON ответ.  


![Пример вывода](https://github.com/ChistiyAlexay/ChistiyOpenWM/blob/main/ChistiyOpenWM/Images/Img.jpg?raw=true)  


API ключ берётся с сайта openweathermap. Можно самому, можно по видео с интернета. ID города так-же берётся с openweather map.  


Инициализация библиотеки:  
const String apiKey = "API ключ";  
const String cityID = "480060";  
  
ChistiyOpenWM weather(apiKey, cityID);  

Запрос погоды происходит так:  
if (weather.updateData()) {  
    Serial.println(weather.getTemperature());  
}  

Подробнее в примере библиотеки
