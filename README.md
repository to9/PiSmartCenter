## PiSmartCenter
[![Travis](https://img.shields.io/badge/release-1.0.0-blue.svg?style=plastic)](https://github.com/to9/PiSmartCenter/tree/master/bin)

## Description

This PiSmartCenter project is written in Qt/QML. It is have real time info display. Can run on the raspberry pi.

## View

- Run on Windows:

<div align=left><img width="800" height="505" src="https://github.com/to9/PiSmartCenter/blob/master/images/PiSmartCenter.png"/></div>


- Run on Raspberry Pi

![image](https://github.com/to9/PiSmartCenter/blob/master/images/PiSmartCenter.gif)

## Setting font library for raspberry 

#### Raspberry Pi installed wqy fonts
- apt-get install ttf-wqy-zenhei

    字库安装成功后，查找文泉驿字库"wqy-zenhei.ttc" 复制到Qt交叉编译库目录下/usr/local/qt-5.9.2-raspberry/lib/fonts. 
  如果没有fonts目录,则新建一个fonts目录. 程序运行后会自动查找该目录下对应字库。
```
mkdir fonts
cp /usr/share/fonts/truetype/wqy/wqy-zenhei.ttc wqy-zenhei.ttc
```

## Setting start-up for raspberry

#### 1: Set Raspberry Pi boot to automatically enter the command line

- raspi-config

    select "3 Boot Options            Configure options for start-up"

    select "B1 Desktop / CLI          Choose whether to boot int a desktop environment or the command line"

    setting "B1 Console                Text console, requiring user to login" 

#### 2: Automatically log in by the command line (root username)

- vim /etc/systemd/system/getty.target.wants/getty@tty1.service

    line： ExecStart=-/sbin/agetty --noclear %I $TERM

    change： ExecStart=-/sbin/agetty --autologin root --noclear %I $TERM

    "root" is the username of the automatic login.

#### 3: Boot script

- vim /etc/profile.d/PiSmartCenter.sh
```
$ cd /uar/local/rasp-qt
$ ./PiSmartCenter 
```
#### 4: reboot

Reboot system.The system automatically executes all the scripts in the "/etc/profile.d/" directory. 

PiSmartCenter program auto start.

## License

[![Crates.io](https://img.shields.io/packagist/l/doctrine/orm.svg?style=plastic)](https://github.com/to9/PiSmartCenter/blob/master/LICENSE)

Copyright (c) 2017-present, G.D.
