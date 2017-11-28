## PiSmartCenter

Project use Qt/QML.

## Description

天气和时钟实时显示应用，可运行树莓派等其他平台上.

## View

* Simple App on Windows:

<div align=left><img width="800" height="505" src="https://github.com/to9/PiSmartCenter/blob/master/images/PiSmartCenter.png"/></div>

## Setting raspberry font library

#### 1： 树莓派上安装文泉驿中文字体
- apt-get install ttf-wqy-zenhei

字库安装成功后，查找文泉驿字库"wqy-zenhei.ttc" 复制到Qt交叉编译库目录下/usr/local/qt-5.9.2-raspberry/lib/fonts. 
如果没有fonts目录,则新建一个fonts目录. 程序运行后会自动查找该目录下对应字库。
```
mkdir fonts
cp /usr/share/fonts/truetype/wqy/wqy-zenhei.ttc wqy-zenhei.ttc
```

## Setting raspberry

#### 1: 设置树开机自动进入命令行

- raspi-config

选择 "3 Boot Options            Configure options for start-up"

选择 "B1 Desktop / CLI          Choose whether to boot int a desktop environment or the command line"

设置 "B1 Console                Text console, requiring user to login" 

#### 2： 开机命令行用户自动登录(root 账户)

- vim /etc/systemd/system/getty.target.wants/getty@tty1.service

将行： ExecStart=-/sbin/agetty --noclear %I $TERM

改成： ExecStart=-/sbin/agetty --autologin root --noclear %I $TERM

其中"root"为自动登录的用户名。

#### 3： 编写开机运行脚本

- vim /etc/profile.d/PiSmartCenter.sh
```
$ cd /uar/local/rasp-qt
$ ./PiSmartCenter 
```
设置完成后重启系统，系统会自动执行"/etc/profile.d/"目录下所有脚本。也就完成了开机自动登录然后自动运行PiSmartCenter目的。

## License

[![Crates.io](https://img.shields.io/packagist/l/doctrine/orm.svg?style=plastic)](https://github.com/to9/CodeStyle)<br>

Copyright (c) 2017-present, G.D.
