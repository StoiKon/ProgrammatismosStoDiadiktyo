#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include "Entity.hpp"
class Entity;
class Item{
  public:
    Item(std::string n,int a,int d,int t);
    Item();
    ~Item();
    std::string toString();
    int arm();
    int dmg();
    int getType();
    std::string getName();
    std::string typeStr();
    virtual void effect(Entity target);
  private:
    int armour;
    int damage;
    std::string name;
    int type;
    int x,y;
    // 0 helmet
    // 1 armour
    // 2 boots
    // 3 cape
    // 4 weapon
    // 5 shield/secondary

};



#endif
