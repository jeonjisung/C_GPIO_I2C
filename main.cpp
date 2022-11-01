#include "mbed.h"

Serial pc(USBTX, USBRX);

DigitalInOut pb9(PB_9);
DigitalInOut pb8(PB_8);
// PB_9, PB_8

int main()
{
	char cmd[4];

	pc.baud(9600);
	pc.printf("Hellow World!\n\r");
	if(pb9.is_connected() && pb8.is_connected()){
		printf("All Connected\n\r");
	}

	pb9.mode(PullNone);
	pb8.mode(PullNone);
	while (1)
	{
		cmd[0] = 0x00;
		cmd[1] = 0x01;
		cmd[2] = 0x02;
		cmd[3] = 0x03;
		pb8.output();
		if(pb8 == 0){
			wait(0.006);
			pb9.output();
		}
		wait(0.006);
		pb8.input();
		if(pb8 == 1){
			pb9.input();
			wait(0.00075);
			pb9.output();
			wait(0.00075);
		}
		wait(0.00075);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.00075);
			pb9.output();
			wait(0.00075);
		}
		wait(0.00075);
		pb8.input();
		if(pb8 == 1){
			pb9.input();
			wait(0.00075);
			pb9.output();
			wait(0.00075);
			pb9.input();
			wait(0.00075);
			pb9.output();
			wait(0.00075);
			pb9.input();
			wait(0.00075);
			pb9.output();
			wait(0.00075);
		}
		wait(0.00075);
		pb8.output();
		wait(0.00075);
		if(pb8 == 0){
			pb9.input();
			wait(0.00075);
			pb9.output();
			wait(0.00075);
			pb9.input();
			wait(0.00075);
			pb9.output();
			wait(0.00075);
			pb9.input();
			wait(0.00075);
			pb9.output();
			wait(0.00075);
			pb9.input();
			wait(0.00075);
			pb9.output();
			wait(0.00075);
		}
		wait(0.00075);
		pb8.input();
		wait(0.00075);
		// --------------- Write [ 0xB8 ] + ACK
		pb8.output();
		wait(0.00085714285);
		if(pb8 == 0){
			pb9.input();
			wait(0.00085714285);
			pb9.output();
			wait(0.00085714285);
			pb9.input();
			wait(0.00085714285);
			pb9.output();
			wait(0.00085714285);
			pb9.input();
			wait(0.00085714285);
			pb9.output();
			wait(0.00085714285);
			pb9.input();
			wait(0.00085714285);
			pb9.output();
			wait(0.00085714285);
			pb9.input();
			wait(0.00085714285);
			pb9.output();
			wait(0.00085714285);
			pb9.input();
			wait(0.00085714285);
			pb9.output();
			wait(0.00085714285);
			pb9.input();
			wait(0.00085714285);
			pb9.output();
			wait(0.00085714285);
			pb9.input();
			wait(0.00085714285);
			pb9.output();
			wait(0.00085714285);
			pb9.input();
			wait(0.00085714285);
			pb9.output();
			wait(0.00085714285);
		}
		wait(0.00085714285);
		pb8.input();
		wait(0.00085714285);
		// --------------------- 0+ACK
		pb9.input();
		pb8.output();
		wait(0.006923076925);
		pb9.output();
		wait(0.006923076925);
		pb8.input();
		if(pb8 == 1){
			pb9.input();
			wait(0.006923076925);
			pb9.output();
			wait(0.006923076925);
		}
		wait(0.006923076925);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.006923076925);
			pb9.output();
			wait(0.006923076925);
		}
		wait(0.006923076925);
		pb8.input();
		if(pb8 == 1){
			pb9.input();
			wait(0.006923076925);
			pb9.output();
			wait(0.006923076925);
			pb9.input();
			wait(0.006923076925);
			pb9.output();
			wait(0.006923076925);
			pb9.input();
			wait(0.006923076925);
			pb9.output();
			wait(0.006923076925);
		}
		wait(0.006923076925);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.006923076925);
			pb9.output();
			wait(0.006923076925);
			pb9.input();
			wait(0.006923076925);
			pb9.output();
			wait(0.006923076925);
		}
		wait(0.006923076925);
		pb8.input();
		pb9.input();
		wait(0.006923076925);
		pb9.output();
		wait(0.006923076925);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.006923076925);
			pb9.output();
			wait(0.006923076925);
		}
		wait(0.006923076925);
		pb8.input();
		cmd[0] = 0x00;
		wait(0.00346153846);
		pb8.output();
		// --------------------- Read[0xB9] + ACK
		if(pb8 == 0){
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
		}
		wait(0.00346153846);
		pb8.input();
		if(pb8 == 1){
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
		}
		wait(0.00782608695);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
		}
		wait(0.00782608695);
		pb8.input();
		if(pb8 == 1){
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
		}
		wait(0.00782608695);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
		}
		wait(0.00782608695);
		pb8.input();
		wait(0.00391304347);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
			pb9.input();
			wait(0.00947368421);
			pb9.output();
			wait(0.00947368421);
			pb9.input();
			wait(0.00947368421);
			pb9.output();
			wait(0.00947368421);
			pb9.input();
			wait(0.00947368421);
			pb9.output();
			wait(0.00947368421);
			pb9.input();
			wait(0.00947368421);
			pb9.output();
			wait(0.00947368421);
			// --------------- 54 + ACK
		}
		wait(0.00391304347);
		pb8.input();
		if(pb8 == 1){
			pb9.input();
			wait(0.00947368421);
			pb9.output();
			wait(0.00947368421);
		}
		wait(0.00947368421);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.00947368421);
			pb9.output();
			wait(0.00947368421);
			pb9.input();
			wait(0.00947368421);
			pb9.output();
			wait(0.00947368421);
		}
		wait(0.00947368421);
		pb8.input();
		wait(0.0047368421);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.00947368421);
			pb9.output(); // 3+ACK
			wait(0.00947368421);
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
		}
		wait(0.0047368421);
		pb8.input();
		if(pb8 == 1){
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);;
		}
		wait(0.00782608695);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
		}
		wait(0.00782608695);
		pb8.input();
		if(pb8 == 1){
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
		}
		wait(0.00782608695);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695);
		}
		wait(0.00782608695);
		pb8.input();
		wait(0.00391304347);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.00782608695);
			pb9.output();
			wait(0.00782608695); // 40+ACK
			pb9.input();
			wait(0.00818181818);
			pb9.output();
			wait(0.00818181818);
			pb9.input();
			wait(0.00818181818);
			pb9.output();
			wait(0.00818181818);
			pb9.input();
			wait(0.00818181818);
			pb9.output();
			wait(0.00818181818);
			pb9.input();
			wait(0.00818181818);
			pb9.output();
			wait(0.00818181818);
			pb9.input();
			wait(0.00818181818);
			pb9.output();
			wait(0.00818181818);
		}
		wait(0.00391304347);
		pb8.input();
		if(pb8 == 1){
			pb9.input();
			wait(0.00818181818);
			pb9.output();
			wait(0.00818181818);
		}
		wait(0.00818181818);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.00818181818);
			pb9.output();
			wait(0.00818181818);
		}
		wait(0.00818181818);
		pb8.input();
		if(pb8 == 1){
			pb9.input();
			wait(0.00818181818);
			pb9.output();
			wait(0.00818181818);
		}
		wait(0.00818181818);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.00818181818);
			pb9.output();
			wait(0.00818181818); // 2+ACK
			pb9.input();
			wait(0.00857142857);
			pb9.output();
			wait(0.00857142857);
		}
		wait(0.00818181818); 
		pb8.input();
		if(pb8 == 1){
			pb9.input();
			wait(0.00857142857);
			pb9.output();
			wait(0.00857142857);
		}
		wait(0.00857142857);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.00857142857);
			pb9.output();
			wait(0.00857142857);
		}
		wait(0.00857142857);;
		pb8.input();
		if(pb8 == 1){
			pb9.input();
			wait(0.00857142857);
			pb9.output();
			wait(0.00857142857);
			pb9.input();
			wait(0.00857142857);
			pb9.output();
			wait(0.00857142857);
			pb9.input();
			wait(0.00857142857);
			pb9.output();
			wait(0.00857142857);
		}
		wait(0.00857142857);
		pb8.output();
		if(pb8 == 0){
			pb9.input();
			wait(0.00857142857);
			pb9.output();
			wait(0.00857142857);
		}
		wait(0.00857142857);
		pb8.input();
		if(pb8 == 1){
			pb9.input();
			wait(0.00857142857);
			pb9.output();
			wait(0.00857142857);
			pb9.input();
			wait(0.00857142857);
			pb9.output();
		}
		wait(0.00857142857);
		pb8.output();
		pb9.input(); // 22 + NAK
		wait(0.006);
		pb8.input();

		printf("습도 = %d.%d\r\n", cmd[0], cmd[1]);
		printf("온도 = %d.%d\r\n", cmd[2], cmd[3]);

		wait(2);
	}
}


