#ifndef FLOORGEN_H
#define FLOORGEN_H
#include "FloorGen.hpp"
#include "Floor.hpp"
#include "EntityGen.hpp"
class FloorGen{
  public:
    FloorGen();
    ~FloorGen();
    // width height number of rooms
    Floor *simpleFloor(char *name,int w,int h,int nr,int level);
  private:
    EntityGen engen;
};

#endif
