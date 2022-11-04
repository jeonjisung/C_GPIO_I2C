#include "mbed.h"

Serial pc(USBTX, USBRX);

DigitalInOut sda(PB_9); // SDA
DigitalInOut scl(PB_8); // SCL

int addr7bit = 0xB8;
int addr8bit = 0xB9;
int ACK = 0;
int NACK = 1;

void i2c_write(unsigned char addr);
void i2c_read(unsigned char ANN);
void i2c_start();
void i2c_end();

int main()
{
	pc.baud(9600);
	pc.printf("Hello World!\n\r");
	sda.output();
	scl.output();
	while (1)
	{
		i2c_start();
		i2c_write(addr7bit);
		i2c_write(0x00);
		i2c_write(addr8bit);
		i2c_read(ACK);
		i2c_read(ACK);
		i2c_read(ACK);
		i2c_read(NACK);
		i2c_end();
		// i2c_write(addr8bit);
		wait(0.100);
	}
}

void i2c_start(){
	scl.output();
	sda.output();

	sda = 1;
	wait(0.00075);

	scl = 1;
	wait(0.00075);

	sda = 0;
	wait(0.00075);

	scl = 0;
	wait(0.00075);
}

void i2c_end(){
	scl.output();
	sda.output();
	
	sda = 0;
	wait(0.00075);

	scl = 0;
	wait(0.00075);

	sda = 1;
	wait(0.00075);

	scl = 1;
	wait(0.00075);
}

void i2c_write(unsigned char addr)
{
	scl.output();
	sda.output();
	for (int i = 0; i < 8; i++)
	{	
		if ((addr & 0x80) == 0x80)
		{
			sda = 1;
			// pb9 = 1;
		}
		else
		{
			sda = 0;
			// pb9 = 0;
		}
		wait(0.00075);
		addr = addr << 1;
		scl = 1;
		wait(0.00075);
		scl = 0;
		wait(0.00075);
	}

	sda.input();
	
	scl = 1;
	wait(0.00075);
	sda.output();
	// wait(0.00075); // ACK
}

void i2c_read(unsigned char ANN)
{
	unsigned char data;

	scl.input();
	sda.output();

	for (int i = 0; i < 8; i++)
	{
		scl.read();
		wait(0.00075);
		sda = 0;
		if (scl == 1)
		{
			data = data | 0x01;
			wait(0.00075);
		}
		else
		{
			data = data | 0x00;
			wait(0.00075);
		}
		pc.printf("%x", data);
	}
	scl.output();
	wait(0.00075);
	sda = ANN;
	scl = 0;
	pc.printf("\n\r", data);
}
