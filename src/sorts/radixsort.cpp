#include "radixsort.hpp"

RadixSort::RadixSort(ColumnManager *columnManager){
    this->columnManager = columnManager;
}

void RadixSort::sort(){
    RSORT();
}


void RadixSort::RSORT(){

    // Get the highest value in the array
    // AKA the tallest column
    // This will be used to know how many digits 
    // the highest value has and therefore how 
    // many iterations the loop should do
    int highest_value = 0;
    for(int i = 0; i < columnManager->getNumber(); i++){
        int value = columnManager->getValue(i);
        
        if (value > highest_value) highest_value = value;
    }

    // This loop performs count sort for
    // every digit in the highest value,
    // which will sort the array

    // E.g. highest_value = 4281, the loop
    // does 4 iterations since 4281 has 4 digits
    for (int exponent = 1; highest_value / exponent; exponent *= 10){
        count(exponent);
    }
}

void RadixSort::count(int exponent){

    int columns_number = columnManager->getNumber();
    // Temporary array will be used 
    // to output values of count array
    int temp[columnManager->getNumber()];
    // Count array will be used to perform 
    // counting sort, 10 items with value 0
    int count[10] = { 0 };

    // count sort ?
    for (int i = 0; i < columns_number; i++) {
        int value = columnManager->getValueR(i);

        count[(value / exponent) % 10]++;
    }

    // count sort step 2
    for (int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    // Get count sort real values and put them
    // in temporary array that will be used as output
    for (int i = columns_number - 1; i >= 0; i--){
        int value = columnManager->getValueR(i);

        temp[count[(value / exponent) % 10] - 1] = value;
        count[(value / exponent) % 10]--;
    }

    // When the counting sort has been done, 
    // copy temporary array values into real array

    // This sorts correctly for current digit,
    // i.e. first RadixSort::count() iteration
    // sorts like 30, 11, 62, 23 and second 
    // iteration sorts second digit like
    // 11, 23, 30, 62. Because RadixSort::count()
    // is called once for every amount of digit
    // the highest_value has, the array will 
    // be fully sorted
    for (int i = 0; i < columns_number; i++) {
        columnManager->setValue(i, temp[i]);

        // Highlight
        columnManager->highlight(i);
    }
}