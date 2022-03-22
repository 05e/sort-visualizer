#pragma once

#include <string>

#include "column_manager.hpp"
#include "window_manager.hpp"

#include "../sorts/quicksort.hpp"
#include "../sorts/bubblesort.hpp"
#include "../sorts/insertionsort.hpp"
#include "../sorts/selectionsort.hpp"
#include "../sorts/mergesort.hpp"
#include "../sorts/radixsort.hpp"

class SortManager{
    public:
        SortManager(WindowManager *windowManager, ColumnManager *columnManager);

        void sort();

        void setSortType(int sortType);
        int getSortType();
        std::string getTitle();

        void setSorted(bool sorted);
        bool isSorted();

    private:
        int sortType;
        bool sorted;

        ColumnManager *columnManager;
        WindowManager *windowManager;
};