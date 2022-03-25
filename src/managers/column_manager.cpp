#include "column_manager.hpp"


ColumnManager::ColumnManager(int columns_number, WindowManager *windowManager, EventManager *eventManager){
    this->windowManager = windowManager;
    this->eventManager = eventManager;

    this->columns_number = columns_number;
    this->width = (windowManager->getSize().x * 1.0) / (this->columns_number * 1.0);
    // Must use the inital window height because SFML automatically
    // scales size and position when resizing window
    this->original_window_height = windowManager->getInitialSize().y;
}


std::vector<sf::RectangleShape> ColumnManager::getColumns(){
    return columns;
}

int ColumnManager::getValue(int index){
    return columns[index].getSize().y;
}

int ColumnManager::getValueR(int index){
    // This function is for rendering
    // array accesses rather than comparisons
    highlight(index);
    return columns[index].getSize().y;
}

void ColumnManager::setValue(int index, int value){
    // Set height of columns[index] column to value
    // and update its position & color based on new height

    // See ColumnManager::create() for position explanation
    columns[index].setSize(sf::Vector2f(width, value));
    columns[index].setPosition(0, windowManager->getRenderWindow()->getSize().y - value);
    columns[index].setFillColor(getColor(value));
}

int ColumnManager::getNumber(){
    return columns_number;
}


void ColumnManager::swap(int index1, int index2){
    // Swap items in vector
    std::iter_swap(columns.begin() + index1, columns.begin() + index2);

    // You could also render the window here, I chose not
    // to but it's up to personal preference! (Right now
    // it renders the window at every comparison, rendering
    // here would mean rendering the window at every swap)
}

void ColumnManager::highlight(int index1, int index2){
    //Save Color to reset it later
    sf::Color color_index1 = columns[index1].getFillColor();
    sf::Color color_index2 = columns[index2].getFillColor();

    //Change color of values being swapped for visualization
    columns[index1].setFillColor(sf::Color::White);
    columns[index2].setFillColor(sf::Color::White);

    // Render columns and update event manager.
    // This allows for event handling during
    // sorting loops and also renders each step
    // of the sorting
    render();
    eventManager->update();

    //Reset Column Colors
    columns[index1].setFillColor(color_index1);
    columns[index2].setFillColor(color_index2);
}

void ColumnManager::highlight(int index){
    // Same as highlight(int, int) but for single highlights
    sf::Color color = columns[index].getFillColor();
    columns[index].setFillColor(sf::Color::White);

    render();
    eventManager->update();

    columns[index].setFillColor(color);
}

void ColumnManager::render(){
    windowManager->clearWindow();

    for(int i = 0; i < columns_number; i++){

        // Choose X position based on width and iteration
        // counter, then change only the X Position of the 
        // column because the Y has already been calculated
        // when creating columns.
        double posX = this->width * i;
        columns[i].setPosition(posX, original_window_height - columns[i].getSize().y); 

        windowManager->render(columns[i]);
    }

    windowManager->displayWindow();
}


sf::Color ColumnManager::getColor(int height){
    // Set hue values for coloring 
    // based on column height
    float max_height = float(windowManager->getSize().y);
    float hue_shift = float(255 / max_height);
    float hue_increase = hue_shift * (height);
    float hue_decrease = 255 - hue_increase;

    std::cout << hue_shift << ", " << hue_increase << ", " << hue_decrease << std::endl;

    switch(sortType){
        case 0:
            // Blue -> Purple
            return sf::Color(hue_increase, hue_decrease, 255); 

        case 1:
            // Red -> Yellow
            return sf::Color(255, hue_increase, 0); 

        case 2:
            // Red -> Purple
            return sf::Color(255, 0, hue_increase); 

        case 3:
            // Green -> Yellow
            return sf::Color(hue_increase, 255, 0); 

        case 4:
            // Purple -> Yellow
            return sf::Color(255, hue_decrease, hue_increase);

        case 5:
            // Cyan -> Red
            return sf::Color(hue_increase, hue_decrease, hue_decrease);

        default:
            // Red if it fails
            return sf::Color::Red;
    }
}

void ColumnManager::generate(int sortType){
    columns.clear();
    this->sortType = sortType;

    create();
    shuffle();
}

void ColumnManager::create(){

    for (int i = 0; i < columns_number; i++){
        // Add sf::RectangleShape instance to columns array
        sf::RectangleShape column;
        columns.push_back(column);

        // Set height based on column's index compared to columns_number
        // this also means that the initial array of columns is
        // always sorted. 
        // Then set column's size since width has already been set.

        // NOTE: ratio must be a double because when columns_number > window.y
        // it would be rounded to 0, which would still equal 0 when multiplied
        // by iteration counter
        double ratio = (original_window_height * 1.0) / (columns_number * 1.0);
        double height = ratio * (i+1);
        columns[i].setSize(sf::Vector2f(this->width, height));

        // Set position of column, the x value doesn't matter since it
        // is calculated in ColumnManager::render(), the y value puts
        // the bottom of the column at the bottom of the window.
        // This makes the columns go from the bottom up instead of the other 
        // way around, which would be the default in SFML as (0,0) = top left.
        columns[i].setPosition(0, original_window_height - height);

        // If the column is large enough, set an outline
        // otherwise leave no outline. 
        // This is because when the columns are really small
        // the outline can cover the columns next to each other
        // (it also looks much prettier like a smooth gradient)
        if(this->width > 10){
            columns[i].setOutlineThickness(1);
            columns[i].setOutlineColor(sf::Color::Black);
        }

        columns[i].setFillColor(getColor(height));
    }
}

void ColumnManager::shuffle(){
    // This shuffles the existing columns,
    // it does not create a new set!

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(columns.begin(), columns.end(), g);
}