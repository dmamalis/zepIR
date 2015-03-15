#ifndef ZEPIR_H_
#define ZEPIR_H_

typedef struct deviceDescriptor_t{
	char dualDirectionalMode;
	char frequencyResponseSetting;
	char hyperSenseLevel;
	char hyperSenseSetting;
	char lightGateThreshold;
	char MDactivationTime;
	char MDcurrentOutputActiveTime;
	char MDRSTpinConfiguration;
	char motionDetectionUnsolicitedMode;
	char motionDetectionSuspendSetting;
	char motionStatus;
	char pingValue;
	char rangeSetting;
	char sensitivity;
	char serialInterfaceCommandMode;
	char singleDirectionalMode;
	char sleepTime;
}deviceDescriptor_t;

int readCommand(int fd,char cmd);
int writeCommand(int fd, char cmd, char val);
int confirmationCommand(int fd, char cmd);

char writeMDRSTpinConfiguration(int fd,char val);
char writeMDactivationTime(int fd,char val);
char writeHyperSenseSetting(int fd,char val);
char writeFrequencyResponseSetting(int fd,char val);
char writeHyperSenseLevel(int fd,char val);
char writeMotionDetectionSyspendSetting(int fd,char val);
char writeSerialInterfaceCommandMode(int fd,char val);
char writeLightGateThreshold(int fd,char val);
char writeMotionDetectedUnsolicitedMode(int fd,char val);
char writeMDOutputState(int fd,char val);
char writePingValue(int fd,char val);
char writeRangeSetting(int fd,char val);
char writeSensitivity(int fd,char val);
char writeDualDirectionalMode(int fd,char val);
char writeSingleDirectionalMode(int fd,char val);
char writeSleepTime(int fd,char val);

char readMotionStatus(int fd);
char readCurrentLightGateInputLevel(int fd);
char readMDRSTpinConfiguration(int fd);
char readMDactivationTime(int fd);
char readHyperSenseSetting(int fd);
char readFrequencyResponseSetting(int fd);
char readHyperSenseLevel(int fd);
char readMotionDetectionSuspendSetting(int fd);
char readModuleSoftwareRevision(int fd);
char readSerialInterfaceCommandMode(int fd);
char readLightGateThreshold(int fd);
char readMotionDetectedUnsolicitedMode(int fd);
char readMDcurrentOutputActiveTime(int fd);
char readPingValue(int fd);
char readRangeSetting(int fd);
char readSensitivity(int fd);
char readDualDirectionalMode(int fd);
char readSingleDirectionalMode(int fd);
char readSleepTime(int fd);

char moduleReset(int fd);
char sleepMode(int fd);

#endif