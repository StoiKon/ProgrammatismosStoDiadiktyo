#ifndef ENTITYGEN_H
#define ENTITYGEN_H
#include "Entity.hpp"
#include <iostream>
#include "ItemGen.hpp"
class EntityGen{
public:
   EntityGen();
   ~EntityGen();
   
   Entity *genThief(int level,int x,int y);
private:
   ItemGen *itemGen;
};


#endif
