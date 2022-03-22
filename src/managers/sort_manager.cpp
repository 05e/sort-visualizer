#include "sort_manager.hpp"

SortManager::SortManager(WindowManager *windowManager, ColumnManager *columnManager){
    this->windowManager = windowManager;
    this->columnManager = columnManager;

    setSorted(false);
    setSortType(0); //Quicksort by default
}

void SortManager::sort(){

    if(!sorted){

        std::cout << "STARTED SORTING" << std::endl;
        switch(this->sortType){
            case 0:{
                QuickSort QuickSort(this->columnManager);
                QuickSort.sort();
                break;
            }

            case 1:{
                BubbleSort BubbleSort(this->columnManager);
                BubbleSort.sort();
                break;
            }

            case 2:{
                InsertionSort InsertionSort(this->columnManager);
                InsertionSort.sort();
                break;
            }

            case 3:{
                SelectionSort SelectionSort(this->columnManager);
                SelectionSort.sort();
                break;
            }

            case 4:{
                MergeSort MergeSort(this->columnManager);
                MergeSort.sort();
                break;
            }

            case 5:{
                RadixSort RadixSort(this->columnManager);
                RadixSort.sort();
                break;
            }

            default:
                break;
        }

        setSorted(true);
    }

    
}


void SortManager::setSortType(int sortType){
    /* SORT TYPE DICTIONARY:
    *  0: QuickSort
    *  1: BubbleSort
    *  2: InsertionSort
    *  3: SelectionSort
    *  4: MergeSort
    *  5: RadixSort
    */
   
   if(sortType != this->sortType){
        this->sortType = sortType;

        //Update Title
        this->windowManager->setTitle(getTitle());
        std::cout << "Selected Algorithm: " << getTitle() << std::endl;

        //Regen Columns
        this->columnManager->generate(this->sortType);

        //Update Sorted State 
        this->sorted = false;
   }
}

int SortManager::getSortType(){
    return this->sortType;
}

std::string SortManager::getTitle(){
    switch(this->sortType){
        case 0:
            return "Quick Sort";
            break;
        
        case 1:
            return "Bubble Sort";

        case 2:
            return "Insertion Sort";

        case 3:
            return "Selection Sort";

        case 4:
            return "Merge Sort";

        case 5:
            return "Radix Sort";

        default:
            return "No Title";
    }
}


void SortManager::setSorted(bool sorted){
    this->sorted = sorted;
    if(this->sorted) std::cout << "SORTED!" << std::endl << std::endl;
}

bool SortManager::isSorted(){
    return this->sorted;
}