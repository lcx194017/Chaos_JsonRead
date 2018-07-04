/*****************************************************************************
Copyright: Chaos
File name: SystemConfig.c
Description: 系统四个配置文件的数据变换，（1）将数据以Json格式写入配置文件 （2）从Json配置文件读取数据
Author: Liu Changxin
Version: V1.0
Date: 2018/07/05
History: 无
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "SystemConfigh.h"

/*************************************************
Function: makeSystemDescJson
Description: 将系统配置描述数据以Json格式写入文件
Input: SystemDesc类型的数据
Return: Json数据指针
Others: 无
*************************************************/
char* makeSystemDescJson(SystemDesc systemDesc)
{
	cJSON * pJsonRoot = NULL;

	pJsonRoot = cJSON_CreateObject();
	if (NULL == pJsonRoot)
		return NULL;

	cJSON_AddStringToObject(pJsonRoot, "siteID", systemDesc.siteID);
	cJSON_AddStringToObject(pJsonRoot, "siteName", systemDesc.siteName);
	cJSON_AddStringToObject(pJsonRoot, "siteCountry", systemDesc.siteCountry);
	cJSON_AddStringToObject(pJsonRoot, "siteProvince", systemDesc.siteProvince);
	cJSON_AddStringToObject(pJsonRoot, "siteCity", systemDesc.siteCity);
	cJSON_AddNumberToObject(pJsonRoot, "siteLongitude", systemDesc.siteLongitude);
	cJSON_AddNumberToObject(pJsonRoot, "siteLatitude", systemDesc.siteLatitude);
	cJSON_AddStringToObject(pJsonRoot, "siteTimeZone", systemDesc.siteTimeZone);
	cJSON_AddStringToObject(pJsonRoot, "plantName", systemDesc.plantName);
	cJSON_AddStringToObject(pJsonRoot, "plantNo", systemDesc.plantNo);
	cJSON_AddStringToObject(pJsonRoot, "equipmentName", systemDesc.equipmentName);
	cJSON_AddStringToObject(pJsonRoot, "equipmentNo", systemDesc.equipmentNo);
	cJSON_AddStringToObject(pJsonRoot, "dataWatchName", systemDesc.dataWatchName);
	cJSON_AddStringToObject(pJsonRoot, "dataWatchAssetID", systemDesc.dataWatchAssetID);
	cJSON_AddStringToObject(pJsonRoot, "dataWachAddedBy", systemDesc.dataWachAddedBy);
	cJSON_AddStringToObject(pJsonRoot, "dataWachAddedDate", systemDesc.dataWachAddedDate);

	char * pJsonData = cJSON_Print(pJsonRoot);
	if (NULL == pJsonData)
	{
		cJSON_Delete(pJsonRoot);
		return NULL;
	}
	cJSON_Delete(pJsonRoot);
	return pJsonData;
}

/*************************************************
Function: makeChannelDescJson
Description: 将通道描述文件数据以Json格式写入文件
Input: ChannelDesc类型的数据
Return: Json数据指针
Others: 无
*************************************************/
char* makeChannelDescJson(ChannelDesc channelDesc)
{
	cJSON * pJsonRoot = NULL;

	pJsonRoot = cJSON_CreateObject();
	if (NULL == pJsonRoot)
		return NULL;
	cJSON_AddNumberToObject(pJsonRoot, "sensorModuleNo", channelDesc.sensorModuleNo);
	cJSON_AddNumberToObject(pJsonRoot, "sensorChannelNo", channelDesc.sensorChannelNo);
	cJSON_AddStringToObject(pJsonRoot, "sensorType", channelDesc.sensorType);
	cJSON_AddStringToObject(pJsonRoot, "sensorName", channelDesc.sensorName);
	cJSON_AddNumberToObject(pJsonRoot, "sensorSensitivity", channelDesc.sensorSensitivity);
	cJSON_AddStringToObject(pJsonRoot, "sensorEngineeringUnit", channelDesc.sensorEngineeringUnit);
	cJSON_AddBoolToObject(pJsonRoot, "sensorRangeCheck", channelDesc.sensorRangeCheck);
	cJSON_AddNumberToObject(pJsonRoot, "sensorRangeMin", channelDesc.sensorRangeMin);
	cJSON_AddNumberToObject(pJsonRoot, "sensorRangeMax", channelDesc.sensorRangeMax);
	cJSON_AddNumberToObject(pJsonRoot, "sensor1xAmplitudeRunout", channelDesc.sensor1xAmplitudeRunout);
	cJSON_AddNumberToObject(pJsonRoot, "sensor1xPhaseRunout", channelDesc.sensor1xPhaseRunout);
	cJSON_AddNumberToObject(pJsonRoot, "sensorGapVoltage", channelDesc.sensorGapVoltage);
	cJSON_AddNumberToObject(pJsonRoot, "sensorLocationInDegree", channelDesc.sensorLocationInDegree);
	cJSON_AddStringToObject(pJsonRoot, "sensorLeftOrRight", channelDesc.sensorLeftOrRight);
	cJSON_AddStringToObject(pJsonRoot, "shaftRotationDirection", channelDesc.shaftRotationDirection);
	cJSON_AddNumberToObject(pJsonRoot, "speedRefChannelNo", channelDesc.speedRefChannelNo);
	cJSON_AddNumberToObject(pJsonRoot, "RPMMultiplier", channelDesc.RPMMultiplier);
	cJSON_AddNumberToObject(pJsonRoot, "pairChannelNo", channelDesc.pairChannelNo);
	cJSON_AddNumberToObject(pJsonRoot, "bearingClearance", channelDesc.bearingClearance);
	cJSON_AddStringToObject(pJsonRoot, "bearingStartPosition", channelDesc.bearingStartPosition);
	cJSON_AddBoolToObject(pJsonRoot, "sensorICP", channelDesc.sensorICP);
	cJSON_AddBoolToObject(pJsonRoot, "couplingACDC", channelDesc.couplingACDC);
	cJSON_AddNumberToObject(pJsonRoot, "zeroScalePosition", channelDesc.zeroScalePosition);
	cJSON_AddNumberToObject(pJsonRoot, "fullScalePosition", channelDesc.fullScalePosition);
	cJSON_AddBoolToObject(pJsonRoot, "tachAutoTach", channelDesc.tachAutoTach);
	cJSON_AddStringToObject(pJsonRoot, "tachTriggerEdge", channelDesc.tachTriggerEdge);
	cJSON_AddNumberToObject(pJsonRoot, "tachTriggerPerRev", channelDesc.tachTriggerPerRev);
	cJSON_AddNumberToObject(pJsonRoot, "tachTriggerHysteresis", channelDesc.tachTriggerHysteresis);
	cJSON_AddStringToObject(pJsonRoot, "tachTriggerVoltageLevel", channelDesc.tachTriggerVoltageLevel);
	cJSON_AddStringToObject(pJsonRoot, "thermalCoupleType", channelDesc.thermalCoupleType);
	cJSON_AddStringToObject(pJsonRoot, "userDefineProperty1", channelDesc.userDefineProperty1);
	cJSON_AddStringToObject(pJsonRoot, "userDefineProperty2", channelDesc.userDefineProperty2);
	cJSON_AddStringToObject(pJsonRoot, "userDefineProperty3", channelDesc.userDefineProperty3);
	cJSON_AddStringToObject(pJsonRoot, "userDefineProperty4", channelDesc.userDefineProperty4);
	cJSON_AddStringToObject(pJsonRoot, "userDefineProperty5", channelDesc.userDefineProperty5);
	cJSON_AddStringToObject(pJsonRoot, "userDefineProperty6", channelDesc.userDefineProperty6);
	cJSON_AddStringToObject(pJsonRoot, "comments", channelDesc.comments);
	cJSON_AddStringToObject(pJsonRoot, "sensorConfigureDate", channelDesc.sensorConfigureDate);

	char * pJsonData = cJSON_Print(pJsonRoot);
	if (NULL == pJsonData)
	{
		cJSON_Delete(pJsonRoot);
		return NULL;
	}
	cJSON_Delete(pJsonRoot);
	return pJsonData;
}

/*************************************************
Function: makeTriggerDescJson
Description: 将触发条件描述文件数据以Json格式写入文件
Input: TriggerDesc类型的数据
Return: Json数据指针
Others: 无
*************************************************/
char* makeTriggerDescJson(TriggerDesc triggerDesc)
{
	cJSON * pJsonRoot = NULL;

	pJsonRoot = cJSON_CreateObject();
	if (NULL == pJsonRoot)
		return NULL;

	cJSON_AddStringToObject(pJsonRoot, "triggerEventName", triggerDesc.triggerEventName);
	cJSON_AddStringToObject(pJsonRoot, "triggeredChannelName", triggerDesc.triggeredChannelName);
	cJSON_AddStringToObject(pJsonRoot, "triggerType", triggerDesc.triggerType);
	cJSON_AddNumberToObject(pJsonRoot, "triggerValue", triggerDesc.triggerValue);
	cJSON_AddStringToObject(pJsonRoot, "triggerNotification", triggerDesc.triggerNotification);
	cJSON_AddStringToObject(pJsonRoot, "preTriggerTime", triggerDesc.preTriggerTime);
	cJSON_AddStringToObject(pJsonRoot, "postTriggerTime", triggerDesc.postTriggerTime);
	cJSON_AddBoolToObject(pJsonRoot, "triggerGatingOn", triggerDesc.triggerGatingOn);
	cJSON_AddNumberToObject(pJsonRoot, "triggerGateLow", triggerDesc.triggerGateLow);
	cJSON_AddNumberToObject(pJsonRoot, "triggerGateHigh", triggerDesc.triggerGateHigh);
	cJSON_AddNumberToObject(pJsonRoot, "gateOperator", triggerDesc.gateOperator);
	cJSON_AddStringToObject(pJsonRoot, "triggerConfigDate", triggerDesc.triggerConfigDate);

	char * pJsonData = cJSON_Print(pJsonRoot);
	if (NULL == pJsonData)
	{
		cJSON_Delete(pJsonRoot);
		return NULL;
	}
	cJSON_Delete(pJsonRoot);
	return pJsonData;
}

/*************************************************
Function: makeOtherDescJson
Description: 将其它描述文件数据以Json格式写入文件
Input: OtherDesc类型的数据
Return: Json数据指针
Others: 无
*************************************************/
char* makeOtherDescJson(OtherDesc otherDesc)
{
	cJSON * pJsonRoot = NULL;

	pJsonRoot = cJSON_CreateObject();
	if (NULL == pJsonRoot)
		return NULL;

	cJSON_AddNumberToObject(pJsonRoot, "tachSampleRate", otherDesc.tachSampleRate);
	cJSON_AddNumberToObject(pJsonRoot, "vibrationSampleRate", otherDesc.vibrationSampleRate);
	cJSON_AddNumberToObject(pJsonRoot, "processDataSampleRate", otherDesc.processDataSampleRate);
	cJSON_AddNumberToObject(pJsonRoot, "scanPeriodFPGA", otherDesc.scanPeriodFPGA);
	cJSON_AddNumberToObject(pJsonRoot, "preTriggerBuffer", otherDesc.preTriggerBuffer);
	cJSON_AddNumberToObject(pJsonRoot, "writingPeriodPLC", otherDesc.writingPeriodPLC);
	cJSON_AddNumberToObject(pJsonRoot, "writtingPeriodOnlineDataBase", otherDesc.writtingPeriodOnlineDataBase);
	cJSON_AddStringToObject(pJsonRoot, "secondaryDataPath", otherDesc.secondaryDataPath);
	cJSON_AddStringToObject(pJsonRoot, "IPAddressDataWatch", otherDesc.IPAddressDataWatch);
	cJSON_AddStringToObject(pJsonRoot, "IPaddressDataBase", otherDesc.IPaddressDataBase);
	cJSON_AddStringToObject(pJsonRoot, "IPAddressFTPServer", otherDesc.IPAddressFTPServer);
	cJSON_AddStringToObject(pJsonRoot, "lastConfigurationUpdated", otherDesc.lastConfigurationUpdated);
	

	char * pJsonData = cJSON_Print(pJsonRoot);
	if (NULL == pJsonData)
	{
		cJSON_Delete(pJsonRoot);
		return NULL;
	}
	cJSON_Delete(pJsonRoot);
	return pJsonData;
}

/*************************************************
Function: parseSystemDescJson
Description: 读取系统配置Json文件
Input: pMsg：数据源指针  systemDesc：解析后数据存放指针
Return: bool 是否解析成功
Others: 无
*************************************************/
bool parseSystemDescJson(char * pMsg, SystemDesc *systemDesc)
{
	if (NULL == pMsg)
		return false;

	cJSON * pJson = cJSON_Parse(pMsg);
	if (NULL == pJson)
		return false;


	cJSON *item;
	bool readStatusFlag = true;

	item = cJSON_GetObjectItem(pJson, "siteID");
	if (item != NULL)
		memcpy(systemDesc->siteID, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "siteName");
	if (item != NULL)
		memcpy(systemDesc->siteName, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "siteCountry");
	if (item != NULL)
		memcpy(systemDesc->siteCountry, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "siteProvince");
	if (item != NULL)
		memcpy(systemDesc->siteProvince, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "siteCity");
	if (item != NULL)
		memcpy(systemDesc->siteCity, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "siteLongitude");
	if (item != NULL)
		systemDesc->siteLongitude = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "siteLatitude");
	if (item != NULL)
		systemDesc->siteLatitude = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "siteTimeZone");
	if (item != NULL)
		memcpy(systemDesc->siteTimeZone, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "plantName");
	if (item != NULL)
		memcpy(systemDesc->plantName, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "plantNo");
	if (item != NULL)
		memcpy(systemDesc->plantNo, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "equipmentName");
	if (item != NULL)
		memcpy(systemDesc->equipmentName, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "equipmentNo");
	if (item != NULL)
		memcpy(systemDesc->equipmentNo, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "dataWatchName");
	if (item != NULL)
		memcpy(systemDesc->dataWatchName, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "dataWatchAssetID");
	if (item != NULL)
		memcpy(systemDesc->dataWatchAssetID, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "dataWachAddedBy");
	if (item != NULL)
		memcpy(systemDesc->dataWachAddedBy, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "dataWachAddedDate");
	if (item != NULL)
		memcpy(systemDesc->dataWachAddedDate, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	cJSON_Delete(pJson);

	return readStatusFlag;
}

/*************************************************
Function: parseChannelDescJson
Description: 读取通道描述配置Json文件
Input: pMsg：数据源指针  channelDesc：解析后数据存放指针
Return: bool 是否解析成功
Others: 无
*************************************************/
bool parseChannelDescJson(char * pMsg, ChannelDesc *channelDesc)
{
	if (NULL == pMsg)
		return false;

	cJSON * pJson = cJSON_Parse(pMsg);
	if (NULL == pJson)
		return false;


	cJSON *item;
	bool readStatusFlag = true;

	item = cJSON_GetObjectItem(pJson, "sensorModuleNo");
	if (item != NULL)
		channelDesc->sensorModuleNo = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "sensorChannelNo");
	if (item != NULL)
		channelDesc->pairChannelNo = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "sensorType");
	if (item != NULL)
		memcpy(channelDesc->sensorType, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "sensorName");
	if (item != NULL)
		memcpy(channelDesc->sensorName, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "sensorSensitivity");
	if (item != NULL)
		channelDesc->sensorSensitivity = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "sensorEngineeringUnit");
	if (item != NULL)
		memcpy(channelDesc->sensorEngineeringUnit, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "sensorRangeCheck");
	if (item != NULL)
		channelDesc->sensorRangeCheck = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "sensorRangeMin");
	if (item != NULL)
		channelDesc->sensorRangeMin = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "sensorRangeMax");
	if (item != NULL)
		channelDesc->sensorRangeMax = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "sensor1xAmplitudeRunout");
	if (item != NULL)
		channelDesc->sensor1xAmplitudeRunout = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "sensor1xPhaseRunout");
	if (item != NULL)
		channelDesc->sensor1xAmplitudeRunout = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "sensorGapVoltage");
	if (item != NULL)
		channelDesc->sensorGapVoltage = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "sensorLocationInDegree");
	if (item != NULL)
		channelDesc->sensorLocationInDegree = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "sensorLeftOrRight");
	if (item != NULL)
		memcpy(channelDesc->sensorLeftOrRight, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "shaftRotationDirection");
	if (item != NULL)
		memcpy(channelDesc->shaftRotationDirection, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "speedRefChannelNo");
	if (item != NULL)
		channelDesc->speedRefChannelNo = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "RPMMultiplier");
	if (item != NULL)
		channelDesc->RPMMultiplier = item->valuedouble;
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "pairChannelNo");
	if (item != NULL)
		channelDesc->pairChannelNo = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "bearingClearance");
	if (item != NULL)
		channelDesc->bearingClearance = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "bearingStartPosition");
	if (item != NULL)
		memcpy(channelDesc->bearingStartPosition, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "sensorICP");
	if (item != NULL)
		channelDesc->sensorICP = item->valueint;
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "couplingACDC");
	if (item != NULL)
		channelDesc->couplingACDC = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "zeroScalePosition");
	if (item != NULL)
		channelDesc->zeroScalePosition = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "fullScalePosition");
	if (item != NULL)
		channelDesc->fullScalePosition = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "tachAutoTach");
	if (item != NULL)
		channelDesc->tachAutoTach = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "tachTriggerEdge");
	if (item != NULL)
		memcpy(channelDesc->tachTriggerEdge, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "tachTriggerPerRev");
	if (item != NULL)
		channelDesc->tachTriggerPerRev = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "tachTriggerHysteresis");
	if (item != NULL)
		channelDesc->tachTriggerHysteresis = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "tachTriggerVoltageLevel");
	if (item != NULL)
		memcpy(channelDesc->tachTriggerVoltageLevel, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "thermalCoupleType");
	if (item != NULL)
		memcpy(channelDesc->thermalCoupleType, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "userDefineProperty1");
	if (item != NULL)
		memcpy(channelDesc->userDefineProperty1, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "userDefineProperty2");
	if (item != NULL)
		memcpy(channelDesc->userDefineProperty2, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "userDefineProperty3");
	if (item != NULL)
		memcpy(channelDesc->userDefineProperty3, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "userDefineProperty4");
	if (item != NULL)
		memcpy(channelDesc->userDefineProperty4, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "userDefineProperty5");
	if (item != NULL)
		memcpy(channelDesc->userDefineProperty5, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "userDefineProperty6");
	if (item != NULL)
		memcpy(channelDesc->userDefineProperty6, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "comments");
	if (item != NULL)
		memcpy(channelDesc->comments, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "sensorConfigureDate");
	if (item != NULL)
		memcpy(channelDesc->sensorConfigureDate, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	cJSON_Delete(pJson);

	return readStatusFlag;
}

/*************************************************
Function: parseTriggerDescJson
Description: 读取触发条件描述配置Json文件
Input: pMsg：数据源指针  triggerDesc：解析后数据存放指针
Return: bool 是否解析成功
Others: 无
*************************************************/
bool parseTriggerDescJson(char * pMsg, TriggerDesc *triggerDesc)
{
	if (NULL == pMsg)
		return false;

	cJSON * pJson = cJSON_Parse(pMsg);
	if (NULL == pJson)
		return false;


	cJSON *item;
	bool readStatusFlag = true;

	item = cJSON_GetObjectItem(pJson, "triggerEventName");
	if (item != NULL)
		memcpy(triggerDesc->triggerEventName, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "triggeredChannelName");
	if (item != NULL)
		memcpy(triggerDesc->triggeredChannelName, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "triggerType");
	if (item != NULL)
		memcpy(triggerDesc->triggerType, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "triggerValue");
	if (item != NULL)
		triggerDesc->triggerValue = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "triggerNotification");
	if (item != NULL)
		memcpy(triggerDesc->triggerNotification, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "preTriggerTime");
	if (item != NULL)
		memcpy(triggerDesc->preTriggerTime, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "postTriggerTime");
	if (item != NULL)
		memcpy(triggerDesc->postTriggerTime, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "triggerGatingOn");
	if (item != NULL)
		triggerDesc->triggerGatingOn = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "triggerGateLow");
	if (item != NULL)
		triggerDesc->triggerGateLow = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "triggerGateHigh");
	if (item != NULL)
		triggerDesc->triggerGateHigh = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "gateOperator");
	if (item != NULL)
		triggerDesc->gateOperator = item->valuedouble;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "triggerConfigDate");
	if (item != NULL)
		memcpy(triggerDesc->triggerConfigDate, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	cJSON_Delete(pJson);

	return readStatusFlag;
}

/*************************************************
Function: parseOtherDescJson
Description: 读取其他配置Json文件
Input: pMsg：数据源指针  otherDesc：解析后数据存放指针
Return: bool 是否解析成功
Others: 无
*************************************************/
bool parseOtherDescJson(char * pMsg, OtherDesc *otherDesc)
{
	if (NULL == pMsg)
		return false;

	cJSON * pJson = cJSON_Parse(pMsg);
	if (NULL == pJson)
		return false;


	cJSON *item;
	bool readStatusFlag = true;

	item = cJSON_GetObjectItem(pJson, "tachSampleRate");
	if (item != NULL)
		otherDesc->tachSampleRate = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "vibrationSampleRate");
	if (item != NULL)
		otherDesc->vibrationSampleRate = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "processDataSampleRate");
	if (item != NULL)
		otherDesc->processDataSampleRate = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "scanPeriodFPGA");
	if (item != NULL)
		otherDesc->scanPeriodFPGA = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "preTriggerBuffer");
	if (item != NULL)
		otherDesc->preTriggerBuffer = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "writingPeriodPLC");
	if (item != NULL)
		otherDesc->writingPeriodPLC = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "writtingPeriodOnlineDataBase");
	if (item != NULL)
		otherDesc->writtingPeriodOnlineDataBase = item->valueint;
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "secondaryDataPath");
	if (item != NULL)
		memcpy(otherDesc->secondaryDataPath, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "IPAddressDataWatch");
	if (item != NULL)
		memcpy(otherDesc->IPAddressDataWatch, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "IPaddressDataBase");
	if (item != NULL)
		memcpy(otherDesc->IPaddressDataBase, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "IPAddressFTPServer");
	if (item != NULL)
		memcpy(otherDesc->IPAddressFTPServer, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	item = cJSON_GetObjectItem(pJson, "lastConfigurationUpdated");
	if (item != NULL)
		memcpy(otherDesc->lastConfigurationUpdated, item->valuestring, strlen(item->valuestring));
	else
		readStatusFlag = false;

	cJSON_Delete(pJson);

	return readStatusFlag;
}
