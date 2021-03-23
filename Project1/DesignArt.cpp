#include "DesignArt.h"
#include <cctype>

using namespace System;

Void FillTable(ArrayIssue::Array nList, DataGridView^ dataTable)
{
	dataTable->ColumnCount = nList.countN;
	for (int i = 0; i < nList.countN; i++)
		dataTable->Rows[0]->Cells[i]->Value = nList.arrayDouble[i];
}

ArrayIssue::Array GetTable(DataGridView^ dataTable)
{
	ArrayIssue::Array* nList = new ArrayIssue::Array(dataTable->ColumnCount);
	for (int i = 0; i < nList->countN; i++)
		nList->arrayDouble[i] = ConvertationToDouble(dataTable->Rows[0]->Cells[i]->Value);
	return *nList;
}

void EmptyTable(DataGridView^ dataTable, int number)
{
	dataTable->ColumnCount = number;
	for (int i = 0; i < number; i++)
		dataTable->Rows[0]->Cells[i]->Value = "";
}

int ConvertationToInt(Object^ text)
{
	Convert^ convertation = nullptr;
	return CheckForOnlyDigit(ConvertationToString(text)) ? convertation->ToInt32(text) : 0;
}

double ConvertationToDouble(Object^ text)
{
	Convert^ convertation = nullptr;
	return CheckForOnlyDigit(ConvertationToString(text)) ? convertation->ToDouble(text) : 0;
}

String^ ConvertationToString(Object^ text)
{
	Convert^ convertation = nullptr;
	return convertation->ToString(text);
}

double CheckForOnlyDigit(String^ text)
{
	double number;
	return Double::TryParse(text, number);
}

String^ GetMethod(ArrayIssue::Array::SortingMethods method)
{
	switch (method)
	{
	case ArrayIssue::Array::SortingMethods::Bubble: return "Сортировка пузырьком"; break;
	case ArrayIssue::Array::SortingMethods::Merge: return "Сортировка слиянием"; break;
	case ArrayIssue::Array::SortingMethods::Quick: return "Быстрая сортировка"; break;
	case ArrayIssue::Array::SortingMethods::Selection: return "Сортировка выбором"; break;
	case ArrayIssue::Array::SortingMethods::Shell: return "Сортировка Шелла"; break;
	default: return ""; break;
	}
}

String^ GetOrder(SortingOrders order)
{
	switch (order)
	{
	case SortingOrders::AbsoluteAscending: return "по возрастанию (по модулю)"; break;
	case SortingOrders::AbsoluteDescending: return "по убыванию (по модулю)"; break;
	case SortingOrders::Ascending: return "по возрастанию"; break;
	case SortingOrders::Descending: return "по убыванию"; break;
	default: return "Беспорядок"; break;
	}
}