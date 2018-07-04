#pragma once

/*****************************************************************************
Copyright: Chaos
File name: SystemConfig.h
Description: 系统四个配置文件的数据类型结构体定义
Author: Liu Changxin
Version: V1.0
Date: 2018/07/05
History: 无
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

//系统描述文件数据定义
typedef struct
{
	char siteID[20];				//Unique ID for each site
	char siteName[50];   			//Controller site name
	char siteCountry[50];			//Controller location country
	char siteProvince[50];			//province
	char siteCity[50];				//city
	double siteLongitude;		    //longitude
	double siteLatitude;			//latitude
	char siteTimeZone[50];
	char plantName[50];				//Unique plant number
	char plantNo[50];
	char equipmentName[50];			//Equipment Description in the plant
	char equipmentNo[50];
	char dataWatchName[50];    		//DNS Name for the DataWatch
	char dataWatchAssetID[50];		//Unique equipment Asset ID
	char dataWachAddedBy[50];		//User who edited settings
	char dataWachAddedDate[50];		//Date of settings’ creation (Time Stamp)

}SystemDesc;

//通道描述文件数据定义
typedef struct
{
	int sensorModuleNo; 			//The slot of the channel in the compact RIO(Valid value : between 1 and 8)  	
	int	sensorChannelNo; 			//The port of the channel on the module(Valid value : between 1 and 8)	
	char sensorType[50];			//Tachometer.High speed channels : Proximeter, Accelerometer, Fast voltage; Low speed channels : Temperature, Pressure, Valve Position, Slow current, Slow voltage	
	char sensorName[50];  			//Name of the Channel – recommend using naming convention in historian	
	float sensorSensitivity;		//Sensitivity of the channel(mV / EU or mA / EU)	
	char sensorEngineeringUnit[50];	//Engineering Unit
	bool sensorRangeCheck;     		//Send out alarm if out of range ? (True or False)
	float sensorRangeMin;			//Minimum input value for the channel	
	float sensorRangeMax;			//Maximum input value for the channel	
	float sensor1xAmplitudeRunout;	//1 time amplitude runout	
	float sensor1xPhaseRunout;   	//1 time phase runout	
	float sensorGapVoltage;      	//Gap Voltage of the probe	
	int sensorLocationInDegree;	    //The location of the probe(usually 0°, 45°, 90°, 135°)
	char sensorLeftOrRight[50];	    //The location of the probe, as seen by looking from the compressor	
	char shaftRotationDirection[50];//Clockwise(CW) or Counterclockwise(CCW)	
	int	speedRefChannelNo;       	//Speed reference channel, if any	
	float RPMMultiplier;	        //The multiple to applied to a pseudo key phasor 	
	int	pairChannelNo;	            //Paired x - y channel, if any	
	float bearingClearance;	        //Bearing initial clearance	
	char bearingStartPosition[50];	//Bearing Start Position(Valid Values : Bottom(default), Center, Top) 
	bool sensorICP;					//Turn on or off ICP to supply power
	bool couplingACDC;          	//Valid Values : AC / DC	
	float zeroScalePosition;	    //Voltage corresponding to valve’s 0 position	
	float fullScalePosition;     	//Voltage corresponding to valve’s full position	
	bool tachAutoTach;				//True or False, to use Sound and Vibration tool kit to auto - tach	
	char tachTriggerEdge[50];	    //Rising or falling edge	
	int tachTriggerPerRev;	        //Tachmeter triggers per revolution	
	float tachTriggerHysteresis; 	//Hysteresis setting	
	char tachTriggerVoltageLevel[50];	//Trigger level in voltage	
	char thermalCoupleType[50];  	//J, K, T, E, N, B, R, and S thermocouple types supported
	char userDefineProperty1[50];	//User defined parameter 1 to pass to Player and Viewer	string
	char userDefineProperty2[50];		
	char userDefineProperty3[50];		
	char userDefineProperty4[50];		
	char userDefineProperty5[50];		
	char userDefineProperty6[50];		
	char comments[100];
	char sensorConfigureDate[50];	//Last setting change date	(Time Stamp)

}ChannelDesc;

//触发条件描述文件数据定义
typedef struct
{
	char triggerEventName[50];	    //Name of the trigger event	
	char triggeredChannelName[50];	//Channel to be evaluated for the trigger event	
	char triggerType[50];       	//Indicates the type of analysis that will be performed to determine if an event has occurred[Time Interval, Time of Day, Delta EU, Delta Speed, Level]
	float triggerValue;	            //Specifies the time(in minutes) for Time Interval or Time of Day trigger types
	char triggerNotification[50];   //[Alarm, Danger]
	char preTriggerTime[50];    	//Time(in seconds) of pre - trigger data to record to file
	char postTriggerTime[50];	    //Time(in seconds) of post - trigger data to record to file	
	bool triggerGatingOn;	        //是否满足条件才触发？	
	float triggerGateLow;	        //Gating condition, low	
	float triggerGateHigh;	        //Gating condition, high	
	float gateOperator;       	    //Gating condition, > , <, > < , greater, less, greater and less than	
	char  triggerConfigDate[50];	//Last setting change date

}TriggerDesc;

//其它配置文件数据定义
typedef struct
{
	int tachSampleRate;          	//Tachometer sampling rate
	int	vibrationSampleRate;     	//Proximeter, vibration, and fast voltage channels’ sampling rate
	int	processDataSampleRate;	    //Temperature and other slow channels’ sampling rate
	int	scanPeriodFPGA;     	    //Scan period(seconds)
	int	preTriggerBuffer;	        //Pre - trigger buffer length(seconds)
	int	writingPeriodPLC;	        //PLC update period for spurious vibration(seconds)
	int	writtingPeriodOnlineDataBase;	//Update period to send data to online data base
	char secondaryDataPath[50];     //Valid values are : “”, “none”, “usb”, and “hard drive”
	char IPAddressDataWatch[50];   	//IP address of this controller
	char IPaddressDataBase[50];	    //IP address of online Data Server
	char IPAddressFTPServer[50];
	char lastConfigurationUpdated[50];	//Last setting change date

}OtherDesc;
