/**
 * Contains prototypes for functions provided in the public interface
 * for various sorting algorithms
 * @author ketsubetsu
 * <pre>
 * File: SortUtil.h
 * </pre>
 */

#ifndef SORTUTIL_H
#define SORTUTIL_H

#include <iostream>
#include <algorithm>

using namespace std;

namespace SortUtil
{
    /* Your Task:
       You will need to templatize these
       function prototypes so that they take arrays
       of any type. For now, they will work with
       int data. Do not templatize them until you get
       the program to work with int data.
    */
    
    /**
      * This function sorts the items in an array into ascending order
      * using the bubble sort algorithm.
      * @param data - the array containing the data.
      * @param size - the number of elements in the array.
      */
    template <typename T>
    void bubbleSort(T data[], int size);
    
    /**
      * This function sorts the items in an array into ascending order
      * using the selection sort algorithm.
      * @param data - the array containing the data.
      * @param size - the number of elements in the array.
      */
    template <typename T>
    void selectionSort(T data[], int size);
    
    
    /**
      * This function sorts the items in an array into ascending order
      * using the insertion sort algorithm.
      * @param data - the array containing the data.
      * @param size - the number of elements in the array.
      */
    template <typename T>
    void insertionSort(T data[], int size);
    
    
    /**
      * This function sorts the items in an array into ascending order
      * using the merge sort algorithm.
      * @param data - the array containing the data.
      * @param start - the starting index.
      * @param end - the ending index.
      */
    template <typename T>
    void quickSort(T data[], int start, int end);
    
    /**
      * This function sorts the items in an array into ascending order
      * using the merge sort algorithm.
      * @param array the array containing the data.
      * @param size the number of elements in the array.
      */
    template <typename T>
    void mergeSort(T array[], int size);
}
#endif
