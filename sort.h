/**
 * @file sort.h
 * @author Ashdeep Singh (Ashdeep.Singh98@myhunter.cuny.edu)
 * @brief H file for sorting algorithms: Insertion Sort, Selection Sort, and Merge Sort along with their helper functions
 * @version 0.1
 * @date 05/06/2022
 *
 * @copyright Copyright (c) 2022
 */

#ifndef _SORT_H_
#define _SORT_H_

// The sorting functions.
//@brief: sorts an array using selection sort
//@param: arr- the array containing the elements to be sorted; int size- the size of the passed arr
template <typename Comparable>
void selection_sort(Comparable arr[], int asize);

//@brief: sorts an array using insertion sort
//@param: arr- the array containing the elements to be sorted; int size- the size of the passed arr
template <typename Comparable>
void insertion_sort(Comparable arr[], int asize);

//@brief: sorts an array using merge sort
//@param: a- the array containing the elements to be sorted; start- the begining postion on the array; end- the end position of the array; mid- the middle positon of the array
template <typename Comparable>
void merge_sort(Comparable a[], int start, int end, int mid);

// The sorting "helper" functions.

// Must work in O(n) time (linear).
//@brief: Returns the position of the smallest Comparable in arr from start to end inclusive
//@param: arr- array to search in; start- the starting point of the sorted array section; end- the ending point of the sorted array section
//@return: an integer represeinting the smallest integer in arr
template <typename Comparable>
int findsmallest(const Comparable arr[], const int start, const int end);

// Must work in O(1) time (constant).
//@brief: Swaps the element at position pos1 with the element at position pos2 in arr.
//@param: pos1- the index of the first element; pos2- index of the second element
template <typename Comparable>
void swap(Comparable arr[], const int pos1, const int pos2);

// @brief: Returns the position, between 0 and size, in arr to insert the target value in insertion sort.
// Must work in O(n) time (linear).
// @param: arr- the array to search in; target- value to place in arr (use as value on compare with); size- size of sorted array
// @return: index representing the position target vale should be placed at
template <typename Comparable>
int findpos(const Comparable arr[], Comparable target, const int size);

// @brief: Moves up all data in arr from start to end inclusive one space.
// Must work in O(n) time (linear).
// @param: arr- array to iterate through; start- starting index of the sorted array; end- ending index of sorted array
template <typename Comparable>
void moveup1(Comparable arr[], const int start, const int end);

// @briefCombines two sorted sub-arrays of arr (i.e., the inclusive intervals [left, pivot] and [pivot+1, right]) to a single sorted array.
// The result of this combined, sorted array is stored back into arr to form a single, sorted array, whose valid elements are contained
// in the interval [left, right]. Must work in O(n) time (linear).
// @praram: arr- array to merge; left- starting point of array; right- end point of array; pivot- middle point in array
template <typename Comparable>
void merge(Comparable arr[], int left, int right, int pivot);

#endif
