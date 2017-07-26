#pragma once
#include <string.h>
using namespace std;

#pragma pack(push, 1)
struct structMsgUdpR01
{
	unsigned int timeStamp;

	unsigned char statusMpu;
	unsigned char statusBaro;
	unsigned char statusCompass;
	unsigned char statusUdp;
	unsigned char statusGS;

	//Gyro Measurements
	short mpuGyroX;
	short mpuGyroY;
	short mpuGyroZ;

	//Accelerometer Measurements with Gravity
	short mpuAccX;
	short mpuAccY;
	short mpuAccZ;

	//Accelerometer Measurements without Gravity
	short mpuAccWorldX;
	short mpuAccWorldY;
	short mpuAccWorldZ;

	//Yaw Pitch Roll Measurements in Radians
	float mpuYaw;
	float mpuPitch;
	float mpuRoll;

	float baroTemp;
	float baroAlt;

	float compassHdg;

	float batteryVoltage;

	// Altitude Parameter Estimation with Kalman Filter
	float quadAccelerationWorldZ; // kalman filtered output
	float quadVelocityWorldZ;   // kalman filtered output
	float quadPositionWorldZ;   // kalman filtered output
	
	unsigned char modeQuad;
	unsigned char autoModeStatus;
	unsigned char statusRx;
	short rxThrottle;
	short rxPitch;
	short rxRoll;
	short rxYaw;

	unsigned char pidRatePitchKp;
	unsigned char pidRatePitchKi;
	unsigned char pidRatePitchKd;
	short pidRatePitchOutput;
	short pidRatePitchPresult;
	short pidRatePitchIresult;
	short pidRatePitchDresult;

	unsigned char pidAnglePitchKp;
	unsigned char pidAnglePitchKi;
	unsigned char pidAnglePitchKd;
	short pidAnglePitchOutput;
	short pidAnglePitchPresult;
	short pidAnglePitchIresult;
	short pidAnglePitchDresult;

	//unsigned char pidRateRollKp;
	//unsigned char pidRateRollKi;
	//unsigned char pidRateRollKd;
	//short pidRateRollOutput;
	//short pidRateRollPresult;
	//short pidRateRollIresult;
	//short pidRateRollDresult;

	//unsigned char pidAngleRollKp;
	//unsigned char pidAngleRollKi;
	//unsigned char pidAngleRollKd;
	//short pidAngleRollOutput;
	//short pidAngleRollPresult;
	//short pidAngleRollIresult;
	//short pidAngleRollDresult;

	//unsigned char pidRateYawKp;
	//unsigned char pidRateYawKi;
	//unsigned char pidRateYawKd;
	//short pidRateYawOutput;
	//short pidRateYawPresult;
	//short pidRateYawIresult;
	//short pidRateYawDresult;

	//unsigned char pidAngleYawKp;
	//unsigned char pidAngleYawKi;
	//unsigned char pidAngleYawKd;
	//short pidAngleYawOutput;
	//short pidAngleYawPresult;
	//short pidAngleYawIresult;
	//short pidAngleYawDresult;

	//short commandedYawAngle;

	unsigned char pidVelAltKp;
	unsigned char pidVelAltKi;
	unsigned char pidVelAltKd;
	short pidVelAltOutput;
	short pidVelAltPresult;
	short pidVelAltIresult;
	short pidVelAltDresult;

	unsigned char pidAccAltKp;
	unsigned char pidAccAltKi;
	unsigned char pidAccAltKd;
	short pidAccAltOutput;
	short pidAccAltPresult;
	short pidAccAltIresult;
	short pidAccAltDresult;

};
#pragma pack(pop)


class cMsgUdpR01
{
public:
	cMsgUdpR01();
	structMsgUdpR01 message;
	unsigned char dataBytes[sizeof(message)];
	void getPacket();
	void setPacket();
	~cMsgUdpR01();
};

























































































































































