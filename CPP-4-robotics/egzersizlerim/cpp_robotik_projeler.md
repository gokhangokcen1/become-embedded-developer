# C++ Robotik Pratik Projeleri — Beceri Geliştirme Yol Haritası

> Bu doküman, önceki ders kitabındaki 65 örnekte öğrendiğin konuları **gerçek, uçtan uca projelerde** birleştirmen için tasarlandı. Projeler zorluk sırasına göre dizildi; her biri bir öncekinin üzerine inşa edilebilir. Her projede: **hangi konuları kullanacağın**, **neden bu sırayla ilerlemen gerektiği**, **adım adım TODO listesi** ve **seni zorlayacak ek görevler (stretch goals)** var.

## Nasıl Çalışmalısın?

1. Her projeyi **sıfırdan kendi başına** yazmaya çalış — bu dokümandaki TODO'lar sana ne yapacağını söyler, nasıl yapacağını değil. Takılırsan önceki ders kitabındaki ilgili bölüme dön.
2. Her projeyi bitirdiğinde bir `README.md` yaz: ne yaptığını, hangi zorluklarla karşılaştığını, neyi farklı yapardın. Bu, portföyün için de değerli olur.
3. Kodunu Git ile versiyonla (her TODO'yu bitirdiğinde bir commit at) — bu hem ilerlemeni görmeni sağlar hem de gerçek bir yazılım geliştirme alışkanlığı kazandırır.
4. Mümkünse `g++ -Wall -Wextra` ile derle — bu flag'ler, `27-robot_char_functions.cpp` içindeki `if (command = 'f')` gibi hataları **derleme sırasında uyarı olarak** sana gösterir.

---

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
- [ ] `SensorReading` adında bir `struct` tanımla: `std::string sensor_name`, `double value`, `std::string unit`, `double timestamp_seconds` alanları olsun.
- [ ] `generate_fake_reading(const std::string& sensor_name)` fonksiyonu yaz — sensör ismine göre (örn. `"temperature"` ise 18.0-30.0 arası, `"battery"` ise 0.0-100.0 arası) `std::uniform_real_distribution` kullanarak rastgele bir değer üretsin ve bir `SensorReading` döndürsün.
- [ ] Bir `std::vector<SensorReading> log;` oluştur.
- [ ] 10 kez döngü çalıştır (`for`): her iterasyonda 3 farklı sensörden (`temperature`, `battery`, `distance`) birer okuma üret, `log` vektörüne ekle (`push_back`), ekrana `std::setprecision(2)` ile biçimlendirilmiş şekilde yazdır.
- [ ] Her iterasyon arasında `std::this_thread::sleep_for(std::chrono::milliseconds(500))` ile gerçekçi bir bekleme koy.
- [ ] Döngü bittikten sonra `log` vektöründeki tüm okumaları `sensor_log.csv` dosyasına yaz (her satır: `sensor_name,value,unit,timestamp`).
- [ ] **Hata kontrolü ekle:** Eğer dosya açılamazsa (`is_open()` başarısız olursa), `std::cerr`'e anlamlı bir hata mesajı yaz ve programı `return 1;` ile sonlandır.

### Zorlaştırma (Stretch Goals)
- [ ] Batarya seviyesi `%20`'nin altına düşerse konsola **kırmızı renkli** (ANSI escape kodlarıyla, `"\033[31m"`) bir uyarı yazdır.
- [ ] Programı `Ctrl+C` ile durdurduğunda bile o ana kadar toplanan verinin dosyaya yazıldığından emin ol (bir sinyal handler ekle — bu senin için yeni bir konu, araştırman gerekecek).

---

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
- [ ] `DistanceSensor : public Sensor` yaz — `read()` metodu 0.1-5.0 metre arası rastgele bir değer döndürsün.
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

---

## Proje 3 — Görev Kuyruğu ve Durum Makineli Robot Kontrolcüsü

**Seviye:** Orta-İleri | **Süre tahmini:** 8-10 saat

### Ne inşa ediyorsun?
Bir robotun görevlerini önceliğe göre sıraya koyan, bir durum makinesiyle (`IDLE`, `MOVING`, `CHARGING`, `ERROR`) hangi görevleri hangi durumda kabul edeceğine karar veren bir kontrolcü.

### Kullanacağın konular ve neden bu proje bunları birleştiriyor
- **`enum class` (Bölüm 12.6):** Robotun durumunu (`RobotState`) modellemek.
- **`struct` + operatör aşırı yükleme (Bölüm 7.6, 9.6):** `Task` struct'ı ve `operator<` ile önceliklendirme.
- **`priority_queue` (Bölüm 12.4):** Görevleri önceliğe göre işlemek.
- **`switch` + `if` mantığı (Bölüm 5.1):** Her durumda hangi görevlerin kabul edilebileceğine karar vermek.
- **Fonksiyonlara ayırma (Bölüm 6):** `process_next_task()`, `transition_state()` gibi fonksiyonlarla kodu organize etmek.
- **`const` referanslar (Bölüm 8.1, 9.3):** Görevleri fonksiyonlara kopyalamadan geçirmek.

### TODO Listesi
- [ ] `enum class RobotState { IDLE, MOVING, CHARGING, ERROR };` tanımla.
- [ ] `struct Task { int priority; std::string name; RobotState required_state; };` tanımla — `required_state`, bu görevin **hangi durumda çalıştırılabileceğini** belirtsin (örn. şarj görevleri sadece `IDLE`'da başlayabilir).
- [ ] `Task` için `operator<` yaz (yüksek `priority` değeri = yüksek öncelik).
- [ ] `RobotController` sınıfı yaz:
  - `private`: `RobotState current_state_`, `std::priority_queue<Task> task_queue_`.
  - `public`: `add_task(Task t)`, `process_next_task()`, `get_state() const`, `force_state(RobotState s)` (acil durum için).
- [ ] `process_next_task()` içinde: kuyruktan en yüksek öncelikli görevi al (`top()`), eğer `required_state` mevcut duruma uymuyorsa görevi **reddet** (ekrana neden reddedildiğini yazdır) ve kuyruktan çıkar, uyuyorsa "görevi çalıştır" (ekrana yazdır) ve duruma göre state geçişi yap (örn. `MOVING` görevi bitince tekrar `IDLE`'a dön).
- [ ] `main()` içinde en az 6 farklı görev ekle (farklı önceliklerde, farklı `required_state` gereksinimleriyle) ve kuyruk boşalana kadar `process_next_task()` çağır.
- [ ] **Acil durdurma senaryosu ekle:** Kuyruğa "EMERGENCY_STOP" adında, her zaman en yüksek önceliğe sahip özel bir görev ekleyebilme (`add_emergency_task`) — bu görev geldiğinde state'i zorla `ERROR`'a çevirsin ve kuyruktaki **diğer tüm görevleri temizlesin** (`priority_queue`'yu boşaltmanın nasıl yapılacağını araştırman gerekecek — `pop()` ile döngü mü, yoksa başka bir yol mu?).

### Zorlaştırma
- [ ] Durum geçişlerini bir `std::map<RobotState, std::vector<RobotState>>` ile "hangi durumdan hangi duruma geçiş geçerli" şeklinde modelle ve geçersiz geçişleri engelle.
- [ ] Her durum değişikliğini zaman damgasıyla bir `.log` dosyasına yaz (Proje 1'deki dosya I/O bilgini burada tekrar kullan).

---

## Proje 4 — Çok Thread'li Sensör Füzyon Simülatörü

**Seviye:** İleri | **Süre tahmini:** 10-14 saat

### Ne inşa ediyorsun?
Proje 2'deki sensörleri **ayrı thread'lerde**, farklı frekanslarda (Hz) çalıştıran, verilerini **thread-safe** bir şekilde paylaşılan bir "durum" nesnesinde toplayan ve ana thread'de bu birleşik veriyi belirli aralıklarla loglayan bir sistem. Bu, gerçek bir ROS2/gömülü sistemin iç mimarisine en çok benzeyen proje.

### Kullanacağın konular ve neden bu proje bunları birleştiriyor
- **`std::thread` (Bölüm 14.1):** Her sensörü kendi bağımsız döngüsünde (kendi Hz'inde) çalıştırmak.
- **`chrono` (Bölüm 14.2):** Her thread'in kendi frekansını (örn. IMU 100Hz, sıcaklık 1Hz) korumasını sağlamak.
- **`shared_ptr` (Bölüm 13.2):** Sensör nesnelerini birden fazla thread arasında güvenle paylaşmak.
- **Struct + `enum class`:** Paylaşılan durumu (`RobotSharedState`) modellemek.
- **Exception handling:** Bir thread içinde oluşan hatanın tüm programı çökertmemesini sağlamak.
- **(Yeni, araştırman gereken konu) `std::mutex`:** Birden fazla thread aynı veriye aynı anda yazarsa **veri yarışı (data race)** oluşur — bunu önlemek için bir kilit (mutex) mekanizması öğrenmen gerekecek. Ders kitabında bu konu yoktu, bu bilinçli bir "sıçrama" — gerçek eşzamanlı sistemler yazmak için mutex kaçınılmazdır.

### TODO Listesi
- [ ] Proje 2'deki `Sensor` sınıf hiyerarşisini bu projeye taşı (veya yeniden yaz).
- [ ] `struct RobotSharedState { double last_distance; double last_temperature; double last_heading; std::mutex mtx; };` tanımla — **neden `mutex`'i struct'ın içine koyduğunu araştır ve anla.**
- [ ] Her sensör için ayrı bir thread fonksiyonu yaz, örn:
  ```cpp
  void distance_sensor_loop(RobotSharedState& state, std::atomic<bool>& running) {
      DistanceSensor sensor;
      while (running) {
          double value = sensor.read();
          {
              std::lock_guard<std::mutex> lock(state.mtx);
              state.last_distance = value;
          }
          std::this_thread::sleep_for(std::chrono::milliseconds(200)); // 5 Hz
      }
  }
  ```
  (Bu bilinçli olarak yarı çözülmüş bir örnek — `std::atomic<bool>` ve `std::lock_guard`'ı **araştırman** bekleniyor.)
- [ ] `main()` içinde 3 sensör için 3 ayrı thread başlat (`temperature`: 1Hz, `distance`: 5Hz, `imu`: 20Hz).
- [ ] Ana thread'de 1 saniyede bir, `mutex` ile korunan şekilde paylaşılan durumu oku ve ekrana yazdır ("sensör füzyonu" — farklı frekanslardaki verilerin tek bir anlık görüntüde birleştirilmesi).
- [ ] Programı 10 saniye çalıştır, sonra `running = false` yap ve tüm thread'leri `join()` ile düzgünce kapat.
- [ ] **Neden `mutex` olmadan bu program çalışırken "tuhaf" (yarış durumu kaynaklı) sonuçlar verebileceğini** kendi cümlelerinle README'ne yaz — bilerek `mutex`'i kaldırıp ne olduğunu gözlemleyerek dene (sonra geri ekle!).

### Zorlaştırma
- [ ] Proje 3'teki `RobotController`'ı bu sisteme entegre et — sensör verilerine göre otomatik state geçişleri tetikle (örn. mesafe < 0.3m ise otomatik `ERROR` durumuna geç).
- [ ] Basit bir hareketli ortalama (moving average) filtresi ekle — `deque` kullanarak son 5 IMU okumasının ortalamasını al, ham veri yerine bunu logla (Bölüm 11.1'deki `deque` bilgini burada kullan).

---

## Proje 5 — Şablonlu, Genel Amaçlı PID Kontrolcü Kütüphanesi

**Seviye:** İleri | **Süre tahmini:** 6-10 saat

### Ne inşa ediyorsun?
Herhangi bir sayısal tiple (`float`, `double`) çalışabilen, tekrar kullanılabilir bir PID (Proportional-Integral-Derivative) kontrolcü sınıfı — gerçek robotik kontrol teorisinin en temel yapı taşı. Bunu, hedef bir hıza ulaşmaya çalışan simüle edilmiş bir motor üzerinde test edeceksin.

### Kullanacağın konular ve neden bu proje bunları birleştiriyor
- **Şablon sınıflar (Bölüm 13.1):** `PidController<T>` — tip bağımsız kontrolcü.
- **Encapsulation:** Kp/Ki/Kd katsayıları `private`, ayarlamak için `public` setter'lar.
- **`chrono`:** Kontrol döngüsünün gerçek zamanlı `dt` (zaman adımı) değerini ölçmek — PID matematiği `dt`'ye dayanır.
- **Operatör aşırı yükleme (opsiyonel):** Kontrol çıktısını sınırlamak (`clamp`) için yardımcı fonksiyonlar.
- **`const` metotlar:** Durumu değiştirmeyen `get_error()` gibi metotlar için.
- **Dosya I/O + `iomanip`:** Simülasyon sonuçlarını (zaman, hedef, gerçek değer, hata) bir CSV'ye yazıp bir grafik programında (Excel, Python/matplotlib) görselleştirmek.

### TODO Listesi
- [ ] Teoriyi kısaca araştır: PID'nin **P** (mevcut hata), **I** (geçmiş hataların toplamı), **D** (hatanın değişim hızı) bileşenlerinin her birinin ne işe yaradığını anla — bunu README'ne 3-4 cümleyle kendi kelimelerinle özetle (bu, kod yazmadan önceki en önemli adım).
- [ ] Şablonlu sınıfı tanımla:
  ```cpp
  template <typename T>
  class PidController {
  public:
      PidController(T kp, T ki, T kd);
      T compute(T setpoint, T measured_value, T dt);
      void reset();
  private:
      T kp_, ki_, kd_;
      T integral_ = 0;
      T previous_error_ = 0;
  };
  ```
- [ ] `compute()` metodunu implemente et: `error = setpoint - measured_value`; `integral_ += error * dt`; `derivative = (error - previous_error_) / dt`; çıktı `kp_*error + ki_*integral_ + kd_*derivative`.
- [ ] Basit bir "sahte motor" simülasyonu yaz: `SimulatedMotor` sınıfı, `apply_control(double control_signal, double dt)` metoduyla kendi hızını güncellesin (basit bir fizik modeli — örn. `velocity += (control_signal - friction * velocity) * dt`).
- [ ] `main()` içinde: hedef hızı `10.0 m/s` olarak belirle, 500 adımlık bir döngüde her adımda PID'nin `compute()` çıktısını motora uygula, motorun gerçek hızını PID'ye geri besle (feedback loop).
- [ ] Her adımın sonucunu (`step, time, target, actual, error`) bir CSV dosyasına yaz.
- [ ] Farklı Kp/Ki/Kd değerleriyle (en az 3 farklı kombinasyon) simülasyonu tekrar çalıştır, sonuçları karşılaştır — hangi kombinasyon daha hızlı/daha az salınımla (overshoot) hedefe ulaşıyor?

### Zorlaştırma
- [ ] Kontrol çıktısına bir üst/alt sınır (saturation) ekle — gerçek motorların sonsuz güç uygulayamayacağını simüle et (`std::clamp` kullanmayı araştır, C++17'de standart kütüphanede var).
- [ ] `PidController<float>` ve `PidController<double>` versiyonlarını aynı simülasyonda çalıştırıp sonuçları karşılaştır — hassasiyet farkı gerçekten gözle görülür bir fark yaratıyor mu?

---

## Genel Öneriler: Bu Projelerden Sonra Ne Yapmalısın?

- **ROS2 öğrenmeye başla.** Proje 2, 3 ve 4'te kurduğun mantık (sınıf hiyerarşileri, `shared_ptr` mesajlar, thread'ler/callback'ler, durum makineleri) doğrudan ROS2'nin `rclcpp` API'sine haritalanır — bu projeleri bitirmiş olman, ROS2'yi öğrenirken "neden böyle tasarlanmış" sorusuna zaten cevap sahibi olman anlamına gelir.
- **Gerçek bir mikrodenetleyiciyle (ESP32) entegre et.** Proje 1 ve 2'deki "sahte sensör" fonksiyonlarını, gerçek bir ESP32 üzerinden seri port ile okunan gerçek sensör verisiyle değiştirmeyi dene — bu, simülasyon ile gerçek donanım arasındaki farkı (gürültü, gecikme, bağlantı kopmaları) elle deneyimlemeni sağlar.
- **Kod incelemesi (code review) alışkanlığı edin.** Her projeyi bitirdiğinde, kodunu bana (veya bir başka geliştiriciye) gösterip "bunu nasıl daha iyi yapardım?" diye sor — özellikle bellek yönetimi ve hata yönetimi konularında geri bildirim almak çok değerlidir.
- **`-Wall -Wextra -Wpedantic` ile derlemeyi alışkanlık haline getir**, hatta `clang-tidy` gibi statik analiz araçlarını dene — profesyonel robotik kod tabanlarının hemen hepsi bu tür sıkı derleme/analiz kurallarıyla çalışır.
