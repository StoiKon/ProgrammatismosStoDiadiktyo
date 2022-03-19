#ifndef DUNGEON_H
#define DUNGEON_H
#include "Floor.hpp"
#include "FloorGen.hpp"
#include <string>
#include <list>
class Dungeon{
  public:
   ~Dungeon();
   Dungeon(std::string name,FloorGen *floorGen,int type,int numberOfFloors);

   Floor *getFloor(int index);
  private:
   std::string name;
   FloorGen *floorGen;
   int type;
  //simple level etc
  //0 simple level
   int numberOfFloors;
   std::list<Floor*> floors;
};

#endif
