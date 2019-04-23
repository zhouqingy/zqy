#include <reg51.h>
#include <stdio.h>
#include <absacc.h>
#define SEG XBYTE[0x8004]
#define DIGIT XBYTE[0x8002]
#define KEYIN XBYTE[0x8001]


typedef unsigned int u16;	  
typedef unsigned char u8;

u8 code smgduan[25]={0x40,0x40,0x5e,0x79,0x71,0x3f,
	                   0x40,0x40,0x39,0x4f,0x5b,0x06,
	                   0x40,0x40,0x7c,0x7d,0x6d,0x66,
	                   0x40,0x40,0x77,0x6f,0x7f,0x07,0xff};
u8 light[6]={0x3f,0x3f,0x3f,0x3f,0x3f,0x3f};		

u8 KeyValue=50;

u8 check=0;

u8 num1,num2,way,left1=0,left2=0;

u16 looptime=100; 

char now=0;

sbit p10=P1^0;
sbit p11=P1^1;
sbit p12=P1^2;
sbit p13=P1^3;
sbit p14=P1^4;
sbit p15=P1^5;
sbit p16=P1^6;
sbit p17=P1^7;
sbit p32=P3^2;
int ind=0;
			
u8 numchange(u8 index)
{
	u8 re=55; 
	switch(index)
	{
		case(0):re=55;break;case(1):re=55;break; case(2):re=13;break;
		case(3):re=14;break;case(4):re=15;break;;case(5):re=0;break;
		case(6):re=55;break;case(7):re=55;break;case(8):re=12;break;
		case(9):re=3;break;case(10):re=2;break;case(11):re=1;break;
		case(12):re=55;break;case(13):re=55;break;case(14):re=11;break;
		case(15):re=6;break;case(16):re=5;break;case(17):re=4;break;
		case(18):re=55;break;case(19):re=55;break;case(20):re=10;break;
		case(21):re=9;break;case(22):re=8;break;case(23):re=7;break;
	}
	return re;
}

void delay(u16 i)
{
	int j=10;
	for(;j>0;j--)
	{for(;i>0;i--);}
}

u8 cnum(u8 index)
{
	u8 re=55; 
	switch(index)
	{
		case(55):re=55;break; case(13):re=2;break;
		case(14):re=3;break;case(15):re=4;break;;case(0):re=5;break;
		case(12):re=8;break;
		case(3):re=9;break;case(2):re=10;break;case(1):re=11;break;
		case(11):re=14;break;
		case(6):re=15;break;case(5):re=16;break;case(4):re=17;break;
		case(10):re=20;break;
		case(9):re=21;break;case(8):re=22;break;case(7):re=23;break;
	}
	return re;
	}

void DigDisplay()
{
	char i;
	for(i=0;i<6;i++)
	{
		switch(i)
		{
			case(0):
				DIGIT=0x01;SEG=light[0]; break;
			case(1):
				DIGIT=0x02;SEG=light[1]; break;
			case(2):
				DIGIT=0x04;SEG=light[2]; break;
			case(3):
				DIGIT=0x08;SEG=light[3]; break;
			case(4):
				DIGIT=0x10;SEG=light[4]; break;
			case(5):
				DIGIT=0x20;SEG=light[5]; break;
		}
		delay(10); 
		SEG=0x00;
	}
}

void error()
{
	int i=0;
	for(;i<6;i++)
	{
		light[i]=0x40;
	}
	while(1)
		DigDisplay();
}



void timer() interrupt 1
{ 
	TH0=0xed;TL0=0xff;
	check++;
	if(check>looptime)
	{
		now++;
		if(now<8)
		light[0]=smgduan[cnum(now)];
		else
		{
			light[0]=smgduan[24];
			if(ind<8)
			{
				switch(ind)
				{	case(0):p10=1;break;
				case(1):p11=1;break;
				case(2):p12=1;break;
				case(3):p13=1;break;
				case(4):p14=1;break;
				case(5):p15=1;break;
				case(6):p16=1;break;
				case(7):p17=1;break;
				}
				ind++;
			}
			else
			{
				ind=1;
				p10=1;p11=0;p12=0;p13=0;
				p14=0;p15=0;p16=0;p17=0;
			}
			now=-1;
			left2++;
			if(left2<=9)
			{
				light[1]=smgduan[cnum(left2)];
			}
			else
			{
				left1++;
				left2=0;
				light[1]=smgduan[cnum(left2)];
				light[2]=smgduan[cnum(left1)];
			}
			
		}
		check=0;
	}
}

void init()
{
	TMOD = 0x01;
	TH0=0xed;TL0=0xff;
	ET0=1;TR0=1;EA=1;
}

int i=0;
u8 ccc=0x3e;
void KeyDown()
{                       
	DIGIT=0x3e;
	KeyValue=50;
			if(KEYIN!=0x0f)
		{
			delay(1000);
			if(KEYIN!=0x0f)
			{KeyValue=0;
				
				switch(KEYIN)
				{
					case(0x07):KeyValue+=18;break;
					case(0x0b):KeyValue+=12;break;
					case(0x0d):KeyValue+=6;break;
					case(0x0e):KeyValue+=0;break;
				}
			}
		}
		if(KeyValue!=50)
		{goto next1;}
		
	DIGIT=0x3d;
	KeyValue=50;
			if(KEYIN!=0x0f)
		{
			delay(1000);
			if(KEYIN!=0x0f)
			{KeyValue=1;
				switch(KEYIN)
				{
					
					case(0x07):KeyValue+=18;break;
					case(0x0b):KeyValue+=12;break;
					case(0x0d):KeyValue+=6;break;
					case(0x0e):KeyValue+=0;break;
				}
			}
		}
				if(KeyValue!=50)
		{goto next1;}
		
	DIGIT=0x3b;
	KeyValue=50;
			if(KEYIN!=0x0f)
		{
			delay(1000);
			if(KEYIN!=0x0f)
			{KeyValue=2;
				switch(KEYIN)
				{
					
					case(0x07):KeyValue+=18;break;
					case(0x0b):KeyValue+=12;break;
					case(0x0d):KeyValue+=6;break;
					case(0x0e):KeyValue+=0;break;
				}
			}
		}
				if(KeyValue!=50)
		{goto next1;}
	DIGIT=0x37;
	KeyValue=50;
			if(KEYIN!=0x0f)
		{
			delay(1000);
			if(KEYIN!=0x0f)
			{KeyValue=3;
				switch(KEYIN)
				{
					
					case(0x07):KeyValue+=18;break;
					case(0x0b):KeyValue+=12;break;
					case(0x0d):KeyValue+=6;break;
					case(0x0e):KeyValue+=0;break;
				}
			}
		}
				if(KeyValue!=50)
		{goto next1;}
		
	DIGIT=0x2f;
	KeyValue=50;
			if(KEYIN!=0x0f)
		{
			delay(1000);
			if(KEYIN!=0x0f)
			{KeyValue=4;
				switch(KEYIN)
				{
					
					case(0x07):KeyValue+=18;break;
					case(0x0b):KeyValue+=12;break;
					case(0x0d):KeyValue+=6;break;
					case(0x0e):KeyValue+=0;break;
				}
			}
		}
				if(KeyValue!=50)
		{goto next1;}
		
	DIGIT=0x1f;
	KeyValue=50;
			if(KEYIN!=0x0f)
		{
			delay(1000);
			if(KEYIN!=0x0f)
			{KeyValue=5;
				switch(KEYIN)
				{
					
					case(0x07):KeyValue+=18;break;
					case(0x0b):KeyValue+=12;break;
					case(0x0d):KeyValue+=6;break;
					case(0x0e):KeyValue+=0;break;
				}
			}
		}
				if(KeyValue!=50)
		{goto next1;}
	/*KeyValue=50;
	for(i=0;i<6;i++)
	{
		KEYIN=0x0f;
		DIGIT=ccc;
		KeyValue=i;
		if(KEYIN!=0x0f)
		{
			delay(1000);
			if(KEYIN!=0x0f)
			{
				switch(KEYIN)
				{
					case(0x07):KeyValue+=18;break;
					case(0x0b):KeyValue+=12;break;
					case(0x0d):KeyValue+=6;break;
					case(0x0e):KeyValue+=0;break;
				}
			}
		if(KeyValue!=50)
		  break;
		}
		ccc=ccc<<1;
		ccc+=0x01;
	}
	ccc=0x3e;*/
	
/*	KEYIN=0x0f;
	if(KEYIN!=0x0f)
	{
		delay(1000);
		if(KEYIN!=0x0f)
		{	
			
			KEYIN=0x0f;
			switch(KEYIN)
			{
				case(0x07):	KeyValue=18;break;
				case(0x0b):	KeyValue=12;break;
				case(0x0d): KeyValue=6;break;
				case(0x0e):	KeyValue=0;break;
			}
			DIGIT=0x01;if(KEYIN==0x0f) KeyValue+=0;
			DIGIT=0x02;if(KEYIN==0x0f) KeyValue+=1;
			DIGIT=0x04;if(KEYIN==0x0f) KeyValue+=2;
			DIGIT=0x08;if(KEYIN==0x0f) KeyValue+=3;
			DIGIT=0x10;if(KEYIN==0x0f) KeyValue+=4;
			DIGIT=0x20;if(KEYIN==0x0f) KeyValue+=5;*/
			next1:while(KEYIN!=0x0f)
			{
				delay(1000);
			}
}
	
void main()
{ 
    P1=0x00;
	  p32=0;
		DigDisplay();
	
	while(KeyValue==50)
	{KeyDown();DigDisplay();}
	DigDisplay();
	way=numchange(KeyValue);
	if(way!=10&&way!=11)error();
	if(way==10)looptime=200;
	if(way==11)looptime=100;
	light[5]=smgduan[KeyValue];
	DigDisplay();
	KeyValue=50;

	while(KeyValue==50)
	{
		KeyDown();DigDisplay();
	}
	num1=numchange(KeyValue);
		if(num1>9)error();
	light[4]=smgduan[KeyValue];
		DigDisplay();
		KeyValue=50;

	while(KeyValue==50)
	{
		KeyDown();DigDisplay();
	}
	num2=numchange(KeyValue);
		if(num2>9)error();
	light[3]=smgduan[KeyValue];
		DigDisplay();
	  KeyValue=50;
	
	init();
	while(1)
	{
		if(num1*10+num2<=left1*10+left2)
		{
			EA=0;
			p32=1;
		}
		DigDisplay();
	}
}
		