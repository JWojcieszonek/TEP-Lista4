#pragma once
#include <string>
#include <vector>
using namespace std;

class CFileLastError
{
public:
	CFileLastError();
	CFileLastError(string sFileName);
	~CFileLastError();

	void vOpenFile(string sFileName);
	void vCloseFile();
	void vPrintLine(string sText);
	void vPrintManyLines(vector<string> sText);
	void vOpenNTimes(string sFileName);
	static bool bGetLastError() ;

	static const int NUMBER_OF_ATTEMPTS;
private:
	FILE *pf_file;
	static bool b_last_error;

};

