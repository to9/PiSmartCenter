#ifndef APPMODEL_H
#define APPMODEL_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QNetworkReply>
#include <QtQml/QQmlListProperty>

class WeatherData : public QObject {
    Q_OBJECT
    Q_PROPERTY(double temperature
               READ temperature WRITE setTemperature
               NOTIFY dataChanged)
    Q_PROPERTY(int airpressure
               READ airpressure WRITE setAirpressure
               NOTIFY dataChanged)
    Q_PROPERTY(int humidity
               READ humidity WRITE setHumidity
               NOTIFY dataChanged)
    Q_PROPERTY(int rain
               READ rain WRITE setRain
               NOTIFY dataChanged)
    Q_PROPERTY(QString info
               READ info WRITE setInfo
               NOTIFY dataChanged)
    Q_PROPERTY(QString image
               READ image WRITE setImage
               NOTIFY dataChanged)
    Q_PROPERTY(double feelst
               READ feelst WRITE setFeelst
               NOTIFY dataChanged)
    Q_PROPERTY(QString direct
               READ direct WRITE setDirect
               NOTIFY dataChanged)
    Q_PROPERTY(double speed
               READ speed WRITE setSpeed
               NOTIFY dataChanged)
    Q_PROPERTY(QString power
               READ power WRITE setPower
               NOTIFY dataChanged)
    Q_PROPERTY(QString publishTime
               READ publishTime WRITE setPublishTime
               NOTIFY dataChanged)
    Q_PROPERTY(QString city
               READ city WRITE setCity
               NOTIFY dataChanged)
    Q_PROPERTY(QString province
               READ province WRITE setProvince
               NOTIFY dataChanged)
    Q_PROPERTY(QString forecasttime
               READ forecasttime WRITE setForecasttime
               NOTIFY dataChanged)
    Q_PROPERTY(int aqi
               READ aqi WRITE setAqi
               NOTIFY dataChanged)
    Q_PROPERTY(int aq
               READ aq WRITE setAq
               NOTIFY dataChanged)
    Q_PROPERTY(QString text
               READ text WRITE setText
               NOTIFY dataChanged)
    Q_PROPERTY(QString alert
               READ alert WRITE setAlert
               NOTIFY dataChanged)
    Q_PROPERTY(QString issuecontent
               READ issuecontent WRITE setIssuecontent
               NOTIFY dataChanged)
    Q_PROPERTY(QString predictionDate
               READ predictionDate WRITE setPredictionDate
               NOTIFY dataChanged)
    Q_PROPERTY(QString dayInfo
               READ dayInfo WRITE setDayInfo
               NOTIFY dataChanged)
    Q_PROPERTY(QString dayImg
               READ dayImg WRITE setDayImg
               NOTIFY dataChanged)
    Q_PROPERTY(QString dayTemperature
               READ dayTemperature WRITE setDayTemperature
               NOTIFY dataChanged)
    Q_PROPERTY(QString dayDirect
               READ dayDirect WRITE setDayDirect
               NOTIFY dataChanged)
    Q_PROPERTY(QString dayPower
               READ dayPower WRITE setDayPower
               NOTIFY dataChanged)
    Q_PROPERTY(QString nigthInfo
               READ nigthInfo WRITE setNigthInfo
               NOTIFY dataChanged)
    Q_PROPERTY(QString nigthImg
               READ nigthImg WRITE setNigthImg
               NOTIFY dataChanged)
    Q_PROPERTY(QString nigthTemperature
               READ nigthTemperature WRITE setNigthTemperature
               NOTIFY dataChanged)
    Q_PROPERTY(QString nigthDirecct
               READ nigthDirecct WRITE setNigthDirecct
               NOTIFY dataChanged)
    Q_PROPERTY(QString nigthPower
               READ nigthPower WRITE setNigthPower
               NOTIFY dataChanged)

public:
    explicit WeatherData(QObject *parent = 0);
    WeatherData(const WeatherData &other);

    double temperature() const;
    int airpressure() const;
    int humidity() const;
    int rain() const;
    QString info() const;
    double feelst() const;
    QString image() const;
    QString direct() const;
    double speed() const;
    QString power() const;
    QString publishTime() const;
    QString city() const;
    QString province() const;
    QString forecasttime() const;
    int aqi() const;
    int aq() const;
    QString text() const;
    QString alert() const;
    QString issuecontent() const;
    QString predictionDate() const;
    QString dayInfo() const;
    QString dayImg() const;
    QString dayTemperature() const;
    QString dayDirect() const;
    QString dayPower() const;
    QString nigthInfo() const;
    QString nigthImg() const;
    QString nigthTemperature() const;
    QString nigthDirecct() const;
    QString nigthPower() const;

    void setTemperature(double value);
    void setAirpressure(int value);
    void setHumidity(int value);
    void setRain(int value);
    void setInfo(const QString &value);
    void setFeelst(double value);
    void setImage(const QString &value);
    void setDirect(const QString &value);
    void setSpeed(double value);
    void setPower(const QString &value);
    void setPublishTime(const QString &value);
    void setCity(const QString &value);
    void setProvince(const QString &value);
    void setForecasttime(const QString &value);
    void setAqi(int value);
    void setAq(int value);
    void setText(const QString &value);
    void setAlert(const QString &value);
    void setIssuecontent(const QString &value);
    void setPredictionDate(const QString &value);
    void setDayInfo(const QString &value);
    void setDayImg(const QString &value);
    void setDayTemperature(const QString &value);
    void setDayDirect(const QString &value);
    void setDayPower(const QString &value);
    void setNigthInfo(const QString &value);
    void setNigthImg(const QString &value);
    void setNigthTemperature(const QString &value);
    void setNigthDirecct(const QString &value);
    void setNigthPower(const QString &value);

signals:
    void dataChanged();

private:
    //气温
    double m_temperature;
    //气压
    int m_airpressure;
    //湿度
    int m_humidity;
    //降雨量
    int m_rain;
    //气象
    QString m_info;
    //体感温度
    double m_feelst;
    //天气图像索引
    QString m_image;
    //风向
    QString m_direct;
    //风速
    double m_speed;
    //风力级数
    QString m_power;
    //发布时间
    QString m_publish_time;
    //城市
    QString m_city;
    //省会
    QString m_province;

    //空气质量
    QString m_forecasttime;
    int m_aqi;
    int m_aq;
    QString m_text;

    //天气预警
    QString m_alert;
    QString m_issuecontent;

    //day and night
    QString m_prediction_date;

    QString m_day_info;
    QString m_day_img;
    QString m_day_temperature;
    QString m_day_direct;
    QString m_day_power;

    QString m_night_info;
    QString m_night_img;
    QString m_night_temperature;
    QString m_night_direct;
    QString m_night_power;
};

Q_DECLARE_METATYPE(WeatherData)

class AppModelPrivate;
class AppModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(WeatherData *weather
               READ weather
               NOTIFY weatherChanged)
//    Q_PROPERTY(QQmlListProperty<WeatherData> forecast
//               READ forecast
//               NOTIFY weatherChanged)

public:
    explicit AppModel(QObject *parent = 0);
    ~AppModel();

    WeatherData *weather() const;
   // QQmlListProperty<WeatherData> forecast() const;

signals:
    void weatherChanged();

public slots:
    Q_INVOKABLE void refreshWeather();

private slots:
    void query(QNetworkReply* reply);
    void aqi_query(QNetworkReply* reply);
    void prediction_query(QNetworkReply* reply);

private:
    AppModelPrivate *d;
};

#endif // APPMODEL_H
