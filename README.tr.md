# Arduino Gas Detector

<p align="center">
  <strong>Gaz seviyesi ve sıcaklık eşiğine dayalı alarm prototipi</strong><br>
  Arduino, MQ-135 analog ölçümü ve DHT11 sıcaklık sensörüyle buzzer/röle kontrolü.
</p>

<p align="center">
  <img alt="Platform" src="https://img.shields.io/badge/Platform-Arduino-00979D?logo=arduino&logoColor=white">
  <img alt="Sensor" src="https://img.shields.io/badge/Sensors-MQ--135%20%2B%20DHT11-orange">
  <img alt="Firmware" src="https://img.shields.io/badge/Firmware-C%2B%2B-blue?logo=cplusplus&logoColor=white">
</p>

---

## Genel Bakış

Bu Arduino sketch'i MQ-135 sensöründen analog gaz değeri okur, DHT11 ile sıcaklığı belirli aralıklarla ölçer ve eşiklerden biri aşıldığında buzzer ile röleyi etkinleştirir. Dijital gaz sensörü çıkışı da alarm koşuluna dahil edilmiştir. Seri port üzerinden tanılama değerleri yazdırılır.

## Donanım ve Pinler

| Bileşen | Arduino pini | Amaç |
|---|---:|---|
| DHT11 | D2 | Sıcaklık ölçümü |
| MQ-135 analog çıkış | A0 | Analog gaz seviyesi |
| Dijital gaz çıkışı | D6 | Dijital alarm girişi |
| Buzzer | D7 | Sesli alarm |
| Röle | D8 | Harici alarm/çıkış |
| Seri port | 9600 baud | Tanılama çıktısı |

Pin eşleşmelerini kullandığınız kart ve modüllere göre doğrulayın.

## İşleyiş

- 🌡️ DHT11 sıcaklığı yaklaşık iki saniyede bir okunur.
- 📈 MQ-135 analog değeri her döngüde okunur.
- 🚨 Analog değer 550 eşiğini aşarsa, sıcaklık 50 °C'yi geçerse veya dijital gaz girişi aktifse alarm devreye girer.
- 🔊 Alarm sırasında buzzer yaklaşık 300 ms aralıkla açılıp kapanır.
- 🔌 Alarm aktifken röle çıkışı HIGH olur.
- 🖥️ Gaz, dijital giriş ve sıcaklık değerleri seri porta yaklaşık 500 ms aralıkla yazdırılır.

## Kurulum

1. Arduino IDE'yi açın.
2. DHT sensör kütüphanesini kurun.
3. GasDedector.ino dosyasını açın.
4. Kartı ve doğru portu seçip firmware'i yükleyin.
5. Seri monitörü 9600 baud hızında açarak ölçümleri gözlemleyin.
6. Alarm eşiklerini sensör modülünüz ve test koşullarınız için kontrollü şekilde ayarlayın.

## Güvenlik Uyarısı

**Bu proje tek başına sertifikalı bir gaz kaçağı veya yangın alarmı değildir.** MQ-135 ölçümü gaz türüne, kalibrasyona, ısınma süresine ve çevre koşullarına bağlıdır; 550 değeri evrensel bir ppm karşılığı değildir. Gerçek güvenlik uygulamalarında uygun sertifikalı dedektör, kalibrasyon, yedekli algılama ve fail-safe tasarım gerekir.

Röleye bağlı yükün elektriksel değerlerini kontrol edin; Arduino pinleriyle yüksek güçlü yükleri doğrudan sürmeyin. Gerçek gaz ortamında tehlikeli testler yapmayın.

## Durum

Bu depo bir Arduino prototipini belgelendirir. Gerçek ortamda güvenlik amaçlı kullanım için uygun değildir; önce laboratuvar ortamında doğrulanmalıdır.
