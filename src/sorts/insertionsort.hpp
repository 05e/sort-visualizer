#pragma once

#include <SFML/Graphics.hpp>

#include "../managers/column_manager.hpp"

class InsertionSort{
    public:
        InsertionSort(ColumnManager *columnManager);
        void sort();

    private: 
        void ISORT();

        ColumnManager *columnManager;
};

