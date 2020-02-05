#include "CFileThrowEx.h"
#include<iostream>
using namespace std;

const int CFileThrowEx::NUMBER_OF_ATTEMPTS = 10;

CFileThrowEx::CFileThrowEx()
{
	pf_file = new FILE();
}

CFileThrowEx::CFileThrowEx(string sFileName)
{
	try
	{
		pf_file = fopen(sFileName.c_str(), "w+");
		if (pf_file == NULL)
		{
			throw 1;
		}
	}
	catch (int e)
	{
		cout << "An exception # " << e << '\n';
	}
}


CFileThrowEx::~CFileThrowEx()
{
	try
	{
		if (pf_file != NULL)
		{
			fclose(pf_file);
		}
		else
		{
			throw 2;
		}
	}
	catch (int e)
	{
		cout << "An exception # " << e << '\n';
	}

}

void CFileThrowEx::vOpenFile(string sFileName)
{
	try
	{
		pf_file = fopen(sFileName.c_str(), "w+");
		if (pf_file == NULL)
		{
			throw 1;
		}
	}
	catch (int e)
	{
		cout << "An exception # " << e << '\n';
	}
}

void CFileThrowEx::vCloseFile()
{
	try
	{
		if (pf_file != NULL)
		{
			fclose(pf_file);
		}
		else
		{
			throw 2;
		}
	}
	catch (int e)
	{
		cout << "An exception # " << e << '\n';
	}
}

void CFileThrowEx::vPrintLine(string sText)
{
	try
	{
		if (pf_file != NULL)
		{			
			fprintf(pf_file, sText.c_str());
		}
		else
		{
			throw 3;
		}
	}
	catch (int e)
	{
		cout << "An exception # " << e << '\n';
	}
}

void CFileThrowEx::vPrintManyLines(vector<string> sText)
{
	try
	{
		if (pf_file != NULL)
		{
			for (vector<string>::iterator it = sText.begin(); it != sText.end(); ++it)
			{
				fprintf(pf_file, (*it).c_str());
			}
		}
		else
		{
			throw 3;
		}
	}
	catch (int e)
	{
		cout << "An exception # " << e << '\n';
	}
}

void CFileThrowEx::vOpenNTimes(string sFileName)
{
	try
	{
		for (int i = 0; i < NUMBER_OF_ATTEMPTS; i++)
		{
			vOpenFile(sFileName);
		}
	}
	catch (int e)
	{
		cout << "An exception # " << e << '\n';
	}
}
