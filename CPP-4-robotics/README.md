# C++ ile Robotik Programlama --- Ders Kitabı

> Bu doküman, bir robotik bootcamp'i sırasında yazılan 65 örnek koddan
> derlenmiştir. Amaç sadece "syntax ezberlemek" değil, her bir C++
> özelliğinin **gerçek bir robot yazılımında (ROS2 node'u, motor
> sürücüsü, sensör okuma döngüsü, path planner, vs.) neden ve nasıl
> kullanıldığını** kavramaktır.

## 🎯 Gerçekten Bilmen Gereken Konular (Öncelik Sırasına Göre)

Kursun tamamı önemli, ama zamanın kısıtlıysa aşağıdaki konulara
**mutlaka** hakim olmalısın --- bunlar gerçek robotik kod tabanlarında
(özellikle ROS2/rclcpp) her gün karşına çıkar:

1.  **Pointers & Referanslar (Bölüm 8)** --- Sensör verisi, bellek
    yönetimi, fonksiyonlara büyük veri geçirme; ROS2'nin `shared_ptr`
    tabanlı mesaj sistemi buna dayanır.
2.  **Smart Pointers --- `unique_ptr` / `shared_ptr` (Bölüm 13.2)** ---
    Modern C++ robotik kodunda çıplak `new`/`delete` neredeyse hiç
    kullanılmaz; ROS2 mesajları, node handle'ları hep smart pointer.
3.  **Sınıflar, Encapsulation, Constructor/Destructor (Bölüm 9)** ---
    Her sensör, her aktüatör, her ROS2 node'u bir sınıftır.
4.  **Polymorphism & Virtual Fonksiyonlar (Bölüm 10)** --- Farklı
    sensör/aktüatör tiplerini ortak bir arayüzden yönetmek (plugin
    mimarileri, ROS2 hardware interface'leri) buna dayanır.
5.  **STL Container'lar --- `vector`, `map`, `queue`, `priority_queue`
    (Bölüm 11-12)** --- Sensör buffer'ları, waypoint listeleri, görev
    kuyrukları, path planning (Dijkstra/A\*) hep bunlarla yazılır.
6.  **Struct'lar ve Enum Class (Bölüm 7.1, 12.6)** --- Robot state
    machine'leri, sensör veri paketleri, ROS2 mesaj tipleri bunlarla
    modellenir.
7.  **Threads & Chrono (Bölüm 14)** --- Gerçek zamanlı robotik
    sistemlerde sensör okuma, kontrol döngüsü ve iletişim genelde ayrı
    thread'lerde çalışır; zamanlama (`chrono`) kontrol döngüsü frekansı
    (Hz) için kritik.
8.  **Exception Handling (Bölüm 8.4)** --- Donanım hatalarını (sensör
    bağlantısı koptu, bölme hatası) güvenli şekilde yönetmek için.
9.  **Templates (Bölüm 13.1)** --- Tip bağımsız, tekrar kullanılabilir
    robotik kütüphaneler (örn. herhangi bir sayı tipiyle çalışan bir
    `PID` sınıfı) yazmak için.
10. **Değişken/Sabit Tipleri ve Type Casting (Bölüm 2, 4)** --- Sensör
    ADC değerlerini voltaja çevirmek, encoder tick'lerini mesafeye
    çevirmek gibi *her robotik projede* karşına çıkan dönüşümler için.

Geri kalan konular (I/O, string işlemleri, döngüler, operatör overload,
dosya işlemleri, random sayılar) bu temellerin üzerine binen, günlük
kullanımda sık ihtiyaç duyacağın pratik araçlardır --- bunları da
atlamadan oku, ama önceliğin yukarıdaki 10 madde olsun.

------------------------------------------------------------------------

## İçindekiler

1.  [Giriş: Neden C++ ve Temel Çıktı](#1-giriş-neden-cnn-ve-temel-çıktı)
2.  [Değişkenler, Veri Tipleri ve
    Sabitler](#2-değişkenler-veri-tipleri-ve-sabitler)
3.  [Girdi/Çıktı (I/O) Yöntemleri](#3-girdiçıktı-io-yöntemleri)
4.  [Tip Dönüşümü (Type Casting)](#4-tip-dönüşümü-type-casting)
5.  [Kontrol Akışı: Koşullar ve
    Döngüler](#5-kontrol-akışı-koşullar-ve-döngüler)
6.  [Fonksiyonlar](#6-fonksiyonlar)
7.  [Veri Yapıları: Dizi, Vektör, String,
    Struct](#7-veri-yapıları-dizi-vektör-string-struct)
8.  [Bellek Yönetimi: Pointer, Exception, Manuel
    Yönetim](#8-bellek-yönetimi-pointer-exception-manuel-yönetim)
9.  [Nesne Yönelimli Programlama (OOP) ---
    Temeller](#9-nesne-yönelimli-programlama-oop--temeller)
10. [OOP --- İleri Seviye: Kalıtım ve
    Polymorphism](#10-oop--i̇leri-seviye-kalıtım-ve-polymorphism)
11. [STL Sıralı Konteynerlar](#11-stl-sıralı-konteynerlar)
12. [STL İlişkisel Konteynerlar ve
    Adaptörler](#12-stl-i̇lişkisel-konteynerlar-ve-adaptörler)
13. [Şablonlar (Templates) ve Modern Bellek
    Yönetimi](#13-şablonlar-templates-ve-modern-bellek-yönetimi)
14. [Eşzamanlılık: Threads ve
    Zamanlama](#14-eşzamanlılık-threads-ve-zamanlama)
15. [Dosya İşlemleri ve Rastgele
    Sayılar](#15-dosya-i̇şlemleri-ve-rastgele-sayılar)
16. [Doküman Standardı: Doxygen](#16-doküman-standardı-doxygen)

------------------------------------------------------------------------

## 1. Giriş: Neden C++ ve Temel Çıktı

### 1.1 Neden Robotikte C++?

Python okunması kolay ve hızlı prototipleme için harikadır, ama gerçek
zamanlı robotik sistemler (motor kontrol döngüleri, sensör füzyonu, path
planning) **milisaniyeler** cinsinden çalışmak zorundadır. C++, donanıma
yakın bellek kontrolü ve düşük gecikme (low-latency) sağladığı için
ROS2'nin çekirdeği (`rclcpp`), gerçek robot sürücüleri ve gömülü
sistemler (ESP32, mikrodenetleyiciler) hâlâ ağırlıklı olarak C++ ile
yazılır.

### 1.2 `#include`, `main()` ve `std::cout`

``` cpp
#include <iostream>

int main() {
    std::cout << "Hello, Automatic Addison!" << std::endl;
    return 0;
}
```

**Neden böyle?** - `#include <iostream>` derleyiciye "giriş/çıkış
(input/output) araçlarını kullanacağım" der. C++'ta hiçbir şey "otomatik
olarak" gelmez --- ihtiyacın olan her kütüphaneyi açıkça dahil edersin.
Bu, derleme süresini ve binary boyutunu küçük tutar; gömülü sistemlerde
(ESP32 gibi kısıtlı flash/RAM'e sahip donanımlarda) bu çok önemlidir. -
`int main()` her C++ programının **giriş noktasıdır**; işletim sistemi
programı çalıştırdığında ilk çağrılan fonksiyon budur. - `std::cout`
("character output") standart çıktı akışına (genelde terminal ekranına)
veri yazar. `<<` operatörü "bunu akışa gönder" anlamına gelir. -
`std::endl` satırı bitirir **ve** çıktı tamponunu (buffer) hemen
diske/ekrana boşaltır (flush). Bu, `\n` karakterinden daha "pahalıdır"
çünkü flush işlemi bir sistem çağrısıdır. - `return 0;` işletim
sistemine "program hatasız bitti" der. Sıfırdan farklı bir değer hata
kodunu ifade eder --- bu, bir robot kontrol scriptinin başka bir script
tarafından çağrıldığında başarı/başarısızlık kontrolü için kritiktir.

**Gerçek robotik projede nerede karşına çıkar?** Her ROS2 node'unun bir
`main()` fonksiyonu vardır; node başlatma, hata loglama (`RCLCPP_INFO`,
aslında `std::cout`'un ROS2'deki karşılığıdır) hep bu mantığın üzerine
kuruludur.

### 1.3 `using namespace std;` --- Kullanmalı mısın?

``` cpp
using namespace std;
string robot_name = "AutomaticAddisonBot";
```

**Teori:** C++ standart kütüphanesinin tüm isimleri (`cout`, `string`,
`vector`...) `std` adlı bir *namespace* (isim alanı) içinde tanımlıdır.
Bunu yapmasaydık, kendi yazdığın bir `string` sınıfıyla standart
kütüphanenin `string`'i çakışabilirdi. `using namespace std;` bu öneki
(`std::`) her seferinde yazmaktan kurtarır.

**Neden dikkatli olmalısın?** Büyük robotik projelerde (özellikle birden
fazla kütüphane --- Eigen, ROS2, PCL --- bir araya geldiğinde)
`using namespace std;` isim çakışmalarına (`ambiguous symbol`
hatalarına) yol açabilir. Bu yüzden gerçek projelerde genelde ya `std::`
öneki her yerde açıkça yazılır ya da `using namespace std;` sadece
`.cpp` dosyalarının içinde (asla `.hpp` header dosyalarında) kullanılır
--- çünkü header dosyasına yazılan `using namespace` onu include eden
**her dosyayı** etkiler.

### 1.4 Yorumlar (Comments)

``` cpp
double speed = 0.5; // speed of the robot in meters per second
/* Calculate the distance traveled
   distance = speed * time */
double distance = speed * time;
```

**Neden önemli?** Robotik kodda birimler (`m/s`, `rad`, `mm`) genelde
değişken isminden anlaşılmaz; yorumlar bu birimleri ve formülün fiziksel
anlamını belgeler. Altı ay sonra kendi kodunu okurken (ya da bir takım
arkadaşın okurken) `speed = 0.5` tek başına hiçbir şey ifade etmez ama
`// m/s cinsinden hız` çok şey ifade eder. `//` tek satır, `/* ... */`
çok satırlı yorum için kullanılır.

### 1.5 Program Argümanları --- `argc`, `argv`

``` cpp
int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; ++i) {
        std::cout << i << ":" << argv[i] << std::endl;
    }
}
```

**Teori:** `argc` (argument count) programa kaç parametre geçildiğini,
`argv` (argument vector) bu parametrelerin metin (C-string) dizisini
tutar. `argv[0]` her zaman programın kendi adıdır.

**Neden gerekli?** ROS2 launch dosyaları node'lara komut satırından
parametre geçer
(`ros2 run my_robot my_node --ros-args -p max_speed:=2.0`); bu
parametreler alt seviyede tam olarak `argc`/`argv` mekanizmasıyla
programa ulaşır. Kendi robot kontrol programını terminalden farklı
ayarlarla (`./robot_controller --port /dev/ttyUSB0`) çalıştırmak
istediğinde bu bilgiye ihtiyacın olur.

------------------------------------------------------------------------

## 2. Değişkenler, Veri Tipleri ve Sabitler

### 2.1 Temel Veri Tipleri

``` cpp
int distance = 100;      // Distance in centimeters
float speed = 5.5;       // Speed in meters per second
char direction = 'N';    // Direction as a cardinal point
bool is_active = true;   // Status of the robot's motor
```

  -----------------------------------------------------------------------
  Tip                                 Ne için kullanılır (robotikte)
  ----------------------------------- -----------------------------------
  `int`                               Encoder tick sayısı, döngü
                                      sayaçları, ID'ler

  `float` / `double`                  Sensör okumaları, hız, açı, mesafe
                                      (double daha hassas, çoğu robotik
                                      matematik kütüphanesi --- Eigen ---
                                      double kullanır)

  `char`                              Tek karakterlik komutlar (`'F'` =
                                      ileri, `'L'` = sola dön), seri port
                                      protokol byte'ları

  `bool`                              Sensör tetiklenme durumu, motor
                                      aktif/pasif, hata bayrakları

  `std::string`                       Robot ismi, log mesajları, seri
                                      porttan gelen komut metinleri
  -----------------------------------------------------------------------

**Neden `float` yerine çoğu yerde `double` görüyorsun?** `float` 32-bit,
`double` 64-bit hassasiyet sunar. Kısa mesafe hesaplarında fark etmez
ama SLAM (eş zamanlı konumlama ve haritalama) gibi birikimli hata
biriktiren hesaplamalarda `float` kullanmak, yüzlerce iterasyon sonra
ciddi konum sapmalarına (drift) yol açabilir --- bu yüzden Eigen ve ROS2
mesajları genelde `double` kullanır.

### 2.2 Sabitler (`const`)

``` cpp
const float MAX_SPEED = 5.0;
```

**Teori:** `const` anahtar kelimesi, değerin program boyunca
**değiştirilemeyeceğini** derleyiciye söyler. Eğer kodun bir yerinde
yanlışlıkla `MAX_SPEED = 10.0;` yazarsan, program çalışmadan önce
**derleme hatası** alırsın --- bu, çalışma zamanında (runtime) fark
edilmesi çok daha tehlikeli olacak bir hatayı en baştan engeller.

**Neden robotikte kritik?** `MAX_SPEED`, `MAX_TORQUE`, `SAFETY_DISTANCE`
gibi güvenlik sınırları neredeyse her zaman `const` (ya da `constexpr`)
olarak tanımlanır. Bir robot kolunun maksimum hızını yanlışlıkla
runtime'da değiştirebilen bir kod, donanımı veya bir insanı
yaralayabilir. `const` burada bir **güvenlik mekanizmasıdır**, sadece
bir stil tercihi değil.

### 2.3 Global Değişkenler ve `static` Yerel Değişkenler

``` cpp
bool sensor_triggered = false;   // global
void check_sensor() { sensor_triggered = true; }
```

``` cpp
void increment_counter() {
    static int count = 0;   // sadece ilk çağrıda 0'a eşitlenir
    count++;
    std::cout << "Counter: " << count << std::endl;
}
```

**Teori:** Global değişkenler tüm fonksiyonlardan erişilebilir ---
pratik ama tehlikelidir çünkü hangi fonksiyonun ne zaman değiştirdiğini
takip etmek zorlaşır (büyük projelerde "spagetti state" sorunu).
`static` yerel değişken ise fonksiyona özeldir ama **fonksiyon çağrıları
arasında değerini korur** --- normal yerel değişkenler her çağrıda
sıfırdan başlarken, `static` olanı "hafızası olan" bir değişkendir.

**Gerçek robotik örnek:** Bir sensör kesme (interrupt) fonksiyonunda "bu
sensör kaç kez tetiklendi" sayacı tutmak için `static int trigger_count`
kullanılır --- global değişkenden daha güvenlidir çünkü sadece o
fonksiyonun kapsamında (scope) yaşar, başka kod yanlışlıkla erişip
bozamaz.

### 2.4 `auto` Anahtar Kelimesi

``` cpp
for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) { ... }
for (auto it = numbers.begin(); it != numbers.end(); ++it) { ... }
```

**Teori:** `auto`, derleyiciye "bu değişkenin tipini ifadenin sağ
tarafından kendin çıkar" der. `std::vector<int>::iterator` gibi uzun ve
karmaşık tip isimlerini elle yazmak yerine `auto` kullanmak kodu
okunabilir kılar.

**Neden önemli?** Modern C++ robotik kodunda (özellikle ROS2, Eigen gibi
şablon-ağırlıklı kütüphanelerle çalışırken) tip isimleri bazen 3-4 satır
uzunluğunda olabilir
(`std::shared_ptr<const sensor_msgs::msg::LaserScan>` gibi). `auto` bu
karmaşıklığı gizler ve kodun "ne yaptığına" odaklanmanı sağlar; ama
dikkat --- tipi tam olarak bilmen gerektiğinde (örn. bir fonksiyona
doğru referans/pointer tipi geçerken) `auto`'ya körü körüne
güvenmemelisin.

------------------------------------------------------------------------

## 3. Girdi/Çıktı (I/O) Yöntemleri

### 3.1 `std::cout` ile Biçimlendirme --- `iomanip`

``` cpp
std::cout << std::fixed << std::setprecision(2);
std::cout << "Precision set to 2 decimal places: " << battery_voltage << std::endl;
```

**Teori:** `double`/`float` değerler varsayılan olarak C++'ta genelde 6
anlamlı basamakla yazdırılır. `std::fixed` ondalık gösterime zorlar,
`std::setprecision(n)` ondalık basamak sayısını belirler.

**Neden gerekli?** Bir batarya voltajını `12.734234234` olarak loglamak
okunabilirliği bozar ve gereksiz gürültü (noise) yaratır; robotik
loglarında/dashboard'larda değerleri anlamlı hassasiyette (`12.73 V`)
göstermek hem okunabilirlik hem de log dosyası boyutu açısından
önemlidir.

### 3.2 `printf` ile C-Tarzı Çıktı

``` cpp
printf("Battery level: %.2f%%\n", battery_percentage);
```

**Teori:** `printf`, C'den miras kalan biçimlendirilmiş çıktı
fonksiyonudur. `%s` string, `%.2f` 2 ondalık basamaklı float, `%d`
integer içindir.

**Neden hâlâ görürsün?** Gömülü sistemlerde (ESP32/Arduino,
mikrodenetleyici firmware'i) `iostream`'in getirdiği ek bellek yükü
(binary boyutu, heap kullanımı) `printf`'ten çok daha fazladır. Kısıtlı
RAM'e sahip bir mikrodenetleyicide `printf` (veya onun gömülü
versiyonları) tercih edilir. `std::cout` masaüstü/Linux tabanlı robotik
yazılımda (ROS2 node'ları gibi) daha yaygındır.

### 3.3 Girdi Alma --- `std::cin` ve Hata Kontrolü

``` cpp
double speed;
std::cin >> speed;
if (!std::cin) {
    std::cerr << "Error: Please enter a valid number for the speed." << std::endl;
    return 1;
}
```

**Teori:** `std::cin >> speed` kullanıcıdan (ya da bir seri
porttan/pipe'tan) veri okur. Eğer okunan veri beklenen tipe (burada
`double`) uymuyorsa, `std::cin` bir "hata durumuna" (fail state) geçer
ve `if (!std::cin)` bunu tespit eder.

**Neden kritik?** Bir robot kontrol arayüzünde kullanıcı yanlışlıkla
"abc" yazarsa ve sen bunu kontrol etmezsen, `speed` tanımsız/çöp bir
değer alabilir ve robot beklenmedik davranış sergileyebilir. Girdi
doğrulaması (input validation), donanımla etkileşen her sistemde
güvenlik açısından zorunludur.

### 3.4 `std::getline` --- Boşluklu Metin Okuma

``` cpp
std::string command;
std::getline(std::cin, command);
```

**Teori:** `std::cin >> variable` sadece **boşluğa kadar** okur; "move
forward" gibi boşluk içeren bir komutu okumak için `std::getline`
gerekir --- bu, tüm satırı (boşluklar dahil) okur.

**Robotik örnek:** Bir robotun seri port üzerinden aldığı komut
satırları (`"MOVE 10 20"`, `"ROTATE 90"`) genelde `getline` ile satır
satır okunup sonra ayrıştırılır (parse edilir).

### 3.5 `std::stringstream` --- Metin ↔ Sayı Dönüşümü ve Birleştirme

``` cpp
std::stringstream ss;
ss << "Motor Speed: " << motor_speed << " RPM, Battery Level: " << battery_level << " Volts";
std::string log_entry = ss.str();
```

**Teori:** `stringstream`, bir string'i tıpkı `cout`/`cin` gibi bir akış
(stream) olarak ele almanı sağlar --- hem yazma (`<<`) hem okuma (`>>`)
yapabilirsin.

**Neden robotikte çok kullanılır?** İki temel senaryo: (1) Farklı
tiplerdeki verileri (sayı + metin) **tek bir log/mesaj string'inde**
birleştirmek (yukarıdaki örnek), (2) Seri porttan gelen `"100,25.5,F"`
gibi bir veri satırını parçalara ayırıp
(`ss >> motor_speed >> comma >> battery >> ...`) sayısal değerlere
çevirmek. ROS2'de mesaj serileştirme/loglama sırasında bu desen sürekli
karşına çıkar.

------------------------------------------------------------------------

## 4. Tip Dönüşümü (Type Casting)

``` cpp
int sensor_value = 527;
double voltage;

voltage = sensor_value * 5.0 / 1023;                          // implicit casting
voltage = (double)sensor_value * 5.0 / 1023;                  // C-style casting
voltage = static_cast<double>(sensor_value) * 5.0 / 1023;     // C++ style casting
```

**Teori:** Bir ADC'den (Analog-Dijital Çevirici) okunan ham değer
(`sensor_value`, genelde 0-1023 arası bir tam sayı) doğrudan bir voltaj
değildir; onu gerçek voltaja çevirmek için ölçekleme (scaling) gerekir.
Eğer `sensor_value / 1023` işlemini `int` olarak yaparsan (tip dönüşümü
yapmadan), C++ **tam sayı bölmesi** (integer division) yapar ve ondalık
kısmı tamamen keser --- sonuç her zaman `0` ya da `1` çıkar, asla
`0.515` gibi bir değer çıkmaz. Bu, robotik/gömülü sistemlerde **en sık
yapılan hatalardan biridir**.

**Neden `static_cast` tercih edilmeli, C-style `(double)` değil?**
`static_cast<double>(x)` derleme zamanında tip güvenliğini kontrol eder
ve niyetini kod okuyana açıkça belirtir ("bunu bilerek dönüştürüyorum").
C-style cast (`(double)x`) daha "kaba"dır, yanlış tipte bir pointer'ı
bile sessizce zorlayabilir ve hataları gizleyebilir. Modern C++ stil
rehberlerinin (Google C++ Style Guide dahil) hepsi
`static_cast`/`dynamic_cast`/`reinterpret_cast` kullanmayı önerir.

**Gerçek robotik örnek:** Bir potansiyometreden veya IR mesafe
sensöründen okunan ham ADC değerini gerçek mesafeye (cm) veya voltaja
çevirmek, hemen hemen her gömülü robotik projesinde ilk yazılan koddur.

------------------------------------------------------------------------

## 5. Kontrol Akışı: Koşullar ve Döngüler

### 5.1 `if / else if / else`

``` cpp
if (battery_level > 0.5 && !obstacle_detected) {
    std::cout << "Robot is moving forward." << std::endl;
} else if (battery_level > 0.5 && obstacle_detected) {
    std::cout << "Robot is avoiding the obstacle." << std::endl;
} else {
    std::cout << "Robot is stopping due to low battery." << std::endl;
}
```

**Teori:** `&&` (VE) ve `||` (VEYA) mantıksal operatörleri birden fazla
koşulu birleştirmeni sağlar. `!` (DEĞİL) bir booleanı tersine çevirir.

**Neden robotikte temel taşı?** Bu yapı, aslında basit bir **karar
mekanizmasının (decision-making) çekirdeğidir**. Gerçek robotlarda
"davranış ağaçları" (behavior trees) ve "durum makineleri" (state
machines) sonuçta bu if/else mantığının daha organize edilmiş
halleridir. Engelden kaçınma, batarya yönetimi, güvenlik durdurmaları
hep bu tür koşullu mantıkla başlar.

### 5.2 Ternary (Üçlü) Operatör

``` cpp
std::string battery_status = (battery_level > battery_treshold) ? "Sufficient" : "Low";
```

**Teori:** `koşul ? değer_doğruysa : değer_yanlışsa` --- tek satırlık
if/else'in kısa yazımıdır.

**Neden kullanılır?** Basit, tek satırlık atamalarda kodu kısaltır ve
okunabilirliği artırır (özellikle log mesajlarında `"Yes" : "No"` gibi).
Ama karmaşık mantık için (birden fazla koşul iç içe) if/else'e geri
dönmek daha okunabilir olur --- ternary'yi zincirlemek
(`a ? b : c ? d : e`) kodu okunamaz hale getirebilir, kaçınılmalıdır.

### 5.3 `for`, `while`, `do-while` Döngüleri

``` cpp
for (int i = 0; i < 5; i++) { ... }             // kaç kez çalışacağı önceden belli

while (distance < target_distance) { ... }       // koşul sağlandığı sürece, sayısı belirsiz

do { ... } while (count < 3);                    // en az 1 kez çalışır, sonra koşulu kontrol eder
```

**Ne zaman hangisi?** - **`for`**: Bilinen sayıda tekrar --- örn. bir
sensör dizisindeki 8 sensörü sırayla okumak. - **`while`**: Bilinmeyen
sayıda tekrar, bir koşula bağlı --- örn. "hedef mesafeye ulaşana kadar
hareket et". - **`do-while`**: En az bir kez çalışması **garanti**
olması gereken durumlar --- örn. bir sensörü ilk kez okuyup **sonra**
"değer stabil mi?" diye kontrol etmek (önce oku, sonra karar ver).

**Robotik örnek:** Bir motor kontrol döngüsü genelde
`while (robot_is_running)` şeklinde sonsuz bir döngüdür (ROS2'de bu
`rclcpp::spin()` içinde gizlenir); PID kontrol algoritmaları da her
döngü adımında (`for`/`while` ile) hatayı hesaplayıp motor komutunu
günceller.

### 5.4 `break` ve `continue`

``` cpp
if (distance[i] > max_distance) {
    std::cout << "Distance exceeds maximum limit. Stopping robot." << std::endl;
    break;      // döngüyü tamamen sonlandırır
}
if (distance[i] < 10) {
    std::cout << "Distance too short. Skipping iteration." << std::endl;
    continue;   // bu iterasyonu atla, döngüye devam et
}
```

**Neden önemli?** `break`, bir **güvenlik durdurma (emergency stop)**
senaryosunun kod karşılığıdır --- "bir tehlike sinyali algıladım,
döngüyü/işlemi hemen durdur". `continue` ise "bu veri noktası
geçersiz/anlamsız, işleme almadan bir sonrakine geç" mantığıdır ---
örneğin gürültülü (noisy) bir sensör okumasını atlayıp devam etmek için
kullanılır.

------------------------------------------------------------------------

## 6. Fonksiyonlar

### 6.1 Fonksiyon Bildirimi, Tanımı ve Çağrısı

``` cpp
double calculate_distance(double x1, double y1, double x2, double y2); // bildirim (declaration)

int main() {
    double distance = calculate_distance(0, 0, 3, 4); // çağrı
}

double calculate_distance(double x1, double y1, double x2, double y2) { // tanım (definition)
    double dx = x2 - x1;
    double dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}
```

**Teori:** Fonksiyon **bildirimi** (declaration/prototype) derleyiciye
"bu isimde, bu parametrelerle, bu dönüş tipiyle bir fonksiyon var,
tanımını sonra göreceksin" der; bu, `main()`'in fonksiyonu, tanımından
önce çağırabilmesini sağlar.

**Neden önemli?** Fonksiyonlara ayırma (decomposition), robotik kodda
**tekrar kullanılabilirliğin** temelidir. `calculate_distance`
fonksiyonu, iki robot arasındaki mesafe, bir robotun hedefe olan
uzaklığı, bir engelin robota uzaklığı gibi onlarca farklı yerde tekrar
tekrar çağrılabilir --- kodu kopyalayıp yapıştırmak yerine.

### 6.2 Fonksiyon Aşırı Yükleme (Overloading)

``` cpp
void move_robot(int distance);
void move_robot(int x, int y);
```

**Teori:** Aynı isimde, farklı parametre listelerine sahip birden fazla
fonksiyon tanımlanabilir; derleyici çağrı sırasında verilen argümanlara
bakarak **doğru olanı otomatik seçer**.

**Neden robotikte kullanışlı?** `move_robot(10)` "10 birim ileri git",
`move_robot(5, 7)` "(5,7) koordinatına git" --- kullanıcı/geliştirici
için sezgisel bir API sunar; her farklı davranış için farklı isimler
uydurmak (`move_forward`, `move_to_coordinate`) yerine tek, tutarlı bir
isim (`move_robot`) altında toplanır.

------------------------------------------------------------------------

## 7. Veri Yapıları: Dizi, Vektör, String, Struct

### 7.1 Diziler (Arrays)

``` cpp
const int size = 5;
int sensor_readings[size];
for (int i = 0; i < size; i++) sensor_readings[i] = i * 10;
```

**Teori:** Dizi, **sabit boyutlu**, bellek üzerinde art arda
(contiguous) yer kaplayan aynı tipteki elemanların koleksiyonudur.
Boyutu derleme zamanında bellidir ve çalışma zamanında değiştirilemez.

**Neden robotikte hâlâ kullanılır?** 8 IR sensörden oluşan sabit bir
sensör dizisi gibi, eleman sayısının **asla değişmeyeceği** durumlarda
diziler `vector`'dan daha hızlıdır (heap tahsisi yoktur, önbellek
(cache) dostudur) --- gerçek zamanlı, düşük gecikmeli gömülü sistemlerde
bu fark önemlidir.

### 7.2 Vektörler (`std::vector`)

``` cpp
std::vector<int> motor_speeds;
motor_speeds.push_back(100);
motor_speeds.push_back(200);
```

**Teori:** `vector`, **dinamik boyutlu** bir dizidir --- eleman
ekledikçe (`push_back`) otomatik olarak büyür, gerektiğinde belleği
kendisi yönetir (RAM'de yeni bir blok ayırıp eski verileri kopyalar).

**Neden vector, dizi yerine varsayılan tercih olmalı?** Robot çalışırken
kaç tane engel algılanacağı, kaç tane waypoint (rota noktası) olacağı
genelde **önceden bilinmez**. `vector`, bu belirsizliği güvenli ve
otomatik bellek yönetimiyle çözer. ROS2 mesajlarındaki dizi alanları
(`float64[] positions` gibi) C++ tarafında hep `std::vector` olarak
temsil edilir.

### 7.3 Stringler

``` cpp
std::string robot_name = "AutomaticAddisonBot";
robot_name[8] = '-';                              // karakter değiştirme
std::string full_name = robot_name + " " + model; // birleştirme (concatenation)
```

**Teori:** `std::string`, C'deki ham `char[]` dizilerinin aksine kendi
boyutunu bilir, otomatik büyür/küçülür ve `+` operatörüyle
birleştirilebilir --- bellek yönetimini senin yerine yapar.

**Robotik örnek:** Robot isimleri, log mesajları, ROS2 topic/servis
isimleri, seri port üzerinden gelen komut metinleri hep `std::string`
ile temsil edilir.

### 7.4 Karakter Fonksiyonları (`<cctype>`) --- ve Klasik Bir Hata

``` cpp
if (islower(command)) { ... }
char uppercase_command = toupper(command);

if (command = 'f') { ... }   // ⚠️ HATA: atama yaptı, karşılaştırma yapmadı!
```

**Teori:** `islower`, `isupper`, `toupper`, `tolower` gibi fonksiyonlar
tek karakterler üzerinde çalışır --- seri porttan gelen tek karakterlik
komutları (`'f'`, `'F'`, `'l'`, `'L'`) normalize etmek (büyük/küçük harf
farkını ortadan kaldırmak) için kullanışlıdır.

**⚠️ Kritik uyarı --- bu kod tabanındaki gerçek bir hata:**
`if (command = 'f')` yazımı, `command == 'f'` (karşılaştırma) yerine
yanlışlıkla `command = 'f'` (atama) yapar! Bu satır her zaman `true`
döner (çünkü atamanın sonucu atanan değerdir ve `'f'` sıfır olmayan bir
değerdir) **ve** `command` değişkeninin değerini sessizce değiştirir.
Bu, C/C++'ta **en sık yapılan ve en tehlikeli hatalardan biridir** ---
bir robot komut yorumlayıcısında bu hata, robotun yanlış komutu "doğru"
sanıp çalıştırmasına yol açabilir. Çözüm: karşılaştırma için her zaman
`==` kullan; bazı ekipler bu hatayı derleme zamanında yakalamak için
`'f' == command` (sabiti solda yazmak --- "Yoda koşulu") stilini tercih
eder, çünkü `'f' = command` derleme hatası verir.

### 7.5 Matematik Fonksiyonları (`<cmath>`)

``` cpp
double radians = angle * M_PI / 180.0;
double sine = sin(radians);
double cosine = cos(radians);
```

**Robotik örnek:** Açı hesapları robotik matematiğinin (kinematik, IMU
açı okuma, yön vektörleri) merkezindedir. `sin`/`cos`, bir robotun
yönelimine (heading) göre x/y hız bileşenlerini hesaplamak, bir robot
kolunun eklem açılarından uç nokta konumunu bulmak (forward kinematics)
gibi hesaplamalarda sürekli kullanılır. Derecelerin (`45.0`) her zaman
radyana çevrilmesi gerektiğini unutma --- C++ trigonometri fonksiyonları
radyan bekler.

### 7.6 Struct'lar

``` cpp
struct RobotSpec {
    std::string model;
    int max_speed;
    double weight;
};
RobotSpec robot = {"MobileBot", 5, 10.5};
```

**Teori:** `struct`, ilişkili verileri **tek bir mantıksal birim**
altında gruplamanın en basit yoludur. C++'ta `struct` ile `class`
arasındaki tek teknik fark varsayılan erişim seviyesidir (`struct`
varsayılan `public`, `class` varsayılan `private`) --- ama geleneksel
olarak `struct` **sadece veri** (davranış/metot olmadan) için, `class`
ise veri + davranış için kullanılır.

**Neden robotikte çok yaygın?** Bir sensör okuması genelde birden fazla
alan içerir (`{timestamp, x, y, z}` gibi bir IMU okuması). Bunları ayrı
ayrı değişkenler yerine tek bir `struct` (veya ROS2'de bir "mesaj tipi")
olarak taşımak, fonksiyonlara veri geçirmeyi çok daha temiz hale getirir
--- `send_data(x, y, z, timestamp)` yerine `send_data(imu_reading)`.

------------------------------------------------------------------------

## 8. Bellek Yönetimi: Pointer, Exception, Manuel Yönetim

### 8.1 Pointer'lar --- Neden Var, Nasıl Çalışır

``` cpp
int robot_id = 42;
int* ptr = &robot_id;      // & : "adresini al"
std::cout << *ptr;          // * : "adresteki değeri getir (dereference)"
*ptr = 99;                  // adresteki değeri değiştir → robot_id de değişir!
```

**Teori:** Her değişken bellekte bir yerde durur ve bir **adrese**
sahiptir. Bir pointer, değeri **doğrudan tutmaz**, o değerin bellekteki
adresini tutar. `&x` "x'in adresini ver", `*ptr` "bu adresteki değeri
getir/değiştir" demektir.

**Neden robotikte hayati?** İki temel sebep: 1. **Verimlilik**: Büyük
bir sensör verisi (örn. bir kamera görüntüsü, bir nokta bulutu)
fonksiyona **kopyalayarak** geçirmek çok yavaştır ve fazla bellek
harcar. Pointer (veya referans) geçirmek, sadece bir adresi (8 byte)
kopyalar. 2. **Paylaşılan durum (shared state)**: Bir sensör kesme
fonksiyonu, ana döngüdeki bir değişkeni doğrudan güncellemek isteyebilir
--- pointer bu "uzaktan değiştirme" yeteneğini sağlar.

**ROS2 bağlantısı:** ROS2'de mesajlar neredeyse hep `shared_ptr`
(paylaşılan pointer) olarak geçirilir --- bu, "ham" pointer'ların
(`int*` gibi) daha güvenli, otomatik bellek yönetimli halidir (bkz.
Bölüm 13.2).

### 8.2 `this` Pointer'ı

``` cpp
class Robot {
public:
    int x, y;
    Robot(int x, int y) {
        this->x = x;   // parametre "x" ile üye değişken "x" aynı isimde, this-> ayırt eder
        this->y = y;
    }
};
```

**Teori:** Her sınıf metodu içinde gizli bir `this` pointer'ı vardır ---
o an çağrılan **nesnenin kendisinin adresini** tutar. Parametre ismi ile
üye değişken ismi çakıştığında (`x` hem parametre hem üye), `this->x`
hangisinden bahsettiğini netleştirir.

### 8.3 İstisna (Exception) Yönetimi

``` cpp
try {
    double result = divide(10, 0);
} catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}

double divide(double a, double b) {
    if (b == 0) throw std::runtime_error("Division by zero");
    return a / b;
}
```

**Teori:** `throw`, bir hatanın oluştuğunu programın geri kalanına
"fırlatır"; `try`/`catch` bloğu bu hatayı yakalayıp **programı
çökertmeden** yönetilebilir hale getirir.

**Neden robotikte kritik?** Fiziksel donanımla çalışan bir sistemde
şunlar sürekli olur: bir sensöre bağlanılamaz, bir seri port zaman
aşımına uğrar, bir konfigürasyon dosyası eksiktir, bir bölme işleminde
payda sıfır olur (örn. `1 / hız` hesaplaması, robot durduğunda). Bu
hataları `try`/`catch` ile yönetmezsen, tüm robot kontrol programı
**aniden çöker** --- bu fiziksel olarak tehlikeli olabilir (robot bir
komut ortasında donabilir). İyi tasarlanmış bir robot yazılımı, hataları
yakalar, güvenli bir duruma geçer (örn. "dur" komutu gönderir) ve
loglar.

### 8.4 Manuel Bellek Yönetimi --- `malloc`/`free`

``` cpp
int *ptr = (int*) malloc(sizeof(int));
*ptr = 5;
free(ptr);
ptr = nullptr;
```

**Teori:** `malloc`, C'den miras kalan, heap üzerinde ham bellek ayıran
fonksiyondur; `free` bu belleği geri verir. `nullptr` ataması, "sarkan
pointer" (dangling pointer --- serbest bırakılmış belleğe hâlâ işaret
eden pointer) hatalarını önlemeye yardımcı olur.

**Neden modern C++'ta önerilmiyor?** `malloc`/`free` **tip güvenliği
sağlamaz** ve constructor/destructor çağırmaz (sınıf nesneleri için
uygun değildir). Eğer `free` çağırmayı unutursan (**memory leak** ---
bellek sızıntısı) ya da iki kez `free` çağırırsan (**double free**),
programın çökmesine veya tahmin edilemez davranışlara yol açar. Uzun
süre çalışan bir robot kontrol yazılımında bellek sızıntısı,
saatler/günler sonra RAM'in tükenip sistemin çökmesine sebep olabilir
--- bu yüzden modern C++'ta bunun yerine **smart pointer**'lar (Bölüm
13.2) tercih edilir. Bu örneği anlamak önemli çünkü hâlâ bazı
eski/gömülü kod tabanlarında (ve C API'lerle etkileşimde) karşına çıkar.

------------------------------------------------------------------------

## 9. Nesne Yönelimli Programlama (OOP) --- Temeller

### 9.1 Sınıf, Constructor, Metot

``` cpp
class DistanceSensor {
private:
    double range;
public:
    DistanceSensor(double max_range) : range(max_range) {}   // constructor + initializer list
    void displayRange() { std::cout << "Sensor maximum range: " << range << std::endl; }
};
```

**Teori:** Bir `class`, veriyi (üye değişkenler / *members*) ve o veri
üzerinde çalışan davranışı (metotlar) **tek bir birimde** bir araya
getirir. **Constructor**, sınıf isimli özel bir metottur ve nesne
oluşturulduğunda otomatik çağrılır --- genelde başlangıç değerlerini
ayarlamak için kullanılır. `: range(max_range)` kısmı **initializer
list** (başlatma listesi) denir; üye değişkeni constructor gövdesi
çalışmadan **önce** doğrudan başlatır --- bu, gövde içinde atama
yapmaktan (`range = max_range;`) daha verimlidir, özellikle `const`
üyeler veya referans üyeler için **zorunludur**.

**Neden robotikte OOP merkezi?** Gerçek dünyadaki her fiziksel bileşen
(bir mesafe sensörü, bir motor, bir kamera, bir robot kolu) doğal olarak
"veri + davranış" birleşimidir --- bir sensörün bir menzili (veri) ve
bir okuma metodu (davranış) vardır. ROS2'nin tüm mimarisi (Node
sınıfları, mesaj tipleri, publisher/subscriber'lar) sınıflar üzerine
kuruludur.

### 9.2 Erişim Belirleyiciler (`private`, `protected`, `public`)

``` cpp
class Robot {
private:   int battery_level_;   // sadece sınıfın kendi içinden erişilebilir
protected: int max_speed_;       // sınıf + türetilen (kalıtım alan) sınıflar erişebilir
public:    Robot(int battery, int speed) { ... }
};
```

**Teori (Encapsulation --- Kapsülleme):** `private` üyeler dış dünyadan
**gizlenir**; sadece sınıfın kendi metotları erişebilir. `protected`,
kalıtım alan (`derived`) sınıflara da erişim izni verir. `public` her
yerden erişilebilir.

**Neden bu kısıtlama iyi bir şey?** `battery_level_` gibi bir değeri
doğrudan `public` yaparsan, kodun herhangi bir yerinden
`robot.battery_level_ = -500;` gibi **fiziksel olarak anlamsız** bir
değer atanabilir. `private` yapıp sadece kontrollü bir
`set_battery_level()` metoduyla değiştirilmesine izin vererek, geçersiz
değerleri (`if (value >= 0 && value <= 100)`) reddedebilirsin. Bu, büyük
robotik kod tabanlarında **veri bütünlüğünü** korumanın temel yoludur.

### 9.3 Getter/Setter Metotları

``` cpp
class RobotArm {
public:
    void set_position(int x, int y, int z) { x_ = x; y_ = y; z_ = z; }
    int get_x() const { return x_; }
private:
    int x_, y_, z_;
};
```

**Teori:** Getter/setter, `private` üye değişkenlere **kontrollü**
erişim sağlayan `public` metotlardır. `const` anahtar kelimesi
(`get_x() const`) "bu metot nesnenin durumunu değiştirmez" garantisi
verir --- derleyici bunu kontrol eder.

**Neden `const` metotlar robotikte önemli?** Sensör verisini okuyan (ama
değiştirmeyen) bir fonksiyona sensörü `const Sensor&` olarak
geçirebilirsin --- bu, o fonksiyonun **yanlışlıkla** sensör durumunu
değiştirmeyeceğini derleme zamanında garanti eder. Çok node'lu/çok
thread'li bir robotik sistemde bu tür garantiler hata ayıklamayı çok
kolaylaştırır.

### 9.4 `static` Üyeler ve Metotlar

``` cpp
class RobotUtils {
public:
    static double calculate_distance(double x1, double y1, double x2, double y2) { ... }
};
double d = RobotUtils::calculate_distance(0, 0, 3, 4);  // nesne oluşturmadan çağrılır!
```

**Teori:** `static` bir metot, **belirli bir nesneye değil, sınıfın
kendisine ait** çalışır --- bir nesne (`RobotUtils utils;`) oluşturmana
gerek yoktur, doğrudan `SınıfAdı::metot()` ile çağrılır.

**Neden kullanışlı?** Mesafe hesaplama gibi, herhangi bir nesnenin
durumuna (state) ihtiyaç duymayan, sadece girdi alıp çıktı üreten
"yardımcı" (utility) fonksiyonlar için idealdir. Robotik projelerde
`MathUtils`, `RobotUtils`, `TransformUtils` gibi sınıflar genelde
tamamen `static` metotlardan oluşur --- matematiksel yardımcı fonksiyon
kütüphaneleri.

### 9.5 Destructor

``` cpp
class RobotController {
public:
    RobotController() {}
    ~RobotController() { std::cout << "Robot controller shutting down" << std::endl; }
};
```

**Teori:** Destructor (`~SınıfAdı()`), nesne yok edildiğinde (scope'tan
çıktığında veya `delete` edildiğinde) **otomatik** çağrılır. Genelde
"temizlik" işleri için kullanılır: açık bir dosyayı kapatmak, bir seri
port bağlantısını kesmek, ayrılmış belleği serbest bırakmak.

**Neden robotikte önemli?** Bir `MotorController` nesnesi yok edilirken
destructor'ı **motorları güvenli şekilde durdurmalı** ve donanım
bağlantısını kapatmalıdır --- aksi halde program beklenmedik şekilde
sonlanırsa (crash, Ctrl+C) motor çalışır durumda "asılı" kalabilir. Bu
desen, C++'ta **RAII** (Resource Acquisition Is Initialization ---
"Kaynak Edinimi Başlatmadır") olarak bilinir: kaynak constructor'da
alınır, destructor'da otomatik bırakılır, böylece kaynak sızıntısı
neredeyse imkansız hale gelir.

### 9.6 Operatör Aşırı Yükleme (Operator Overloading)

``` cpp
class Distance {
public:
    int meters;
    Distance(int m = 0) : meters(m) {}
    Distance operator+(const Distance& other) const { return Distance(meters + other.meters); }
};
Distance sum = d1 + d2;   // aslında d1.operator+(d2) çağrılıyor
```

**Teori:** C++'ta `+`, `-`, `==` gibi operatörlerin kendi sınıflarınla
nasıl davranacağını **tanımlayabilirsin**. `operator+` tanımlandığında,
`d1 + d2` yazımı otomatik olarak `d1.operator+(d2)` çağrısına dönüşür.

**Neden robotikte kullanışlı?** Robotik matematiğinde vektörler,
konumlar, dönüşümler (transforms) sürekli toplanır/çıkarılır/çarpılır
(örn. `Eigen::Vector3d` kütüphanesi tam olarak bunu yapar --- bkz. Bölüm
1'deki `05-simple_eigen_example.cpp`). Kendi `Position` veya `Pose`
sınıfını yazarken `operator+` tanımlamak, `add_positions(p1, p2)` yazmak
yerine doğal matematiksel `p1 + p2` yazımını mümkün kılar --- kodun
matematiksel formüllere çok daha yakın okunmasını sağlar.

### 9.7 Header (.hpp) ve Kaynak (.cpp) Dosyalarını Ayırma

``` cpp
// robot.hpp
#ifndef ROBOT_HPP
#define ROBOT_HPP
class Robot { public: void greet(); };
#endif

// robot.cpp
#include "robot.hpp"
void Robot::greet() { std::cout << "Hello, I am a robot." << std::endl; }
```

**Teori:** `.hpp` (header) dosyası sınıfın **arayüzünü** (hangi metotlar
var, hangi parametreleri alıyor) tanımlar; `.cpp` dosyası bu metotların
**gerçek uygulamasını** (implementation) içerir.
`#ifndef`/`#define`/`#endif` (**include guard**), aynı header'ın birden
fazla dosyaya include edilmesi durumunda "yeniden tanımlama" derleme
hatasını önler.

**Neden büyük robotik projelerde zorunlu?** Bir ROS2 paketinde
onlarca/yüzlerce dosya olabilir. Header/kaynak ayrımı sayesinde: (1)
Başka bir dosya sadece `.hpp`'yi include ederek sınıfı kullanabilir, tüm
implementasyon detaylarını görmesine gerek kalmaz (**arayüz/uygulama
ayrımı**), (2) sadece `.cpp` değiştiğinde tüm projeyi değil sadece o
dosyayı yeniden derlemek yeterlidir (**daha hızlı derleme** --- büyük
robotik kod tabanlarında derleme süresi ciddi bir mühendislik
kaygısıdır).

------------------------------------------------------------------------

## 10. OOP --- İleri Seviye: Kalıtım ve Polymorphism

### 10.1 Kalıtım (Inheritance) ve Sanal Fonksiyonlar (`virtual`)

``` cpp
class Robot {
public:
    virtual void move() { std::cout << "Robot is moving" << std::endl; }
};
class WheeledRobot : public Robot {
public:
    void move() override { std::cout << "Wheeled Robot is rolling" << std::endl; }
};

Robot* robot1 = new WheeledRobot();
robot1->move();   // "Wheeled Robot is rolling" yazdırır — Robot::move değil!
```

**Teori:** `class WheeledRobot : public Robot` --- `WheeledRobot`,
`Robot`'un tüm özelliklerini **miras alır** ve üzerine ekleme/değiştirme
yapabilir. `virtual` anahtar kelimesi, hangi `move()` fonksiyonunun
çağrılacağına **çalışma zamanında** (compile time değil, runtime'da),
nesnenin **gerçek tipine** bakılarak karar verilmesini sağlar --- buna
**polymorphism (çok biçimlilik)** denir. `override` anahtar kelimesi
(zorunlu değil ama şiddetle önerilir) derleyiciye "bu metodun bir üst
sınıf sanal fonksiyonunu ezdiğini biliyorum" der --- yazım hatası (örn.
`move` yerine `Move`) yaparsan derleyici hata verir.

**Neden robotikte bu kadar önemli?** Bu, **tam olarak** ROS2'nin
hardware abstraction (donanım soyutlama) katmanının çalışma prensibidir.
Bir `Robot*` pointer'ı (veya referansı), altında `WheeledRobot`,
`LeggedRobot`, `DroneRobot` gibi **tamamen farklı donanımlar** olsa da
aynı kodla (`robot->move()`) çalıştırılabilir. Bu sayede yüksek seviye
planlama kodun (path planning, görev yönetimi), altta hangi fiziksel
robotun çalıştığını **bilmek zorunda kalmaz** --- bu, kod tekrar
kullanılabilirliğinin ve modülerliğin temelidir.

**`delete` neden gerekli?** `new` ile heap'te oluşturulan bir nesne,
`delete` ile elle serbest bırakılmalıdır (yorumda da belirtildiği gibi,
C'deki `free`'nin C++ karşılığı). Bunu unutmak **memory leak**'e yol
açar (bkz. Bölüm 13.2'de bunun modern çözümü: smart pointer'lar).

### 10.2 Soyut Sınıflar ve Saf Sanal Fonksiyonlar (Pure Virtual)

``` cpp
class Actuator {
public:
    virtual void activate() = 0;   // "= 0" → saf sanal fonksiyon
};
class Motor : public Actuator {
public:
    void activate() override { std::cout << "Motor is running." << std::endl; }
};

void test_actuator(Actuator& actuator) { actuator.activate(); }  // hangi aktüatör olduğunu bilmiyor!
```

**Teori:** `= 0` ile biten bir sanal fonksiyon **saf sanal (pure
virtual)** fonksiyondur; bu, `Actuator` sınıfını **soyut (abstract)**
yapar --- yani `Actuator` nesnesi **doğrudan oluşturulamaz**
(`Actuator a;` derleme hatası verir), sadece bir **arayüz/kontrat**
görevi görür. Her türetilen sınıf bu fonksiyonu **mutlaka** kendi
implementasyonuyla doldurmak zorundadır.

**Neden bu, gerçek robotik mimarilerin temelidir?** Bu tam olarak
"programlamaya arayüze göre, implementasyona göre değil" prensibidir.
`test_actuator(Actuator& actuator)` fonksiyonu, kendisine bir `Motor` mu
`Servo` mu geçirildiğini **hiç bilmez ve umursamaz** --- sadece "her
Actuator'ın bir `activate()` metodu vardır" garantisine güvenir.
ROS2'nin `hardware_interface` paketi, MoveIt'in planner arayüzleri,
Nav2'nin costmap plugin'leri hep bu desenle (soyut temel sınıf + somut
implementasyonlar) inşa edilir --- yeni bir sensör/aktüatör/algoritma
eklemek, mevcut kodu değiştirmeden yeni bir sınıf yazmak kadar kolay
hale gelir.

------------------------------------------------------------------------

## 11. STL Sıralı Konteynerlar

### 11.1 `std::deque`, `std::list`, `std::forward_list`

``` cpp
std::deque<int> robot_positions = {10, 20, 30};
robot_positions.push_front(5);   // vector'da yok! deque'de var
robot_positions.push_back(40);

std::list<std::string> robot_actions = {"move", "rotate", "scan"};  // çift yönlü bağlı liste
std::forward_list<double> sensor_readings = {1.5, 2.7, 3.2};        // tek yönlü bağlı liste
```

  -----------------------------------------------------------------------
  Konteyner               Özellik                 Ne zaman kullan
  ----------------------- ----------------------- -----------------------
  `vector`                Sona ekleme hızlı,      Varsayılan seçim, çoğu
                          rastgele erişim hızlı   durumda

  `deque`                 Hem başa hem sona       Bir sensör verisi
                          ekleme hızlı            tamponu (buffer) --- en
                                                  eski veriyi baştan atıp
                                                  yeniyi sona eklemek

  `list`                  Ortadan ekleme/silme    Sık sık ortadan öğe
                          hızlı, rastgele erişim  eklenip çıkarılan görev
                          yok                     listeleri

  `forward_list`          `list`'ten daha az      Bellek kısıtlı gömülü
                          bellek kullanır (tek    sistemlerde basit
                          yönlü)                  sıralı liste
  -----------------------------------------------------------------------

**Robotik örnek --- `deque`:** Bir sensörün "son N okuma" hareketli
ortalamasını (moving average / low-pass filter) tutmak için idealdir:
`sensor_data.push_back(yeni_deger); sensor_data.pop_front();` --- sabit
boyutlu bir "kayan pencere" (sliding window) oluşturur, gürültülü sensör
verisini yumuşatmak için robotikte çok sık kullanılan bir teknik.

### 11.2 İteratörler

``` cpp
std::vector<int> sensor_data = {10, 20, 30, 40, 50};
for (auto it = sensor_data.begin(); it != sensor_data.end(); ++it) {
    *it *= 2;   // pointer gibi, * ile değeri değiştir
}
```

**Teori:** İteratör, bir konteynerin elemanları üzerinde **gezinmek**
için kullanılan, pointer'a çok benzeyen bir soyutlamadır (`begin()` ilk
elemanı, `end()` son elemandan **bir sonrasını** gösterir). Tüm STL
konteynerları aynı iteratör arayüzünü sunduğu için, aynı döngü mantığı
`vector`, `list`, `set`, `map` üzerinde neredeyse aynı şekilde çalışır.

**Neden `for (const auto& value : container)` (range-based for) yerine
bazen iteratör kullanılır?** Range-based for sadece okuma/basit
değiştirme için yeterlidir; ama bir elemanı **silmek** veya konteynerin
ortasına eleman **eklemek** istediğinde, doğrudan iteratöre ihtiyacın
olur (`container.erase(it)` gibi).

### 11.3 Lambda İfadeleri ve `std::sort` / `std::for_each`

``` cpp
std::sort(sensor_readings.begin(), sensor_readings.end(), [](int a, int b) { return a > b; });

std::for_each(distances.begin(), distances.end(), [](int &d) { d += 1; });
```

**Teori:** `[](int a, int b) { return a > b; }` bir **lambda
ifadesidir** --- isimsiz, satır içi (inline) bir fonksiyondur. `[]`
(yakalama listesi/capture list) dış kapsamdaki değişkenlere nasıl
erişileceğini belirtir (boş bırakılırsa hiçbir dış değişken
kullanılmaz).

**Neden robotikte kullanışlı?** Bir sensör okuma listesini büyükten
küçüğe sıralamak (en yüksek öncelikli engeli bulmak), bir listedeki her
elemana aynı düzeltmeyi (kalibrasyon offseti) uygulamak gibi **kısa, tek
kullanımlık işlemler** için ayrı bir isimli fonksiyon tanımlamak
gereksiz karmaşıklık yaratır. Lambda, bu mantığı **kullanıldığı yerde**
tanımlamanı sağlar --- kod daha kısa ve okunması daha kolay olur. Modern
ROS2 kodunda callback fonksiyonları (bir mesaj geldiğinde ne yapılacağı)
çoğunlukla lambda olarak yazılır.

------------------------------------------------------------------------

## 12. STL İlişkisel Konteynerlar ve Adaptörler

### 12.1 `std::set` / `std::multiset`

``` cpp
std::set<int> unique_landmarks = {10, 20, 30, 20, 40, 30};   // tekrarlar otomatik silinir, sıralı tutulur
std::multiset<std::string> repeated_commands = {"move", "rotate", "move"};  // tekrara izin verir
```

**Teori:** `set`, elemanları **otomatik sıralı** ve **benzersiz
(unique)** tutan bir konteynerdir --- aynı elemanı iki kez eklemeye
çalışırsan, ikincisi sessizce yok sayılır.

**Robotik örnek:** Bir SLAM haritalama algoritması, algılanan
**benzersiz** dönüm noktalarını (landmark) tutmak isteyebilir --- aynı
dönüm noktası birden fazla kez algılansa bile `set` içinde yalnızca bir
kez yer alır, otomatik olarak tekilleştirme (deduplication) yapılmış
olur.

### 12.2 `std::map` / `std::multimap`

``` cpp
std::map<std::string, int> sensor_readings;
sensor_readings["temperature"] = 25;
sensor_readings["humidity"] = 60;
```

**Teori:** `map`, **anahtar-değer (key-value)** çiftleri tutan, anahtara
göre otomatik sıralanan bir konteynerdir --- dizi indeksleri yerine
anlamlı isimlerle (`"temperature"`) veriye erişmeni sağlar. `multimap`,
aynı anahtarın birden fazla değerle ilişkilendirilmesine izin verir
(örn. `"move"` komutunun hem `"forward"` hem `"backward"` seçeneği
olması).

**Neden robotikte çok kullanışlı?** Farklı sensörlerden gelen
adlandırılmış verileri (`"temperature"`, `"humidity"`, `"pressure"`) tek
bir yapıda tutmak, her biri için ayrı değişken tanımlamaktan çok daha
esnektir --- özellikle sensör sayısı/tipi çalışma zamanında (config
dosyasından) belirlendiğinde. ROS2 parametre sistemi de kavramsal olarak
bir `map<string, ParameterValue>` gibi çalışır.

### 12.3 `std::stack` ve `std::queue`

``` cpp
std::stack<int> my_stack;      // LIFO — Last In, First Out (son giren ilk çıkar)
my_stack.push(10); my_stack.top(); my_stack.pop();

std::queue<std::string> my_queue;  // FIFO — First In, First Out (ilk giren ilk çıkar)
my_queue.push("Sensor data"); my_queue.front(); my_queue.pop();
```

**Neden robotikte iki farklı yapı gerekli?** - **`stack` (LIFO):** "Geri
al" (undo) mekanizmaları, bir path planning algoritmasının derinlik
öncelikli aramasında (DFS) ziyaret edilen düğümleri takip etmek. -
**`queue` (FIFO):** Robotun işleyeceği komutların **sırayla** işlenmesi
gerektiği durumlar --- örn. "önce gelen komut önce çalışsın" mantığıyla
bir hareket komut kuyruğu; sensör verisi işleme hattı (pipeline) da
genelde FIFO mantığıyla çalışır (en eski veri önce işlenir).

### 12.4 `std::priority_queue`

``` cpp
struct Task {
    int priority;
    std::string description;
    bool operator<(const Task& other) const { return priority < other.priority; }
};
std::priority_queue<Task> tasks;
tasks.push({2, "Navigate to charging station"});
tasks.push({1, "Send sensor data"});
tasks.push({3, "Emergency stop"});
// tasks.top() her zaman en yüksek öncelikli (priority=3) görevi verir
```

**Teori:** `priority_queue`, elemanları ekleme sırasına göre değil,
**tanımlanan önceliğe göre** sıralı tutar; `top()` her zaman en yüksek
öncelikli elemanı verir. Bunun çalışması için `operator<`
tanımlanmalıdır (Bölüm 9.6'daki operatör aşırı yükleme burada devreye
giriyor).

**Neden robotikte kritik derecede önemli?** Bu, **gerçek bir robot görev
zamanlayıcısının (task scheduler)** temelidir: "Acil durdur" komutu her
zaman "şarj istasyonuna git" komutundan önce işlenmelidir, öncelik
sırasına göre değil geliş sırasına göre çalışan bir `queue` bunu garanti
edemez. Ayrıca **A\* ve Dijkstra path planning algoritmaları**
(robotların en kısa/en güvenli yolu bulması için kullandığı
algoritmalar) tam olarak bir `priority_queue` üzerine inşa edilir ---
"en düşük maliyetli sonraki düğümü" seçmek için.

### 12.5 Konteyner Seçim Rehberi (Özet)

  İhtiyaç                                        Konteyner
  ---------------------------------------------- ------------------
  Sıralı, rastgele erişilebilir liste            `vector`
  Baştan/sondan hızlı ekleme (sensör buffer'ı)   `deque`
  Benzersiz, otomatik sıralı elemanlar           `set`
  İsim → değer eşlemesi                          `map`
  Sırayla işlenecek komutlar (FIFO)              `queue`
  Önceliğe göre işlenecek görevler               `priority_queue`
  Geri al / DFS (LIFO)                           `stack`

### 12.6 `enum class` --- Durum Makineleri (State Machines)

``` cpp
enum class RobotState { IDLE, MOVING, GRASPING, ERROR };

void print_robot_state(RobotState state) {
    switch (state) {
        case RobotState::IDLE: std::cout << "Robot is idle." << std::endl; break;
        case RobotState::MOVING: std::cout << "Robot is moving." << std::endl; break;
        // ...
    }
}
```

**Teori:** `enum class`, sınırlı sayıda **adlandırılmış sabit**
tanımlamanı sağlar. Eski C-tarzı `enum`'dan farkı: `enum class` **tip
güvenlidir** (bir `RobotState` değerini yanlışlıkla bir `int` ile
karşılaştıramazsın) ve isimleri kendi kapsamında tutar
(`RobotState::IDLE`, başka bir enum'un `IDLE` değeriyle çakışmaz).

**Neden robotikte temel bir tasarım deseni?** Neredeyse her robot, açık
bir **durum makinesi (state machine)** ile modellenir:
`IDLE → MOVING → GRASPING → ERROR` gibi durumlar arasında geçiş yapar ve
her durumda farklı davranır (hangi komutları kabul eder, hangi güvenlik
kontrolleri aktiftir). `enum class` + `switch`, bu durum makinesini
**okunabilir ve tip-güvenli** şekilde ifade etmenin standart C++ yoludur
--- sayısal kodlar (`0`, `1`, `2`) yerine anlamlı isimler kullanmak, hem
kodu okunabilir kılar hem de geçersiz bir duruma (`RobotState`'te
olmayan bir değere) geçişi derleme zamanında engeller.

------------------------------------------------------------------------

## 13. Şablonlar (Templates) ve Modern Bellek Yönetimi

### 13.1 Şablon Fonksiyonlar ve Sınıflar

``` cpp
template <typename T>
T find_max(T a, T b) { return (a > b) ? a : b; }

find_max<int>(10, 20);
find_max<double>(5.5, 2.1);
```

``` cpp
template<typename T>
class Point {
    T x, y;
public:
    Point(T x, T y) : x(x), y(y) {}
};
Point<int> int_point(5, 10);
Point<double> double_point(3.14, 2.71);
```

**Teori:** `template <typename T>`, aynı kodu **tip parametreli**
yazmanı sağlar --- `T` yerine derleme zamanında `int`, `double`, kendi
sınıfın vs. herhangi bir tip konabilir. Derleyici her farklı tip için
ayrı bir versiyon "üretir" (bu sürece **template instantiation** denir),
bu yüzden çalışma zamanı performans kaybı **yoktur** (Python'daki
generic'lerin aksine).

**Neden robotikte güçlü bir araç?** Bir `PID` kontrolcü sınıfı düşün ---
bazen `float` hassasiyetle (hızlı, gömülü sistem), bazen `double`
hassasiyetle (masaüstü, yüksek hassasiyet gerektiren) çalışmasını
isteyebilirsin. Şablon olmadan bu iki versiyonu ayrı ayrı yazman gerekir
(kod tekrarı); şablonla **tek bir `PID<T>` sınıfı** hem `PID<float>` hem
`PID<double>` olarak kullanılabilir. Eigen kütüphanesi (Bölüm 1'de
gördüğün `Eigen::Vector3d`) baştan sona şablonlarla yazılmıştır ---
`Vector3d` aslında `Matrix<double, 3, 1>` şablonunun bir kısaltmasıdır.

### 13.2 Akıllı Pointer'lar (Smart Pointers)

``` cpp
std::unique_ptr<Sensor> sensor1 = std::make_unique<Sensor>("TemperatureSensor", 25.5);
std::shared_ptr<Sensor> sensor2 = std::make_shared<Sensor>("HumiditySensor", 60.0);
std::weak_ptr<Sensor> weak_sensor = sensor2;
```

**Teori:** - **`unique_ptr`**: Bir kaynağın **tek bir sahibi** olduğunu
garanti eder --- kopyalanamaz, sadece "taşınabilir" (moved). Sahip
scope'tan çıktığında bellek **otomatik** serbest bırakılır (destructor
otomatik çağrılır --- RAII, bkz. Bölüm 9.5). - **`shared_ptr`**: Bir
kaynağın **birden fazla sahibi** olabilir; dahili bir referans sayacı
(reference count) tutar, sayaç sıfıra düştüğünde (son sahip de yok
olduğunda) bellek otomatik serbest bırakılır. - **`weak_ptr`**:
`shared_ptr`'a "gözlemci" gibi bakar, sahiplik saymaz (referans sayacını
artırmaz) --- döngüsel referans (`A` `B`'yi, `B` `A`'yı `shared_ptr` ile
tutması → ikisi de asla silinmez) sorununu çözmek için kullanılır.

**Neden bu, modern robotik C++'ın en önemli konseptlerinden biri?**
Bölüm 8.4'te gördüğün `malloc`/`free` ve Bölüm 10.1'deki `new`/`delete`
**manuel** bellek yönetimi gerektirir --- unutmak (leak) veya yanlış
yapmak (double-free, dangling pointer) ciddi hatalara yol açar. Smart
pointer'lar bu riski **tamamen ortadan kaldırır**: bellek otomatik ve
**deterministik** şekilde yönetilir. **ROS2'nin (`rclcpp`) tüm mesaj
sistemi `shared_ptr` üzerine kuruludur** --- bir subscriber callback'i
mesajı `shared_ptr<const Msg>` olarak alır; birden fazla node/callback
aynı mesaja aynı anda "sahip" olabilir ve hiçbiri elle `delete` çağırmak
zorunda değildir. Modern C++ robotik kodunda çıplak `new`/`delete`
görmek, kod incelemesinde (code review) neredeyse her zaman bir "bunu
smart pointer yap" yorumuyla karşılanır.

------------------------------------------------------------------------

## 14. Eşzamanlılık: Threads ve Zamanlama

### 14.1 `std::thread`

``` cpp
std::thread sensor_thread1(sensorTask, "TemperatureSensor", 2);
std::thread control_thread(controlTask, "MotionController", 4);
sensor_thread1.join();   // ana thread, bu thread bitene kadar bekler
control_thread.join();
```

**Teori:** `std::thread`, verdiğin bir fonksiyonu **ayrı bir yürütme
dizisinde (paralel)** çalıştırır. `join()`, ana thread'in o thread
bitene kadar beklemesini sağlar (aksi halde ana program, alt thread'ler
bitmeden sonlanabilir).

**Neden robotikte hayati?** Gerçek bir robot **aynı anda** birçok şey
yapmalıdır: sensörleri okumak (yüksek frekans), motor kontrol döngüsünü
çalıştırmak (çok yüksek frekans, gerçek zamanlı), ağ üzerinden komut
almak (düşük frekans, ne zaman geleceği belirsiz), loglama yapmak.
Bunların hepsini **tek bir thread'de sırayla** yapmaya çalışırsan, biri
yavaşladığında (örn. ağ gecikmesi) diğer her şey (motor kontrolü!)
bloklanır --- bu fiziksel olarak tehlikelidir. Bu yüzden ROS2'nin
**executor** mimarisi (callback'leri farklı thread'lerde/thread
havuzlarında çalıştırma) ve genel olarak robotik yazılım, thread'ler
üzerine ağır şekilde kuruludur.

### 14.2 `std::chrono` --- Zamanlama

``` cpp
auto start_time = std::chrono::steady_clock::now();
std::this_thread::sleep_for(std::chrono::seconds(2));
auto end_time = std::chrono::steady_clock::now();
std::chrono::duration<double> elapsed_seconds = end_time - start_time;
```

**Teori:** `steady_clock`, geriye gitmeyen (monotonic), süre ölçümü için
güvenli bir saattir (sistem saati --- `system_clock` --- kullanıcı
tarafından değiştirilebilir, bu yüzden süre ölçümünde tercih edilmez).
`sleep_for`, mevcut thread'i belirtilen süre kadar **duraklatır**.

**Neden robotikte kritik?** Bir kontrol döngüsünün **sabit bir
frekansta** (örn. 100 Hz = saniyede 100 kez) çalışması gerekir --- PID
kontrolcüleri, sensör füzyon algoritmaları (Kalman filtresi gibi)
matematiksel olarak sabit zaman adımına (`dt`) dayanır. `chrono`, hem bu
zamanlamayı sağlamak (`sleep_for` ile döngü hızını sabitlemek) hem de
performans ölçmek (bir hesaplamanın ne kadar sürdüğünü, gerçek zamanlı
bir kısıtı aşıp aşmadığını kontrol etmek) için kullanılır.

------------------------------------------------------------------------

## 15. Dosya İşlemleri ve Rastgele Sayılar

### 15.1 Dosyaya Yazma/Okuma (`<fstream>`)

``` cpp
std::ofstream output_file("robot_data.txt");
if (output_file.is_open()) {
    output_file << "Sensor1: 10.5\n";
    output_file.close();
}
std::ifstream input_file("robot_data.txt");
std::string line;
while (std::getline(input_file, line)) { std::cout << line << std::endl; }
```

**Teori:** `ofstream` ("output file stream") dosyaya yazar, `ifstream`
("input file stream") dosyadan okur --- `cout`/`cin` ile aynı `<<`/`>>`
operatörlerini kullanırlar çünkü hepsi ortak bir akış (stream) arayüzünü
paylaşır. `is_open()` kontrolü, dosyanın (yanlış yol, izin hatası vb.
yüzden) gerçekten açılıp açılmadığını doğrular.

**Neden robotikte gerekli?** Sensör kalibrasyon parametrelerini (örn.
IMU offset değerleri), robot konfigürasyonunu (YAML/JSON dosyaları ---
ROS2'de parametre dosyaları tam olarak budur) okumak/yazmak, uçuş/görev
verisini (data logging, "black box" kaydı) diske yazmak için dosya G/Ç
işlemleri her robotik projede bulunur.

### 15.2 Rastgele Sayı Üretimi

``` cpp
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<double> dis(0.0, 1.0);
double random_double = dis(gen);
```

**Teori:** Eski C tarzı `rand()`/`srand()` **düşük kaliteli**
(istatistiksel olarak öngörülebilir desenlere sahip) rastgele sayılar
üretir. Modern C++ `<random>` kütüphanesi, `mt19937` (Mersenne Twister)
gibi **yüksek kaliteli** bir rastgele sayı üreticisini (generator),
`uniform_real_distribution` gibi bir **dağılımla** (distribution)
birleştirerek çok daha güvenilir rastgelelik sağlar.

**Neden robotikte önemli?** Rastgelelik, robotikte üç ana yerde karşına
çıkar: (1) **Parçacık filtreleri (particle filters)** ve Monte Carlo
lokalizasyon algoritmaları binlerce rastgele "parçacık" örnekler, (2)
**Pekiştirmeli öğrenme (reinforcement learning)** tabanlı kontrol, keşif
(exploration) sırasında rastgele eylemler dener, (3) **Simülasyon ve
test** --- sensör gürültüsünü (noise) yapay olarak simüle etmek,
algoritmanı gerçek donanıma yüklemeden önce test etmek için gerçekçi
rastgele bozulmalar eklemek. Kötü kalitede rastgelelik, bu
algoritmaların gerçekte olduğundan daha iyi/kötü performans
gösteriyormuş gibi yanıltıcı sonuçlar vermesine yol açabilir.

------------------------------------------------------------------------

## 16. Doküman Standardı: Doxygen

``` cpp
/**
 * @brief Controller class for robot movement
 * @details Handles basic movement operations and speed control for the robot
 */
class RobotController {
public:
    /**
     * @brief Construct a new Robot Controller object
     * @param name The name identifier for the robot
     * @param speed The maximum speed in meters per second
     */
    RobotController(std::string name, double speed);

    /**
     * @brief Moves the robot forward by the specified distance
     * @param distance The distance to move in meters
     * @return void
     */
    void moveForward(double distance);
};
```

**Teori:** Doxygen, özel yorum etiketleri (`@brief`, `@param`,
`@return`, `@details`) kullanarak koddan **otomatik olarak HTML/PDF
dokümantasyon üretebilen** bir araçtır. Bu etiketler ayrıca modern
IDE'lerin (VSCode, CLion) fonksiyon üzerine geldiğinde gösterdiği
"tooltip" yardım metinlerini de besler.

**Neden profesyonel robotik projelerde standart?** ROS2'nin kendi kod
tabanı ve neredeyse tüm ciddi açık kaynak robotik kütüphaneleri (MoveIt,
Nav2, PCL) Doxygen kullanır. Bir takımda çalışırken, bir fonksiyonun ne
yaptığını, hangi birimde parametre beklediğini (`distance` metre mi
santimetre mi?) anlamak için kaynak kodun implementasyonunu okumak
zorunda kalmamak **büyük zaman kazandırır** --- özellikle 10+ kişilik
bir robotik ekipte veya açık kaynak bir kütüphaneyi kullanırken bu
dokümantasyon, kodun kendisi kadar değerlidir.

------------------------------------------------------------------------

## Kapanış: Bu Bilgiyi Gerçek Bir Projeye Nasıl Taşırsın?

Bu kurstaki her konu, aslında büyük bir ROS2/robotik yazılımının **birer
tuğlasıdır**: - Bir **sensör sınıfı** yazarken → OOP (Bölüm 9),
pointer/smart pointer (Bölüm 8, 13.2) - Sensör verisini **tamponlarken**
→ `deque`/`vector` (Bölüm 7, 11) - **Görev/komut yönetiminde** →
`queue`/`priority_queue` + `enum class` state machine (Bölüm 12) -
**Farklı donanım tiplerini** ortak arayüzden yönetirken → virtual/pure
virtual (Bölüm 10) - **Gerçek zamanlı kontrol döngüsünde** → `thread` +
`chrono` (Bölüm 14) - **Hataları güvenli yönetirken** → `try`/`catch`
(Bölüm 8.3)

Bir sonraki adım olarak, bu parçaları birleştiren küçük bir proje (örn.
"sahte sensörlerden veri okuyan, `enum class` ile durum makinesi
işleten, `priority_queue` ile komutları sıraya sokan, ayrı bir thread'de
10Hz log yazan basit bir robot simülatörü") yazmak, bu 65 örneği gerçek
bir sistemde nasıl bir araya geldiğini görmenin en iyi yoludur.

------------------------------------------------------------------------

# C++ ile Robotik Programlama --- Genişletilmiş Ders Kitabı

> **Bu bölüm, mevcut ders notlarının üzerine eklenen "kitaplaştırılmış"
> katmandır.**
>
> Amaç artık sadece kurs örneklerini açıklamak değil; C bilen birinin
> C++'ı **robotik yazılım geliştirecek şekilde düşünmesini**, kod
> okuyabilmesini, hata ayıklayabilmesini ve daha sonra ROS2/rclcpp
> koduna geçerken yabancılık çekmemesini sağlamaktır.
>
> Temel çalışma döngüsü:
>
> **Öğren → Kaynağı kapat → Kendin yaz → Hata üret → Debug et → Küçük
> proje yap → Dokümante et → İlerle**

------------------------------------------------------------------------

## 17. Bu Kitabı Nasıl Kullanmalısın?

Bu kitap bir roman gibi baştan sona okunmak için değil, **referans +
çalışma kitabı** olarak kullanılmalıdır.

Her konuyu üç seviyede ele al:

### Seviye 1 --- Tanı

Kodun ne olduğunu gördüğünde anlayabiliyor musun?

Örneğin:

``` cpp
std::unique_ptr<Sensor> sensor = std::make_unique<Sensor>();
```

Bu satırı gördüğünde:

-   `unique_ptr` ne?
-   `make_unique` ne?
-   `Sensor` neden pointer üzerinden tutuluyor?
-   sahiplik kimde?
-   nesne ne zaman yok olacak?

sorularının cevabını verebilmelisin.

### Seviye 2 --- Üret

Kaynağı kapatıp benzerini kendin yaz.

### Seviye 3 --- Uyarlama

Aynı özelliği robotik bir probleme uygula.

Örneğin:

``` text
unique_ptr öğren
      ↓
Sensor sınıfını unique_ptr ile oluştur
      ↓
SensorManager yaz
      ↓
Birden fazla sensörü yönet
      ↓
Kaynak sahipliğini açıklayabil
```

**Bir konuyu sadece "gördüm" diye bitirmiş sayma.**

------------------------------------------------------------------------

# 18. C'den C++'a Geçerken Zihinsel Model

C biliyorsan C++ öğrenirken en büyük hata şudur:

> "C'nin üzerine biraz syntax ekledim, artık C++ biliyorum."

Hayır.

C++ aynı zamanda **kaynak sahipliği, nesne ömrü, tip güvenliği,
soyutlama ve generic programming** düşüncesidir.

## 18.1 C'deki yaklaşım

C'de sıkça:

``` c
Sensor *sensor = malloc(sizeof(Sensor));

if (sensor == NULL) {
    return 1;
}

sensor_init(sensor);
sensor_read(sensor);

free(sensor);
```

C++'ta modern yaklaşım:

``` cpp
auto sensor = std::make_unique<Sensor>();

sensor->read();
```

Buradaki asıl fark syntax değildir.

Asıl fark:

``` text
C:
Programcı kaynağın sahibidir.
Programcı ne zaman free edeceğini takip eder.

Modern C++:
Kaynak bir nesnenin yaşam süresine bağlanır.
Scope sona erdiğinde destructor çalışır.
```

Bu düşünceye **RAII** denir.

------------------------------------------------------------------------

# 19. Scope, Lifetime ve Ownership

Bu üç kavram C++ öğrenirken sürekli karşına çıkacak.

## 19.1 Scope

Bir ismin nereden erişilebilir olduğunu ifade eder.

``` cpp
void test()
{
    int speed = 10;
}
```

`speed` sadece fonksiyonun ilgili scope'u içinde kullanılabilir.

## 19.2 Lifetime

Nesnenin gerçekten yaşadığı zaman aralığıdır.

``` cpp
{
    Sensor sensor;
    sensor.read();
}
```

`sensor`, `{` ile başlayan scope'a girdikten sonra oluşturulur ve `}`
noktasında yok edilir.

## 19.3 Ownership

Bir kaynağın sorumluluğunun kimde olduğunu ifade eder.

Örneğin:

``` text
RobotController
      │
      └── owns ──> Motor
```

Controller motorun sahibiyse motorun yaşam süresini controller
yönetebilir.

Modern C++'ta kod okurken kendine sürekli şu soruyu sor:

> **"Bu nesnenin sahibi kim?"**

Bu soru çoğu pointer problemini çözmeye yardım eder.

------------------------------------------------------------------------

# 20. Reference (`&`) --- Pointer ile Aynı Şey Değil

C bilen biri için önemli bir ayrım.

## Pointer

``` cpp
int value = 10;
int* ptr = &value;

*ptr = 20;
```

Pointer:

-   adres tutabilir
-   `nullptr` olabilir
-   başka bir nesneye yönlendirilebilir
-   `*` ile dereference edilir

## Reference

``` cpp
int value = 10;
int& ref = value;

ref = 20;
```

Reference:

-   mevcut bir nesneye başka bir isim verir
-   normal kullanımda `nullptr` gibi "boş" bir durum taşımaz
-   oluşturulduktan sonra başka bir nesneye yeniden bağlanmaz

Örnek:

``` cpp
void set_speed(int& speed)
{
    speed = 100;
}

int robot_speed = 20;
set_speed(robot_speed);
```

`robot_speed` fonksiyon içinde doğrudan değiştirildi.

------------------------------------------------------------------------

# 21. `const T&` --- Robotikte Çok Önemli Bir İmza

Büyük bir nesneyi kopyalamadan okumak için sık kullanılan desen:

``` cpp
void print_sensor(const SensorData& data)
{
    std::cout << data.temperature << '\n';
}
```

Burada üç fikir aynı anda vardır:

``` text
const
 ↓
fonksiyon değiştirmesin

&
 ↓
kopya oluşturma

SensorData
 ↓
beklenen veri tipi
```

Karşılaştır:

``` cpp
void process(SensorData data);              // kopya
void process(SensorData& data);             // değiştirebilir
void process(const SensorData& data);      // değiştiremez + kopyalamaz
```

Genel zihinsel model:

``` text
Küçük temel tip:
int

Büyük nesneyi sadece okuyacaksan:
const T&

Büyük nesneyi değiştireceksen:
T&

Sahiplik devri gerekiyorsa:
smart pointer / move
```

Bu son satır özellikle önemlidir.

------------------------------------------------------------------------

# 22. `const`'un Farklı Kullanımları

`const` sadece değişkenlerde kullanılmaz.

## 22.1 Const değişken

``` cpp
const double MAX_SPEED = 2.0;
```

## 22.2 Const reference

``` cpp
void log(const std::string& message);
```

## 22.3 Const member function

``` cpp
class Robot
{
public:
    int speed() const;
};
```

Buradaki:

``` cpp
speed() const
```

şunu ifade eder:

> Bu fonksiyon nesnenin gözlemlenebilir durumunu değiştirmeyeceğini
> garanti eder.

Örnek:

``` cpp
class Robot
{
private:
    int speed_;

public:
    int speed() const
    {
        return speed_;
    }
};
```

------------------------------------------------------------------------

# 23. `nullptr`

Modern C++'ta pointer için:

``` cpp
int* ptr = nullptr;
```

kullan.

Eski kodlarda:

``` cpp
int* ptr = NULL;
```

veya:

``` cpp
int* ptr = 0;
```

görebilirsin.

Modern C++ kodunda tercih:

``` cpp
nullptr
```

Örneğin:

``` cpp
Sensor* sensor = nullptr;

if (sensor != nullptr)
{
    sensor->read();
}
```

------------------------------------------------------------------------

# 24. `->` Operatörü

Bir pointer üzerinden nesnenin üyesine erişirken:

``` cpp
sensor->read();
```

şu ifadeye denktir:

``` cpp
(*sensor).read();
```

Bu yüzden:

``` cpp
Robot robot;
robot.move();
```

ile:

``` cpp
Robot* robot = &some_robot;
robot->move();
```

arasındaki farkı bil.

------------------------------------------------------------------------

# 25. `auto` --- Ne Zaman Kullanılır?

`auto`:

``` cpp
auto speed = 10.0;
```

ifadesinde derleyicinin tipi çıkarmasına izin verir.

Sonuç:

``` cpp
double speed = 10.0;
```

gibi olur.

Iteratorlarda özellikle faydalıdır:

``` cpp
for (auto it = data.begin(); it != data.end(); ++it)
{
}
```

Modern robotik kodda daha da önemli:

``` cpp
auto message = std::make_shared<SensorData>();
```

Ancak `auto`yu:

> "Tipleri öğrenmeme gerek yok."

şeklinde kullanma.

Önce tipin ne olduğunu anlamalısın.

İyi kullanım:

``` cpp
auto iterator = container.begin();
```

Çünkü iterator tipi gereksiz derecede uzun olabilir.

Kötü kullanım:

``` cpp
auto x = complicated_function();
```

Eğer `x`'in tipi kodun anlamını anlamak için kritikse, tipi açıkça
yazmak daha öğretici olabilir.

------------------------------------------------------------------------

# 26. Range-Based `for`

Modern C++'ta çok sık göreceğin döngü:

``` cpp
std::vector<double> distances = {1.2, 2.4, 3.1};

for (double distance : distances)
{
    std::cout << distance << '\n';
}
```

Burada değerler kopyalanır.

Büyük nesnelerde:

``` cpp
for (const auto& distance : distances)
{
    std::cout << distance << '\n';
}
```

okuma için iyi bir varsayılandır.

Değiştirmek istiyorsan:

``` cpp
for (auto& distance : distances)
{
    distance *= 2.0;
}
```

Robotik veri işleme kodunda bu desen çok sık kullanılır.

------------------------------------------------------------------------

# 27. `std::array` --- C Dizisi ile `vector` Arasında

C dizisi:

``` cpp
double readings[8];
```

Modern C++ tarafında sabit boyutlu koleksiyon için:

``` cpp
std::array<double, 8> readings;
```

avantajı:

-   boyut bilgisini taşır
-   STL algoritmalarıyla uyumludur
-   `.size()` vardır
-   range-based `for` kullanılabilir

Örnek:

``` cpp
std::array<double, 8> readings{};

for (auto& value : readings)
{
    value = 0.0;
}
```

Robotikte:

``` text
8 ultrasonik sensör
4 encoder
6 IMU ekseni
```

gibi boyutu sabit koleksiyonlarda `std::array` oldukça anlamlıdır.

------------------------------------------------------------------------

# 28. `vector` ve Capacity Mantığı

``` cpp
std::vector<int> data;

data.push_back(10);
data.push_back(20);
```

`size()` kaç eleman olduğunu söyler:

``` cpp
data.size()
```

`capacity()` ise mevcut ayrılmış kapasiteyi ifade eder:

``` cpp
data.capacity()
```

Önemli:

``` cpp
size != capacity
```

Örneğin:

``` text
size = 5
capacity = 8
```

olabilir.

## `reserve()`

Kaç eleman geleceğini yaklaşık olarak biliyorsan:

``` cpp
data.reserve(1000);
```

kullanabilirsin.

Bu, tekrar tekrar yeniden bellek ayırma ihtiyacını azaltabilir.

Robotik örnek:

``` cpp
std::vector<Waypoint> path;
path.reserve(500);
```

------------------------------------------------------------------------

# 29. `emplace_back` ve `push_back`

``` cpp
std::vector<Sensor> sensors;

sensors.push_back(Sensor("Lidar"));
```

ve:

``` cpp
sensors.emplace_back("Lidar");
```

aynı genel amaca hizmet eder.

`emplace_back`, nesneyi container'ın içinde verilen argümanlarla
oluşturabilir.

Örneğin:

``` cpp
sensors.emplace_back("Lidar", 20.0);
```

Burada `Sensor` constructor'ına doğrudan argüman verilir.

Öğrenme aşamasında:

> `push_back` ve `emplace_back` farkını bil; ama her yerde
> `emplace_back` kullanmak zorunda olduğunu düşünme.

------------------------------------------------------------------------

# 30. Iterator Geçersizleşmesi

Bu, STL öğrenirken önemli bir hata sınıfıdır.

Örneğin bir `vector` büyürken yeni bellek alanına taşınabilir.

``` cpp
std::vector<int> values = {1, 2, 3};

auto it = values.begin();

values.push_back(4);
```

`push_back` sonrasında eski iterator'ın geçerli kalacağı garanti
değildir.

Genel kural:

> Bir container'ı değiştirdiğinde elindeki
> iterator/reference/pointer'ların hâlâ geçerli olup olmadığını bil.

Robotik kodda bu özellikle büyük veri yapıları ve callback'ler içinde
önemlidir.

------------------------------------------------------------------------

# 31. `std::string` ve `std::string_view`

Normal string:

``` cpp
std::string command = "MOVE";
```

Modern C++'ta ayrıca:

``` cpp
std::string_view command = "MOVE";
```

görebilirsin.

`string_view` genellikle mevcut karakter dizisini **sahiplenmeden**
görüntülemek için kullanılır.

Bu nedenle önemli soru:

> Bu veri bana mı ait, yoksa sadece ona bakıyor muyum?

`std::string` sahip olabilir.

`std::string_view` sahip değildir.

Bu nedenle `string_view` kullanırken referans verdiği verinin lifetime'ı
kritik hale gelir.

------------------------------------------------------------------------

# 32. `enum class` ile Sağlam State Machine

Robotik için çok önemli bir desen:

``` cpp
enum class RobotState
{
    IDLE,
    MOVING,
    ERROR
};
```

Sonra:

``` cpp
RobotState state = RobotState::IDLE;
```

Karar:

``` cpp
switch (state)
{
case RobotState::IDLE:
    // bekle
    break;

case RobotState::MOVING:
    // hareket et
    break;

case RobotState::ERROR:
    // güvenli dur
    break;
}
```

Bunu gerçek bir robot mantığına çevirebilirsin:

``` text
IDLE
 │
 ├── start → MOVING
 │
 └── error → ERROR

MOVING
 │
 ├── target reached → IDLE
 │
 └── error → ERROR

ERROR
 │
 └── reset → IDLE
```

Bu yapı ROS2 node'larında da davranış yönetimi için kullanılabilir.

------------------------------------------------------------------------

# 33. `switch` ile State Machine Tasarımı

State machine yazarken sadece `switch` kullanmak yetmez.

Ayrıca **geçişleri** açıkça düşün:

``` cpp
if (state == RobotState::MOVING && obstacle_detected)
{
    state = RobotState::ERROR;
}
```

Daha iyi tasarımda geçişler ayrı fonksiyonlara ayrılabilir:

``` cpp
void handle_state();
void update_state();
void enter_error_state();
```

Böylece:

``` text
sensör okuma
     ↓
durum güncelleme
     ↓
karar
     ↓
motor komutu
```

pipeline'ı görünür hale gelir.

------------------------------------------------------------------------

# 34. Constructor ve Member Initializer List

Şunu yazmak mümkündür:

``` cpp
class Robot
{
private:
    std::string name_;
    double speed_;

public:
    Robot(std::string name, double speed)
    {
        name_ = name;
        speed_ = speed;
    }
};
```

Ama tercih edilen yapı:

``` cpp
Robot(std::string name, double speed)
    : name_(std::move(name)),
      speed_(speed)
{
}
```

Burada member initializer list kullanılır.

Özellikle şu tiplerde kritik:

``` cpp
const int id_;
std::string name_;
Sensor sensor_;
```

Çünkü bu üyeler constructor gövdesine girildikten sonra "sonradan
başlatılmak" yerine doğrudan initialize edilebilir.

------------------------------------------------------------------------

# 35. Constructor Overloading

Bir sınıfın birden fazla constructor'ı olabilir:

``` cpp
class Robot
{
public:
    Robot();
    Robot(std::string name);
    Robot(std::string name, double max_speed);
};
```

Örneğin:

``` cpp
Robot a;
Robot b("Robot1");
Robot c("Robot2", 2.5);
```

Bu, farklı kullanım senaryoları için API sağlar.

Ancak çok fazla constructor oluşturmak yerine mantıklı varsayılanlar ve
açık parametreler kullanmak daha okunabilirdir.

------------------------------------------------------------------------

# 36. `explicit`

Tek parametreli constructor'larda önemli bir C++ özelliği:

``` cpp
class Distance
{
public:
    Distance(double meters);
};
```

Bu constructor implicit conversion'a izin verebilir.

Örneğin:

``` cpp
Distance d = 5.0;
```

Bunu istemiyorsan:

``` cpp
explicit Distance(double meters);
```

yazabilirsin.

Robotikte bu, yanlışlıkla birimlerin birbirine dönüşmesini engellemede
yararlı olabilir.

Örneğin:

``` text
Meters
Degrees
Radians
Seconds
```

gibi fiziksel büyüklükler söz konusu olduğunda tip güvenliği önemlidir.

------------------------------------------------------------------------

# 37. Destructor ve RAII'yi Gerçekten Anlamak

RAII:

> Bir kaynağın yaşam süresini bir nesnenin yaşam süresine bağlama
> yaklaşımıdır.

Kaynaklar:

-   heap belleği
-   dosya
-   mutex
-   socket
-   serial port
-   hardware handle
-   GPU resource

olabilir.

Örneğin:

``` cpp
{
    std::ofstream log("robot.log");

    log << "Robot started\n";
}
```

Scope sona erdiğinde `log` nesnesinin destructor'ı çalışır.

Bu sayede dosyanın kapatılması nesnenin yaşam süresine bağlanır.

Modern C++ düşüncesi:

``` text
Kaynağı aldım
    ↓
Nesneyi oluşturdum
    ↓
Nesne yaşadığı sürece kaynak kullanılabilir
    ↓
Nesne yok oldu
    ↓
Kaynak otomatik bırakıldı
```

------------------------------------------------------------------------

# 38. Rule of 0, 3 ve 5

Modern C++ öğrenirken ileride karşılaşacağın önemli konu.

## Rule of 0

Sınıfın kaynak yönetimini STL/smart pointer gibi RAII nesnelerine
bırakırsan çoğu zaman:

``` cpp
class Robot
{
    std::string name_;
    std::vector<double> data_;
};
```

için destructor/copy/move fonksiyonlarını elle yazmana gerek kalmaz.

Bu ideal durumdur.

## Rule of 3

Eski/manuel resource-management kodunda destructor, copy constructor ve
copy assignment gibi özel member fonksiyonları birlikte önem kazanır.

## Rule of 5

Modern C++'ta move constructor ve move assignment da devreye girer.

Şimdilik ana fikir:

> **Kendi resource-management sınıfını yazmak zorunda değilsen yazma.**

STL ve RAII kullan.

------------------------------------------------------------------------

# 39. Copy ve Move Semantiği

C'de:

``` c
memcpy(...)
```

gibi zihinsel modeller yaygındır.

C++'ta bir nesnenin:

``` text
copy
move
```

davranışları ayrı kavramlardır.

## Copy

``` cpp
std::string a = "robot";
std::string b = a;
```

Burada `b`, `a`'nın kopyasıdır.

İki nesne bağımsızdır.

## Move

``` cpp
std::string a = "robot";
std::string b = std::move(a);
```

Burada amaç, kaynak içindeki pahalı kaynakların mümkünse kopyalanmak
yerine devredilmesidir.

Önemli:

``` cpp
std::move(...)
```

tek başına hiçbir şeyi "hareket ettirmez".

O, bir ifadeyi **move'a uygun bir değer kategorisiyle** kullanabilmek
için cast benzeri bir araçtır.

Asıl move constructor/assignment çalışır.

------------------------------------------------------------------------

# 40. `std::move` Kullanırken En Önemli Kural

Şunu yazdıktan sonra:

``` cpp
std::string name = "Robot";
std::string other = std::move(name);
```

`name` hâlâ geçerli bir nesnedir ama içeriğinin ne olduğuna
güvenmemelisin.

Genel prensip:

> Moved-from nesne kullanılabilir bir durumda olmalıdır, fakat değerini
> varsayma.

Bu nedenle:

``` cpp
std::move(name);
std::cout << name;
```

gibi kodlar çoğu durumda tasarım açısından şüphelidir.

------------------------------------------------------------------------

# 41. `unique_ptr`

En basit sahiplik modeli:

``` cpp
auto sensor = std::make_unique<Sensor>();
```

Burada tek sahip vardır.

Kopyalayamazsın:

``` cpp
auto sensor2 = sensor; // hata
```

Ama taşıyabilirsin:

``` cpp
auto sensor2 = std::move(sensor);
```

Sahiplik:

``` text
sensor
   │
   └── owns Sensor

move
   ↓

sensor2
   │
   └── owns Sensor
```

Robotik kullanım:

``` cpp
class Robot
{
private:
    std::unique_ptr<MotorController> motor_;
};
```

Robot controller motorun tek sahibiyse bu model anlamlıdır.

------------------------------------------------------------------------

# 42. `shared_ptr`

Birden fazla sahibin bulunması gerekiyorsa:

``` cpp
auto sensor = std::make_shared<Sensor>();

auto another_owner = sensor;
```

İki `shared_ptr` aynı nesneyi sahiplenir.

Reference count mantığı:

``` text
sensor
   │
   ├── owner 1
   └── owner 2

count = 2
```

Bir owner yok olduğunda:

``` text
count = 1
```

Son owner da yok olduğunda:

``` text
count = 0
       ↓
resource destroyed
```

Ancak önemli bir tasarım prensibi:

> "shared_ptr var çünkü kolay" iyi bir mimari gerekçe değildir.

Önce gerçekten **shared ownership** gerekip gerekmediğini sor.

------------------------------------------------------------------------

# 43. `weak_ptr`

`weak_ptr`, sahiplik oluşturmaz.

``` cpp
std::weak_ptr<Sensor> observer = sensor;
```

Daha sonra:

``` cpp
if (auto locked = observer.lock())
{
    locked->read();
}
```

ile nesne hâlâ yaşıyor mu kontrol edebilirsin.

Önemli kullanım alanlarından biri circular ownership:

``` text
A shared_ptr → B
B shared_ptr → A
```

Bu durumda iki nesne birbirini yaşatabilir.

`weak_ptr` ile ownership döngüsü kırılabilir.

------------------------------------------------------------------------

# 44. Pointer Karar Ağacı

Bir pointer gördüğünde:

### 1. Sahiplik var mı?

Hayır:

``` cpp
T*
```

veya daha güvenli şekilde:

``` cpp
T&
const T&
```

kullanılabilir.

### 2. Tek sahip var mı?

``` cpp
std::unique_ptr<T>
```

### 3. Gerçekten ortak sahiplik mi?

``` cpp
std::shared_ptr<T>
```

### 4. Ortak sahipliği gözlemlemek mi istiyorsun?

``` cpp
std::weak_ptr<T>
```

Bu karar ağacını ezberlemekten daha değerlidir.

------------------------------------------------------------------------

# 45. Exception Tasarımı

Exception:

``` cpp
throw std::runtime_error("Sensor connection failed");
```

ile yukarı taşınabilir.

Yakalama:

``` cpp
try
{
    sensor.connect();
}
catch (const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
```

Ancak robotikte önemli nüans:

> Her hata için exception kullanmak zorunda değilsin.

Örneğin yüksek frekanslı bir kontrol döngüsünde normal çalışma sırasında
exception üretmek tasarım açısından uygun olmayabilir.

Hata kategorilerini ayır:

``` text
Normal durum
    ↓
return value / status

Beklenmeyen veya nadir hata
    ↓
exception

Programlanması mümkün olmayan kritik durum
    ↓
assert / fail-safe / shutdown strategy
```

------------------------------------------------------------------------

# 46. `std::optional`

Bir fonksiyonun bazen değer döndürmemesi gerekiyorsa:

``` cpp
std::optional<double> read_distance();
```

Örneğin:

``` cpp
auto distance = sensor.read_distance();

if (distance)
{
    std::cout << *distance << '\n';
}
```

Buradaki anlam:

``` text
değer var
veya
değer yok
```

Bu, "hata için özel magic number" kullanmaktan daha temiz olabilir.

Kötü örnek:

``` cpp
return -9999.0;
```

Çünkü gerçek bir ölçümün de benzer değerde olması veya bu özel değerin
unutulması mümkündür.

------------------------------------------------------------------------

# 47. `std::variant`

Bir verinin birkaç farklı tipten biri olabileceği durumlarda:

``` cpp
std::variant<int, double, std::string> value;
```

kullanılabilir.

Robot komutları için örnek:

``` text
MoveCommand
RotateCommand
StopCommand
```

gibi farklı veri tiplerini tek bir mesaj yapısında modellemek için
kullanılabilir.

Bu konu ROS2'ye geçerken şart değil, fakat modern C++ kodunu okurken
karşılaşabileceğin bir araçtır.

------------------------------------------------------------------------

# 48. `std::tuple`

Birden fazla farklı değeri bir arada taşıyabilir:

``` cpp
auto result = std::make_tuple(1.0, 2.0, 3.0);
```

Ancak robotik kodda çoğu zaman:

``` cpp
struct Position
{
    double x;
    double y;
    double z;
};
```

daha açıklayıcıdır.

Genel prensip:

> Kodun anlamını artırıyorsa `struct`; sadece geçici bir grup değer
> gerekiyorsa `tuple`.

------------------------------------------------------------------------

# 49. Templates --- Generic Programming

Template:

``` cpp
template <typename T>
T square(T value)
{
    return value * value;
}
```

Artık:

``` cpp
square(3);
square(3.5);
```

gibi farklı tiplerle çalışabilir.

Robotikte:

``` cpp
template <typename T>
class PID
{
private:
    T kp_;
    T ki_;
    T kd_;

public:
    PID(T kp, T ki, T kd)
        : kp_(kp), ki_(ki), kd_(kd)
    {
    }
};
```

şeklinde bir yapı düşünülebilir.

Sonra:

``` cpp
PID<float> pid_float(...);
PID<double> pid_double(...);
```

kullanılabilir.

------------------------------------------------------------------------

# 50. Template ile Overloading Farkı

Overloading:

``` cpp
void move(int distance);
void move(double distance);
```

Template:

``` cpp
template <typename T>
void move(T distance);
```

Overloading'de farklı fonksiyonlar tanımlarsın.

Template'de bir **genel kalıp** tanımlarsın.

------------------------------------------------------------------------

# 51. Lambda Capture

Basit lambda:

``` cpp
[](int x)
{
    return x * 2;
}
```

Dışarıdan değişken kullanmak:

``` cpp
double offset = 1.5;

auto calibrate = [offset](double value)
{
    return value + offset;
};
```

`[offset]` capture'dır.

Reference capture:

``` cpp
[&offset]
```

tüm dış değişkenleri capture etmek:

``` cpp
[&]
```

de mümkündür.

Ancak büyük kodlarda `[&]` kullanımı lifetime ve okunabilirlik açısından
dikkat gerektirir.

Robotik callback'lerde lambda gördüğünde özellikle capture kısmını
incele.

------------------------------------------------------------------------

# 52. STL Algorithms

C++'ta sadece container öğrenmek yetmez.

Örneğin:

``` cpp
std::sort(values.begin(), values.end());
```

ve:

``` cpp
std::find(values.begin(), values.end(), 42);
```

gibi algoritmalar vardır.

Diğer önemli araçlar:

``` text
std::sort
std::find
std::find_if
std::count
std::count_if
std::transform
std::for_each
std::remove
std::copy
std::max_element
std::min_element
```

Robotik örnek:

``` cpp
auto closest = std::min_element(
    distances.begin(),
    distances.end()
);
```

Bu, elle döngü yazmadan minimum değeri bulmayı sağlar.

------------------------------------------------------------------------

# 53. `erase` ve `remove` İdiomu

Önemli STL deseni:

``` cpp
values.erase(
    std::remove(values.begin(), values.end(), 0),
    values.end()
);
```

`remove` fiziksel olarak container boyutunu küçültmez.

`erase` gerçekten elemanları siler.

Bu ayrımı bilmek STL kodunu okurken önemlidir.

------------------------------------------------------------------------

# 54. `map` mi `unordered_map` mi?

`std::map`:

``` cpp
std::map<std::string, int> sensors;
```

anahtarları sıralı tutar.

`std::unordered_map`:

``` cpp
std::unordered_map<std::string, int> sensors;
```

hash table yaklaşımı kullanır.

Genel fark:

``` text
map
→ sıralı
→ ağaç tabanlı yapı
→ logaritmik arama davranışı

unordered_map
→ sıralama garantisi yok
→ hash tabanlı
→ ortalama O(1) lookup
```

Robotik config:

``` cpp
unordered_map<std::string, double> parameters;
```

gibi kullanılabilir.

Ancak deterministik sıralama gerekiyorsa `map` daha uygun olabilir.

------------------------------------------------------------------------

# 55. Queue, Mutex ve Thread Birlikte

Robotik yazılımın tipik mantığı:

``` text
Sensor Thread
     │
     ↓
   Queue
     │
     ↓
Processing Thread
     │
     ↓
  Command Queue
     │
     ↓
Control Thread
```

Birden fazla thread aynı queue'ya erişirse synchronization gerekir.

------------------------------------------------------------------------

# 56. `std::mutex`

Paylaşılan veriyi korumak:

``` cpp
std::mutex mutex;
int sensor_value = 0;

void update()
{
    std::lock_guard<std::mutex> lock(mutex);
    sensor_value++;
}
```

`lock_guard`, mutex'i scope boyunca kilitli tutar.

Scope sona erince otomatik unlock olur.

Bu yine RAII'dir.

``` text
constructor
    ↓
lock

destructor
    ↓
unlock
```

------------------------------------------------------------------------

# 57. Neden `lock_guard` Önemli?

Şu yaklaşım risklidir:

``` cpp
mutex.lock();

do_something();

mutex.unlock();
```

Eğer `do_something()` sırasında exception veya erken return olursa
unlock unutulabilir.

RAII:

``` cpp
std::lock_guard<std::mutex> lock(mutex);
```

ile:

``` text
lock
 ↓
işlem
 ↓
scope sonu
 ↓
unlock
```

garanti altına alınır.

------------------------------------------------------------------------

# 58. Data Race Nedir?

İki thread aynı belleğe erişiyorsa ve en az biri yazıyorsa
synchronization olmadan:

``` text
Thread A → write
Thread B → read/write
```

data race oluşabilir.

Örneğin:

``` cpp
int counter = 0;
```

iki thread'in aynı anda:

``` cpp
counter++;
```

yapması güvenli değildir.

Çözüm her zaman mutex olmak zorunda değildir; `std::atomic` de
kullanılabilir.

------------------------------------------------------------------------

# 59. `std::atomic`

Basit shared state için:

``` cpp
std::atomic<bool> running{true};
```

bir thread:

``` cpp
running = false;
```

diğeri:

``` cpp
while (running)
{
}
```

şeklinde kullanabilir.

Ancak atomic:

> "Bütün thread problemlerini çözer"

demek değildir.

Birden fazla değişkenin birlikte tutarlı olması gerekiyorsa daha
kapsamlı synchronization gerekir.

------------------------------------------------------------------------

# 60. `condition_variable`

Bir thread'in sürekli:

``` cpp
while (queue.empty())
{
}
```

şeklinde beklemesi CPU tüketebilir.

Bunun yerine condition variable kullanılabilir:

``` text
Producer
   ↓
push data
   ↓
notify

Consumer
   ↓
wait
   ↓
wake
   ↓
process
```

Robotik veri pipeline'larında bu desen çok değerlidir.

------------------------------------------------------------------------

# 61. Thread Lifecycle

Bir thread:

``` cpp
std::thread worker(task);
```

ile oluşturulduğunda yönetilmelidir.

Örneğin:

``` cpp
worker.join();
```

veya uygun durumda:

``` cpp
worker.detach();
```

kullanılabilir.

Genel olarak `detach()` dikkat gerektirir; thread'in yaşam süresi ile
bağlı kaynakların yaşam süresini kontrol etmek zorlaşabilir.

Modern C++ tarafında ileride `std::jthread` de görebilirsin.

------------------------------------------------------------------------

# 62. `chrono` ve Robot Kontrol Frekansı

Robot kontrol döngüsü:

``` text
10 Hz  → 100 ms
20 Hz  → 50 ms
50 Hz  → 20 ms
100 Hz → 10 ms
```

Dönüşüm:

``` text
period = 1 / frequency
```

C++:

``` cpp
using namespace std::chrono_literals;

std::this_thread::sleep_for(10ms);
```

Ancak gerçek kontrol döngüsünde sadece:

``` cpp
sleep_for(10ms);
```

demek kusursuz 100 Hz garanti etmez.

Çünkü hesaplama süresi de vardır.

Daha doğru zihinsel model:

``` text
iteration start
     ↓
sensor read
     ↓
compute
     ↓
command
     ↓
remaining time
     ↓
sleep
     ↓
next iteration
```

------------------------------------------------------------------------

# 63. `steady_clock` Neden Kontrol Döngüsünde?

Geçen zamanı ölçmek için:

``` cpp
std::chrono::steady_clock::now();
```

uygundur.

Sistem saatinin değişmesi elapsed-time hesabını bozmamalıdır.

Örneğin:

``` cpp
auto start = std::chrono::steady_clock::now();

// computation

auto end = std::chrono::steady_clock::now();

auto elapsed = end - start;
```

Bu yaklaşım:

-   performans ölçümü
-   kontrol loop timing
-   timeout

gibi işlerde kullanışlıdır.

------------------------------------------------------------------------

# 64. Dosya I/O ve RAII

Şu kullanım:

``` cpp
std::ofstream log("robot.log");

if (!log)
{
    std::cerr << "Cannot open log file\n";
    return;
}

log << "Robot started\n";
```

dosya nesnesini scope'a bağlar.

Ayrıca CSV gibi formatlarla basit telemetry kaydı yapılabilir:

``` text
timestamp,x,y,theta
0.00,0.0,0.0,0.0
0.10,0.1,0.0,0.02
0.20,0.2,0.01,0.03
```

Bu veriler daha sonra:

-   plotting
-   hata analizi
-   sensor calibration
-   controller tuning

için kullanılabilir.

------------------------------------------------------------------------

# 65. Birim Hataları --- Robotikte Sessiz Tehlike

Şu iki değer aynı tiptedir:

``` cpp
double angle1 = 90.0;
double angle2 = 1.5708;
```

Ama biri derece, diğeri radyan olabilir.

C++ bunu otomatik olarak anlayamaz.

Bu nedenle değişken isimleri:

``` cpp
double angle_deg;
double angle_rad;
```

gibi olabilir.

Daha ileri seviye tasarımda farklı birim türleri ayrı sınıflarla
modellenebilir.

Temel prensip:

> Robotik kodda birimleri kodun parçası olarak düşün.

------------------------------------------------------------------------

# 66. Floating-Point Hataları

Şunu bekleme:

``` cpp
0.1 + 0.2 == 0.3
```

her zaman matematikteki kadar temiz davranacaktır.

Floating-point temsilinin sınırlamaları vardır.

Bu yüzden:

``` cpp
if (a == b)
```

yerine belirli durumlarda tolerans:

``` cpp
std::abs(a - b) < epsilon
```

kullanılabilir.

Robotikte:

-   encoder
-   IMU
-   odometry
-   localization
-   controller

hesaplarında bu konu önemlidir.

------------------------------------------------------------------------

# 67. `std::abs`, `std::sqrt`, `std::sin`, `std::cos`

Robotik matematikte temel araçlar:

``` cpp
std::abs(x);
std::sqrt(x);
std::sin(theta);
std::cos(theta);
std::atan2(y, x);
```

Özellikle:

``` cpp
std::atan2(y, x);
```

yön/heading hesaplarında çok önemlidir.

Örneğin:

``` cpp
double heading = std::atan2(dy, dx);
```

Bir vektörün yönünü hesaplamak için kullanılabilir.

------------------------------------------------------------------------

# 68. `std::hypot`

Mesafe:

``` cpp
double distance =
    std::sqrt(dx * dx + dy * dy);
```

yerine:

``` cpp
double distance = std::hypot(dx, dy);
```

ile ifade edilebilir.

Bu hem okunabilirlik hem de sayısal davranış açısından yararlı olabilir.

------------------------------------------------------------------------

# 69. Header Tasarımı

Modern bir header:

``` cpp
#pragma once

#include <string>

class Robot
{
public:
    Robot(std::string name);

    void move(double distance);

    std::string name() const;

private:
    std::string name_;
};
```

Implementation:

``` cpp
#include "robot.hpp"

Robot::Robot(std::string name)
    : name_(std::move(name))
{
}

void Robot::move(double distance)
{
    // ...
}

std::string Robot::name() const
{
    return name_;
}
```

Header'ın amacı:

> Kullanıcının sınıfı kullanmak için bilmesi gereken interface'i
> göstermek.

------------------------------------------------------------------------

# 70. Include Dependency'lerini Küçük Tut

Bir header:

``` cpp
#include <iostream>
#include <vector>
#include <map>
#include <thread>
#include <random>
```

gibi gereksiz bağımlılıklarla doluysa derleme maliyeti artabilir.

Mümkün olduğunca:

``` text
header
 ↓
minimum gerekli include

cpp
 ↓
implementation-specific include
```

ayrımı yap.

Bu, büyük ROS2 workspace'lerinde önem kazanır.

------------------------------------------------------------------------

# 71. `#pragma once` ve Include Guard

İki yaygın yöntem:

``` cpp
#pragma once
```

ve:

``` cpp
#ifndef ROBOT_HPP
#define ROBOT_HPP

// ...

#endif
```

İkisi de header'ın tekrar tekrar işlenmesini önlemeye yöneliktir.

Mevcut ders notlarında include guard örneği gösterilmiştir; gerçek
projelerde `#pragma once` da çok yaygındır.

------------------------------------------------------------------------

# 72. Namespace Tasarımı

Kendi robot kütüphaneni yazarken:

``` cpp
namespace robot
{
class Motor
{
};
}
```

kullanabilirsin.

Sonra:

``` cpp
robot::Motor motor;
```

Bu, büyük projelerde isim çakışmalarını azaltır.

ROS2 kodunda da namespace'leri sık göreceksin:

``` cpp
rclcpp::
std::
geometry_msgs::
sensor_msgs::
```

Bunları "gereksiz uzun isimler" olarak değil:

> **Bu tip hangi kütüphaneden geliyor?**

sorusunun cevabı olarak düşün.

------------------------------------------------------------------------

# 73. CMake'e Geçiş İçin Temel Zihin Haritası

C++ kodunun:

``` text
.hpp
.cpp
```

olarak ayrılması yetmez.

Bunların derlenmesi gerekir.

Basit bir proje:

``` text
robot_project/
├── CMakeLists.txt
├── include/
│   └── robot.hpp
├── src/
│   ├── robot.cpp
│   └── main.cpp
└── build/
```

CMake:

``` cmake
cmake_minimum_required(VERSION 3.16)

project(robot_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(robot
    src/main.cpp
    src/robot.cpp
)

target_include_directories(robot PRIVATE include)
```

Bu yapı ROS2'de `ament_cmake` öğrenirken çok işine yarayacaktır.

------------------------------------------------------------------------

# 74. Compilation Pipeline

C++ kodunun çalışma sürecini bil:

``` text
.cpp
 ↓
Preprocessor
 ↓
Compiler
 ↓
Object file
 ↓
Linker
 ↓
Executable
```

Header:

``` cpp
#include "robot.hpp"
```

preprocessor aşamasında ilgili içeriğin kullanılmasını sağlar.

Compiler:

``` text
.cpp → .o
```

Linker:

``` text
birden fazla .o
   +
libraries
   ↓
executable
```

Bu yüzden bazen:

``` text
compilation error
```

ile:

``` text
linker error
```

aynı şey değildir.

------------------------------------------------------------------------

# 75. "Undefined Reference" Nedir?

Örneğin header:

``` cpp
class Robot
{
public:
    void move();
};
```

ama implementation dosyası build'e dahil edilmemişse:

``` text
undefined reference to Robot::move()
```

gibi linker hatası görebilirsin.

Zihinsel model:

``` text
Declaration var
Implementation var
ama linker implementation'ı bulamıyor
```

Bu ayrımı öğrenmek CMake/ROS2 build hatalarını anlamayı çok
kolaylaştırır.

------------------------------------------------------------------------

# 76. Debugging: Compiler Warnings

C++ öğrenirken compiler'ı mümkün olduğunca konuşkan kullan.

GCC ile tipik:

``` bash
-Wall
-Wextra
-Wpedantic
```

uyarıları değerlidir.

Örneğin:

``` cpp
if (command = 'f')
```

gibi bir hatayı compiler warning ile yakalama ihtimalini artırabilirsin.

Temel prensip:

> Warning'leri "önemsiz sarı mesajlar" olarak görme.

Bir warning bazen gelecekteki runtime bug'ının ilk belirtisidir.

------------------------------------------------------------------------

# 77. GDB ile C++ Debugging

Temel akış:

``` text
program crash
   ↓
gdb ile çalıştır
   ↓
breakpoint
   ↓
step
   ↓
inspect variable
   ↓
backtrace
```

Önemli komutlar:

``` text
break main
run
next
step
continue
print variable
backtrace
```

Pointer/memory hatalarında özellikle:

``` text
backtrace
```

çok değerlidir.

------------------------------------------------------------------------

# 78. Segmentation Fault'u Anlamak

Tipik örnek:

``` cpp
int* ptr = nullptr;

*ptr = 10;
```

Program geçersiz belleğe erişmeye çalışır.

Başka örnek:

``` cpp
std::vector<int> values = {1, 2, 3};

std::cout << values[100];
```

`operator[]` sınır kontrolü yapmaz.

Debug amaçlı:

``` cpp
values.at(100);
```

bounds check yapabilir ve hata durumunu daha görünür hale getirebilir.

------------------------------------------------------------------------

# 79. Undefined Behavior (UB)

C/C++'ta bazı hatalar:

> "Program kesin şöyle davranır."

şeklinde tanımlanamaz.

Örneğin:

-   geçersiz pointer dereference
-   array sınırı aşma
-   lifetime sona ermiş nesneye erişme
-   bazı signed integer overflow durumları

undefined behavior kapsamına girebilir.

Bu yüzden:

> "Benim bilgisayarımda çalışıyor."

bir doğruluk kanıtı değildir.

Robotikte UB özellikle tehlikelidir çünkü davranış donanım, compiler ve
optimizasyon seviyesine göre değişebilir.

------------------------------------------------------------------------

# 80. `at()` ve `operator[]`

Vector:

``` cpp
values[i];
```

hızlı ve unchecked erişim sağlar.

``` cpp
values.at(i);
```

bounds checking yapar.

Debugging/validasyon sırasında `at()` daha açıklayıcı olabilir.

------------------------------------------------------------------------

# 81. `assert`

Programlama varsayımını kontrol etmek için:

``` cpp
#include <cassert>

assert(speed >= 0.0);
```

kullanılabilir.

Örneğin:

``` cpp
double normalize(double value)
{
    assert(value >= 0.0);
    // ...
}
```

`assert` kullanıcı input validation'ın yerine geçmez.

Daha çok:

> "Programcı olarak bu koşulun doğru olması gerektiğine inanıyorum."

demektir.

------------------------------------------------------------------------

# 82. Logging Düşüncesi

Robotik debugging'de:

``` cpp
std::cout
```

öğrenmek başlangıç için yeterlidir.

Fakat gerçek robotik sistemlerde:

``` text
INFO
WARN
ERROR
DEBUG
```

seviyeleri ve timestamp/thread/node bilgileri önem kazanır.

ROS2'de daha sonra:

``` text
RCLCPP_INFO
RCLCPP_WARN
RCLCPP_ERROR
RCLCPP_DEBUG
```

gibi loglama araçları göreceksin.

Şimdilik amaç:

> Log'un sadece "bir şey yazdırmak" olmadığını anlamak.

------------------------------------------------------------------------

# 83. C++ ile Robotik Veri Pipeline'ı

Şu sistemi düşün:

``` text
Sensor
  ↓
raw data
  ↓
validation
  ↓
calibration
  ↓
filter
  ↓
state estimation
  ↓
controller
  ↓
actuator
```

C++ konularını bu pipeline'a yerleştir:

  Pipeline      C++ konusu
  ------------- ------------------------
  Sensor        class
  raw data      struct
  validation    if / optional
  calibration   function
  buffer        vector / deque
  filtering     algorithms / templates
  state         enum class
  ownership     smart pointer
  controller    class / polymorphism
  actuator      interface
  timing        chrono
  concurrency   thread / mutex
  logging       streams / file I/O

Bu tabloyu ezberlemekten ziyade **neden her parçanın orada olduğunu**
anlamaya çalış.

------------------------------------------------------------------------

# 84. Örnek Mini Mimari: Sensor → Processor → Controller

``` cpp
struct SensorData
{
    double distance;
    double timestamp;
};

class Sensor
{
public:
    SensorData read();
};

class Processor
{
public:
    bool obstacle_detected(const SensorData& data) const;
};

class Controller
{
public:
    void stop();
    void move_forward();
};
```

Ana akış:

``` cpp
Sensor sensor;
Processor processor;
Controller controller;

while (running)
{
    SensorData data = sensor.read();

    if (processor.obstacle_detected(data))
    {
        controller.stop();
    }
    else
    {
        controller.move_forward();
    }
}
```

Bu küçük örnekte bile:

-   class
-   struct
-   reference
-   const
-   function
-   loop

bir araya geliyor.

------------------------------------------------------------------------

# 85. Bu Mimariyi ROS2'ye Taşıdığında

Daha sonra yapı kabaca:

``` text
ROS2 Node
 │
 ├── Subscriber
 │       ↓
 │   Sensor Message
 │       ↓
 │   Processor
 │       ↓
 │   Controller
 │       ↓
 └── Publisher
```

olabilir.

C++ temelinin amacı tam olarak budur:

> ROS2 syntax'ını ezberlemek yerine ROS2'nin kullandığı C++ yapılarını
> okuyabilecek hale gelmek.

------------------------------------------------------------------------

# 86. ROS2'ye Geçerken Karşına Çıkacak C++ Kalıpları

Daha sonra şu tür kodlar gördüğünde yabancılık çekmemen gerekir:

``` cpp
class RobotNode : public rclcpp::Node
{
public:
    RobotNode()
        : Node("robot_node")
    {
        publisher_ =
            create_publisher<std_msgs::msg::String>("status", 10);
    }

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};
```

Burada birden fazla C++ konusu aynı anda vardır:

``` text
class
inheritance
constructor
initializer list
template
namespace
smart pointer
member variable
```

Bu nedenle C++'ı sadece:

``` text
for
if
vector
class
```

seviyesinde bırakmamak gerekir.

------------------------------------------------------------------------

# 87. Callback Mantığı

ROS2'de bir callback kabaca:

``` cpp
void callback(const MessageType::SharedPtr msg)
{
    // gelen mesajı işle
}
```

şeklinde olabilir.

Burada:

``` cpp
const
SharedPtr
pointer
function parameter
```

gibi kavramların hepsi C++ temelinden gelir.

Callback'i gördüğünde:

> "Bu garip ROS2 syntax'ı."

deme.

Şöyle parçala:

``` text
void
 ↓
return type

callback
 ↓
function name

const MessageType::SharedPtr
 ↓
parameter type
```

------------------------------------------------------------------------

# 88. Template Syntax'ı Okuma

Şu ifade:

``` cpp
std::vector<double>
```

şu şekilde okunabilir:

``` text
vector
   ↓
double tipindeki elemanları taşıyor
```

Şu:

``` cpp
std::shared_ptr<Sensor>
```

şu demektir:

``` text
shared_ptr
   ↓
Sensor nesnesine sahip
```

Şu:

``` cpp
create_publisher<MessageType>()
```

şu:

``` text
create_publisher
       ↓
hangi mesaj tipi?
       ↓
MessageType
```

Template syntax'ını bu şekilde parçalamak ROS2 kodunu ciddi biçimde
kolaylaştırır.

------------------------------------------------------------------------

# 89. Polymorphism'i Gerçek Robot Sistemine Uygulamak

Interface:

``` cpp
class Motor
{
public:
    virtual ~Motor() = default;

    virtual void set_speed(double speed) = 0;
};
```

Gerçek motor:

``` cpp
class Esp32Motor : public Motor
{
public:
    void set_speed(double speed) override
    {
        // ESP32 iletişimi
    }
};
```

Simülasyon motoru:

``` cpp
class SimulatedMotor : public Motor
{
public:
    void set_speed(double speed) override
    {
        // simulation
    }
};
```

Controller:

``` cpp
class Controller
{
public:
    void drive(Motor& motor)
    {
        motor.set_speed(1.0);
    }
};
```

Controller:

``` text
gerçek motor
      veya
simülasyon motoru
```

olduğunu bilmek zorunda değildir.

Bu, test edilebilirlik açısından da çok değerlidir.

------------------------------------------------------------------------

# 90. Virtual Destructor Neden Önemli?

Base class üzerinden polymorphic deletion yapıyorsan:

``` cpp
class Base
{
public:
    virtual ~Base() = default;
};
```

gibi virtual destructor tasarımı gerekir.

Örneğin:

``` cpp
std::unique_ptr<Base> object =
    std::make_unique<Derived>();
```

base interface üzerinden nesnenin doğru şekilde yok edilmesi önemlidir.

Bu nedenle polymorphic base class tasarlarken:

``` cpp
virtual ~Base() = default;
```

desenini tanı.

------------------------------------------------------------------------

# 91. Composition mı Inheritance mı?

Robotikte her ilişki inheritance değildir.

Inheritance:

``` text
WheeledRobot IS-A Robot
```

Composition:

``` text
Robot HAS-A Motor
Robot HAS-A Sensor
Robot HAS-A Controller
```

Örneğin:

``` cpp
class Robot
{
private:
    Motor motor_;
    Sensor sensor_;
};
```

Çoğu sistemde composition çok güçlüdür.

Genel soru:

> "Bu sınıf gerçekten diğer sınıfın bir türü mü?"

Değilse inheritance yerine composition düşün.

------------------------------------------------------------------------

# 92. Dependency Injection'ın Basit Hali

Controller'ın motoru kendisinin oluşturması:

``` cpp
class Controller
{
private:
    Motor motor_;
};
```

ile dışarıdan motor verilmesi:

``` cpp
class Controller
{
private:
    Motor& motor_;

public:
    Controller(Motor& motor)
        : motor_(motor)
    {
    }
};
```

arasında mimari fark vardır.

İkincisi testte:

``` cpp
FakeMotor fake_motor;
Controller controller(fake_motor);
```

gibi kullanılabilir.

Bu daha sonra unit testing için çok değerlidir.

------------------------------------------------------------------------

# 93. Test Edilebilir Robotik Kod

Kötü:

``` cpp
void move_robot()
{
    // doğrudan hardware register
    // doğrudan serial port
    // doğrudan global state
}
```

Daha test edilebilir:

``` text
Controller
   ↓
Motor interface
   ↓
RealMotor / FakeMotor
```

Böylece gerçek donanım olmadan controller davranışı test edilebilir.

Senin yalnızca ESP32 ile çalıştığın bir ortamda bu özellikle değerlidir:

``` text
Simulation / Fake
      ↓
algoritmayı test et

ESP32
      ↓
hardware davranışını test et
```

------------------------------------------------------------------------

# 94. C++ Proje Yapısı

Küçük robotik proje:

``` text
robot_sim/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── sensor.hpp
│   ├── controller.hpp
│   └── robot.hpp
├── src/
│   ├── sensor.cpp
│   ├── controller.cpp
│   ├── robot.cpp
│   └── main.cpp
├── tests/
│   └── ...
├── data/
│   └── sensor_log.csv
└── docs/
    └── ...
```

Bu yapı seni daha sonra ROS2 package düzenine hazırlayacaktır.

------------------------------------------------------------------------

# 95. README'de Ne Olmalı?

GitHub projesinde README sadece:

``` text
This is a robot project.
```

olmamalı.

En azından:

``` text
# Project Name

## What it does

## Architecture

## Features

## Build

## Run

## Example Output

## Debugging

## Lessons Learned

## Future Work
```

bulunabilir.

Özellikle senin roadmap'in açısından:

> **Document**

aşamasını atlama.

------------------------------------------------------------------------

# 96. Robotik Projesi İçin Önerilen İlk C++ Mini Proje

## "Robot Simulator"

Donanım gerektirmez.

Robot:

``` text
x
y
theta
battery
state
```

tutsun.

Örneğin:

``` cpp
struct Pose
{
    double x;
    double y;
    double theta;
};
```

State:

``` cpp
enum class RobotState
{
    IDLE,
    MOVING,
    ERROR
};
```

Sensor:

``` cpp
class DistanceSensor
{
public:
    double read();
};
```

Controller:

``` cpp
class RobotController
{
public:
    void update();
};
```

Command queue:

``` cpp
std::queue<std::string> commands;
```

Log:

``` cpp
std::ofstream log_file;
```

Timing:

``` cpp
std::chrono::steady_clock
```

Bu tek proje çok sayıda C++ konusunu birbirine bağlar.

------------------------------------------------------------------------

# 97. Projeyi Aşamalı Büyüt

### V1

``` text
Robot
Pose
State
move()
stop()
```

### V2

``` text
DistanceSensor
obstacle detection
```

### V3

``` text
queue
commands
```

### V4

``` text
priority_queue
emergency stop priority
```

### V5

``` text
thread
sensor loop
control loop
```

### V6

``` text
mutex
shared state
```

### V7

``` text
smart pointers
interfaces
polymorphism
```

### V8

``` text
CMake
README
Doxygen
GitHub
```

Bu noktada artık kurs örnekleri tek tek değil, **bir sistem olarak**
düşünmeye başlarsın.

------------------------------------------------------------------------

# 98. Öğrenme Görevleri

Her bölümden sonra kendine üç soru sor.

### Soru 1

> Bu syntax ne yapıyor?

### Soru 2

> C'de bunun karşılığı ne olurdu?

### Soru 3

> Robotikte nerede kullanırım?

Örneğin `unique_ptr`:

``` text
1. Tek sahipli dinamik nesne yönetimi.
2. C'de malloc/free + ownership convention.
3. Sensor/driver/controller resource ownership.
```

Üçüne de cevap veremiyorsan konu henüz bitmemiştir.

------------------------------------------------------------------------

# 99. Bilmen Gereken C++ Konuları --- Kontrol Listesi

## Temel

-   [ ] `std::cout`
-   [ ] `std::cin`
-   [ ] `std::cerr`
-   [ ] `std::string`
-   [ ] namespace
-   [ ] `const`
-   [ ] `auto`
-   [ ] type casting
-   [ ] `nullptr`

## Fonksiyonlar

-   [ ] declaration
-   [ ] definition
-   [ ] reference
-   [ ] pointer
-   [ ] `const T&`
-   [ ] overload
-   [ ] default arguments
-   [ ] lambda

## OOP

-   [ ] class
-   [ ] struct
-   [ ] constructor
-   [ ] destructor
-   [ ] initializer list
-   [ ] private/public/protected
-   [ ] static
-   [ ] inheritance
-   [ ] virtual
-   [ ] override
-   [ ] abstract class
-   [ ] composition

## Memory

-   [ ] stack
-   [ ] heap
-   [ ] lifetime
-   [ ] ownership
-   [ ] RAII
-   [ ] unique_ptr
-   [ ] shared_ptr
-   [ ] weak_ptr
-   [ ] move
-   [ ] copy

## STL

-   [ ] vector
-   [ ] array
-   [ ] deque
-   [ ] list
-   [ ] set
-   [ ] map
-   [ ] unordered_map
-   [ ] queue
-   [ ] stack
-   [ ] priority_queue
-   [ ] iterator
-   [ ] algorithms

## Concurrency

-   [ ] thread
-   [ ] mutex
-   [ ] lock_guard
-   [ ] atomic
-   [ ] condition_variable
-   [ ] chrono
-   [ ] timing

## Tooling

-   [ ] GCC
-   [ ] warnings
-   [ ] GDB
-   [ ] CMake
-   [ ] header/source separation
-   [ ] Git
-   [ ] Doxygen

------------------------------------------------------------------------

# 100. "Junior Robotics C++" Seviyesinde Ne Kadarını Bilmelisin?

Her şeyi uzman seviyesinde bilmek gerekmiyor.

## Mutlaka rahat ol

``` text
class
struct
constructor
const
reference
pointer
vector
string
map
queue
enum class
lambda
auto
smart pointer
RAII
inheritance
virtual
CMake
GDB
```

## Okuyabilecek seviyede ol

``` text
templates
move semantics
weak_ptr
mutex
atomic
condition_variable
variant
optional
advanced STL algorithms
```

## Daha sonra derinleşebilir

``` text
metaprogramming
concepts
coroutines
custom allocators
advanced template machinery
lock-free programming
expression templates
```

Bunlar junior robotics başvurusu öncesinde ana çalışma hattının önüne
geçmemeli.

------------------------------------------------------------------------

# 101. Sık Yapılan Hatalar

## Hata 1 --- Her şeyi ezberlemeye çalışma

C++ çok büyük bir dil.

Amaç:

> Her şeyi ezberlemek değil, doğru aracı tanımak ve gerektiğinde doğru
> dokümantasyondan kullanabilmek.

## Hata 2 --- Her pointer gördüğünde korkmak

Şunu sor:

``` text
Bu pointer neyi gösteriyor?
Sahibi kim?
Ne kadar yaşıyor?
nullptr olabilir mi?
```

## Hata 3 --- Her şeyi `shared_ptr` yapmak

Shared ownership gerekmiyorsa `unique_ptr` veya reference/value daha
uygun olabilir.

## Hata 4 --- `std::move` gördüğünde "nesne taşındı" diye düşünmek

Önce move semantics'i düşün.

## Hata 5 --- C++ koduna C kodu gibi yaklaşmak

Modern C++'ın asıl gücü:

``` text
RAII
STL
type safety
ownership
abstraction
generic programming
```

tarafındadır.

------------------------------------------------------------------------

# 102. Kod Okuma Stratejisi

İlk kez büyük bir C++ dosyası gördüğünde yukarıdan aşağıya her satırı
anlamaya çalışma.

Şu sırayı kullan:

``` text
1. Class adı
2. Public API
3. Private members
4. Constructor
5. Resource ownership
6. Callback / main loop
7. Data flow
8. Threading
9. Error handling
10. Implementation details
```

Robotik projede:

``` text
Sensor → Processing → State → Controller → Actuator
```

akışını bulmaya çalış.

Bu yöntem ROS2 package'lerinde özellikle faydalıdır.

------------------------------------------------------------------------

# 103. Kod Yazarken Kendine Soracağın 10 Soru

1.  Bu nesnenin sahibi kim?
2.  Bu veri kopyalanıyor mu?
3.  `const` olabilir mi?
4.  Reference yeterli mi?
5.  Pointer gerçekten gerekli mi?
6.  Bu kaynak RAII ile yönetilebilir mi?
7.  Bu sınıf gerçekten inheritance gerektiriyor mu?
8.  Bu state bir `enum class` olabilir mi?
9.  Bu container ihtiyacıma uygun mu?
10. Bu kodun birimi ve lifetime'ı açık mı?

Bu sorular zamanla otomatik düşünce haline gelmeli.

------------------------------------------------------------------------

# 104. Son Büyük Zihinsel Harita

C++ robotik öğrenimini şu şekilde gör:

``` text
                         C++
                          │
          ┌───────────────┼────────────────┐
          │               │                │
        DATA           OBJECTS          CONTROL
          │               │                │
      struct          class             if/loop
      vector           ctor              state
      array            dtor              enum
      string           RAII
          │               │
          └───────┬───────┘
                  │
              OWNERSHIP
                  │
       pointer / reference
                  │
       unique_ptr/shared_ptr
                  │
              STL / ALGO
                  │
        ┌─────────┴─────────┐
        │                   │
    concurrency          templates
        │                   │
 thread/mutex             generic
 chrono/atomic            reusable
        │                   │
        └─────────┬─────────┘
                  │
               CMake
                  │
               Debugging
                  │
                Linux
                  │
                ROS2
                  │
             Robotics
```

C++'ı bu bağlantılarla öğrendiğinde, konular birbirinden kopuk syntax
parçaları olmaktan çıkar.

------------------------------------------------------------------------

# 105. ROS2'ye Geçiş Öncesi Son Kontrol

Aşağıdaki kodu kaynak bakmadan kabaca yazabiliyorsan C++ temelinin
oturmaya başladığını düşünebilirsin:

``` cpp
#include <iostream>
#include <memory>
#include <string>
#include <vector>

enum class RobotState
{
    IDLE,
    MOVING,
    ERROR
};

struct SensorData
{
    double distance;
};

class Sensor
{
public:
    explicit Sensor(std::string name)
        : name_(std::move(name))
    {
    }

    SensorData read() const
    {
        return SensorData{10.0};
    }

private:
    std::string name_;
};

class Robot
{
public:
    Robot()
        : sensor_(std::make_unique<Sensor>("front_sensor")),
          state_(RobotState::IDLE)
    {
    }

    void update()
    {
        const SensorData data = sensor_->read();

        if (data.distance < 1.0)
        {
            state_ = RobotState::ERROR;
        }
        else
        {
            state_ = RobotState::MOVING;
        }
    }

    RobotState state() const
    {
        return state_;
    }

private:
    std::unique_ptr<Sensor> sensor_;
    RobotState state_;
};

int main()
{
    Robot robot;

    robot.update();

    std::cout << "Robot updated.\n";
}
```

Bu küçük kodun içinde bile:

``` text
include
namespace
class
struct
enum class
constructor
initializer list
explicit
string
move
unique_ptr
make_unique
const
reference/value semantics
private
public
method
state machine
```

vardır.

Bunu anlayabiliyorsan ROS2'ye geçerken karşılaşacağın C++ syntax'ının
büyük kısmı artık tamamen yabancı görünmeyecektir.

------------------------------------------------------------------------

# 106. Final: Bu Kitabın Amacı

Bu kitabın sonunda hedef:

> "C++ syntax'ının tamamını biliyorum."

değil.

Asıl hedef:

> **"Bir robotik C++ kod tabanını açtığımda ownership'i, class yapısını,
> veri akışını, STL kullanımını, callback'leri, thread'leri ve CMake
> bağlantılarını anlayabiliyorum; küçük bir component'i kendim yazıp
> debug edebiliyorum."**

Bundan sonraki öğrenme zinciri:

``` text
C
 ↓
Modern C++
 ↓
CMake
 ↓
Linux
 ↓
ROS2
 ↓
ROS2 + C++
 ↓
TF2 / URDF
 ↓
Sensors / Odometry
 ↓
EKF
 ↓
SLAM
 ↓
Nav2
 ↓
Autonomous Robot
```

C++ burada amaç değil.

**Robotik yazılım geliştirmek için kullandığın temel araçtır.**

------------------------------------------------------------------------

# 107. Çalışma Protokolü

Her yeni C++ konusu için:

``` text
1. Konuyu oku
       ↓
2. Örneği çalıştır
       ↓
3. Kaynağı kapat
       ↓
4. Aynısını kendin yaz
       ↓
5. Bilerek bir hata yap
       ↓
6. Compiler/GDB ile bul
       ↓
7. Robotik örneğe uyarla
       ↓
8. README'ye kısa not ekle
       ↓
9. Git commit
       ↓
10. Sonraki konu
```

Bu döngüyü koru.

**Bir konu = bir ana kaynak.**

Yeni bir kaynak ancak mevcut yol haritanda gerçek bir boşluğu
kapatıyorsa eklenmeli.

------------------------------------------------------------------------

## Kapanış Notu

Mevcut kurs örneklerini sadece "video 1, video 2..." şeklinde tüketmek
yerine, her örneği bu kitabın ilgili kavramına bağla.

Örneğin:

``` text
vector örneği
    ↓
STL container
    ↓
sensor buffer
    ↓
robotic application

pointer örneği
    ↓
ownership
    ↓
smart pointer
    ↓
ROS2 SharedPtr

class örneği
    ↓
encapsulation
    ↓
composition
    ↓
ROS2 Node

thread örneği
    ↓
mutex
    ↓
executor/callback mantığı
    ↓
robotic concurrency
```

Bu bağlantıları kurduğun noktada **C++ öğrenmekten robotik C++
düşünmeye** geçmiş olursun.
