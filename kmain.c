#include "framebuffer.h"
#include "serial.h"


    
void kmain(){

    char msg[] = "Initial_OS";
   
    
    serial_write(0x3F8, msg, 10);
    fb_write(msg, 10);
    
}
