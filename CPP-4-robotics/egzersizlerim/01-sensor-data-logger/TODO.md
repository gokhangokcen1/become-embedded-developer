## Proje 1 — Sensör Veri Günlükleyici (Sensor Data Logger)

**Seviye:** Başlangıç | **Süre tahmini:** 3-5 saat

### Ne inşa ediyorsun?
Sahte (simüle edilmiş) sıcaklık, batarya ve mesafe sensörlerinden periyodik olarak veri "okuyan", bu veriyi ekrana biçimlendirilmiş şekilde yazdıran ve bir dosyaya kaydeden bir konsol programı.

### Kullanacağın konular ve neden bu proje bunları birleştiriyor
- **Struct'lar (Bölüm 7.6):** Her sensör okumasını `{timestamp, sensor_name, value, unit}` gibi tek bir yapıda tutmak, dağınık değişkenler yerine düzenli veri modellemeyi öğretir.
- **Rastgele sayı üretimi (Bölüm 15.2):** Gerçek donanımın yerine geçecek, gerçekçi sınırlar içinde (örn. sıcaklık 18-30°C arası) sahte veri üretmeyi öğretir — bu, donanımın olmadığı durumlarda yazılımı test etmenin standart yoludur.
- **`vector` (Bölüm 7.2):** Okunan tüm verileri bellekte tutmak için.
- **`iomanip` ile biçimlendirme (Bölüm 3.1):** Sıcaklığı `23.45°C` gibi düzgün formatta yazdırmak için.
- **Dosya I/O (Bölüm 15.1):** Verileri `sensor_log.csv` dosyasına kaydetmek için.
- **`chrono` (Bölüm 14.2):** Her okumaya gerçekçi bir zaman damgası (timestamp) eklemek ve okumalar arasında belirli bir süre beklemek için.

### TODO Listesi
- [ X ] `SensorReading` adında bir `struct` tanımla: `std::string sensor_name`, `double value`, `std::string unit`, `double timestamp_seconds` alanları olsun.
- [ X ] `generate_fake_reading(const std::string& sensor_name)` fonksiyonu yaz — sensör ismine göre (örn. `"temperature"` ise 18.0-30.0 arası, `"battery"` ise 0.0-100.0 arası) `std::uniform_real_distribution` kullanarak rastgele bir değer üretsin ve bir `SensorReading` döndürsün.
- [ X ] Bir `std::vector<SensorReading> log;` oluştur.
- [ X ] 10 kez döngü çalıştır (`for`): her iterasyonda 3 farklı sensörden (`temperature`, `battery`, `distance`) birer okuma üret, `log` vektörüne ekle (`push_back`), ekrana `std::setprecision(2)` ile biçimlendirilmiş şekilde yazdır.
- [ X ] Her iterasyon arasında `std::this_thread::sleep_for(std::chrono::milliseconds(500))` ile gerçekçi bir bekleme koy.
- [ X ] Döngü bittikten sonra `log` vektöründeki tüm okumaları `sensor_log.csv` dosyasına yaz (her satır: `sensor_name,value,unit,timestamp`).
- [ X ] **Hata kontrolü ekle:** Eğer dosya açılamazsa (`is_open()` başarısız olursa), `std::cerr`'e anlamlı bir hata mesajı yaz ve programı `return 1;` ile sonlandır.
