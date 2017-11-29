import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "qml/Weather"
import WeatherInfo 1.0

import "qml/BezierClock/NonKDE"

ApplicationWindow {
    visible: true
    width: 1024
    height: 600
    title: qsTr("PiSmartCenter")

    AppModel {
        id: model
    }

    Rectangle {
        id: mainView
        anchors.fill: parent

       /* Image {
            anchors.fill: parent
            source: "images/background.png"
        }*/

        Rectangle {
            anchors.fill: parent
            color: "black"
        }

       Weather {
            id: weather
            anchors.fill: parent

            temperature: model.weather.temperature
            airpressure: model.weather.airpressure
            humidity: model.weather.humidity
            rain: model.weather.rain
            weather_tpye: model.weather.info
            feelst: model.weather.feelst
            weather_image: model.weather.image
            wind_direct: model.weather.direct
            wind_speed: model.weather.speed
            wind_power: model.weather.power
            city: model.weather.city
            province: model.weather.province
            publishTime: model.weather.publishTime
            aqi: model.weather.aqi
            aqiText: model.weather.text

            alert: model.weather.alert
            issuecontent: model.weather.issuecontent

            //prediction
            prediction_date: model.weather.predictionDate
            prediction_day_info: model.weather.dayInfo
            prediction_day_img: model.weather.dayImg
            prediction_day_temperature: model.weather.dayTemperature
            prediction_day_direct: model.weather.dayDirect
            prediction_day_power: model.weather.dayPower
            prediction_night_info: model.weather.nigthInfo
            prediction_night_img: model.weather.nigthImg
            prediction_night_temperature: model.weather.nigthTemperature
            prediction_night_direct: model.weather.nigthDirecct
            prediction_night_power: model.weather.nigthPower
        }

        BezierClockMain{
            id: clock
            anchors.top: mainView.top
            anchors.topMargin: 10
            anchors.right: mainView.right

            width: 750
            height: 160
        }
    }

}
