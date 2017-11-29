## PiSmartCenter
[![Travis](https://img.shields.io/badge/release-1.0.0-blue.svg?style=plastic)](https://github.com/to9/PiSmartCenter/tree/master/bin)

## Description

This PiSmartCenter project is written in Qt/QML. It is have real time info display. Can run on the raspberry pi.

## View

* Simple App on Windows:

<div align=left><img width="800" height="505" src="https://github.com/to9/PiSmartCenter/blob/master/images/PiSmartCenter.png"/></div>

## Setting font library for raspberry 

#### 树莓派上安装文泉驿中文字体
- apt-get install ttf-wqy-zenhei

    字库安装成功后，查找文泉驿字库"wqy-zenhei.ttc" 复制到Qt交叉编译库目录下/usr/local/qt-5.9.2-raspberry/lib/fonts. 
  如果没有fonts目录,则新建一个fonts目录. 程序运行后会自动查找该目录下对应字库。
```
mkdir fonts
cp /usr/share/fonts/truetype/wqy/wqy-zenhei.ttc wqy-zenhei.ttc
```

## Setting start-up for raspberry

#### 1: 设置树开机自动进入命令行

- raspi-config

    select "3 Boot Options            Configure options for start-up"

    select "B1 Desktop / CLI          Choose whether to boot int a desktop environment or the command line"

    setting "B1 Console                Text console, requiring user to login" 

#### 2: 开机命令行用户自动登录(root 账户)

- vim /etc/systemd/system/getty.target.wants/getty@tty1.service

    line： ExecStart=-/sbin/agetty --noclear %I $TERM

    change： ExecStart=-/sbin/agetty --autologin root --noclear %I $TERM

    "root" is the username of the automatic login.

#### 3: 编写开机运行脚本

- vim /etc/profile.d/PiSmartCenter.sh
```
$ cd /uar/local/rasp-qt
$ ./PiSmartCenter 
```
设置完成后重启系统，系统会自动执行"/etc/profile.d/"目录下所有脚本。也就完成了开机自动登录然后自动运行PiSmartCenter目的。

## License

[![Crates.io](https://img.shields.io/packagist/l/doctrine/orm.svg?style=plastic)](https://github.com/to9/PiSmartCenter)<br>

Copyright (c) 2017-present, G.D.
