#pragma once
#include <string>
#include <vector>
using namespace std;

class CFileThrowEx
{
public:
	CFileThrowEx();
	CFileThrowEx(string sFileName);
	~CFileThrowEx();

	void vOpenFile(string sFileName);
	void vCloseFile();
	void vPrintLine(string sText);
	void vPrintManyLines(vector<string> sText);
	void vOpenNTimes(string sFileName);

	static const int NUMBER_OF_ATTEMPTS;

private:
	FILE *pf_file;
};

