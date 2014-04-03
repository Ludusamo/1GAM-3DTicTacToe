#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "Screens/Screen.h"
#include "System/ScreenManager.h"
#include "Level/Level.h"
#include <SFML/Graphics.hpp>

#include "Entity/Entity.h"
#include "Entity/Mob.h"

class GameScreen : public Screen {
public:
    GameScreen();
    ~GameScreen();

    void loadContent();
    void unloadContent();
    void update(sf::Time &delta);
    void render(sf::RenderWindow &window);
protected:
private:
    int numPlayers, turn;
    Button buffer;
    std::vector<Button> buttons;
    Component main;
    Level level;

    sf::Texture tex1;
    sf::Sprite turnS, oneS, twoS;

    enum turn {P1, P2};
};

#endif // GAMESCREEN_H
