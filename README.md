# EmbeddedSystems-Cache-I-O
Cache basics along with virtual/physical memory basics.
Embedded Systems ECE1175 Lab 3

Please write C/C++ code to multiple two N by N matrices. Please follow the (element data type, matrix size) specified in the table below to

Test your program with randomly generated matrices and analyze the cache misses using perf. Record the runtime (s) and L1 data cache miss rate (%) of your program for each test. Fill the table with your measurements.
Is the cache miss rate of your implementation < 0.1%? If not, can you meet this constraint by optimizing your code? (Hint: try swapping the order of your loops)

Please write C/C++ code to directly manipulate GPIO registers from Raspberry Pi OS (Raspbian). 

For security reasons, the operating system itself does not provide direct access to the physical memory and users are basically doing all their work on the virtual memory. You need to use mmap() and the device file dev/mem to create a mapping from virtual memory (user space) to physical memory (GPIO registers), such that you will be able to manipulate GPIO registers through your program.

To debug and demonstrate your code, you can use GPIO 42 to control the onboard green LED to show a blinking pattern (to setup the LED, refer to lab lecture slides). Alternatively, if you have an external LED, or you have a multimeter or oscilloscope, you could use that to indicate your GPIO output.

You can first use existing libraries such as RPi.GPIO for debugging, then need to find a way to manipulate GPIO directly through the registers.
