#include<reg51.h> 

unsigned char d[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x7F,0x6F};

void delay(int i){
	unsigned int j,k; 
	for(j=0;j<i;j++)
		for(k=0;k<1200;k++);
}

void main()
{
	unsigned char i; 
	P2 = 0xFE;
	while(1){
		for(i=0;i<0x0A;i++)
		{
			P0=d[i];
			delay(2000);
		}
		for(i=8;i>0;i--)
		{
			P0=d[i];
			delay(2000);
		}
	}
} 