#include <iostream>
#include "Screens/MainMenuScreen.h"

MainMenuScreen::MainMenuScreen() {
    //ctor
}

MainMenuScreen::~MainMenuScreen() {
    //dtor
}

void MainMenuScreen::loadContent() {
    confirm.push_back(sf::Keyboard::Return);
    confirm.push_back(sf::Keyboard::Space);

    sf::Texture tex1;
    Button b;
    tex1.loadFromFile("res/imgs/button_sheet.png");
    b.load(sf::Vector2f(224, 500), tex1, sf::Vector2f(0, 0), sf::Vector2f(96, 64), sf::Vector2i(2, 2));

    tex.loadFromFile("res/imgs/TitleScreen.png");
    main.load(sf::Vector2f(0,0), sf::Vector2f(640,640), tex);
    main.addButton(b);
    components.push_back(main);
}

void MainMenuScreen::unloadContent() {
    Screen::unloadContent();
}

void MainMenuScreen::update(sf::Time &delta) {
    Screen::update(delta);
    if (input.keyPressed(confirm) || components[0].getButtons()[0].isPressed())
        ScreenManager::getInstance().addScreen(new GameScreen);
}

void MainMenuScreen::render(sf::RenderWindow &window) {
    Screen::render(window);
    for (Button &b : components[0].getButtons()) {
        window.draw(b);
    }
}
