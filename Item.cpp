#include "include/Item.hpp"
std::string Item::typeStr(){
   switch(type){
     case 0:
       
       return "helmet";
     case 1:
       
       return "armour";
     case 2:
       
       return "boots";
     case 3:
       
       return "cape";
     case 4:
       
       return "weapon";
     case 5:
       
       return "shield";
     default:
       return "null";
   }
}
std::string Item::toString(){
   return name+" armour: "+std::to_string(armour)+" damage: "+std::to_string(damage)+" type: "+typeStr();
}

Item::Item(std::string n,int a,int d,int t):name(n),armour(a),damage(d),type(t){
   std::cout<<"new Item ->"<<toString()<<std::endl;
   x=0;y=0;
}
int Item::arm(){
   return armour;
}
int Item::dmg(){
   return damage;
}
std::string Item::getName(){
   return name;
}
Item::~Item(){
   std::cout<<toString()<<" freed";
}
void Item::effect(Entity target){
   return;
}
int Item::getType(){
   return type;
}
Item::Item(){
   name="empty";
   armour=0;
   damage=0;
   type=-1;
   x=0;
   y=0;
}
