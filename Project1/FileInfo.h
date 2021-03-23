#pragma once
#include "string"

namespace FileInfo
{
	class FileInformation
	{
	public:	double* dArray;
			int numberN;
			std::string info;

			FileInformation();

			FileInformation(double*, int, std::string);
	};
}