#include "mbed.h"

Serial pc(USBTX, USBRX);

DigitalInOut sda(PB_9); // SDA
DigitalOut scl(PB_8);	// SCL

int addr7bit = 0xB8;
int addr8bit = 0xB9;

void i2c_write(unsigned char addr);
void i2c_read(char *cmd);
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
		i2c_read(cmd);
		// i2c_read(cmd, ACK);
		// i2c_read(cmd, ACK);
		// i2c_read(cmd, NACK);
		i2c_end();

		pc.printf("습도 : %d.%d\n\r", cmd[0], cmd[1]);
		pc.printf("온도 : %d.%d\n\r", cmd[2], cmd[3]);
		// i2c_write(addr8bit);
		wait(1);
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

	scl = 0;
	wait_us(40);

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

void i2c_read(char *cmd)
{
	int j = 0;
	unsigned char data = 0;
	while (j < 5)
	{
		data = 0;
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
			if (i != 7)
				data = data << 1;
		}
		cmd[j] = data;

		wait_us(40);
		// write ack
		sda.output();
		
		if (j < 4)
		{
			sda = 0;
		}
		else
		{
			sda = 1;
		}
		
		scl = 1;
		wait_us(40);
		scl = 0;
		wait_us(40);

		j++;
	}
}
