/**
 * This program measures the approximate runtimes it takes for various 
 * sorting algorithms to sort arrays of random integers and floating
 * point values.
 * @author ketsubetsu
 * <pre>
 * File: SortProfiler.cpp
 * </pre>
 */

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>

#include "ArrayUtil.cpp"
#include "SortUtil.cpp"

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv)
{
   
   int *iArray1, *iArray2, *iArray3;
   double *dArray1, *dArray2, *dArray3;
   long bTime, sTime, qTime;
   int size[] = {100, 500, 1000, 5000, 10000, 50000, 100000};
   srand(time(NULL));
   
   /******************************************************** 
   The code below is intended for debugging. Uncomment it
   to verify that all the code for the various sorting
   algorithms are working correctly.
   Comment out this section of the code again once you have
   verified that they work correctly. In each case a random
   array of size 50 is generated and the orignal and sorted
   arrays are printed.
   ********************************************************/
/*
      int *testArray = new int[50];
      cout<<"***Testing Selection Sort***"<<endl;
      cout<<"Original Array:"<<endl;
      ArrayUtil::genRandArray(testArray,50);
      ArrayUtil::printArray(testArray,0,49,5);
      cout<<endl;
      SortUtil::selectionSort(testArray,50);
      cout<<"Sorted Array:"<<endl;
      ArrayUtil::printArray(testArray,0,49,5);
      cout<<endl;
      
      cout<<"***Testing Bubble Sort***"<<endl;
      cout<<"Original Array:"<<endl;
      ArrayUtil::genRandArray(testArray,50);
      ArrayUtil::printArray(testArray,0,49,5);
      cout<<endl;
      SortUtil::bubbleSort(testArray,50);
      cout<<"Sorted Array:"<<endl;
      ArrayUtil::printArray(testArray,0,49,5);
      cout<<endl;
      

      cout<<"***Testing Quick Sort***"<<endl;
      cout<<"Original Array:"<<endl;
      ArrayUtil::genRandArray(testArray,50);
      ArrayUtil::printArray(testArray,0,49,5);
      cout<<endl;
      SortUtil::quickSort(testArray,0,49);
      cout<<"Sorted Array:"<<endl;
      ArrayUtil::printArray(testArray,0,49,5);
      cout<<endl;
      exit(1);
*/
   cout<<"Using Arrays with Random Integers"<<endl;
   cout<<setw(8)<<left<<"n"<<setw(16)<<left<<"selectionSort"<<setw(16)<<left<<"bubbleSort"<<setw(12)<<left<<"quickSort"<<endl;
   for(int i = 0; i < 50; i++) cout<<"-";
   cout<<endl;
   //cout<<"  n     selectionSort   bubbleSort   quickSort"<<endl;
   for (int i = 0; i < 7; i++)
   {
      iArray1 = new int[size[i]];
      iArray2 = new int[size[i]];
      iArray3 = new int[size[i]];		 
      
      ArrayUtil::genRandArray(iArray1,size[i]);
      ArrayUtil::arrayCopy(iArray1, 0, iArray2, 0, size[i]);
      ArrayUtil::arrayCopy(iArray1, 0, iArray3, 0, size[i]);
      
      auto start = high_resolution_clock::now();
      SortUtil::selectionSort(iArray1,size[i]);
      auto elapsed = high_resolution_clock::now() - start;
      sTime = duration_cast<microseconds>(elapsed).count();

      start = high_resolution_clock::now();
      SortUtil::bubbleSort(iArray2,size[i]);
      elapsed = high_resolution_clock::now() - start;
      bTime = duration_cast<microseconds>(elapsed).count();

      start = high_resolution_clock::now();
      SortUtil::quickSort(iArray3,0,size[i]-1);
      elapsed = high_resolution_clock::now() - start;
      qTime = duration_cast<microseconds>(elapsed).count();
	  
      cout<<setw(8)<<size[i]<<setw(16)<<sTime<<setw(16)<<bTime<<setw(12)<<qTime<<endl;
      
      delete[] iArray1;
      delete[] iArray2;
	  delete[] iArray3;          
   }
   cout<<endl<<endl;
   
   cout <<"*** NOW USING THE ALGORITHMS WITH DOUBLES ***"<<endl<<endl;

   /* Repeat/modify the code above for the same array sizes but this time
      the contents of the array (array type) would be doubles. The functions
      to generate random doubles has already been written for you.  Also, 
	  pointers to a double, dArray?, are declared for use in allocating the 
	  arrays of doubles. 
   */

   cout<<setw(8)<<left<<"n"<<setw(16)<<left<<"selectionSort"<<setw(16)<<left<<"bubbleSort"<<setw(12)<<left<<"quickSort"<<endl;
   for(int i = 0; i < 50; i++) cout<<"-";
   cout<<endl;
   //cout<<"  n     selectionSort   bubbleSort   quickSort"<<endl;
   for (int i = 0; i < 7; i++)
   {
      dArray1 = new double[size[i]];
      dArray2 = new double[size[i]];
      dArray3 = new double[size[i]];		 
      
      ArrayUtil::genRandArray(dArray1,size[i]);
      ArrayUtil::arrayCopy(dArray1, 0, dArray2, 0, size[i]);
      ArrayUtil::arrayCopy(dArray1, 0, dArray3, 0, size[i]);
      
      auto start = high_resolution_clock::now();
      SortUtil::selectionSort(dArray1,size[i]);
      auto elapsed = high_resolution_clock::now() - start;
      sTime = duration_cast<microseconds>(elapsed).count();

      start = high_resolution_clock::now();
      SortUtil::bubbleSort(dArray2,size[i]);
      elapsed = high_resolution_clock::now() - start;
      bTime = duration_cast<microseconds>(elapsed).count();

      start = high_resolution_clock::now();
      SortUtil::quickSort(dArray3,0,size[i]-1);
      elapsed = high_resolution_clock::now() - start;
      qTime = duration_cast<microseconds>(elapsed).count();
	  
      cout<<setw(8)<<size[i]<<setw(16)<<sTime<<setw(16)<<bTime<<setw(12)<<qTime<<endl;
      
      delete[] dArray1;
      delete[] dArray2;
	  delete[] dArray3;          
   }

 
  cout<<endl<<endl;
  return 0;
}
