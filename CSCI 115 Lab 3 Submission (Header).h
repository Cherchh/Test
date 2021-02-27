#ifndef CSCI115_LAB3_ARRAYSORTER_H
#define CSCI115_LAB3_ARRAYSORTER_H
/* This is my submission for Lab 3. This program includes functions
 * that perform different sorting algorithms on a given array,
 * such as Selection Sort, Insertion Sort, and Bubble Sort,
 * as well implementing Binary Search both Iteratively and
 * Recursively.
 *
 *
 * Created by Christian C. on 2/5/2021.
 *
 **/

class ArraySorter{
public:
    int * myArray;
    int size;

    ArraySorter(); //default constructor creates an array of size 10 w/ random numbers
    void swap(int a, int b); //swaps content at myArray[a] and myArray[b]
    void randomizeArray(); //fills the array with random numbers
    void displayArray(); //outputs the array to the console
    void bubbleSort(); //performs Bubble Sort
    void selectionSort(); //performs Selection Sort
    void insertionSort(); //performs Insertion Sort
    int binarySearchIt(int left, int right, int target); //performs Iterative binary search for target, returns index if found, else -1
    int binarySearchRec(int left, int right, int target); //performs recursive binary search for target, if found returns the index, else -1
};

#endif //CSCI115_LAB3_ARRAYSORTER_H
