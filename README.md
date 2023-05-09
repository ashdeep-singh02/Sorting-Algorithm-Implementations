[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7774748&assignment_repo_type=AssignmentRepo)
# Assignment 4

## Background Information: 
In this project we implemented various algorithms to sort an array of elements from least to greatest. 

Insertion sort is an algorithm used for sorting that essentially splits the array into two parts. One side is dedicated to hold the sorted elements, while the other holds the remaining elements. At each iteration, we pick an element from the unsorted section and search for its correct position in the sorted section. All elements that come after the correctly placed element must be moved up 1 index before we insert the item.

The selection sort algorithm functions by repeatedly finding the minimum element at each iteration. Like insertion sort, it too divides the array into a sorted/unsorted section. Once the smallest element in the unsorted section has been found, the element is added to the sorted section of the array. 

Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then it merges the two sorted halves. The merge_sort splits the array into halves repeatedly until only one element remains in the array. The merge function is then called on the arrays split by merge_sort to "concatenate" them into one array in sorted order. 

## Our Task:
Our task in this project was to implement the helping functions that allow these algorithms to work successfully. This included:
* findSmallest- find the smallest element (Selection Sort)
* swap- swap two elements at specific indices (Selection Sort)
* findPos- return an elements correct position in sorted order (Insertion Sort)
* moveUp1- move up data in an array to account for new element to be inserted (Insertion Sort)
* merge- merges elements from two arrays in sorted order (Merge Sort)

## Bugs Encountered: 
* Merge Sort final array was missing elements; Error- neglected to check for elements remaining in one array once the other array runs out of elements; Solution- Include check for both sides (right/left) of array, if elements remaining push them into the sorted array.
* Array returned by insertion sort contained larger numbers; Error- Incorrect indexing with findPos helper function. causing the address of an index out of bounds to be added to the array.


Instructions on how to compile and run the code are listed below.

## To Run:
Create an array in sort_driver.cc; Pass created array to one of the sorting algorithm functions as an argument, along with other necessary details. 

## To Compile

The command:

```bash
make
```

will produce the library file `sort.o` and executable `sort_driver`.


## To Run

```bash
./sort_driver
```
