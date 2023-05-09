/**
 *
 * @file sort_driver.cc
 * @author Ashdeep Singh (Ashdeep.Singh98@myhunter.cuny.edu)
 * @brief testing file for sort.cc/sort.h
 * @version 0.1
 * @date 05/06/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "sort.h" // include the sort library
#include <iostream>
using namespace std;

int main()
{
	// TODO: Test your sort library. This code will not be graded.
	int arr[5] = {-9, 5, 34, 7,23};
	int size = 5;
	// insertion_sort(arr, size);

	merge_sort(arr, 0 , 4, (4/2));

	for(int i = 0; i < size; i++){
		cout << arr[i] << endl;
	}

	// selection_sort(arr,6);
	// for(int i = 0; i < size; i++){
	// 	cout << arr[i] << endl;
	// }
}
