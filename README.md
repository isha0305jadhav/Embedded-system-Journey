# Embedded System Journey

A hands-on learning repository for mastering embedded systems through C programming — covering microcontrollers, memory protocols, hardware interfaces, and real-world firmware development, assisted by AI.

---

## Goals

- Write and improve C code for embedded targets
- Understand microcontroller architecture and peripherals
- Learn and implement memory and communication protocols
- Build progressively advanced embedded projects
- Use AI to accelerate learning and code review

---

## Topics Covered

### C Programming for Embedded Systems
- Bare-metal C: pointers, bit manipulation, memory layout
- Volatile, const, static — why they matter in embedded
- Interrupt service routines (ISRs) and concurrency basics
- Linked lists, ring buffers, and other embedded-friendly data structures

### Microcontrollers
- GPIO, timers, PWM, ADC
- ARM Cortex-M architecture (STM32, RP2040, etc.)
- AVR (Arduino/ATmega)
- Bootloaders and startup code

### Memory & Storage
- Flash, SRAM, EEPROM — differences and use cases
- Memory-mapped I/O
- DMA (Direct Memory Access)
- External storage: SD cards, NOR/NAND Flash

### Communication Protocols
- UART / USART
- SPI (Serial Peripheral Interface)
- I2C (Inter-Integrated Circuit)
- CAN Bus
- USB (HID, CDC)

### RTOS & Concurrency
- FreeRTOS basics: tasks, queues, semaphores
- Scheduling and priority
- Low-power design

---

## Repository Structure

```
embedded-system-journey/
├── c-fundamentals/       # Core C concepts for embedded
├── microcontrollers/     # MCU-specific code and projects
│   ├── stm32/
│   ├── avr/
│   └── rp2040/
├── protocols/            # Protocol implementations
│   ├── uart/
│   ├── spi/
│   ├── i2c/
│   └── can/
├── memory/               # Memory management experiments
├── rtos/                 # FreeRTOS projects
└── projects/             # End-to-end embedded projects
```

---

## Tools & Environment

| Tool | Purpose |
|------|---------|
| GCC ARM Toolchain | Cross-compilation |
| OpenOCD / J-Link | Flashing and debugging |
| VS Code + Cortex-Debug | IDE + debug extension |
| STM32CubeMX | Peripheral configuration |
| Logic Analyzer | Protocol debugging |
| AI (Claude) | Code review, concept explanation, debugging |

---

## Progress Tracker

- [ ] C pointers and bit manipulation exercises
- [ ] GPIO blink on STM32
- [ ] UART communication
- [ ] SPI with external sensor
- [ ] I2C with OLED display
- [ ] DMA transfer example
- [ ] FreeRTOS task scheduling
- [ ] CAN Bus communication
- [ ] Complete embedded project

---

## Learning Philosophy

This repo follows a learn-by-doing approach — every concept is implemented in code, tested on hardware (or simulated), and reviewed with AI assistance to catch mistakes and deepen understanding.

---

*Journey started: 2025 | Language: C | Focus: Embedded Systems*
