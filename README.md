| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C5 | ESP32-C6 | ESP32-H2 | ESP32-P4 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- |

# _SW-420_
![Modulo SW-420 usado](https://docs.sunfounder.com/projects/umsk/es/latest/_images/24_sw420_vibration_module.png)

## How to use example
This example use GPIO 10 connected to DO terminal and GPIO 2 as the internal led on the esp32-c3-wroom-v2 the code configure a interruption DO_GPIO pin when the interruption happen an internal count goes up and the led turn on/off folowing the DO pin level.
The sensitivity can be turn on the module itself.

## Example folder contents

The project **SW-420** contains one source file in C language [main.c](main/main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both). 

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
└── README.md                  This is the file you are currently reading
```
Additionally, the sample project contains Makefile and component.mk files, used for the legacy Make based build system. 
They are not used or needed when building with CMake and idf.py.
