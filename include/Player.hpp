#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.hpp"
#include "Item.hpp"

class Player{
public:
   Player();
   ~Player();

   Entity *playerEntity;
   void pickUp(Item item);
private:
   Item inventory[10][8];

};
#endif
