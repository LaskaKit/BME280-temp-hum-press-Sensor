# The module with measurement of pressure, temperature and humidity BME280 with μSup connector
Are you looking for a sensor what is able to measure temperature, humidity and pressure? Probably, you would like to buy BME280, but we are 100% sure you will appreciate the BME280 with our module. It is so versatile!

![Assembled module - TOP](https://github.com/LaskaKit/BME280-temp-hum-press-Sensor/blob/main/img/BME280_uSup1.jpg)

Do you want to quickly connect BME280 module with your evaluation board/shield? Use [μSup connector](https://blog.laskarduino.cz/predstavujeme-univerzalni-konektor-pro-propojeni-modulu-a-cidel-%ce%bcsup/), there are two connectors just in case you would like to connect another modules. If you don't have a cable with μSup (or SparkFun Qwiic or Adafruit STEMMA, yes, there are compatible each other), you can connect BME280 with 4pins header to another board. Just use dupont wires. 

Is the module so big? No problem, just cut the part with connectors. Then you can put the rest of connector [to this cover](https://www.laskakit.cz/kryt-senzoru-s-kabelem--4pin--1m/)

The module includes built-in pull-up resistors for I2C (SDA/SCL) signals. The default setting is that solder bridge is closed, it means the pull-up resistors are connected to I2C. You can screw the module to your box thanks to two holes on the sides. 

## BME280
The sensor BME280 is made by Bosch company with huge community. You can find a library for all of platforms such as Arduino, STM32 or Raspberry Pi.</br>
https://github.com/adafruit/Adafruit_BME280_Library </br>
https://github.com/sparkfun/SparkFun_BME280_Arduino_Library</br>
https://github.com/ProjectsByJRP/stm32-bme280</br>
https://pypi.org/project/RPi.bme280/</br>

The measurement accuracy is +-1 °C in range from 0 °C to 65 °C, the resolution is defined as 0.01 °C and the sensor is able to work in range from -40 to +85 °C, of course the inaccuracy outside of 0 - 65 °C range is higher - up to 1.5 °C. 

The humidity accuracy is defined as +-3 %RH, the resolution is 0.008 %RH and long-term stability is lower than +-0,5 %RH per year.

The pressure accuracy is  +-1 hPa in range from 0 to 65 °C, the resolution is 0.18 Pa and log-term stability is defined as +- 1hPa.  

The minimum and maximum power supply is from 1.71V up to 3.6V. </br>
The power consumption achieves up to 3.6 uA (temperature, humidity, pressure with 1Hz measurement) and the current in deep-sleep is 0.1 uA. 

The I2C address can be set to 0x77 or 0x76, the default address is 0x77 and defined by closed solder bridge. If you want to use 0x76 I2C address, you have to cut the track in solder bridge and solder oposite side with center pad. 

![Assembled module - BOTTOM](https://github.com/LaskaKit/BME280-temp-hum-press-Sensor/blob/main/img/BME280_uSup2.jpg)


The example code with ESP32-LPkit is available on https://github.com/LaskaKit/BME280-temp-hum-press-Sensor/tree/main/SW
