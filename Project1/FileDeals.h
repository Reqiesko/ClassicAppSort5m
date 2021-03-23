#pragma once
#include "string"
#include "NumberClass.h"
#include "FileInfo.h"
#include <Windows.h>
#include <list>

enum ReadFileErrors
{
	IncorrectFormat = 0,
	CorrectFormat,
	EmptyFile
};

/// <summary>This method opens the file for reading.
/// <para>Input data: source of the file.</para>
/// <para>Output data: reference to the stream.</para>
/// </summary>
std::ifstream* OpenFile(std::string);

/// <summary>This method opens the file for writing.
/// <para>Input data: source of the file.</para>
/// <para>Output data: reference to the stream.</para>
/// </summary>
std::ofstream* OpenSaveFile(std::string);

/// <summary>This method checks if the file is really opened.
/// <para>Input data: reference to the stream for reading.</para>
/// <para>Output data: true if opened, false if not.</para>
/// </summary>
bool IfReallyOpened(std::ifstream*);

/// <summary>This method checks if the file is really opened.
/// <para>Input data: reference to the stream for writing.</para>
/// <para>Output data: true if opened, false if not.</para>
/// </summary>
bool IfReallyOpened(std::ofstream*);

/// <summary>This method gets data from the file filling the structure.
/// <para>Input data: reference to the stream for reading, reference to the two-dimensional array, references to the number of elements in row and column.</para>
/// <para>Output data: error code.</para>
/// </summary>
ReadFileErrors GetArray(std::ifstream*, ArrayIssue::Array&);

/// <summary>This method gets integer data from the file and checks its correctness.
/// <para>Input data: reference to the stream for reading, reference to the element to be read.</para>
/// <para>Output data: true if data is correct, false if not.</para>
/// </summary>
bool GetValue(System::String^, list<double>&);

/// <summary>This method saves data to the file.
/// <para>Input data: reference to the stream for writing, two-dimensional array with numbers to be saved, number of elements in row and column.</para>
/// </summary>
void SaveArray(std::ofstream*, list<FileInfo::FileInformation*>);

/// <summary>This method closes the file for reading.
/// <para>Input data: reference to the stream for reading.</para>
/// </summary>
void CloseFile(std::ifstream*);

/// <summary>This method closes the file for writing.
/// <para>Input data: reference to the stream for writing.</para>
/// </summary>
void CloseFile(std::ofstream*);