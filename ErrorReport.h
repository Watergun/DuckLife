#ifndef ERROR_REPORT_H
#define ERROR_REPORT_H

#include <iostream>
#include <cstdlib>

class ERROR_REPORT
{

public:
	//Constructor
	ERROR_REPORT();

	static int ErrorCount;
	//
	static void ReportError(const char* ErrorMessage);
	static void ReportError(const char* FileName,
				const char* ClassName,
				const char* FunctionName,
				const char* Topic,
				const char* Additional = NULL);
	static void ReportError(int ErrorCode);
};

inline void REP_ERR(const char* MSG)
{
	ERROR_REPORT::ReportError(MSG);
}

inline void REP_ERR(const char* FILE,
		    const char* CLASS,
		    const char* FUNCTION,
		    const char* TOPIC,
		    const char* ADDITIONAL)
{
	ERROR_REPORT::ReportError(FILE,CLASS,FUNCTION,TOPIC,ADDITIONAL);
}

inline void REP_ERR(const char* FILE,
		    const char* CLASS,
		    const char* FUNCTION,
		    const char* TOPIC)
{
	ERROR_REPORT::ReportError(FILE,CLASS,FUNCTION,TOPIC);
}

inline void REP_ERR(int ERROR_CODE)
{
	ERROR_REPORT::ReportError(ERROR_CODE);
}

#endif
