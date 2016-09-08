//************************************************
// drawable.cpp
//************************************************

//Include SFML dependencies
#include <SFML/Graphics.hpp>

//Include dependencies
#include "entity.h"
#include "entitymanager.h"

Entity::Entity() : Entity::Entity(0, 0) {
    x_ = 0;
    y_ = 0;
    mouse_  = NULL;
    window_ = NULL;
    entitymanager_ = NULL;
}

Entity::Entity(int x, int y) {
    sprite.setPosition(x, y);
}

sf::Sprite Entity::get_sprite(void) {
    return sprite;
}

void Entity::set_window(sf::RenderWindow* window) {
    window_ = window;
}

void Entity::set_mouse(sf::Mouse* mouse) {
    mouse_ = mouse;
}

void Entity::set_entitymanager(EntityManager* entitymanager) {
    entitymanager_ = entitymanager;
}

void Entity::set_id(int id) {
    id_ = id;
}

int Entity::get_id(void) {
    return id_;
}

bool Entity::is_character(void) { return false; }
