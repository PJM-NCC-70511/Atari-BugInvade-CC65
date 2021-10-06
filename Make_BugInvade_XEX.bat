set cc65=..\bin\cc65
set PATH=..\bin;..\;..\include;..\asminc;..\lib
rem  Compile and assemble main program

cc65 -t atari -o BUG_INVADE_C.ASM BUG_INVADE.C
ca65 -t atari -o BUG_INVADE_C.O BUG_INVADE_C.ASM -l bug_invade_clisting_c.txt

rem  Assemble native routines in assembler
ca65 -t atari -o Bug_Invade_data.o Bug_Invade_data.asm -l Bug_Invade_data.txt

rem  Link binary file
ld65 -C linker_xex.cfg -o  BUG_INVADE.XEX BUG_INVADE.O Bug_Invade_data.o atari.lib 

