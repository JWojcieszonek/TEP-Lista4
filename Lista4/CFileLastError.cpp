#include "CFileLastError.h"
#include <iostream>
using namespace std;

const int CFileLastError::NUMBER_OF_ATTEMPTS = 10;

CFileLastError::CFileLastError()
{
	b_last_error = false;
	pf_file = NULL;
}

CFileLastError::CFileLastError(string sFileName)
{
	//const char* c_file_name = sFileName.c_str();
	b_last_error = false;
	pf_file = fopen(sFileName.c_str(), "w+");
	if (pf_file == NULL)
	{
		b_last_error = true;
		return;
	}
}


CFileLastError::~CFileLastError()
{
	b_last_error = false;
	if (pf_file != NULL)
	{
		fclose(pf_file);
	}
	else
	{
		b_last_error = true;
		return;
	}
}

void CFileLastError::vOpenFile(string sFileName)
{
	b_last_error = false;
	pf_file = fopen(sFileName.c_str(), "w+");
	if (pf_file == NULL)
	{
		b_last_error = true;
		return;
	}
}

void CFileLastError::vCloseFile()
{
	b_last_error = false;
	
	if (pf_file != NULL)
	{
		fclose(pf_file);
	}
	else
	{
		b_last_error = true;
		return;
	}
		
}

void CFileLastError::vPrintLine(string sText)
{
	b_last_error = false;
	if (pf_file != NULL)
	{
		fprintf(pf_file, sText.c_str());
	}
	else
	{
		b_last_error = true;
		return;
	}
}

void CFileLastError::vPrintManyLines(vector<string> sText)
{
	b_last_error = false;
	if (pf_file != NULL)
	{
		for (vector<string>::iterator it = sText.begin(); it != sText.end(); ++it)
		{
			fprintf(pf_file, (*it).c_str());
		}
	}
	else
	{
		b_last_error = true;
		return;
	}
}

bool CFileLastError::bGetLastError()
{
	cout << b_last_error << endl;
	return b_last_error;
}

void CFileLastError::vOpenNTimes(string sFileName)
{
	b_last_error = false;
	for (int i = 0; i < NUMBER_OF_ATTEMPTS; i++)
	{
		vOpenFile(sFileName);
	}	
	
}

