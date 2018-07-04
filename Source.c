#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "SystemConfigh.h"


char* makeSystemDescJson(SystemDesc systemDesc);
bool parseSystemDescJson(char * pMsg, SystemDesc *systemDesc);

int main()
{
	SystemDesc systemDesc = { 0 };
	memcpy(systemDesc.siteID, "001", strlen("001"));
	memcpy(systemDesc.siteName, "玄武区", strlen("玄武区"));
	memcpy(systemDesc.siteCountry, "中国", strlen("中国"));
	memcpy(systemDesc.siteProvince, "江苏", strlen("江苏"));
	memcpy(systemDesc.siteCity, "南京", strlen("南京"));
	systemDesc.siteLongitude = 1.111111;
	systemDesc.siteLatitude = 2.222222;
	memcpy(systemDesc.siteTimeZone, "aaaa", strlen("aaaa"));
	memcpy(systemDesc.plantName, "bbbb", strlen("bbbb"));
	memcpy(systemDesc.plantNo, "002", strlen("002"));
	memcpy(systemDesc.equipmentName, "设备名称", strlen("设备名称"));
	memcpy(systemDesc.equipmentNo, "003", strlen("003"));
	memcpy(systemDesc.dataWatchName, "cccc", strlen("cccc"));
	memcpy(systemDesc.dataWatchAssetID, "004", strlen("004"));
	memcpy(systemDesc.dataWachAddedBy, "张三", strlen("张三"));
	memcpy(systemDesc.dataWachAddedDate, "2018/07/05", strlen("2018/07/05"));

	char* p = makeSystemDescJson(systemDesc);
	if (NULL == p)
	{
		printf("transfer data to json error!");
		return 0;
	}
	//写入文件
	FILE *f;
	fopen_s(&f, "systemDesc.json", "w");
	if (f == NULL)
	{
		printf("open file error!");
		return 0;
	}
	fprintf_s(f, "%s", p);
	fclose(f);
	free(p);


	//读取文件测试
	FILE *file;
	long len;
	char *content;
	fopen_s(&file, "systemDesc.json", "r");
	if (file == NULL)
	{
		printf("open file error!");
		return 0;
	}
	fseek(file, 0, SEEK_END);
	len = ftell(file);
	fseek(file, 0, SEEK_SET);
	content = (char*)malloc(len + 1);
	fread(content, 1, len, file);
	fclose(file);

	//从文件中读取Json数据
	SystemDesc person = { 0 };
	bool flag = parseSystemDescJson(content, &person);
	return 0;
}