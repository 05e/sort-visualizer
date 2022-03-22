#pragma once

#include <SFML/Graphics.hpp>

#include "../managers/column_manager.hpp"

class MergeSort{
    public:
        MergeSort(ColumnManager *columnManager);
        void sort();
        
    private: 
        void MSORT(int low, int high);
        void merge(int low, int high, int mid);

        ColumnManager *columnManager;
};

