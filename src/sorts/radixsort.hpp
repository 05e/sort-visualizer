#pragma once

#include <SFML/Graphics.hpp>

#include "../managers/column_manager.hpp"

class RadixSort{
    public:
        RadixSort(ColumnManager *columnManager);
        void sort();
        

    private: 
        void RSORT();
        void count(int exponent);

        ColumnManager *columnManager;
};