# Modul tlaku, teploty a vlhkosti BME280 s konektorem μŠup
Hledáš čidlo, který bude měřit jak teplotu a vlhkost tak i tlak? To asi hledáš čidlo BME280, určitě ale oceníš náš modul na který je toto čidlo osazeno.
Proč? Protože je tak všestranný! 

![Osazený modul - TOP](https://github.com/LaskaKit/BME280-temp-hum-press-Sensor/blob/main/img/BME280_uSup1.jpg)

Chceš modul BME280 rychle propojit se svou deskou? Použij [μŠup konektor](https://blog.laskarduino.cz/predstavujeme-univerzalni-konektor-pro-propojeni-modulu-a-cidel-%ce%bcsup/), jsou tam rovnou dva abys mohl propojit další moduly a vývojové desky. Pokud nemáš kabel s μŠup (nebo SparkFun Qwiic nebo Adafruit STEMMA, ano, se všemi je μŠup kompatibilní), můžeš modul s BME280 propojit se svou deskou skrze čtyřpinový hřebínek ke kterému použiješ dupont kabely. 

Je modul moc velký? Ani to není problém! Může DPS jednoduše ustřihnout a nechat si jen část modulu, který můžeš zabudovat [do tohoto krytu](https://www.laskakit.cz/kryt-senzoru-s-kabelem--4pin--1m/)

Modul má vlastní pull-up rezistory, které jsou ve výchozím nastavení zapojené mezi napájení a SDA/SCL. Pokud je použít nechceš, přeřízni cestu v pájecím mostě. 
Modul může být pevně připevněn v krabičce díky otvorům po jeho stranách.

## BME280
Čidlo BME280 je dlouholetým a velmi oblíbeným čidlem firmy Bosch. Pro toto čidlo existuje velké množství knihoven jak pro Arduino, tak i pro STM32 nebo Raspberry Pi.</br>
https://github.com/adafruit/Adafruit_BME280_Library </br>
https://github.com/sparkfun/SparkFun_BME280_Arduino_Library</br>
https://github.com/ProjectsByJRP/stm32-bme280</br>
https://pypi.org/project/RPi.bme280/</br>

Přesnost měření teploty je +-1 °C v rozsahu od 0 °C do 65 °C, rozlišení je pak uvedeno jako 0,01 °C a čidlo dokáže fungovat v rozsahu od -40 do +85°C samozřejmě je mimo rozsah 0-65°C dovolena vyšší nepřesnost - až 1,5 °C. 

Přesnost měření vlhkosti je v katalogovém listu uvedena hodnota +-3 %RH, rozlišení 0,008 %RH a vliv stárnutí součástky je uveden v katalogovém listu jako menší než +-0,5 %RH za jeden rok.

Přenost měření tlaku se v rozsahu teplot od 0 do 65 °C pohybuje +- 1hPa, rozlišení dat je 0,18Pa a vliv stárnutí čidla na měření je +- 1hPa.  

Napájecí napětí čidla se pohybuje v rozsahu od 1,71V až do 3,6V. </br>
Spotřeba během měření se pohybuje okolo 3,6 uA (teplota, vlhkost, tlak s frekvencí měření 1Hz) a ve spánku čidlo BME280 odebírá pouhých 0,1 uA. 

I2C adresa může být 0x76 nebo 0x77, výchozí propojka je nastavena na 0x77. Pokud chceš změnit I2C adresu na 0x76, musíš přeříznout cestu v pájecím mostě a zapájet střed s druhou stranou označenou jako 0x76.

![Osazený modul- BOTTOM](https://github.com/LaskaKit/BME280-temp-hum-press-Sensor/blob/main/img/BME280_uSup2.jpg)


Vzorový kód pro BME280 ve spojení s vývojovým kitem ESP32-LPkit najdeš na https://github.com/LaskaKit/BME280-temp-hum-press-Sensor/tree/main/SW
