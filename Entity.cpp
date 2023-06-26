


#include "Entity.hpp"

Entity::Entity(const std::string& name) : name(name) {}

std::string Entity::getName() const {
    return name;
}

void Entity::setName(const std::string& newName) {
    name = newName;
}
