# ROBOTICS / EMBEDDED ROADMAP

> **Ana hedef:** 3–4 ay içinde junior robotics / embedded pozisyonlarına başvurabilecek seviyeye gelmek.

> **Ana prensip:**
> 
> **Learn → Build → Debug → Document → Move on**

---

# 0. BU ROADMAP NASIL KULLANILACAK?

Bu doküman benim **tek ana yol haritam**.

Kaybolduğumda:

1. Şu an hangi aydayım?
    
2. Hangi aşamadayım?
    
3. Bu aşamanın çıkış kriterlerini tamamladım mı?
    
4. Tamamladıysam sıradaki aşamaya geç.
    
5. Tamamlamadıysam eksik noktaya dön.
    
6. Yeni kurs/resource arama.
    

## Altın kural

**Bir konu = bir ana kaynak.**

Aynı şeyi:

- 5 YouTube playlistinden,
    
- 3 Udemy kursundan,
    
- 4 kitaptan
    

öğrenmeye çalışma.

Bir ana kaynak seç → çalış → proje yap → takıldığında dokümantasyona bak.

### Kullanacağım ana kaynaklar

| Alan       | Ana kaynak                                               |
| ---------- | -------------------------------------------------------- |
| C          | **Fehmi Uyar — C Programlama ve Algoritma Mantığı**      |
| C++        | **Fehmi Uyar — C++ Eğitim Seti**                         |
| OS         | **OSTEP — Operating Systems: Three Easy Pieces**         |
| Networking | **Computer Networking: A Top-Down Approach**             |
| ROS2       | **Taha Eren Karakış — Sıfırdan ROS2**                    |
| Embedded   | **ESP-IDF resmi dokümantasyonu + proje yaparak öğrenme** |
| Linux      | **Kullanarak + man pages**                               |
| Gazebo     | **ROS2/Gazebo dokümantasyonu + proje**                   |

## Şimdilik izlemeyeceğim / çalışmayacağım

- Aynı konuyu anlatan ikinci C kursu
    
- İkinci C++ kursu
    
- İkinci ROS2 kursu
    
- Rastgele "embedded roadmap" videoları
    
- Kernel seviyesinde OS çalışmaları
    
- İleri network uzmanlığı
    
- Gereksiz algoritma grind'i
    
- Sertifika kovalamak
    
- Her gördüğüm yeni teknoloji
    

**Yeni bir kaynak bulduğumda ilk sorum:**

> "Bu roadmap'teki hangi açığı kapatıyor?"

Cevap yoksa → **ignore.**

---

# 1. BÜYÜK RESİM

```text
                         C
                         │
                         ↓
              Low-Level C + Memory
                         │
                         ↓
                    C Projects
                         │
                         ↓
                 ESP32 / ESP-IDF
                         │
                         ↓
                     FreeRTOS
                         │
                         ↓
                       C++
                         │
              ┌──────────┼──────────┐
              ↓          ↓          ↓
            OOP         STL       RAII
              └──────────┼──────────┘
                         ↓
                       CMake
                         │
                         ↓
                       Linux
                         │
                 ┌───────┴───────┐
                 ↓               ↓
                OS           Networking
                 │               │
                 └───────┬───────┘
                         ↓
                    ROS2 Basics
                         │
                         ↓
                    ROS2 + C++
                         │
                         ↓
                URDF / Xacro / TF2
                         │
                         ↓
                   RViz2 + Gazebo
                         │
                         ↓
              Sensors + Odometry
                         │
                         ↓
                        EKF
                         │
                         ↓
                       SLAM
                         │
                         ↓
                       Nav2
                         │
                         ↓
              Autonomous Mobile Robot
                         │
                         ↓
                      GitHub
                         │
                         ↓
                Job Applications
```

---

# 2. ÖNCELİK SIRASI

Her şeyi aynı önemde görmeyeceğim.

## 🔴 CORE — Ana uzmanlık

Bunlar benim asıl yatırımım:

```text
C
↓
Embedded
↓
FreeRTOS
↓
C++
↓
ROS2
↓
Robotics
```

## 🟡 SUPPORT — Sistemi anlamak için

Bunlar önemli ama ana uzmanlığım değil:

```text
Linux
OS
Networking
CMake
Git
```

## 🟢 SECONDARY — Gerektiği kadar

```text
LeetCode
Python
Computer Vision
AI/ML
```

Bunlar daha sonra robotics projesinin ihtiyacına göre büyütülebilir.

---

# 3. AY 1 — C + EMBEDDED

## AY 1 ANA HEDEFİ

C'yi syntax seviyesinde bırakmamak.

Ay sonunda:

> "C ile program yazabiliyorum, memory/pointer mantığını anlayabiliyorum ve öğrendiğim kavramları mikrodenetleyici üzerinde kullanabiliyorum."

demeliyim.

---

# 3.1 C PROGRAMLAMA

## Ana kaynak

**Fehmi Uyar — C Programlama ve Algoritma Mantığı**

Yaklaşık:

- 130 video
    
- ~26 saat
    

### Öğreneceğim konular

```text
Variables
Data Types
Operators
Conditions
Loops
Functions
Arrays
Strings
Struct
Enum
Union
Header / Source
Compilation
Linking
```

Bunları sadece izlemeyeceğim.

Her konudan sonra:

```text
Öğren
 ↓
Kapat
 ↓
Kendin yaz
 ↓
Küçük problem çöz
```

---

# 3.2 LOW-LEVEL C

C'nin asıl önemli kısmı burada başlıyor.

## Pointer

```text
Pointer
Pointer arithmetic
Array ↔ Pointer
Function pointer
const
static
volatile
```

## Bit manipulation

```text
AND
OR
XOR
NOT
Left shift
Right shift
Bit masking
Register mantığı
```

Özellikle:

```text
1 bit set etmek
1 bit clear etmek
1 bit toggle etmek
bit okumak
register değiştirmek
```

konularını rahat yapabilmeliyim.

---

# 3.3 MEMORY

Öğreneceğim:

```text
Stack
Heap
Memory layout

malloc
calloc
realloc
free

Buffer
Buffer overflow
Lifetime
Ownership
Undefined Behavior
```

Burada amaç:

> "malloc ne işe yarıyor?"

sorusunu bilmek değil.

Şunu anlayabilmek:

> "Bu memory kimin sorumluluğunda, ne kadar yaşayacak ve ne zaman serbest bırakılacak?"

---

# 3.4 DEBUGGING

Öğreneceğim:

```text
GCC warnings
GDB
Breakpoint
Watch
Stack trace
Segmentation fault
Undefined behavior
```

Bir program çalışmadığında:

```text
"olmuyor"
```

demek yerine:

```text
Nerede bozuldu?
↓
Memory ne durumda?
↓
Variable ne durumda?
↓
Stack trace ne diyor?
↓
Neden bozuldu?
```

diye bakacağım.

---

# 3.5 C PROJELERİ

## Proje 1 — CLI Calculator

Öğreneceğim:

```text
Functions
Input / Output
Conditions
Error handling
```

---

## Proje 2 — Dynamic Array

Öğreneceğim:

```text
Pointers
Structs
malloc/free
Memory management
```

---

## Proje 3 — Stack / Queue

Öğreneceğim:

```text
Data structures
Pointers
Dynamic memory
```

---

## Proje 4 — Binary / Hex Utility

Öğreneceğim:

```text
Bitwise
Masking
Shifting
```

---

## Proje 5 — Simple Logger

Öğreneceğim:

```text
File I/O
Buffers
Structs
Error handling
```

---

# 3.6 ESP32 / ESP-IDF

Artık:

```text
C
 ↓
Gerçek donanım
```

bağlantısını kuracağım.

## Sıra

```text
GPIO
 ↓
PWM
 ↓
ADC
 ↓
UART
 ↓
Timer
 ↓
I2C
 ↓
SPI
 ↓
Interrupt
 ↓
FreeRTOS
```

---

# 3.7 GPIO

Öğren:

```text
Input
Output
Pull-up
Pull-down
Button
Debouncing
GPIO Interrupt
```

### Mini proje

**Button-controlled state machine**

---

# 3.8 PWM

Öğren:

```text
Frequency
Duty cycle
PWM output
```

### Mini proje

```text
Potentiometer
      ↓
     ADC
      ↓
    PWM
      ↓
     LED
```

---

# 3.9 ADC

Öğren:

```text
Analog input
Sampling
Resolution
Noise
Basic filtering
```

### Mini proje

**Sensor monitoring system**

---

# 3.10 UART

Öğren:

```text
TX
RX
Baud rate
Buffer
Interrupt-based communication
```

### Mini proje

PC → ESP32:

```text
led on
led off
pwm 50
adc
status
```

komutlarını gönderebil.

---

# 3.11 TIMER

Öğren:

```text
Hardware timer
Periodic interrupt
Timing
ISR
```

### Mini proje

Belirli aralıklarla sensor sampling sistemi.

---

# 3.12 I2C

Öğren:

```text
Address
Register
Master
Sensor communication
```

### Mini proje

Bir I2C sensöründen veri oku.

---

# 3.13 SPI

Öğren:

```text
Clock
MOSI
MISO
CS
Full duplex
```

### Mini proje

Bir SPI peripheral ile veri alışverişi.

---

# 3.14 FreeRTOS

ESP-IDF üzerinde:

```text
Task
Scheduler
Queue
Mutex
Semaphore
Event
Software Timer
ISR → Task communication
```

### Ana proje

```text
Sensor Task
      │
      ↓
    Queue
      │
      ↓
Processing Task
      │
      ↓
    Queue
      │
      ↓
Communication Task
      │
      ↓
    UART
```

Buradaki amaç API ezberlemek değil.

Amaç:

> **Concurrency ve embedded software architecture düşünmeye başlamak.**

---

# 3.15 AY 1 — OS + NETWORKING'E GİRİŞ

Bunları C/ESP32'den bağımsız ayrı bir dünya haline getirmeyeceğim.

Haftada birkaç oturum destekleyici olarak çalışacağım.

---

## OS — Ana kaynak

**OSTEP**

Öncelik:

```text
Processes
Process API
CPU scheduling
Address spaces
Memory
Paging
Threads
Locks
Condition variables
Semaphores
Concurrency
File systems
I/O
```

Kernel yazmayacağım.

Amaç:

> Programın işletim sistemi üzerinde nasıl çalıştığını anlamak.

---

## NETWORKING — Ana kaynak

**Computer Networking: A Top-Down Approach**

Öncelik:

```text
Application Layer
HTTP
DNS

Transport Layer
TCP
UDP
Sockets

Network Layer
IP
Routing

Link Layer
Ethernet
ARP
DHCP
```

Sonrasında:

```text
Wireshark
```

ile gerçek paketleri incele.

Networking'in amacı burada network engineer olmak değil.

Amaç:

> Embedded/robotics sistemlerinin ağ üzerinden nasıl iletişim kurduğunu anlamak.

---

# AY 1 ÇIKIŞ KRİTERİ

Aşağıdakiler tamamlanmadan "C öğrendim" demeyeceğim.

```text
[ ] C ile orta büyüklükte küçük program yazabiliyorum
[ ] Pointer kullanabiliyorum
[ ] Memory yönetimini anlayabiliyorum
[ ] Stack / heap farkını biliyorum
[ ] malloc/free kullanabiliyorum
[ ] Bit manipulation yapabiliyorum
[ ] GDB ile temel debugging yapabiliyorum
[ ] ESP-IDF ile GPIO kullanabiliyorum
[ ] PWM kullanabiliyorum
[ ] ADC okuyabiliyorum
[ ] UART kullanabiliyorum
[ ] Timer kullanabiliyorum
[ ] Interrupt kullanabiliyorum
[ ] I2C mantığını anlayabiliyorum
[ ] SPI mantığını anlayabiliyorum
[ ] FreeRTOS Task kullanabiliyorum
[ ] Queue / Mutex mantığını anlayabiliyorum
[ ] Basit OS process/thread mantığını anlayabiliyorum
[ ] Temel TCP/UDP/socket mantığını anlayabiliyorum
```

**Hepsi mükemmel olmak zorunda değil.**

Ama temel seviyede yapabiliyor ve araştırarak ilerleyebiliyor olmalıyım.

---

# 4. AY 2 — C++ + LINUX + ROS2

## AY 2 ANA HEDEFİ

```text
C / Embedded
      ↓
Modern C++
      ↓
Linux
      ↓
ROS2
```

Bu ayda artık sistem yazılımı ile robotics yazılımı birbirine bağlanıyor.

---

# 4.1 C++

## Ana kaynak

**Fehmi Uyar — C++ Eğitim Seti**

Yaklaşık:

- 120 video
    
- ~30 saat
    

---

## Temel

```text
Classes
Objects
Constructors
Destructors
Encapsulation
Inheritance
Polymorphism
```

---

# 4.2 STL

Öğren:

```text
vector
array
string
map
unordered_map
set
queue
stack
iterators
algorithms
```

Amaç STL'yi ezberlemek değil.

Bir problem geldiğinde:

> "Burada hangi container mantıklı?"

diye düşünebilmek.

---

# 4.3 C MEMORY → C++ MEMORY

C'deki memory bilgisini C++'a taşı.

```text
Stack
Heap
References
const
RAII
Ownership
unique_ptr
shared_ptr
Move semantics
Resource management
```

Özellikle:

> **RAII + ownership**

çok önemli.

Amaç:

> "C++ syntax biliyorum."

değil.

Amaç:

> **Güvenli, anlaşılır ve kaynak yönetimi düzgün C++ yazabilmek.**

---

# 4.4 CMAKE

Öğren:

```text
CMakeLists.txt
Targets
Libraries
Include directories
Linking
Build types
Dependencies
```

Temel proje:

```text
project/
├── CMakeLists.txt
├── include/
├── src/
└── tests/
```

Artık:

```text
g++ main.cpp
```

seviyesinden çıkıp gerçek proje build sistemine geç.

---

# 4.5 LINUX

Ubuntu üzerinde çalış.

## Terminal

```text
cd
ls
cp
mv
rm
grep
find
cat
less
tail
pipes
redirection
```

## System

```text
Process
Thread
File descriptor
Signals
Permissions
Environment variables
Basic IPC
```

## Development

```text
GCC
GDB
Git
CMake
SSH
```

Amaç:

> **Linux üzerinde C/C++ projesini build/debug/run edebilmek.**

Linux için yeni bir dev kursu arama.

Kullanarak öğren.

---

# 4.6 STM32

STM32'yi hemen almak zorunda değilim.

ESP32'de öğrendiğim kavramları STM32 tarafına taşı.

```text
ESP32              STM32

GPIO       →       GPIO
UART       →       USART
Timer      →       TIM
Interrupt  →       NVIC
ADC        →       ADC
PWM        →       TIM
I2C        →       I2C
SPI        →       SPI
```

Ek olarak:

```text
RCC
DMA — temel
```

Amaç:

> **Farklı MCU'larda aynı embedded problemini çözebildiğimi görmek.**

ESP32'de GPIO öğrenmişsem STM32 GPIO'yu sıfırdan bir ay daha çalışmayacağım.

---

# 4.7 LEETCODE

Sadece:

**10–30 problem.**

Öncelik:

```text
Array
String
Hash map
Stack
Queue
Linked list
Binary search
Basic tree
```

C++ STL kullan.

LeetCode ana çalışma alanım değil.

Amaç:

> C++ ile problem çözme hızını artırmak.

Günde 3 saat LeetCode yapıp robotics'i bırakmak yok.

---

# 4.8 ROS2

## Ana kaynak

**Taha Eren Karakış — Sıfırdan ROS2**

Yaklaşık:

- 34 video
    
- ~4.5 saat
    

Bu kursun amacı:

> ROS2 syntax + architecture öğrenmek.

Kursu bitirmek başarı kriteri değil.

---

# 4.9 ROS2 TEMELLERİ

Sırayla:

```text
Workspace
 ↓
Package
 ↓
Node
 ↓
Topic
 ↓
Publisher
 ↓
Subscriber
 ↓
Service
 ↓
Action
 ↓
Parameter
 ↓
Message
```

Bu kavramların birbirleriyle ilişkisini anlamalıyım.

---

# 4.10 ROS2 + C++

Ana geliştirme dili:

# C++

Python:

> Sadece örnekleri anlamak / gerektiğinde kullanmak için.

Öğren:

```text
rclcpp
Publisher
Subscriber
Timer
Service
Action
Parameters
Custom messages — temel
```

---

# 4.11 ROS2 MINI PROJECT

```text
Sensor Node
      │
      ↓
    Topic
      │
      ↓
Processing Node
      │
      ↓
    Topic
      │
      ↓
Control Node
```

Hepsini **C++** ile yaz.

---

# 4.12 ROS2 LAUNCH

Öğren:

```text
Launch files
Parameters
Multiple nodes
Configuration
```

Sonunda:

```text
ros2 launch ...
```

ile bütün sistemi başlatabil.

---

# AY 2 ÇIKIŞ KRİTERİ

```text
[ ] Modern C++ ile küçük proje yazabiliyorum
[ ] Classes kullanabiliyorum
[ ] STL kullanabiliyorum
[ ] RAII mantığını anlıyorum
[ ] Ownership mantığını anlıyorum
[ ] unique_ptr/shared_ptr mantığını biliyorum
[ ] CMake ile proje oluşturabiliyorum
[ ] Linux terminalinde rahatım
[ ] GCC/GDB/Git/CMake kullanabiliyorum
[ ] STM32 peripheral mantığını anlayabiliyorum
[ ] En az 10 LeetCode problemi çözdüm
[ ] ROS2 workspace oluşturabiliyorum
[ ] ROS2 package oluşturabiliyorum
[ ] Node oluşturabiliyorum
[ ] Publisher/subscriber yazabiliyorum
[ ] Service/action mantığını anlıyorum
[ ] ROS2 projesini C++ ile build/run edebiliyorum
[ ] Launch kullanabiliyorum
```

---

# 5. AY 3 — ROBOTICS + GAZEBO

Artık:

> **Teknoloji öğrenmekten → sistem kurmaya**

geçiyorum.

Ana ortam:

# ROS2 + Gazebo

Gazebo ayrı bir ders değil.

Gazebo:

> **C++, Linux, ROS2 ve robotics bilgisini birleştirdiğim simülasyon laboratuvarı.**

---

# 5.1 ROBOT DESCRIPTION — URDF

Öğren:

```text
Link
Joint
Visual
Collision
Inertial
Joint types
```

İlk robot:

**Differential-drive robot**

---

# 5.2 XACRO

URDF'nin daha düzenli ve tekrar kullanılabilir şekilde oluşturulmasını öğren.

---

# 5.3 TF2

Coordinate frame mantığını öğren.

```text
map
 │
 ↓
odom
 │
 ↓
base_link
 │
 ├── lidar_link
 ├── imu_link
 └── camera_link
```

Öğren:

```text
Translation
Rotation
Quaternion
Coordinate frames
Transform
```

Burayı atlama.

Robotics'te coordinate frame karmaşası ciddi problem çıkarır.

---

# 5.4 RVIZ2

Görüntüle:

```text
Robot model
TF
LaserScan
IMU
Odometry
Map
Path
```

Amaç:

> Robotun sistemde ne yaptığını görsel olarak takip edebilmek.

---

# 5.5 GAZEBO

Simülasyonda:

```text
Differential-drive robot
Wheels
Motors
LiDAR
IMU
Encoder
Camera
```

oluştur.

Gazebo ile:

```text
Physics
Gravity
Collision
Friction
Sensors
Robot dynamics
Simulated world
```

konularını gerçek robot olmadan deneyebilirsin.

---

# 5.6 BÜYÜK PROJE — DIFFERENTIAL DRIVE ROBOT

```text
              LiDAR
                │
                ↓
        ┌─────────────┐
        │    Robot    │
      O─│             │─O
        └─────────────┘
          ↑         ↑
       Encoder    Encoder
```

ROS2:

```text
/cmd_vel
/odom
/scan
/imu
/tf
```

Robotu C++ node'larıyla kontrol et.

---

# 5.7 ODOMETRY

Öğren:

```text
Wheel encoder
Wheel velocity
Differential-drive kinematics
Position estimation
Orientation estimation
```

Pipeline:

```text
Encoder
   ↓
Wheel velocity
   ↓
Differential-drive kinematics
   ↓
Odometry
   ↓
/odom
```

Burada matematiği ezberleme.

Robotun:

> "Ne kadar ilerledim ve ne kadar döndüm?"

sorusunu nasıl cevapladığını anla.

---

# 5.8 IMU

Öğren:

```text
Accelerometer
Gyroscope
Orientation
Noise
Bias
```

IMU verisini ROS2 üzerinden kullan.

---

# 5.9 SENSOR FUSION — EKF

Şimdi:

```text
Encoder ──────┐
              ├──→ EKF → Better state estimate
IMU ──────────┘
```

EKF'nin matematiğini en azından kavramsal olarak öğren.

Amaç:

> "Robot nerede?"

sorusuna tek sensörden daha iyi cevap verebilmek.

---

# 5.10 SLAM

LiDAR + odometry kullan.

```text
LiDAR
  +
Odometry
  ↓
 SLAM
  ↓
 Map
```

Robot:

```text
Çevreyi algılasın
       ↓
Harita oluştursun
       ↓
Kendi konumunu tahmin etsin
```

---

# 5.11 NAV2

Son aşama:

```text
Map
 ↓
Localization
 ↓
Path Planning
 ↓
Controller
 ↓
Robot
```

Robot:

```text
[ ] Goal kabul ediyor
[ ] Path oluşturuyor
[ ] Engellerden kaçıyor
[ ] Hedefe gidiyor
```

---

# 5.12 AY 3 FINAL PROJECT

# AUTONOMOUS MOBILE ROBOT

```text
                         ROS2
                           │
           ┌───────────────┼───────────────┐
           ↓               ↓               ↓
         LiDAR             IMU           Encoder
           │               │               │
           └───────────────┼───────────────┘
                           ↓
                          EKF
                           ↓
                      Localization
                           ↓
                          SLAM
                           ↓
                          Nav2
                           ↓
                  Autonomous Robot
                           ↑
                         Gazebo
```

Robot:

```text
[ ] Gazebo'da çalışacak
[ ] Differential-drive olacak
[ ] LiDAR kullanacak
[ ] IMU kullanacak
[ ] Encoder kullanacak
[ ] Odometry oluşturacak
[ ] EKF kullanacak
[ ] SLAM yapacak
[ ] Nav2 kullanacak
[ ] Goal'a gidecek
[ ] Engellerden kaçacak
```

Bu proje benim **ana portföy projem** olacak.

---

# 6. GERÇEK DONANIMA GEÇİŞ

Maddi imkan oluştuğunda:

```text
                 SIMULATION
                      │
                      ↓
                    Gazebo
                      │
              ┌───────┴───────┐
              ↓               ↓
            ROS2           Sensors
              │
              ↓
        Real Hardware
              │
        ┌─────┴─────┐
        ↓           ↓
      STM32        ESP32
        │
        ↓
   Motor Driver
        │
        ↓
      Motors
```

Önce simülasyonda sistemi kur.

Sonra:

> **Aynı sistemi gerçek donanıma taşı.**

---

# 7. GITHUB

Her önemli projeyi GitHub'a koy.

## Repository yapısı

```text
project/
├── README.md
├── src/
├── include/
├── config/
├── launch/
├── urdf/
├── worlds/
└── ...
```

## README

Her projede:

### 1. Problem

Ne yapıyorum?

### 2. Architecture

Sistem nasıl çalışıyor?

### 3. Technologies

```text
C/C++
ROS2
Gazebo
Linux
```

### 4. How to Build

Nasıl build edilir?

### 5. How to Run

Nasıl çalıştırılır?

### 6. Results

```text
Video
GIF
Screenshot
```

### 7. Problems & Solutions

Projede karşılaştığım **gerçek problemler**.

Bu bölüm özellikle önemli.

Çünkü:

> "Çalışan tutorial"

yerine:

> "Problemi çözen mühendis"

göstermek istiyorum.

---

# 8. PROJE / ÖĞRENME ORANI

## AY 1

```text
40% öğrenme
60% proje
```

## AY 2

```text
30% öğrenme
70% proje
```

## AY 3

```text
20% öğrenme
80% proje
```

Oran zamanla tersine dönecek.

Başlangıç:

```text
Tutorial dependency
```

Sonra:

```text
Documentation dependency
```

Sonunda:

```text
Independent problem solving
```

---

# 9. HER KONUDA UYGULAYACAĞIM DÖNGÜ

Her yeni konu:

```text
1. Öğren
      ↓
2. Küçük örnek yap
      ↓
3. Bilgisayarı kapat
      ↓
4. Kendin tekrar yaz
      ↓
5. Bir problem çöz
      ↓
6. Debug et
      ↓
7. GitHub'a koy
      ↓
8. Sonraki konu
```

Bir tutorial'ı izleyip:

> "Anladım."

demek **öğrenmek değildir.**

Asıl test:

> Bilgisayarı kapattığımda aynı şeyi kendim yazabiliyor muyum?

---

# 10. TAKILDIĞIMDA NE YAPACAĞIM?

Bir problemle karşılaştığımda hemen yeni kurs açmayacağım.

Şu sırayı izle:

```text
1. Hata mesajını oku
        ↓
2. Kendi kodumu incele
        ↓
3. Debugger / logs kullan
        ↓
4. Official documentation
        ↓
5. Google / Stack Overflow / GitHub issues
        ↓
6. Gerekirse AI'a soru sor
        ↓
7. Çöz
        ↓
8. Problemi README / notes'a yaz
```

Amaç:

> **Sorun çıktığında kaynak değiştirmek değil, sorunu çözmek.**

---

# 11. BİR KONUYU NE ZAMAN BIRAKACAĞIM?

Bir konuyu %100 bilmem gerekmiyor.

Şu üç koşul yeterli:

```text
[ ] Temel mantığını anlıyorum
[ ] Küçük bir şey yapabiliyorum
[ ] Bilmediğim kısmı dokümantasyondan araştırabiliyorum
```

Örneğin ROS2 Action'ın bütün API'sini ezberlemem gerekmiyor.

Ama:

> "Action nedir, ne zaman kullanılır ve dokümantasyondan nasıl implement ederim?"

biliyorsam devam.

---

# 12. NEYİ YAPMAYACAĞIM?

## ❌ Aynı konuyu tekrar tekrar öğrenmek

```text
C kursu
→ başka C kursu
→ başka C playlisti
→ başka C kitabı
```

Yok.

---

## ❌ Tutorial hell

```text
Tutorial
↓
Tutorial
↓
Tutorial
↓
Tutorial
```

yerine:

```text
Tutorial
↓
Project
↓
Problem
↓
Documentation
```

---

## ❌ Her teknolojiyi öğrenmek

Şimdilik:

```text
C
C++
ESP32
FreeRTOS
Linux
OS
Networking
CMake
ROS2
Gazebo
```

yeter.

---

## ❌ LeetCode'a gömülmek

10–30 problem yeterli.

---

## ❌ ROS2'yi Python'da bırakmak

ROS2 mimarisini öğrenirken Python örnekleri görülebilir.

Ama ana geliştirme:

# C++

---

## ❌ Gazebo'yu ayrı bir ders yapmak

Gazebo:

> **Laboratuvar.**

Öğrendiğim her şeyi orada birleştireceğim.

---

# 13. 3–4 AY SONUNDA HEDEF PROFİL

```text
ENGINEERING
│
├── C
│   ├── Memory
│   ├── Pointers
│   ├── Low-level
│   ├── Bitwise
│   └── Debugging
│
├── EMBEDDED
│   ├── ESP32
│   ├── ESP-IDF
│   ├── STM32 concepts
│   └── FreeRTOS
│
├── C++
│   ├── OOP
│   ├── STL
│   ├── RAII
│   ├── Ownership
│   └── CMake
│
├── LINUX
│   ├── Terminal
│   ├── Processes
│   ├── Threads
│   ├── Files
│   └── Debugging
│
├── NETWORKING
│   ├── TCP
│   ├── UDP
│   ├── IP
│   ├── HTTP
│   ├── DNS
│   └── Wireshark
│
└── ROBOTICS
    ├── ROS2
    ├── C++
    ├── TF2
    ├── URDF
    ├── RViz2
    ├── Gazebo
    ├── Sensors
    ├── Odometry
    ├── EKF
    ├── SLAM
    └── Nav2
```

---

# 14. NİHAİ HEDEF

Roadmap'in sonunda hedef:

> **"Bir robotics projesinde bana verilen kısmı, bilmediğim noktaları dokümantasyondan öğrenerek bağımsız şekilde geliştirebilmek."**

Yani hedef:

```text
"Her şeyi biliyorum."
```

değil.

Hedef:

```text
Problem
  ↓
Araştır
  ↓
Anla
  ↓
Uygula
  ↓
Debug
  ↓
Çöz
```

döngüsünü bağımsız şekilde çalıştırabilmek.

---

# 15. İŞ BAŞVURUSU HEDEFİ

```text
                    GitHub
                       │
                       ↓
             Autonomous Robot
                  Project
                       │
          ┌────────────┼────────────┐
          ↓            ↓            ↓
       Embedded       C++          ROS2
          │            │            │
          └────────────┼────────────┘
                       ↓
                    Robotics
                       │
              ┌────────┴────────┐
              ↓                 ↓
           I-TECH         Other Firms
```

**I-TECH ilk hedef.**

Ama roadmap tek firmaya göre tasarlanmayacak.

Hedef:

> I-TECH'e başvurabilecek seviyeye gelirken aynı zamanda başka robotics / embedded firmalarına da başvurabilecek genel bir temel oluşturmak.

---

# 16. TEK SAYFALIK KONTROL LİSTESİ

Her gün roadmap'i açmak yerine gerektiğinde buraya bak.

## PHASE 1 — C

```text
[ ] C fundamentals
[ ] Functions
[ ] Arrays
[ ] Struct
[ ] Pointers
[ ] Pointer arithmetic
[ ] Function pointers
[ ] const/static/volatile
[ ] Bitwise
[ ] Memory
[ ] malloc/free
[ ] UB
[ ] GDB
[ ] C projects
```

↓

## PHASE 2 — EMBEDDED

```text
[ ] GPIO
[ ] PWM
[ ] ADC
[ ] UART
[ ] Timer
[ ] Interrupt
[ ] I2C
[ ] SPI
[ ] FreeRTOS
[ ] Sensor → Processing → Communication
```

↓

## PHASE 3 — SYSTEMS SUPPORT

```text
[ ] Linux
[ ] Processes
[ ] Threads
[ ] File descriptors
[ ] IPC
[ ] TCP
[ ] UDP
[ ] IP
[ ] DNS
[ ] HTTP
[ ] Wireshark
```

↓

## PHASE 4 — C++

```text
[ ] Classes
[ ] OOP
[ ] STL
[ ] References
[ ] RAII
[ ] Ownership
[ ] Smart pointers
[ ] Move semantics
[ ] CMake
```

↓

## PHASE 5 — ROS2

```text
[ ] Workspace
[ ] Package
[ ] Node
[ ] Topic
[ ] Publisher
[ ] Subscriber
[ ] Service
[ ] Action
[ ] Parameter
[ ] Message
[ ] rclcpp
[ ] Launch
```

↓

## PHASE 6 — ROBOTICS

```text
[ ] URDF
[ ] Xacro
[ ] TF2
[ ] RViz2
[ ] Gazebo
[ ] Differential drive
[ ] LiDAR
[ ] IMU
[ ] Encoder
[ ] Odometry
[ ] EKF
[ ] SLAM
[ ] Nav2
```

↓

## PHASE 7 — PORTFOLIO

```text
[ ] Autonomous mobile robot
[ ] GitHub repository
[ ] README
[ ] Architecture diagram
[ ] Build instructions
[ ] Run instructions
[ ] Demo video/GIF
[ ] Problems & Solutions
[ ] CV update
[ ] Applications
```

---

# 17. BENİM KAYBOLMAMI ENGELLEYECEK TEK CÜMLE

Bir gün:

> "Acaba şunu da mı öğrenmeliyim?"

diye düşünürsem:

**Hayır.**

Önce roadmap'teki sıradaki kutuya bak.

```text
Şu anki kutu
     ↓
Öğren
     ↓
Proje yap
     ↓
Debug
     ↓
Dokümante et
     ↓
Çıkış kriterini kontrol et
     ↓
NEXT
```

Yeni teknoloji ancak mevcut projenin **gerçekten ihtiyaç duyduğu zaman** roadmap'e girer.

---

# 18. SON HALİ

```text
                 ┌─────────────┐
                 │      C      │
                 └──────┬──────┘
                        ↓
              ┌─────────────────┐
              │ Low-Level / Mem │
              └────────┬────────┘
                       ↓
              ┌─────────────────┐
              │   C Projects    │
              └────────┬────────┘
                       ↓
              ┌─────────────────┐
              │ ESP32 / ESP-IDF │
              └────────┬────────┘
                       ↓
              ┌─────────────────┐
              │    FreeRTOS     │
              └────────┬────────┘
                       ↓
              ┌─────────────────┐
              │       C++       │
              └────────┬────────┘
                       ↓
              ┌─────────────────┐
              │ CMake + Linux   │
              └────────┬────────┘
                       ↓
              ┌─────────────────┐
              │   OS + Network  │
              └────────┬────────┘
                       ↓
              ┌─────────────────┐
              │      ROS2       │
              └────────┬────────┘
                       ↓
              ┌─────────────────┐
              │    ROS2 + C++   │
              └────────┬────────┘
                       ↓
              ┌─────────────────┐
              │ URDF/Xacro/TF2  │
              └────────┬────────┘
                       ↓
              ┌─────────────────┐
              │ RViz2 + Gazebo  │
              └────────┬────────┘
                       ↓
              ┌─────────────────┐
              │ Sensors/Odom    │
              └────────┬────────┘
                       ↓
              ┌─────────────────┐
              │   EKF + SLAM    │
              └────────┬────────┘
                       ↓
              ┌─────────────────┐
              │      Nav2       │
              └────────┬────────┘
                       ↓
              ┌─────────────────┐
              │ Autonomous      │
              │ Mobile Robot    │
              └────────┬────────┘
                       ↓
                    GitHub
                       ↓
              I-TECH + Others
```

# Başla.

**İlk durak: C.**

Başka hiçbir şeyi düşünme.

Fehmi Uyar C → küçük C uygulamaları → low-level/memory → C projeleri.

Sonra ESP32.

Sonra FreeRTOS.

Sonra C++.

Sonra Linux/OS/networking desteği.

Sonra ROS2.

Sonra Gazebo.

Sonra robot.

**Birkaç ay boyunca işin bu.**
