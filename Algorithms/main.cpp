// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "bubble_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "list.h"
#include "linked_list.h"

using namespace algorithms;

void print_list(list<int>& list)
{
    std::cout << "[ ";
    for (int i = 0; i < list.size(); i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << "] " << std::endl;
}

int main()
{
    linked_list<int> ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);

    list<int> items = { 3, 6, 1, 22, 5, 4, 5, 0, -44, 100, 2, -1, 0, 5, 11, -41, 3, 1, 55, 32, 03 };
    list<int> sortedItems = items;

    list<int> bubbleSortItems = items;
    bubble_sort(bubbleSortItems);
    print_list(bubbleSortItems);

    list<int> quickSortItems = items;
    quick_sort(quickSortItems);
    print_list(quickSortItems);

    list<int> mergeSortItems = items;
    merge_sort(mergeSortItems);
    print_list(mergeSortItems);

    list<int> heapSortItems = items;
    heap_sort(heapSortItems);
    print_list(heapSortItems);
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
