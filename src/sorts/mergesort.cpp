#include "mergesort.hpp"

// https://www.youtube.com/watch?v=TzeBrDU-JaY 
// ^^^ super duper great video

MergeSort::MergeSort(ColumnManager *columnManager){
    this->columnManager = columnManager;
}

void MergeSort::sort(){
    MSORT(0, columnManager->getNumber()-1);
}

// setValue(index, value) for loop breaks everything

void MergeSort::MSORT(int low, int high){
    // This makes the recursion continue
    // until the low point reaches the high 
    // point, meaning the whole array
    // has been iterated through, broken down,
    // and merged.
    if(low < high){
        int mid = (low+high) / 2;
        // Recursively MSORT() by doing
        // left side first (low = low, high = mid)
        // and right side second (low = mid+1, high= high)
        // This is what "breaks down" the array into single
        // values, before starting to merge them
        MSORT(low, mid); 
        MSORT(mid+1, high); 
        merge(low, high, mid);
    }
}

void MergeSort::merge(int low, int high, int mid){

    // Create temporary array where
    // values will be added onto
    // This is ugly because I could just
    // have temp[high], but <C++11 doesn't allow
    // variable size arrays so here we go
    int max = columnManager->getNumber();
    int temp[max];

    // Start indexes that will be used
    // to iterate through the arrays
    int left_index = low;
    int right_index = mid+1;
    int temp_index = low;

    // Repeat for as long as:
    // left index is between 0 and middle point
    // AND 
    // right index is between middle point and highest point
    while (left_index <= mid && right_index <= high){

        // Highlight
        columnManager->highlight(left_index, right_index);

        // If the item of the current iteration from the 
        // left partition is smaller / equal to the item
        // of the current iteration from the right side,
        // set the item of the iteration index of the temp
        // array to the item of the current iteration from the 
        // left partition
        if(columnManager->getValue(left_index) <= columnManager->getValue(right_index)){
            temp[temp_index] = columnManager->getValue(left_index);
            left_index++;
        }
        // Otherwise, do the same thing but with the
        // item of the current iteration of the right
        // partition instead
        else{
            temp[temp_index] = columnManager->getValue(right_index);
            right_index++;
        } 

        temp_index++;
    }

    // Only one of these two will trigger
    // once only one of the two inital partitions
    // (left & right) are missing some items in them.

    // These set the remaining values of the left or right
    // array as the value for the temp array with the 
    // temp_index
    while (left_index <= mid){

        // Highlight
        columnManager->highlight(left_index, mid);

        temp[temp_index] = columnManager->getValue(left_index);

        temp_index++;
        left_index++;
    } 
    while (right_index <= high){

        // Highlight
        columnManager->highlight(right_index, high);

        temp[temp_index] = columnManager->getValue(right_index);

        temp_index++;
        right_index++;
    }


    // Once the temp array is finished,
    // set items of the real array
    // to the items of the temp one
    for(int i = low; i < temp_index; i++) {
        columnManager->setValue(i, temp[i]);
    }
}