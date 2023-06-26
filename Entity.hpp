#ifndef Entity_hpp
#define Entity_hpp

#include <string>

class Entity {
protected:
    std::string name;

public:
    Entity(const std::string& name);
    virtual ~Entity() = default;

    std::string getName() const;
    void setName(const std::string& newName);
};

#endif /* Entity_hpp */
