#ifndef HANDLER_H
#define HANDLER_H
#include "Floor.hpp"
#include "Player.hpp"
#include "Entity.hpp"
class Handler{
  public:
   Handler();
   ~Handler();
  
  private:
   Player *player;
   Level *Currentlevel;
   bool inWorldMap;






};
#endif
