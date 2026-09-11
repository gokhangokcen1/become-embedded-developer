# ROBOTICS / EMBEDDED ROADMAP

<mark> C →  </mark>LOW LEVEL C / MEMORY MANAGEMENT DEBUGGING → EMBEDDED / MCU / ARM →  RTOS/FREETOS + OS → C++ + CMAKE + LINUX + GIT → ROS2

# 0. ROADMAP'İN ANA MANTIĞI

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

|Alan|Ana kaynak|Yardımcı kaynak|
|---|---|---|
|C|[**Fehmi Uyar — C Programlama ve Algoritma Mantığı**](https://www.youtube.com/playlist?list=PLY20HpFruiK1cFSUqhP_XJSc_T0LWRh6t)|[C Programming and Memory Management ](https://www.youtube.com/watch?v=rJrd2QMVbGM&t=1s) |
|Low-Level C|**Columbia — Low-Level C Programming** referans dokümanı| |
|C++|[**Fehmi Uyar — C++ Eğitim Seti**](https://www.youtube.com/playlist?list=PLY20HpFruiK17RArt5Guq8fF4GQgssQ0m)| |
|OS|[**Kemal Bıçakçı - İşletim Sistemleri (OSTEP)**](https://www.youtube.com/playlist?list=PLmPsb7nQhv7NLRWdIiDVNBDCMOtuUn6WZ)| |
|Networking|[**Kemal Bıçakçı - Veri İletişimi ve Bilgisayar Ağları (CN:ATDA)**](https://www.youtube.com/playlist?list=PLmPsb7nQhv7OLsCOLgVaIiKgRX_SHEcoy)| |
|Embedded|[**Modern Embedded Systems Programming Course - Quantum Leaps**](https://www.youtube.com/playlist?list=PLPW8O6W-1chwyTzI3BHwBLbGQoPFxPAPM) |**ESP-IDF resmi dokümantasyonu + wokwi STM32** |
|Linux|**Kullanarak + man pages**| |
|ROS2 - Gazebo|[**ROS2 Tutorials (Basic to Advanced Simulation) - Kevin Wood**](https://www.youtube.com/playlist?list=PLSK7NtBWwmpTS_YVfjeN3ZzIxItI1P_Sr)| |
