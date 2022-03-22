#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <random>

#include "window_manager.hpp"
#include "event_manager.hpp"

class ColumnManager{
    public:

        ColumnManager(int columns_number, WindowManager *windowManager, EventManager *eventManager);
        
        void generate();
        void generate(int sortType);
        void shuffle();

        void swap(int index1, int index2);

        void highlight(int index1, int index2);
        void highlight(int index);
        void render();


        std::vector<sf::RectangleShape> getColumns();
        int getNumber();

        int getValue(int index);
        int getValueR(int index);
        void setValue(int index, int value);
        
    private:
    
        int columns_number;
        int sortType;
        double width;

        void create();
        sf::Color getColor(int height);

        WindowManager *windowManager;
        EventManager *eventManager;
        std::vector<sf::RectangleShape> columns;
};