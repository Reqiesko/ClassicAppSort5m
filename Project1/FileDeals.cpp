#include "FileDeals.h"
#include "fstream"
#include <list>
#include <msclr/gcroot.h>
#include <msclr/marshal_cppstd.h>

using namespace std;
using namespace ArrayIssue;

ifstream* OpenFile(string fileSource)
{
	ifstream* fileStream = new ifstream;
	(*fileStream).open(fileSource);
	return fileStream;
}

ofstream* OpenSaveFile(string fileSource)
{
	ofstream* fileStream = new ofstream;
	(*fileStream).open(fileSource);
	return fileStream;
}

ReadFileErrors GetArray(ifstream* fileStream, Array& nArray)
{
	double number = 0;
	list<double>* nList = new list<double>();
	string text;
	while (getline(*fileStream, text))
	{
		if (!GetValue(gcnew System::String(text.c_str()), *nList) && !System::String::IsNullOrEmpty(gcnew System::String(text.c_str())))
			return IncorrectFormat;
	}
	if (nList->size() == 0)
		return EmptyFile;
	Array::RemakeArray(nArray, nArray.arrayDouble, nList->size());
	for (int i = 0; i < nArray.countN; i++)
	{
		nArray.arrayDouble[i] = nList->back();
		nList->pop_back();
	}
	nList->clear();
	delete nList;
	return CorrectFormat;
}

bool GetValue(System::String^ text, list<double>& numbers)
{
	double number;
	for each (System::String ^ part in text->Split(' '))
	{
		part = part->Replace('.', ',');
		if (System::Double::TryParse(part, number))
			numbers.push_front(number);
		else if(!System::String::IsNullOrEmpty(part)) return false;
	}
	return true;
}

void SaveArray(ofstream* fileStream, list<FileInfo::FileInformation*> fileInfoList)
{
	int listSize = fileInfoList.size();
	for (int i = 0; i < listSize; i++)
	{
		FileInfo::FileInformation* fileInfoElement = fileInfoList.back();
		*fileStream << "Действие №" << i << "." << endl << fileInfoElement->info << " " << endl;
		for (int i = 0; i < fileInfoElement->numberN; i++)
			*fileStream << fileInfoElement->dArray[i] << " ";
		*fileStream << endl << endl;
		fileInfoList.pop_back();
	}
}

void CloseFile(ifstream* fileStream)
{
	(*fileStream).close();
	delete fileStream;
}

void CloseFile(ofstream* fileStream)
{
	(*fileStream).close();
	delete fileStream;
}
