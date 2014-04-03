#include "Level/Level.h"

Level::Level() {

}

Level::~Level() {
    //dtor
}

void Level::load() {
}

void Level::loadLevel(const std::string& tilesetFile, const std::string&  file) {
    sf::Image image;
    if (!image.loadFromFile("res/lvls/" + file))
        std::cout << "Cannot Load Level." << std::endl;
    width = image.getSize().x;
    height = image.getSize().y;
    name = file;

    // Loading Map
    std::vector<int> bufferV;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int i = 0; i < 256; i++) {
                if (image.getPixel(x, y) == TileData::tiles[i].getLevelColor()) {
                    tiles.push_back(TileData::tiles[i].getId());
                    if (TileData::tiles[i].isSolid()) bufferV.push_back(1);
                    else bufferV.push_back(0);
                    break;
                }
            }
        }
        colMap.push_back(bufferV);
        bufferV.clear();
    }

    if (!tmap.load(tilesetFile, sf::Vector2u(2, 1), tiles, width, height))
        std::cout << "Map could not be loaded." << std::endl;
}

void Level::saveLevel() {
    sf::Image image;
    image.create(width, height, sf::Color::Black);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image.setPixel(x, y, TileData::tiles[tiles[x + y * width]].getLevelColor());
        }
    }
    image.saveToFile("res/lvls/" + name);
}

void Level::generateLevel(const std::string& tilesetFile, int widthB, int heightB) {
    width = widthB;
    height = heightB;

    std::vector<int> bufferV;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
//            tiles.push_back(TileData::tiles[levelBuffer[x][y]].getId());
//            if (TileData::tiles[levelBuffer[x][y]].isSolid()) bufferV.push_back(1);
//            else bufferV.push_back(0);
        }
        colMap.push_back(bufferV);
        bufferV.clear();
    }

    if (!tmap.load(tilesetFile, sf::Vector2u(32, 32), tiles, width, height))
        std::cout << "Map could not be loaded." << std::endl;
}

void Level::unload() {
    tmap.unload();
}

void Level::update(sf::Time delta) {

}

void Level::render(sf::RenderWindow &window) {
    window.draw(tmap);
}

int Level::getWidth() {
    return width;
}

int Level::getHeight() {
    return height;
}
