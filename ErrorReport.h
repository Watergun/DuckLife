#ifndef ERROR_REPORT_H
#define ERROR_REPORT_H

#include <iostream>
#include <cstdlib>

class ERROR_REPORT
{

public:
	//Constructor
	ERROR_REPORT()
       	{
		ErrorCount = 0;
	};
	
	static int ErrorCount;
	//
	static int ReportError(char* Message);
	static int ReportError(char* FileName, char* ClassName, char* FunctionName, char* Topic, char* Additional = 0);
	static int ReportError(int ErrorCode);
};

#endif
