#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class WindowManager
{
public:
    WindowManager();
    WindowManager(int windowWidth, int windowHeight);
    ~WindowManager();
    void terminateWindow();

    void clearWindow();
    void displayWindow();
    void render(const sf::Drawable &drawable);

    void setTitle(std::string title);

    bool isRunning();
    sf::RenderWindow *getRenderWindow();
    sf::Vector2u getSize();

private:
    void setupWindow(int windowWidth, int windowHeight);
    void createWindow();

    sf::RenderWindow window;
    sf::Vector2u windowSize;
    
    sf::Text title;
    sf::Font font;
    bool running;
};