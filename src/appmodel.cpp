#include "appmodel.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>
#include <QUrlQuery>
#include <QElapsedTimer>
#include <QDebug>

WeatherData::WeatherData(QObject *parent) :
        QObject(parent)
{
}

WeatherData::WeatherData(const WeatherData &other) :
        QObject(0),
        m_temperature(other.m_temperature),
        m_airpressure(other.m_airpressure),
        m_humidity(other.m_humidity),
        m_rain(other.m_rain),
        m_info(other.m_info),
        m_feelst(other.m_feelst),
        m_image(other.m_image),
        m_direct(other.m_direct),
        m_speed(other.m_speed),
        m_power(other.m_power)
{
}

double WeatherData::temperature() const
{
    return m_temperature;
}
int WeatherData::airpressure() const
{
    return m_airpressure;
}
int WeatherData::humidity() const
{
    return m_humidity;
}
int WeatherData::rain() const
{
    return m_rain;
}
QString WeatherData::info() const
{
    return m_info;
}
double WeatherData::feelst() const
{
    return m_feelst;
}
QString WeatherData::image() const
{
    return m_image;
}
QString WeatherData::direct() const
{
    return m_direct;
}
double WeatherData::speed() const
{
    return m_speed;
}
QString WeatherData::power() const
{
    return m_power;
}
QString WeatherData::publishTime() const
{
    return m_publish_time;
}

QString WeatherData::city() const
{
    return m_city;
}

QString WeatherData::province() const
{
    return m_province;
}

QString WeatherData::forecasttime() const
{
    return m_forecasttime;
}
int WeatherData::aqi() const
{
    return m_aqi;
}
int WeatherData::aq() const
{
    return m_aq;
}
QString WeatherData::text() const
{
    return m_text;
}
QString WeatherData::alert() const
{
    return m_alert;
}
QString WeatherData::issuecontent() const
{
    return m_issuecontent;
}

QString WeatherData::predictionDate() const
{
    return m_prediction_date;
}
QString WeatherData::dayInfo() const
{
    return m_day_info;
}
QString WeatherData::dayImg() const
{
    return m_day_img;
}
QString WeatherData::dayTemperature() const
{
    return m_day_temperature;
}
QString WeatherData::dayDirect() const
{
    return m_day_direct;
}
QString WeatherData::dayPower() const
{
    return m_day_power;
}
QString WeatherData::nigthInfo() const
{
    return m_night_info;
}
QString WeatherData::nigthImg() const
{
    return m_night_img;
}
QString WeatherData::nigthTemperature() const
{
    return m_night_temperature;
}
QString WeatherData::nigthDirecct() const
{
    return m_night_direct;
}
QString WeatherData::nigthPower() const
{
    return m_night_power;
}

void WeatherData::setTemperature(double value)
{
    m_temperature = value;
    emit dataChanged();
}

void WeatherData::setAirpressure(int value)
{
    m_airpressure = value;
    emit dataChanged();
}

void WeatherData::setHumidity(int value)
{
    m_humidity = value;
    emit dataChanged();
}

void WeatherData::setRain(int value)
{
    m_rain = value;
    emit dataChanged();
}

void WeatherData::setInfo(const QString &value)
{
    m_info = value;
    emit dataChanged();
}

void WeatherData::setFeelst(double value)
{
    m_feelst = value;
    emit dataChanged();
}

void WeatherData::setImage(const QString &value)
{
    m_image = value;
    emit dataChanged();
}

void WeatherData::setDirect(const QString &value)
{
    m_direct = value;
    emit dataChanged();
}

void WeatherData::setSpeed(double value)
{
    m_speed = value;
    emit dataChanged();
}

void WeatherData::setPower(const QString &value)
{
    m_power = value;
    emit dataChanged();
}

void WeatherData::setPublishTime(const QString &value)
{
    m_publish_time = value;
    emit dataChanged();
}

void WeatherData::setCity(const QString &value)
{
    m_city = value;
    emit dataChanged();
}

void WeatherData::setProvince(const QString &value)
{
    m_province = value;
    emit dataChanged();
}

void WeatherData::setForecasttime(const QString &value)
{
    m_forecasttime = value;
    emit dataChanged();
}

void WeatherData::setAqi(int value)
{
    m_aqi = value;
    emit dataChanged();
}

void WeatherData::setAq(int value)
{
    m_aq = value;
    emit dataChanged();
}

void WeatherData::setText(const QString &value)
{
    m_text = value;
    emit dataChanged();
}


void WeatherData::setAlert(const QString &value)
{
    m_alert = value;
    emit dataChanged();
}
void WeatherData::setIssuecontent(const QString &value)
{
    m_issuecontent = value;
    emit dataChanged();
}

void WeatherData::setPredictionDate(const QString &value)
{
    m_prediction_date = value;
    emit dataChanged();
}
void WeatherData::setDayInfo(const QString &value)
{
    m_day_info = value;
    emit dataChanged();
}
void WeatherData::setDayImg(const QString &value)
{
    m_day_img = value;
    emit dataChanged();
}
void WeatherData::setDayTemperature(const QString &value)
{
    m_day_temperature = value;
    emit dataChanged();
}
void WeatherData::setDayDirect(const QString &value)
{
    m_day_direct = value;
    emit dataChanged();
}
void WeatherData::setDayPower(const QString &value)
{
    m_day_power = value;
    emit dataChanged();
}
void WeatherData::setNigthInfo(const QString &value)
{
    m_night_info = value;
    emit dataChanged();
}
void WeatherData::setNigthImg(const QString &value)
{
    m_night_img = value;
    emit dataChanged();
}
void WeatherData::setNigthTemperature(const QString &value)
{
    m_night_temperature = value;
    emit dataChanged();
}
void WeatherData::setNigthDirecct(const QString &value)
{
    m_night_direct = value;
    emit dataChanged();
}
void WeatherData::setNigthPower(const QString &value)
{
    m_night_power = value;
    emit dataChanged();
}

class AppModelPrivate
{
public:

    QNetworkAccessManager *manager;
    WeatherData data;
    QTimer requestNewWeatherTimer;

    AppModelPrivate() :
            manager(NULL)
    {
        requestNewWeatherTimer.setSingleShot(false);
        requestNewWeatherTimer.setInterval(20*60*1000); // 20 min
    }
};

AppModel::AppModel(QObject *parent) :
        QObject(parent),
        d(new AppModelPrivate)
{
    connect(&d->requestNewWeatherTimer, SIGNAL(timeout()), this, SLOT(refreshWeather()));
    d->requestNewWeatherTimer.start();
    d->manager = new QNetworkAccessManager(this);

    d->data.setTemperature(0);
    d->data.setAirpressure(0);
    d->data.setHumidity(0);
    d->data.setRain(0);
    d->data.setInfo("?");
    d->data.setFeelst(0);
    d->data.setImage("?");
    d->data.setDirect("?");
    d->data.setSpeed(0);
    d->data.setPower("?");

    refreshWeather();
}

AppModel::~AppModel()
{
    delete d;
}

void AppModel::refreshWeather()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this, SLOT(query(QNetworkReply*)));
    QNetworkRequest request(QUrl(""));//?????
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application");
    manager->get(request);

    QNetworkAccessManager *manager_aqi = new QNetworkAccessManager(this);
    connect(manager_aqi,SIGNAL(finished(QNetworkReply*)),this, SLOT(aqi_query(QNetworkReply*)));
    QNetworkRequest request_aqi(QUrl(""));//????
    request_aqi.setHeader(QNetworkRequest::ContentTypeHeader, "application");
    manager_aqi->get(request_aqi);

    QNetworkAccessManager *manager_prediction = new QNetworkAccessManager(this);
    connect(manager_prediction,SIGNAL(finished(QNetworkReply*)),this, SLOT(prediction_query(QNetworkReply*)));
    QNetworkRequest request_prediction(QUrl(""));//??????
    request_prediction.setHeader(QNetworkRequest::ContentTypeHeader, "application");
    manager_prediction->get(request_prediction);
}

void AppModel::query(QNetworkReply* reply)
{
    QString val = reply->readAll();
    qDebug() << val;
    QJsonDocument json_doc = QJsonDocument::fromJson(val.toUtf8());
    if(json_doc.isObject())
    {
        QJsonObject obj = json_doc.object();
        QJsonValue jsonval_station = obj.value("station");
        if(jsonval_station.isObject())
        {
            QJsonObject obj_1 = jsonval_station.toObject();
            QJsonValue jsonval_url = obj_1.value("url");
            QJsonValue jsonval_code = obj_1.value("code");
            QJsonValue jsonval_city = obj_1.value("city");
            QJsonValue jsonval_province = obj_1.value("province");

            d->data.setCity(jsonval_city.toString());
            d->data.setProvince(jsonval_province.toString());

            qDebug()<<"\njsonval_url     "<<jsonval_url.toString()
                    <<"\njsonval_code    "<<jsonval_code.toString()
                    <<"\njsonval_city    "<<jsonval_city.toString()
                    <<"\njsonval_province"<<jsonval_province.toString();

        }

         QJsonValue jsonval_publish_time = obj.value("publish_time");
         if(jsonval_publish_time.isString())
         {
             qDebug()<<"\njsonval_publish_time"<<jsonval_publish_time.toString();
             d->data.setPublishTime(jsonval_publish_time.toString());
         }

         QJsonValue jsonval_weather = obj.value("weather");
         if(jsonval_weather.isObject())
         {
            QJsonObject obj_1 = jsonval_weather.toObject();
            QJsonValue jsonval_temperature = obj_1.value("temperature");
            QJsonValue jsonval_airpressure = obj_1.value("airpressure");
            QJsonValue jsonval_humidity = obj_1.value("humidity");
            QJsonValue jsonval_rain = obj_1.value("rain");
            QJsonValue jsonval_rcomfort = obj_1.value("rcomfort");
            QJsonValue jsonval_icomfort = obj_1.value("icomfort");
            QJsonValue jsonval_info = obj_1.value("info");
            QJsonValue jsonval_img = obj_1.value("img");
            QJsonValue jsonval_feelst = obj_1.value("feelst");

            d->data.setTemperature(jsonval_temperature.toDouble());
            d->data.setAirpressure(jsonval_airpressure.toInt());
            d->data.setHumidity(jsonval_humidity.toInt());
            d->data.setRain(jsonval_rain.toInt());
            d->data.setInfo(jsonval_info.toString());
            d->data.setFeelst(jsonval_feelst.toDouble());
            d->data.setImage(jsonval_img.toString());


             qDebug()<<"\ntemperature"<<jsonval_temperature.toDouble()
                     <<"\nairpressure"<<jsonval_airpressure.toInt()
                     <<"\nhumidity   "<<jsonval_humidity.toInt()
                     <<"\nrain       "<<jsonval_rain.toInt()
                     <<"\nrcomfort   "<<jsonval_rcomfort.toInt()
                     <<"\nicomfort   "<<jsonval_icomfort.toInt()
                     <<"\ninfo       "<<jsonval_info.toString()
                     <<"\nimg        "<<jsonval_img.toString()
                     <<"\nfeelst     "<<jsonval_feelst.toDouble();
         }

         QJsonValue jsonval_wind = obj.value("wind");
         if(jsonval_wind.isObject())
         {
             QJsonObject obj_1 = jsonval_wind.toObject();
             QJsonValue jsonval_direct = obj_1.value("direct");
             QJsonValue jsonval_power = obj_1.value("power");
             QJsonValue jsonval_speed = obj_1.value("speed");

             d->data.setDirect(jsonval_direct.toString());
             d->data.setSpeed(jsonval_speed.toDouble());
             d->data.setPower(jsonval_power.toString());

             qDebug()<<"\njsonval_direct"<<jsonval_direct.toString()
                     <<"\njsonval_power"<<jsonval_power.toString()
                     <<"\njsonval_speed   "<<jsonval_speed.toDouble();
         }

         QJsonValue jsonval_warn = obj.value("warn");
         if(jsonval_warn.isObject())
         {
            QJsonObject obj_1 = jsonval_warn.toObject();
            QJsonValue jsonval_alert = obj_1.value("alert");
            QJsonValue jsonval_pic = obj_1.value("pic");
            QJsonValue jsonval_province = obj_1.value("province");
            QJsonValue jsonval_city = obj_1.value("city");
            QJsonValue jsonval_url = obj_1.value("url");
            QJsonValue jsonval_issuecontent = obj_1.value("issuecontent");
            QJsonValue jsonval_fmeans = obj_1.value("fmeans");

            d->data.setAlert(jsonval_alert.toString());
            d->data.setIssuecontent(jsonval_issuecontent.toString());

            qDebug()<<"\njsonval_alert"<<jsonval_alert.toString()
                 <<"\njsonval_pic"<<jsonval_pic.toString()
                 <<"\njsonval_province"<<jsonval_province.toString()
                 <<"\njsonval_city"<<jsonval_city.toString()
                 <<"\njsonval_url"<<jsonval_url.toString()
                 <<"\njsonval_issuecontent"<<jsonval_issuecontent.toString()
                 <<"\njsonval_fmeans"<<jsonval_fmeans.toString();
         }
    }
}

void AppModel::aqi_query(QNetworkReply* reply)
{
    QString val = reply->readAll();
    qDebug() << val;
    QJsonDocument json_doc = QJsonDocument::fromJson(val.toUtf8());
    if(json_doc.isObject())
    {
        QJsonObject obj = json_doc.object();
        QJsonValue jsonval_forecasttime = obj.value("forecasttime");
        if(jsonval_forecasttime.isString())
        {
            d->data.setForecasttime(jsonval_forecasttime.toString());
            qDebug()<<"\njsonval_forecasttime"<<jsonval_forecasttime.toString();
        }

         QJsonValue jsonval_aqi = obj.value("aqi");

         if(jsonval_aqi.isDouble())
         {
             d->data.setAqi(jsonval_aqi.toInt());
             qDebug()<<"\njsonval_aqi"<<jsonval_aqi.toInt();
         }

         QJsonValue jsonval_aq = obj.value("aq");
         if(jsonval_aq.isDouble())
         {
            d->data.setAq(jsonval_aq.toInt());
             qDebug()<<"\njsonval_aq"<<jsonval_aq.toInt();
         }

         QJsonValue jsonval_text = obj.value("text");
         if(jsonval_text.isString())
         {
             d->data.setText(jsonval_text.toString());
             qDebug()<<"\njsonval_text"<<jsonval_text.toString();
         }
    }
}

void AppModel::prediction_query(QNetworkReply* reply)
{
    QString val = reply->readAll();
    qDebug() << val;

    QJsonDocument json_doc = QJsonDocument::fromJson(val.toUtf8());
    if(json_doc.isArray())
    {
        QJsonArray json_array = json_doc.array();
        for(int i = 0; i< json_array.count(); i++)
        {
            QJsonValue json_val = json_array.at(i);
            if(json_val.isObject())
            {
               QJsonObject obj = json_val.toObject();
               QJsonValue jsonval_station = obj.value("station");
               if(jsonval_station.isObject())
               {
                    QJsonObject jsonobject_station_obj = jsonval_station.toObject();

                    QJsonValue jsonval_station_url = jsonobject_station_obj.value("url");
                    QJsonValue jsonval_station_code = jsonobject_station_obj.value("code");
                    QJsonValue jsonval_station_city = jsonobject_station_obj.value("city");
                    QJsonValue jsonval_station_province = jsonobject_station_obj.value("province");

                    qDebug()<<"url: "<<jsonval_station_url.toString();
                    qDebug()<<"code: "<<jsonval_station_code.toString();
                    qDebug()<<"city: "<<jsonval_station_city.toString();
                    qDebug()<<"province: "<<jsonval_station_province.toString();
               }


               QJsonValue jsonval_publish_time = obj.value("publish_time");
               if(jsonval_publish_time.isString())
               {
                   qDebug()<<"publish_time: "<<jsonval_publish_time.toString();
               }

               QJsonValue jsonval_temperature = obj.value("temperature");
               if(jsonval_temperature.isDouble())
               {
                   qDebug()<<"temperature: "<<jsonval_temperature.toDouble();
               }

               QJsonValue jsonvalue_detail = obj.value("detail");
               if(jsonvalue_detail.isArray())
               {
                   QJsonArray jsonarray_detail = jsonvalue_detail.toArray();
                   for(int m = 0; m< jsonarray_detail.count(); m++)
                   {
                        QJsonValue jsonarray_detail_array = jsonarray_detail.at(m);
                        if(jsonarray_detail_array.isObject())
                        {
                            QJsonObject jsonobject_detail_obj = jsonarray_detail_array.toObject();

                            QJsonValue jsonval_date = jsonobject_detail_obj.value("date");
                            QJsonValue jsonval_pt = jsonobject_detail_obj.value("pt");
                            QJsonValue jsonval_day = jsonobject_detail_obj.value("day");
                            QJsonValue jsonval_night = jsonobject_detail_obj.value("night");
                            d->data.setPredictionDate(jsonval_date.toString());

                            qDebug()<<"--------------------------------------------------";
                            qDebug()<<"date:"<<jsonval_date.toString();
                            qDebug()<<"pt:"<<jsonval_pt.toString();
                            if(jsonval_day.isObject())
                            {
                                qDebug()<<"day:";
                                QJsonObject jsonobject_day_weather = jsonval_day.toObject();
                                QJsonValue jsonval_day_weather = jsonobject_day_weather.value("weather");
                                if(jsonval_day_weather.isObject())
                                {
                                    QJsonObject jsonval_day_weather_obj = jsonval_day_weather.toObject();

                                    QJsonValue jsonobject_day_weather_info = jsonval_day_weather_obj.value("info");
                                    QJsonValue jsonobject_day_weather_img = jsonval_day_weather_obj.value("img");
                                    QJsonValue jsonobject_day_weather_temperature = jsonval_day_weather_obj.value("temperature");
                                    d->data.setDayInfo(jsonobject_day_weather_info.toString());
                                    d->data.setDayImg(jsonobject_day_weather_img.toString());
                                    d->data.setDayTemperature(jsonobject_day_weather_temperature.toString());

                                    qDebug()<<"info: "<<jsonobject_day_weather_info.toString();
                                    qDebug()<<"img: "<<jsonobject_day_weather_img.toString();
                                    qDebug()<<"temperature: "<<jsonobject_day_weather_temperature.toString();
                                }

                                QJsonValue jsonval_day_wind = jsonobject_day_weather.value("wind");
                                if(jsonval_day_wind.isObject())
                                {
                                    QJsonObject jsonval_day_wind_obj = jsonval_day_wind.toObject();

                                    QJsonValue jsonobject_day_wind_direct = jsonval_day_wind_obj.value("direct");
                                    QJsonValue jsonobject_day_wind_power = jsonval_day_wind_obj.value("power");
                                    d->data.setDayDirect(jsonobject_day_wind_direct.toString());
                                    d->data.setDayPower(jsonobject_day_wind_power.toString());

                                    qDebug()<<"direct: "<<jsonobject_day_wind_direct.toString();
                                    qDebug()<<"power: "<<jsonobject_day_wind_power.toString();
                                }
                            }

                            if(jsonval_night.isObject())
                            {
                                qDebug()<<"night:";
                                QJsonObject jsonobject_night_weather = jsonval_night.toObject();
                                QJsonValue jsonval_night_weather = jsonobject_night_weather.value("weather");
                                if(jsonval_night_weather.isObject())
                                {
                                    QJsonObject jsonval_night_weather_obj = jsonval_night_weather.toObject();

                                    QJsonValue jsonobject_night_weather_info = jsonval_night_weather_obj.value("info");
                                    QJsonValue jsonobject_night_weather_img = jsonval_night_weather_obj.value("img");
                                    QJsonValue jsonobject_night_weather_temperature = jsonval_night_weather_obj.value("temperature");
                                    d->data.setNigthInfo(jsonobject_night_weather_info.toString());
                                    d->data.setNigthImg(jsonobject_night_weather_img.toString());
                                    d->data.setNigthTemperature(jsonobject_night_weather_temperature.toString());

                                    qDebug()<<"info: "<<jsonobject_night_weather_info.toString();
                                    qDebug()<<"img: "<<jsonobject_night_weather_img.toString();
                                    qDebug()<<"temperature: "<<jsonobject_night_weather_temperature.toString();
                                }

                                QJsonValue jsonval_night_wind = jsonobject_night_weather.value("wind");
                                if(jsonval_night_wind.isObject())
                                {
                                    QJsonObject jsonval_night_wind_obj = jsonval_night_wind.toObject();

                                    QJsonValue jsonobject_night_wind_direct = jsonval_night_wind_obj.value("direct");
                                    QJsonValue jsonobject_night_wind_power = jsonval_night_wind_obj.value("power");
                                    d->data.setNigthDirecct(jsonobject_night_wind_direct.toString());
                                    d->data.setNigthPower(jsonobject_night_wind_power.toString());

                                    qDebug()<<"direct: "<<jsonobject_night_wind_direct.toString();
                                    qDebug()<<"power: "<<jsonobject_night_wind_power.toString();
                                }
                            }
                        }
                   }
               }

            }
        }
    }
}

WeatherData *AppModel::weather() const
{
    return &(d->data);
}
