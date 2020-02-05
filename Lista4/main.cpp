#include "CFileLastError.h"
#include "CFileThrowEx.h"
#include "CFileErrCode.h"
#include "Zakres.h"
using namespace std;

bool CFileLastError::b_last_error = false;

int main()
{
	vector<string> vAlpha{ "a","b","c","d" };

	//CFileLastError::bSetLastError(false);
	CFileLastError cLastErrTest;
	cLastErrTest.vOpenFile("filename");
	cLastErrTest.bGetLastError();
	cLastErrTest.vPrintManyLines(vAlpha);
	cLastErrTest.vOpenNTimes("filename");
	cLastErrTest.bGetLastError();
	cLastErrTest.vCloseFile();
	cLastErrTest.bGetLastError();

	CFileThrowEx cExcTest;
	cExcTest.vOpenFile("filename1");
	cExcTest.vPrintManyLines(vAlpha);
	cExcTest.vOpenNTimes("filename");
	cExcTest.vCloseFile();

	CFileErrCode cErrTest("filename2");
	cErrTest.bPrintManyLines(vAlpha);
	cErrTest.bOpenNTimes("filename");
	cErrTest.bCloseFile();

	Zakres cTest1(0, 10, 13);
	Zakres cTest2;
	cTest1.setValue(12);
	//cTest1 = 4;
	cTest1 = cTest2;
	//cTest1 = 4;
	
	return 0;
}