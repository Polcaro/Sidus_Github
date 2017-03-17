#pragma once
/*
This header file define all the configurable variables including constants, pin mapping, etc.
*/

//Wifi, UDP Definitions


//Pin Definitions
#define		PIN_LED				5

#define		PIN_RX_THR			38	
#define		PIN_RX_PITCH		37	
#define		PIN_RX_ROLL			36
#define		PIN_RX_YAW			39
#define		PIN_RX_5TH_CHAN		34
#define		PIN_RX_6TH_CHAN		35

#define		PIN_M_FL			32
#define		PIN_M_FR			33
#define		PIN_M_BR			25
#define		PIN_M_BL			26

#define		PIN_BUZZER			27

#define		PWM_FREQ		50
#define		PWM_DEPTH		16

#define		PWM_MICROSECONDS_TO_BITS	3.277 //pow(2, PWM_DEPTH)*PWM_FREQ/pow(10,6);

#define		M_FL_CHANNEL		1
#define		M_FR_CHANNEL		2
#define		M_BR_CHANNEL		3
#define		M_BL_CHANNEL		4
#define		BUZZER_PWM_CHANNEL		5

#define		RX_DATATIME_THESHOLD		1000

#define		CMD_PITCH_MIN	-45.0
#define		CMD_PITCH_MAX	+45.0
#define		DC_PITCH_MIN	1100.0
#define		DC_PITCH_MAX	1900.0

#define		CMD_ROLL_MIN	-45.0
#define		CMD_ROLL_MAX	+45.0
#define		DC_ROLL_MIN		1100.0
#define		DC_ROLL_MAX		1900.0

#define		CMD_THR_MIN		1000.0
#define		CMD_THR_MAX		1900.0
#define		DC_THR_MIN		1100.0
#define		DC_THR_MAX		1900.0

#define		CMD_YAW_MIN		-45.0
#define		CMD_YAW_MAX		+45.0
#define		DC_YAW_MIN		1100.0
#define		DC_YAW_MAX		1900.0

#define		CMD_THR_ARM_START	CMD_THR_MIN+(CMD_THR_MAX-CMD_THR_MIN)/10

#define		CMD_MODE_CHANGE_THR_GAP		50
#define		CMD_MODE_CHANGE_ANGLE_GAP	10


#define		PID_RATE_PITCH_KP			0.8
#define		PID_RATE_PITCH_KI			0.0
#define		PID_RATE_PITCH_KD			0.025
#define		PID_RATE_PITCH_OUTMIN		-250
#define		PID_RATE_PITCH_OUTMAX		250
#define		PID_RATE_PITCH_F1_DEFAULT	0.0
#define		PID_RATE_PITCH_F2_DEFAULT	0.5
#define		PID_RATE_PITCH_OUT_FILT_CONSTANT	0.7

#define		PID_ANGLE_PITCH_KP			1.0
#define		PID_ANGLE_PITCH_KI			0.0
#define		PID_ANGLE_PITCH_KD			0.0
#define		PID_ANGLE_PITCH_OUTMIN		-250
#define		PID_ANGLE_PITCH_OUTMAX		250
#define		PID_ANGLE_PITCH_F1_DEFAULT	0.75
#define		PID_ANGLE_PITCH_F2_DEFAULT	0.75
#define		PID_ANGLE_PITCH_OUT_FILT_CONSTANT	0.7

#define		PID_RATE_ROLL_KP			0.4
#define		PID_RATE_ROLL_KI			0.0
#define		PID_RATE_ROLL_KD			0.0
#define		PID_RATE_ROLL_OUTMIN		-250
#define		PID_RATE_ROLL_OUTMAX		250
#define		PID_RATE_ROLL_F1_DEFAULT	0.5
#define		PID_RATE_ROLL_F2_DEFAULT	0.5
#define		PID_RATE_ROLL_OUT_FILT_CONSTANT		0.7

#define		RX_MAX_PULSE_WIDTH			2000	//in microseconds

#define		MPU_GYRO_DEG_SEC_TO_LSB		16.4     //This value can be used to convert deg/sec to LSB

#define		RESOLUTION_PID_KP			0.01
#define		RESOLUTION_PID_KI			0.001
#define		RESOLUTION_PID_KD			0.001
#define		RESOLUTION_PID_F			0.01

#define		SERIAL_COM_SPEED			921600
#define		SERIAL_PARSE_OVF_MULT		3

float		PID_THR_BATT_SCALE_FACTOR = 1.0;

struct structPID
{
	double Kp;
	double Ki;
	double Kd;
	double sensedVal;
	double setpoint;
	double output;
	double outputFiltered;
	float  outputFilterConstant;
	double outputCompensated;
	double outputLimitMin;
	double outputLimitMax;
	float f1;
	float f2;
	double d_bypass;
};
struct structSuperPID
{
	structPID ratePitch;
	structPID rateRoll;
	structPID rateYaw;
	structPID anglePitch;
	structPID angleRoll;
	structPID angleYaw;	
}pidVars;



//Enum Type Definitions, two mcu config files may be merged!
typedef enum
{
	statusType_Normal = 0,
	statusType_NotInitiated = 1,
	statusType_InitFail = 2,
	statusType_Fail = 3,
	statusType_UnreliableData = 4
}statusType;

typedef enum
{
	modeQuadSAFE = 0,
	modeQuadDirCmd = 1,
	modeQuadARMED = 2,
	modeQuadSpare = 3,

}modeQuadType;

typedef enum
{
	pidCommandNoAction = 0,
	pidCommandApplyRatePitch = 1,
	pidCommandApplyRateRoll = 2,
	pidCommandApplyRateYaw = 3,
	pidCommandApplyAnglePitch = 4,
	pidCommandApplyAngleRoll = 5,
	pidCommandApplyAngleYaw = 6,
}pidCommandType;

typedef enum
{
	buzzerMelodyNoTone = 0,
	buzzerMelodyArmWarning = 1,
}buzzerMelodyType;


//Global Variable Declarations
int test_task_counter = 0;

volatile uint32_t startTime_Thr;
volatile uint32_t startTime_Pitch;
volatile uint32_t startTime_Roll;
volatile uint32_t startTime_Yaw;

volatile unsigned short dutyCycle_Thr;
volatile unsigned short dutyCycle_Pitch;
volatile unsigned short dutyCycle_Roll;
volatile unsigned short dutyCycle_Yaw;


volatile uint32_t rxLastDataTime;

float cmdPitch = 0, cmdRoll = 0, cmdThr = 0, cmdYaw = 0;

//Status related declarations
unsigned char modeQuad;
unsigned char statusRx;
