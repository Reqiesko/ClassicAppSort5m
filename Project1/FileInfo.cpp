#include "FileInfo.h"

namespace FileInfo
{
	FileInformation::FileInformation()
	{
		numberN = 1;
		dArray = new double[numberN];
		info = "";
	}

	FileInformation::FileInformation(double* arrayD, int number, std::string text)
	{
		numberN = number;
		dArray = arrayD;
		info = text;
	}
}