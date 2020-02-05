#include "CFileErrCode.h"

const int CFileErrCode::NUMBER_OF_ATTEMPTS = 10;

CFileErrCode::CFileErrCode()
{
	pf_file = NULL;
}

CFileErrCode::CFileErrCode(string sFileName)
{
	pf_file = fopen(sFileName.c_str(), "w+");
	if (pf_file == NULL)
	{
		
	}
}

CFileErrCode::CFileErrCode(string sFileName, bool* bErrCode)
{
	*bErrCode = false;
	pf_file = fopen(sFileName.c_str(), "w+");
	if (pf_file != NULL)
	{
		*bErrCode = true;
	}
}



CFileErrCode::~CFileErrCode()
{
	if (pf_file != NULL)
	{
		fclose(pf_file);
	}
	else
	{
		
	}
}

bool CFileErrCode::bOpenFile(string sFileName)
{

	pf_file = fopen(sFileName.c_str(), "w+");
	if (pf_file == NULL)
	{
		return false;
	}
	return true;
}

bool CFileErrCode::bCloseFile()
{

	if (pf_file != NULL)
	{
		fclose(pf_file);
		return true;
	}
	else
	{
		return false;
	}
	
}

bool CFileErrCode::bPrintLine(string sText)
{
	if (pf_file != NULL)
	{
		fprintf(pf_file, sText.c_str());
		return true;
	}
	else
	{
		return false;
	}
	
}

bool CFileErrCode::bPrintManyLines(vector<string> sText)
{
	if (pf_file != NULL)
	{
		for (vector<string>::iterator it = sText.begin(); it != sText.end(); ++it)
		{
			fprintf(pf_file, (*it).c_str());
		}
		return true;
	}
	else
	{
		return false;
	}
	
}

bool CFileErrCode::bOpenNTimes(string sFileName)
{
	for (int i = 0; i < NUMBER_OF_ATTEMPTS; i++)
	{
		pf_file = fopen(sFileName.c_str(), "w+");
	}
	if (pf_file != NULL)
		return true;
	else
		return false;
}
		