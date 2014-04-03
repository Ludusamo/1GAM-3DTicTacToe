#include "Screens/GameScreen.h"

GameScreen::GameScreen() {
    //ctor
}

GameScreen::~GameScreen() {
    //dtor
}

void GameScreen::loadContent() {
    level.load();
    level.loadLevel("res/imgs/Tilesheet_A.png", "bigger_level.png");

    buttons.push_back(buffer);

    turn = P1;
    numPlayers = 2;

    sf::Texture background;
    background.loadFromFile("res/imgs/gameBackground.png");
    main.load(sf::Vector2f(0, 0), sf::Vector2f(640, 640), background);
    sf::Texture tex;
    if (!tex.loadFromFile("res/imgs/button_sheet.png")) std::cout << "Cannot load button sheet." << std::endl;
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 4; x++) {
            int xx = x * 64;
            int yy = 32 * ((y / 4) + y);

            Button b;
            b.load(sf::Vector2f(xx + 64, yy + 32), tex, sf::Vector2f(0, 64), sf::Vector2f(32, 32), sf::Vector2i(2, 1));
            main.addButton(b);
        }
    }
    Button b;
    b.load(sf::Vector2f(556, 608), tex, sf::Vector2f(0, 96), sf::Vector2f(64, 32), sf::Vector2i(2, 1));
    main.addButton(b);
    components.push_back(main);


    if (!tex1.loadFromFile("res/imgs/extra_sprites.png")) std::cout << "Cannot open extra sprites." << std::endl;
    turnS.setTexture(tex1);
    turnS.setTextureRect(sf::IntRect(0, 0, 256, 128));
    turnS.setPosition(340, 25);
    oneS.setTexture(tex1);
    oneS.setTextureRect(sf::IntRect(0, 128, 128, 128));
    oneS.setPosition(430, 150);
    twoS.setTexture(tex1);
    twoS.setTextureRect(sf::IntRect(128, 128, 128, 128));
    twoS.setPosition(410, 150);
}

void GameScreen::unloadContent() {
    level.unload();
}

void GameScreen::update(sf::Time &delta) {
    Screen::update(delta);
    level.update(delta);
    int COUNT = 0;
    if (numPlayers == 2) {
        for (Button &b : components[0].getButtons()) {
            COUNT++;
            if (COUNT == components[0].getButtons().size() && b.isPressed()) {
                ScreenManager::getInstance().addScreen(new MainMenuScreen);
                break;
            }
            if (b.isPressed() && !b.isSelected()) {
                int x = b.getBounds().left / 64;
                int y = b.getBounds().top / 32;
                level.getTilemap().changeTile(sf::Vector2f(x, y), turn + 2);
                if (turn == P1) turn = P2;
                else turn = P1;
                b.setSelected(true);
            }
        }
    }
}

void GameScreen::render(sf::RenderWindow &window) {
    Screen::render(window);
    level.render(window);
    for (Button &b : components[0].getButtons()) {
        window.draw(b);
    }
    window.draw(turnS);
    if (turn == P1) window.draw(oneS);
    else window.draw(twoS);
}
