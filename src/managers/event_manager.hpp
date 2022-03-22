#pragma once

#include <iostream>

#include "window_manager.hpp"

class EventManager{
    public:
        EventManager(WindowManager *windowManager);

        void update();

    private:
        WindowManager *windowManager;
};