<h1 align = "center">UEDX48480021-MD80ESP32_2.1英寸旋钮屏</h1>

<p align="center" width="90%">
    <img src="image/2.1.jpg" alt="">
    <img src="image/2.1_1.jpg" alt="">
</p>

## **[English](./README.md) | 中文**

## ⚠️ 注意事项
**硬件区分**  
   本仓库适用于**无触摸版本**的旋钮硬件。对于带触摸功能的类似旋鈕，请参考：  
   [UEDX48480021-MD80ESP32-2.1inch-Touch-Knob-Display](https://github.com/VIEWESMART/UEDX48480021-MD80ESP32-2.1inch-Touch-Knob-Display)  
   - **主要区别**:
     - 触摸 vs. 无触摸
     - 不同的显示驱动芯片 (GC9503CV vs. ST7701S)
     - **固件和库不可互换**

## 快速入门

### Arduino 示例项目
1. 安装 [Arduino](https://www.arduino.cc/en/software) 并打开它。

2. 打开项目文件夹中的 `example` 目录，选择 `SquareLinePorting` 项目文件夹，然后打开 `SquareLinePorting.ino` 文件以打开 Arduino IDE 项目工作区。

3. 打开右上角的 `工具` 菜单 -> 选择 `开发板` -> `开发板管理器`。搜索 `esp32` 并下载由 **Espressif Systems** 编写的开发板文件（建议使用 3.0.7 版本，较新版本可能无法正常工作）。
   安装后，返回 `开发板` 菜单，在 `esp32` 类别下，选择 `ESP32S3 Dev Module` 开发板。

4. 在 `工具` 菜单中，检查并选择下表中所示的正确设置。

#### ESP32-S3

|          Setting         |              Value              |
| :----------------------: | :-----------------------------: |
|           Board          |        ESP32S3 Dev Module       |
|       CPU Frequency      |          240MHz (WiFi)          |
|     Core Debug Level     |               None              |
|      USB CDC On Boot     |             Enabled             |
|      USB DFU On Boot     |             Disabled            |
|       Events Run On      |              Core 1             |
|        Flash Mode        |            QIO 80MHz            |
|        Flash Size        |           16MB (128Mb)          |
|      Arduino Runs On     |              Core 1             |
| USB Firmware MSC On Boot |             Disabled            |
|     Partition Scheme     | 16M Flash (3MB APP/9.9MB FATFS) |
|           PSRAM          |            OPI PSRAM            |
|        Upload Mode       |        UART0/Hardware CDC       |
|       Upload Speed       |              921600             |
|         USB Mode         |      Hardware CDC and JTAG      |

5. 在 `工具` -> `端口` 菜单中，选择正确的端口。

6. 打开菜单栏 **[文件](image/6.png)** -> **[首选项](image/6.png)**，找到 **[项目文件夹位置](image/7.png)**，
   将项目目录中 **Libraries** 文件夹下的所有库文件和文件夹复制到此目录下的 **libraries** 文件夹中（在 Windows 上的默认位置是 `C:\Users\<username>\Documents\Arduino\libraries`）。

7. 点击右上角的 <kbd>[√](image/8.png)</kbd> 按钮进行编译。
   如果编译成功，用数据线将微控制器连接到电脑，
   然后点击右上角的 <kbd>[→](image/9.png)</kbd> 按钮上传程序。

## 参考：硬件详情与恢复

### 内部结构参考
为了方便硬件调试或定制，以下是内部组件的参考图：

<p align="center" width="100%">
    <img src="image/disassembled-internal-picture-1.jpg" alt="内部组件视图 1" width="45%">
    <img src="image/disassembled-internal-picture-2.jpg" alt="内部组件视图 2" width="45%">
</p>

---

### TTL 恢复模式
如果设备因固件问题变得无响应，请使用 TTL-to-USB 转换器（例如 CH340G 模块）进行恢复：

 **接线指南**:  
   请按照下图所示的引脚映射进行连接：  
   <p align="center" width="60%">
       <img src="image/ttl-pins.jpg" alt="TTL 恢复接线" >
   </p>

 **恢复步骤**:
   - 将 TTL 模块连接到 PC 并打开串口终端（波特率 115200）
   - 在给板子上电的同时，**按住中央旋钮按钮** (BOOT/IO0)

> 💡 **注意**: 中央旋钮按钮硬连接到 `IO0`，用于强制进入下载模式。


## 参考：仓库目录介绍

```
├── Libraries                 Arduino 示例所需的库文件
├── Schematic                 产品的电路原理图
├── examples                  示例文件，包括 IDF 框架和 Arduino 框架
├── image                     产品或示例项目相关的图片
├── information               产品规格书，包括所涉及的 IC 或外设
├── tools                     烧录工具和图像转换工具
└── README.md                 您当前正在阅读的文件，对产品进行简要介绍
```

## 版本迭代：
|     开发板版本     | 屏幕尺寸 | 分辨率  |  更新日期  | 更新说明 |
| :----------------: | :------: | :-----: | :--------: | :------: |
| UEDX48480021-MD80E | 2.1英寸  | 480*480 | 2024-07-23 | 初始版本 |

## 购买链接

|        产品        |    SOC    | FLASH |     PSRAM      |                                                          链接                                                           |
| :----------------: | :-------: | :---: | :------------: | :---------------------------------------------------------------------------------------------------------------------: |
| UEDX48480021-MD80E | ESP32S3R8 |  16M  | 8M (Octal SPI) | [VIEWE 商城](https://viewedisplay.com/product/esp32-7-inch-800x480-rgb-ips-tft-display-touch-screen-arduino-lvgl-uart/) |

## 目录
- [描述](#描述)
- [模块](#模块)
- [引脚概览](#引脚概览)
- [快速入门](#快速入门)
- [常见问题](#常见问题)
- [原理图](#原理图)
- [信息](#信息)
- [依赖库](#依赖库)

## 描述

UEDX48480021-MD80ESP32_2.1inch-Knob-Display 是一款带有方形 2.1 英寸 480 * 480 分辨率显示屏的开发板，基于 ESP32S3，适用于带显示功能的单片机项目开发。


## 模块

### 1.MCU

* 芯片: ESP32-S3-R8
* PSRAM: 8M (Octal SPI) 
* FLASH: 16M
* 更多详情，请访问[乐鑫 ESP32-S3 Datashee](https://www.espressif.com.cn/sites/default/files/documentation/esp32-s3_datasheet_en.pdf)

### 2. 屏幕

* 尺寸: 2.1英寸 IPS 屏幕
* 分辨率: 480x480px
* 屏幕类型: IPS
* 驱动芯片: GC9503CV
* 兼容库:  ESP32_Display_Panel
* 总线通信协议: 3 Wire SPI-RGB 24bits

### 3. 触摸

* 芯片: 无触摸

## 引脚概览

| IPS 屏幕引脚 | ESP32S3 引脚 |
| :----------: | :----------: |
|      DE      |     IO17     |
|    VSYNC     |     IO3      |
|    HSYNC     |     IO46     |
|     PCLK     |     IO9      |
|    DATA0     |     IO10     | //B
|    DATA1     |     IO11     |
|    DATA2     |     IO12     |
|    DATA3     |     IO13     |
|    DATA4     |     IO14     |
|    DATA5     |     IO21     |  //G
|    DATA6     |     IO47     |
|    DATA7     |     IO48     |
|    DATA8     |     IO45     |
|    DATA9     |     IO38     |
|    DATA10    |     IO39     |
|    DATA11    |     IO40     |  //R
|    DATA12    |     IO41     |
|    DATA13    |     IO42     |
|    DATA14    |     IO2      |
|    DATA15    |     IO1      |
|    SPI_CS    |     IO18     |
|   SPI_SCK    |     IO13     |
|   SPI_SDA    |     IO12     |
|     RST      |     IO8      |
|  BACKLIGHT   |     IO7      |


| 按键引脚 | ESP32S3 引脚 |
| :------: | :----------: |
|   boot   |     IO0      |
|  reset   |   chip-en    |

| 编码器引脚 | ESP32S3 引脚 |
| :--------: | :----------: |
|    PHA     |     IO6      |
|    PHB     |     IO5      |

| USB/UART 引脚 | ESP32S3 引脚 |
| :-----------: | :----------: |
|    USB-DN     |     IO19     |
|    USB-DP     |     IO20     |
|    UART RX    |     IO43     |
|    UART TX    |     IO44     |




### 固件下载
1. 打开项目文件“tools”并找到 ESP32 烧录工具。打开它。

2. 选择正确的烧录芯片和烧录方法，然后点击“确定”。如图所示，按照步骤 1->2->3->4->5 烧录程序。如果烧录不成功，请按住“BOOT-0”按钮，然后再次下载并烧录。

3. 烧录项目文件根目录“[firmware](./firmware/)”中的文件，里面有固件文件版本的说明，选择合适的版本下载即可。

<p align="center" width="100%">
    <img src="image/10.png" alt="示例">
    <img src="image/11.png" alt="示例">
</p>

## 常见问题

* Q. 阅读完以上教程后，我仍然不知道如何搭建编程环境。我该怎么办？
* A. 如果您在阅读完以上教程后仍然不明白如何搭建环境，可以参考 [VIEWE-FAQ]() 文档说明进行搭建。

<br />

* Q. 为什么 Arduino IDE 在打开时提示我更新库文件？我应该更新它们吗？
* A. 选择不更新库文件。不同版本的库文件可能不相互兼容，因此不建议更新库文件。

<br />

* Q. 为什么我的板子上的“Uart”接口没有串口数据输出？它是有缺陷且无法使用吗？
* A. 默认项目配置使用 USB 接口作为 Uart0 串口输出用于调试目的。“Uart”接口连接到 Uart0，因此在没有配置的情况下不会输出任何数据。<br />对于 PlatformIO 用户，请打开项目文件“platformio.ini”并将“build_flags = xxx”下的选项从“-D ARDUINO_USB_CDC_ON_BOOT=true”修改为“-D ARDUINO_USB_CDC_ON_BOOT=false”以启用外部“Uart”接口。<br />对于 Arduino 用户，打开“工具”菜单并选择“USB CDC On Boot: Disabled”以启用外部“Uart”接口。

<br />

* Q. 为什么我的板子一直无法下载程序？
* A. 请按住“BOOT”按钮，然后再次尝试下载程序。

## 原理图
<p align="center" width="100%">
    <img src="Schematic/MD80E.SCH.20240725_00.png" alt="示例">
</p>

## 信息
[产品规格书](information/UEDX48480021-MD80E%20V3.3%20SPEC.pdf)

[显示屏数据手册](information/UE021WV-RB40-L002B.pdf)

[按键](information/6x6Silent%20switch.pdf)

[编码器](information/C219783_%E6%97%8B%E8%BD%AC%E7%BC%96%E7%A0%81%E5%99%A8_EC28A1520401_%E8%A7%84%E6%A0%BC%E4%B9%A6_WJ239718.PDF)

## 依赖库
* [ESP32_Display_Panel>0.2.1](https://github.com/esp-arduino-libs/ESP32_Display_Panel) (由于支持旋钮硬件的 ESP32_Display_Panel 官方版本尚未发布，请先[下载](./Libraries/ESP32_Display_Panel)该库)
* [ESP32_IO_Expander](https://github.com/esp-arduino-libs/ESP32_IO_Expander) (由于最新版本尚未发布，请先[下载](./Libraries/ESP32_IO_Expander)该库)
* [ESP32_Button](https://github.com/esp-arduino-libs/ESP32_Button)
* [ESP32_Knob](https://github.com/esp-arduino-libs/ESP32_Knob)
* [lvgl-8.4.0](https://lvgl.io)