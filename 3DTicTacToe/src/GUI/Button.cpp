#include "GUI/Button.h"

Button::Button()
{
    //ctor
}

Button::~Button()
{
    //dtor
}

void Button::load(sf::Vector2f pos, const sf::Texture& tex, sf::Vector2f texCoord, sf::Vector2f texDimensions, sf::Vector2i scale) {
    this->pos = pos;
    this->tex = tex;
    this->texCoord = texCoord;
    this->texDimensions = texDimensions;
    selected = false;
    change = 1;

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(4);
    vertices[0].position = sf::Vector2f(pos.x, pos.y);
    vertices[1].position = sf::Vector2f(pos.x + (scale.x * texDimensions.x), pos.y);
    vertices[2].position = sf::Vector2f(pos.x + (scale.x * texDimensions.x), pos.y + (scale.y * texDimensions.y));
    vertices[3].position = sf::Vector2f(pos.x, pos.y + (scale.y * texDimensions.y));
    vertices[0].texCoords = sf::Vector2f(texCoord.x, texCoord.y);
    vertices[1].texCoords = sf::Vector2f(texCoord.x + texDimensions.x, texCoord.y);
    vertices[2].texCoords = sf::Vector2f(texCoord.x + texDimensions.x, texCoord.y + texDimensions.y);
    vertices[3].texCoords = sf::Vector2f(texCoord.x, texCoord.y + texDimensions.y);

    bounds.left = pos.x;
    bounds.top = pos.y;
    bounds.width = scale.x * texDimensions.x;
    bounds.height = scale.y * texDimensions.y;
}

void Button::unload() {
    Entity::unload();
}

void Button::update(sf::Vector2i &p) {
    if (bounds.contains(p.x, p.y)) {
        change = 1;
        highlight(change);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            pressed = true;
        }
    } else {
        change = 0;
        highlight(change);
        pressed = false;
    }
}

void Button::highlight(int change) {
    vertices[0].texCoords = sf::Vector2f(texCoord.x + (change * texDimensions.x), texCoord.y);
    vertices[1].texCoords = sf::Vector2f(texCoord.x + ((change + 1) * texDimensions.x), texCoord.y);
    vertices[2].texCoords = sf::Vector2f(texCoord.x + ((change + 1) * texDimensions.x), texCoord.y + texDimensions.y);
    vertices[3].texCoords = sf::Vector2f(texCoord.x + (change * texDimensions.x), texCoord.y + texDimensions.y);
}
