# ChistiyOpenWM
Библиотека для получения текущих погодных данных с сервиса OpenWeatherMap по ID города и парсить JSON ответ.  
<br>
<br>
<br>

<div style="border: 2px solid #333; padding: 10px; display: inline-block;">

![Пример вывода](https://github.com/ChistiyAlexay/ChistiyOpenWM/blob/main/ChistiyOpenWM/Images/Img.jpg?raw=true)  
<br>
Вывод в консоль из примера

</div>  

<br>
<br>
<br>

API ключ берётся с сайта openweathermap. Можно самому, можно по видео с интернета. ID города так-же берётся с openweather map.  

  
  
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

Подробнее в примере библиотеки
