#pragma once

#include <SFML/Graphics.hpp>

#include "../managers/column_manager.hpp"

class SelectionSort{
    public:
        SelectionSort(ColumnManager *columnManager);
        void sort();

    private: 
        void SSORT();

        ColumnManager *columnManager;
};