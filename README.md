<!-- omit from toc -->
# Firmware for the steering wheel of Apex Corse

This document explains in details what this codebase is for, how to navigate it and how it works. It contains the source code for the display positioned on the steering wheel of our car.

- [The hardware](#the-hardware)
- [The software](#the-software)
  - [The TouchGFX app](#the-touchgfx-app)
    - [How it works](#how-it-works)
    - [The setup](#the-setup)
    - [MVC pattern](#mvc-pattern)
    - [Best practices](#best-practices)
  - [CAN handling](#can-handling)
  - [The `main` function](#the-main-function)
  - [Building and running](#building-and-running)

## The hardware

It consists in a [STM32F469I-DISCO](https://www.st.com/en/evaluation-tools/32f469idiscovery.html) with an incorporated display. It is connected via CAN peripherals to the network inside the car, allowing it to listen for values emitted by the sensors all around the car.

The parts we care about are:

<!-- TODO: Improve this part -->
- The digital pins, which we'll use for user input via external buttons.
- The CAN ports.

## The software

The code consists in:

-   A [TouchGFX](https://support.touchgfx.com/docs/introduction/welcome) app, responsible for the UI and user interaction. The code for it is inside `steering/TouchGFX`.
-   A class (`CanHandler`) that manages the CAN connection.
-   The `main` function defined [here](./steering/Core/Src/main.c).

### The TouchGFX app

#### How it works

#### The setup

#### MVC pattern

#### Best practices

### CAN handling

### The `main` function

### Building and running
