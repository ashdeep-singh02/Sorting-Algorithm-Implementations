/**
 *
 * @file sort.cc
 * @author Ashdeep Singh (Ashdeep.Singh98@myhunter.cuny.edu)
 * @brief Implementation of insertion, selection, and merge sort along with their helper functions
 * @version 0.1
 * @date 05/06/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "sort.h"

#include <utility> // for std::swap(), etc.



template <typename Comparable>
void selection_sort(Comparable arr[], int asize)
{
	//sort all the info in arr (total size: asize) from smallest to largest.
	int nsort = 0; // size of the sorted section.

	while (nsort < asize)
	{
		int spos = findsmallest(arr, nsort, asize - 1);
		swap(arr, spos, nsort); // interchange the 2 values.
		++nsort;
	}
}

template <typename Comparable>
void insertion_sort(Comparable arr[], int asize)
{
	int nsort = 0; // size of the sorted section.

	while (nsort < asize)
	{
		Comparable copy = std::move(arr[nsort]);
		int pos = findpos(arr, copy, nsort);
		// pos is the position for copy.
		// nsort is size of sorted values.

		moveup1(arr, pos, nsort - 1);
		// move data from pos to nsort-1 inclusive.

		arr[pos] = std::move(copy);
		++nsort;
	}
}

// 'a' is an array of 'Items' whose valid elements are between 'start' and 'end', inclusively.
// 'mid' is the position in 'a' in which to divide the array.
template <typename Comparable>
void merge_sort(Comparable a[], int start, int end, int mid)
{

	if (start >= end) // the array is either empty or contains a single element.
		return;		  // sorting problem already solved. Nothing to do.

	// sort the left portion of the array.
	merge_sort(a, start, mid, (start + mid) / 2);

	// sort the right portion of the array
	merge_sort(a, mid + 1, end, (mid + 1 + end) / 2);

	// combined the two sorted array portions in a single sorted array.
	merge(a, start, end, mid);
}

// Returns the position of the smallest Comparable in arr from start to end inclusive
// @pre start <= end
template <typename Comparable>
int findsmallest(const Comparable arr[], int start, int end)
{
	int currentSmallest = start; //variable holding the smallest value found in arr
	for(int i = start+1; i <= end; i++){
		if(arr[i] < arr[currentSmallest]) currentSmallest = i;
	}
	return currentSmallest;
}

// Swaps the element at position pos1 with the element at position pos2 in arr.
template <typename Comparable>
void swap(Comparable arr[], int pos1, int pos2)
{
	int temp = std::move(arr[pos1]); //std move to prevent unnecessary copies 
	arr[pos1] = std::move(arr[pos2]);
	arr[pos2] = std::move(temp);
}

// Returns the position, between 0 and size, in arr to insert the target value in insertion sort.
template <typename Comparable>
int findpos(const Comparable arr[], Comparable target, int size)
{
	int sizeCopy = size; //copy of size, prevent original data from being manipulated
	while((sizeCopy > 0) && (arr[sizeCopy - 1] > target)){
		sizeCopy--; //decrement in correct position not found; continue searching
	}
	return sizeCopy;
}

// Moves up all data in arr from start to end inclusive one space.
template <typename Comparable>
void moveup1(Comparable arr[], int start, int end)
{
	for(int j = end; j >= start; j --){
		arr[j+1] = std::move(arr[j]); //move up the values in the arr 
	}
}

// Combines two sorted sub-arrays of arr (i.e., the inclusive intervals [left, pivot] and [pivot+1, right])
// to a single sorted array.
template <typename Comparable>
void merge(Comparable arr[], int left, int right, int pivot) {
	int leftBegin = left; //variables representing the start/end of the 2 arrays to be merged
	int leftEnd = pivot;
	int rightBegin = pivot+1; 
	int rightEnd = right;
	
	int tempPos = left; //pointer to second (temp) array

	int numElements = right - left + 1; 
	Comparable tempArr[numElements]; //temporary array to merge data into

	while(leftBegin <= leftEnd && rightBegin <= rightEnd){ //compare elements in 1st and 2nd arrays
		if(arr[leftBegin] <= arr[rightBegin]){
			tempArr[tempPos++] = std::move(arr[leftBegin++]);
		}
		else{
			tempArr[tempPos++] = std::move(arr[rightBegin++]);
		}
	}

	while(leftBegin <= leftEnd){ //add remaning elements from left arr
		tempArr[tempPos++] = std::move(arr[leftBegin++]);
	}
	while(rightBegin <= rightEnd){ //add remaning elements from right arr
		tempArr[tempPos++] = std::move(arr[rightBegin++]);
	}

	for(int i = 0; i < numElements; ++i, --rightEnd){ //copy values back into original array
		arr[rightEnd] = std::move(tempArr[rightEnd]);
	}

}

// Template instantiations. Only ints are supported for now. Do not change these but add more instantiations
// for other types if you like.
template void selection_sort<int>(int[], int);
template int findsmallest<int>(const int[], int, int);
template void insertion_sort<int>(int[], int);
template void merge_sort<int>(int[], int, int, int);
