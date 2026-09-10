# ROBOTICS / EMBEDDED ROADMAP

> **Ana hedef:** Güçlü bir embedded / firmware temeli oluşturmak ve bunun üzerine robotics uzmanlığı ekleyerek junior robotics / embedded pozisyonlarına başvurabilecek seviyeye gelmek.

> **Ana prensip:**
> 
> **Learn → Build → Debug → Document → Move on**

---

# 0. ROADMAP'İN ANA MANTIĞI

Bu roadmap'in amacı mümkün olan her teknolojiyi öğrenmek değil.

Önce:

> **Embedded/Firmware dünyasında mümkün olduğunca çok işte karşıma çıkacak ortak temeli kur.**

Sonra:

> **Robotics uzmanlığını bunun üzerine koy.**

En son:

> **Başvuracağım sektöre göre özel teknolojileri ekle.**

Bu nedenle roadmap üç ana katmandan oluşur:

```text
                         EMBEDDED / FIRMWARE
                                │
              ┌─────────────────┴─────────────────┐
              │                                   │
            CORE                               COMMON
              │                                   │
       C / C++ / MCU                       RTOS / ARM / Linux
       Memory / Debug                     Protocols / Testing
       Peripherals                        Bring-up / Networking
              │                                   │
              └─────────────────┬─────────────────┘
                                ↓
                         ROBOTICS CORE
                                │
                    ROS2 / C++ / Gazebo
                    Sensors / TF2 / Odom
                    EKF / SLAM / Nav2
                                │
                                ↓
                       SECTOR SPECIFIC
                                │
                CAN / BMS / FPGA / USB / MIPI
                BLE / QNX / UDS / DO-178C
                ARINC / MIL-STD / vb.
```

---

# 1. ÖNCELİK SIRASI

## 🔴 CORE — KESİNLİKLE ÖĞREN

Bunlar embedded / firmware tarafının temelidir.

```text
C
C++
Low-Level C
Memory
Pointers
Bitwise
Debugging

Microcontrollers
ARM / Cortex-M
GPIO
Timers
Interrupts
ADC
PWM

UART
SPI
I2C

Git
CMake
Basic Linux
```

Bunlar roadmap'in **ana gövdesidir.**

---

# 2. 🟠 COMMON — ÇOK SAYIDA İŞTE KARŞIMA ÇIKACAK

Bunlar her pozisyonda aynı ölçüde gerekli olmayabilir fakat embedded/firmware işlerinin büyük bölümünde ciddi değer taşır.

```text
RTOS
FreeRTOS concepts
Hardware bring-up
Driver development
Schematic reading
Hardware debugging
Testing
Unit / Integration / Regression
Python scripting
Ethernet
TCP / UDP
Multithreading
Concurrency
Performance / Memory optimization
```

Özellikle:

```text
C
 ↓
MCU
 ↓
Peripherals
 ↓
RTOS
 ↓
Debugging
 ↓
Testing
 ↓
Bring-up
```

zincirini kurmak hedef.

---

# 3. 🟡 ROBOTICS SPECIALIZATION

CORE + COMMON temeli oluştuktan sonra robotics tarafına geçiyorum.

```text
C++
 ↓
ROS2
 ↓
URDF / Xacro
 ↓
TF2
 ↓
RViz2
 ↓
Gazebo
 ↓
Sensors
 ↓
Odometry
 ↓
EKF
 ↓
SLAM
 ↓
Nav2
```

Bu bölüm beni genel embedded adayından:

> **Embedded + Robotics**

profiline taşıyacak.

---

# 4. 🟢 SECTOR / JOB SPECIFIC

Bunlar başlangıçta öğrenilecek şeyler değil.

İlana ve sektöre göre sonradan eklenir.

### Automotive

```text
CAN
CAN FD
UDS
BMS
Functional Safety
MISRA C
```

### Aerospace / Defense

```text
DO-178C
ARINC 429
MIL-STD-1553
FlexRay
Safety-critical systems
```

### Consumer Electronics

```text
USB
BLE
Wi-Fi
MIPI
HDMI
PCIe
DDR
SoC
```

### FPGA / Digital Hardware

```text
FPGA
VHDL
Verilog
Mixed-signal
```

### Hardware Design

```text
PCB design
PCB layout
SPICE
PSPICE
MATLAB
Cadence / OrCAD
```

### Embedded Linux

```text
Linux kernel
Device drivers
QNX
```

Bu teknolojiler **CORE değildir.**

Bir iş gerçekten gerektiriyorsa öğrenilir.

---

# 5. KAYNAK SİSTEMİ

> **Bir konu = bir ana kaynak.**

Aynı konuyu birçok kursla öğrenmeye çalışmayacağım.

|Alan|Ana kaynak|
|---|---|
|C|**Fehmi Uyar — C Programlama ve Algoritma Mantığı**|
|Low-Level C|**Columbia — Low-Level C Programming** referans dokümanı|
|C++|**Fehmi Uyar — C++ Eğitim Seti**|
|OS|**OSTEP — Operating Systems: Three Easy Pieces**|
|Networking|**Computer Networking: A Top-Down Approach**|
|Embedded|**ESP-IDF resmi dokümantasyonu + proje**|
|Linux|**Kullanarak + man pages**|
|ROS2|**Taha Eren Karakış — Sıfırdan ROS2**|
|Gazebo|**ROS2/Gazebo resmi dokümantasyonu + proje**|

Official documentation ikinci bir kurs değildir.

Bir şeyi öğrenirken:

```text
Ana kaynak
    ↓
Proje
    ↓
Takıldım
    ↓
Official documentation
```

şeklinde ilerleyeceğim.

---

# 6. PHASE 1 — C

## Hedef

C'yi syntax seviyesinde bırakmamak.

Şu seviyeye gelmek:

> **C ile program yazabiliyorum ve programın memory üzerinde nasıl çalıştığını anlayabiliyorum.**

---

## 6.1 C FUNDAMENTALS

Öğren:

```text
Variables
Data types
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

Ana kaynak:

**Fehmi Uyar — C Programlama ve Algoritma Mantığı**

---

# 7. LOW-LEVEL C

C'nin embedded tarafında kritik olan bölümü.

## Pointers

```text
Pointer
Pointer arithmetic
Array ↔ Pointer
Pointer parameters
Function pointers
const
static
volatile
```

---

## Bit manipulation

```text
AND
OR
XOR
NOT

Left shift
Right shift

Bit masking

Set bit
Clear bit
Toggle bit
Read bit
```

Hedef:

```text
Register
   ↓
Bit
   ↓
Mask
   ↓
Modify
```

mantığını rahatça anlayabilmek.

---

# 8. MEMORY

Öğren:

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

Asıl amaç:

> Memory'nin nerede bulunduğunu, ne kadar yaşadığını ve kimin sorumluluğunda olduğunu anlayabilmek.

---

# 9. C DEBUGGING

Öğren:

```text
GCC warnings
GDB
Breakpoints
Watch
Stack trace
Segmentation fault
Undefined behavior
```

Debugging düşüncesi:

```text
Problem
 ↓
Reproduce
 ↓
Locate
 ↓
Inspect
 ↓
Understand
 ↓
Fix
 ↓
Verify
```

---

# 10. C PROJECTS

## Project 1 — CLI Calculator

```text
Functions
Input / Output
Conditions
Error handling
```

## Project 2 — Dynamic Array

```text
Pointers
Structs
malloc/free
Memory management
```

## Project 3 — Stack / Queue

```text
Data structures
Pointers
Dynamic memory
```

## Project 4 — Binary / Hex Utility

```text
Bitwise
Masking
Shifting
```

## Project 5 — Logger

```text
File I/O
Buffers
Structs
Error handling
```

---

# 11. PHASE 2 — EMBEDDED CORE

Artık:

```text
C
 ↓
Microcontroller
```

bağlantısını kuruyorum.

Buradan itibaren roadmap'in en önemli bölümlerinden biri başlıyor.

---

# 12. MICROCONTROLLER FUNDAMENTALS

En az bir MCU'yu gerçekten kullanabilmek.

Ana platform:

> **ESP32 / ESP-IDF**

Öğren:

```text
MCU architecture
CPU
Memory
Flash
RAM
Registers
Peripherals
Interrupts
Timers
GPIO
```

---

# 13. ARM / CORTEX-M

ARM'i ayrı bir uzmanlık olarak değil, MCU mimarisini anlamak için öğren.

Öğren:

```text
ARM architecture
Cortex-M concepts
Registers
Memory map
Interrupts
NVIC
Exception handling
Peripheral registers
```

Assembly öğrenme hedefi yok.

Ama:

> C kodunun MCU üzerinde CPU/register/memory seviyesinde nasıl çalıştığını

anlayabilmeliyim.

---

# 14. MCU PERIPHERALS

Ana sıra:

```text
GPIO
 ↓
Timer
 ↓
Interrupt
 ↓
PWM
 ↓
ADC
 ↓
UART
 ↓
I2C
 ↓
SPI
```

---

# 15. GPIO

Öğren:

```text
Input
Output
Pull-up
Pull-down
Button
Debouncing
GPIO interrupt
```

### Mini Project

**Button-controlled state machine**

---

# 16. TIMER / INTERRUPTS

Öğren:

```text
Hardware timer
Periodic interrupt
ISR
Timing
Interrupt latency
ISR limitations
```

Mini project:

> Belirli aralıklarla sensor sampling sistemi.

---

# 17. PWM

Öğren:

```text
Frequency
Duty cycle
PWM generation
```

Project:

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

# 18. ADC

Öğren:

```text
Analog input
Resolution
Sampling
Noise
Basic filtering
```

Project:

> Sensor monitoring system.

---

# 19. UART

Öğren:

```text
TX
RX
Baud rate
Frames
Buffers
Interrupt-based communication
```

Project:

```text
PC
 ↓
UART
 ↓
ESP32
```

Komut sistemi:

```text
led on
led off
pwm 50
adc
status
```

---

# 20. I2C

Öğren:

```text
Master
Slave
Address
Register
Read
Write
Sensor communication
```

Project:

> Bir I2C sensöründen veri oku ve anlamlı şekilde işle.

---

# 21. SPI

Öğren:

```text
Clock
MOSI
MISO
CS
Full duplex
```

Project:

> Bir SPI peripheral ile veri alışverişi.

---

# 22. HARDWARE DEBUGGING

Artık sadece kod debug etmeyeceğim.

Öğren:

```text
Schematic okuma
Datasheet okuma
Pinout
Voltage levels
Signal flow
Peripheral configuration
```

Temel araçları tanı:

```text
Debugger
Logic analyzer
Oscilloscope
Multimeter
```

Amaç:

> "Kodum doğru görünüyor ama hardware neden çalışmıyor?"

sorusunu araştırabilmek.

---

# 23. HARDWARE BRING-UP

Çok önemli COMMON becerilerinden biri.

Bir board / peripheral / sensor geldiğinde:

```text
Hardware
 ↓
Power
 ↓
MCU
 ↓
Flash firmware
 ↓
UART / logging
 ↓
Peripheral initialization
 ↓
Communication test
 ↓
Debug
 ↓
Integration
```

mantığını anlayabilmeliyim.

---

# 24. DRIVER DEVELOPMENT

Öğren:

```text
Hardware peripheral
 ↓
Register / interface
 ↓
Driver
 ↓
Application
```

Bir peripheral için:

```text
Initialize
Configure
Read
Write
Error handling
```

katmanlarını düşünebilmek.

---

# 25. RTOS

RTOS artık **COMMON** seviyesinde.

Ana platform:

> **FreeRTOS / ESP-IDF**

Öğren:

```text
Task
Scheduler
Queue
Mutex
Semaphore
Event
Software timer
ISR → Task communication

Concurrency
Synchronization
Race condition
Priority
Stack
Task lifetime
```

Ana proje:

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

Amaç:

> RTOS API ezberlemek değil.

Amaç:

> **Concurrent embedded software architecture tasarlayabilmek.**

---

# 26. TESTING

Embedded iş ilanlarında tekrar tekrar karşılaşılabilecek ortak beceri.

Öğren:

```text
Unit testing
Integration testing
Regression testing
Functional testing
Test automation
Assertions
Testable code
```

Mümkün olduğunca projelerde:

```text
Code
 ↓
Test
 ↓
Debug
 ↓
Fix
 ↓
Regression test
```

döngüsünü kullan.

---

# 27. PERFORMANCE / MEMORY / POWER

Embedded sistemlerde kaynaklar sınırlıdır.

Öğren:

```text
CPU usage
Memory usage
Stack usage
Heap usage
Timing
Latency
Power consumption
Optimization
```

Amaç:

> "Kod çalışıyor."

seviyesinden:

> "Kod doğru, zamanında çalışıyor ve kaynakları kontrol altında."

seviyesine geçmek.

---

# 28. PYTHON

Python ana uzmanlık değil.

Sadece gerektiği kadar:

```text
Scripting
Serial communication
Test automation
Log processing
Data processing
Build / tooling scripts
```

Öğren.

Amaç Python developer olmak değil.

---

# 29. PHASE 3 — LINUX + SYSTEMS

Embedded development'in destek katmanı.

---

# 30. LINUX

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

> **Linux üzerinde C/C++ projesi build/debug/run edebilmek.**

---

# 31. OPERATING SYSTEMS

Ana kaynak:

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

Kernel yazmak yok.

Amaç:

> Programın OS üzerinde nasıl çalıştığını anlamak.

---

# 32. NETWORKING

Ana kaynak:

**Computer Networking: A Top-Down Approach**

Öncelik:

```text
TCP
UDP
IP
Routing

HTTP
DNS

Sockets

Ethernet
ARP
DHCP
```

Sonrasında:

> Wireshark

ile gerçek paketleri incele.

Networking'de hedef network engineer olmak değil.

Amaç:

> Embedded/robotics sistemlerinin ağ üzerinden nasıl haberleştiğini anlamak.

---

# 33. ETHERNET

Ethernet'i özellikle COMMON seviyesinde tut.

Öğren:

```text
Ethernet frame
MAC address
Switching
IP
TCP / UDP
Sockets
Latency
Bandwidth
Packet loss
```

Daha sonra robotics ve embedded networking projelerinde kullan.

---

# 34. GIT + CMAKE

## Git

```text
clone
branch
commit
merge
rebase — temel
diff
log
tag
```

Amaç:

> Profesyonel bir projede çalışabilecek seviyede Git kullanmak.

## CMake

```text
CMakeLists.txt
Targets
Libraries
Include directories
Linking
Build types
Dependencies
Tests
```

Proje:

```text
project/
├── CMakeLists.txt
├── include/
├── src/
└── tests/
```

---

# 35. PHASE 4 — C++

Artık C temelinin üzerine modern C++.

Ana kaynak:

**Fehmi Uyar — C++ Eğitim Seti**

---

# 36. C++ FUNDAMENTALS

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

# 37. STL

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

Amaç:

> Hangi problemde hangi STL yapısının uygun olduğunu anlayabilmek.

---

# 38. C++ MEMORY

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

---

# 39. C++ PROJECT

Bir orta boyutlu C++ projesi yap.

Örneğin:

```text
Sensor abstraction
        ↓
Data processing
        ↓
Logger
        ↓
Configuration
```

Projede:

```text
C++
STL
RAII
CMake
Git
Testing
```

birlikte kullan.

---

# 40. STM32

STM32 ayrı bir başlangıç roadmap'i değil.

ESP32'de öğrendiğim embedded kavramlarını başka MCU'ya taşıma aşaması.

```text
ESP32                STM32

GPIO       →         GPIO
UART       →         USART
Timer      →         TIM
Interrupt  →         NVIC
ADC        →         ADC
PWM        →         TIM
I2C        →         I2C
SPI        →         SPI
```

Ek olarak:

```text
RCC
DMA — temel
```

Amaç:

> **"Sadece ESP32 biliyorum."**

yerine:

> **"MCU mantığını biliyorum; farklı MCU'ya adapte olabilirim."**

demek.

---

# 41. PHASE 5 — ROBOTICS

Artık CORE + COMMON temelinin üzerine robotics koyuyorum.

Ana ortam:

> **ROS2 + C++ + Gazebo**

---

# 42. ROS2

Ana kaynak:

**Taha Eren Karakış — Sıfırdan ROS2**

Öğren:

```text
Workspace
Package
Node
Topic
Publisher
Subscriber
Service
Action
Parameter
Message
```

---

# 43. ROS2 + C++

Ana geliştirme dili:

> **C++**

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

Mini project:

```text
Sensor Node
      ↓
    Topic
      ↓
Processing Node
      ↓
    Topic
      ↓
Control Node
```

---

# 44. ROS2 LAUNCH

Öğren:

```text
Launch files
Parameters
Multiple nodes
Configuration
```

Hedef:

```text
ros2 launch ...
```

ile sistemi başlatabilmek.

---

# 45. URDF / XACRO

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

> Differential-drive robot

Xacro ile daha düzenli robot description oluştur.

---

# 46. TF2

Öğren:

```text
Coordinate frames
Translation
Rotation
Quaternion
Transform
```

Temel yapı:

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

---

# 47. RVIZ2

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

> Robotun sistem içerisinde ne yaptığını görsel olarak takip edebilmek.

---

# 48. GAZEBO

Gazebo'yu ayrı bir teori dersi olarak görme.

Gazebo:

> **Embedded + C++ + Linux + ROS2 + robotics bilgisini birleştirdiğim laboratuvar.**

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

kullan.

---

# 49. ODOMETRY

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
Kinematics
 ↓
Odometry
 ↓
/odom
```

---

# 50. IMU

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

# 51. SENSOR FUSION — EKF

```text
Encoder ──────┐
              ├──→ EKF → State estimate
IMU ──────────┘
```

Kavramsal olarak öğren:

```text
State
Prediction
Measurement
Correction
Noise
```

Amaç:

> Robotun konumunu tek sensörden daha güvenilir tahmin edebilmek.

---

# 52. SLAM

LiDAR + odometry:

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
Çevreyi algılar
      ↓
Harita oluşturur
      ↓
Konumunu tahmin eder
```

---

# 53. NAV2

Son robotics katmanı:

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
Goal kabul eder
Path oluşturur
Engellerden kaçar
Hedefe gider
```

---

# 54. FINAL PROJECT — AUTONOMOUS MOBILE ROBOT

Ana portföy projesi:

```text
                         ROS2
                           │
            ┌──────────────┼──────────────┐
            ↓              ↓              ↓
          LiDAR           IMU          Encoder
            │              │              │
            └──────────────┼──────────────┘
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
[ ] Differential-drive
[ ] LiDAR
[ ] IMU
[ ] Encoder
[ ] Odometry
[ ] EKF
[ ] SLAM
[ ] Nav2
[ ] Goal navigation
[ ] Obstacle avoidance
```

Bu proje:

> **C/C++ → Linux → RTOS/embedded mantığı → networking → ROS2 → robotics**

birikiminin vitrini olacak.

---

# 55. PHASE 6 — REAL HARDWARE

Maddi imkan oluştuğunda:

```text
Simulation
    ↓
Gazebo
    ↓
ROS2
    ↓
Sensors
    ↓
Real hardware
    ↓
MCU
    ↓
Motor driver
    ↓
Motors
```

Hedef:

> Simülasyonda çözdüğüm problemi gerçek donanıma taşıyabilmek.

---

# 56. PHASE 7 — SECTOR / JOB SPECIFIC

Bu bölüm **CORE bittikten sonra** açılacak.

Burada bütün teknolojileri öğrenmeye çalışmayacağım.

İlana göre seçim yapacağım.

---

## Automotive

```text
CAN
CAN FD
UDS
BMS
Functional Safety
MISRA C
```

---

## Aerospace / Defense

```text
DO-178C
ARINC 429
MIL-STD-1553
FlexRay
10BaseT1S
Safety-critical development
```

---

## Consumer Electronics

```text
USB
BLE
Wi-Fi
MIPI
HDMI
PCIe
DDR
SoC
```

---

## FPGA

```text
FPGA
VHDL
Verilog
Digital design
```

---

## Hardware Design

```text
PCB design
PCB layout
SPICE
PSPICE
MATLAB
Cadence
OrCAD
```

---

## Embedded Linux

```text
Linux kernel
Device drivers
QNX
```

---

# 57. CAN — SECTOR ÖRNEĞİ

CAN artık ilk aşamada öğrenilecek CORE değil.

Ama:

> Automotive / robotics / industrial / battery sistemleri hedefleniyorsa

yüksek öncelikli hale gelir.

Öğren:

```text
CAN bus
CAN node
CAN frame
Identifier
Arbitration
TX / RX
Error handling
CAN FD — daha sonra
UDS — ihtiyaç halinde
```

---

# 58. BMS — SECTOR ÖRNEĞİ

BMS:

> Embedded'in temel konusu değil, belirli bir ürün/sektör uzmanlığıdır.

Gerekirse:

```text
Battery cells
Voltage measurement
Current measurement
Temperature
SOC
SOH
Balancing
Protection
Charging
CAN
```

öğrenilir.

---

# 59. PORTFOLIO

Her önemli projeyi GitHub'a koy.

Örnek:

```text
project/
├── README.md
├── src/
├── include/
├── tests/
├── config/
├── launch/
├── urdf/
├── worlds/
└── ...
```

README:

```text
Problem
Architecture
Technologies
Build
Run
Results
Problems & Solutions
```

Özellikle:

> **Problems & Solutions**

bölümü önemli.

Sadece:

> "Tutorial'ı yaptım."

değil:

> "Bir problem yaşadım → araştırdım → debug ettim → nedenini buldum → düzelttim."

göstermek istiyorum.

---

# 60. ÖĞRENME / PROJE ORANI

## Başlangıç

```text
40% Learning
60% Building
```

## Orta aşama

```text
30% Learning
70% Building
```

## Son aşama

```text
20% Learning
80% Building
```

Hedef:

```text
Tutorial dependency
        ↓
Documentation dependency
        ↓
Independent problem solving
```

---

# 61. HER KONUDA KULLANILACAK DÖNGÜ

```text
Learn
 ↓
Small example
 ↓
Build
 ↓
Break
 ↓
Debug
 ↓
Fix
 ↓
Document
 ↓
Move on
```

Bir konuyu %100 bilmek gerekmiyor.

Şunlar yeterli:

```text
[ ] Temel mantığını anlıyorum
[ ] Küçük bir şey yapabiliyorum
[ ] Bilmediğim kısmı araştırabiliyorum
[ ] Debug edebiliyorum
```

---

# 62. TAKILDIĞIMDA

Kaynak değiştirmeyeceğim.

```text
1. Error message
       ↓
2. Own code
       ↓
3. Logs / debugger
       ↓
4. Documentation
       ↓
5. Search / GitHub issues
       ↓
6. AI
       ↓
7. Fix
       ↓
8. Document
```

Amaç:

> **Sorun çıkınca yeni teknolojiye kaçmak değil, mevcut problemi çözmek.**

---

# 63. LEETCODE

Ana çalışma alanı değil.

Toplam:

> **10–30 problem**

Yeterli.

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

---

# 64. 3–4 AY SONUNDA HEDEF PROFİL

```text
ENGINEERING
│
├── C
│   ├── Pointers
│   ├── Memory
│   ├── Low-level
│   ├── Bitwise
│   └── Debugging
│
├── EMBEDDED CORE
│   ├── MCU
│   ├── ARM / Cortex-M
│   ├── GPIO
│   ├── Timer
│   ├── Interrupt
│   ├── ADC
│   ├── PWM
│   ├── UART
│   ├── SPI
│   └── I2C
│
├── EMBEDDED COMMON
│   ├── RTOS
│   ├── FreeRTOS
│   ├── Driver development
│   ├── Hardware bring-up
│   ├── Schematic reading
│   ├── Hardware debugging
│   ├── Testing
│   ├── Python scripting
│   └── Ethernet
│
├── C++
│   ├── OOP
│   ├── STL
│   ├── RAII
│   ├── Ownership
│   └── CMake
│
├── LINUX / SYSTEMS
│   ├── Linux
│   ├── Processes
│   ├── Threads
│   ├── Memory
│   ├── IPC
│   ├── TCP
│   ├── UDP
│   └── Wireshark
│
└── ROBOTICS
    ├── ROS2
    ├── ROS2 C++
    ├── URDF
    ├── Xacro
    ├── TF2
    ├── RViz2
    ├── Gazebo
    ├── LiDAR
    ├── IMU
    ├── Encoder
    ├── Odometry
    ├── EKF
    ├── SLAM
    └── Nav2
```

---

# 65. ROADMAP'İN EN ÖNEMLİ AYRIMI

## 🔴 CORE

```text
C
C++
MCU
ARM
Memory
Pointers
Debugging

GPIO
Timer
Interrupt
ADC
PWM

UART
SPI
I2C

Git
CMake
Linux
```

## 🟠 COMMON

```text
RTOS
FreeRTOS
Hardware bring-up
Driver development
Schematic
Testing
Python
Ethernet
Networking
Performance
Memory optimization
```

## 🟡 ROBOTICS

```text
ROS2
ROS2 C++
Gazebo
URDF
TF2
Sensors
Odometry
EKF
SLAM
Nav2
```

## 🟢 SECTOR / JOB SPECIFIC

```text
CAN
BMS
USB
BLE
Wi-Fi
FPGA
VHDL
MIPI
PCIe
QNX
UDS
MISRA C
DO-178C
ARINC 429
MIL-STD-1553
...
```

---

# 66. TEK SAYFALIK KONTROL LİSTESİ

## 🔴 CORE — FIRST

```text
[ ] C fundamentals
[ ] Functions
[ ] Arrays
[ ] Struct / Enum / Union
[ ] Pointers
[ ] Pointer arithmetic
[ ] const / static / volatile
[ ] Bitwise
[ ] Memory
[ ] malloc / free
[ ] Undefined behavior
[ ] GDB

[ ] Microcontroller concepts
[ ] ARM / Cortex-M
[ ] GPIO
[ ] Timer
[ ] Interrupt
[ ] ADC
[ ] PWM
[ ] UART
[ ] I2C
[ ] SPI

[ ] Git
[ ] CMake
[ ] Linux basics
```

---

## 🟠 COMMON

```text
[ ] RTOS concepts
[ ] FreeRTOS
[ ] Tasks
[ ] Queue
[ ] Mutex
[ ] Semaphore
[ ] Concurrency

[ ] Driver development
[ ] Schematic reading
[ ] Datasheet reading
[ ] Hardware debugging
[ ] Hardware bring-up

[ ] Unit testing
[ ] Integration testing
[ ] Regression testing
[ ] Test automation

[ ] Python scripting
[ ] Ethernet
[ ] TCP / UDP
[ ] Performance
[ ] Memory optimization
```

---

## 🟡 ROBOTICS

```text
[ ] C++ fundamentals
[ ] OOP
[ ] STL
[ ] RAII
[ ] Ownership
[ ] Smart pointers
[ ] CMake

[ ] ROS2
[ ] Workspace
[ ] Package
[ ] Node
[ ] Topic
[ ] Publisher
[ ] Subscriber
[ ] Service
[ ] Action
[ ] Parameter
[ ] rclcpp
[ ] Launch

[ ] URDF
[ ] Xacro
[ ] TF2
[ ] RViz2
[ ] Gazebo
[ ] LiDAR
[ ] IMU
[ ] Encoder
[ ] Odometry
[ ] EKF
[ ] SLAM
[ ] Nav2
```

---

## 🟢 SECTOR SPECIFIC

```text
[ ] CAN
[ ] CAN FD
[ ] UDS
[ ] BMS
[ ] MISRA C
[ ] Functional Safety

[ ] USB
[ ] BLE
[ ] Wi-Fi
[ ] MIPI
[ ] PCIe
[ ] HDMI
[ ] DDR

[ ] FPGA
[ ] VHDL / Verilog

[ ] PCB
[ ] SPICE
[ ] MATLAB

[ ] QNX
[ ] Linux Kernel

[ ] DO-178C
[ ] ARINC 429
[ ] MIL-STD-1553
```

---

# 67. NİHAİ HEDEF

Roadmap'in sonunda hedef:

> **"Her şeyi bilen embedded mühendisi" olmak değil.**

Hedef:

> **Bir embedded/robotics sisteminde bana verilen problemi anlayıp, eksik olduğum noktaları dokümantasyondan öğrenerek, kodlayıp, hardware/software tarafında debug edip, test edip çalışır hale getirebilmek.**

Problem:

```text
Problem
 ↓
Understand
 ↓
Research
 ↓
Design
 ↓
Implement
 ↓
Debug
 ↓
Test
 ↓
Document
 ↓
Solve
```

Bu döngüyü bağımsız şekilde çalıştırabilmek.

---

# 68. SON SIRA

Roadmap'in gerçek sırası artık:

```text
                    ┌───────────────┐
                    │ C             │
                    └───────┬───────┘
                            ↓
                    ┌───────────────┐
                    │ Low-Level C   │
                    │ Memory        │
                    │ Debugging     │
                    └───────┬───────┘
                            ↓
                    ┌───────────────┐
                    │ MCU + ARM     │
                    └───────┬───────┘
                            ↓
                    ┌───────────────┐
                    │ Peripherals   │
                    │ GPIO          │
                    │ Timer         │
                    │ ADC/PWM       │
                    │ UART          │
                    │ SPI/I2C       │
                    └───────┬───────┘
                            ↓
                    ┌───────────────┐
                    │ RTOS          │
                    │ FreeRTOS      │
                    └───────┬───────┘
                            ↓
                 ┌──────────┴──────────┐
                 ↓                     ↓
          Hardware / Firmware      Systems
                 │                     │
          Bring-up / Driver       Linux / OS
          Schematic / Debug       Networking
          Testing / Python        Ethernet
                 │                     │
                 └──────────┬──────────┘
                            ↓
                    ┌───────────────┐
                    │ C++           │
                    │ CMake         │
                    └───────┬───────┘
                            ↓
                    ┌───────────────┐
                    │ ROS2          │
                    └───────┬───────┘
                            ↓
                    ┌───────────────┐
                    │ Robotics      │
                    │ Gazebo        │
                    │ Sensors       │
                    │ TF2           │
                    │ Odometry      │
                    │ EKF           │
                    │ SLAM          │
                    │ Nav2          │
                    └───────┬───────┘
                            ↓
                    ┌───────────────┐
                    │ Final Robot   │
                    └───────┬───────┘
                            ↓
                         GitHub
                            ↓
                    Job Applications
                            │
             ┌──────────────┴──────────────┐
             ↓                             ↓
        Robotics Jobs                Embedded Jobs
             │                             │
             └──────────────┬──────────────┘
                            ↓
                   SECTOR SPECIFIC
                            │
             CAN / BMS / FPGA / USB / etc.
```

# Başlangıç

**İlk durak hâlâ C.**

Ama artık neden C öğrendiğimiz çok daha net:

```text
C
 ↓
Low-level düşünce
 ↓
MCU
 ↓
Hardware
 ↓
RTOS
 ↓
Firmware
 ↓
C++
 ↓
Robotics
```

**Sektör-spesifik şeyler şimdilik kafadan çıkıyor.** CAN, BMS, FPGA, USB, DO-178C vs. bir ilan gerçekten gerektirdiğinde açılacak kutular.

Şu anda işimiz:

> **C → Embedded Core → Common Embedded Skills → C++ → Robotics.**




<!--
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

| Alan       | Ana kaynak                                               | Yardımcı kaynak | 
| ---------- | -------------------------------------------------------- | ----------------|
| C          | **Fehmi Uyar — C Programlama ve Algoritma Mantığı**      | Modern Embedded Systems Programming Course |
| C++        | **Fehmi Uyar — C++ Eğitim Seti**                         | Kemal Bıçakçı - Veri iletişimi ve Bilgisayar Ağları dersleri |
| OS         | **OSTEP — Operating Systems: Three Easy Pieces**         | Kemal Bıçakçı - İşletim Sistemleri dersleri |
| Networking | **Computer Networking: A Top-Down Approach**             | |
| ROS2       | **Taha Eren Karakış — Sıfırdan ROS2**                    | |
| Embedded   | **ESP-IDF resmi dokümantasyonu + proje yaparak öğrenme** | |
| Linux      | **Kullanarak + man pages**                               | |
| Gazebo     | **ROS2/Gazebo dokümantasyonu + proje**                   | |

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
-->
