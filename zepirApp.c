#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <stdlib.h>
#include "zepir.h"

deviceDescriptor_t device;

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

void printSettings(int fd, deviceDescriptor_t device){
	device.dualDirectionalMode = readDualDirectionalMode(fd);
	device.frequencyResponseSetting = readFrequencyResponseSetting(fd);
	device.hyperSenseLevel = readHyperSenseLevel(fd);
	device.hyperSenseSetting = readHyperSenseSetting(fd); 
	device.lightGateThreshold = readLightGateThreshold(fd);
	device.MDactivationTime = readMDactivationTime(fd);
	device.MDcurrentOutputActiveTime = readMDcurrentOutputActiveTime(fd);
	device.MDRSTpinConfiguration = readMDRSTpinConfiguration(fd);
	device.motionDetectionUnsolicitedMode = readMotionDetectedUnsolicitedMode(fd);
	device.motionDetectionSuspendSetting = readMotionDetectionSuspendSetting(fd);
	device.motionStatus = readMotionStatus(fd);
	device.pingValue = readPingValue(fd);
	device.rangeSetting = readRangeSetting(fd);
	device.sensitivity = readSensitivity(fd);
	device.serialInterfaceCommandMode = readSerialInterfaceCommandMode(fd);
	device.singleDirectionalMode = readSingleDirectionalMode(fd);
	device.sleepTime = readSleepTime(fd);
	printf("==============SETTINGS===================\n");
	printf("Dual Directional Mode:\t\t\t%c\n",device.dualDirectionalMode);
	printf("Frequency Response Setting:\t\t%c\n",device.frequencyResponseSetting);
	printf("Hyper Sense Level:\t\t\t%d\n",device.hyperSenseLevel);
	printf("Hyper Sense Setting:\t\t\t%c\n",device.hyperSenseSetting);
	printf("Light Gate Threshold:\t\t\t%d\n",device.lightGateThreshold);
	printf("MD Activation Time:\t\t\t%d\n",device.MDactivationTime);
	printf("MD Current Output Active Time:\t\t%d\n",device.MDcurrentOutputActiveTime);
	printf("MD/RST Pin Configuration:\t\t%c\n",device.MDRSTpinConfiguration);
	printf("Motion Detection Unsolicited Mode:\t%c\n",device.motionDetectionUnsolicitedMode);
	printf("Motion Detection Suspend Setting:\t%c\n",device.motionDetectionSuspendSetting);
	printf("Motion Status:\t\t\t\t%c\n",device.motionStatus);
	printf("Ping Value:\t\t\t\t%d\n",device.pingValue);
	printf("Range Setting:\t\t\t\t%d\n",device.rangeSetting);
	printf("Sensitivity:\t\t\t\t%d\n",device.sensitivity);
	printf("Serial Interface Command Mode:\t\t%c\n",device.serialInterfaceCommandMode);
	printf("Single Directional Mode:\t\t%c\n",device.singleDirectionalMode);
	printf("Sleep Time:\t\t\t\t%d\n",device.sleepTime);	
	printf("=========================================\n");
}

int main( int argc, char** argv )
{
	
	int fd = open_port();
	char command;
	int res;
	char mode;
	int value;
	while(1){
		printf("Give command: ");
		scanf(" %c",&command);
		//scanf("%c",&dump);
		switch(command){
			case 'a':
				printf("Motion Status: %c\n",readMotionStatus(fd));
				break;
			case 'b':
				printf("Current Light Gate Level iss: %d\n",readMotionStatus(fd));
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
				printf("Hyper Sense Level: %d\n",readHyperSenseLevel(fd));
				break;
			case 'h':
				printf("Motion Detection Syspend Setting: %c\n",readMotionDetectionSuspendSetting(fd));
				break;
			case 'i':
				printf("Serial Interface Command Mode: %c\n",readSerialInterfaceCommandMode(fd));
				break;
			case 'l':
				printf("Light Gate Threshold: %d\n",readLightGateThreshold(fd));
				break;
			case 'm':
				printf("Motion Detected Unsolicited Mode: %c\n",readMotionDetectedUnsolicitedMode(fd));
				break;
			case 'o':
				printf("MD Current Output Active Time: %d\n",readMDcurrentOutputActiveTime(fd));
				break;
			case 'p':
				printf("Ping Value: %d\n",readPingValue(fd));
				break;
			case 'r':
				printf("Range Setting: %d\n",readRangeSetting(fd));
				break;
			case 's':
				printf("Sensitivity: %d\n",readSensitivity(fd));
				break;
			case 'u':
				printf("Dual Directional Mode: %c\n",readDualDirectionalMode(fd));
				break;
			case 'v':
				printf("Single Directional Mode: %c\n",readSingleDirectionalMode(fd));
				break;
			case 'y':
				printf("Sleep Time: %d\n",readSleepTime(fd));
				break;
			case 'C':
				scanf(" %c",&mode);
				writeMDRSTpinConfiguration(fd,mode);
				break;
			case 'D':
				scanf("%d",&value);
				writeMDactivationTime(fd,(char)value);
				break;
			case 'E':
				scanf(" %c",&mode);
				writeHyperSenseSetting(fd,mode);
				break;
			case 'F':
				scanf(" %c",&mode);
				writeFrequencyResponseSetting(fd,mode);
				break;
			case 'G':
				scanf("%d",&value);
				writeHyperSenseLevel(fd,value);
				break;
			case 'H':
				scanf(" %c",&mode);
				writeMotionDetectionSyspendSetting(fd,mode);
				break;
			case 'K':
				scanf(" %c",&mode);
				writeSerialInterfaceCommandMode(fd,mode);
				break;
			case 'L':
				scanf("%d",&value);
				writeLightGateThreshold(fd,value);
				break;
			case 'M':
				scanf(" %c",&mode);
				writeMotionDetectedUnsolicitedMode(fd,mode);
				break;
			case 'O':
				scanf("%d",&value);
				writeMDoutputState(fd,value);
				break;
			case 'P':
				scanf("%d",&value);
				writePingValue(fd,value);
				break;
			case 'R':
				scanf("%d",&value);
				writeRangeSetting(fd,value);
				break;
			case 'S':
				scanf("%d",&value);
				writeSensitivity(fd,value);
				break;
			case 'U':
				scanf(" %c",&mode);
				writeDualDirectionalMode(fd,mode);
				break;
			case 'V':
				scanf(" %c",&mode);
				writeSingleDirectionalMode(fd,mode);
				break;
			case 'X':
				moduleReset(fd);
				break;
			case 'Y':
				scanf("%d",&value);
				writeSleepTime(fd,value);
				break;
			case 'Z':
				sleepMode(fd);
				break;
			case 'A':
				close(fd);
				exit(0);
			case 'B':
				printSettings(fd,device);
				break;
			default:
				printf("No such command\n");
				break;
		}
	}
	close(fd);
}
