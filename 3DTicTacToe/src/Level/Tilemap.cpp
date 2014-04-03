#include "Level/Tilemap.h"

Tilemap::Tilemap() {
    //ctor
}

Tilemap::~Tilemap() {
    //dtor
}

bool Tilemap::load(const std::string& tilesetFile, sf::Vector2u tileScale, const std::vector<int> tiles, unsigned int width, unsigned int height) {
    if (!tileset.loadFromFile(tilesetFile))
        return false;

    this->tileScale = tileScale;
    this->width = width;
    this->height = height;

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            int tilenum = tiles[x + y * width];

            int xx = tilenum % (tileset.getSize().x / TILE_SIZE);
            int yy = tilenum / (tileset.getSize().x / TILE_SIZE);

            sf::Vertex* quad = &m_vertices[(x + y * width) * 4];

            quad[0].position = sf::Vector2f(x * TILE_SIZE * tileScale.x, y * TILE_SIZE * tileScale.y);
            quad[1].position = sf::Vector2f((x + 1) * TILE_SIZE * tileScale.x, y * TILE_SIZE * tileScale.y);
            quad[2].position = sf::Vector2f((x + 1) * TILE_SIZE * tileScale.x, (y + 1) * TILE_SIZE * tileScale.y);
            quad[3].position = sf::Vector2f(x * TILE_SIZE * tileScale.x, (y + 1) * TILE_SIZE * tileScale.y);

            quad[0].texCoords = sf::Vector2f(xx * TILE_SIZE, yy * TILE_SIZE);
            quad[1].texCoords = sf::Vector2f((xx + 1) * TILE_SIZE, yy * TILE_SIZE);
            quad[2].texCoords = sf::Vector2f((xx + 1) * TILE_SIZE, (yy + 1) * TILE_SIZE);
            quad[3].texCoords = sf::Vector2f(xx * TILE_SIZE, (yy + 1) * TILE_SIZE);
        }
    }
    return true;
}

bool Tilemap::generateLevel() {
    return true;
}

bool Tilemap::unload() {
    m_vertices.clear();
    return true;
}

void Tilemap::changeTile(sf::Vector2f tilePos, int id) {
    int x = tilePos.x;
    int y = tilePos.y;
    sf::Vertex* quad = &m_vertices[(x + y * width) * 4];

    int xx = id % (tileset.getSize().x / TILE_SIZE);
    int yy = id / (tileset.getSize().x / TILE_SIZE);
    quad[0].texCoords = sf::Vector2f(xx * TILE_SIZE, yy * TILE_SIZE);
    quad[1].texCoords = sf::Vector2f((xx + 1) * TILE_SIZE, yy * TILE_SIZE);
    quad[2].texCoords = sf::Vector2f((xx + 1) * TILE_SIZE, (yy + 1) * TILE_SIZE);
    quad[3].texCoords = sf::Vector2f(xx * TILE_SIZE, (yy + 1) * TILE_SIZE);
}
