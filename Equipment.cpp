#include "include/Equipment.hpp"

Equipment::Equipment(){
  helmet=NULL;
  armour=NULL;
  cape=NULL;
  weapon=NULL;
  secondary=NULL;
  boots=NULL;
}
Equipment::~Equipment(){
   
}
int Equipment::dmg(){
   int d=0;
   if(weapon!=NULL){
      d+=weapon->dmg();
   }
   if(secondary!=NULL){
      d+=secondary->dmg();
   }
   return d;
}

int Equipment::armourf(){
   int a=0;
   if(helmet !=NULL)
     a+=helmet->arm();
   if(armour!=NULL)
     a+=armour->arm();
   if(helmet !=NULL)
     a+=cape->arm();
   if(secondary!=NULL)
     a+=secondary->arm();
   if(boots !=NULL)
     a+=boots->arm();
}
void Equipment::equip(Item item){
   switch(item.getType()){
      case 0:
        helmet = &item;
        break;
      case 1:
        armour = &item;
        break;
      case 2:
        boots=&item;
        break;
      case 3:
        cape=&item;
        break;
      case 4:
        weapon = &item;
        break;
      case 5:
        secondary = &item;
        break;
   }
}
