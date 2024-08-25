#include "chip.hpp"

/* CONSTRUCTOR */
Chip::Chip() {
    pos.x = 0.f;
    pos.y = 0.f;

    color = sf::Color::Transparent;

    circle.setFillColor(color);
    circle.setRadius(CHIP_DIAMETER / 2);

    placed = false;
}

// Chip::Chip(sf::Vector2f coords, sf::Color c) {
//     pos = coords;
//     color = c;

//     circle.setFillColor(color);
//     circle.setRadius(CHIP_DIAMETER / 2);
// }


/* GETTER AND SETTER */
sf::Vector2f Chip::getPos() {
    return pos;
}

int Chip::setPos(sf::Vector2f coords) {
    pos = coords;

    return 1;
}

sf::Color Chip::getColor() {
    return color;
}

void Chip::setColor(sf::Color color) {
    this->color = color;
    circle.setFillColor(color);
}

void Chip::setTexture(sf::Texture texture) {
    this->texture = texture;
    color = sf::Color::White;
    circle.setTexture(&this->texture);
    circle.setTextureRect(sf::IntRect(0, 0, CHIP_DIAMETER, CHIP_DIAMETER));
}

void Chip::place() {
    placed = true;
}

void Chip::unplace() {
    placed = false;
}

bool Chip::isPlaced() {
    return placed;
}

/* DRAW */
sf::CircleShape Chip::render() {
    circle.setPosition(pos);

    return circle;
}