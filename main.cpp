#include <iostream>
#include "include/Floor.hpp"
#include "include/FloorGen.hpp"
#include "include/Entity.hpp"
int main(){
   int *tiles;
   tiles = new int[30];
   for(int i=0;i<30;i++){
      tiles[i]=0;
   }
   Floor test = Floor("test",tiles,5,6);
   test.printTiles();
   FloorGen *fg;
   fg = new FloorGen();
   Floor *fp;
   fp = fg->simpleFloor("genTest",60,60,30,1);
   fp->printTiles();
   Entity player=Entity("player",1,0,0,Stats(10,10,10));
   Entity wolf=Entity("wolf",1,0,0,Stats(5,5,5));
   player.attack(&wolf);
   delete fp;
   delete fg; 

   return 0;
}
