#include "io.h"
#include "framebuffer.h"
#include "serial.h"
#include "memory_segments.h"
#include "keyboard.h"
#include "interrupts.h"
#include "multiboot.h"
#include "paging.h"




    
void kmain(multiboot_info_t *mbinfo){


    module_t* modules = (module_t*) mbinfo->mods_addr;       
    unsigned int address_of_module = modules->mod_start; 

    typedef void (*call_module_t)(void);
    call_module_t start_program = (call_module_t) address_of_module;
    start_program();
   
    segments_install_gdt();
    interrupts_install_idt();
    init_paging();
    
}
