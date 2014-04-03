#ifndef BUTTON_H
#define BUTTON_H

#include "SFML/Graphics.hpp"
#include "Entity/Entity.h"

class Button : public Entity
{
    public:
        Button();
        ~Button();

        void load(sf::Vector2f pos, const sf::Texture& tex, sf::Vector2f texCoord, sf::Vector2f texDimensions, sf::Vector2i scale);
        void unload();
        void update(sf::Vector2i &p);
        bool isPressed() {
            return pressed;
        }
        void setSelected(bool x) {
            selected = x;
        }
        bool isSelected() {
            return selected;
        }
        sf::FloatRect getBounds() {
            return bounds;
        }
        enum State { SAME, HIGHLIGHTED };
    protected:
    void highlight(int change);
    sf::Vector2f pos, texCoord, texDimensions;
    sf::FloatRect bounds;
    int change;
    bool pressed, selected;
    private:

    std::string msg;
};

#endif // BUTTON_H
