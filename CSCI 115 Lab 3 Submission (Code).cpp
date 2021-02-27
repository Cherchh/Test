#include <iostream>
#include "ArraySorter.h"
using namespace std;

ArraySorter::ArraySorter() {
    size = 10;
    myArray = new int [size];

    for(int i = 0; i < size; i++){
        myArray[i] = rand() % 10 + 1;
    }
}

void ArraySorter::swap(int a, int b){
    int temp;

    temp = myArray[a];
    myArray[a] = myArray[b];
    myArray[b] = temp;
}

void ArraySorter::randomizeArray() {

    for(int i = 0; i < size; i++){
        myArray[i] = rand() % 10 + 1;
    }

}

void ArraySorter::displayArray() {

    for(int i = 0; i < size;i++){
        cout << myArray[i] << " ";
    }
    cout << endl;
}

void ArraySorter::bubbleSort() {

    int temp;

    for (int i = 0; i < size-1; i++){
        for (int j = 0; j < size-i-1; j++){
            if (myArray[j] > myArray[j+1]){
                //swaps j with j+1
                temp = myArray[j];
                myArray[j] = myArray[j+1];
                myArray[j+1] = temp;
            }
        }
    }

}

void ArraySorter::selectionSort() {

    int min;
    int temp;

    for (int i = 0; i < size-1; i++){
        min = i; // Finds the minimum element
        for (int j = i+1; j < size; j++){
            if (myArray[j] < myArray[min]){
                min = j;
            }
        }
        //Swaps min and first element
        temp = myArray[min];
        myArray[min] = myArray[i];
        myArray[i] = temp;
    }

}

void ArraySorter::insertionSort() {

    int key;
    int i;
    int j;

    for (i = 1; i < size; i++){
        key = myArray[i];
        j = i - 1;

        while (j >= 0 && myArray[j] > key) { //Moves myArray[i] right one if they're greater than key
            myArray[j + 1] = myArray[j];
            j = j - 1;
        }
        myArray[j + 1] = key;
    }

}

int ArraySorter::binarySearchIt(int left, int right, int target) { //Returns index of target

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If target is in the middle
        if (myArray[mid] == target){
            return mid;
        }


        // If target is greater than middle, search right subarray
        if (myArray[mid] < target){
            left = mid + 1;
        }

        // If target is smaller than middle, search left subarray
        else{
            right = mid - 1;
        }
    }

    // if target is not found, return -1
    return -1;

}

int ArraySorter::binarySearchRec(int left, int right, int target) { //Returns index of target

    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If target is in the middle
        if (myArray[mid] == target){
            return mid;
        }

        // If target is smaller than mid, then search left subarray
        if (myArray[mid] > target){
            return binarySearchRec(left, mid - 1, target);
        }

        // If target is greater than mid, then search right subarray
        return binarySearchRec(mid + 1, right, target);
    }

    // If target isn't in array, return -1
    return -1;

}

//For testing purposes
int main() {

    ArraySorter* myArray = new ArraySorter[10];

    cout << "Before: ";
    myArray->displayArray();
    cout << endl;
/*
    myArray->randomizeArray();

    myArray->bubbleSort();

    myArray->selectionSort();

    myArray->insertionSort();
*/
    cout << "After: ";
    myArray->displayArray();
    cout << endl;

    int binSearchRec = myArray->binarySearchRec(0,9, 10);;
    cout << "Binary search (recursive) for 10: " << binSearchRec << endl;

    int binSearchIt = myArray->binarySearchIt(0,9, 10);;
    cout << "Binary search (iterative) for 10: " << binSearchIt << endl;


    return 0;
}
