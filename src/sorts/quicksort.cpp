#include "quicksort.hpp"

QuickSort::QuickSort(ColumnManager *columnManager){
    this->columnManager = columnManager;
}

void QuickSort::sort(){
    int max = columnManager->getNumber() - 1; 
    QSORT(0, max);
}

int QuickSort::partition(int min, int max){

    double pivot = columnManager->getValue(max);
    int i = min - 1;

    // Makes all values sorted compared to the pivot value
    for(int j = min; j < max; ++j){
        double currentValue = columnManager->getValue(j);

        // Highlight
        columnManager->highlight(j, max);

        if( currentValue <= pivot){
            i++;
            columnManager->swap(i, j);
        }
    }
    columnManager->swap(i+1, max);

    return i+1;
}

void QuickSort::QSORT(int min, int max){
    if(min < max){
        int pivot = partition(min, max);

        QSORT(min, pivot-1); //Quicksort Left Side
        QSORT(pivot+1, max); //Quicksort Right Side
    }
}