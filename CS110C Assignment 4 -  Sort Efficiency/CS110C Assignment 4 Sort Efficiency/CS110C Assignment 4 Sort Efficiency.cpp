// CS110C Assignment 4 Sort Efficiency.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Danny Chan
// CS110C
// 2/20/2021

#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
using namespace std;
/*
Part 1: O(n2) sort
Pick a O(n2) sorting algorithm (bubble, INSERTION, or selection) and implement it in a C++ program to sort an array of integers. Add a counter to the sort function to track the number of times that the function accesses elements from the array you are sorting.  For example, if your function has the line array[i] = max that counts as one array access.  If your function has the line if (array[i] < array[i+1]) that counts as two array accesses.
*/

// insertion sort with counter 
int insertionSort(int arrayInsert[], int arraySize)
{
    int insertionCounter = 0;
    for (int unsorted = 1; unsorted < arraySize; unsorted++)
    {
        int nextNum = arrayInsert[unsorted];
        insertionCounter++; // array access on the right in prev statement
        int insertedLoc = unsorted;
        while ((insertedLoc > 0) && arrayInsert[insertedLoc - 1] > nextNum)
        {
            insertionCounter++; // array access on the 2nd condition of while loop
            arrayInsert[insertedLoc] = arrayInsert[insertedLoc - 1];
            insertionCounter = insertionCounter + 2; // +2 due to left and right having array access in prev statement 
            insertedLoc--;
        }
        arrayInsert[insertedLoc] = nextNum;
        insertionCounter++; // array access on left
    }
    return insertionCounter;
}

/*
Part 2: O(n log n) sort
Do the same thing as part 1, but with a O(n log n) algorithm (MERGE SORT or quick sort).
*/

// merge sort helper function merge
int merge(int mergeArray[], int first, int last, int middle)
{
    int mergeSortCounter = 0;
    int leftArray;
    int rightArray;
    const int leftSide = last - middle;
    const int rightSide = middle - first + 1;
    int* lArray;
    int* rArray;
    lArray = new int[leftSide];
    rArray = new int[rightSide];
    int l = 0; // for left side
    int r = 0; // for right side
    int m = 0; // for sorting into main array for merge sort 
    for (int leftIndex = 0; leftIndex < leftSide; leftIndex++)
    {
        lArray[leftIndex] = mergeArray[first + leftIndex];
        mergeSortCounter++; // +1 due to array access on the right side
    }
    for (int rightIndex = 0; rightIndex < rightSide; rightIndex++)
    {
        rArray[rightIndex] = mergeArray[middle + first + rightIndex];
        mergeSortCounter++; // +1 due to array access on the right side
    }
    while ((l < leftSide) && (r < rightSide))
    {
        if (lArray[l] <= rArray[r])
        {
            mergeArray[m] = lArray[l];
            l++;
            mergeSortCounter++; // +1 due to array access on the left side
        }
        else
        {
            mergeArray[m] = rArray[r];
            r++;
            mergeSortCounter++; // +1 due to array access on the left side
        }
        m++;
    }
    while (l < leftSide)
    {
        mergeArray[m] = lArray[l];
        l++;
        m++;
        mergeSortCounter++; // +1 due to array access on the left side
    }
    while (r < rightSide)
    {
        mergeArray[m] = rArray[r];
        r++;
        m++;
        mergeSortCounter++; // +1 due to array access on the left side
    }
    return mergeSortCounter;
    delete[] lArray;
    delete[] rArray;
}
// merge sort function
int mergeSort(int mergeArray[], int first, int last)
{
    int mergeSortCounter = 0;
    int middle;
    if (first < last)
    {
        middle = first + (last - first) / 2;
        mergeSortCounter += mergeSort(mergeArray, first, middle);
        mergeSortCounter += mergeSort(mergeArray, middle + 1, last);
        mergeSortCounter += merge(mergeArray, first, last, middle);
    }
    return mergeSortCounter;
}

int countingSort(int arr[], int countSize)
{
    const int countArrSize = 1000;
    int newCountArray[countArrSize];
    int count[countArrSize];
    int highest = 0;
    int countingCounter = 0;
    for (int h = 0; h < countSize; h++)
    {
        if (arr[h] > highest)
        {
            highest = arr[h];
            countingCounter++; // +1 due to array access on the right side
        }
    }
    for (int c = 0; c <= highest; c++)
    {
        count[c] = 0;
    }
    for (int i = 0; i < countSize; i++)
    {
        count[arr[i]]--;
        countingCounter++; // +1 due to array access 
    }
    for (int j = 1; j <= highest; j++)
    {
        count[j] += count[j - 1];
    }
    for (int k = countSize - 1; k >= 0; k--)
    {
        newCountArray[count[arr[k]] - 1] = arr[k];
        count[arr[k]]--;
        countingCounter = countingCounter + 3; // +3 due to array access in previous lines
    }
    for (int l = 0; l < countSize; l++)
    {
        arr[l] = newCountArray[l];
        countingCounter++;
        // +1 due to array access on the left side
    }
    return countingCounter;
}

int main()
{
    srand(time(NULL));
    // function testers
    int arrayTester[] = { 9,17,50,28,32 };

    cout << "Using a preset Array: " << endl;
    cout << " " << endl;
    // using insertion sort 
    cout << "Insertion sort Counter is: " << insertionSort(arrayTester, 5) << endl;
    cout << " " << endl;

    // using mergesort 
    cout << "Merge sort Counter is: " << mergeSort(arrayTester, 0, 4) << endl;
    cout << " " << endl;

    // using counting sort
    cout << "Counting sort Counter is: " << countingSort(arrayTester, 5) << endl;
    cout << " " << endl;


    // lengths/size of array
    const int arrayLength1 = 8;
    const int arrayLength2 = 32;
    const int arrayLength3 = 128;
    // insertion sort tests variables
    int insSort8Pass1, insSort8Pass2, insSort8Pass3, insSort8Average;
    int insSort32Pass1, insSort32Pass2, insSort32Pass3, insSort32Average;
    int insSort128Pass1, insSort128Pass2, insSort128Pass3, insSort128Average;
    // merge sort test variables
    int mergeSort8Pass1, mergeSort8Pass2, mergeSort8Pass3, mergeSort8Average;
    int mergeSort32Pass1, mergeSort32Pass2, mergeSort32Pass3, mergeSort32Average;
    int mergeSort128Pass1, mergeSort128Pass2, mergeSort128Pass3, mergeSort128Average;
    // counting sort test variables 
    int cSort8Pass1, cSort8Pass2, cSort8Pass3, cSort8Average;
    int cSort32Pass1, cSort32Pass2, cSort32Pass3, cSort32Average;
    int cSort128Pass1, cSort128Pass2, cSort128Pass3, cSort128Average;

    cout << "Now using random generated input arrays... " << endl;
    cout << " " << endl;

    // insertion sort length 8 test

    cout << " " << endl;
    int insSort8Arr1[arrayLength1];
    for (int i = 0; i < arrayLength1; i++)
    {
        insSort8Arr1[i] = rand() % 100 + 1;
    }
    insSort8Pass1 = insertionSort(insSort8Arr1, arrayLength1);
    cout << "Array accesses first test insertion sort with a length of 8 is: " << insSort8Pass1 << endl;
    cout << " " << endl;

    int insSort8Arr2[arrayLength1];
    for (int i = 0; i < arrayLength1; i++)
    {
        insSort8Arr2[i] = rand() % 100 + 1;
    }
    insSort8Pass2 = insertionSort(insSort8Arr2, arrayLength1);
    cout << "Array accesses second test insertion sort with a length of 8 is: " << insSort8Pass2 << endl;
    cout << " " << endl;

    int insSort8Arr3[arrayLength1];
    for (int i = 0; i < arrayLength1; i++)
    {
        insSort8Arr3[i] = rand() % 100 + 1;
    }
    insSort8Pass3 = insertionSort(insSort8Arr3, arrayLength1);
    cout << "Array accesses third test insertion sort with a length of 8 is: " << insSort8Pass3 << endl;
    cout << " " << endl;

    insSort8Average = (insSort8Pass1 + insSort8Pass2 + insSort8Pass3) / 3;
    cout << "The average of array accesses for insertion sort with an array length of 8 is: " << insSort8Average << endl;
    cout << " " << endl;

    // insertion sort length 32 test 

    cout << " " << endl;
    int insSort32Arr1[arrayLength2];
    for (int i = 0; i < arrayLength2; i++)
    {
        insSort32Arr1[i] = rand() % 100 + 1;
    }
    insSort32Pass1 = insertionSort(insSort32Arr1, arrayLength2);
    cout << "Array accesses first test insertion sort with a length of 32 is: " << insSort32Pass1 << endl;
    cout << " " << endl;

    int insSort32Arr2[arrayLength2];
    for (int i = 0; i < arrayLength2; i++)
    {
        insSort32Arr2[i] = rand() % 100 + 1;
    }
    insSort32Pass2 = insertionSort(insSort32Arr2, arrayLength2);
    cout << "Array accesses second test insertion sort with a length of 32 is: " << insSort32Pass2 << endl;
    cout << " " << endl;

    int insSort32Arr3[arrayLength2];
    for (int i = 0; i < arrayLength2; i++)
    {
        insSort32Arr3[i] = rand() % 100 + 1;
    }
    insSort32Pass3 = insertionSort(insSort32Arr3, arrayLength2);
    cout << "Array accesses third test insertion sort with a length of 32 is: " << insSort32Pass3 << endl;
    cout << " " << endl;

    insSort32Average = (insSort32Pass1 + insSort32Pass2 + insSort32Pass3) / 3;
    cout << "The average of array accesses for insertion sort with an array length of 32 is: " << insSort32Average << endl;
    cout << " " << endl;

    // insertion sort length 128

    cout << " " << endl;
    int insSort128Arr1[arrayLength3];
    for (int i = 0; i < arrayLength3; i++)
    {
        insSort128Arr1[i] = rand() % 100 + 1;
    }
    insSort128Pass1 = insertionSort(insSort128Arr1, arrayLength3);
    cout << "Array accesses first test insertion sort with a length of 128 is: " << insSort128Pass1 << endl;
    cout << " " << endl;

    int insSort128Arr2[arrayLength3];
    for (int i = 0; i < arrayLength3; i++)
    {
        insSort128Arr2[i] = rand() % 100 + 1;
    }
    insSort128Pass2 = insertionSort(insSort128Arr2, arrayLength3);
    cout << "Array accesses second test insertion sort with a length of 128 is: " << insSort128Pass2 << endl;
    cout << " " << endl;

    int insSort128Arr3[arrayLength3];
    for (int i = 0; i < arrayLength3; i++)
    {
        insSort128Arr3[i] = rand() % 100 + 1;
    }
    insSort128Pass3 = insertionSort(insSort128Arr3, arrayLength3);
    cout << "Array accesses third test insertion sort with a length of 128 is: " << insSort128Pass3 << endl;
    cout << " " << endl;

    insSort128Average = (insSort128Pass1 + insSort128Pass2 + insSort128Pass3) / 3;
    cout << "The average of array accesses for insertion sort with an array length of 128 is: " << insSort128Average << endl;
    cout << " " << endl;


    // merge sort length 8 test

    cout << " " << endl;
    int mergeSort8Arr1[arrayLength1];
    for (int i = 0; i < arrayLength1; i++)
    {
        mergeSort8Arr1[i] = rand() % 100 + 1;
    }
    mergeSort8Pass1 = mergeSort(mergeSort8Arr1, 0, 7);
    cout << "Array accesses first test merge sort with a length of 8 is: " << mergeSort8Pass1 << endl;
    cout << " " << endl;

    int mergeSort8Arr2[arrayLength1];
    for (int i = 0; i < arrayLength1; i++)
    {
        mergeSort8Arr2[i] = rand() % 100 + 1;
    }
    mergeSort8Pass2 = mergeSort(mergeSort8Arr2, 0, 7);
    cout << "Array accesses second test merge sort with a length of 8 is: " << mergeSort8Pass2 << endl;
    cout << " " << endl;

    int mergeSort8Arr3[arrayLength1];
    for (int i = 0; i < arrayLength1; i++)
    {
        mergeSort8Arr3[i] = rand() % 100 + 1;
    }
    mergeSort8Pass3 = mergeSort(mergeSort8Arr3, 0, 7);
    cout << "Array accesses third test merge sort with a length of 8 is: " << mergeSort8Pass3 << endl;
    cout << " " << endl;

    mergeSort8Average = (mergeSort8Pass1 + mergeSort8Pass2 + mergeSort8Pass3) / 3;
    cout << "The average of array accesses for merge sort with an array length of 8 is: " << mergeSort8Average << endl;
    cout << " " << endl;

    // merge sort length 32 test

    cout << " " << endl;
    int mergeSort32Arr1[arrayLength2];
    for (int i = 0; i < arrayLength2; i++)
    {
        mergeSort32Arr1[i] = rand() % 100 + 1;
    }
    mergeSort32Pass1 = mergeSort(mergeSort32Arr1, 0, 31);
    cout << "Array accesses first test merge sort with a length of 32 is: " << mergeSort32Pass1 << endl;
    cout << " " << endl;

    int mergeSort32Arr2[arrayLength2];
    for (int i = 0; i < arrayLength2; i++)
    {
        mergeSort32Arr2[i] = rand() % 100 + 1;
    }
    mergeSort32Pass2 = mergeSort(mergeSort32Arr2, 0, 31);
    cout << "Array accesses second test merge sort with a length of 32 is: " << mergeSort32Pass2 << endl;
    cout << " " << endl;

    int mergeSort32Arr3[arrayLength2];
    for (int i = 0; i < arrayLength2; i++)
    {
        mergeSort32Arr3[i] = rand() % 100 + 1;
    }
    mergeSort32Pass3 = mergeSort(mergeSort32Arr3, 0, 31);
    cout << "Array accesses third test merge sort with a length of 32 is: " << mergeSort32Pass3 << endl;
    cout << " " << endl;

    mergeSort32Average = (mergeSort32Pass1 + mergeSort32Pass2 + mergeSort32Pass3) / 3;
    cout << "The average of array accesses for merge sort with an array length of 32 is: " << mergeSort32Average << endl;
    cout << " " << endl;

    // merge sort length 128 test
    cout << " " << endl;
    int mergeSort128Arr1[arrayLength3];
    for (int i = 0; i < arrayLength1; i++)
    {
        mergeSort128Arr1[i] = rand() % 100 + 1;
    }
    mergeSort128Pass1 = mergeSort(mergeSort128Arr1, 0, 127);
    cout << "Array accesses first test merge sort with a length of 128 is: " << mergeSort128Pass1 << endl;
    cout << " " << endl;

    int mergeSort128Arr2[arrayLength3];
    for (int i = 0; i < arrayLength3; i++)
    {
        mergeSort128Arr2[i] = rand() % 100 + 1;
    }
    mergeSort128Pass2 = mergeSort(mergeSort128Arr2, 0, 127);
    cout << "Array accesses second test merge sort with a length of 128 is: " << mergeSort128Pass2 << endl;
    cout << " " << endl;

    int mergeSort128Arr3[arrayLength3];
    for (int i = 0; i < arrayLength3; i++)
    {
        mergeSort128Arr3[i] = rand() % 100 + 1;
    }
    mergeSort128Pass3 = mergeSort(mergeSort128Arr3, 0, 127);
    cout << "Array accesses third test merge sort with a length of 128 is: " << mergeSort128Pass3 << endl;
    cout << " " << endl;

    mergeSort128Average = (mergeSort128Pass1 + mergeSort128Pass2 + mergeSort128Pass3) / 3;
    cout << "The average of array accesses for merge sort with an array length of 128 is: " << mergeSort128Average << endl;
    cout << " " << endl;


    // counting sort length 8 test
    cout << " " << endl;
    int countingSort8Arr1[arrayLength1];
    for (int i = 0; i < arrayLength1; i++)
    {
        countingSort8Arr1[i] = rand() % 100 + 1;
    }
    cSort8Pass1 = countingSort(countingSort8Arr1, 8);
    cout << "Array accesses first test counting sort with a length of 8 is: " << cSort8Pass1 << endl;
    cout << " " << endl;

    int countingSort8Arr2[arrayLength1];
    for (int i = 0; i < arrayLength1; i++)
    {
        countingSort8Arr2[i] = rand() % 100 + 1;
    }
    cSort8Pass2 = countingSort(countingSort8Arr2, 8);
    cout << "Array accesses second test counting sort with a length of 8 is: " << cSort8Pass2 << endl;
    cout << " " << endl;

    int countingSort8Arr3[arrayLength1];
    for (int i = 0; i < arrayLength1; i++)
    {
        countingSort8Arr3[i] = rand() % 100 + 1;
    }
    cSort8Pass3 = countingSort(countingSort8Arr3, 8);
    cout << "Array accesses third test counting sort with a length of 8 is: " << cSort8Pass3 << endl;
    cout << " " << endl;

    cSort8Average = (cSort8Pass1 + cSort8Pass2 + cSort8Pass3) / 3;
    cout << "The average of array accesses for counting sort with an array length of 8 is: " << cSort8Average << endl;
    cout << " " << endl;

    // counting sort length 32 test
    cout << " " << endl;
    int countingSort32Arr1[arrayLength2];
    for (int i = 0; i < arrayLength2; i++)
    {
        countingSort32Arr1[i] = rand() % 100 + 1;
    }
    cSort32Pass1 = countingSort(countingSort32Arr1, 32);
    cout << "Array accesses first test counting sort with a length of 32 is: " << cSort32Pass1 << endl;
    cout << " " << endl;

    int countingSort32Arr2[arrayLength2];
    for (int i = 0; i < arrayLength2; i++)
    {
        countingSort32Arr2[i] = rand() % 100 + 1;
    }
    cSort32Pass2 = countingSort(countingSort32Arr2, 32);
    cout << "Array accesses second test counting sort with a length of 32 is: " << cSort32Pass2 << endl;
    cout << " " << endl;

    int countingSort32Arr3[arrayLength2];
    for (int i = 0; i < arrayLength2; i++)
    {
        countingSort32Arr3[i] = rand() % 100 + 1;
    }
    cSort32Pass3 = countingSort(countingSort32Arr3, 32);
    cout << "Array accesses third test counting sort with a length of 32 is: " << cSort32Pass3 << endl;
    cout << " " << endl;

    cSort32Average = (cSort32Pass1 + cSort32Pass2 + cSort32Pass3) / 3;
    cout << "The average of array accesses for counting sort with an array length of 32 is: " << cSort32Average << endl;
    cout << " " << endl;

    // counting sort length 128 test
    cout << " " << endl;
    int countingSort128Arr1[arrayLength3];
    for (int i = 0; i < arrayLength3; i++)
    {
        countingSort128Arr1[i] = rand() % 100 + 1;
    }
    cSort128Pass1 = countingSort(countingSort128Arr1, 128);
    cout << "Array accesses first test counting sort with a length of 128 is: " << cSort128Pass1 << endl;
    cout << " " << endl;

    int countingSort128Arr2[arrayLength3];
    for (int i = 0; i < arrayLength3; i++)
    {
        countingSort128Arr2[i] = rand() % 100 + 1;
    }
    cSort128Pass2 = countingSort(countingSort32Arr2, 128);
    cout << "Array accesses second test counting sort with a length of 128 is: " << cSort128Pass2 << endl;
    cout << " " << endl;

    int countingSort128Arr3[arrayLength3];
    for (int i = 0; i < arrayLength3; i++)
    {
        countingSort128Arr3[i] = rand() % 100 + 1;
    }
    cSort128Pass3 = countingSort(countingSort128Arr3, 128);
    cout << "Array accesses third test counting sort with a length of 128 is: " << cSort128Pass3 << endl;
    cout << " " << endl;

    cSort128Average = (cSort128Pass1 + cSort128Pass2 + cSort128Pass3) / 3;
    cout << "The average of array accesses for counting sort with an array length of 128 is: " << cSort128Average << endl;
    cout << " " << endl;

}

/*
[dchan89@hills ~]$ ./a.out
Using a preset Array:

Insertion sort Counter is: 14

Merge sort Counter is: 24

Counting sort Counter is: 28

Now using random generated input arrays...


Array accesses first test insertion sort with a length of 8 is: 44

Array accesses second test insertion sort with a length of 8 is: 38

Array accesses third test insertion sort with a length of 8 is: 71

The average of array accesses for insertion sort with an array length of 8 is: 51


Array accesses first test insertion sort with a length of 32 is: 857

Array accesses second test insertion sort with a length of 32 is: 719

Array accesses third test insertion sort with a length of 32 is: 647

The average of array accesses for insertion sort with an array length of 32 is: 741


Array accesses first test insertion sort with a length of 128 is: 13358

Array accesses second test insertion sort with a length of 128 is: 12239

Array accesses third test insertion sort with a length of 128 is: 12362

The average of array accesses for insertion sort with an array length of 128 is: 12653


Array accesses first test merge sort with a length of 8 is: 48

Array accesses second test merge sort with a length of 8 is: 48

Array accesses third test merge sort with a length of 8 is: 48

The average of array accesses for merge sort with an array length of 8 is: 48


Array accesses first test merge sort with a length of 32 is: 320

Array accesses second test merge sort with a length of 32 is: 320

Array accesses third test merge sort with a length of 32 is: 320

The average of array accesses for merge sort with an array length of 32 is: 320


Array accesses first test merge sort with a length of 128 is: 1792

Array accesses second test merge sort with a length of 128 is: 1792

Array accesses third test merge sort with a length of 128 is: 1792

The average of array accesses for merge sort with an array length of 128 is: 1792


Array accesses first test counting sort with a length of 8 is: 42

Array accesses second test counting sort with a length of 8 is: 42

Array accesses third test counting sort with a length of 8 is: 42

The average of array accesses for counting sort with an array length of 8 is: 42


Array accesses first test counting sort with a length of 32 is: 164

Array accesses second test counting sort with a length of 32 is: 165

Array accesses third test counting sort with a length of 32 is: 162

The average of array accesses for counting sort with an array length of 32 is: 163


Array accesses first test counting sort with a length of 128 is: 643

Array accesses second test counting sort with a length of 128 is: 643

Array accesses third test counting sort with a length of 128 is: 644

The average of array accesses for counting sort with an array length of 128 is: 643


-Counting sort is not practical because the input cannot be arbitrary, each element must be one of a predetermined set of possible values. -5
-Your counting sort makes many passes through the array. This works, but you really only need to make one pass through the array and check each element. Increment count[i] when you find value i in the array. No points off, just wanted to let you know.

*/