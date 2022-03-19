#ifndef ENTITY_H
#define ENTITY_H

#include "Equipment.hpp"
#include <string>
#include "Floor.hpp"
#include <iostream>
#include "Item.hpp"

class Floor;
class Item;
class Equipment;
struct Stats{
   int strength;//damage
   int endurance;//health
   int intelligence;//critical and magic if i ever make magic
   Stats(){
      strength=0;
      endurance=0;
      intelligence=0;
   }
   Stats(int s,int e,int i):strength(s),endurance(e),intelligence(i){
   
   }
   ~Stats(){}
};
class Entity{
   public:
     Entity();
     ~Entity();
     Entity(std::string name,int level,int x,int y,Stats stats);
     void checkForLevelUp();
     std::string statsString();
     void reduceHealth(int ammount);
     void attack(Entity *target);
     //movement
     void up(Floor *floor);
     void down(Floor *floor);
     void left(Floor *floor);
     void right(Floor *floor); 
     std::string toString();
     void equip(Item item); 
     int armour();
     int damage();
   private:
     std::string name;
     int x,y;//position in map
     int maxHealth,currentHealth;
     int level;
     int maxXp,currentXp;
     int statPoints;

     Stats stats;
     Equipment* equipment;

     void updateHealthStat();

     bool alive;

      
};
#endif
