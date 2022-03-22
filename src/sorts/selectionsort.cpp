#include "selectionsort.hpp"

SelectionSort::SelectionSort(ColumnManager *columnManager){
    this->columnManager = columnManager;
}

void SelectionSort::sort(){
    SSORT();
}

void SelectionSort::SSORT(){
    // Repeat for every column
    for(int i = 0; i < columnManager->getNumber(); i++){

        // Set the current minimum value to the value 
        // of the current index, and the current minimum index
        // to the current index itself
        double currentMinimum = columnManager->getValue(i);
        int currentMinimumIndex = i;

        // Repeat for every column after the current minimum index
        for(int j = i+1; j < columnManager->getNumber(); j++){
            // Get value of the current interation index 
            double currentValue = columnManager->getValue(j);

            //Render and calculate render time
            columnManager->highlight(j, currentMinimumIndex);

            // If the value of the current iteration is smaller 
            // than the current minimum value, make the current
            // minimum value the value of the current iteration,
            // and the current minimum index the index of the 
            // current iteration
            
            // Basically, this changes the general current minimum value
            // to the newfound smallest value, and it is done every time 
            // a new smallest value is found
            if (currentValue < currentMinimum) {
                currentMinimum = currentValue;
                currentMinimumIndex = j;
            }
        }
        // Swap the new smallest value with the current smallest
        // value, and when this is done for every column it
        // is putting at each iteration the new smallest value 
        // in its right place
        columnManager->swap(i, currentMinimumIndex);
    }
}