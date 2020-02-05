#pragma once
#include <string>
#include <vector>

using namespace std;
class CFileErrCode
{
public:
	CFileErrCode();
	CFileErrCode(string sFileName);
	CFileErrCode(string sFileName, bool* bErrCode);
	~CFileErrCode();

	bool bOpenFile(string sFileName);
	bool bCloseFile();
	bool bPrintLine(string sText);
	bool bPrintManyLines(vector<string> sText);
	bool bOpenNTimes(string sFileName);

	static const int NUMBER_OF_ATTEMPTS;

private:
	FILE *pf_file;
};

