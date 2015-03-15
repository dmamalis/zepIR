#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <stdlib.h>
#include "zepir.h"

/*
 * 'open_port()' - Open serial port 1.
 *
 * Returns the file descriptor on success or -1 on error.
 */

int open_port(void){
  int fd; /* File descriptor for the port */

  fd = open("/dev/ttyO1", O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1)
  {
   /*
    * Could not open the port.
    */
    perror("open_port: Unable to open /dev/ttyf1 - ");
  }
  else
    fcntl(fd, F_SETFL, 0);

  return (fd);
}

int main( int argc, char** argv )
{
	int fd = open_port();
	char command;
	int res;
	char val;
	while(1){
		printf("Give command: ");
		scanf(" %c",&command);
		//scanf("%c",&dump);
		switch(command){
			case 'a':
				printf("Motion Status: %c\n",readMotionStatus(fd));
				break;
			case 'b':
				printf("Current Light Gate Level iss: %c\n",readMotionStatus(fd));
				break;
			case 'c':
				res = readMDRSTpinConfiguration(fd);
				if(res == 'M')
					printf("Pin configured as MD\n");
				else if(res == 'R')
					printf("Pin configured as RST\n");
				else
					printf("Pin Configuration is undefined: %c\n",res);
				break;
			case 'd':
				printf("Activation Time: %d\n",readMDactivationTime(fd));
				break;
			case 'e':
				printf("Hyper Sense Setting: %c\n",readHyperSenseSetting(fd));
				break;
			case 'f':
				printf("Frequency Response Setting: %c\n",readFrequencyResponseSetting(fd));
				break;
			case 'g':
				printf("Hyper Sense Level: %c\n",readHyperSenseLevel(fd));
				break;
			case 'h':
				printf("Motion Detection Syspend Setting: %c\n",readMotionDetectionSuspendSetting(fd));
				break;
			case 'i':
				printf("Serial Interface Command Mode: %c\n",readSerialInterfaceCommandMode(fd));
				break;
			case 'l':
				printf("Light Gate Threshold: %c\n",readLightGateThreshold(fd));
				break;
			case 'm':
				printf("Motion Detected Unsolicited Mode: %c\n",readMotionDetectedUnsolicitedMode(fd));
				break;
			case 'o':
				printf("MD Current Output Active Time: %c\n",readMDcurrentOutputActiveTime(fd));
				break;
			case 'p':
				printf("Ping Value: %c\n",readPingValue(fd));
				break;
			case 'r':
				printf("Range Setting: %c\n",readRangeSetting(fd));
				break;
			case 's':
				printf("Sensitivity: %c\n",readSensitivity(fd));
				break;
			case 'u':
				printf("Dual Directional Mode: %c\n",readDualDirectionalMode(fd));
				break;
			case 'v':
				printf("Single Directional Mode: %c\n",readSingleDirectionalMode(fd));
				break;
			case 'y':
				printf("Sleep Time: %c\n",readSleepTime(fd));
				break;
			case 'C':
				scanf(" %c",&val);
				writeMDRSTpinConfiguration(fd,val);
				break;
			case 'D':
				scanf(" %c",&val);
				writeMDactivationTime(fd,val);
				break;
			case 'E':
				scanf(" %c",&val);
				writeHyperSenseSetting(fd,val);
				break;
			case 'F':
				scanf(" %c",&val);
				writeFrequencyResponseSetting(fd,val);
				break;
			case 'G':
				scanf(" %c",&val);
				writeHyperSenseLevel(fd,val);
				break;
			case 'H':
				scanf(" %c",&val);
				writeMotionDetectionSyspendSetting(fd,val);
				break;
			case 'K':
				scanf(" %c",&val);
				writeSerialInterfaceCommandMode(fd,val);
				break;
			case 'L':
				scanf(" %c",&val);
				writeLightGateThreshold(fd,val);
				break;
			case 'O':
				scanf(" %c",&val);
				writeMDOutputState(fd,val);
				break;
			case 'P':
				scanf(" %c",&val);
				writePingValue(fd,val);
				break;
			case 'R':
				scanf(" %c",&val);
				writeRangeSetting(fd,val);
				break;
			case 'S':
				scanf(" %c",&val);
				writeSensitivity(fd,val);
				break;
			case 'U':
				scanf(" %c",&val);
				writeDualDirectionalMode(fd,val);
				break;
			case 'V':
				scanf(" %c",&val);
				writeSingleDirectionalMode(fd,val);
				break;
			case 'X':
				moduleReset(fd);
				break;
			case 'Y':
				writeSleepTime(fd,val);
				break;
			case 'Z':
				sleepMode(fd);
				break;
			case 'A':
				close(fd);
				exit(0);
			default:
				printf("No such command\n");
				break;
		}
	}
	close(fd);
}


//read commands
//----->command
//<-----response
//write commands
//----->command
//<-----CurrentValue (single byte)
//----->NewValue (single byte)
//<-----ACK (NACK after 2.5s)
//confirmation commands
//----->Command
//<-----ACK
//----->Sequence(4 characters)
//<-----ACK

