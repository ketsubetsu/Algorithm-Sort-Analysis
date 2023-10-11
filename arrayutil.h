/**
 * Contains prototypes for utility functions for array
 * @author ketsubetsu
 * <pre>
 * File: ArrayUtil.h 
 * </pre>
 */
 
#include <cstdlib>
#include <iostream>

#ifndef ARRAYUTIL_H
#define ARRAYUTIL_H


using namespace std;

namespace ArrayUtil
{
    /** copies numElems elements from array a to array b
     * starting at position i in array a and starting at
     * position j in array b.
     * @param a - the source array
     * @param i - the starting index in the source array
     * @param b - the destination array
     * @param j - the starting index in the destination array
     * @param numElems - the number of elements to copy from
     * the source array into the destination array.
     */
    template <typename T>
    void arrayCopy (T a[], int i, T b[], int j, int numElems);
    
    /**
     * This function fills an array with random numbers
     * @param data - array
     * @param size - size of the array
     */
    template <typename T>
    void genRandArray (T* data, int size);    
    
    /**
     * This function fills an array with numbers in ascending or descending order
     * @param data - array
     * @param size - size of the array
     */
    template <typename T>
    void genSortedArray (T *data, int size, bool ascending);    
    
    /**
     * Prints elements whose subscripts are in the range F to L
     * of an array, numPerLine elements  per line.
     * @param  data - an array containing data to be printed.  
     * @param first the first index of the array.
     * @param last the last index of the array.
     */
    template <typename T>
    void printArray (T data[], int first, int last, int numPerLine);
}
#endif
