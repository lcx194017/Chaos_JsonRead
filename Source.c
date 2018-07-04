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
	memcpy(systemDesc.siteName, "������", strlen("������"));
	memcpy(systemDesc.siteCountry, "�й�", strlen("�й�"));
	memcpy(systemDesc.siteProvince, "����", strlen("����"));
	memcpy(systemDesc.siteCity, "�Ͼ�", strlen("�Ͼ�"));
	systemDesc.siteLongitude = 1.111111;
	systemDesc.siteLatitude = 2.222222;
	memcpy(systemDesc.siteTimeZone, "aaaa", strlen("aaaa"));
	memcpy(systemDesc.plantName, "bbbb", strlen("bbbb"));
	memcpy(systemDesc.plantNo, "002", strlen("002"));
	memcpy(systemDesc.equipmentName, "�豸����", strlen("�豸����"));
	memcpy(systemDesc.equipmentNo, "003", strlen("003"));
	memcpy(systemDesc.dataWatchName, "cccc", strlen("cccc"));
	memcpy(systemDesc.dataWatchAssetID, "004", strlen("004"));
	memcpy(systemDesc.dataWachAddedBy, "����", strlen("����"));
	memcpy(systemDesc.dataWachAddedDate, "2018/07/05", strlen("2018/07/05"));

	char* p = makeSystemDescJson(systemDesc);
	if (NULL == p)
	{
		printf("transfer data to json error!");
		return 0;
	}
	//д���ļ�
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


	//��ȡ�ļ�����
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

	//���ļ��ж�ȡJson����
	SystemDesc person = { 0 };
	bool flag = parseSystemDescJson(content, &person);
	return 0;
}