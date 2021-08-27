#include "framebuffer.h"
#include "serial.h"
#include "memory_segments.h"
#include "keyboard.h"
#include "interrupts.h"
#include "multiboot.h"

    
int kmain(multiboot_info_t *mbinfo)
{

       //Intialize gdt
       segments_install_gdt();
      //Initialize idt
       interrupts_install_idt();
    
    /*    
    serial_write(msg, sizeof(msg));
    fb_write(msg, sizeof(msg));
    
    scancode = keyboard_read_scan_code();
    ascii = keyboard_scan_code_to_ascii(scancode);
    asciicode[0] = ascii;
    serial_write(asciicode, sizeof(asciicode));
    fb_write(asciicode, sizeof(asciicode));*/


     // Test appel module 
        module_t* modules = (module_t*) mbinfo->mods_addr;       
	unsigned int address_of_module = modules->mod_start;     
	
	if((mbinfo -> mods_count)==1){
	
	typedef void (*call_module_t)(void);
	call_module_t start_program = (call_module_t) address_of_module;
    	start_program();
    	}else
    		return 0;

   
   return 0; 
}


