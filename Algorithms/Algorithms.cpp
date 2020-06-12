// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "List.h"

using namespace Algorithms;

int main()
{
    List<int> items = { 3, 6, 1, 22, 5, 4, 5, 0, -44, 100, 2, -1, 0, 5, 11, -41, 3, 1, 55, 32, 03 };
    List<int> sortedItems = items;

    List<int> bubbleSortItems = items;
    BubbleSort(bubbleSortItems);

    List<int> quickSortItems = items;
    QuickSort(quickSortItems);

    List<int> mergeSortItems = items;
    MergeSort(mergeSortItems);

    List<int> heapSortItems = items;
    HeapSort(heapSortItems);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
