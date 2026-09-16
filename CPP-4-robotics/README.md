# C++ Fundamentals for Robotics — Ders Notları

> **Kaynak:** Automatic Addison — C++ Fundamentals for Robotics  
> **Amaç:** C bilen birinin C++'ı robotics / embedded / ROS2 geliştirmelerinde kullanabilecek şekilde anlaması.
>
> Bu README, gönderdiğim örnek kodların tamamı dikkate alınarak hazırlanmıştır. C++ syntax'ını sıfırdan öğretmek yerine, **C'den C++'a geçerken ortaya çıkan yeni kavramlara, nedenlerine ve gerçek projelerde nasıl düşünülmesi gerektiğine** odaklanır.

---

# 1. C++'ı Nasıl Düşünmeliyim?

C biliyorsan C++ öğrenirken en büyük hata şudur:

> "C'nin biraz daha gelişmiş hali."

C++ C'nin birçok özelliğini içerir ama modern C++ ile program tasarlama şekli ciddi biçimde farklılaşır.

C'de sık gördüğümüz düşünce:

```text
veri
+
fonksiyon
+
pointer
+
manuel resource yönetimi
```

C++'ta buna şunlar eklenir:

```text
type
class/object
constructor/destructor
ownership
RAII
reference
STL
templates
smart pointer
exception
namespace
abstraction
```

Özellikle robotics/ROS2 tarafında C++ kodu gördüğünde şu soruları sormaya alış:

1. Bu nesnenin tipi ne?
2. Bu nesnenin sahibi kim?
3. Ne kadar yaşayacak?
4. Kopyalanıyor mu, reference mı veriliyor?
5. Resource varsa kim temizliyor?
6. Bu sınıf hangi davranışları kendi içinde topluyor?
7. Buradaki `auto`, `&`, `*`, `const`, `::`, `<T>` ne anlatıyor?

---

# 2. `#include` ve Header Mantığı

Örneğin:

```cpp
#include <iostream>
```

C++ standard library'deki input/output araçlarını kullanabilmemizi sağlar.

Benzer şekilde:

```cpp
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <stdexcept>
```

ilgili özellikleri sağlar.

Örnek:

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, Automatic Addison!" << std::endl;
    return 0;
}
```

Burada `iostream`, `std::cout` ve `std::endl` gibi araçların declaration'larını sağlar.

## C ile karşılaştırma

C'de:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

görürüz.

C++'ta:

```cpp
#include <iostream>
#include <vector>
#include <string>
```

gibi daha yüksek seviyeli abstraction'lar da standard library'nin parçasıdır.

---

# 3. Namespace ve `std::`

C++ kodlarında sürekli:

```cpp
std::cout
std::string
std::vector
std::endl
```

görürüz.

Buradaki `std`, standard library'nin namespace'idir.

Örneğin:

```cpp
std::string robot_name = "Robot";
```

şu anlama gelir:

> `string` isimli şeyi `std` namespace'inden kullan.

## Neden namespace var?

Büyük projelerde farklı kütüphaneler aynı isimleri kullanabilir.

Örneğin:

```cpp
std::vector
Eigen::Vector3d
rclcpp::Node
```

tamamen farklı namespace'lerdir.

`::` operatörü namespace veya class içerisindeki bir üyeye erişmek için kullanılır.

---

## `using namespace std`

Şunu yazarsan:

```cpp
using namespace std;

string name;
cout << name;
```

`std::` yazmak zorunda kalmazsın.

Küçük örneklerde sorun yaratmaz.

Ancak büyük projelerde özellikle header dosyalarında:

```cpp
using namespace std;
```

kullanmak genellikle kaçınılması gereken bir alışkanlıktır.

Çünkü namespace'in içindeki isimleri global scope'a taşımış gibi olursun ve isim çakışmalarını artırabilirsin.

Bu nedenle robotics projelerinde:

```cpp
std::vector
std::string
std::cout
```

şeklini görmek normaldir.

---

# 4. `std::cout`, `std::cin`, `std::cerr`

C'deki:

```c
printf("Battery: %d\n", battery);
```

yerine C++:

```cpp
std::cout << "Battery: " << battery << std::endl;
```

kullanabilir.

`<<` burada stream'e veri gönderir.

Birden fazla parçayı zincirleyebilirsin:

```cpp
std::cout
    << "Robot: "
    << robot_name
    << " Battery: "
    << battery
    << std::endl;
```

## C karşılaştırması

### C

```c
printf("Robot: %s Battery: %d\n", name, battery);
```

### C++

```cpp
std::cout << "Robot: "
          << name
          << " Battery: "
          << battery
          << '\n';
```

C++ yaklaşımı type-safe bir stream abstraction sağlar ve C-style format string'e olan ihtiyacı azaltır.

---

# 5. `std::endl` ve `\n`

```cpp
std::cout << "Hello" << std::endl;
```

iki şey yapar:

1. newline ekler
2. stream'i flush eder

Çoğu durumda sadece:

```cpp
std::cout << "Hello\n";
```

yeterlidir.

`std::endl` yanlış değildir; sadece her newline'da flush gerektiğinde daha anlamlıdır.

---

# 6. `std::string`

C'de string aslında karakter dizisidir:

```c
char name[] = "Robot";
```

veya:

```c
const char* name = "Robot";
```

C++'ta:

```cpp
std::string name = "Robot";
```

kullanabiliriz.

Bu çok önemli bir abstraction'dır.

```cpp
std::string robot_name = "AutomaticAddisonBot";
```

Karaktere:

```cpp
robot_name[0]
```

ile erişilebilir.

Değiştirilebilir:

```cpp
robot_name[8] = '-';
```

String'ler birleştirilebilir:

```cpp
std::string model = "X100";

std::string full_name =
    robot_name + " " + model;
```

## C'den farkı

C'de string yönetiminde:

- buffer boyutu
- null terminator
- `strcpy`
- `strcat`
- `strlen`
- buffer overflow

gibi konularla manuel olarak uğraşmak gerekir.

C++:

```cpp
std::string
```

ile bu işlerin önemli kısmını object'in içine alır.

Bu:

```text
C:
char buffer[100];
manuel yönetim

C++:
std::string
object kendi state'ini yönetiyor
```

şeklinde düşünülebilir.

---

# 7. `std::vector`

C'deki klasik array:

```cpp
int numbers[5];
```

sabit boyutludur.

C++:

```cpp
std::vector<int> numbers;
```

dinamik boyutlu bir container'dır.

Eleman:

```cpp
numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
```

ile eklenebilir.

Erişim:

```cpp
numbers[0]
```

Boyut:

```cpp
numbers.size()
```

## Neden vector?

C'de:

```c
int* numbers = malloc(...);
```

yapıp kapasiteyi, belleği, büyütmeyi ve `free()` işlemini kendin yönetebilirsin.

C++:

```cpp
std::vector<int>
```

bu resource yönetiminin büyük kısmını object'in içine koyar.

Bu C++'ın genel felsefesinin önemli bir örneğidir:

> Manuel resource yönetimi yerine resource'u yöneten type kullan.

---

# 8. Array ve Vector Arasındaki Fark

```cpp
int data[5];
```

ile:

```cpp
std::vector<int> data;
```

aynı şey değildir.

Array:

- boyutu sabittir
- basit
- düşük seviyelidir
- stack üzerinde oluşturulabilir

Vector:

- dinamik boyutludur
- heap kullanabilir
- büyüyebilir
- kendi memory yönetimini yapar
- STL ile uyumludur

Robotics'te ikisi de kullanılabilir.

Örneğin sensör sayısı compile-time sabitse:

```cpp
double sensors[8];
```

mantıklı olabilir.

Sensör sayısı dinamikse:

```cpp
std::vector<double> sensors;
```

daha uygundur.

---

# 9. Iterator

Kodunda:

```cpp
for (
    std::vector<int>::iterator it = numbers.begin();
    it != numbers.end();
    ++it
)
{
    std::cout << *it << std::endl;
}
```

gördün.

Iterator'ı ilk etapta:

> Bir container içerisinde dolaşan pointer-benzeri nesne.

olarak düşünebilirsin.

```cpp
numbers.begin()
```

ilk elemana iterator verir.

```cpp
numbers.end()
```

son elemanın kendisi değildir.

Son elemandan **bir sonraki pozisyonu** gösterir.

Bu yüzden:

```cpp
it != numbers.end()
```

kullanılır.

Elemanın kendisine:

```cpp
*it
```

ile erişilir.

---

# 10. `auto`

Şu:

```cpp
std::vector<int>::iterator it = numbers.begin();
```

yerine:

```cpp
auto it = numbers.begin();
```

yazılabilir.

Compiler sağ taraftan tipi çıkarır.

```cpp
auto x = 10;
```

→ `int`

```cpp
auto speed = 3.5;
```

→ `double`

```cpp
auto it = numbers.begin();
```

→ iterator'ın gerçek tipi.

`auto` dynamic typing değildir.

Tip hâlâ compile-time'da bellidir.

## Neden kullanılır?

Özellikle uzun ve karmaşık tiplerde kodu okunabilir tutar:

```cpp
auto it = numbers.begin();
```

şu ifadeden daha okunabilirdir:

```cpp
std::vector<int>::iterator it = numbers.begin();
```

Modern C++ kodunda `auto` çok sık karşına çıkar.

---

# 11. `std::cin` ve Input Validation

Kod:

```cpp
double speed;

std::cin >> speed;

if (!std::cin) {
    std::cerr << "Invalid number";
    return 1;
}
```

Burada kullanıcıdan `double` alınmaya çalışılıyor.

Eğer kullanıcı:

```text
5.5
```

girerse başarılıdır.

Ama:

```text
hello
```

girerse stream fail state'e geçebilir.

Bu yüzden:

```cpp
if (!std::cin)
```

kontrolü yapılabilir.

Robotics açısından bu mantık daha sonra:

```text
sensor data
configuration
command
network input
```

gibi dışarıdan gelen verilerin doğrulanması fikrine bağlanır.

---

# 12. `std::getline`

```cpp
std::string command;

std::getline(std::cin, command);
```

bir satırın tamamını okur.

Şu:

```cpp
std::cin >> command;
```

boşlukta durur.

Örneğin:

```text
move forward
```

girildiğinde `cin >> command` sadece:

```text
move
```

alabilir.

`getline` ise:

```text
move forward
```

alır.

---

# 13. Type Casting

Kodunda üç yaklaşım gördün:

```cpp
voltage = sensor_value * 5.0 / 1023;
```

```cpp
voltage = (double)sensor_value * 5.0 / 1023;
```

```cpp
voltage =
    static_cast<double>(sensor_value) * 5.0 / 1023;
```

C++'ta üçüncüsü tercih edilir.

```cpp
static_cast<double>(sensor_value)
```

açıkça:

> Bu değeri `double` olarak değerlendir.

demektir.

## C

```c
(double)x
```

## C++

```cpp
static_cast<double>(x)
```

C-style cast daha genel ve daha az kontrollüdür.

C++ cast'leri dönüşümün niyetini açıklar.

Şimdilik en önemli cast:

```cpp
static_cast<T>(value)
```

---

# 14. `stringstream`

```cpp
std::stringstream ss;

ss << "Motor Speed: "
   << motor_speed
   << " RPM";
```

Burada `cout` yerine stream'i memory içerisindeki string'e yönlendirmiş olduk.

Sonra:

```cpp
std::string result = ss.str();
```

ile string elde edilir.

Bunu:

```text
mesaj oluşturma
log oluşturma
string formatlama
```

gibi işlemlerde düşünebilirsin.

---

# 15. Matematik ve `<cmath>`

Kodunda:

```cpp
#include <cmath>

double radians = angle * M_PI / 180.0;

double sine = sin(radians);
double cosine = cos(radians);
```

kullanıldı.

Buradaki:

```cpp
sin()
cos()
sqrt()
```

matematik fonksiyonlarıdır.

Robotics'te bunlar çok önemlidir:

```text
position
orientation
rotation
trajectory
distance
kinematics
```

gibi alanlarda sürekli karşına çıkar.

Örneğin:

```cpp
double distance =
    sqrt(dx * dx + dy * dy);
```

Öklid mesafesidir.

---

# 16. Eigen Örneği

Kod:

```cpp
#include <eigen3/Eigen/Dense>

int main()
{
    Eigen::Vector3d v(1, 2, 3);

    std::cout << v.transpose() << std::endl;
}
```

Burada C++ standard library değil, **Eigen** isimli harici bir kütüphane kullanılıyor.

```cpp
Eigen::Vector3d
```

3 elemanlı `double` vektördür.

Matematiksel olarak:

```text
v =
[1]
[2]
[3]
```

şeklinde düşünülebilir.

```cpp
v.transpose()
```

ise satır biçiminde gösterilmesini sağlar:

```text
1 2 3
```

## Robotics açısından neden önemli?

Robotics'te:

```text
vector
matrix
rotation
transformation
coordinate frame
```

çok temel kavramlardır.

ROS2 projelerinde Eigen gibi matematik kütüphanelerine rastlaman normaldir.

Buradaki önemli fikir:

> C++ sadece dil değil; güçlü kütüphanelerle birlikte kullanılan bir ecosystem'dir.

---

# 17. Command Line Arguments

Kod:

```cpp
int main(int argc, char* argv[])
```

C'den de tanıdık olabilir.

```text
argc
```

kaç argument olduğunu belirtir.

```text
argv
```

argument string'lerini taşır.

Örneğin:

```bash
./main_example arg1 "argument2" test123
```

şeklinde çalıştırırsan:

```text
argv[0] = "./main_example"
argv[1] = "arg1"
argv[2] = "argument2"
argv[3] = "test123"
```

olur.

`argc`:

```text
4
```

olur.

Burada `argv[0]` genellikle programın adıdır.

Robotics'te command-line arguments:

```text
configuration
file path
mode
debug option
parameter
```

gibi bilgiler için kullanılabilir.

---

# 18. C++ OOP'ye Geçiş

Buradan itibaren C++'ın C'den en önemli farklarından birine geliyoruz:

# Class ve Object

Kod:

```cpp
class DistanceSensor
{
private:
    double range;

public:
    DistanceSensor(double max_range)
        : range(max_range)
    {
    }

    void displayRange()
    {
        std::cout
            << "Sensor maximum range: "
            << range
            << " meters"
            << std::endl;
    }
};
```

Burada bir **class** tanımlıyoruz.

Class'ı:

> Kendi verisini ve o veri üzerinde çalışan davranışları bir arada tutan bir type.

olarak düşün.

---

# 19. Class ve Object Farkı

Class:

```cpp
class DistanceSensor
{
    ...
};
```

bir blueprint/type'tır.

Object:

```cpp
DistanceSensor frontSensor(10.0);
```

o type'ın gerçek instance'ıdır.

Başka bir object:

```cpp
DistanceSensor rearSensor(5.5);
```

oluşturabiliriz.

Dolayısıyla:

```text
DistanceSensor
      │
      ├── frontSensor
      │       range = 10.0
      │
      └── rearSensor
              range = 5.5
```

Aynı class'tan iki farklı object vardır.

---

# 20. `private`, `protected`, `public`

C'deki `struct` genellikle verileri doğrudan erişilebilir tutabilir:

```c
struct Robot {
    int battery;
};
```

C++ class'larında erişim kontrolü vardır.

```cpp
class Robot
{
private:
    int battery_level_;

protected:
    int max_speed_;

public:
    void print_status();
};
```

### `private`

Sadece class'ın kendi üyeleri erişebilir.

Dışarıdan:

```cpp
robot.battery_level_
```

yapamazsın.

### `protected`

Class'ın kendisi ve derived class'lar erişebilir.

### `public`

Dışarıdan erişilebilir.

---

# 21. Encapsulation

Bu erişim kontrolünün temel amacı:

> Object'in iç state'ini kontrolsüz şekilde dışarıya açmamak.

Örneğin:

```cpp
class Robot
{
private:
    int battery_level_;
};
```

diyerek dışarıdan:

```cpp
robot.battery_level_ = -500;
```

gibi bir şey yapılmasını engelleyebilirsin.

Bunun yerine:

```cpp
robot.setBatteryLevel(50);
```

gibi kontrollü bir interface tasarlanabilir.

Bu fikir **encapsulation** olarak adlandırılır.

---

# 22. Constructor

Şu:

```cpp
DistanceSensor(double max_range)
    : range(max_range)
{
}
```

constructor'dır.

Object oluşturulduğunda otomatik olarak çalışır.

```cpp
DistanceSensor sensor(10.0);
```

yaptığında:

```text
object oluştur
    ↓
constructor çalışır
    ↓
range initialize edilir
```

---

# 23. Constructor Initializer List

Şu:

```cpp
DistanceSensor(double max_range)
    : range(max_range)
{
}
```

özellikle önemlidir.

Bu:

```cpp
range = max_range;
```

ile tamamen aynı fikir değildir.

Initializer list, member'ın constructor çalışmadan önce initialize edilmesini sağlar.

Özellikle:

```cpp
const member
reference member
class member
```

gibi bazı üyelerde initializer list zorunlu olabilir.

Modern C++'ta:

```cpp
Robot(int battery, int speed)
    : battery_level_(battery),
      max_speed_(speed)
{
}
```

şeklini tercih etmek iyi bir alışkanlıktır.

---

# 24. Member Naming

Kodunda:

```cpp
battery_level_;
max_speed_;
name_;
x_;
y_;
```

gibi isimler gördün.

Sondaki `_`, bunların class member olduğunu belirtmek için kullanılan yaygın bir naming convention'dır.

Örneğin:

```cpp
class Robot
{
private:
    int battery_level_;

public:
    void setBatteryLevel(int battery)
    {
        battery_level_ = battery;
    }
};
```

Burada:

```text
battery
```

parametre,

```text
battery_level_
```

member variable'dır.

Bu zorunlu syntax değildir; bir naming convention'dır.

---

# 25. Constructor ile Object State

Kod:

```cpp
class Robot
{
public:
    Robot(std::string name, int x, int y)
    {
        name_ = name;
        x_ = x;
        y_ = y;
    }

private:
    std::string name_;
    int x_;
    int y_;
};
```

Sonra:

```cpp
Robot robot1("Robot1", 0, 0);
Robot robot2("Robot2", 10, 20);
```

Object'lerin başlangıç state'i constructor tarafından oluşturulur.

Bu robotics'te çok doğal bir tasarımdır:

```text
Robot
 ├── name
 ├── position
 ├── state
 ├── sensors
 └── methods
```

---

# 26. Destructor

Kod:

```cpp
class RobotController
{
public:
    RobotController()
    {
    }

    ~RobotController()
    {
        std::cout
            << "Robot controller shutting down"
            << std::endl;
    }
};
```

`~RobotController()` destructor'dır.

Object'in lifetime'ı bittiğinde otomatik çalışır.

Örneğin:

```cpp
int main()
{
    RobotController controller;

    controller.control_robot();

    return 0;
}
```

`controller` scope dışına çıkarken destructor çalışır.

---

# 27. Constructor + Destructor: Lifetime

C++'ın çok önemli fikirlerinden biri:

```text
object oluşturuldu
       ↓
constructor
       ↓
object kullanılıyor
       ↓
scope bitti
       ↓
destructor
```

Bu lifecycle ileride **RAII** kavramının temelini oluşturur.

C'de çoğu zaman:

```c
resource = acquire();
...
release(resource);
```

işini manuel yapmak gerekir.

C++'ta:

```cpp
Resource resource;
```

gibi bir object resource'un sahibi olabilir.

Object yok olduğunda cleanup otomatik yapılabilir.

---

# 28. `static` Local Variable

Kod:

```cpp
void increment_counter()
{
    static int count = 0;

    count++;

    std::cout
        << "Counter: "
        << count
        << std::endl;
}
```

Fonksiyon 5 kez çağrılıyor:

```cpp
for (int i = 0; i < 5; i++)
{
    increment_counter();
}
```

çıktı:

```text
Counter: 1
Counter: 2
Counter: 3
Counter: 4
Counter: 5
```

## Neden?

Normal local:

```cpp
int count = 0;
```

olsaydı her function call'da yeniden initialize edilirdi.

`static local` ise program boyunca aynı storage'ı kullanır.

Kabaca:

```text
function call #1
count = 0 → 1

function call #2
count = 1 → 2

function call #3
count = 2 → 3
```

şeklinde state korunur.

## Önemli

`static` burada:

> "Değişkenin değeri function call'lar arasında yaşasın."

anlamındadır.

Bu, class member'daki `static` ile aynı konu değildir; C++'ta `static` farklı bağlamlarda farklı özellikler ifade edebilir.

---

# 29. Function Overloading

Kod:

```cpp
void move_robot(int distance);
void move_robot(int x, int y);
```

ve:

```cpp
move_robot(10);
move_robot(5, 7);
```

C++ burada aynı isimli fakat farklı parameter listesine sahip fonksiyonlara izin verir.

Bu:

# Function Overloading

olarak adlandırılır.

Compiler argument'lara bakarak hangi fonksiyonun çağrılacağını seçer.

```cpp
move_robot(10);
```

→

```cpp
void move_robot(int distance);
```

```cpp
move_robot(5, 7);
```

→

```cpp
void move_robot(int x, int y);
```

C'de aynı isimli iki fonksiyon tanımlayamazsın.

C++'ta function overloading vardır.

---

# 30. Pointer ve Reference

Pointer:

```cpp
int robot_id = 42;

int* ptr = &robot_id;
```

C'den bildiğin gibi:

```cpp
ptr
```

adres,

```cpp
*ptr
```

adresteki değerdir.

```cpp
*ptr = 99;
```

yapınca:

```cpp
robot_id == 99
```

olur.

---

# 31. Reference

C++'ta:

```cpp
int x = 10;

int& ref = x;
```

`ref`, `x` için reference'tır.

```cpp
ref = 20;
```

yaparsan:

```cpp
x == 20
```

olur.

Reference'ı ilk etapta:

> Aynı object'e verilen ikinci isim.

gibi düşünebilirsin.

---

# 32. Pointer vs Reference

## Pointer

```cpp
int* ptr = &x;
```

Pointer:

- adres tutar
- null olabilir
- başka bir adrese yönlendirilebilir
- `*` ile dereference edilir
- pointer arithmetic yapılabilir

## Reference

```cpp
int& ref = x;
```

Reference:

- başka bir object'e bağlanır
- normal kullanımda null değildir
- kullanım syntax'ı daha sade
- `*` ile dereference edilmez

---

# 33. Neden Reference Var?

C'de büyük bir object'i kopyalamadan fonksiyona vermek için pointer sık kullanılır:

```c
void process_robot(struct Robot* robot);
```

C++:

```cpp
void process_robot(Robot& robot);
```

yazabilir.

Bu durumda:

```cpp
robot.battery
```

gibi doğal bir syntax elde edilir.

Pointer'da:

```cpp
robot->battery
```

kullanılır.

---

# 34. `const` Reference

Modern C++'ta çok önemli pattern:

```cpp
void print_robot(const Robot& robot)
{
    ...
}
```

Burada iki şey aynı anda söyleniyor:

1. Object'i kopyalama.
2. Fonksiyon object'i değiştirmesin.

Bu nedenle:

```cpp
const T&
```

çok sık görülür.

Özellikle büyük object'lerde:

```cpp
const std::string&
const std::vector<T>&
const Eigen::MatrixXd&
```

gibi kullanımlar görebilirsin.

---

# 35. Exception Handling

Kod:

```cpp
double divide(double a, double b)
{
    if (b == 0)
    {
        throw std::runtime_error("Division by zero");
    }

    return a / b;
}
```

çağıran taraf:

```cpp
try
{
    double result = divide(10, 0);
}
catch (const std::exception& e)
{
    std::cerr << e.what();
}
```

şeklinde.

## Mantık

Normal akış:

```text
function
  ↓
return
```

exception:

```text
function
  ↓
throw
  ↓
uygun catch aranır
  ↓
catch
```

---

# 36. `std::exception` ve `const std::exception&`

Şu:

```cpp
catch (const std::exception& e)
```

çok önemli bir C++ pattern'idir.

`e` exception object'ine reference'tır.

`const` olduğu için değiştiremezsin.

Reference kullanıldığı için exception object'ini gereksiz yere kopyalamazsın.

`e.what()` hata mesajını verir.

---

# 37. Exception vs Return Code

C'de sık gördüğümüz:

```c
int result = function();

if (result != 0) {
    // error
}
```

yaklaşımında hata return value ile taşınır.

C++ exception yaklaşımında:

```cpp
throw ...
```

ile normal return akışından ayrılabilirsin.

Her robotics kodunda her hata için exception kullanmak zorunda değilsin.

Özellikle gerçek-time / embedded sistemlerde hata yönetimi tasarım kararıdır.

Önemli olan:

> Exception'ın ne olduğunu ve gördüğünde nasıl okuyacağını bilmek.

---

# 38. Class Interface ve Implementation Ayrımı

Kodunda:

```cpp
#include "33-robot.hpp"
#include <iostream>

void Robot::greet()
{
    std::cout << "Hello, I am a robot." << std::endl;
}

int main()
{
    Robot my_robot;
    my_robot.greet();
}
```

ve ayrı dosyada:

```cpp
#ifndef ROBOT_HPP
#define ROBOT_HPP

class Robot
{
public:
    void greet();
};

#endif
```

var.

Burada C++ projelerinin gerçek dünyadaki önemli yapısına geldik.

---

# 39. `.hpp` Nedir?

`.hpp` genellikle C++ header dosyası için kullanılan uzantıdır.

Header'da class'ın **interface/declaration** kısmını tutabiliriz:

```cpp
class Robot
{
public:
    void greet();
};
```

Source `.cpp` dosyasında implementation:

```cpp
void Robot::greet()
{
    std::cout << "Hello";
}
```

bulunabilir.

Yani:

```text
robot.hpp
    ↓
Robot class ne sunuyor?

robot.cpp
    ↓
Robot bunu nasıl yapıyor?
```

---

# 40. Neden Ayırıyoruz?

Küçük programda her şeyi:

```cpp
main.cpp
```

içinde yazabilirsin.

Ama gerçek projede:

```text
Robot
Sensor
Motor
Controller
Planner
Node
...
```

gibi birçok class olacaktır.

Bunların hepsini tek dosyaya koymak yönetilemez hale gelir.

Bu yüzden:

```text
include/
    robot.hpp

src/
    robot.cpp
    main.cpp
```

gibi yapı kullanılır.

---

# 41. Include Guard

Header'da:

```cpp
#ifndef ROBOT_HPP
#define ROBOT_HPP

class Robot
{
public:
    void greet();
};

#endif
```

var.

Buna **include guard** denir.

Amaç header'ın aynı translation unit içerisinde birden fazla kez include edilmesinden doğabilecek problemlerin önüne geçmektir.

Mantık:

```text
ROBOT_HPP tanımlı mı?
        │
      hayır
        ↓
class'ı ekle
        ↓
ROBOT_HPP tanımla

Tekrar include?
        ↓
ROBOT_HPP zaten tanımlı
        ↓
class tekrar eklenmez
```

Modern C++'ta bunun yerine:

```cpp
#pragma once
```

da çok yaygındır.

---

# 42. `Robot::greet()`

Şu:

```cpp
void Robot::greet()
```

şunu anlatır:

> `Robot` class'ının `greet` member function'ını tanımlıyorum.

Buradaki:

```cpp
::
```

scope resolution operator'dır.

Benzer syntax:

```cpp
std::cout
```

→ `cout`, `std` namespace'inde.

```cpp
Robot::greet
```

→ `greet`, `Robot` class'ında.

---

# 43. Class İçinde Function Tanımlamak

Şunu da yapabilirdin:

```cpp
class Robot
{
public:
    void greet()
    {
        std::cout << "Hello";
    }
};
```

Böylece implementation class'ın içinde olur.

Küçük class'larda normaldir.

Büyük projelerde declaration'ı `.hpp`, implementation'ı `.cpp` dosyasına ayırmak daha düzenli olabilir.

---

# 44. `main()` ve Program Lifetime

Tipik:

```cpp
int main()
{
    Robot robot;

    return 0;
}
```

akış:

```text
program başlar
    ↓
main()
    ↓
robot oluşturulur
    ↓
robot kullanılır
    ↓
main scope'u biter
    ↓
robot destructor
    ↓
return
```

Bu lifetime mantığını çok iyi oturt.

Çünkü modern C++'ın büyük kısmı bunun üzerine kuruludur.

---

# 45. RAII — C++'ın En Önemli Fikirlerinden Biri

RAII:

> Resource Acquisition Is Initialization

olarak açılır.

İsim biraz garip ama fikir basittir:

> Resource'un lifetime'ını bir object'in lifetime'ına bağla.

Örneğin C'de:

```c
FILE* file = fopen(...);

if (file == NULL) {
    ...
}

/* kullan */

fclose(file);
```

`fclose` çağrısını unutursan resource leak olabilir.

C++'ta bir wrapper object:

```cpp
File file(...);
```

resource'u sahiplenebilir.

Object scope'tan çıkınca destructor cleanup yapar.

Bu:

```text
constructor → resource acquire
destructor  → resource release
```

modelidir.

`std::vector`, `std::string`, `std::unique_ptr` gibi birçok modern C++ abstraction'ının arkasındaki önemli düşünce budur.

---

# 46. C++ Memory Management'a Giriş

C'de:

```c
int* p = malloc(sizeof(int));
...
free(p);
```

gibi manuel memory management yapabilirsin.

C++'ta:

```cpp
new
delete
```

vardır ama modern C++'ta mümkün olduğunca raw `new/delete` yerine ownership'i yöneten abstraction'lar tercih edilir.

Örneğin:

```cpp
std::unique_ptr<T>
```

Bu konu ilerleyen videolarda daha önemli hale gelecek.

Ana soru:

> "Bu pointer hangi adrese gidiyor?"

kadar:

> **"Bu object'in sahibi kim ve ne zaman yok olacak?"**

olmalıdır.

---

# 47. C'den C++'a Büyük Geçiş: Ownership

C'de:

```c
Robot* robot = malloc(sizeof(Robot));
```

yaptığında belleğin sahibi olursun.

Senin görevin:

```c
free(robot);
```

çağırmaktır.

C++'ta mümkün olduğunca:

```text
resource
   ↓
owner object
   ↓
destructor
   ↓
automatic cleanup
```

modeline geçilir.

Bu, C++ öğrenirken ezberlenmesi gereken en önemli mental modellerden biridir.

---

# 48. `struct` ve `class`

C:

```c
struct Robot
{
    int battery;
};
```

C++:

```cpp
struct Robot
{
    int battery;
};
```

C++'ta `struct` hâlâ vardır.

Ancak:

```cpp
class Robot
{
    int battery;
};
```

ile:

```cpp
struct Robot
{
    int battery;
};
```

arasındaki önemli varsayılan fark:

### `struct`

Üyeler varsayılan olarak:

```cpp
public
```

### `class`

Üyeler varsayılan olarak:

```cpp
private
```

Bu nedenle C++'ta:

```cpp
class Robot
{
private:
    int battery_;
};
```

çok normaldir.

---

# 49. Encapsulation Neden Robotics'te Faydalı?

Diyelim:

```cpp
class Motor
{
private:
    double speed_;

public:
    void setSpeed(double speed);
};
```

Dışarıdan:

```cpp
motor.speed_ = -99999;
```

yapılamaz.

Bunun yerine:

```cpp
motor.setSpeed(100);
```

kullanılır.

`setSpeed` içinde:

```cpp
if (speed < 0)
{
    ...
}
```

gibi kurallar uygulanabilir.

Bu:

```text
raw data access
```

yerine:

```text
controlled interface
```

sağlar.

---

# 50. `static` ile `const` Farkı

Kodlarında:

```cpp
const float MAX_SPEED = 5.0;
```

gördün.

`const`:

> Bu object/değer üzerinden değişiklik yapılmasını engelle.

demektir.

```cpp
const float MAX_SPEED = 5.0;
```

sonrasında:

```cpp
MAX_SPEED = 10.0;
```

yapamazsın.

`static` ise başka bir kavramdır.

Örneğin:

```cpp
static int count = 0;
```

local variable'ın lifetime'ını function call'ların ötesine taşır.

Bu ikisini karıştırma:

```text
const  → değiştirilemezlik
static → storage/lifetime/linkage bağlamı
```

---

# 51. `const` ve Robotics

Robot parametreleri için:

```cpp
const double MAX_SPEED = 5.0;
```

gibi kullanımlar anlamlıdır.

Bir fonksiyona:

```cpp
void print(const Robot& robot);
```

dediğinde ise:

```text
Robot'u değiştirmeyeceğim
+
kopyalamayacağım
```

anlamına gelir.

Bu yüzden `const` modern C++'ta çok daha büyük bir rol oynar.

---

# 52. C++ Naming Convention

Kodunda:

```cpp
battery_level_;
max_speed_;
name_;
```

gibi member isimleri var.

Buradaki `_` yaygın bir convention'dır.

Örneğin:

```cpp
class Robot
{
private:
    int battery_level_;

public:
    void setBatteryLevel(int battery)
    {
        battery_level_ = battery;
    }
};
```

Burada:

```text
battery          → function parameter
battery_level_   → class member
```

olduğu hemen anlaşılır.

Bu zorunlu değildir ama büyük projelerde okunabilirliği artırır.

---

# 53. Constructor Overloading

Bir class'ın birden fazla constructor'ı olabilir:

```cpp
Robot();
Robot(std::string name);
Robot(std::string name, int x, int y);
```

Bunun mantığı function overloading'e benzer.

Object'in nasıl oluşturulacağını farklı şekillerde tanımlayabilirsin.

---

# 54. Destructor Ne Zaman Çalışır?

Stack üzerinde:

```cpp
int main()
{
    Robot robot;
}
```

`robot`, scope'un sonunda yok edilir.

Yaklaşık:

```text
{
    Robot robot;
} ← destructor
```

düşünebilirsin.

Bu yüzden scope C++'ta çok önemlidir.

Scope sadece:

> "Değişken nereden görülebiliyor?"

değil,

aynı zamanda:

> **"Object ne zaman yok olacak?"**

sorusunu da belirler.

---

# 55. Scope

Örneğin:

```cpp
{
    Robot robot;

    // robot burada kullanılabilir
}

// robot artık yok
```

Object'in lifetime'ı scope ile bağlanabilir.

Bu yüzden C++ kodu okurken `{}` bloklarına dikkat et.

---

# 56. Operator Overloading'e Giriş

C++ bir operator'ün class için nasıl davranacağını tanımlamana izin verir.

Örneğin matematiksel bir type:

```cpp
Vector
```

için:

```cpp
v1 + v2
```

anlamlı olabilir.

Operator overloading ile `+` operator'üne class'a özel davranış verilebilir.

Amaç:

```cpp
vector.add(vector2)
```

yerine:

```cpp
v1 + v2
```

gibi doğal bir syntax sağlayabilmektir.

Bunu kötüye kullanmak okunabilirliği azaltabilir; operator yalnızca doğal bir anlam taşıyorsa kullanılmalıdır.

---

# 57. Lambda Expressions

Modern C++'ta function'u isimsiz şekilde tanımlayabilirsin:

```cpp
auto square = [](int x)
{
    return x * x;
};
```

Burada:

```cpp
[]
```

lambda'nın capture kısmıdır.

```cpp
(int x)
```

parametredir.

```cpp
return x * x;
```

body'dir.

Lambda:

> Küçük, lokal bir davranışı bir yerde tanımlamak.

için kullanışlıdır.

Özellikle STL algorithms ile çok önemlidir.

---

# 58. Lambda ve Capture

Örneğin:

```cpp
int threshold = 10;

auto check = [threshold](int value)
{
    return value > threshold;
};
```

`threshold` lambda içine capture edilmiştir.

`[threshold]`:

> `threshold` değerini lambda'nın içine al.

anlamına gelir.

`[&]` gibi capture biçimleri de vardır ve bunlar reference ile capture eder.

Lambda gördüğünde ilk bakman gereken şey:

```cpp
[...]
```

kısmıdır.

---

# 59. File I/O

C++ dosya işlemleri için:

```cpp
#include <fstream>
```

gibi araçlar sunar.

Genel fikir:

```text
file stream
    ↓
read / write
    ↓
close
```

C'de:

```c
FILE*
fopen()
fprintf()
fclose()
```

kullanırken C++'ta stream abstraction'ları kullanabilirsin.

Buradaki asıl önemli fikir yine resource lifetime'dır.

---

# 60. Templates

C++'ın en güçlü özelliklerinden biri:

# Generic Programming

Örneğin:

```cpp
template <typename T>
T add(T a, T b)
{
    return a + b;
}
```

Burada `T` gerçek bir type yerine geçen template parameter'dır.

Sonra:

```cpp
add<int>(1, 2);
```

ve:

```cpp
add<double>(1.5, 2.5);
```

gibi kullanılabilir.

---

# 61. `std::vector<int>` Neden `<int>` Alıyor?

Şu:

```cpp
std::vector<int>
```

aslında template kullanımına örnektir.

`vector` kabaca:

```cpp
template <typename T>
class vector;
```

gibi düşünülebilir.

Dolayısıyla:

```cpp
std::vector<int>
```

→ integer vector

```cpp
std::vector<double>
```

→ double vector

```cpp
std::vector<std::string>
```

→ string vector

olur.

Bu nedenle `<T>` syntax'ı gördüğünde:

> "Bu generic/template type olabilir."

diye düşün.

---

# 62. Macro vs Template

C'de:

```c
#define SQUARE(x) ((x) * (x))
```

gibi macro yazabilirsin.

Macro compiler'ın gerçek type system'inin dışında, preprocessor aşamasında çalışır.

C++'ta birçok durumda template daha güvenli ve type-aware bir abstraction sağlar.

Örneğin:

```cpp
template <typename T>
T square(T x)
{
    return x * x;
}
```

Bu gerçek C++ type system'i içinde çalışır.

Macro tamamen kötü değildir; conditional compilation gibi alanlarda hâlâ kullanılır.

Ama generic code için çoğu zaman template daha uygun bir araçtır.

---

# 63. STL — Standard Template Library

STL, modern C++ öğrenmenin merkezindedir.

Gönderdiğin kodlarda şimdiden:

```cpp
std::vector
std::string
iterator
```

gördün.

STL'nin önemli parçaları:

```text
containers
iterators
algorithms
function objects / lambdas
```

Container örnekleri:

```cpp
std::vector
std::array
std::deque
std::list
std::map
std::unordered_map
std::set
std::unordered_set
```

Bunların hepsini ezberlemek zorunda değilsin.

Ama `vector`, `string`, `array`, `map`, `unordered_map` gibi temel yapıları tanıyabilmelisin.

---

# 64. Container + Iterator + Algorithm

Modern C++'ın önemli mental modeli:

```text
Container
    ↓
Iterator
    ↓
Algorithm
```

Örneğin:

```cpp
std::vector<int> numbers;
```

veriyi tutar.

```cpp
numbers.begin()
```

iterator verir.

STL algorithm'leri bu iterator'larla çalışabilir.

Bu yaklaşım C'deki:

```c
for (int i = 0; i < n; i++)
```

mantığından daha genel bir abstraction sağlar.

---

# 65. `std::vector` ile Loop

Kodunda:

```cpp
for (int i = 0; i < motor_speeds.size(); i++)
{
    std::cout << motor_speeds[i];
}
```

çalışır.

Ama modern C++'ta ileride:

```cpp
for (const auto& speed : motor_speeds)
{
    std::cout << speed;
}
```

gibi range-based for göreceksin.

Bu genellikle daha okunabilirdir.

Burada:

```cpp
const auto&
```

şunu ifade eder:

```text
auto  → gerçek tipi compiler bulsun
&     → kopyalama yapma
const → değiştirme
```

Bu pattern'i öğrenmek çok değerlidir.

---

# 66. C++'ta Memory'yi Anlama

C'den gelen önemli bilgilerin üzerine C++ şunu ekler:

```text
Memory
+
Lifetime
+
Ownership
```

Örneğin:

```cpp
Robot robot;
```

deyince sadece:

> Robot nerede?

sorusu değil:

> Robot ne zaman oluşturuldu?

> Ne zaman yok olacak?

> İçindeki resource'ların sahibi kim?

soruları da önemlidir.

---

# 67. Stack Object

```cpp
Robot robot;
```

gibi local object'ler otomatik lifetime'a sahip olabilir.

Scope:

```cpp
{
    Robot robot;
}
```

bittiğinde destructor çağrılır.

Bu nedenle manuel:

```cpp
delete
```

gerekmeyebilir.

---

# 68. Raw Pointer

```cpp
Robot* robot;
```

sadece pointer'ın var olduğunu söyler.

Bu object'in sahibi olduğu anlamına gelmez.

Bu ayrım çok önemlidir:

```text
pointer
≠
owner
```

Bir raw pointer:

- object'i gözlemliyor olabilir
- başka bir object'in adresini tutuyor olabilir
- ownership taşımıyor olabilir

Bu yüzden modern C++'ta raw pointer gördüğünde otomatik olarak:

> "Bunu delete etmeliyim."

deme.

Önce ownership'i anlamaya çalış.

---

# 69. Smart Pointer

Modern C++ burada:

```cpp
std::unique_ptr
std::shared_ptr
std::weak_ptr
```

gibi smart pointer'lar sunar.

Bunların temel amacı pointer'ın yanında ownership semantics sağlamaktır.

---

# 70. `unique_ptr`

```cpp
std::unique_ptr<Robot> robot;
```

temel olarak:

> Bu resource'un tek sahibi benim.

anlamına gelir.

Object scope'tan çıktığında resource otomatik temizlenir.

Bu:

```cpp
std::unique_ptr<Robot>
```

ile:

```cpp
Robot* robot = new Robot();
```

arasındaki temel farktır.

Raw pointer'da ownership'i kendin takip edersin.

`unique_ptr` ownership'i type'ın içine koyar.

---

# 71. `shared_ptr`

```cpp
std::shared_ptr<Robot>
```

bir resource'un birden fazla owner tarafından paylaşılmasını sağlar.

Reference counting kullanır.

Kabaca:

```text
Robot
 ↑
 │
shared_ptr A
shared_ptr B
shared_ptr C
```

Son owner da yok olduğunda object yok edilir.

Ancak `shared_ptr` her yerde kullanılmamalıdır.

Ownership gerçekten shared ise anlamlıdır.

---

# 72. `weak_ptr`

`weak_ptr`, shared ownership'a katılmadan bir `shared_ptr` tarafından yönetilen object'e erişim sağlar.

Özellikle circular ownership problemlerinde önemlidir.

Örneğin:

```text
A → B
↑   ↓
└───┘
```

iki `shared_ptr` birbirini tutarsa reference count sıfıra düşmeyebilir.

`weak_ptr` bu tür durumlarda kullanılabilir.

---

# 73. `std::move`

Smart pointer'larla birlikte çok önemli bir kavram:

```cpp
std::move
```

Örneğin:

```cpp
std::unique_ptr<Robot> a =
    std::make_unique<Robot>();

std::unique_ptr<Robot> b =
    std::move(a);
```

Burada ownership `a`'dan `b`'ye taşınır.

```text
a
 ↓
Robot

std::move(a)

b
 ↓
Robot
```

`unique_ptr` kopyalanamaz çünkü:

> Tek ownership.

olması gerekir.

---

# 74. Move Semantics

C++'ta bazı object'ler pahalı şekilde kopyalanabilir.

Örneğin büyük bir:

```cpp
std::vector
std::string
```

düşün.

Kopyalamak:

```text
data'nın tamamını tekrar oluştur
```

gerektirebilir.

Move semantics ise resource'un ownership'ini taşıyabilir.

Bu yüzden modern C++:

```text
copy
vs
move
```

ayrımına sahiptir.

Şimdilik temel mental model:

```text
copy → yeni resource/data oluştur
move → mevcut resource'u başka object'e aktar
```

şeklinde olsun.

---

# 75. RAII + Smart Pointer

Bunları birlikte düşün:

```text
RAII
 ↓
object lifetime
 ↓
resource lifetime
```

ve:

```text
unique_ptr
 ↓
ownership
 ↓
destructor
 ↓
automatic cleanup
```

Modern C++ memory management'ın ana fikri budur.

---

# 76. C ile Memory Management Karşılaştırması

## C

```c
Robot* robot = malloc(sizeof(Robot));

if (robot == NULL) {
    ...
}

/* use robot */

free(robot);
```

Programcı:

```text
allocate
+
track ownership
+
free
```

yapar.

## Modern C++

```cpp
auto robot =
    std::make_unique<Robot>();
```

Object scope'tan çıkınca cleanup otomatik gerçekleşebilir.

Bu yüzden:

> Modern C++ mümkün olduğunca ownership'i type system ile ifade etmeye çalışır.

---

# 77. Multithreading

Kodlarında ilerleyen bölümde multithreading görmen önemli.

Robotics'te aynı anda:

```text
sensor reading
motor control
communication
planning
logging
```

gibi farklı işler yürüyebilir.

C++ thread abstraction'ları ile:

```cpp
std::thread
```

gibi yapılar kullanılabilir.

Ancak thread oluşturmak kadar:

```text
shared data
race condition
mutex
lock
deadlock
lifetime
```

gibi kavramları anlamak önemlidir.

---

# 78. `mutex` Mental Modeli

İki thread aynı veriyi değiştiriyorsa:

```text
Thread A ──┐
           ├── shared data
Thread B ──┘
```

aynı anda erişim problem yaratabilir.

Mutex:

```text
Thread A
   ↓
lock
   ↓
shared data
   ↓
unlock
```

gibi erişimi korumaya yardımcı olur.

Robotics'te sensor state veya controller state gibi shared data'larda önemlidir.

---

# 79. Time ve `chrono`

Modern C++ zaman işlemleri için:

```cpp
#include <chrono>
```

kullanır.

Örneğin:

```cpp
std::chrono::milliseconds(100)
```

100 ms'lik süreyi ifade eder.

Robotics'te:

```text
control loop
timer
sensor update
timeout
periodic task
```

gibi kavramlar nedeniyle zaman abstraction'ları çok önemlidir.

ROS2'de de zaman ve timer kavramlarıyla sık karşılaşacaksın.

---

# 80. C++ ve Robotics Arasındaki Bağlantı

Bu kursta öğrendiğin kavramları robotics tarafına bağlarsak:

| C++ | Robotics'te olası kullanım |
|---|---|
| `std::vector` | Sensor data / trajectory |
| `std::string` | Robot name / topic / command |
| `class` | Robot / Sensor / Controller |
| constructor | Object initialization |
| destructor | Resource cleanup |
| reference | Büyük object'i kopyalamadan aktarma |
| `const` | Read-only data |
| `unique_ptr` | Ownership |
| `shared_ptr` | Shared ownership |
| lambda | Callback / algorithm |
| template | Generic robotics utilities |
| STL | Data structures / algorithms |
| Eigen | Matrix / vector / transformations |
| thread | Concurrent tasks |
| mutex | Shared state synchronization |
| chrono | Timers / control periods |
| header/source | Büyük proje organizasyonu |
| namespace | Library/module separation |
| exception | Error handling |

---

# 81. ROS2 İçin Özellikle Bilmen Gereken C++

ROS2 tarafına geçtiğinde C++ kodu gördüğünde özellikle şunları tanıyabilmelisin:

```cpp
class MyNode : public rclcpp::Node
{
    ...
};
```

Burada:

```text
class
inheritance
public
```

vardır.

Şunu:

```cpp
std::shared_ptr<...>
```

gördüğünde:

```text
shared ownership
```

düşünebilmelisin.

Şunu:

```cpp
const std::string&
```

gördüğünde:

```text
kopyalama yok
değiştirme yok
```

diye okuyabilmelisin.

Şunu:

```cpp
auto
```

gördüğünde:

```text
compiler type inference
```

düşünmelisin.

Şunu:

```cpp
[this]()
{
    ...
}
```

gördüğünde:

```text
lambda + capture
```

demelisin.

Şunu:

```cpp
std::vector<T>
```

gördüğünde:

```text
STL dynamic container
```

demelisin.

---

# 82. C vs C++ — Büyük Resim

| Konu | C | C++ |
|---|---|---|
| String | `char[]`, `char*` | `std::string` |
| Dynamic array | `malloc` | `std::vector` |
| OOP | built-in class yok | `class` |
| Encapsulation | manuel tasarım | `private/protected/public` |
| Constructor | yok | var |
| Destructor | yok | var |
| Function overloading | yok | var |
| Reference | yok | var |
| Namespace | yok | var |
| Templates | yok | var |
| STL | yok | var |
| Smart pointer | yok | var |
| RAII | yok | var |
| Exception | yok | var |
| Operator overloading | yok | var |
| Lambda | yok | var |
| `auto` | yok | var |
| Move semantics | yok | var |

---

# 83. C Bilgimi C++'ta Nasıl Kullanmalıyım?

C bilgini çöpe atma.

Tam tersine C bilgisi sana C++'ın alt seviyesini anlamada avantaj sağlar.

Örneğin:

```cpp
std::vector<int>
```

kullanırken arka planda:

```text
memory
pointer
allocation
object lifetime
```

olduğunu bilirsin.

Ama artık her şeyi manuel yapmak zorunda değilsin.

Bu önemli geçiştir:

```text
C:

"Belleği kendim yöneteyim."

        ↓

Modern C++:

"Belleği yöneten doğru abstraction'ı kullanayım."
```

---

# 84. C++ Öğrenirken Yapmaman Gereken Hata

C'den geldiğin için her şeyi şu şekilde yazmaya çalışma:

```cpp
malloc
free
raw pointer
char*
manual array
printf
```

Bunları bilmen gerekir.

Ama modern C++ kodunda çoğu zaman daha yüksek seviyeli karşılıkları vardır:

```text
char*          → std::string
C array        → std::array / std::vector
malloc/free    → RAII / containers / smart pointers
printf         → iostream veya uygun modern formatting araçları
raw ownership  → unique_ptr / shared_ptr
manual loop    → STL algorithms / range-based for
```

Bu:

> "C++'ta pointer kullanılmaz."

anlamına gelmez.

Tam tersine pointer'ı çok iyi bilmelisin.

Ama **ne zaman raw pointer kullanacağını** bilmek, pointer syntax'ını bilmekten daha değerlidir.

---

# 85. `nullptr`

Modern C++'ta pointer'ın boş olduğunu belirtmek için:

```cpp
nullptr
```

kullanılır.

C'deki:

```c
NULL
```

yerine tercih edilir.

Örneğin:

```cpp
Robot* robot = nullptr;
```

Burada pointer herhangi bir object'i göstermiyor.

Modern C++ kodunda:

```cpp
nullptr
```

görmeye alış.

---

# 86. `const` Bir Tasarım Aracıdır

`const` sadece:

```cpp
const int x = 10;
```

demek değildir.

Fonksiyonlarda:

```cpp
void process(const Robot& robot);
```

çok önemlidir.

Bu imza okuyana bilgi verir:

```text
Robot kopyalanmayacak
Robot değiştirilmeyecek
```

Dolayısıyla C++'ta type signature aynı zamanda:

> "Bu fonksiyonun niyeti nedir?"

sorusuna cevap verir.

---

# 87. C++ Type System'ini Okumayı Öğren

Aşağıdaki ifadeyi gördüğünde:

```cpp
const std::vector<double>& readings
```

tek parça olarak korkma.

Sağdan sola / parçalarına ayır:

```text
readings
    ↓
&
    ↓
reference
    ↓
std::vector<double>
    ↓
double'lardan oluşan vector
    ↓
const
    ↓
fonksiyon bunu değiştiremez
```

Yani:

> `readings`, double vector'üne const reference'tır.

Bu şekilde karmaşık C++ declaration'ları okunabilir hale gelir.

---

# 88. Bir C++ Kodunu Okuma Sırası

Yeni bir robotics kodu gördüğünde şu sırayla incele:

## 1. Header'lar

```cpp
#include <...>
#include "..."
```

Hangi kütüphaneler kullanılıyor?

---

## 2. Namespace

```cpp
std::
rclcpp::
Eigen::
```

Hangi ecosystem'den geliyor?

---

## 3. Class

```cpp
class Robot
```

Hangi object tasarlanmış?

---

## 4. Members

```cpp
private:
    ...
```

Object hangi state'i tutuyor?

---

## 5. Constructor

```cpp
Robot(...)
```

Object başlangıçta nasıl kuruluyor?

---

## 6. Methods

```cpp
void move();
```

Object ne yapabiliyor?

---

## 7. Ownership

```cpp
unique_ptr
shared_ptr
reference
raw pointer
```

Kim kimin sahibi?

---

## 8. Lifetime

Object ne zaman oluşturuluyor?

Ne zaman yok oluyor?

---

## 9. Callback / Thread

Bir lambda veya callback varsa:

```cpp
[...](...)
{
    ...
}
```

ne zaman çağrılıyor?

---

# 89. Kodlarındaki Küçük Ama Önemli Hata

Şu örnekte:

```cpp
if (command = 'f')
{
    std::cout << "Command is 'f'" << std::endl;
}
```

burada `==` yerine `=` kullanılmış.

Doğrusu:

```cpp
if (command == 'f')
{
    std::cout << "Command is 'f'" << std::endl;
}
```

Fark:

```cpp
=
```

assignment:

```text
command'a 'f' ata
```

```cpp
==
```

comparison:

```text
command 'f' mi?
```

Senin yazdığın:

```cpp
command = 'f'
```

önce assignment yapıyor, sonra expression'ın sonucu üzerinden `if` çalışıyor.

Bu klasik ve çok önemli bir hatadır.

---

# 90. `float`, `double` ve Literal'lar

Kodunda:

```cpp
float battery_percentage = 75.5f;
```

buradaki:

```cpp
f
```

literal'ın `float` olduğunu belirtir.

```cpp
75.5
```

ise default olarak `double` literal'dır.

Dolayısıyla:

```cpp
float x = 5.5f;
```

ile:

```cpp
double x = 5.5;
```

farklıdır.

Robotics/embedded'te precision ve memory açısından `float` / `double` seçimi önem kazanabilir.

---

# 91. Ternary Operator

Kod:

```cpp
std::string status =
    battery_level > threshold
        ? "Sufficient"
        : "Low";
```

şunun kısa halidir:

```cpp
std::string status;

if (battery_level > threshold)
{
    status = "Sufficient";
}
else
{
    status = "Low";
}
```

Syntax:

```cpp
condition ? value_if_true : value_if_false;
```

Kısa seçimler için kullanışlıdır.

Çok karmaşık logic'i ternary içine doldurmak okunabilirliği düşürebilir.

---

# 92. `break` ve `continue`

Kod:

```cpp
if (distance[i] > max_distance)
{
    break;
}
```

`break`:

> İçinde bulunduğun loop'u tamamen bitir.

---

```cpp
if (distance[i] < 10)
{
    continue;
}
```

`continue`:

> Bu iteration'ı atla, sonraki iteration'a geç.

Robotics'te örneğin:

```text
sensor invalid
    ↓
continue
```

ve:

```text
critical safety condition
    ↓
break / stop
```

gibi mantıklar görebilirsin.

---

# 93. `do-while`

Kod:

```cpp
do
{
    ...
}
while (count < 3);
```

`while`'dan farkı:

> Body en az bir kere çalışır.

```cpp
while (condition)
{
    ...
}
```

ise condition ilk başta false ise hiç çalışmayabilir.

Robotics'te:

```text
execute once
then check condition
```

gereken durumlarda kullanılabilir.

---

# 94. Implicit Conversion

Örneğin:

```cpp
double speed = 5;
```

C++ `int` olan `5` değerini `double`'a dönüştürür.

Bu:

```text
implicit conversion
```

olarak adlandırılır.

Her implicit conversion kötü değildir.

Ama özellikle robotics/embedded'te:

```text
int
float
double
unsigned
signed
```

arasında dönüşümlere dikkat etmek gerekir.

---

# 95. Undefined Behavior Mantığı

C biliyorsan bunu zaten duymuş olmalısın:

> Compiler'ın sana güvenli bir sonuç vermek zorunda olmadığı durumlar.

C++ da aynı şekilde undefined behavior içerir.

Örneğin:

```cpp
int* p = nullptr;
std::cout << *p;
```

geçersizdir.

Modern C++ abstraction'ları bazı hata sınıflarını azaltır ama C++ hâlâ low-level bir dildir.

Bu yüzden:

```text
RAII
const
type system
smart pointers
STL
```

kullanmak güvenliği artırsa da temel memory bilgisinin yerini tutmaz.

---

# 96. C++'ta "Object" Kavramı

C'de genellikle:

```text
struct + functions
```

şeklinde düşünürsün.

C++:

```cpp
Robot robot;
```

dediğinde `robot` yalnızca bir veri collection'ı değil, davranışları olan bir object olabilir.

Örneğin:

```cpp
robot.move();
robot.stop();
robot.getBattery();
```

Object'in interface'i olur.

Bu OOP'nin temel düşüncesidir.

---

# 97. Inheritance

Gönderdiğin mevcut kodlarda inheritance'ın temel syntax'ı henüz örneklenmemiş olsa da robotics/ROS2'de çok sık göreceksin.

Örneğin:

```cpp
class MyNode : public rclcpp::Node
{
};
```

Burada:

```text
MyNode
  ↓
rclcpp::Node'dan türetilmiş
```

demektir.

`public` inheritance:

> Derived class, base class'ın public interface'ini uygun şekilde kullanır.

Inheritance gördüğünde ilk sor:

> "Bu class hangi base class'ın özelliklerini kullanıyor?"

---

# 98. Polymorphism

Bir base class pointer/reference'ı üzerinden farklı derived class'ların davranabilmesi polymorphism'dir.

Örneğin:

```cpp
class Sensor
{
public:
    virtual double read() = 0;
};
```

ve:

```cpp
class Lidar : public Sensor
{
public:
    double read() override;
};
```

Burada `Sensor` genel interface olabilir.

`Lidar` ise spesifik implementation'dır.

Robotics'te:

```text
Sensor
 ├── Lidar
 ├── Camera
 └── IMU
```

gibi abstraction'larda bu fikir yararlı olabilir.

---

# 99. `virtual` ve `override`

Polymorphism kullanırken:

```cpp
virtual
```

base class'taki davranışın derived class tarafından override edilebilmesini sağlar.

Derived class'ta:

```cpp
double read() override;
```

yazmak compiler'a:

> "Ben base class'taki virtual function'ı override ediyorum."

demektir.

`override` yazmak hataları yakalamaya yardımcı olduğu için tercih edilir.

---

# 100. Modern C++ İçin Genel Öncelik

C bildiğin için C++'ta öğrenme önceliğini şöyle düşün:

## Zaten Bildiğin Temeller

```text
if
for
while
switch
basic types
functions
arrays
pointers
basic operators
```

Bunları tekrar tekrar çalışmak gerekmiyor.

---

## Asıl Öğrenmen Gerekenler

```text
namespace
std::
string
vector
reference
const reference
auto
class
object
constructor
destructor
encapsulation
header/source
initializer list
overloading
inheritance
virtual
polymorphism
lambda
templates
STL
RAII
unique_ptr
shared_ptr
move semantics
multithreading
chrono
```

Bunlar C++ tarafındaki asıl farkı oluşturuyor.

---

# 101. C++ Mental Model — Tek Sayfada

C'de:

```text
data
 ↓
pointer
 ↓
manual resource management
 ↓
function
```

Modern C++:

```text
TYPE
 ↓
OBJECT
 ↓
LIFETIME
 ↓
OWNERSHIP
 ↓
BEHAVIOR
 ↓
RAII
 ↓
STL / LIBRARIES
```

Bir C++ object'i gördüğünde:

```text
Bu ne?
↓
Class/type

Ne tutuyor?
↓
Members

Nasıl oluşuyor?
↓
Constructor

Ne yapıyor?
↓
Methods

Kim erişebilir?
↓
public/private/protected

Ne kadar yaşıyor?
↓
Scope/lifetime

Resource sahibi kim?
↓
Ownership

Nasıl temizleniyor?
↓
Destructor/RAII

Kopyalanıyor mu?
↓
Copy semantics

Taşınıyor mu?
↓
Move semantics
```

Bu mental model C++ okuma becerinin temelidir.

---

# 102. Kod Okuma Egzersizi

Örneğin ileride şöyle bir kod görürsen:

```cpp
class RobotController
{
public:
    RobotController(std::shared_ptr<Robot> robot)
        : robot_(std::move(robot))
    {
    }

    void update(const std::vector<double>& sensors)
    {
        ...
    }

private:
    std::shared_ptr<Robot> robot_;
};
```

Bunu tek parça görüp korkmamalısın.

Parçala:

```text
class RobotController
```

→ RobotController isimli class.

```cpp
RobotController(...)
```

→ constructor.

```cpp
std::shared_ptr<Robot>
```

→ Robot üzerinde shared ownership.

```cpp
std::move(robot)
```

→ ownership/value move ediliyor.

```cpp
robot_
```

→ class member.

```cpp
const std::vector<double>& sensors
```

→ double vector'ü, kopyalanmıyor, değiştirilmesine izin yok.

Bu noktada kodu büyük ölçüde okuyabiliyorsan C++ tarafında doğru yoldasın.

---

# 103. C++ Öğrenirken En Önemli 10 Kavram

Bu kurstan sonra özellikle şu 10 kavramı gerçekten anlamış ol:

1. **Reference**
2. **`const`**
3. **Class / Object**
4. **Constructor / Destructor**
5. **RAII**
6. **STL / `vector`**
7. **Smart pointers**
8. **Ownership**
9. **Lambda**
10. **Templates**

Bunların syntax'ını ezberlemekten çok:

> **Neden varlar ve hangi problemi çözüyorlar?**

sorusuna cevap verebilmek önemli.

---

# 104. Robotics Junior Seviyesinde C++ İçin Hedef

C++ konusunda hedefin:

> "C++ standardındaki her şeyi bilmek"

olmamalı.

Hedef:

```text
C++ kodunu okuyabilmek
        ↓
class yapısını anlayabilmek
        ↓
STL kullanabilmek
        ↓
reference/pointer farkını anlayabilmek
        ↓
ownership anlayabilmek
        ↓
RAII mantığını anlayabilmek
        ↓
smart pointer okuyabilmek
        ↓
lambda okuyabilmek
        ↓
template syntax'ını okuyabilmek
        ↓
header/source yapısını anlayabilmek
        ↓
CMake ile projeyi build edebilmek
        ↓
ROS2 C++ kodunu okuyup değiştirebilmek
        ↓
kendi ROS2 node'unu yazabilmek
```

Bu seviyeye ulaşmak robotics/ROS2 için çok daha değerlidir.

---

# 105. Kursu Bitirirken Kendine Sor

Aşağıdaki sorulara bakmadan cevap verebiliyorsan iyi durumdasın:

### Namespace

- `std::` neden var?
- `using namespace std` neden büyük projelerde dikkatli kullanılmalı?

### STL

- `vector` neden C array'den farklı?
- `iterator` ne?
- `auto` ne yapıyor?

### Reference

- `T*` ile `T&` farkı ne?
- `const T&` neden çok kullanılıyor?

### OOP

- class ve object farkı ne?
- constructor ne zaman çalışıyor?
- destructor ne zaman çalışıyor?
- `private` neden var?
- initializer list neden kullanılıyor?

### Memory

- raw pointer ile owner aynı şey mi?
- `unique_ptr` neden var?
- `shared_ptr` neden var?
- `weak_ptr` ne problemi çözüyor?
- `std::move` neden gerekiyor?
- RAII ne?

### Project Structure

- `.hpp` neden var?
- `.cpp` neden ayrı?
- `Robot::greet()` ne anlama geliyor?
- include guard ne işe yarıyor?

### Modern C++

- lambda nedir?
- template nedir?
- STL nedir?
- exception nedir?
- `virtual` / `override` ne işe yarar?
- thread/mutex ne problemi çözer?

---

# 106. Son Mental Model

C biliyor olman C++ öğrenirken büyük avantaj.

Çünkü C++'ın altındaki:

```text
memory
pointer
stack
heap
function
array
address
compile
link
```

mantığını zaten biliyorsun.

Şimdi bunun üzerine şunu koyman gerekiyor:

```text
C
│
├── pointer
├── memory
├── function
├── struct
│
└───────────────┐
                ↓
             C++
                │
                ├── class
                ├── object
                ├── constructor
                ├── destructor
                ├── reference
                ├── namespace
                ├── STL
                ├── template
                ├── lambda
                ├── RAII
                ├── smart pointer
                ├── ownership
                ├── move semantics
                ├── polymorphism
                └── modern project structure
```

Asıl geçiş:

```text
C:

"Bu memory'nin adresi ne?"

        ↓

C++:

"Bu object'in type'ı ne?
Kim sahibi?
Ne kadar yaşayacak?
Nasıl initialize oluyor?
Nasıl yok oluyor?
Kopyalanıyor mu?
Taşınıyor mu?"
```

**C++'ın robotics açısından öğrenilmesi gereken özü budur.**

---

# 107. Kısa Referans — Syntax Cheat Sheet

```cpp
// Namespace
std::cout
std::string
std::vector<int>

// String
std::string name = "Robot";

// Vector
std::vector<int> values;
values.push_back(10);

// Auto
auto it = values.begin();

// Reference
int& ref = value;

// Const reference
const std::string& name

// Cast
static_cast<double>(x)

// Class
class Robot
{
private:
    int battery_;

public:
    Robot(int battery)
        : battery_(battery)
    {
    }

    void move();
};

// Constructor
Robot(...);

// Destructor
~Robot();

// Member definition outside class
void Robot::move()
{
}

// Function overloading
void move(int x);
void move(int x, int y);

// Exception
try
{
}
catch (const std::exception& e)
{
}

// Lambda
auto f = [](int x)
{
    return x * 2;
};

// Template
template <typename T>
T add(T a, T b)
{
    return a + b;
}

// Smart pointer
std::unique_ptr<Robot>
std::shared_ptr<Robot>
std::weak_ptr<Robot>

// Ownership transfer
std::move(ptr)

// Null pointer
nullptr

// Header
#ifndef ROBOT_HPP
#define ROBOT_HPP
...
#endif
```

---

# 108. Bu README'nin Kullanım Amacı

Bu dosya kurs boyunca bir **referans notu** olarak kullanılmalı.

Yeni bir şey gördüğünde:

```text
"Bu ne?"
```

diye bak.

Sonra:

```text
"Neden böyle yapılmış?"
```

diye düşün.

Son olarak:

```text
"C'de bunu nasıl yapardım?"
```

ile karşılaştır.

Özellikle C++'ta ezberlenecek syntax miktarı çoktur. Syntax'ın tamamını ezberlemeye çalışma.

Şu üç soruyu cevaplayabilmek daha değerlidir:

```text
1. Bu abstraction hangi problemi çözüyor?

2. C'de bunu nasıl yapardım?

3. Robotics/ROS2 kodunda neden bunu kullanmak isteyebilirim?
```

Bu üç soruya cevap verebildiğinde C++ artık sana yabancı bir dil gibi görünmemeye başlayacaktır.
