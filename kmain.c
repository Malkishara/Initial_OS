#include "framebuffer.h"
#include "serial.h"
#include "memory_segments.h"


    
void kmain(){

    char msg[] = "Initial_OS";
   
    
    serial_write(0x3F8, msg, 10);
    fb_write(msg, 10);
    segments_install_gdt();
    
    
}
