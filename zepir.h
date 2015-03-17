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
	char MDoutputState;
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

extern deviceDescriptor_t device;

void updateDualDirectionalMode(char res);
void updateFrequencyResponseSetting(char res);
void updateHyperSenseLevel(char res);
void updateHyperSenseSetting(char res);
void updateLightGateThreshold(char res);
void updateMDactivationTime(char res);
void updateMDcurrentOutputActiveTime(char res);
void updateMDoutputState(char res);
void updateMDRSTpinConfiguration(char res);
void updateMotionDetectionUnsolicitedMo(char res);
void updateMotionDetectionSuspendSettin(char res);
void updateMotionStatus(char res);
void updatePingValue(char res);
void updateRangeSetting(char res);
void updateSensitivity(char res);
void updateSerialInterfaceCommandMode(char res);
void updateSingleDirectionalMode(char res);
void updateSleepTime(char res);

char getdualDirectionalMode();
char getFrequencyResponseSetting();
char getHyperSenseLevel();
char getHyperSenseSetting();
char getlightGateThreshold();
char getMDactivationTime();
char getMDcurrentOutputActiveTime();
char getMDRSTpinConfiguration();
char getMDoutputState();
char getMotionDetectionUnsolicitedMo();
char getMotionDetectionSuspendSettin();
char getMotionStatus();
char getPingValue();
char getRangeSetting();
char getSensitivity();
char getSerialInterfaceCommandMode();
char getSingleDirectionalMode();
char getSleepTime();

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
char writeMDoutputState(int fd,char val);
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