#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <peekpoke.h>
#include <stdlib.h>
#include <string.h>		// For memset()
#include <atari.h>
#include <joystick.h> 
#include <errno.h>      


#if defined(__ATARI__)  // Atari 400 / 800 / XL / XE / XEGS   Antic  GTIA  Pokey
  #include <atari_equates.h>
#elif !defined(__ATARI2600__) // TIA  RIOT

#elif defined(__ATARI5200__)  //  Antic  GTIA  Pokey

#elif !defined(__ATARI7800__) // TIA  MARIA  RIOT

#elif defined(__LYNX__)

#elif defined(__VIC20__) //VIC I

#elif defined(__C16__)  // TED

#elif defined(__C64__) // VIC II SID

#elif defined(__C128__) // VIC II SID + 

#elif defined(__APPLE2__)

#endif

extern unsigned char CHARSET_GAME;
extern unsigned char CHARSET_TITLE;
extern unsigned char CHARSET_GAME_HI;
extern unsigned char CHARSET_TITLE_HI;
extern unsigned int  TITLE_DATA;

extern unsigned char PMBANK;
extern unsigned char VARBANK;                                       
extern unsigned char SCREEN_ADDR;                                        
extern unsigned char GAME_SCREEN_ADDR;
extern unsigned char PMBANK_HI;

extern unsigned char M0;								  
extern unsigned char M1;								  
extern unsigned char M2;							  
extern unsigned char M3;								  
extern unsigned char M4;								  
extern unsigned char M5;							  
extern unsigned char M6;								  
extern unsigned char M7;								  
extern unsigned char M8;								  
extern unsigned char M9;								  
      
extern unsigned char NDX0;								  
extern unsigned char NDX1;								  
extern unsigned char NDX2;								  
extern unsigned char NDX3;								  
extern unsigned char SPRITENUM;            
extern unsigned char SETSP0COLOR;          
extern unsigned char SETSP1COLOR;          
extern unsigned char SETSPWIDTH;           
extern unsigned char SPRITENHOZ;           
extern unsigned char SPRITENVRT;           
extern unsigned char SPHOZNEXT;            
extern unsigned char SPRHZ0;              
extern unsigned char SPRHZ1;              
extern unsigned char SPRHZ2;              
extern unsigned char SPRHZ3;              
extern unsigned char SPZONT;               
extern unsigned char SPZONB;               
extern unsigned char SPSRC0;               
extern unsigned char SPSRC1;               
extern unsigned char SPSRC2;               
extern unsigned char SPSRC3;               
extern unsigned char SPSRC4;               
extern unsigned char SPRITEUSE;                                   
extern unsigned int  MIBANK;               
extern unsigned int  PMBNK0;                         
extern unsigned int  PMBNK1;                   
extern unsigned int  PMBNK2;                   
extern unsigned int  PMBNK3;               

extern unsigned char shooter_px;    
extern unsigned char shooter_py;    
extern unsigned char shooter_status;
extern unsigned char prior_x;       
extern unsigned char prior_y;       
extern unsigned char stick_read;    

extern unsigned int  GAME_VBI;
extern unsigned int  TITLE_VBI;


extern unsigned int  GAME00_DLI;
extern unsigned int  GAME01_DLI;
extern unsigned int  GAME02_DLI;
extern unsigned int  GAME03_DLI;
      
extern unsigned int  TITLE00_DLI;
extern unsigned int  TITLE01_DLI;
extern unsigned int  TITLE02_DLI;
extern unsigned int  TITLE03_DLI;

extern unsigned char stick_read;
    

extern unsigned int  DISPLAY_LIST_TITLE;      
extern unsigned int  DISPLAY_LIST_GAME;

extern unsigned char BUG_TYPE[];
extern unsigned char BUG_XPOS[];   
extern unsigned char BUG_YPOS[];   
extern unsigned char BUG_XDIR[];   
extern unsigned char BUG_YDIR[];   
extern unsigned char BUG_STATUS[];
extern unsigned char BUG_DATA1[];
extern unsigned char BUG_DATA2[];

extern unsigned char P000;
extern unsigned char P001;
extern unsigned char P002;
extern unsigned char P003;
extern unsigned char P004;
extern unsigned char P005;
extern unsigned char P006;
extern unsigned char P007;
extern unsigned char P008;
extern unsigned char P009;
extern unsigned char P010;
extern unsigned char P011;
extern unsigned char P012;
extern unsigned char P013;
extern unsigned char P014;
extern unsigned char P015;
extern unsigned char P016;
extern unsigned char P017;
extern unsigned char P018;
extern unsigned char P019;
extern unsigned char P020;
extern unsigned char P021;
extern unsigned char P022;
extern unsigned char P023;
extern unsigned char P024;
extern unsigned char P025;
extern unsigned char P026;
extern unsigned char P027;
extern unsigned char P028;
extern unsigned char P029;
extern unsigned char P030;
extern unsigned char P031;
extern unsigned char P032;
extern unsigned char P033;
extern unsigned char P034;
extern unsigned char P035;
extern unsigned char P036;
extern unsigned char P037;
extern unsigned char P038;
extern unsigned char P039;
extern unsigned char P040;
extern unsigned char P041;
extern unsigned char P042;
extern unsigned char P043;
extern unsigned char P044;
extern unsigned char P045;
extern unsigned char P046;
extern unsigned char P047;
extern unsigned char P048;
extern unsigned char P049;
extern unsigned char P050;
extern unsigned char P051;
extern unsigned char P052;
extern unsigned char P053;
extern unsigned char P054;
extern unsigned char P055;
extern unsigned char P056;
extern unsigned char P057;
extern unsigned char P058;
extern unsigned char P059;
extern unsigned char P060;
extern unsigned char P061;
extern unsigned char P062;
extern unsigned char P063;

extern char BULLET_STATUS;
extern char BULLET_X_POS;
extern char BULLET_Y_POS;
extern int  BULLET_SCREEN_LOC;
extern char BULLET_HIT1;
extern char BULLET_HIT2;
extern int  BULLET_L2;
extern char BULLET_SPEED;
extern char BULLET_SCREEN_SUB;
// ML calls written in CA65 assembly

extern void cdecl PMMOVE(unsigned int, unsigned int, unsigned int, unsigned int,  unsigned int);
extern void cdecl MOVE_SHOOTER(void);
extern void cdecl SET_BULLET(void);
extern unsigned int cdecl GET_SCREEN_BYTE(unsigned int, unsigned int);
extern void cdecl START_SOUND(unsigned int, unsigned int);
extern void cdecl Kill_Playing_Music(void);
extern void cdecl SILENCE(void);   



#pragma regvaraddr(on)  /* Allow taking the address
                        * of register variables
                        */
  
#define	NDX0									 0xCA
#define	NDX1									 0xCB
#define	NDX2									 0xCC
#define	NDX3									 0xCD
#define	HOLDX									 0xCE
#define	HOLDY									 0xCF
    
#define	PMMEMORY                                 PMBANK                                         
#define	VARBANK                                  VARBANK


      


#define	SPRITENUM	((unsigned char *)             (PMBANK+0x0180))
#define	SETSP0COLOR ((unsigned char *)           (PMBANK+0x0190))
#define	SETSP1COLOR ((unsigned char *)           (PMBANK+0x01A0))
#define	SETSPWIDTH ((unsigned char *)            (PMBANK+0x01B0))
#define	SPRITENHOZ ((unsigned char *)            (PMBANK+0x01C0))
#define	SPRITENVRT ((unsigned char *)            (PMBANK+0x01E0))
#define	SPHOZNEXT  ((unsigned char *)            (PMBANK+0x01F0))
#define	SCREEN_LINE_ADDR_LOW ((unsigned char *)	 (PMBANK+0x0000))
#define	SCREEN_LINE_ADDR_HIGH ((unsigned char *) (PMBANK+0x0020))
#define	CHARSET_ADDRESS ((unsigned char *)       0xA400

#define SPRHZ0	((unsigned char *)	            (PMBANK+0x0200)) 
#define SPRHZ1	((unsigned char *)	            (PMBANK+0x0210)) 
#define SPRHZ2	((unsigned char *)	            (PMBANK+0x0220)) 
#define SPRHZ3	((unsigned char *)	            (PMBANK+0x0230)) 
#define SPZONT  ((unsigned char *)              (PMBANK+0x0240))
#define SPZONB  ((unsigned char *)              (PMBANK+0x0250))
#define SPSRC0  ((unsigned char *)              (PMBANK+0x0260)) 
#define SPSRC1  ((unsigned char *)              (PMBANK+0x0278))
#define SPSRC2  ((unsigned char *)              (PMBANK+0x0290))
#define SPSRC3  ((unsigned char *)              (PMBANK+0x02A8))
#define SPSRC4  ((unsigned char *)              (PMBANK+0x02C0))
#define SPRITEUSE ((unsigned char *)           	(PMBANK+0x02D8))
                                            
#define MIBANK ((unsigned char *)              	(PMBANK+0x0300))
#define PMBNK0 ((unsigned char *)               (PMBANK+0x0400))
#define PMBNK1 ((unsigned char *)	              (PMBANK+0x0500))
#define PMBNK2 ((unsigned char *)               (PMBANK+0x0600))
#define PMBNK3 ((unsigned char *)	              (PMBANK+0x0700))

unsigned short int BUG_MOVE_FRACTION[6]={};
unsigned short int BUG_MOVE_DELAY[6]={};

unsigned short int DIR_X_ADD[] = {000,001,001,001,000,255,255,255,000,002,002,002,000,254,254,254};
unsigned short int DIR_Y_ADD[] = {255,255,000,001,001,001,000,255,254,254,000,002,002,002,000,254};
unsigned short int BUG_DIE_COLOR[] = {14,26,12,24,10,22,8,20,6,18};
unsigned short int BUG_DEFAULT_COLOR[] = {000,172,48,72,104,60,26,204,90,50,60};
unsigned short int BUG_XSTART_MIN[] = {0, 48, 48, 48, 48, 02, 60, 54, 56, 52, 52};
unsigned short int BUG_XSTART_MAX[] = {0,200,200,200,200,253,188,194,192,196,196}; 
unsigned short int BUG_Y_START[] = {0,10,12,10,12,32,4,4,4,4};
unsigned short int BUG_SCORE_VALUE[] = {0,7,10,15,12,30,20,40,25,35,45};
unsigned short int MOVE_FRACTION_BASE[] = {0,68,0,63,72,80,60,30,30,30};
unsigned short int MOVE_FRACTION_MULT[] = {1,2,1,3,2,3,4,3,3,3};  //00,00 68 3  00 00 62 3 72 2 80 3 60 4 30 3
unsigned short int MOVE_FRACTION_MAX[] = {0,240,127,240,240,255,224,248,252,250,250};
unsigned char DL_ADDR_SET;
unsigned char	A;
unsigned char B;
unsigned char	C;
unsigned char D;
unsigned char	E;
unsigned char	F;
unsigned char	G;
unsigned char	H;
unsigned char	I;
unsigned char	J;
unsigned char	K;
unsigned char	L;
unsigned int 	N;
unsigned int 	M;
unsigned int  O;
unsigned char	P;
unsigned char	Q;
unsigned char	R;
unsigned char	S;
unsigned int 	T;
unsigned int  U;
unsigned char	V;
unsigned char	W;
unsigned char	X;
unsigned char	Y;
unsigned char	Z;
unsigned char	SPRITE_2FRAME;
unsigned short int	BUG_X_MOVE;
unsigned short int	BUG_Y_MOVE;
unsigned int Add_New_Bug_CountDown;
unsigned int Add_New_Bug_Reset; 
unsigned short int Bugs_Remaining;
unsigned int Next_Extra_Life_Score;
unsigned char BUG_INDEX;
unsigned char	PC;
unsigned char	SU;
unsigned int  SCR_ADDR;
unsigned char	Current_Level;
unsigned int  Score;
unsigned char	Lives;
unsigned char Exit_Flag;
unsigned short int hiscore [11] = {0,0,0,0,0,0,0,0,0,0,0}; //Set High Scores to 0
unsigned short HiScore_Place;
unsigned int  G1;
unsigned int  G2;
unsigned int  G3;
unsigned int  G4;
unsigned int  G5;
unsigned int  G6;
unsigned int  G7;

//------------------------------
void DISPLAY_TITLE(void)
  {
        POKE(NMIEN,64);        
        POKEW(DLISTW,&DISPLAY_LIST_TITLE); 	 
        POKEW(SDLSTW,&DISPLAY_LIST_TITLE);
        POKEW(VVBLKD,&TITLE_VBI); 
        POKE(CHBAS,&CHARSET_TITLE_HI);                                    
        memset(&PMBANK + 768,0,1280);
        POKE(709,80);
        POKE(710,42);        
      	POKE(711,80);
        POKE(712,34);
        memset(&SCREEN_ADDR, 0, 1024);        
      	gotoxy(12,2);
      	printf ("B U G   I N V A D E");
      	gotoxy(1,3);
      	printf ("CC65 Version          By Peter J. Meyer");
      	gotoxy(3,6);
      	printf ("Your Score : %u",Score);
      	gotoxy(12,8);
      	printf ("High Scores");
        
        for (I = 1; I < 11; I++)
          {
           if (I < 10)
              {J = 13;}
           else
             {J = 12;}
      	   gotoxy(J,8+I);
      	   printf ("  %u : %u  ",I,hiscore[I]);
           
            if (I == HiScore_Place)
            {
              gotoxy(12,8+I);
              printf("*\n");
            } 
          }          
      	gotoxy(0,20);
      	printf (" Press START or FIRE to play begin game\n");
      	while (PEEK(CONSOL) & 0x01 == 1)
      	{
      	} 
      	while (PEEK(CONSOL) & 0x01 == 0)
      	{
      	} 
  }
//------------------------------
void PRINT_SCORE(void)
  {
   	gotoxy(0,0);
    printf("SCORE:%u\n",Score);
    gotoxy(20,0);
    printf("PASS:%u\n",Lives);
  	gotoxy(30,0);    
    printf("LEVEL:%u\n",Current_Level);
    }
//------------------------------
void BULLET_PLAYFIELD(void)
{
    BULLET_STATUS = 0;
    BULLET_HIT1 = 0;
		memcpy(&PMBANK + 792 + BULLET_Y_POS, &PMBANK+528,32);
  	G1 = PEEK(BULLET_L2)&127;
  	G2 = PEEK(BULLET_L2 - 40)&127;
  	G3 = PEEK(BULLET_L2 - 80)&127;
  	G4 = PEEK(BULLET_L2 + 1)&127;
  	G5 = PEEK(BULLET_L2 - 39)&127;
  	G6 = PEEK(BULLET_L2 - 1)&127;    
  	G7 = PEEK(BULLET_L2 - 41)&127;
    START_SOUND(1,1);
	if (G1 == 67 && (G2 == 65 || G2 == 66) && G3 != 65 && G3 != 66)
	{
		POKE( BULLET_L2,0);
		POKE(BULLET_L2 - 40,0);
	}
	if (G1 == 67 && (G2 == 65 || G2 == 66) && (G3 == 65 || G3 == 66))
	{
		POKE(BULLET_L2,0);
		POKE(BULLET_L2 - 40,67);
	}
	if (G1 == 67 && ((G4 > 68 && G4 < 72) || (G6>67 && G6 < 71)))
	{
		POKE(BULLET_L2, 69+(PEEK(RANDOM)&1));
	}
	if (G1 == 67 && G4 > 68 && G4 < 72 && G6 == 0)
	{
		POKE(BULLET_L2,68);
	}
	if (G1 == 67 && G4 == 0 && G6 > 67 && G6 < 71)
	{
		POKE(BULLET_L2,71);
	}
	if (G1 == 71 && G6 == 0)
	{
		POKE(BULLET_L2,0);
	}
	if (G1 == 71 && G4 == 0)
	{
		POKE(BULLET_L2,0);
	}
	if (G1 == 68 && G6 == 0)
	{
		POKE(BULLET_L2,0);
	}
	if (G1 == 68 && G4 == 0)
	{
		POKE(BULLET_L2,0);
	}
	if (G1 == 68 && (G4 == 69 || G4 == 70))
	{
		POKE(BULLET_L2,0);
		POKE(BULLET_L2 + 1,68);
	}
	if (G1 == 71 && (G6 == 69 || G6 == 70))
	{
		POKE(BULLET_L2,0);
		POKE(BULLET_L2 - 1,71);
	}
	if (G1 == 68 && G4 == 71)
	{
		POKE(BULLET_L2,0);
		POKE(BULLET_L2 + 1,0);
	}
	if (G1 == 71 && G6 == 68)
	{
		POKE(BULLET_L2,0);
		POKE(BULLET_L2 - 1,0);
	}
	if ((G2 == 65 || G2 == 66) && ((G5 > 68 && G5 < 72) || (G7>67 && G7 < 71)))
	{
		POKE(BULLET_L2 - 40,69 + (PEEK(RANDOM)&1));
	}
	if ((G2 == 65 || G2 == 66) && (G5 > 68 && G5 < 72) && G7 == 0)
	{
		POKE(BULLET_L2 - 40,68);
	}
	if ((G2 == 65 || G2 == 66) && (G7 > 67 && G7 < 71) && G5 == 0)
	{
		POKE(BULLET_L2 - 40,71);
	}
	if ((G1 == 69 || G1 == 70) && (G4 == 69 || G4 == 70) && (G6 == 69 || G6 == 70))
	{
	  POKE(BULLET_L2,0);
	  POKE(BULLET_L2 - 1,71);
	  POKE(BULLET_L2 + 1,68);
	}
	if ((G1 == 69 || G1 == 70) && (G4 == 69 || G4 == 70) && G6 == 68)
	{
		POKE(BULLET_L2,0);
		POKE(BULLET_L2 - 1,0);
		POKE(BULLET_L2 + 1,68);
	}
	if ((G1 == 69 || G1 == 70) && G4 == 71 && (G6 == 69 || G6 == 70))
	{
		POKE(BULLET_L2,0);
		POKE(BULLET_L2 - 1,71);
		POKE(BULLET_L2 + 1,0);
	}
	if ((G1 == 69 || G1 == 70) && G4 == 71 && G6 == 68)
	{
		POKE(BULLET_L2,0);
		POKE(BULLET_L2 + 1,0);
		POKE(BULLET_L2 - 1,0);
	}
	if (G4 + 127 > 63 && G4 + 127 < 68 && G1>67)
	{
		POKE(BULLET_L2,0);
	}
	if (G6 + 127 > 63 && G6 + 127 < 68 && G1>67)
	{
		POKE(BULLET_L2,0);
	}
	if (G4 + 127 > 63 && G4 + 127 < 68 && G1>67 && (G6 == 68 || G6 == 71))
	{
		POKE(BULLET_L2,0);
		POKE(BULLET_L2 - 1,0);
	}
	if (G6 + 127 > 63 && G6 + 127 < 68 && G1>67 && (G4 == 68 || G4 == 71))
	{
		POKE(BULLET_L2,0);
		POKE(BULLET_L2 + 1,0);
	}
	if (G4 > 63 && G4 < 68 && G1>67 && (G6 == 69 || G6 == 70))
	{
		POKE(BULLET_L2,0);
		POKE(BULLET_L2 - 1,71);
	}  
	if (G6 > 63 && G6 < 68 && G1>67 && (G4 == 69 || G4 == 70))
	{
		POKE (BULLET_L2,0);
		POKE (BULLET_L2 + 1,68);
	}
	if ((G2 == 65 || G2 == 66) && G1 > 67)
	{
		POKE (BULLET_L2,67);
	}
  
		POKE(53278,0); 
}
//------------------------------
void BULLET_HIT_BUG(void)
  {
      L = 2;
      for (I = 0;I<=2;I++)
        {
          if ((PEEK(M0PL) & L) == L)
            {
              if (BUG_TYPE[I] >= 1 && BUG_TYPE[I] < 13)
                {
                  K = BUG_TYPE[I]; 
                  Score = Score + BUG_SCORE_VALUE[K];
                  if (Score > Next_Extra_Life_Score)
                  {
                    Next_Extra_Life_Score = Next_Extra_Life_Score + 1000;
                    ++ Lives;
                    START_SOUND(5,1);
                  }
                  POKE(PCOLR1+I,15);          
                  BUG_TYPE[I] = 15;            
                  BUG_XDIR[I] = 0;
                  POKE(HITCLR,255);        
                  BULLET_STATUS = 0;
    				      memcpy(&PMBANK + 792 + BULLET_Y_POS, &PMBANK+528,32);
                  PRINT_SCORE();
                  START_SOUND(2,1);
                  Bugs_Remaining = Bugs_Remaining - 1;
                  if (Bugs_Remaining > 250 && Exit_Flag == 0)  
                    {             
                    Exit_Flag = 1;
                    }
                }                      
            }
            L += L;
        }         
  }
//------------------------------
void DRAW_PIECE_0(void)
{
	POKE(N+X,67);
	POKE(N+X-40,65);
}
//------------------------------
void DRAW_PIECE_1(void)
  {
	POKE(N + X, 67);
	POKE(N + X - 40, 194);
  }
//------------------------------
void DRAW_PIECE_2(void)
{
    X = rand()%30;
    Y = rand()%8+2;
    L = PEEK(X+N);
    if (L!=67) 
      {
        POKE(X+N,68);
      }
    L=PEEK(X+Y+N);
    if (L!=67) 
      {
        POKE(X+Y+N,71);
      }
    for (O = N + X + 1; O < N + X + Y; O++)
        {
        if (PEEK(O)!=67) 
         {
          POKE(O,69 + rand()%2);
          }
        }
  	P = 0;
}
//------------------------------
void DEFINE_NEW_BUG(void)
  {
      _randomize();
      P = 1 + rand()%8;
      BUG_TYPE[BUG_INDEX] = P;
      R = BUG_DEFAULT_COLOR[P]; 
      POKE(705 + BUG_INDEX,R);
      BUG_YPOS[BUG_INDEX] = BUG_Y_START[P];      
      while (BUG_X_MOVE < BUG_XSTART_MIN[P] || BUG_X_MOVE > BUG_XSTART_MAX[P])
        {
          BUG_X_MOVE = PEEK(RANDOM);  
        }      
      BUG_XPOS[BUG_INDEX]  = BUG_X_MOVE;
      if (BUG_TYPE[BUG_INDEX] != 2)   
          {
            I = MOVE_FRACTION_BASE[P] + Current_Level * MOVE_FRACTION_MULT[P];
            if (I > MOVE_FRACTION_MAX[P]) 
              {
                I = MOVE_FRACTION_MAX[P];
              }
              BUG_MOVE_FRACTION[BUG_INDEX]  = I;
          		BUG_MOVE_DELAY[BUG_INDEX]  = BUG_MOVE_FRACTION[BUG_INDEX]  + PEEK(RANDOM) & 31;                        
          }
    	if (BUG_TYPE[BUG_INDEX]  == 1) // *** Beetle      
    	{
//   		BUG_XPOS[BUG_INDEX]  = 48 + rand()%152;
//  		BUG_YPOS[BUG_INDEX]  = 10;  
    		BUG_XDIR[BUG_INDEX] = (PEEK(RANDOM) & 2) - 1;
//  		POKE(PCOLR1 + BUG_INDEX,172);
    		I = 68 + Current_Level * 2;
    		if (I > 224)
    		{
    			I = 224;
    		}
    		BUG_MOVE_FRACTION[BUG_INDEX]  = I;
    		BUG_MOVE_DELAY[BUG_INDEX]  = I;
    		I = 2 + Current_Level / 4;
    		if (I > 4)
    		{
    			I = 4;
    		}
    		BUG_YDIR[BUG_INDEX]  = I;
    	}
    	else if (BUG_TYPE[BUG_INDEX]  == 2) // *** Flea
    	{
//  		BUG_XPOS[BUG_INDEX]  = 48 + rand()%152;
//  		BUG_YPOS[BUG_INDEX]  = 12;
    		BUG_XDIR[BUG_INDEX] = (PEEK(RANDOM) & 2) - 1;
//  		POKE(PCOLR1 + BUG_INDEX,80);
    		if (Current_Level < 5)
    		{
    		  I = 30 - Current_Level * 3;
    		}
    		else
    		{
    		  I = 28 - Current_Level * 2;
    		}
    		if (I < 5)
    		{
    			I = 5;
    		}
    		BUG_MOVE_FRACTION[BUG_INDEX]  = I;
    		BUG_MOVE_DELAY[BUG_INDEX]  = BUG_MOVE_FRACTION[BUG_INDEX]  + rand()%24;
    		BUG_YDIR[BUG_INDEX]  = 0;
    	}

    	else if (BUG_TYPE[BUG_INDEX]  == 3) // *** Ant
    	{
//   	BUG_XPOS[BUG_INDEX]  = 48 + rand()%152;
//   	BUG_YPOS[BUG_INDEX]  = 10;  
    		BUG_XDIR[BUG_INDEX] = (PEEK(RANDOM) & 2) - 1;
//    POKE(PCOLR1 + BUG_INDEX,56);
//  		I = 62 + Current_Level * 3;  
//  		if (I > 240)
//  		{                                    
//  			I = 240;
//  		}
//  		BUG_MOVE_FRACTION[BUG_INDEX]  = I;
//  		BUG_MOVE_DELAY[BUG_INDEX]  = I;
    		I = 3 + Current_Level;
    		if (I > 6)
    		{
    			I = 6;
    		}
    		BUG_YDIR[BUG_INDEX]  = I;
    	}
    	else if (BUG_TYPE[BUG_INDEX]  == 4) //** Termite
    	{
   //	BUG_XPOS[BUG_INDEX]  = 48 + rand()%152;
   //	BUG_YPOS[BUG_INDEX]  = 10;
    		BUG_XDIR[BUG_INDEX] = (PEEK(RANDOM) & 2) - 1;
   //	POKE(PCOLR1 + BUG_INDEX,104);  
    		I = 72 + Current_Level * 2;  
    		if (I > 240)
    		{
    			I = 240;                  
    		}
    		BUG_MOVE_FRACTION[BUG_INDEX]  = I;
    		BUG_MOVE_DELAY[BUG_INDEX]  = I;
    		I = 2 + Current_Level / 4;
    		if (I > 4)
    		{
    			I = 4;
    		}
    		BUG_YDIR[BUG_INDEX]  = I;
    	}
    	else if (BUG_TYPE[BUG_INDEX]  == 5) //** Bee'
    	{
        BUG_XDIR[BUG_INDEX] = (PEEK(RANDOM) & 2) - 1;
    		if (BUG_XDIR[BUG_INDEX]  == 1)
    		{
    		  BUG_XPOS[BUG_INDEX]  = 32;          
    		}
    		else                        
    		{
    		  BUG_XPOS[BUG_INDEX]  = 224;
    		}
    		BUG_YPOS[BUG_INDEX]  = 32 + rand()%128;
   //	POKE(PCOLR1 + BUG_INDEX,60);
//  		I = 80 + Current_Level * 3;  
//  		if (I > 255)
//  		{
//  			I = 255;
//  		}
//  		BUG_MOVE_FRACTION[BUG_INDEX]  = I;
//  		BUG_MOVE_DELAY[BUG_INDEX]  = I;
    	}
    	else if (BUG_TYPE[BUG_INDEX]  == 6) //** Roach
    	{
   /// BUG_XPOS[BUG_INDEX]  = 60 + rand()%128;
   //	BUG_YPOS[BUG_INDEX]  = 10;
   // 		POKE(PCOLR1 + BUG_INDEX,26);
//  		I = 60 + Current_Level * 4;  
//  		if (I > 240)
//  		{
//  			I = 240;
//  		}
//  		BUG_MOVE_FRACTION[BUG_INDEX]  = I;
//  		BUG_MOVE_DELAY[BUG_INDEX]  = I;
    	}
    	else if (BUG_TYPE[BUG_INDEX]  == 7) //** Fly
    	{
// 	    BUG_XPOS[BUG_INDEX]  = 54 + rand()%140;
//	    BUG_YPOS[BUG_INDEX]  = 10;
    		BUG_XDIR[BUG_INDEX]  = 3 + rand()%3;
//   	  POKE(PCOLR1 + BUG_INDEX,204);
//  		I = 54 + Current_Level * 3;
//  		if (I > 252)
//  		{
//  			I = 252;
//  		}
//  		BUG_MOVE_FRACTION[BUG_INDEX]  = I;
//  		BUG_MOVE_DELAY[BUG_INDEX]  = I;
    	}
      else if (BUG_TYPE[BUG_INDEX]  == 8) //** Mosquito  
    	{
//    	BUG_XPOS[BUG_INDEX]  = 56 + rand()%136;
//  		BUG_YPOS[BUG_INDEX]  = 10;
    		BUG_XDIR[BUG_INDEX]  = 0; //rand()%3 - 1;
//  		POKE(PCOLR1 + BUG_INDEX,124);
//  		I = 30 + Current_Level * 3;                    
//  		if (I > 246)
//  		{
//  			I = 246;
//  		}
//  		BUG_MOVE_FRACTION[BUG_INDEX]  = I;
//  		BUG_MOVE_DELAY[BUG_INDEX]  = I;
    	}                       
  }
//------------------------------
void BUG_GOT_PASSED(void)
  {
     Lives = Lives - 1;    
    if (Lives > 250) 
        {
        Exit_Flag = 3;                       
        }
    else
        {
        START_SOUND(1,1);
        BUG_TYPE[BUG_INDEX] = 14;
        BUG_XDIR[BUG_INDEX] = 15;
        PRINT_SCORE();
        BUG_YPOS[BUG_INDEX] = 198;
        POKE(PCOLR1+BUG_INDEX,15);
        }    
  }
//------------------------------
void BUG_TYPE_BEETLE(void)
    {
    	  BUG_MOVE_DELAY[BUG_INDEX] += BUG_MOVE_FRACTION[BUG_INDEX];
        BUG_X_MOVE = BUG_XDIR[BUG_INDEX];
    	  if (BUG_MOVE_DELAY[BUG_INDEX] > 256)
    	  {
    		  BUG_X_MOVE += BUG_XDIR[BUG_INDEX]; 
    		  BUG_MOVE_DELAY[BUG_INDEX] = 0;
    	  }
    		BUG_XPOS[BUG_INDEX] = BUG_XPOS[BUG_INDEX] + BUG_X_MOVE;
    	  if (BUG_XPOS[BUG_INDEX] < 48)
    	  {
      		BUG_XPOS[BUG_INDEX] = 48;
      		BUG_XDIR[BUG_INDEX] = 1;
      		BUG_YPOS[BUG_INDEX] += BUG_YDIR[BUG_INDEX];
    	  }
    	  if (BUG_XPOS[BUG_INDEX] > 200)
    	  {
      		BUG_XPOS[BUG_INDEX] = 200;
      		BUG_XDIR[BUG_INDEX] = -1; 
      		BUG_YPOS[BUG_INDEX] += BUG_YDIR[BUG_INDEX];
    	  }
	      if (BUG_XDIR[BUG_INDEX] > 127)
    	  {
    		  N = &P004 + SPRITE_2FRAME;
    	  }                        
    	  else
    	  {
    		  N = &P002 + SPRITE_2FRAME;
    	  } 
        PMMOVE(2 + BUG_INDEX,N,12,BUG_XPOS[BUG_INDEX],24 + BUG_YPOS[BUG_INDEX]);                     
    }
//------------------------------
void BUG_TYPE_FLEA(void)
{
	  if (BUG_MOVE_DELAY[BUG_INDEX] > 0 && BUG_YDIR[BUG_INDEX] == 0)
	  {
		  BUG_MOVE_DELAY[BUG_INDEX] -= 1;
		  if (BUG_MOVE_DELAY[BUG_INDEX] == 0)
		  {
			 BUG_YDIR[BUG_INDEX] = 250;
       P = (PEEK(RANDOM) & 3);
//      gotoxy(12 + BUG_INDEX * 2,0);
//      printf("%u\n",P);
			 if (P == 0)
			 {
				 BUG_XDIR[BUG_INDEX] = (PEEK(RANDOM) & 2) - 1;
			 }
		  }
	  if (BUG_XDIR[BUG_INDEX] > 127)
    	  {
    		  N = &P006;
    	  }
    	  else
    	  {
    		  N = &P008;
    	  }              
	  }
	  else if (BUG_MOVE_DELAY[BUG_INDEX] == 0)
	  {
		  BUG_MOVE_DELAY[BUG_INDEX] = 0;
		  BUG_XPOS[BUG_INDEX] +=  BUG_XDIR[BUG_INDEX];
      P =  (BUG_YDIR[BUG_INDEX] & 1);
      if (P == 0 && BUG_YPOS[BUG_INDEX] > 2)
        {
        BUG_YPOS[BUG_INDEX] = BUG_YPOS[BUG_INDEX] + (BUG_YDIR[BUG_INDEX]);  
        }             
      else if (BUG_YPOS[BUG_INDEX] < 4)
        {
          BUG_YPOS[BUG_INDEX] += 2;            
        } 
		  BUG_YDIR[BUG_INDEX] = BUG_YDIR[BUG_INDEX] + 1;
		  if (BUG_XPOS[BUG_INDEX] < 48)
		  {
			BUG_XPOS[BUG_INDEX] = 48;
			BUG_XDIR[BUG_INDEX] = 1;
			BUG_YPOS[BUG_INDEX] += 1;
		  }
		  if (BUG_XPOS[BUG_INDEX] > 200)
		  {
			BUG_XPOS[BUG_INDEX] = 200;
			BUG_XDIR[BUG_INDEX] = 255;
			BUG_YPOS[BUG_INDEX] += 1;
		  }

		  if (BUG_YDIR[BUG_INDEX] >= 9 && BUG_YDIR[BUG_INDEX] < 16)
		  {
			  BUG_YDIR[BUG_INDEX] = 0;
        P = (PEEK(RANDOM) & 15);
			  BUG_MOVE_DELAY[BUG_INDEX] += P;
		  }
  	  if (BUG_XDIR[BUG_INDEX] > 127)
  	  {
  		  PMMOVE(2 + BUG_INDEX,&P007,12,BUG_XPOS[BUG_INDEX],24 + BUG_YPOS[BUG_INDEX]);
  	  }
  	  else
  	  {
  		  PMMOVE(2 + BUG_INDEX,&P009,12,BUG_XPOS[BUG_INDEX],24 + BUG_YPOS[BUG_INDEX]);
  	  }
	  if (BUG_XDIR[BUG_INDEX] > 127)
    	  {
    		  N = &P007;
    	  }
    	  else
    	  {
    		  N = &P009;
    	  }              
	  }
    PMMOVE(2 + BUG_INDEX,N,12,BUG_XPOS[BUG_INDEX],24 + BUG_YPOS[BUG_INDEX]);
}
//------------------------------                     
void BUG_TYPE_RED_ANT(void)
{
	  BUG_MOVE_DELAY[BUG_INDEX] += BUG_MOVE_FRACTION[BUG_INDEX];
    BUG_X_MOVE = BUG_XDIR[BUG_INDEX];
	  if (BUG_MOVE_DELAY[BUG_INDEX] > 256)
	  {
		  BUG_X_MOVE += BUG_XDIR[BUG_INDEX];
		  BUG_MOVE_DELAY[BUG_INDEX] = 0;
	  }
		BUG_XPOS[BUG_INDEX] = BUG_XPOS[BUG_INDEX] + BUG_X_MOVE;
	  if (BUG_XPOS[BUG_INDEX] < 48)
	  {
		BUG_XPOS[BUG_INDEX] = 48;
		BUG_XDIR[BUG_INDEX] = 1;
		BUG_YPOS[BUG_INDEX] += BUG_YDIR[BUG_INDEX];
	  }
	  if (BUG_XPOS[BUG_INDEX] > 200)
	  {
		BUG_XPOS[BUG_INDEX] = 200;
		BUG_XDIR[BUG_INDEX] = -1;
		BUG_YPOS[BUG_INDEX] = BUG_YPOS[BUG_INDEX] + BUG_YDIR[BUG_INDEX];
	  }
		  P = (GET_SCREEN_BYTE(BUG_XPOS[BUG_INDEX],BUG_YPOS[BUG_INDEX]));
//    gotoxy(10 ,2 + BUG_INDEX);
//    printf("%u    \n",N);   
		 if (P > 0)
		 {
		   BUG_XPOS[BUG_INDEX] = BUG_XPOS[BUG_INDEX] - BUG_XDIR[BUG_INDEX];
		   BUG_XDIR[BUG_INDEX] = - BUG_XDIR[BUG_INDEX];
		   P = (PEEK(RANDOM) & 3);
       if (P == 0)
		   {
			 if (BUG_YPOS[BUG_INDEX] > 2)
			 {
				 BUG_YPOS[BUG_INDEX] = BUG_YPOS[BUG_INDEX] - 1;
			 }
		   }
		   else
		   {
			 BUG_YPOS[BUG_INDEX] = BUG_YPOS[BUG_INDEX] + BUG_YDIR[BUG_INDEX];
		   }
		 }

	  if (BUG_XDIR[BUG_INDEX] > 127)
    	  {
    		  N = &P012 + SPRITE_2FRAME;
    	  }
    	  else
    	  {
    		  N = &P010 + SPRITE_2FRAME;
    	  }
    PMMOVE(2 + BUG_INDEX,N,12,BUG_XPOS[BUG_INDEX],24 + BUG_YPOS[BUG_INDEX]);
}
//------------------------------                     
void BUG_TYPE_TERMITE(void)
{
	  BUG_MOVE_DELAY[BUG_INDEX] += BUG_MOVE_FRACTION[BUG_INDEX];
    BUG_X_MOVE = BUG_XDIR[BUG_INDEX];
	  if (BUG_MOVE_DELAY[BUG_INDEX] > 256)
	  {
		  BUG_X_MOVE = BUG_X_MOVE + BUG_XDIR[BUG_INDEX];
		  BUG_MOVE_DELAY[BUG_INDEX] = 0;
	  }
		BUG_XPOS[BUG_INDEX] = BUG_XPOS[BUG_INDEX] + BUG_X_MOVE;
    if ((PEEK(RANDOM) & 15) < 7)
      {
        P = (GET_SCREEN_BYTE(BUG_XPOS[BUG_INDEX],BUG_YPOS[BUG_INDEX]));
        if (P > 0)
        {
        	if ((PEEK(RANDOM) & 2) == 2)
        	{
        		BUG_XPOS[BUG_INDEX] = BUG_XPOS[BUG_INDEX] - BUG_XDIR[BUG_INDEX];
        	}
        	if (BUG_YPOS[BUG_INDEX] > 2)
        	{
        		BUG_YPOS[BUG_INDEX] = BUG_YPOS[BUG_INDEX] - 1 - (PEEK(RANDOM) & 1);
        	}
        }
        else
        {
        	I = 2 + (PEEK(RANDOM) & 3);
        	if (BUG_XPOS[BUG_INDEX] + 3 > 0)
        	{
        		BUG_YPOS[BUG_INDEX] = BUG_YPOS[BUG_INDEX] + rand()%I;
        	}
        }
      }
	  if (BUG_XPOS[BUG_INDEX] < 48)
	  {
		BUG_XPOS[BUG_INDEX] = 48;
		BUG_XDIR[BUG_INDEX] = 1;
	  }
	  if (BUG_XPOS[BUG_INDEX] > 200)
	  {
		BUG_XPOS[BUG_INDEX] = 200;
		BUG_XDIR[BUG_INDEX] = -1;
	  }
	  if (BUG_XDIR[BUG_INDEX] > 127)
    {
      N = &P014 + SPRITE_2FRAME;
    }
  	else
    {
      N = &P016 + SPRITE_2FRAME;
    }
    PMMOVE(2 + BUG_INDEX,N,12,BUG_XPOS[BUG_INDEX],24 + BUG_YPOS[BUG_INDEX]);
}      
//------------------------------                     
void BUG_TYPE_BEE(void)
  {
    BUG_X_MOVE = BUG_XDIR[BUG_INDEX];
    BUG_MOVE_DELAY[BUG_INDEX] += BUG_MOVE_FRACTION[BUG_INDEX];
	  if (BUG_MOVE_DELAY[BUG_INDEX] > 256)
	  {
		  BUG_X_MOVE = BUG_X_MOVE + BUG_XDIR[BUG_INDEX];
		  BUG_MOVE_DELAY[BUG_INDEX] = 0;
	  }
  	BUG_XPOS[BUG_INDEX] = BUG_XPOS[BUG_INDEX] + BUG_X_MOVE;
	  if (BUG_XPOS[BUG_INDEX] < 28 || BUG_XPOS[BUG_INDEX] > 228)
	  {
		  POKE(HPOSP1 + BUG_INDEX,0);
		  BUG_TYPE[BUG_INDEX] = 0;
	  }
	  else
	  {
		  BUG_YDIR[BUG_INDEX] = rand()%3 - 1;
		  BUG_YPOS[BUG_INDEX] = BUG_YPOS[BUG_INDEX] + BUG_YDIR[BUG_INDEX];
		  if (BUG_YPOS[BUG_INDEX] < 20)
		  {
			  BUG_YPOS[BUG_INDEX] = 20;
		  }
		  if (BUG_YPOS[BUG_INDEX] > 156)
		  {
			  BUG_YPOS[BUG_INDEX] = 156;
		  }
  	}
	  if (BUG_XDIR[BUG_INDEX] > 127)
    {      
      N = &P046 + SPRITE_2FRAME;
    }
  	else
    {
      N = &P044 + SPRITE_2FRAME;
    }
    PMMOVE(2 + BUG_INDEX,N,12,BUG_XPOS[BUG_INDEX],24 + BUG_YPOS[BUG_INDEX]);
  }
//------------------------------                     
void BUG_TYPE_ROACH(void)
  {
  	  BUG_MOVE_DELAY[BUG_INDEX] += BUG_MOVE_FRACTION[BUG_INDEX];
      if (BUG_MOVE_DELAY[BUG_INDEX] > 256)
      {
       BUG_MOVE_DELAY[BUG_INDEX] = 0;
       J = 2;
      }
      else
      {
       J = 1;
      }
      BUG_YPOS[BUG_INDEX] += J;
  	 if (PEEK(RANDOM) > 127)
  	 {
  	   BUG_X_MOVE = rand()%3 - 1;
  	   BUG_XPOS[BUG_INDEX] = BUG_XPOS[BUG_INDEX] + BUG_X_MOVE;
  	 }
  	 if (BUG_XPOS[BUG_INDEX] < 48)
  	 {
  	   BUG_XPOS[BUG_INDEX] = 48;
  	 }
  	 if (BUG_XPOS[BUG_INDEX] > 200)
  	 {
  	   BUG_XPOS[BUG_INDEX] = 200;
  	 }
  	 PMMOVE(2 + BUG_INDEX,&P018 + SPRITE_2FRAME,12,BUG_XPOS[BUG_INDEX],24 + BUG_YPOS[BUG_INDEX]);
  }   
//------------------------------                     
void BUG_TYPE_FLY(void)
  {
    BUG_MOVE_DELAY[BUG_INDEX] += BUG_MOVE_FRACTION[BUG_INDEX];
    I = BUG_XDIR[BUG_INDEX];
    if (BUG_MOVE_DELAY[BUG_INDEX] > 256)
    {
      I = BUG_XDIR[BUG_INDEX]+8;
      BUG_MOVE_DELAY[BUG_INDEX] = 0;
    }
    else
    {
      I = BUG_XDIR[BUG_INDEX];
    }
    BUG_XPOS[BUG_INDEX] += DIR_X_ADD[I];
    BUG_YPOS[BUG_INDEX] += DIR_Y_ADD[I];
    PMMOVE(2 + BUG_INDEX,&P022 + SPRITE_2FRAME+24 * BUG_XDIR[BUG_INDEX], 12,BUG_XPOS[BUG_INDEX], 24 + BUG_YPOS[BUG_INDEX]);
    if (SPRITE_2FRAME == 0)
    {
    BUG_XDIR[BUG_INDEX] = (BUG_XDIR[BUG_INDEX] + BUG_YDIR[BUG_INDEX]) & 7;
    }
    else
    {
      I = BUG_XDIR[BUG_INDEX];
      if (I == 0)
      {
      	  if (BUG_YDIR[BUG_INDEX] == 0)
      	  {
      		  BUG_YDIR[BUG_INDEX] = (PEEK(RANDOM)&2)-1;
      	  }
      }
      else
      {
      	  if (BUG_YPOS[BUG_INDEX] < 5)
      	  {
            BUG_YPOS[BUG_INDEX] = BUG_YPOS[BUG_INDEX] + 1;
            if (I == 0)
            {
              BUG_XDIR[BUG_INDEX] = 4;
              BUG_YDIR[BUG_INDEX] = 0;
            }
      		  else if (I > 4)
      		  {
      			  BUG_YDIR[BUG_INDEX] = 255;
      		  }
            else if (I < 4)
            {
      			  BUG_YDIR[BUG_INDEX] = 1;
      		  }
            else
            {
      			  BUG_YDIR[BUG_INDEX] = 0;
      		  }                                   
      	  }
      	  else if (BUG_XPOS[BUG_INDEX] < 56)
      	  {
      		  if (I == 6)
      		  {
      			BUG_YDIR[BUG_INDEX] = (PEEK(RANDOM) & 2)-1;
      		  }
      		  else if (I == 7)
      		  {
      			BUG_YDIR[BUG_INDEX] = 1;
      		  }
      		  else if (I == 5)
      		  {
      			BUG_YDIR[BUG_INDEX] = 255;
      		  }
      	  }
      	  else if (BUG_XPOS[BUG_INDEX] > 191)
      	  {
      		  if (I == 2)
      		  {
      			BUG_YDIR[BUG_INDEX] = (PEEK(RANDOM) & 2)-1;
      		  }
      		  else if (I == 3)
      		  {
      			BUG_YDIR[BUG_INDEX] = 1;
      		  }
      		  else if (I == 1)
      		  {
      			BUG_YDIR[BUG_INDEX] = 255;
      		  }
      	  }
      	  else 
      	  {
      		  if ((PEEK(RANDOM) & 3) == 0)
      		  {
      			  if (BUG_YDIR[BUG_INDEX] == 0)
      			  {
      				  BUG_YDIR[BUG_INDEX] = (PEEK(RANDOM) & 2)-1;
      			  }
      		  }
      		  else
      		  {
      			  BUG_YDIR[BUG_INDEX] = 0;
      		  }
      	  }          
        }
      }
   }  
//------------------------------                     
void BUG_TYPE_MOSQUITO(void)
  {
	  BUG_MOVE_DELAY[BUG_INDEX] += BUG_MOVE_FRACTION[BUG_INDEX];
    BUG_X_MOVE = BUG_XDIR[BUG_INDEX];
	  if (BUG_MOVE_DELAY[BUG_INDEX] > 256)
	  {
		  BUG_X_MOVE += BUG_XDIR[BUG_INDEX];
		  BUG_MOVE_DELAY[BUG_INDEX] = 0;
      J = 2;
	  }
	  else
	  {
      J = 1;   
	  }
	  BUG_XPOS[BUG_INDEX] += BUG_XDIR[BUG_INDEX];
	  BUG_YPOS[BUG_INDEX] += J;                      
    if (BUG_XPOS[BUG_INDEX] < 48)
    {
  	BUG_XPOS[BUG_INDEX] = 48;
		BUG_XDIR[BUG_INDEX] = 1;
    }
    if (BUG_XPOS[BUG_INDEX] > 200)
    {
    BUG_XPOS[BUG_INDEX] = 200;
		BUG_XDIR[BUG_INDEX] = 255;
    }
	  if (SPRITE_2FRAME == 0 && PEEK(RANDOM)<16)
	  {
		   BUG_XDIR[BUG_INDEX] = rand()%3 - 1;
	  }                               
	  if (BUG_XDIR[BUG_INDEX] == 0)
    {
      N = &P040 + SPRITE_2FRAME;
    }
  	else if (BUG_XDIR[BUG_INDEX] == 1)
    {
      N = &P042 + SPRITE_2FRAME;
    }
  	else if (BUG_XDIR[BUG_INDEX] == 255)
    {
      N = &P038 + SPRITE_2FRAME;
    }
    PMMOVE(2 + BUG_INDEX,N,12,BUG_XPOS[BUG_INDEX],24 + BUG_YPOS[BUG_INDEX]);
  }
//------------------------------                     
void BUG_TYPE_INCH_WORM(void)
    {
//  BUG_MOVE_DELAY[BUG_INDEX] = BUG_MOVE_DELAY[BUG_INDEX] + BUG_MOVE_FRACTION[BUG_INDEX];
    
    }
//------------------------------                     
void BUG_TYPE_HORNET(void)
    {
//  BUG_MOVE_DELAY[BUG_INDEX] = BUG_MOVE_DELAY[BUG_INDEX] + BUG_MOVE_FRACTION[BUG_INDEX];
    
    }
//------------------------------                     
void BUG_PASSED_EFFECT(void)
    {
        BUG_XDIR[BUG_INDEX] = BUG_XDIR[BUG_INDEX] - 1;
        if (BUG_XDIR[BUG_INDEX] > 250)
          {
            PMMOVE(2 + BUG_INDEX,&PMBANK+528,12,BUG_XPOS[BUG_INDEX],24 + BUG_YPOS[BUG_INDEX]);
            BUG_XPOS[BUG_INDEX] = 0;
            BUG_YPOS[BUG_INDEX] = 0;
            BUG_TYPE[BUG_INDEX] = 0;
          }               
        POKE (PCOLR1+BUG_INDEX,BUG_XDIR[BUG_INDEX]);
    }
//------------------------------
void BUG_DIE(void)
    {
        BUG_XDIR[BUG_INDEX] = BUG_XDIR[BUG_INDEX] + 1;
        POKE (PCOLR1 + BUG_INDEX, BUG_DIE_COLOR[BUG_INDEX]);
        PMMOVE(2 + BUG_INDEX,&P056 + BUG_XDIR[BUG_INDEX] * 12 ,12,BUG_XPOS[BUG_INDEX],24 + BUG_YPOS[BUG_INDEX]);
        if (BUG_XDIR[BUG_INDEX] >= 7)
          {            
            PMMOVE(2 + BUG_INDEX,&PMBANK+528,12,BUG_XPOS[BUG_INDEX],24 + BUG_YPOS[BUG_INDEX]);
            BUG_XPOS[BUG_INDEX] = 0;
            BUG_YPOS[BUG_INDEX] = 0;
            BUG_TYPE[BUG_INDEX] = 0;                    
          }
    }
//------------------------------                     
void DRAW_FIELD(void)
{
    POKE(NMIEN,0);
    POKEW(VDSLST,&GAME00_DLI);
    POKE(COLOR0,16);  
    POKE(COLOR1,66);
    POKE(COLOR2,60);
    POKE(COLOR3,156);
    POKE(COLOR4,224);    
		memset(&GAME_SCREEN_ADDR, 0, 1040);
//   for( i = 10; i < 255; i = i + 1 ){
    P = 0;
    SCR_ADDR = &GAME_SCREEN_ADDR;
    for(N = SCR_ADDR + 120; N <= (SCR_ADDR + 880); N += 40)
    {
			for(M = 0;M <= 2;M++) 
			{
				X = rand()%40;
				Y = rand()%(2+P);
					if (Y == 0)
					{
						DRAW_PIECE_0();
					}
					else if (Y == 1)
					{
						DRAW_PIECE_1();
					}
					else if (Y == 2)
					{
						DRAW_PIECE_2();
					}
			}
      P = 1;
  }
  
    if (Current_Level < 9)
        {
        Bugs_Remaining = 10;
        Add_New_Bug_CountDown = 24;
        Add_New_Bug_Reset = 24;
        }
    else if (Current_Level < 17)
        {
        Bugs_Remaining = 12;
        Add_New_Bug_CountDown = 20;
        Add_New_Bug_Reset = 22;
        }
    else if (Current_Level < 25)
        {
        Bugs_Remaining = 14;
        Add_New_Bug_CountDown = 16;
        Add_New_Bug_Reset = 20;
        }
    else  
        {
        Bugs_Remaining = 16;   
        Add_New_Bug_CountDown = 12;
        Add_New_Bug_Reset = 18;                   
        }

    for (BUG_INDEX = 0; BUG_INDEX <= 2; BUG_INDEX++)
      {
    		DEFINE_NEW_BUG();
    	}  
    POKE(SDMCTL,62);
    POKE(NMIEN,192);      
  }
//------------------------------

void DISPLAY_GAME_OVER(void)
{
    SILENCE();
    START_SOUND(6,1);
  	for (N = 0; N <= 128; N++)
  	{
    T = PEEK(20);
    while (PEEK(20)==T) {};
    P = (PEEK(20) & 15);
    gotoxy(12,12);
    if (P == 14)  
      {
          printf ("                  \n");           
      }
    else if (P == 6)
      {        
          printf ("G A M E    O V E R\n");           
      }
  	}  
    POKE (NMIEN,0);
    I = 11;
    HiScore_Place = 99;

     while (I > 0)
     {
        if(Score > hiscore[I])
        {
          HiScore_Place=I;                
        }
     I -= 1;
     }
     if (HiScore_Place < 5)
     {
      I = 5;  
      do
      {
        hiscore[I] = hiscore[I - 1];
        I -= 1;    
      }
      while (I != HiScore_Place);
      hiscore[HiScore_Place] = Score;
     }  
     SILENCE();  
}
//------------------------------
void Game_Loop(void)
{
    do
    {    
         		memset(&SCREEN_ADDR, 0, 1024);
     		    DRAW_FIELD();            
//***    			// Set the Defaults for the Shooter'
       			POKE (PCOLR0,30);
        		memset(&PMBANK+768,0,1280);
            memset(&PMBANK+512,3,16);
            memset(&PMBANK+528,0,48);
       			shooter_px = 124;
            shooter_py = 197;
            BULLET_SPEED = 8;
            BULLET_SCREEN_SUB = 40;
            SILENCE();
        		PRINT_SCORE();
       			Exit_Flag = 0;
            T = PEEK(20);
        		//*** Main Game Loop Begins here'
         			do
              {
                  while (T == PEEK(20)) {};
                  T = PEEK(20);
                  MOVE_SHOOTER();
                  PMMOVE(1,&P000,12,shooter_px,shooter_py);                 
//***    					O = !O;
                 	SPRITE_2FRAME = 12 - SPRITE_2FRAME;
         					for (BUG_INDEX = 0; BUG_INDEX <= 2; BUG_INDEX++)
           			    {
          				  //Use Block to Branch to programming for differnent bug types.
                  	  if (BUG_YPOS[BUG_INDEX] > 200 && BUG_TYPE[BUG_INDEX] >= 1 && BUG_TYPE[BUG_INDEX] < 12)
                  	  {
                  		  BUG_GOT_PASSED();
                  	  }
                      if (BUG_TYPE[BUG_INDEX] == 1)
              			  {
           							BUG_TYPE_BEETLE();
            				  }
                		  else if (BUG_TYPE[BUG_INDEX] == 2)
           					  {
           							BUG_TYPE_FLEA();
           					  }
           					  else if (BUG_TYPE[BUG_INDEX] == 3)
           					  {
           							BUG_TYPE_RED_ANT();
           					  }
           					  else if (BUG_TYPE[BUG_INDEX] == 4)
            				  {
           							BUG_TYPE_TERMITE();
           					  }
            				  else if (BUG_TYPE[BUG_INDEX] == 5)
            				  {
           							BUG_TYPE_BEE();
                		  }
                		  else if (BUG_TYPE[BUG_INDEX] == 6)
                		  {
           							BUG_TYPE_ROACH();
           					  }
            				  else if (BUG_TYPE[BUG_INDEX] == 7)
              			  {
           							BUG_TYPE_FLY();
           					  }
           					  else if (BUG_TYPE[BUG_INDEX] == 8)
           					  {
           							BUG_TYPE_MOSQUITO();
           					  }
                      else if (BUG_TYPE[BUG_INDEX] == 9)
           					  {
           							BUG_TYPE_INCH_WORM();
           					  }                    
                      else if (BUG_TYPE[BUG_INDEX] == 10)
           					  {
           							BUG_TYPE_HORNET();
           					  }                                        
           					  else if (BUG_TYPE[BUG_INDEX] == 14)
                      {
                        BUG_PASSED_EFFECT();                      
                      }                       
                      else if (BUG_TYPE[BUG_INDEX] == 15)
           					  {
           							BUG_DIE();
           					  }
                  }    
         					//Bullet Status. 0 = Not on screen. 1 in Motion 
         					if (BULLET_STATUS == 0)
         					{
         						if (PEEK(TRIG0) == 0)
         						{
                    SET_BULLET();
          						//Start the Bullet at the shooter
//       							BULLET_STATUS = 1;
//          	  			BULLET_X_POS = shooter_px + 3;
//          					U = &GAME_SCREEN_ADDR + ((shooter_px - 46) / 4);
//       							BULLET_Y_POS = shooter_py - 29;
//                    BULLET_SCREEN_LOC = U  + ((shooter_py - 29) / 8) * 40; 
                      START_SOUND(0,1);
//       							POKE (53252,BULLET_X_POS);
//                		memcpy(&PMBANK + 792 + BULLET_Y_POS, &PMBANK+520,16);
            					POKE (77,0);
            				}
          				}
         					else
         					{
//       						BULLET_Y_POS -= 8;
//       						if (BULLET_Y_POS < 8)
//       						{
//            				BULLET_STATUS = 0;
//       							memcpy(&PMBANK + 792 + BULLET_Y_POS, &PMBANK+528,32);
//       						}
//        					else
//        					{
//                    POKE (53252,BULLET_X_POS);
//       							memcpy(&PMBANK + 792 + BULLET_Y_POS, &PMBANK+520,16);
         							if (BULLET_HIT1 > 0)
                				{
                        BULLET_PLAYFIELD();
                        }                         
         							if (PEEK(M0PL) > 0)
         							{
         								BULLET_HIT_BUG();
                      }
                 	  }
//       					}
          				Add_New_Bug_CountDown -= 1;
          				if (Add_New_Bug_CountDown > 250)
          				{
            		  Add_New_Bug_CountDown = Add_New_Bug_Reset;
         					}
          				else if (Add_New_Bug_CountDown < 3)
         					{
            				if (BUG_TYPE[Add_New_Bug_CountDown] == 0)
         						{
          					  BUG_INDEX = Add_New_Bug_CountDown;
              			  DEFINE_NEW_BUG();
         						  Add_New_Bug_CountDown = 0;
          					}
         					}
              } while (Exit_Flag == 0);
              if (Exit_Flag == 1)
                {
                  if (Current_Level < 40)
                  {
                    Current_Level = Current_Level + 1; 
                  }
                  START_SOUND(7,1);                
                }                  
  		} while ( Exit_Flag <= 1 );
      
  	  if (Exit_Flag == 3);
  	  {
  			 DISPLAY_GAME_OVER();
  	  }
}



//{***************************************************************************************}
//{************************************** MAIN *******************************************}
//{***************************************************************************************}

void main(void)
  {
// TOP LOGIC LOOP'
		POKEW (SAVMSC,&SCREEN_ADDR); 	   
    Current_Level = 0;
		POKE (0xD301,PEEK(0xD301)|2); //Disable Internal Basic
		POKE (PMBASE,&PMBANK_HI);
		POKE (GRACTL,3);
		POKE (623,1);
    memset(&SCREEN_ADDR, 0, 1024);
		HiScore_Place = 99;
		//Begin the Top Logic Loop
    while (1)
        {
    		DISPLAY_TITLE();  
     	  BUG_INDEX = 0;  
        POKEW(DLISTW,&DISPLAY_LIST_GAME); 	 
        POKEW(SDLSTW,&DISPLAY_LIST_GAME); 
        POKE(CHBAS,&CHARSET_TITLE_HI);   
        POKEW(VVBLKD,&GAME_VBI);
        Current_Level = 1;
    		memset(&PMBANK+768,0,1280);
        memset(&PMBANK+512,3,16);
        memset(&PMBANK+528,0,32);
        Next_Extra_Life_Score = 1000;
        Score = 0;
        Lives = 7;
        PRINT_SCORE();
//      BULLET_X_POS = 248;
//      BULLET_Y_POS = 224;
//      while (BULLET_X_POS > 8)
//        {
//          BULLET_Y_POS = BULLET_Y_POS - 16;              
//          memcpy(&PMBANK + 768 + BULLET_Y_POS, &PMBANK+512,32);
//          if(BULLET_Y_POS==224)
//            {
//              BULLET_X_POS = BULLET_X_POS - 1;
//            }
//            POKE(HPOSM0,BULLET_X_POS);
//            PMMOVE(1,&P000,12,BULLET_X_POS+24,BULLET_Y_POS);        
//        } 
//        N=P000;
//        memset(PMBANK, 255, 2048);
           
//      sleep(5);
         Game_Loop();    
        }
   }
