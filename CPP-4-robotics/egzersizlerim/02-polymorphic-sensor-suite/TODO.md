## Proje 2 — Çok Sensörlü Robot Sınıf Hiyerarşisi (Polymorphic Sensor Suite)

**Seviye:** Orta | **Süre tahmini:** 6-8 saat

### Ne inşa ediyorsun?
Farklı sensör tiplerini (mesafe, sıcaklık, IMU) **ortak bir arayüzden** yöneten, polymorphism kullanan bir sensör yönetim sistemi. Bu proje, Proje 1'in "tek tip veri" yaklaşımını, gerçek robotlardaki gibi **birbirinden çok farklı sensörleri** tek bir sistemde toplamaya genişletir.

### Kullanacağın konular ve neden bu proje bunları birleştiriyor
- **Soyut sınıflar / pure virtual (Bölüm 10.2):** `Sensor` adında bir temel sınıf, her sensör tipinin uyması gereken `read()` ve `get_name()` arayüzünü tanımlar.
- **Kalıtım + virtual (Bölüm 10.1):** `DistanceSensor`, `TemperatureSensor`, `ImuSensor` sınıfları `Sensor`'dan türer.
- **Smart pointer'lar (Bölüm 13.2):** Sensörleri `new`/`delete` yerine `std::unique_ptr<Sensor>` ile yönetmek — bellek sızıntısı riskini ortadan kaldırmak.
- **`vector<unique_ptr<Sensor>>`:** Farklı sensör tiplerini **tek bir listede** tutmak — polymorphism'in asıl gücü burada ortaya çıkar.
- **Encapsulation (Bölüm 9.2, 9.3):** Her sensörün `private` iç durumu (son okunan değer, kalibrasyon offseti) ve `public` getter'ları.
- **Exception handling (Bölüm 8.3):** Bir sensör "bağlantı hatası" simüle ettiğinde (örn. `%5` ihtimalle rastgele) bunu `throw`/`catch` ile yönetmek.

### TODO Listesi
- [ ] Soyut temel sınıfı tanımla:
  ```cpp
  class Sensor {
  public:
      virtual double read() = 0;             // saf sanal
      virtual std::string get_name() const = 0;
      virtual ~Sensor() = default;           // ⚠️ neden virtual destructor gerekli? Araştır ve README'ne yaz.
  };
  ```
- [ X ] `DistanceSensor : public Sensor` yaz — `read()` metodu 0.1-5.0 metre arası rastgele bir değer döndürsün.
- [ ] `TemperatureSensor : public Sensor` yaz — `read()` metodu 15-35°C arası değer döndürsün.
- [ ] `ImuSensor : public Sensor` yaz — `read()` metodu -180 ile 180 derece arası bir yönelim (heading) açısı döndürsün.
- [ ] `%5` ihtimalle (rastgele sayı ile kontrol et) her sensörün `read()` metodu `std::runtime_error("Sensor disconnected: " + get_name())` fırlatsın.
- [ ] `main()` içinde `std::vector<std::unique_ptr<Sensor>> sensors;` oluştur, `make_unique` ile 1 `DistanceSensor`, 1 `TemperatureSensor`, 1 `ImuSensor` ekle.
- [ ] Bir döngüde tüm sensörleri sırayla oku; her okumayı `try`/`catch` içine al — hata olursa "Sensör X bağlantısı koptu, atlanıyor" yazdır, program çökmesin.
- [ ] Başarılı okumaları bir `std::map<std::string, double>` içinde en son değer olarak tut (`sensor_name → last_value`).
- [ ] Programın sonunda tüm sensörlerin **son bilinen değerlerini** `map`'ten okuyup özet halinde yazdır.

### Zorlaştırma
- [ ] `Sensor` sınıfına `virtual void calibrate(double offset)` ekle, her sensör tipi bunu farklı şekilde uygulasın.
- [ ] Sensörleri isimle aramak için `find_sensor_by_name(const std::string& name)` fonksiyonu yaz (döngüyle `vector` içinde arama yapmalısın).
- [ ] Neden `unique_ptr` kullandığını, `shared_ptr` kullansaydın ne değişirdi diye README'ne bir paragraf yaz (gerçekten düşün, kopyalama).