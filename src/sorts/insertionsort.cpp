#include "insertionsort.hpp"


InsertionSort::InsertionSort(ColumnManager *columnManager){
    this->columnManager = columnManager;
}   

void InsertionSort::sort(){
    ISORT();
}

void InsertionSort::ISORT(){

    // Repeat for every item in array (except first item 
    // because it is always sorted at the start)
    for(int i = 1; i < columnManager->getNumber(); i++){
        // Repeat for every item smaller than i,
        // start from the highest index going down to the 
        // lowest, if the current iteration value is larger
        // than the next index value, swap the two.
        int j = i - 1;
        while(j >= 0 && columnManager->getValue(j) > columnManager->getValue(j+1)){

            //Highlight
            columnManager->highlight(j, i);
            
            columnManager->swap(j, j+1);
            j=j-1;
        }
    }
}