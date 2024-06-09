#include<windows.h>

#define Black         1
#define DarkBlue      2
#define DarkGreen     3
#define DarkCyanBlue  4
#define DarkRed       5
#define DarkPurple    6
#define Brown         7
#define LightGrey     8
#define DarkGrey      9
#define Blue          10
#define Green         11
#define CyanBlue      12
#define Red           13
#define Purple        14
#define Yellow        15
#define White         16

#define C_W Color_Set(White,White);cout
#define C_B Color_Set(Black,Black);cout
#define C_b Color_Set(Blue,Blue);cout
#define C_p Color_Set(Purple,Purple);cout
#define C_r Color_Set(Red,Red);cout
#define C_y Color_Set(Yellow,Yellow);cout
#define C_c Color_Set(DarkCyanBlue,DarkCyanBlue);cout

/*
a ±³¾°É« 
b ±³¾°É« 
*/
void Color_Set(int a,int b){
	int x=a*16+b-17;
	if(x==0)
		x=256;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	}
void Color_Clear(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4+2+1);
	}

