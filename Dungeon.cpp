#include "include/Dungeon.hpp"
#include <iostream>
#include <algorithm>
Dungeon::~Dungeon(){
 floors.clear();
}

Dungeon::Dungeon(std::string name,FloorGen *floorGen,int type,int numberOfFloors){
   this->name=name;
   this->floorGen=floorGen;
   this->type=type;
   this->numberOfFloors = numberOfFloors;
   switch(type){
     case 0:
         floors.push_back(floorGen->simpleFloor("Floor 1",100,100,20,1));
         break;
     default:
         std::cout<<"Dungeon type does not exitst"<<std::endl;
         break;
   }
   std::cout<<"new Dungeon"<<std::endl;
}
Floor *Dungeon::getFloor(int index){
   if(index > numberOfFloors){
      std::cout<<"there is no next level"<<std::endl;
      return nullptr;
   }
   if(index >= floors.size()){
      floors.push_back(floorGen->simpleFloor("Floor 1",100,100,20,1));
     return floors.back(); 
   }
   if(index < floors.size()){
       std::list<Floor*>::iterator it = floors.begin();
       std::advance(it, index);
       return *it;

   }
   return nullptr;
}


