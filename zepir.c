#include <stdio.h>   /* Standard input/output definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <stdlib.h>
#include "zepir.h"

int readCommand(int fd,char cmd){
	char buffer[1];
	int n;
	n = write(fd,&cmd,sizeof(cmd));
	if(n<0){
		fputs("write() failed!\n",stderr);
		return -1;
	}
	n = read(fd, buffer, sizeof(buffer));
	if(n<0){
		fputs("read() failed!\n", stderr);
		return -1;
	}
	return buffer[0];	
}

int writeCommand(int fd, char cmd, char val){
	char buffer[1];
	int n;
	n = write(fd,&cmd,sizeof(cmd));
	if(n<0){
		fputs("write() failed!\n",stderr);
		return -1;
	}
	n = read(fd, buffer, sizeof(buffer));
	if(n<0){
		fputs("read() failed!\n", stderr);
		return -1;
	}
	n = write(fd, &val, sizeof(val));
	if(n<0){
		fputs("write() of 1 bytes failed \n", stderr);
		return -1;
	}
	n = read(fd, buffer, sizeof(buffer));
	if(n<0){
		fputs("read failed!\n", stderr);
		return -1;
	}
	return 1;
}

int confirmationCommand(int fd, char cmd){
	char confirmation[4]={'1','2','3','4'};
	int n;
	n = write(fd,&cmd,sizeof(cmd));
	if(n<0){
		fputs("write() failed!\n",stderr);
		return -1;
	}
	n = write(fd,&confirmation,sizeof(confirmation));
	if(n<0){
		fputs("write() failed!\n",stderr);
		return -1;
	}
	return 1;
}



char readMotionStatus(int fd){
	char res;
	res = readCommand(fd,'a');
	if(res<0){
		fputs("Error in readMotionStatus()\n",stderr);
		return -1;
	}
	return res;
}

char readCurrentLightGateInputLevel(int fd){
	char res;
	res = readCommand(fd,'b');
	if(res<0){
		fputs("Error in readCurrentLightGateInputLevel()\n",stderr);
		return -1;
	}
	return res;
}

char readMDRSTpinConfiguration(int fd){
	char res;
	res = readCommand(fd,'c');
	if(res<0){
		fputs("Error in readMDRSTpinConfiguration()\n",stderr);
		return -1;
	}
	return res;
}

char readMDactivationTime(int fd){
	char res;
	res = readCommand(fd,'d');
	if(res<0){
		fputs("Error in readMDactivationTime()\n",stderr);
		return -1;
	}
	return res;
}

char readHyperSenseSetting(int fd){
	char res;
	res = readCommand(fd,'e');
	if(res<0){
		fputs("Error in readHyperSenseSetting()\n",stderr);
		return -1;
	}
	return res;
}

char readFrequencyResponseSetting(int fd){
	char res;
	res = readCommand(fd,'f');
	if(res<0){
		fputs("Error in readFrequencyResponseSetting()\n",stderr);
		return -1;
	}
	return res;
}

char readHyperSenseLevel(int fd){
	char res;
	res = readCommand(fd,'g');
	if(res<0){
		fputs("Error in readHyperSenseLevel()\n",stderr);
		return -1;
	}
	return res;
}

char readMotionDetectionSuspendSetting(int fd){
	char res;
	res = readCommand(fd,'h');
	if(res<0){
		fputs("Error in readMotionDetectionSuspendSetting()\n",stderr);
		return -1;
	}
	return res;
}

char readModuleSoftwareRevision(int fd){
	char res;
	res = readCommand(fd,'i');
	if(res<0){
		fputs("Error in readModuleSoftwareRevision()\n",stderr);
		return -1;
	}
	return res;
}

char readSerialInterfaceCommandMode(int fd){
	char res;
	res = readCommand(fd,'k');
	if(res<0){
		fputs("Error in readSerialInterfaceCommandMode()\n",stderr);
		return -1;
	}
	return res;
}

char readLightGateThreshold(int fd){
	char res;
	res = readCommand(fd,'l');
	if(res<0){
		fputs("Error in readLightGateThreshold()\n",stderr);
		return -1;
	}
	return res;
}

char readMotionDetectedUnsolicitedMode(int fd){
	char res;
	res = readCommand(fd,'m');
	if(res<0){
		fputs("Error in readMotionDetectedUnsolicitedMode()\n",stderr);
		return -1;
	}
	return res;
}

char readMDcurrentOutputActiveTime(int fd){
	char res;
	res = readCommand(fd,'o');
	if(res<0){
		fputs("Error in readMDcurrentOutputActiveTime()\n",stderr);
		return -1;
	}
	return res;
}

char readPingValue(int fd){
	char res;
	res = readCommand(fd,'p');
	if(res<0){
		fputs("Error in readPingValue()\n",stderr);
		return -1;
	}
	return res;
}

char readRangeSetting(int fd){
	char res;
	res = readCommand(fd,'r');
	if(res<0){
		fputs("Error in readRangeSetting()\n",stderr);
		return -1;
	}
	return res;
}

char readSensitivity(int fd){
	char res;
	res = readCommand(fd,'s');
	if(res<0){
		fputs("Error in readRangeSetting()\n",stderr);
		return -1;
	}
	return res;
}

char readDualDirectionalMode(int fd){
	char res;
	res = readCommand(fd,'u');
	if(res<0){
		fputs("Error in readDualDirectionalMode()\n",stderr);
		return -1;
	}
	return res;
}

char readSingleDirectionalMode(int fd){
	char res;
	res = readCommand(fd,'v');
	if(res<0){
		fputs("Error in readSingleDirectionalMode()\n",stderr);
		return -1;
	}
	return res;
}

char readSleepTime(int fd){
	char res;
	res = readCommand(fd,'y');
	if(res<0){
		fputs("Error in readSleepTime()\n",stderr);
		return -1;
	}
	return res;
}

char writeMDRSTpinConfiguration(int fd,char val){
	char res;
	if(val!='M' && val!='R'){
		fputs("Value must be 'M' or 'R'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'C', val);
	if(res<0){
		fputs("Error in writeMDRSTpinConfiguration()\n",stderr);
		return -1;
	}
	return res;
}

char writeMDactivationTime(int fd,char val){
	char res;
	if(val<0 || val>255){
		fputs("Value must be in [0,255]'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'D', (char) val);
	if(res<0){
		fputs("Error in writeMDactivationTime()\n",stderr);
		return -1;
	}
	return res;
}

char writeHyperSenseSetting(int fd,char val){
	char res;
	if(val!='Y' && val!='N'){
		fputs("Value must be 'Y' or 'N'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'E', val);
	if(res<0){
		fputs("Error in writeHyperSenseSetting()\n",stderr);
		return -1;
	}
	return res;	
}

char writeFrequencyResponseSetting(int fd,char val){
	char res;
	if(val!='H' && val!='L'){
		fputs("Value must be 'H' or 'L'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'F', val);
	if(res<0){
		fputs("Error in writeFrequencyResponseSetting()\n",stderr);
		return -1;
	}
	return res;	
}

char writeHyperSenseLevel(int fd,char val){
	char res;
	if(val<0 || val>3){
		fputs("Value must be in [0,3]'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'G', (char)val);
	if(res<0){
		fputs("Error in writeHyperSenseLevel()\n",stderr);
		return -1;
	}
	return res;	
}

char writeMotionDetectionSyspendSetting(int fd,char val){
	char res;
	if(val!='Y' && val!='N'){
		fputs("Value must be 'Y' or 'N'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'H', val);
	if(res<0){
		fputs("Error in writeMotionDetectionSyspendSetting()\n",stderr);
		return -1;
	}
	return res;	
}

char writeSerialInterfaceCommandMode(int fd,char val){
	char res;
	if(val!='D' && val!='A'){
		fputs("Value must be 'D' or 'A'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'K', val);
	if(res<0){
		fputs("Error in writeSerialInterfaceCommandMode()\n",stderr);
		return -1;
	}
	return res;	
}

char writeLightGateThreshold(int fd,char val){
	char res;
	if(val<0 || val>255){
		fputs("Value must be in [0,255]'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'L', (char)val);
	if(res<0){
		fputs("Error in writeLightGateThreshold()\n",stderr);
		return -1;
	}
	return res;
}

char writeMotionDetectedUnsolicitedMode(int fd,char val){
	char res;
	if(val!='Y' && val!='N'){
		fputs("Value must be 'Y' or 'N'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'M', val);
	if(res<0){
		fputs("Error in writeMotionDetectedUnsolicitedMode()\n",stderr);
		return -1;
	}
	return res;	
}

char writeMDOutputState(int fd,char val){
	char res;
	if(val<0 || val>255){
		fputs("Value must be in [0,255]'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'O', (char)val);
	if(res<0){
		fputs("Error in writeMDOutputState()\n",stderr);
		return -1;
	}
	return res;
}

char writePingValue(int fd,char val){
	char res;
	if(val<0 || val>255){
		fputs("Value must be in [0,255]'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'P', (char)val);
	if(res<0){
		fputs("Error in writePingValue()\n",stderr);
		return -1;
	}
	return res;
}

char writeRangeSetting(int fd,char val){
	char res;
	if(val<0 || val>7){
		fputs("Value must be in [0,7]'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'R', (char)val);
	if(res<0){
		fputs("Error in writeRangeSetting()\n",stderr);
		return -1;
	}
	return res;
}

char writeSensitivity(int fd,char val){
	char res;
	if(val<0 || val>255){
		fputs("Value must be in [0,255]'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'S', (char)val);
	if(res<0){
		fputs("Error in writeSensitivity()\n",stderr);
		return -1;
	}
	return res;
}

char writeDualDirectionalMode(int fd,char val){
	char res;
	if(val!='Y' && val!='N'){
		fputs("Value must be 'Y' or 'N'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'U', val);
	if(res<0){
		fputs("Error in writeDualDirectionalMode()\n",stderr);
		return -1;
	}
	return res;	
}

char writeSingleDirectionalMode(int fd,char val){
	char res;
	if(val!='A' && val!='+' && val!='-'){
		fputs("Value must be 'A','+' or '-'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'U', val);
	if(res<0){
		fputs("Error in writeSingleDirectionalMode()\n",stderr);
		return -1;
	}
	return res;	
}

char writeSleepTime(int fd,char val){
	char res;
	if(val<0 || val>255){
		fputs("Value must be in [0,255]'\n", stderr);
		return -1;
	}
	res = writeCommand(fd, 'Y', (char)val);
	if(res<0){
		fputs("Error in writeSleepTime()\n",stderr);
		return -1;
	}
	return res;
}

char moduleReset(int fd){
	char res;
	res = confirmationCommand(fd,'X');
	if(res<0){
		fputs("Error in moduleReset()\n",stderr);
		return -1;
	}
	return res;
}

char sleepMode(int fd){
	char res;
	res = confirmationCommand(fd,'Z');
	if(res<0){
		fputs("Error in moduleReset()\n",stderr);
		return -1;
	}
	return res;
}