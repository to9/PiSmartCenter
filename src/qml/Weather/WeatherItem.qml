import QtQuick 2.7

Item {
    id: weather_item
   // anchors.fill: parent

    property color background

    property string data
    property double temperature
    property string tpye
    property string image
    property string direct
    property string power

    Rectangle {
        id: weather_1
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        anchors.right: parent.right
        anchors.rightMargin: 30

        radius: 15
        opacity: 0.5
        width: 150
        height: 350
        color: background
    }
}
