#include "mbed.h"

Serial pc(USBTX, USBRX);

DigitalInOut sda(PB_9); // SDA
DigitalOut scl(PB_8);	// SCL

int addr7bit = 0xB8;
int addr8bit = 0xB9;
int ACK = 0;
int NACK = 1;

void i2c_write(unsigned char addr);
unsigned char i2c_read(int ANN);
void i2c_start();
void i2c_end();
void i2c_init();

int main()
{
	char cmd[4];

	pc.baud(9600);
	pc.printf("Hello World!12\n\r");
	sda.output();
	while (1)
	{
		i2c_init();
		i2c_start();
		i2c_write(addr7bit);
		wait_us(40);
		i2c_write(0x00);
		wait_us(40);
		i2c_start();
		i2c_write(addr8bit);
		wait_us(40);
		cmd[0] = i2c_read(ACK);
		cmd[1] = i2c_read(ACK);
		cmd[2] = i2c_read(ACK);
		cmd[3] = i2c_read(NACK);
		i2c_end();

		pc.printf("%d.%d\n\r", cmd[0], cmd[1]);
		pc.printf("%d.%d\n\r", cmd[2], cmd[3]);
		// i2c_write(addr8bit);
		wait(2);
	}
}

void i2c_init()
{
	sda.output();
	scl = 1;
	sda = 1;
}

void i2c_start()
{
	sda.output();

	scl = 1;
	wait_us(40);

	sda = 1;
	wait_us(40);

	sda = 0;
	wait_us(40);

	scl = 0;
	wait_us(40);
}

void i2c_end()
{
	sda.output();

	sda = 0;
	wait_us(40);

	scl = 1;
	wait_us(40);

	sda = 1;
	wait_us(40);
}

void i2c_write(unsigned char addr)
{
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
		scl = 1;
		wait_us(40);
		addr = addr << 1;
		scl = 0;
		wait_us(40);
	}
	sda = 0;

	// read ack
	sda.input();
	scl = 1;
	sda.read();
	wait_us(40);
	scl = 0;
	wait_us(40);
}

unsigned char i2c_read(int ANN)
{
	unsigned char data;

	sda.input();

	for (int i = 0; i < 8; i++)
	{
		wait_us(40);
		scl = 1;
		if (sda.read() == 1)
		{
			data = data | 0x01;
		}
		else // sda.read() == 0
		{
			data = data | 0x00;
		}
		wait_us(40);
		scl = 0;
		wait_us(40);
		if (i == 7)
			break;
		data = data << 1;
	}

	// read ack
	sda.output();
	wait_us(40);
	scl = 1;
	sda = ANN;
	wait_us(40);
	scl = 0;
	wait_us(40);

	return data;
}
