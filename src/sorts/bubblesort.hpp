#pragma once

#include <SFML/Graphics.hpp>

#include "../managers/column_manager.hpp"

class BubbleSort{
    public:
        BubbleSort(ColumnManager *columnManager);
        void sort();

    private: 
        void BSORT();

        ColumnManager *columnManager;
};

