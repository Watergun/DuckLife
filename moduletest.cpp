#include "InfoMessage.h"
#include "CModel.h"

int main()
{
	CModel model("filename");

	INFO_MSG("Model loaded at",(int)&model);
	return 0;
}
