#include "NumberClass.h"
#include <random>
#include <ctime>
#include <windows.h>

using namespace ArrayIssue;

Array::Array()
{
	countN = 1;
	arrayDouble = new double[countN];
	arrayDouble[0] = 0;
}

Array::Array(int count)
{
	countN = count;
	arrayDouble = new double[countN];
	for (int i = 0; i < countN; i++)
		arrayDouble[i] = GenerateNumbers();
}

Array::Array(double* theArray, int count)
{
	countN = count;
	arrayDouble = theArray;
}

void Array::RemakeArray(Array &a, double* theArray, int count)
{
	a.countN = count;
	a.arrayDouble = theArray;
}

double* Array::DoubleVector(vector<double> vectorD)
{
	double* arrayD = new double[vectorD.size()];
	int i = -1;
	for each (double variable in vectorD)
		arrayD[++i] = variable;
	return arrayD;
}

vector<double> Array::DoubleVector(double* arrayD, int count)
{
	vector<double> vectorD;
	for (int i = 0; i < count; i++)
		vectorD.push_back(arrayD[i]);
	return vectorD;
}

double Array::GenerateNumbers()
{
	static default_random_engine generator(unsigned(time(nullptr)));
	uniform_real_distribution<double> distribution(minRandom, maxRandom); 
	return RoundToTwo(distribution(generator));
}

double Array::RoundToTwo(double number)
{
	return ((int)(number * 100)) / 100.00;
}

void Array::SortChaosSort()
{
	int randomPlace;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < countN / 2; i++)
	{
		randomPlace = rand() % countN;
		swap(arrayDouble[i], arrayDouble[randomPlace]);
	}
}

void Array::SortBubbleSort()
{
	bool sorting;
	int countA = countN - 1;
	operations = 0, comparisons = 0;
	do
	{
		sorting = false;
		for (int k = 0; k < countA; k++)
		{
			if (!method && arrayDouble[k] > arrayDouble[k + 1] || method && abs(arrayDouble[k]) > abs(arrayDouble[k + 1]))
			{
				swap(arrayDouble[k], arrayDouble[k + 1]);
				operations++;
				sorting = true;
			}
			comparisons++;
		}
		countA--;
	} while (sorting);
}

void Array::SortSelectionSort()
{
	int tnumber;
	operations = 0, comparisons = 0;
	for (int j = 0; j < countN; j++)
	{
		tnumber = j;
		for (int i = j + 1; i < countN; i++)
		{
			comparisons++;
			if (!method && arrayDouble[i] < arrayDouble[tnumber] || method && abs(arrayDouble[i]) < abs(arrayDouble[tnumber]))
			{
				tnumber = i;
				operations++;
			}
		}
		if (tnumber != j)
		{
			swap(arrayDouble[j], arrayDouble[tnumber]);
			operations++;
		}
	}
}

void Array::SortInsertionSort()
{
	int tnumber;
	operations = 0, comparisons = 0;
	double element;
	for (int j = 2; j < countN; j++)
	{
		tnumber = j + 1;
		element = arrayDouble[tnumber];
		for (int k = j + 1; k > 0; k--)
		{
			if (!method && element > arrayDouble[k - 1] || method && abs(element) > abs(arrayDouble[k - 1]))
			{
				tnumber = k - 1;
				arrayDouble[k] = arrayDouble[tnumber];
				operations++;
			}
			comparisons++;
		}
		arrayDouble[tnumber] = element;
	}
}

void Array::SortShellSort()
{
	int half, k;
	operations = 0, comparisons = 0, half = countN / 2;
	while (half > 0)
	{
		for (int j = 0; j < countN - half; j++)
		{
			k = j;
			while (k >= 0 && (!method && arrayDouble[k] > arrayDouble[k + half] || method && abs(arrayDouble[k]) > abs(arrayDouble[k + half])))
			{
				swap(arrayDouble[k], arrayDouble[k + half]);
				operations++;
				comparisons++;
				k--;
			}
			comparisons++;
		}
		half /= 2;
	}
}

void Array::SortQuickSort()
{
	int* arraying = new int[countN];
	operations = 0, comparisons = 0;
	PartOfQuickSort1(0, countN - 1);
	delete[] arraying;
}

void Array::PartOfQuickSort1(int eFirst, int eLast)
{
	int first = eFirst, last = eLast;
	double middle = arrayDouble[(first + last) / 2];
	do
	{
		while (!method && arrayDouble[first] < middle || method && abs(arrayDouble[first]) < abs(middle)) first++;
		while (!method && arrayDouble[last] > middle || method && abs(arrayDouble[last]) > abs(middle)) last--;
		if (first <= last)
		{
			swap(arrayDouble[first++], arrayDouble[last--]);
			operations++;
		}
		comparisons++;
	} while (first < last);
	if (eFirst < last) PartOfQuickSort1(eFirst, last);
	if (first < eLast) PartOfQuickSort1(first, eLast);
}

void Array::SortMergeSort()
{
	operations = 0, comparisons = 0;
	int middle = countN / 2;
	if (countN % 2 != 0)
		middle++;
	int step = 2, count = 0, j = middle;
	vector<double> part, merge;
	while (step < countN) 
	{
		for (int i = 0; i < middle; i++, j++) 
		{
			if (count != step) 
			{
				part.push_back(arrayDouble[i]);
				count++;
				if (j < countN) 
				{
					part.push_back(arrayDouble[j]);
					count++;
				}
			}
			if (count == step)
			{
				count = 0;
				PartOfMergeSort1(&part, step);
				for (int index = 0; index < step; index++) 
					merge.push_back(part[index]);
				part.clear();
			}
		}
		j = middle;
		count = 0;
		int size = merge.size();
		int left = countN - size;
		if (size != countN) 
		{
			PartOfMergeSort1(&part, left);
			for (int index = 0; index < left; index++) 
				merge.push_back(part[index]); 
		}
		part.clear();
		arrayDouble = DoubleVector(merge);
		merge.clear();
		step *= 2;
	}
	merge = DoubleVector(arrayDouble, countN);
	PartOfMergeSort1(&merge, countN);
	arrayDouble = DoubleVector(merge);
	merge.clear();
}

void Array::PartOfMergeSort1(vector<double>* smallArray, int step)
{
	vector<double> as = *smallArray;
	int id = step;
	bool count = true;
	while (count)
	{
		count = false;
		for (int i = 0; i < step - 1; i++)
		{
			double a = (*smallArray)[i], b = (*smallArray)[i + 1];
			if (!method && (*smallArray)[i] >(*smallArray)[i + 1] || method && abs((*smallArray)[i]) > abs((*smallArray)[i + 1]))
			{
				count = true;
				swap((*smallArray)[i], (*smallArray)[i + 1]);
				operations++;
			}
			comparisons++;
		}
	}
}

void Array::SortingCheck(SortingMethods sorting)
{
	seconds = 0;
	int start = (int)GetTickCount64(), finish = 0,	comparisons = 0, operations = 0;
	switch (sorting)
	{
	case SortingMethods::Bubble: SortBubbleSort(); break;
	case SortingMethods::Quick: SortQuickSort(); break;
	case SortingMethods::Merge: SortMergeSort(); break;
	case SortingMethods::Selection: SortSelectionSort(); break;
	case SortingMethods::Shell: SortShellSort(); break;
	}
	finish = (int)GetTickCount64();
	seconds = finish - start;
}

Array::SortingMethods Array::Statistics()
{
	int bestOperations, bestTime, bestComparisons;
	SortingMethods bestSort;
	double* firstArray = CopyArray(arrayDouble);
	for (int i = 1; i <= 5; i++)
	{
		arrayDouble = CopyArray(firstArray);
		SortingCheck((SortingMethods)i);
		if (i == 1 || comparisons + operations < bestComparisons + bestOperations || seconds < bestTime)
		{
			bestOperations = operations;
			bestTime = seconds;
			bestComparisons = comparisons;
			bestSort = (SortingMethods)i;
		}
	}
	operations = bestOperations;
	seconds = bestTime;
	comparisons = bestComparisons;
	return bestSort;
}

double* Array::CopyArray(double* inputA)
{
	double* firstArray = new double[countN];
	for (int i = 0; i < countN; i++)
		firstArray[i] = inputA[i];
	return firstArray;
}

void Array::ReverseArray()
{
	for (int i = 0; i < countN - i - 1; i++)
		swap(arrayDouble[i], arrayDouble[countN - i - 1]);
}