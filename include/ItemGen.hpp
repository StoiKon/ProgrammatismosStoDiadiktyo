#ifndef ITEMGEN_H
#define ITEMGEN_H
#include "Item.hpp"
#include <iostream>
#include <string>
class ItemGen{
public:
   ItemGen();
   ~ItemGen();
   
   Item genHelmet(std::string name,int tier);
   Item genArmour(std::string name,int tier);
   Item genBoots(std::string name,int tier);
   Item genCape(std::string name,int tier);
   Item genWeapon(std::string name,int tier);
   Item genShield(std::string name,int tier);
   
private:

};

#endif
