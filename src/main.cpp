#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "managers/application.hpp"


//https://github.com/zedrex/algosketch

// sort alg. idea: at each step, check which items are sorted 
// and randomly swap all the ones that aren't
// https://www.geeksforgeeks.org/program-check-array-sorted-not-iterative-recursive/ 


// radix sort
// randomize, keep correct ones, randomize, etc.

// user input for n of columns
// ^^ window no worky :(


int main()
{
    srand(time(NULL));

    WindowManager windowManager(1000, 600);
    EventManager eventManager(&windowManager);
    ColumnManager columnManager(111, &windowManager, &eventManager);
    SortManager sortManager(&windowManager, &columnManager);


    while(windowManager.isRunning()){

        //Event Handling when not in a loop
        sf::Event event;
        while(windowManager.getRenderWindow()->pollEvent(event)){

            switch (event.type){

                case sf::Event::Closed: 
                    windowManager.terminateWindow();
                    break;


                case sf::Event::KeyPressed:

                    /* KEYBINDS:
                    *  [1] - QUICKSORT
                    *  [2] - BUBBLESORT
                    *  [3] - INSERTIONSORT
                    *  [4] - SELECTIONSORT
                    *  [5] - MERGESORT
                    *  [6] - RADIXSORT
                    * 
                    *  [R] - SHUFFLE
                    *  [G] - GENERATE NEW COLUMNS
                    *  [SPACE] - SORT
                    */

                    if(event.key.code == sf::Keyboard::R){
                        columnManager.shuffle();
                        sortManager.setSorted(false);
                    }

                    if(event.key.code == sf::Keyboard::G){
                        columnManager.generate(sortManager.getSortType());
                        sortManager.setSorted(false);
                    }

                    if(event.key.code == sf::Keyboard::Space) sortManager.sort();

                    if(event.key.code == sf::Keyboard::Num1) sortManager.setSortType(0);
                    if(event.key.code == sf::Keyboard::Num2) sortManager.setSortType(1);
                    if(event.key.code == sf::Keyboard::Num3) sortManager.setSortType(2);
                    if(event.key.code == sf::Keyboard::Num4) sortManager.setSortType(3);
                    if(event.key.code == sf::Keyboard::Num5) sortManager.setSortType(4);
                    if(event.key.code == sf::Keyboard::Num6) sortManager.setSortType(5);
                    
                    break;
                
                default:
                    break;
            }
        }

        columnManager.render();
    }

    return 0;
}   