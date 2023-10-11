/**
 * implementation of the functions for various sorting algorithms
 * along with auxilliary functions (for internal use).
 * @author ketsubetsu
 * <pre>
 * File: SortUtil.cpp
 * </pre>
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "SortUtil.h"
#include "ArrayUtil.h"

using namespace std;


/* auxilliary function (for internal use only) 
   First, implement the functions so that they work
   with integer arrays. After you verify that they
   do, then templatize them so that they work with
   arrays of any numeric type. The starter code in 
   the main function (SortProfiler.cpp) is written
   to test many of these functions on integer arrays.
*/

/**
 * Partitions an array for quicksort and returns the pivot index.
 * @param data - the array containing the data.
 * @param start - the first index.
 * @param end - the last index.
 * @return the index of the element about which the array is partitioned.
 */

template <typename T>
static void swap(T *a, T *b)
{
  T t = *a;
  *a = *b;
  *b = t;
}

template <typename T>
static int partition(T data[], int start, int end)
{
   //implement this function
    T pivot = data[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (data[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(data[pivotIndex], data[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (data[i] <= pivot) {
            i++;
        }

        while (data[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(data[i++], data[j--]);
        }
    }

    return pivotIndex;
}

/** This function merges two subarrays into the original array.
 * @param data - the original array
 * @param first - a subarray
 * @param sizeFirst - the size of the first subarray
 * @param second - a subarray
 * @param sizeSecond - the size of the second subarray.
 */
template <typename T>
static void merge(int data[], T first[],int sizeFirst, T second[], int sizeSecond)
{
   int iFirst = 0;
   int iSecond = 0;
   int j = 0;
   while (iFirst < sizeFirst && iSecond < sizeSecond)
   {
      if (first[iFirst] < second[iSecond])
      {
         data[j] = first[iFirst];
         iFirst++;
      }
      else
      {
         data[j] = second[iSecond];
         iSecond++;
      }
      j++;
   }
   ArrayUtil::arrayCopy(first, iFirst,data,j,sizeFirst-iFirst);
   ArrayUtil::arrayCopy(second, iSecond, data, j, sizeSecond-iSecond);
}


/* sorting functions */
/*void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}*/

template <typename T>
inline void SortUtil::bubbleSort(T data[], int size)
{
   //implement this function
    int i, j;
    for (i = 0; i < size-1; i++)
        for (j = 0; j < size-i-1; j++)
            if (data[j] > data[j+1])
                swap(&data[j], &data[j+1]);
}

/*void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}*/

template <typename T>
inline void SortUtil::selectionSort(T data[], int size)
{
   //implement this function
    int i, j, min_idx;

    for (i = 0; i < size-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < size; j++)
            if (data[j] < data[min_idx])
                min_idx = j;

        swap(&data[min_idx], &data[i]);
    }
}

template <typename T>
inline void SortUtil::insertionSort(T data[],int size)
{
   for (int i = 1; i < size; i++)
   {
      int next = data[i];
      int j = i;
      while (j > 0 && data[j-1] > next)
      {
         data[j] = data[j-1];
         j--;
      }
      data[j] = next;
   }
}

template <typename T>
inline void SortUtil::quickSort(T data[], int start, int end)
{
   //implement this function
	  if (start < end) {

	    int piv = partition(data, start, end);

	    quickSort(data, start, piv - 1);

	    quickSort(data, piv + 1, end);
	  }
}

template <typename T>
inline void SortUtil::mergeSort(T data[], int size)
{
   if (size <= 1)
      return;
   int *first = new int[size/2];
   int *second = new int[size -size/2];
   ArrayUtil::arrayCopy(data,0,first,0,size/2);
   ArrayUtil::arrayCopy(data,size/2,second,0,size-size/2);
   mergeSort(first,size/2);
   mergeSort(second,size-size/2);
   merge(data, first,size/2,second, size-size/2);
   delete[] first;
   delete[] second;
}
