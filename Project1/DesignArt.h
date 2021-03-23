#pragma once
#include "NumberClass.h"

using namespace System::Windows::Forms;

enum class SortingOrders
{
	Ascending,
	Descending,
	AbsoluteAscending,
	AbsoluteDescending,
	Chaos
};

System::Void FillTable(ArrayIssue::Array, DataGridView^);

ArrayIssue::Array GetTable(DataGridView^);

void EmptyTable(DataGridView^, int);

int ConvertationToInt(System::Object^);

double ConvertationToDouble(System::Object^);

System::String^ ConvertationToString(System::Object^);

double CheckForOnlyDigit(System::String^);

System::String^ GetMethod(ArrayIssue::Array::SortingMethods);

System::String^ GetOrder(SortingOrders order);