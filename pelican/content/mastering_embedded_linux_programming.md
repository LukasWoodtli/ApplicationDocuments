Title: Mastering Embedded Linux Programming
Category: Programming
Tags: Embedded Systems, OS, Linux, Unix
Date: 2018-01-20



Notes to the book [Mastering Embedded Linux Programming](https://www.packtpub.com/networking-and-servers/mastering-embedded-linux-programming)


My code examples can be found here: [GitHub](https://github.com/LukasWoodtli/MasteringEmbeddedLinuxProgramming)


*"The versions of the main packages [...] are U-Boot 2015.07, Linux 4.1, Yocto Project 1.8 "Fido", and Buildroot 2015.08"*


[TOC]

# Chapter 1. Starting Out

*"At the heart of most embedded devices is a highly integrated chip that contains one or more processor cores and interfaces with main memory, mass storage, and peripherals of many types. This is referred to as a System on Chip, or SoC"*

## Selecting the right operating system

*"Some things to consider*

- *Is your hardware up to the job? Compared to a traditional RTOS [...], Linux requires a lot more resources. It needs at least a 32-bit processor, and lots more memory.*
- *Do you have the right skill set? [...] detailed knowledge of Linux and how it relates to your hardware.*
- *Is your system real-time? Linux can handle many real-time activities so long as you pay attention to certain details"*

## Project lifecycle

*"Four sections that reflect the phases of a project. The phases are not necessarily sequential."*

- *"set up the development environment and create a working platform for the later phases. "board bring-up" phase."*
- *"System architecture and design choices [...] storage of programs and data, how to divide work between kernel device drivers and applications, and how to initialize the system."*
- *"Writing embedded applications [...] Linux process and threads model and how to manage memory in a resource-constrained device."*
- *"Debugging and optimizing performance [...] trace, profile, and debug your code in both the applications and the kernel."*


*"Debugging and optimizing performance (chapters 12 and 13) describe how to trace, profile, and debug your code in both the applications and the kernel."*

## The four elements of embedded Linux

- *"Toolchain: This consists of the compiler and other tools needed to create code for your target device. Everything else depends on the toolchain."*
- *"Bootloader: This is necessary to initialize the board and to load and boot the Linux kernel."*
- *"Kernel: This is the heart of the system, managing system resources and interfacing with hardware."*
- *"Root filesystem: This contains the libraries and programs"*

## Hardware for embedded Linux

*"[In] source code for Linux 4.1, there are 30 architectures, each represented by a sub-directory in the `arch/` directory. They are all 32- or 64-bit architectures, most with a **memory management unit (MMU)**, but some without."*

*"There is another group that doesn't have an MMU that runs a subset of Linux known as micro controller Linux or uClinux."*

*"[Linux needs] a reasonable amount of RAM. 16 MiB is a good minimum"*

*"[We need] non-volatile storage, usually flash memory. 8 MiB is enough for a simple device"*

*"Linux has extensive support for flash storage devices, including raw NOR and NAND flash chips and managed flash in the form of SD cards, eMMC chips, USB flash memory"*

*"A debug port is very useful, most commonly an RS-232 serial port. It does not have to be fitted on production boards, but makes board bring-up, debugging, and development much easier."*

*"[We] need some means of loading software when starting from scratch. [For example JTAG] but modern SoCs have the ability to load boot code directly from removable media, especially SD and micro SD cards, or serial interfaces such as RS-232 or USB."*


# Chapter 2. Learning About Toolchains

## What is a toolchain?

*"A standard GNU toolchain consists of three main components:"*

- [Binutils](http://www.gnu.org/software/binutils/): Assembler, linker, (ld) and other tools
- [GCC](http://gcc.gnu.org/): Compilers for C, C++, Objective-C, Objective-C++, Java, Fortran, Ada, and Go. They all use a common back-end which produces assembler code for the GNU assembler (GAS)
- **C library**: Standardized API based on POSIX (interface to the operating system kernel from applications)

*"As well as these, you will need a copy of the Linux kernel headers,"*

*"of the header files in the include directory of your kernel source code. Those headers are intended for use in the kernel only and contain definitions that will cause conflicts if used in their raw state to compile regular Linux applications. Instead, you will need to generate a set of sanitized kernel headers"*


## Types of toolchain - native versus cross toolchain

*"here are two types of toolchain:*

- *Native: This toolchain runs on the same type of system [...] This is the usual case for desktops and servers, and it is becoming popular on certain classes of embedded devices. [...]*
- *Cross: This toolchain runs on a different type of system than the target, allowing the development to be done on a fast desktop PC and then loaded onto the embedded target for testing."*

*"Almost all embedded Linux development is done using a cross development toolchain, partly because most embedded devices are not well suited to program development since they lack computing power, memory, and storage, but also because it keeps the host and target environments separate."*

*"there is a counter argument in favor of native development. Cross development creates the burden of cross-compiling all the libraries and tools that you need for your target."*


## CPU architectures

*"toolchain has to be built according to the capabilities of the target CPU:*

- *CPU architecture: arm, mips, x86_64, and so on*
- *Big- or little-endian operation: Some CPUs can operate in both modes, but the machine code is different for each*
- *Floating point support: Not all versions of embedded processors implement a hardware floating point unit, in which case, the toolchain can be configured to call a software floating point library instead*
- *Application Binary Interface (ABI): The calling convention used for passing parameters between function calls"*


### ARM OABI, EABI and EABIHF

*"With many architectures, the ABI is constant across the family of processors. One notable exception is ARM. The ARM architecture transitioned to the *Extended Application Binary Interface* (**EABI**) in the late 2000's, resulting in the previous ABI being named the *Old Application Binary Interface* (**OABI**). While the OABI is now obsolete, you continue to see references to EABI. Since then, the *EABI has split into two*, based on the way that floating point parameters are passed. The *original EABI uses general purpose (integer)* registers* while the *newer **EABIHF** uses floating point registers. The EABIHF is significantly faster at floating point operations since it removes the need for copying between integer and floating point registers, but it is not compatible with CPUs that do not have a floating point unit. The choice, then, is between two incompatible ABIs: *you cannot mix and match the two* and so you have to decide at this stage."*


### GNU prefix tuple

*"GNU uses a prefix to the tools to identify the various combinations that can be generated, consisting of a tuple of three or four components separated by dashes:*

- *CPU: The CPU architecture, such as arm, mips, or x86_64. If the CPU has both endian modes, they may be differentiated by adding **el for little-endian**, or **eb for big-endian**. Good examples are little-endian MIPS, mipsel and big-endian ARM, armeb.*
- *Vendor: This identifies the provider of the toolchain. Examples include buildroot, poky, or just unknown. Sometimes it is left out altogether.*
- *Kernel: For our purposes, it is always 'linux'.*
- *Operating system: A name for the user space component, which might be `gnu` or `uclibcgnu`. The ABI may be appended here as well so, for ARM toolchains, you may see `gnueabi`, `gnueabihf`, `uclibcgnueabi`, or `uclibcgnueabihf`."*

*"You can find the tuple used when building the toolchain by using the `-dumpmachine` option of `gcc`"*
