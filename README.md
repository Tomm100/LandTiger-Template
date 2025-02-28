# LandTiger ARM Cortex-M3 Peripheral Template
This repository offers a ready-to-use template for efficiently working with the peripherals of the LandTiger development board, powered by the ARM Cortex-M3 (LPC1768). It features modular drivers, practical examples, and a well-structured organization for embedded projects.

## Academic Context
This repository is intended to support coursework and projects for the following courses at Politecnico di Torino:

  - Architetture dei Sistemi di Elaborazione (course code: 02GOLOV)
  - Computer Architecture (English version of the same course)

The template offers practical tools to streamline development with the LandTiger board, allowing students to focus on mastering key concepts in embedded systems.

## LandTiger NXP LPC1768
The code is designed for the **LandTiger NXP LPC1768** used at Politecnico.
Key details about the chip:
  - ARM 32-bit Cortex-M3 microcontroller with MPU, CPU clock up to 100MHz
  - 512kB on-chip Flash ROM
  - 64kB RAM with a Nested Vectored Interrupt Controller
  - 4x 32-bit Timers and a Repetitive Interrupt Controller
  - Power Management Unit and Wakeup Interrupt Controller
  - The project is developed using the Keil uVision IDE

## Project Structure

```
├── .gitignore                # File to exclude items from versioning
├── sample.*                  # Project files for Keil uVision
├── utilities.c/.h            # Utility functions
│
├── RTE/                      # Run-Time Environment configurations
│   ├── RTE_Components.h      # Configuration file for different profiles
│
├── Source/                   # Main source code
│   ├── sample.c              # Main file
│   ├── startup_LPC17xx.s     # Startup file for LPC1768
│   ├── system_LPC17xx.c      # System configuration
│   │
│   ├── button_EXINT/         # Button management with interrupts
│   │   ├── button.h          # Header file
│   │   ├── IRQ_button.c      # Interrupt handler
│   │   ├── lib_button.c      # Button library
│   │
│   ├── CMSIS_core/           # CMSIS files for ARM Cortex-M3
│   │   ├── *.h               # Core header files
│   │
│   ├── GLCD/                 # Graphic display management
│   │   ├── AsciiLib.c/.h     # ASCII character library
│   │   ├── GLCD.c/.h        # GLCD driver
│   │   ├── HzLib.c/.h        # Hz management library
│   │
│   ├── joystick/             # Joystick control
│   │   ├── funct_joystick.c  # Management functions
│   │   ├── joystick.h        # Header file
│   │   ├── lib_joystick.c    # Joystick library
│   │
│   ├── led/                  # LED management
│   │   ├── funct_led.c       # LED control functions
│   │   ├── led.h             # Header file
│   │   ├── lib_led.c         # LED library
│   │
│   ├── RIT/                  # RIT timer management
│   │   ├── IRQ_RIT.c         # Interrupt handler
│   │   ├── lib_RIT.c         # RIT library
│   │   ├── RIT.h             # Header file
│   │
│   ├── timer/                # Timer management
│   │   ├── IRQ_timer.c       # Timer interrupt handler
│   │   ├── lib_timer.c       # Timer library
│   │   ├── timer.h           # Header file
│   │
│   ├── TouchPanel/           # Touch panel management
│       ├── TouchPanel.c/.h   # Touch panel driver
```
