#include "include/EntityGen.hpp"
#include <ctime>
#include "include/ItemGen.hpp"
EntityGen::EntityGen(){
   srand(time(NULL));
   itemGen =new ItemGen();
}
EntityGen::~EntityGen(){
   std::cout<<"Entity Gen memory freed"<<std::endl;
}
//simplest mob
Entity *EntityGen::genThief(int level,int x,int y){
  Stats stats =Stats(5+level/3,5+level/3,6+level/3); 
  std::cout<<"New Thief generated"<<std::endl;
  Entity *en =new Entity("Thief",level,x,y,stats);
  if(rand()%10 < 5)
      en->equip(itemGen->genArmour("thief armour",0));
  if(rand()%10 < 7)
      en->equip(itemGen->genWeapon("iron sword",0));
  if(rand()%10 <2)   
      en->equip(itemGen->genShield("shield",0));
  return en;}
