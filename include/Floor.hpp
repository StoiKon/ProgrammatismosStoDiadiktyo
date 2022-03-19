#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include "Entity.hpp"
#include <vector>
class Entity;
struct Room{
   int x,y,w,h;
   Room(int x,int y,int w,int h){
      this->x=x;
      this->y=y;
      this->w=w;
      this->h=h;
      std::cout<<"Room -> x-"<<x<<" y-"<<y<<" ";
      std::cout<<"w-"<<w<<" h"<<h<<std::endl;
   }
   Room(){
      x=-1;y=-1;w=-1;h=-1;
   }
   ~Room(){
      std::cout<<"Room "<<x<<":"<<y<<" freed"<<std::endl;
   }
};
class Floor{
  public:
    ~Floor();
    Floor();
    Floor(char *name,int *tiles,int w,int h);

    void printTiles();
    void setRooms(Room *rooms,int nr);
    int getWidth();
    int getHeight();
    Room getRoom(int index);
    int getNumberOfRooms();
    int tileCollision(int x,int y);
   
    void addEntity(Entity *e);
  private:
    char *name;
    int *tiles;
    Room *rooms;
    int nr;
    int w,h;
    std::vector<Entity> entities;
};
#endif
