import QtQuick 2.7
import "../Style"

Item {
    id: weather_id

    //real
    property double temperature
    property int airpressure
    property int humidity
    property int rain
    property string weather_tpye
    property double feelst
    property string weather_image
    property string wind_direct
    property double wind_speed
    property string wind_power
    property string publishTime
    property string city
    property string province
    property int aqi
    property string aqiText
    property string alert
    property string issuecontent

    //prediction
    property string prediction_date
    property string prediction_day_info
    property string prediction_day_img
    property string prediction_day_temperature
    property string prediction_day_direct
    property string prediction_day_power
    property string prediction_night_info
    property string prediction_night_img
    property string prediction_night_temperature
    property string prediction_night_direct
    property string prediction_night_power

    function getWeatherImage(image)
    {
        var data;

        switch (image) {
        case "0": //晴
            data = "images/sunny.png"
            break;
        case "1": //多云
            data = "images/cloudy.png"
            break;
        case "2": //阴
            data = "images/overcast.png"
            break;
        case "3": //阵雨
            data = "images/shower.png"
            break;
        case "4": //雷阵雨
            data = "images/heavy_storm.png"
            break;
        case "5": //中雪????
            data = "images/snow_2.png"
            break;
        case "6": //雨夹雪
            data = "images/sleet.png"
            break;
        case "7": //小雨
            data = "images/rain_1.png"
            break;
        case "8": //小到中雨
            data = "images/rain_2.png"
            break;
        case "9": //大雨
            data = "images/rain_3.png"
            break;
        case "10": //大到暴雨
            data = "images/rain_4.png"
            break;
        case "11": //暴雨到特大暴雨
            data = "images/rain_5.png"
            break;
        case "12": //特大暴雨
            data = "images/rain_5.png"
            break;
        case "13": //镇雪
            data = "images/snow_0.png"
            break;
        case "14": //小雪
            data = "images/snow_1.png"
            break;
        case "15": //小到中雪
            data = "images/snow_2.png"
            break;
        case "16": //大雪
            data = "images/snow_3.png"
            break;
        case "17": //大到暴雪
            data = "images/snow_3.png"
            break;
        case "18": //雾
            data = "images/foggy.png"
            break;
        case "19": //中雨??
            data = "images/rain_2.png"
            break;
        case "20": //大风
            data = "images/wind.png"
        case "21": //小到中雨
            data = "images/rain_2.png"
        case "29": //浮尘
            data = "images/dust.png"
            break;
        default:
            data = "images/unknown.png"
        }

        return data;
    }

    Item {
        anchors.fill: parent

        Image {
            id: id_weather_image
            width: 250;
            height: 250
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.left: parent.left

            source: getWeatherImage(weather_image);

            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: city_temperature
            anchors.top: id_weather_image.bottom
            anchors.left: parent.left
            anchors.topMargin: 10

            text: temperature + "℃"
            color: "white"
            font.family: "Helvetica"
            font.pointSize: 80
            font.bold: true
        }

        Text {
            id: city_tpye
            anchors.top: id_weather_image.bottom
            anchors.topMargin: 5
            anchors.left: city_temperature.right

            text: weather_tpye
            color: "white"
            font.family: "Helvetica"
            font.pointSize: 30
        }

        Text {
            id: city_feelst
            anchors.left: city_temperature.right
            anchors.bottom: shadow.top

            text: "/" + feelst + "°"
            color: "white"
            font.family: "Helvetica"
            font.pointSize: 30
        }

        Image {
            id: shadow
            anchors.top: city_temperature.bottom
            source: "images/shadow.png"
            width: 400;
            height: 2
        }

        Text {
            id: city_direct_power_speed
            anchors.top: shadow.bottom
            anchors.topMargin: 5
            anchors.left: parent.left

            text: wind_direct + " " + wind_power + " 风速" + wind_speed + "m/s"
            color: "white"
            font.family: "Helvetica"
            font.pointSize: 30
        }

        Text {
            id: city_humidity_rain
            anchors.top: city_direct_power_speed.bottom
            anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 50

            text: "湿度" + humidity + "%"+ " 降水" + rain + "mm"
            color: "white"
            font.family: "Helvetica"
            font.pointSize: 30
        }

        Text {
            id: city_aqi
            anchors.top: city_humidity_rain.bottom
            anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 100

            text: "空气指数" + aqi
            color: "white"
            font.family: "Helvetica"
            font.pointSize: 30
        }

        Text {
            id: city_aqiText
            anchors.top: city_humidity_rain.bottom
            anchors.topMargin: 5
            anchors.left: city_aqi.right
            anchors.leftMargin: 20

            text: aqiText
            color: {
                if(aqi <= 50)
                    "green"
                else if((51 <= aqi) && (aqi < 100))
                    "yellow"
                else if((101 <= aqi) && (aqi < 150))
                    "orange"
                else if((151 <= aqi) && (aqi < 200))
                    "red"
                else if((201 <= aqi) && (aqi <= 300))
                    "fuchsia"
                else if(300 < aqi)
                    "maroon"
            }
            font.family: "Helvetica"
            font.pointSize: 30
        }

        property string city
        property string province
        Text {
            id: city_publishTime
            anchors.bottom: parent.bottom
            anchors.right: parent.right

            text: publishTime + "发布[ " + province + "-" + city + " ] v1.0.0"
            color: "white"
            font.family: "Helvetica"
            font.pointSize: 10
        }

        //prediction day
        Rectangle {
            id: id_weatherItem_day
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.right: id_weatherItem_night.left
            anchors.rightMargin: 20

            radius: 15
            opacity: 0.5
            width: 170
            height: 340
            color: "blue"

            Text {
                id: id_prediction_day_date
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 10

                text: prediction_date
                color: "white"
                font.family: "Helvetica"
                font.pointSize: 20
                font.bold: true
            }

            Image {
                id: id_prediction_day_image
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: id_prediction_day_date.bottom
                anchors.topMargin: 10

                width: 100;
                height: 100
                source: getWeatherImage(prediction_day_img);
                fillMode: Image.PreserveAspectFit
            }

            Text {
                id: id_prediction_day_type
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: id_prediction_day_image.bottom
                anchors.topMargin: 10

                text: prediction_day_info
                color: "white"
                font.family: "Helvetica"
                font.pointSize: 20
            }

            Text {
                id: id_prediction_day_temperature
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: id_prediction_day_type.bottom
                anchors.topMargin: 10

                text: prediction_day_temperature + "℃"
                color: "white"
                font.family: "Helvetica"
                font.pointSize: 20
            }

            Text {
                id: id_prediction_day_direct
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: id_prediction_day_temperature.bottom
                anchors.topMargin: 10

                text: prediction_day_direct
                color: "white"
                font.family: "Helvetica"
                font.pointSize: 20
            }

            Text {
                id: id_prediction_day_power
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: id_prediction_day_direct.bottom
                anchors.topMargin: 10

                text: prediction_day_power
                color: "white"
                font.family: "Helvetica"
                font.pointSize: 20
            }
        }

        //prediction night
        Rectangle {
            id: id_weatherItem_night
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.right: parent.right
            anchors.rightMargin: 20

            radius: 15
            opacity: 0.5
            width: 170
            height: 340
            color: "green"

            Text {
                id: id_prediction_night_date
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 10

                text: prediction_date
                color: "white"
                font.family: "Helvetica"
                font.pointSize: 20
                font.bold: true
            }

            Image {
                id: id_prediction_night_image
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: id_prediction_night_date.bottom
                anchors.topMargin: 10

                width: 100;
                height: 100
                source: getWeatherImage(prediction_night_img);
                fillMode: Image.PreserveAspectFit
            }

            Text {
                id: id_prediction_night_type
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: id_prediction_night_image.bottom
                anchors.topMargin: 10

                text: prediction_night_info
                color: "white"
                font.family: "Helvetica"
                font.pointSize: 20
            }

            Text {
                id: id_prediction_night_temperature
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: id_prediction_night_type.bottom
                anchors.topMargin: 10

                text: prediction_night_temperature + "℃"
                color: "white"
                font.family: "Helvetica"
                font.pointSize: 20
            }

            Text {
                id: id_prediction_night_direct
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: id_prediction_night_temperature.bottom
                anchors.topMargin: 10

                text: prediction_night_direct
                color: "white"
                font.family: "Helvetica"
                font.pointSize: 20
            }

            Text {
                id: id_prediction_night_power
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: id_prediction_night_direct.bottom
                anchors.topMargin: 10

                text: prediction_night_power
                color: "white"
                font.family: "Helvetica"
                font.pointSize: 20
            }
        }
    }
}
