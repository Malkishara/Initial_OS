#include "io.h"
#include "framebuffer.h"
#include "serial.h"
#include "memory_segments.h"
#include "keyboard.h"
#include "interrupts.h"
#include "multiboot.h"
#include "paging.h"
#include "hardware_interrupt_enabler.h"




void init(u32int kernelPhysicalEnd) {

  init_gdt();

  serial_configure(SERIAL_COM1_BASE, Baud_115200);
  init_paging(kernelPhysicalEnd);
  interrupts_install_idt();

}


int kmain(u32int kernelPhysicalEnd){


  	init(kernelPhysicalEnd);
  	disable_hardware_interrupts();
  	switch_to_user_mode();


  	return 0;
}
