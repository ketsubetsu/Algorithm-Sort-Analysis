/**
 * Contains implementations for various array utility functions
 * @author ketsubetsu
 * <pre>
 * File: ArrayUtil.cpp
 * </pre>
 */

#include <cstdlib>
#include<iostream>
#include<iomanip>
#include <cstring>
#include <climits>
#include "ArrayUtil.h"

using namespace std;

template <typename T>
void ArrayUtil::arrayCopy(T a[], int i, T b[],int j, int numElems)
{
   /*
   for (int m = i; m < (i+numElems); m++)
   {
      b[j] = a[m];
      j++;
   }
   */
   memcpy(&b[j],&a[i],sizeof(T)*numElems);
}

template <typename T>
void ArrayUtil::genRandArray(T* data, int size)
{
    srand(time(NULL));
    T factor = 1;
   for (int i=0; i<size;i++)
      data[i]=rand()%INT_MAX*factor;
}

template <typename T>
void ArrayUtil::genSortedArray(T* data, int size, bool ascending)
{
   int i;
   T factor = 1;
   if (ascending)
   {
      for (i=0; i<size;i++)
         data[i] = i*factor;
   }
   else
   {
      for (i=0; i<size;i++)
         data[i]=size-i*factor;
   }
}


template <typename T>
void ArrayUtil::printArray(T data[],int first,int last, int numPerLine)
{
   for (int i = first; i <= last; i++)
   {
      cout<<fixed<<setprecision(4);
      cout<<setw(10)<<data[i]<<" ";
      if ((i - first + 1) % numPerLine == 0)
         cout<<endl;
   }
}
