#include "event_manager.hpp"

EventManager::EventManager(WindowManager *windowManager){
    this->windowManager = windowManager;
}

void EventManager::update(){

    sf::Event event;
    while(this->windowManager->getRenderWindow()->pollEvent(event)){
        
        // Closes program when closing window
        // even if in a loop (eventManager.update)
        // is called in columnManager.swap)
        if(event.type == sf::Event::Closed) {
            this->windowManager->terminateWindow();
        }

        // Exit sorting button?
        // closing window in a loop won't close the app

        // create quit function in all sorts that
        // turns a bool to true, in the sorting
        // loop do if(exit) break; or something
    }
}
