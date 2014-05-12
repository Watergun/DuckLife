#include "ErrorReport.h"

int ERROR_REPORT::ErrorCount = 0;

ERROR_REPORT::ERROR_REPORT()
{
	ErrorCount = 0;
}

void ERROR_REPORT::ReportError(const char* ErrorMessage)
{
	std::cout << "[ERROR] " << ErrorMessage << std::endl;
	ErrorCount++;
}

void ERROR_REPORT::ReportError(const char* FileName,
				const char* ClassName,
				const char* FunctionName,
				const char* Topic,
				const char* Additional)
{
	std::cout << "[ERROR] REPORTED:" << std::endl;
	std::cout << "\tFile:\t\t" << FileName << std::endl;
	std::cout << "\tClass:\t\t" << ClassName << std::endl;
	std::cout << "\tFunction:\t" << FunctionName << std::endl;
	std::cout << "\tTopic:\t\t" << Topic << std::endl;
	if(Additional != NULL)
		std::cout << "\t*** " << Additional << " ***" << std::endl;
	std::cout << std::endl;

	ErrorCount++;
}

void ERROR_REPORT::ReportError(int ErrorCode)
{
	std::cout << "[ERROR] Errorcode: " << ErrorCode << std::endl;
	ErrorCount++;
}
