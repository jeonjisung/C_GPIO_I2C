#include "mbed.h"

Serial pc(USBTX, USBRX);

DigitalInOut pb9(PB_9);
DigitalInOut pb8(PB_8);

int main()
{
	i2c_write(0xB8);
	i2c_read(0xB8);
}

void i2c_write(unsigned char addr)
{
	pb8.output();
	pb9.output();
	for (int i = 0; i < 8; i++)
	{
		pb8 = 1;
		wait(0.00075);
		if ((addr & 0x80) == 0x80)
		{
			pb9 = 1;
		}
		else
		{
			pb9 = 0;
		}
		wait(0.00075);
		addr = addr << 1;
		pb8 = 0;
		wait(0.00075);
	}
	wait(0.00075); // ACK
}

void i2c_read(unsigned char addr)
{
	unsigned char output;

	for (int i = 0; i < 8; i++)
	{
		if ((addr & 0x80)== 0x80)
		{
			if (pb8 == 1)
			{
				if(pb9 == 1){
					output = 1;
				}
			}
			else
			{
				if(pb9 == 1){
					output = 0;
				}
			}
			addr = addr << 1;
		}
	}
	printf("%d", output);
}
