#include "event_manager.hpp"

EventManager::EventManager(WindowManager *windowManager){
    this->windowManager = windowManager;
}

void EventManager::update(){

    sf::Event event;
    while(windowManager->getRenderWindow()->pollEvent(event)){
        
        // Closes program when closing window
        // even if in a loop (eventManager.update)
        // is called in columnManager.swap)
        if(event.type == sf::Event::Closed) {
            std::exit(1); //ugly, but it works
        }

        else if(event.type == sf::Event::Resized){
            if (windowManager->getSize().x < 400 || windowManager->getSize().y < 250) 
                windowManager->setSize(400, 250);
        }
    }

    // stop sorting on keypress?
}