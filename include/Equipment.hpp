#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "Item.hpp"
class Item;
struct Equipment{
  public:
   Item *helmet;
   Item *armour;
   Item *boots;
   Item *cape;
   Item *weapon;
   Item *secondary; 
    Equipment();
   ~Equipment();
   int dmg();
   int armourf();
   void equip(Item item);
  private:


};
#endif
