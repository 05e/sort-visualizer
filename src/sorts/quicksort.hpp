#pragma once

#include <SFML/Graphics.hpp>

#include "../managers/column_manager.hpp"

class QuickSort{
    public:
        QuickSort(ColumnManager *columnManager);
        void sort();
        
    private: 
        void QSORT(int min, int max);
        int partition(int min, int max);

        ColumnManager *columnManager;
};

