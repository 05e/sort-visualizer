#include "window_manager.hpp"

WindowManager::WindowManager()
{
    this->setupWindow(800, 400);
}

WindowManager::WindowManager(int windowWidth, int windowHeight)
{
    this->setupWindow(windowWidth, windowHeight);
}

WindowManager::~WindowManager()
{
    this->terminateWindow();
}



bool WindowManager::isRunning()
{
    return this->running;
}

sf::RenderWindow *WindowManager::getRenderWindow()
{
    return &(this->window);
}

sf::Vector2u WindowManager::getSize(){
    return this->window.getSize();
}



void WindowManager::render(const sf::Drawable &drawable)
{
    this->window.draw(drawable);
}

void WindowManager::displayWindow()
{
    this->window.display();
}

void WindowManager::clearWindow()
{
    this->window.clear(sf::Color::Black);

    render(this->title);
}

void WindowManager::setTitle(std::string title){
    this->title.setString(title);
}


void WindowManager::terminateWindow()
{
    this->running = false;
    this->window.close();
}

void WindowManager::setupWindow(int windowWidth, int windowHeight)
{
    //Set up Title & Font
    this->font.loadFromFile("res/computer-modern.ttf");
    this->title.setFont(font);
    this->title.setCharacterSize(46);

    this->windowSize = sf::Vector2u(windowWidth, windowHeight);
    this->running = true;
    
    createWindow();
}

void WindowManager::createWindow()
{
    //Create Window w/ Settings
    this->window.create({this->windowSize.x, this->windowSize.y, 32}, "Sort Visualizer");
    this->window.setFramerateLimit(60);
    this->window.setVerticalSyncEnabled(false);

    //Set Window Icon
    sf::Image icon;
        icon.loadFromFile("res/smile.png");
        this->window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}