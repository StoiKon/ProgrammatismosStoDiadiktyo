#include "include/Entity.hpp"
#include <iostream>
Entity::~Entity(){
   std::cout<<"Entity "<<name<<" memory cleared"<<std::endl;
}
Entity::Entity(){
   
   alive = false;
   name="Null";
   x=-1;
   y=-1;
   maxHealth=0;
   currentHealth=0;
   level=0;
   maxXp=0;
   currentXp=0;
   std::cout<<"Null Entity Created"<<std::endl;
   statPoints=0;
   equipment=new Equipment();
}

Entity::Entity(std::string name,int level,int x,int y,Stats stats){
   this->name=name;
   this->x=x;
   this->y=y;
   this->level=level;
   this->stats=stats;
   maxXp=(level*level*5)/3;
   std::cout<<"Entity "<<name<<" level "<<level<<std::endl;
   std::cout<<x<<" : "<<y<<std::endl;
   std::cout<<"Stats "<<statsString()<<std::endl;
   std::cout<<"created"<<std::endl;
   alive = true;
   statPoints=0;
   
   //diminishing returns
   maxHealth = 20 + stats.endurance * 6;
   currentHealth=maxHealth;
   
   equipment=new Equipment();
}
//
void Entity::checkForLevelUp(){
   int previousLevel =level;
   this->level+= (currentXp >= maxXp);
   currentXp -= ( currentXp >= maxXp )*maxXp;
   maxXp=(level*level*5)/3;
   if(previousLevel < level){
      std::cout<<"Entity "<<name<<" leveled up -> "<<level<<std::endl;
      updateHealthStat();
   }
}

std::string Entity::statsString(){
   return "\n strength "+std::to_string(stats.strength)+"\n endurance "+std::to_string(stats.endurance)+"\n intelligence "+std::to_string(stats.intelligence)+"\n";
}
int Entity::damage(){
      return stats.strength+equipment->dmg();
}
void Entity::reduceHealth(int amount){
   if(!alive){return;}
   amount =amount - equipment->armourf()%amount;
   currentHealth-= amount;
   if(currentHealth <=0){
      std::cout<<name<<" died";
      alive=false;
   }
}
void Entity::attack(Entity *target){
   target->reduceHealth(damage());
}
void Entity::up(Floor *floor){
   y-=(y>0 && y<floor->getHeight()-1);
}
void Entity::down(Floor *floor){
   y+=(y>0 && y<floor->getHeight()-1);
}
void Entity::left(Floor *floor){
   x-=(x>0 && x<floor->getWidth()-1);
}
void Entity::right(Floor *floor){
   x+=(x>0 && x<floor->getWidth()-1);
}
void Entity::updateHealthStat(){
   maxHealth = 20 + stats.endurance * 6;
   currentHealth=maxHealth;
}
std::string Entity::toString(){
   return name +" level "+std::to_string(level);
}
void Entity::equip(Item item){
   equipment->equip(item);
}


