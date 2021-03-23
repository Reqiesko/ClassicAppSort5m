#pragma once
#include <vector>

using namespace std;
using namespace System::Collections;
using namespace System::Collections::Generic;

namespace ArrayIssue
{
	class Array
	{
	public: enum class SortingOrders { Regular, Absolute };

	public: enum class SortingMethods
			{
				Auto,
				Bubble,
				Merge,
				Quick,
				Selection,
				Shell
			};

	private:const int minRandom = -100;
			const int maxRandom = 100;

	public:double* arrayDouble;
		   int countN;
		   int comparisons = 0;
		   int operations = 0;
		   int seconds = 0;
		   bool method = (bool)SortingOrders::Regular;

		   Array();
		   Array(int);
		   Array(double*, int);

		   static void RemakeArray(Array&, double*, int);
		   void ReverseArray();

	private: double GenerateNumbers();

			 /// <summary>This method helps to sort elements in the array with Bubble sorting.
			 /// <para>Input data: reference to the two-dimensional array for initialization, number of elements in row and column, references to the number of operations and comparisons.</para>
			 /// </summary>

			 double RoundToTwo(double);

			 double* DoubleVector(vector<double>);
			 vector<double> DoubleVector(double*, int);

			 void SortBubbleSort();

			 /// <summary>This method helps to sort elements in the array with Selection sorting.
			 /// <para>Input data: reference to the two-dimensional array for initialization, number of elements in row and column, references to the number of operations and comparisons.</para>
			 /// </summary>
			 void SortSelectionSort();

			 /// <summary>This method helps to sort elements in the array with Insertion sorting.
			 /// <para>Input data: reference to the two-dimensional array for initialization, number of elements in row and column, references to the number of operations and comparisons.</para>
			 /// </summary>
			 void SortInsertionSort();

			 /// <summary>This method helps to sort elements in the array with Shell sorting.
			 /// <para>Input data: reference to the two-dimensional array for initialization, number of elements in row and column, references to the number of operations and comparisons.</para>
			 /// </summary>
			 void SortShellSort();

			 /// <summary>This method helps to sort elements in the array with Quick sorting.
			 /// <para>Input data: reference to the two-dimensional array for initialization, number of elements in row and column, references to the number of operations and comparisons.</para>
			 /// </summary>
			 void SortQuickSort();

			 /// <summary>This method is a part of Quick sorting which helps to sort elements in descending order.
			 /// <para>Input data: reference to the two-dimensional array for initialization, number of elements in row and column, references to the number of operations and comparisons.</para>
			 /// </summary>
			 void PartOfQuickSort1(int, int);

			 void SortMergeSort();

			 void PartOfMergeSort1(vector<double>*, int);

			 double* CopyArray(double*);

	public: void SortingCheck(SortingMethods);

			SortingMethods Statistics();

			void SortChaosSort();
	};
}