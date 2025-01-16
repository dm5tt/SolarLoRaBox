![SolarLoraBox PCB](doc/pcb_v002jpg.jpg)

# What is this thing?

This is an experimental platform for an solar driven LoRa sensor station based on the

- Microcontroller: ST STM32U083CCT6
- Radio: Heltec HT-RA62 (Semtech SX1262)
- Charging Controller: TI BQ25185
- Flash: Windbond W25Q128JVS (128MBit)
- Reset IC: APX803L05-32SA-7 (3.2V)
- LDO: HEERMICR HE9073A30MR (3.0V)

# Features

 - Solar Input up to 18V (24V survival)
 - 3A maximum load
 - 1A maximum charge current
 - Pseudo-MPPT (VINDPM)
 - Power Path (= if the battery is fully charged and there's enough solar power the device is getting powered directly from solar. It also can mix battery and solar energy.)
 - Two ADC signals for getting VLOAD and  VBUS voltage using voltage dividers
 - 3.7V LiPo either via 18650 block or JST-PH 2.0 connector

Lots if this stuff was already proven and validated in the project [SolarMeshtasticNode](https://github.com/dm5tt/SolarMeshtasticNode).

# Interfaces

- 4x I2C

- 1x UART

- 1x USB

# Programming interfaces

The STM32U0 spits out its bootloader on the I2C, UART and USB.

For "comfort programming" it has a TC2030 where you can connect a Segger or ST-Link

# Hardware verification (v0.0.1)

### SWD interface: ✅

```
 - Connecting via USB to probe/ programmer device 0
 - Probe/ Programmer firmware: x
 - Probe/ Programmer S/N: x
 - Device "STM32U083CC" selected.
 - Target interface speed: 4000 kHz (Fixed)
 - VTarget = 3.324V
 - InitTarget() start
 - InitTarget() end - Took 33.1ms
 - Found SW-DP with ID 0x6BA02477
 - DPIDR: 0x6BA02477
 - CoreSight SoC-400 or earlier
 - Scanning AP map to find all available APs
 - AP[2]: Stopped AP scan as end of AP map has been reached
 - AP[0]: AHB-AP (IDR: 0x84770001, ADDR: 0x00000000)
 - AP[1]: APB-AP (IDR: 0x54770002, ADDR: 0x01000000)
 - Iterating through AP map to find AHB-AP to use
 - AP[0]: Core found
 - AP[0]: AHB-AP ROM base: 0xF0000000
 - CPUID register: 0x410CC601. Implementer code: 0x41 (ARM)
 - Found Cortex-M0 r0p1, Little endian.
 - FPUnit: 4 code (BP) slots and 0 literal slots
 - CoreSight components:
 - ROMTbl[0] @ F0000000
 - [0][0]: E00FF000 CID B105100D PID 000BB4C0 ROM Table
 - ROMTbl[1] @ E00FF000
 - [1][0]: E000E000 CID B105E00D PID 000BB008 SCS
 - [1][1]: E0001000 CID B105E00D PID 000BB00A DWT
 - [1][2]: E0002000 CID B105E00D PID 000BB00B FPB
 - Executing init sequence ...
  - Initialized successfully
 - Target interface speed: 4000 kHz (Fixed)
 - Found 1 JTAG device. Core ID: 0x6BA02477 (None)
 - Connected successfully
```

### Bootloader mode (USB): ✅

Switch set to "0"

```
Found DFU: [0483:df11] ver=0220, devnum=13, cfg=1, intf=0, path="3-3.3", alt=3, name="@ENGI Bytes        /0x1FFF6C00/01*1024.e", serial="x"
Found DFU: [0483:df11] ver=0220, devnum=13, cfg=1, intf=0, path="3-3.3", alt=2, name="@OTP Memory        /0x1FFF6800/01*1024 e", serial="x"
Found DFU: [0483:df11] ver=0220, devnum=13, cfg=1, intf=0, path="3-3.3", alt=1, name="@OB Bytes          /0x40022020/01*136 e", serial="x"
Found DFU: [0483:df11] ver=0220, devnum=13, cfg=1, intf=0, path="3-3.3", alt=0, name="@Internal Flash    /0x08000000/128*02Kg", serial="x"
```

### UART: 

Todo

### SPI, Flash: 

Todo

### SPI, LoRa: 

Todo

