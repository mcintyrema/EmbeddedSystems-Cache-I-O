#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
using namespace std;

#define GPIO_BASE_ADDRESS       0xfe200000
#define GPIO_GPFSEL     0x00000010
#define GPIO_GPSET      0x00000020
#define GPIO_GPCLR      0x0000002c

static uint8_t pin = 42;

int main(){
    
    int fd = open("/dev/mem", O_RDWR);
    void *GPIO_BASE = mmap(0, sysconf(_SC_PAGESIZE), PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO_BASE_ADDRESS);
    close(fd);

    if(GPIO_BASE == MAP_FAILED){
        cout << "Failed to call mmap." << endl;
        exit(EXIT_FAILURE);
    }else{
        cout << "mmap called, GPIO_BASE = " << GPIO_BASE << endl;
    }

    uint32_t *GPIO_SEL = (uint32_t*)(GPIO_BASE + GPIO_GPFSEL);
    uint32_t *GPIO_SET = (uint32_t*)(GPIO_BASE + GPIO_GPSET);
    uint32_t *GPIO_CLR = (uint32_t*)(GPIO_BASE + GPIO_GPCLR);

    *GPIO_SEL &= ~(7<<(pin%10*3));
    *GPIO_SEL |= (1<<(pin%10*3));
    
    int i = 10;
    while(i-- > 0){
        *GPIO_SET = (uint32_t)(1<<(pin%32));
        sleep(1);
        *GPIO_CLR = (uint32_t)(1<<(pin%32));
        sleep(1);
    }

    if(munmap(GPIO_BASE, sysconf(_SC_PAGESIZE))==-1){
        cout << "Failed to call mmap." << endl;
        exit(EXIT_FAILURE);
    }else{
        cout << "Succeeded to call mmap" << endl;
    }

    exit(EXIT_SUCCESS);
}
