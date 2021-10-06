; BINARY DATA FOR BUG INVADE GAME

  .IF .DEFINED(__ATARI__)
  
  .ELSEIF .DEFINED(__ATARI2600__)
  
  .ELSEIF .DEFINED(__ATARI5200__)
  
  .ELSEIF .DEFINED(__ATARI7800__)
  
  .ELSEIF .DEFINED(__LYNX__)
  
  .ELSEIF .DEFINED(__VIC20__) 
  
  .ELSEIF .DEFINED(__C16__)
  
  .ELSEIF .DEFINED(__C64__)
  
  .ELSEIF .DEFINED(__C128__)
  
  .ELSEIF .DEFINED(__APPLE2__)
  
  .ELSEIF .DEFINED(__NES__)
  
  .ENDIF

  .segment "DATA0"
      .include "..\asminc\Atari 8-bit Equates.asm"
      .include "..\asminc\zeropage.inc"      
  
_CHARSET_GAME:
_CHARSET_TITLE:   
_TITLE_DATA:

  .incbin         "BUGINVDE.FNT"

_PMBANK                                  =$9000                                        
_VARBANK                                 =$9800                                                                                                                                       

_SCREEN_ADDR                             =$9A00                                         
_GAME_SCREEN_ADDR                        =$9A50                                        

_RTCLOCK                                 =$12
_PMBANK_HI                               = >_PMBANK      
_CHARSET_GAME_HI                         = >_CHARSET_GAME
_CHARSET_TITLE_HI                        = >_CHARSET_TITLE
      
      .export _CHARSET_GAME
      .export _CHARSET_TITLE
      .export _CHARSET_GAME_HI 
      .export _CHARSET_TITLE_HI
      .export _TITLE_DATA

      .export _PMBANK     
      .export _VARBANK                                        
      .export _SCREEN_ADDR                                         
      .export _GAME_SCREEN_ADDR
      .export _PMBANK_HI



M0		        	          	            =$C0
M1		        	          	            =$C1
M2		        	          	            =$C2
M3		        	          	            =$C3
M4		        	          	            =$C4
M5		        	          	            =$C5
M6		        	          	            =$C6
M7		        	          	            =$C7
M8		        	          	            =$C8
M9		        	          	            =$C9
NDX0									                  =$CA
NDX1									                  =$CB
NDX2									                  =$CC
NDX3									                  =$CD



_shooter_px                             =$A0
_shooter_py                             =$A1
_BULLET_SCREEN_LOC                      =$A2
                        
PMSAVELO = _PMBANK + $02E0
PMSAVEHI = _PMBANK + $02E8
PMSAVESZ = _PMBANK + $02F0
PMNUMBER = M9
FROMLO = NDX0
FROMHI = NDX1
PMYPOS = NDX2   
PAGEBASE = NDX0
PAGEBSHI = NDX1
                    

SPRITENUM	                                        =_PMBANK+$0180
SETSP0COLOR                                       =_PMBANK+$0190
SETSP1COLOR                                       =_PMBANK+$01A0
SETSPWIDTH                                        =_PMBANK+$01B0
SPRITENHOZ                                        =_PMBANK+$01C0
SPRITENVRT                                        =_PMBANK+$01E0
SPHOZNEXT                                         =_PMBANK+$01F0

SPRHZ0	                            	            =_PMBANK+$0200 
SPRHZ1	                            	            =_PMBANK+$0210 
SPRHZ2	                            	            =_PMBANK+$0220 
SPRHZ3	                            	            =_PMBANK+$0230 
SPZONT                                            =_PMBANK+$0240
SPZONB                                            =_PMBANK+$0250
SPSRC0                                            =_PMBANK+$0260 
SPSRC1                                            =_PMBANK+$0278
SPSRC2                                            =_PMBANK+$0290
SPSRC3                                            =_PMBANK+$02A8
SPSRC4                                            =_PMBANK+$02C0
SPRITEUSE                                         =_PMBANK+$02D8
                                            
MIBANK                                            =_PMBANK+$0300
PMBNK0                                            =_PMBANK+$0400
PMBNK1                             	              =_PMBANK+$0500
PMBNK2                                            =_PMBANK+$0600
PMBNK3                             	              =_PMBANK+$0700
            

_prior_x                                          =_VARBANK + $010
_prior_y                                          =_VARBANK + $011
_shooter_status                                   =_VARBANK + $012
_stick_read                                       =_VARBANK + $013
_BULLET_STATUS                                    =_VARBANK + $01C
_BULLET_SPEED                                     =_VARBANK + $01D
_BULLET_SCREEN_SUB                                =_VARBANK + $01E
_BULLET_X_POS                                     =_VARBANK + $021
_BULLET_Y_POS                                     =_VARBANK + $022
_BULLET_HIT1                                      =_VARBANK + $023
_BULLET_L1                                        =_VARBANK + $024
_BULLET_L2                                        =_VARBANK + $026
_BULLET_L3                                        =_VARBANK + $028
_BULLET_L4                                        =_VARBANK + $02A
_BULLET_L5                                        =_VARBANK + $02C
_BULLET_L6                                        =_VARBANK + $02E

_BUG_TYPE                                         =_VARBANK + $030
_BUG_XPOS                                         =_VARBANK + $036
_BUG_YPOS                                         =_VARBANK + $03C
_BUG_XDIR                                         =_VARBANK + $042
_BUG_YDIR                                         =_VARBANK + $048
_BUG_STATUS                                       =_VARBANK + $04E
_BUG_DATA1                                        =_VARBANK + $054
_BUG_DATA2                                        =_VARBANK + $05A
; 
SOUND_COMMANDER_VARIABLE_AREA                     =_VARBANK + $060;
      .export M0									  
      .export M1									  
      .export M2								  
      .export M3									  
      .export M4									  
      .export M5								  
      .export M6									  
      .export M7									  
      .export M8									  
      .export M9									  
      
      .export NDX0									  
      .export NDX1									  
      .export NDX2									  
      .export NDX3									  
      .export SPRITENUM	            
      .export SETSP0COLOR           
      .export SETSP1COLOR           
      .export SETSPWIDTH            
      .export SPRITENHOZ            
      .export SPRITENVRT            
      .export SPHOZNEXT             
      .export SPRHZ0	              
      .export SPRHZ1	              
      .export SPRHZ2	              
      .export SPRHZ3	              
      .export SPZONT                
      .export SPZONB                
      .export SPSRC0                
      .export SPSRC1                
      .export SPSRC2                
      .export SPSRC3                
      .export SPSRC4                
      .export SPRITEUSE                                    
      .export MIBANK                
      .export PMBNK0                          
      .export PMBNK1                    
      .export PMBNK2                    
      .export PMBNK3                

      .export _shooter_px     
      .export _shooter_py     
      .export _shooter_status 
      .export _prior_x        
      .export _prior_y        
      .export _stick_read     

      .export _BULLET_STATUS
      .export _BULLET_X_POS 
      .export _BULLET_Y_POS 
      .export _BULLET_SCREEN_LOC
      .export _BULLET_HIT1
      .export _BULLET_L2;
      .export _BULLET_SPEED;
      .export _BULLET_SCREEN_SUB;
      .export _BUG_TYPE
      .export _BUG_XPOS  
      .export _BUG_YPOS  
      .export _BUG_XDIR  
      .export _BUG_YDIR        
      .export _BUG_STATUS
      .export _BUG_DATA1 
      .export _BUG_DATA2
      
_DISPLAY_LIST_TITLE:
     .byte $70,$F0,$44
     .byte <_SCREEN_ADDR
     .byte >_SCREEN_ADDR
     .byte $04,$05,$00,$04,$00,$04,$00,$04,$00,$04,$00,$04,$00,$04,$00
     .byte $04,$00,$04,$00,$04,$00,$04,$00,$04,$00,$04,$00,$04,$00,$04,$00
     .byte $04,$00,$04,$00,$04,$00,$04,$00,$04,$00,$04,$00,$04,$00,$04,$41
     .byte <_DISPLAY_LIST_TITLE 
     .byte >_DISPLAY_LIST_TITLE
    
_DISPLAY_LIST_GAME:
     .byte $70,$70,$C4
     .byte <_SCREEN_ADDR
     .byte >_SCREEN_ADDR
     .byte $10,$44
     .byte <_GAME_SCREEN_ADDR
     .byte >_GAME_SCREEN_ADDR
     .byte $04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$41
     .byte <_DISPLAY_LIST_GAME 
     .byte >_DISPLAY_LIST_GAME
      
      .export _DISPLAY_LIST_TITLE
      .export _DISPLAY_LIST_GAME




_SCREEN_ROW_LOW:
    .byte <(_GAME_SCREEN_ADDR +   0),<(_GAME_SCREEN_ADDR +   40), <(_GAME_SCREEN_ADDR +  80), <(_GAME_SCREEN_ADDR + 120), <(_GAME_SCREEN_ADDR + 160)
    .byte <(_GAME_SCREEN_ADDR + 200), <(_GAME_SCREEN_ADDR + 240), <(_GAME_SCREEN_ADDR + 280), <(_GAME_SCREEN_ADDR + 320), <(_GAME_SCREEN_ADDR + 360)  
  	.byte <(_GAME_SCREEN_ADDR + 400), <(_GAME_SCREEN_ADDR + 440), <(_GAME_SCREEN_ADDR + 480), <(_GAME_SCREEN_ADDR + 520), <(_GAME_SCREEN_ADDR + 560)
  	.byte <(_GAME_SCREEN_ADDR + 600), <(_GAME_SCREEN_ADDR + 640), <(_GAME_SCREEN_ADDR + 680), <(_GAME_SCREEN_ADDR + 720), <(_GAME_SCREEN_ADDR + 760)
    .byte <(_GAME_SCREEN_ADDR + 800), <(_GAME_SCREEN_ADDR + 840), <(_GAME_SCREEN_ADDR + 880), <(_GAME_SCREEN_ADDR + 920), <(_GAME_SCREEN_ADDR + 960)
    .byte <(_GAME_SCREEN_ADDR + 1000), <(_GAME_SCREEN_ADDR + 1040)
    
_SCREEN_ROW_HIGH:
	  .byte >(_GAME_SCREEN_ADDR +   0), >(_GAME_SCREEN_ADDR +  40), >(_GAME_SCREEN_ADDR +  80), >(_GAME_SCREEN_ADDR + 120), >(_GAME_SCREEN_ADDR + 160)
  	.byte >(_GAME_SCREEN_ADDR + 200), >(_GAME_SCREEN_ADDR + 240), >(_GAME_SCREEN_ADDR + 280), >(_GAME_SCREEN_ADDR + 320), >(_GAME_SCREEN_ADDR + 360)
  	.byte >(_GAME_SCREEN_ADDR + 400), >(_GAME_SCREEN_ADDR + 440), >(_GAME_SCREEN_ADDR + 480), >(_GAME_SCREEN_ADDR + 520), >(_GAME_SCREEN_ADDR + 560)
  	.byte >(_GAME_SCREEN_ADDR + 600), >(_GAME_SCREEN_ADDR + 640), >(_GAME_SCREEN_ADDR + 680), >(_GAME_SCREEN_ADDR + 720), >(_GAME_SCREEN_ADDR + 760)
  	.byte >(_GAME_SCREEN_ADDR + 800), >(_GAME_SCREEN_ADDR + 840), >(_GAME_SCREEN_ADDR + 880), >(_GAME_SCREEN_ADDR + 920), >(_GAME_SCREEN_ADDR + 960)
  	.byte >(_GAME_SCREEN_ADDR + 1000), >(_GAME_SCREEN_ADDR + 1040)  

      .export _SCREEN_ROW_LOW
      .export _SCREEN_ROW_HIGH

_P000: .BYTE  0, 24, 24, 24, 60, 126, 219, 153, 153, 219, 126, 60
_P001: .BYTE  129, 36, 0, 66, 36, 0, 0, 36, 66, 0, 36, 129
_P002: .BYTE  0, 0, 2, 4, 7, 14, 124, 254, 127, 93, 85, 0
_P003: .BYTE  0, 0, 4, 4, 7, 14, 124, 254, 127, 186, 170, 0
_P004: .BYTE  0, 0, 64, 32, 224, 112, 62, 127, 254, 93, 85, 0
_P005: .BYTE  0, 0, 32, 32, 224, 112, 62, 127, 254, 186, 170, 0
_P006: .BYTE  0, 0, 0, 0, 0, 0, 28, 60, 60, 20, 20, 0
_P007: .BYTE  0, 0, 0, 0, 0, 0, 28, 60, 60, 18, 34, 0
_P008: .BYTE  0, 0, 0, 0, 0, 0, 56, 60, 60, 40, 40, 0
_P009: .BYTE  0, 0, 0, 0, 0, 0, 56, 60, 60, 72, 68, 0
_P010: .BYTE  0, 0, 0, 2, 4, 6, 87, 254, 251, 88, 168, 168
_P011: .BYTE  0, 0, 0, 2, 4, 7, 86, 255, 248, 88, 84, 84
_P012: .BYTE  0, 0, 0, 64, 32, 96, 234, 127, 223, 26, 21, 21
_P013: .BYTE  0, 0, 0, 64, 32, 224, 106, 255, 31, 26, 42, 42
_P014: .BYTE  0, 0, 0, 0, 1, 7, 158, 124, 244, 212, 80, 64
_P015: .BYTE  0, 0, 0, 0, 1, 7, 158, 124, 242, 201, 36, 16
_P016: .BYTE  0, 0, 0, 0, 128, 224, 121, 62, 47, 43, 10, 2
_P017: .BYTE  0, 0, 0, 0, 128, 224, 121, 62, 79, 147, 36, 8
_P018: .BYTE  40, 41, 26, 29, 127, 94, 94, 61, 61, 75, 92, 20
_P019: .BYTE  10, 74, 44, 92, 127, 61, 61, 94, 94, 105, 29, 20
_P020: .BYTE  64, 40, 31, 28, 124, 30, 93, 60, 31, 28, 30, 40
_P021: .BYTE  1, 10, 124, 28, 31, 60, 93, 30, 124, 28, 60, 10
_P022: .BYTE  0, 24, 24, 0, 24, 24, 60, 126, 255, 195, 0, 0
_P023: .BYTE  0, 0, 24, 24, 0, 24, 219, 126, 60, 24, 0, 0
_P024: .BYTE  0, 0, 3, 3, 124, 252, 60, 124, 108, 12, 8, 0
_P025: .BYTE  0, 224, 115, 51, 28, 28, 63, 115, 99, 1, 0, 0
_P026: .BYTE  0, 192, 224, 112, 56, 123, 123, 56, 112, 224, 192, 0
_P027: .BYTE  0, 8, 24, 56, 48, 123, 123, 48, 56, 24, 8, 0
_P028: .BYTE  8, 12, 108, 124, 60, 252, 124, 3, 3, 0, 0, 0
_P029: .BYTE  0, 1, 99, 115, 63, 28, 28, 51, 115, 224, 0, 0
_P030: .BYTE  0, 0, 195, 255, 126, 60, 24, 24, 0, 24, 24, 0
_P031: .BYTE  0, 0, 0, 24, 60, 126, 219, 24, 0, 24, 24, 0
_P032: .BYTE  0, 16, 48, 54, 62, 60, 63, 62, 192, 192, 0, 0
_P033: .BYTE  0, 0, 128, 198, 206, 252, 56, 56, 204, 206, 7, 0
_P034: .BYTE  0, 3, 7, 14, 12, 222, 222, 12, 14, 7, 3, 0
_P035: .BYTE  0, 16, 24, 12, 12, 222, 222, 12, 12, 24, 16, 0
_P036: .BYTE  0, 0, 192, 192, 62, 63, 60, 62, 54, 48, 16, 0
_P037: .BYTE  0, 7, 206, 204, 56, 56, 252, 206, 198, 128, 0, 0
_P038: .BYTE  1, 3, 3, 6, 14, 204, 248, 248, 120, 108, 142, 12
_P039: .BYTE  1, 3, 115, 246, 238, 44, 27, 63, 103, 99, 128, 0
_P040: .BYTE  8, 8, 8, 8, 8, 28, 62, 107, 73, 93, 8, 8
_P041: .BYTE  8, 73, 73, 107, 62, 28, 8, 8, 8, 28, 8, 8
_P042: .BYTE  128, 192, 192, 96, 112, 51, 31, 31, 30, 54, 113, 48
_P043: .BYTE  128, 192, 206, 111, 119, 52, 216, 252, 230, 198, 1, 0
_P044: .BYTE  0, 240, 9, 54, 127, 255, 255, 127, 54, 42, 201, 0
_P045: .BYTE  0, 15, 17, 54, 127, 255, 255, 127, 54, 42, 73, 1
_P046: .BYTE  0, 15, 144, 108, 254, 255, 255, 254, 108, 84, 147, 0
_P047: .BYTE  0, 240, 136, 108, 254, 255, 255, 254, 108, 84, 146, 128
_P048: .BYTE  0, 0, 0, 0, 0, 0, 126, 255, 255, 165, 165, 0
_P049: .BYTE  0, 0, 0, 0, 0, 60, 126, 126, 102, 102, 66, 0
_P050: .BYTE  0, 0, 0, 24, 24, 60, 60, 102, 102, 102, 66, 0
_P051: .BYTE  0, 0, 24, 60, 60, 60, 60, 60, 60, 60, 36, 0
_P052: .BYTE  60, 126, 66, 223, 255, 199, 223, 255, 223, 94, 126, 36
_P053: .BYTE  60, 126, 102, 219, 255, 191, 163, 255, 219, 70, 126, 60
_P054: .BYTE  60, 126, 131, 239, 255, 239, 239, 255, 239, 110, 60, 24
_P055: .BYTE  60, 126, 70, 219, 255, 90, 70, 255, 223, 94, 126, 60
_P056: .BYTE  0, 0, 24, 60, 126, 126, 126, 126, 60, 24, 0, 0
_P057: .BYTE  0, 0, 0, 24, 60, 60, 60, 60, 24, 0, 0, 0
_P058: .BYTE  0, 0, 90, 126, 60, 126, 126, 60, 126, 90, 0, 0
_P059: .BYTE  24, 153, 219, 126, 60, 255, 255, 60, 126, 219, 153, 24
_P060: .BYTE  153, 219, 255, 126, 60, 231, 231, 60, 126, 255, 219, 153
_P061: .BYTE  153, 219, 126, 36, 0, 195, 195, 0, 36, 126, 219, 153
_P062: .BYTE  153, 219, 0, 0, 0, 195, 195, 0, 0, 0, 219, 153
_P063: .BYTE  153, 129, 0, 0, 0, 129, 129, 0, 0, 0, 129, 153

      .export _P000
      .export _P001
      .export _P002
      .export _P003
      .export _P004   
      .export _P005
      .export _P006
      .export _P007
      .export _P008
      .export _P009
      .export _P010
      .export _P011
      .export _P012
      .export _P013
      .export _P014
      .export _P015
      .export _P016
      .export _P017
      .export _P018
      .export _P019
      .export _P020
      .export _P021
      .export _P022
      .export _P023
      .export _P024
      .export _P025
      .export _P026
      .export _P027
      .export _P028
      .export _P029
      .export _P030
      .export _P031
      .export _P032
      .export _P033
      .export _P034
      .export _P035
      .export _P036
      .export _P037
      .export _P038
      .export _P039
      .export _P040
      .export _P041
      .export _P042
      .export _P043
      .export _P044
      .export _P045
      .export _P046
      .export _P047
      .export _P048
      .export _P049
      .export _P050
      .export _P051
      .export _P052
      .export _P053
      .export _P054
      .export _P055
      .export _P056      
      .export _P057      
      .export _P058      
      .export _P059      
      .export _P060
      .export _P061
      .export _P062
      .export _P063      

_SPRITEADDR_PLY0LO:
      .byte <_P000,<_P001,<_P002,<_P003,<_P004,<_P005,<_P006,<_P007,<_P008,<_P009,<_P010,<_P011,<_P012,<_P013,<_P014,<_P015
      .byte <_P016,<_P017,<_P018,<_P019,<_P020,<_P021,<_P022,<_P023,<_P024,<_P025,<_P026,<_P027,<_P028,<_P029,<_P030,<_P031
      .byte <_P032,<_P033,<_P034,<_P035,<_P036,<_P037,<_P038,<_P039,<_P040,<_P041,<_P042,<_P043,<_P044,<_P045,<_P046,<_P047
      .byte <_P048,<_P049,<_P050,<_P051,<_P052,<_P053,<_P054,<_P055,<_P056,<_P057,<_P058,<_P059,<_P060,<_P061,<_P062,<_P063
_SPRITEADDR_PLY0HI: 
      .byte >_P000,>_P001,>_P002,>_P003,>_P004,>_P005,>_P006,>_P007,>_P008,>_P009,>_P010,>_P011,>_P012,>_P013,>_P014,>_P015
      .byte >_P016,>_P017,>_P018,>_P019,>_P020,>_P021,>_P022,>_P023,>_P024,>_P025,>_P026,>_P027,>_P028,>_P029,>_P030,>_P031
      .byte >_P032,>_P033,>_P034,>_P035,>_P036,>_P037,>_P038,>_P039,>_P040,>_P041,>_P042,>_P043,>_P044,>_P045,>_P046,>_P047
      .byte >_P048,>_P049,>_P050,>_P051,>_P052,>_P053,>_P054,>_P055,>_P056,>_P057,>_P058,>_P059,>_P060,>_P061,>_P062,>_P063
_SPRITEADDR_PLY0W:
      .word _P000,_P001,_P002,_P003,_P004,_P005,_P006,_P007,_P008,_P009,_P010,_P011,_P012,_P013,_P014,_P015
      .word _P016,_P017,_P018,_P019,_P020,_P021,_P022,_P023,_P024,_P025,_P026,_P027,_P028,_P039,_P030,_P031
      .word _P032,_P033,_P034,_P035,_P036,_P037,_P038,_P039,_P040,_P041,_P042,_P043,_P044,_P045,_P046,_P047
      .word _P048,_P049,_P050,_P051,_P052,_P053,_P054,_P055,_P056,_P057,_P058,_P059,_P060,_P061,_P062,_P063
            
      .export _SPRITEADDR_PLY0LO      ; Makes Sprite Address Table available to C compiled program
      .export _SPRITEADDR_PLY0HI      ; Makes Sprite Address Table available to C compiled program
      .export _SPRITEADDR_PLY0W       ; Makes Sprite Address Table available to C compiled program
            
START_SOUND_ADDR_LO:                                                                                                                                                                                                                                                                       
    .BYTE <SHOOT_SOUND,<SOUND_1,<SOUND_2,<SOUND_3,<SOUND_4
    .BYTE <SOUND_5,<SOUND_6,<SOUND_7
START_SOUND_ADDR_HI:                                                                                                                                                                                                                                                                       
    .BYTE >SHOOT_SOUND,>SOUND_1,>SOUND_2,>SOUND_3,>SOUND_4
    .BYTE >SOUND_5,>SOUND_6,>SOUND_7
START_SOUND_LENGTH_LO:                                                                                                                                                                                                                                                                         
    .BYTE <SHOOT_SOUND_SIZE,<SOUND_1_SIZE,<SOUND_2_SIZE,<SOUND_3_SIZE
    .BYTE <SOUND_4_SIZE,<SOUND_5_SIZE,<SOUND_6_SIZE,<SOUND_7_SIZE
START_SOUND_LENGTH_HI:                                                                                                                                                                                                                                                                     
    .BYTE >SHOOT_SOUND_SIZE,>SOUND_1_SIZE,>SOUND_2_SIZE,>SOUND_3_SIZE
    .BYTE >SOUND_4_SIZE,>SOUND_5_SIZE,>SOUND_6_SIZE,>SOUND_7_SIZE

SHOOT_SOUND:
    .BYTE 111,32,110,40,110,48,109,56,108,64,108,72,107,80,106,88,106,96,105,104
    .BYTE 104,112,104,120,103,128,102,136,102,144,101,152,100,160,100,168,99,176
    .BYTE 98,184,98,192,97,200,97,208,97,216,97,224,97,232,97,240,97,248
SHOOT_SOUND_SIZE=(*-SHOOT_SOUND) / 2 + 1
    
SOUND_1:
    .BYTE 15,32,15,32,15,33,15,34,14,33,14,32,13,32,12,32,11,32
    .BYTE 10,32,9,34,8,35,6,36,5,35,4,34,3,33,2,32,1,32  
SOUND_1_SIZE=(*-SOUND_1) / 2 + 1

SOUND_2:
    .BYTE 143,255,143,180,142,127,142,89,141,63,141,44,140,31,139,21,138,15,137,11,136,7,135,4,134,2,133,1
SOUND_2_SIZE=(*-SOUND_2) / 2 + 1
    
SOUND_3:    
    .BYTE 175,1,175,4,175,16,175,64,172,1,172,4,172,16,172,64,169,1,169,4,169,16
    .BYTE 169,64, 166,1,166,4,166,16,166,64,163,1,163,4,163,16,163,64 
SOUND_3_SIZE=(*-SOUND_3) / 2 + 1

SOUND_4:    
    .BYTE 175,64, 175,128,175,192,173,64,173,128,173,192,171,64,171,128,171,192
    .BYTE 169,64, 169,128,169,192,167,64,167,128,167,192,165,64,165,128,165,192
    .BYTE 163,64,163,128,163,192,161,64,161,128,161,192,0,0,0,0
SOUND_4_SIZE=(*-SOUND_4) / 2 + 1

SOUND_5:    
    .BYTE $8F,248,$8F,240,$8E,232,$8E,224,$0D,216,$8D,208,$8C,200,$6C,192
    .BYTE $8B,252,$6B,244,$0A,236,$8A,228,$89,220,$89,212,$88,204,$88,196
    .BYTE $07,248,$87,240,$86,232,$66,224,$85,216,$85,208,$84,200,$84,192
    .BYTE $83,252,$83,244,$83,236,$82,228,$82,220,$62,212,$01,204,$81,196   
SOUND_5_SIZE=(*-SOUND_5) / 2 + 1

SOUND_6:
    .BYTE 143,96,143,97,142,98,142,99,141,100,141,101,140,102,140,103,139,104,138,105,137,106
    .BYTE 137,107,136,108,135,109,134,110,134,112,133,114,132,116,132,118,131,120,131,122,130,124,129,126  
SOUND_6_SIZE=(*-SOUND_6) / 2 + 1

SOUND_7:
    .BYTE 175,128,170,128,165,128
    .BYTE 175,064,170,064,165,064
    .BYTE 175,128,170,128,165,128
    .BYTE 175,032,170,032,165,032
    .BYTE 175,128,170,128,165,128
    .BYTE 175,016,170,016,165,016
SOUND_7_SIZE=(*-SOUND_7) / 2 + 1


    .include "atari_sound_commander.asm"
_GAME_VBI:
    .export _GAME_VBI 
;	lda #<_GAME00_DLI
;	sta VDSLST+0
;	lda #>_GAME00_DLI
;	sta VDSLST+1
;	  lda #$22      
;  	sta COLBAK
    



    JSR PROCESS_SOUNDS
        	
		JMP XITVBV	


;    ldy #11
;    lda #0
;clear_sprite_loop:            
; 		sta (SP00L),Y
; 		sta (SP01L),Y
; 		sta (SP02L),Y
; 		sta (SP03L),Y
;    dey
;    bpl clear_sprite_loop


;    ldy #11
;    lda #0
;write_sprite_loop:            
; 		lda (LD00L),Y
;    sta (SP00L),Y
;    lda (LD01L),Y
; 		sta (SP01L),Y
;    lda (LD02L),Y
; 		sta (SP02L),Y
;    lda (LD03L),Y
;   sta (SP03L),Y
;    dey
;    bpl write_sprite_loop



_TITLE_VBI:
      .export _TITLE_VBI 
		lda #<_TITLE00_DLI
		sta VDSLST+0
		lda #>_TITLE00_DLI
		sta VDSLST+1
		lda #$22
		sta COLBAK
		lda #$36
		sta COLPF3				
		inc _RTCLOCK+2
		jmp XITVBV


PAUSE_VBI:
      .export PAUSE_VBI

		jmp XITVBV

_TITLE00_DLI:
      .export _TITLE00_DLI 
	pha	
	lda #$D8
	sta WSYNC
	sta COLPF0
	lda #$06
	sta COLPF1
	lda #$AA
	sta COLPF1
;lda #>CHARSET_TITLE
;sta CHBASE
  lda #<_TITLE01_DLI
  sta VDSLST+0
	lda #>_TITLE01_DLI
	sta VDSLST+1
	pla
	rti

_TITLE01_DLI:
      .export _TITLE01_DLI 
	pha	
	lda #142
	sta WSYNC
	sta COLPF0
	lda #216
	sta COLPF1
	lda #56
	sta COLPF2
; lda #>CHARSET_GAME
; sta CHBASE
	lda #<_TITLE00_DLI
	sta VDSLST+0
	lda #>_TITLE00_DLI
	sta VDSLST+1
	pla
	rti

_TITLE02_DLI:
      .export _TITLE02_DLI 
	PHA
  PLA
  RTI


_TITLE03_DLI:
      .export _TITLE03_DLI 
	PHA
  PLA
  RTI


_GAME00_DLI:
      .export _GAME00_DLI 
	  PHA
    LDA #$10
    STA COLPF0  
    LDA #$F6
    STA WSYNC
    STA COLPF1  
    LDA #$EC 
    STA COLPF2
    LDA #$5A  
    STA COLPF3
    LDA #$34  
    STA COLBAK    
    PLA
  RTI

_GAME01_DLI:
      .export _GAME01_DLI 
	PHA
  PLA
  RTI

_GAME02_DLI:
      .export _GAME02_DLI 
	PHA
  PLA
  RTI

_GAME03_DLI:
      .export _GAME03_DLI 
	PHA
  PLA
  RTI

_GAME04_DLI:
      .export _GAME04_DLI 
	PHA
  PLA
  RTI


 
;
;  Title Screen is a Simple Text for Basic Version 

; ------------------------------------------------------------------------
; Actual code
; *** end of main startup code
  
;;        .segment "DATA0"
; ------------------------------------------------------------------------     

_MOVE_SHOOTER:
    .export _MOVE_SHOOTER
;     PLA
;     LDA _shooter_px 
;     STA _prior_x        
;     LDA _shooter_pY
;     STA _prior_y 
      LDA #1  
      BIT PORTA
      BNE MS_L2 
      LDA _shooter_py 
      SEC       
      SBC #2 
      CMP #183  
      BCS MS_L3 
      LDA #183  
      STA _shooter_py 
MS_L2:
      LDA #2    
      BIT PORTA  
      BNE MS_L4 
      LDA _shooter_py 
      CLC       
      ADC #2 
      CMP #229  
      BCC MS_L3 
      LDA #229  
MS_L3:
      STA _shooter_py
MS_L4:            
      LDA #$04
      BIT PORTA
      BNE MS_L6
      LDA _shooter_px 
      SEC       
      SBC #2 
      CMP #46
      BCS MS_L5
      LDA #46 
MS_L5:
      STA _shooter_px 
MS_L6:
      LDA #$08  
      BIT PORTA 
      BNE MS_L8 
      LDA _shooter_px 
      CLC       
      ADC #2 
      CMP #202  
      BCC MS_L7
      LDA #202 
MS_L7:
      STA _shooter_px
MS_L8:


      LDA _BULLET_STATUS 
      BEQ  No_Moving_Bullet
      LDA _BULLET_X_POS
      STA HPOSM0

      LDX _BULLET_SPEED
      LDA #0
      LDY _BULLET_Y_POS
ERASE_BULLET_LOOP:      
      STA _PMBANK + 792,Y
      INY
      DEX
      BPL ERASE_BULLET_LOOP


      LDY #0
      LDA _BULLET_Y_POS
      SEC
      SBC _BULLET_SPEED
      CMP #240
      BCS REMOVE_BULLET_FROM_SCREEN      
BULLET_STILE_ONSCREEN:     
      STA _BULLET_Y_POS

      LDX _BULLET_SPEED
      LDA #3
      LDY _BULLET_Y_POS
DRAW_BULLET_LOOP:
      LDA #3
      STA _PMBANK + 792,Y
      INY
      DEX
      BPL DRAW_BULLET_LOOP
      
      
      LDA _BULLET_SCREEN_LOC
      SEC
      SBC _BULLET_SCREEN_SUB
      STA _BULLET_SCREEN_LOC
      BCS No_MS_Sub_Hi
      DEC _BULLET_SCREEN_LOC + 1
No_MS_Sub_Hi:     
      LDY #40
      LDA (_BULLET_SCREEN_LOC),Y
      BNE Bullet_Hit_Screen_Object
      LDY #0
      LDA (_BULLET_SCREEN_LOC),Y
      BNE Bullet_Hit_Screen_Object            
No_Moving_Bullet:      
      RTS
Bullet_Hit_Screen_Object:
      STA _BULLET_HIT1
      
      TYA
      CLC 
      ADC _BULLET_SCREEN_LOC
      STA _BULLET_L2
      LDA  _BULLET_SCREEN_LOC + 1
      ADC #0
      STA _BULLET_L2 + 1      
REMOVE_BULLET_FROM_SCREEN:
      LDA #0
      STA _BULLET_STATUS 
      
      LDX #32
      LDY _BULLET_Y_POS 
REMOVE_BULLET_SCREEN_LOOP:
      STA _PMBANK + 792,Y
      INY
      DEX
      BPL REMOVE_BULLET_SCREEN_LOOP
      LDA _BULLET_HIT1
      BNE SET_HIT_BULLET_LOCATIONS      
      RTS

SET_HIT_BULLET_LOCATIONS:

      RTS      
; ------------------------------------------------------------------------
                  
_SET_BULLET:
    .export _SET_BULLET
    LDA _shooter_px
    CLC
    ADC #3
    STA _BULLET_X_POS
    SEC
    SBC #46
    LSR
    LSR
    STA M1
    STA HPOSM0 
    LDA _shooter_py
    SEC
    SBC #20
    STA _BULLET_Y_POS
    SBC #2
    LSR
    LSR
    LSR    
    TAY
    LDA _SCREEN_ROW_LOW,Y
    CLC
    ADC M1
    STA _BULLET_SCREEN_LOC
    LDA _SCREEN_ROW_HIGH + 1,Y
    ADC #0
    STA _BULLET_SCREEN_LOC + 1
    LDA #1
    STA _BULLET_STATUS
    LDA #3
    LDY _BULLET_Y_POS
    LDX #7
DRAW_NEW_BULLET_LOOP:
    STA _PMBANK + 792,Y
    INY
    DEX
    BPL DRAW_NEW_BULLET_LOOP       
    RTS
; ------------------------------------------------------------------------    
    
    



;;;; ***** Need test to see if value can be returned to Basic
_GET_SCREEN_BYTE:
      .export _GET_SCREEN_BYTE
    LDY #0
    LDA (sp),Y
    SEC
    SBC #1 
    LSR
    LSR
    LSR
    TAY
    LDA _SCREEN_ROW_LOW,Y
    STA NDX0
    LDA _SCREEN_ROW_HIGH,Y
    STA NDX1    
    STA M6 
    LDY #2
    LDA (sp),Y  
    SEC
    SBC #48
    LSR 
    LSR
    TAY

    LDA sp
    CLC
    ADC #4
    STA sp
    BCC  No_INC_C_Stack_Hi_GSB
    INC sp+1        
No_INC_C_Stack_Hi_GSB:
    LDX #0
    LDA (NDX0),Y
    BNE Save_Found_Byte
    INY
    LDA (NDX0),Y    
Save_Found_Byte:   

    
    RTS   
; ------------------------------------------------------------------------    
    
_PMMOVE:
    .export _PMMOVE 
    LDY #6
    LDA (sp),Y
    STA FROMLO
    LDY #7
    LDA (sp),Y 
    STA FROMHI    
    LDY #8
    LDA (sp),y
    TAX
    STX PMNUMBER
    LDY #2
    LDA (sp),Y    
    CPX #$05
    BNE COMBOSKIP
    CLC 
    ADC #$08
    STA HPOSM0
    SEC 
    SBC #$02
    STA HPOSM1
    SBC #$02
    STA HPOSM2
    SBC #$02
    LDX #7
COMBOSKIP:
    STA HPOSP0-1,X
    TXA
    CLC 
    ADC #$03
    CMP #$08
    BCC NOCOMBO
    LDA #$03
NOCOMBO:
    CLC
    ADC #_PMBANK_HI
    STA PMYPOS+1    
    LDA PMSAVELO,X
    STA PMYPOS+0
    LDA PMSAVESZ,X
    TAY 
    LDA #$00
CLEARLOOP:
    STA (PMYPOS),Y
    DEY 
    BPL CLEARLOOP     
    LDY #0
    LDA (sp),Y    
    STA PMSAVELO,X
    STA PMYPOS+0
    LDY #4
    LDA (sp),Y    
    STA PMSAVESZ,X
    TAY                
    DEY 
DRAWLOOP:
    LDA (FROMLO),Y
    STA (PMYPOS),Y
    DEY 
    BPL DRAWLOOP
    LDA sp
    CLC
    ADC #10
    STA sp
    BCC No_INC_C_Stack_Hi_PMV
    INC sp + 1
No_INC_C_Stack_Hi_PMV:   
    RTS       
    
; ------------------------------------------------------------------------
_DRAWSCREEN:
    .export _DRAWSCREEN
    
    
    RTS    
; ------------------------------------------------------------------------
_CHECKSCREENHIT:
    .export _CHECKSCREENHIT
    
    
    RTS
    