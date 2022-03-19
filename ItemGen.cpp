#include "include/ItemGen.hpp"
#include <ctime>
ItemGen::~ItemGen(){
   std::cout<<"ItemGen freed"<<std::endl;
}

ItemGen::ItemGen(){
   srand(time(NULL));
}

Item ItemGen::genHelmet(std::string name,int tier){
  int armour = 3 +rand()%2;
  int damage = 0;
  int t=0;//type = helmet
  return Item(name,armour,damage,t);
}


Item ItemGen::genArmour(std::string name,int tier){
  int armour = 5 +rand()%2;
  int damage = 0;
  int t=1;//type = helmet
  return Item(name,armour,damage,t);
}


Item ItemGen::genBoots(std::string name,int tier){
  int armour = 1 +rand()%2;
  int damage = 0;
  int t=2;//type = helmet
  return Item(name,armour,damage,t);
}


Item ItemGen::genCape(std::string name,int tier){
  int armour = 0 +rand()%2;
  int damage = 0;
  int t=3;//type = helmet
  return Item(name,armour,damage,t);
}

Item ItemGen::genWeapon(std::string name,int tier){
  int armour = 0;
  int damage = 7+rand()%6;
  int t=4;//type = helmet
  return Item(name,armour,damage,t);
}
Item ItemGen::genShield(std::string name,int tier){
  int armour = 3 +rand()%2;
  int damage = 0;
  int t=5;//type = helmet
  return Item(name,armour,damage,t);
}
