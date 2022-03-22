#include "bubblesort.hpp"

BubbleSort::BubbleSort(ColumnManager *columnManager){
    this->columnManager = columnManager;
}

void BubbleSort::sort(){
    BSORT();
}

void BubbleSort::BSORT(){

    // Repeat for every column to sort highest column
    // column_number amount of times, therefore sorting
    // the entire array
    for(int i = 0; i < columnManager->getNumber(); i++){

        // Repeat for every column again, since this loop
        // sorts the highest column once ( - 1 so it doesn't 
        // compare the last column to an inexistent array value
        // and -i so it doesn't compare all the values it has 
        // already sorted)
        for(int j = 0; j < (columnManager->getNumber() - i) - 1; j++){

            double currentValue = columnManager->getValue(j);
            double nextValue = columnManager->getValue(j+1);

            //Highlight
            columnManager->highlight(j, j+1);
            
            // If next value is smaller than the current one, swap
            // this causes the biggest value in the array to 'bubble'
            // up to the top at each step.
            if(nextValue < currentValue) columnManager->swap(j, j+1);
        }
    }
}
