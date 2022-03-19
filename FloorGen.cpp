#include "include/FloorGen.hpp"
#include <iostream>
#include <ctime>

bool roomInsideMap(Room A,int mw,int mh){
   return A.x>=0 && A.x<=mw
     && A.x + A.w <=mw && A.y >= 0 &&
     A.y + A.h <= mh && A.y <= mh;
}
bool roomCollision(Room A,Room B){
   return A.x-3 >= B.x && A.x+3 <= B.x+B.w ||
     A.y-3 >= B.y && A.y+3 <= B.y+B.h ||
   A.x-3 >= B.x && A.x+3 <= B.x+B.w &&
      A.x+A.w-3 >= B.x && A.x+A.w+3 <= B.x+B.w ||
     A.y+A.h-3 >= B.y && A.y+A.h+3 <= B.y+B.h ||
     A.y+A.h-3 >= B.y && A.y+A.h+3 <= B.y+B.h ||
     A.x-3 + A.w >= B.x && A.x + A.w+3 <= B.x+B.w ||
     A.y + A.h-3>= B.y && A.y + A.h+3 <= B.y+B.h;
}


FloorGen::FloorGen(){
   std::cout<<"Floor Generator initialized"<<std::endl;
   srand(time(NULL));
   //entity Generator
   engen=EntityGen();
}
FloorGen::~FloorGen(){
   std::cout<<"Floor Generator exited"<<std::endl;
}

Floor *FloorGen::simpleFloor(char *name,int w,int h,int nr,int level){
   std::cout<<"generating simple level"<<std::endl;
   int *tiles;
   tiles = new int[w*h];
   for(int i=0;i<w*h;i++){
      tiles[i]=0;
   }
   std::cout<<"generating rooms dimensions"<<std::endl;
   int generatedSoFar=0,tries=0;
   int collisions=0,outOfBounds=0;
   Room *rooms;
   rooms = new Room[nr];
   for(int i=0;i<nr;i++){
     std::cout<<"room "<<i<<std::endl;
      rooms[i].x=-1;//not placed
      rooms[i].y=-1;//not palced
      //setting width and hight
      rooms[i].w=5+(rand()%4);
      rooms[i].h=5+(rand()%4);
      std::cout<<rooms[i].w<<"x"<<rooms[i].h<<std::endl;
   }
   std::cout<<"choosing room locations ..."<<std::endl;
do{
      for(int i=0;i<nr;i++){
         std::cout<<"Room "<<i<<std::endl;
         tries=0;
            while(!roomInsideMap(rooms[i],w,h)){
               std::cout<<"room outside of bounds"<<std::endl;
               outOfBounds++;
               rooms[i].x=(rand()*rand())%(w - rooms[i].w);
               rooms[i].y=(rand()*rand())%(h - rooms[i].h);
               tries++;
               }
         std::cout<<"checking room collisions"<<std::endl;
         for(int j=i-1;j>=0;j--){
            if(roomCollision(rooms[i],rooms[j])){
               //std::cout<<"room collision"<<" "<<tries<<std::endl;
               tries++;
               collisions++;
               if(tries >100){
                  std::cout<<"to many collisions\n";break;} 
               while(!roomInsideMap(rooms[i],w,h)){
                  std::cout<<"room outside of bounds"<<std::endl;
                  rooms[i].x=(rand()*rand())%(w - rooms[i].w);
                  rooms[i].y=(rand()%rand())%(h - rooms[i].h);
                  tries++;
               }
                j=i-1;
            }
         }
          
          generatedSoFar++;
          std::cout<<"generated so far -> "<<generatedSoFar<<std::endl; 
      }
      //build rooms to tile array
   }while(generatedSoFar<nr && tries<300);
   std::cout<<"building rooms"<<std::endl;
   for(int i=0;i<generatedSoFar;i++){

     for(int k=rooms[i].y;k<=rooms[i].y+rooms[i].h;k++){
         for(int j=rooms[i].x;j<=rooms[i].x+rooms[i].w;j++){
            if(tiles[j+k*w]!=2)
            tiles[j+k*w]=2-(k==rooms[i].y || j==rooms[i].x || rooms[i].y+rooms[i].h==k || rooms[i].x+rooms[i].w==j); 
         }
      }
   }
   
   std::cout<<"out of bounds - "<<outOfBounds;
   std::cout<<"\n collisions - "<<collisions<<std::endl;
   //Road Generation
   std::cout<<"road Generation "<<std::endl;
   int rx,ry,sw=1;//road x road y sw=switch
   //go until you find room center
   for(int i=0; i<generatedSoFar;i++){
     std::cout<<"generating road between "<<i<<"-"<<i+1<<std::endl;
    rx = rooms[i].x+rooms[i].w/2;
    ry = rooms[i].y+rooms[i].h/2;
    while(rx != rooms[i+1].x+rooms[i+1].w/2 
        && ry != rooms[i+1].y+rooms[i+1].h/2){
      sw= sw - (sw == 1)+ (sw == 0);
      std::cout<<sw<<std::endl;
      for(int j = 0;j<10;j++){
         tiles[rx+ry*w]=2;
         if(rx<=rooms[i+1].x+rooms[i+1].w/2)
         {   rx+=(sw==1);}
         if(rx>rooms[i+1].x+rooms[i+1].w/2)
         {   rx-=(sw==1);}
         if(ry<=rooms[i+1].y+rooms[i+1].h/2)
         {   ry+=(sw==0);}
         if(ry>rooms[i+1].y+rooms[i+1].h/2)
         {   ry-=(sw==0);}
         std::cout<<rx<<"-"<<ry<<" --> "<<rooms[i+1].x+rooms[i+1].w/2<<"-"<<rooms[i+1].y+rooms[i+1].h/2<<std::endl;

      }
    }
   }
   //Entrance to next and Previous Level
   //stairs up
   Room r=rooms[(rand()%generatedSoFar)];
   int ux=r.x+r.w/2,uy=r.y+r.h/2;
   tiles[ux + uy*w]=4;
   //stairs down
   r=rooms[(rand()%generatedSoFar)];
   ux=r.x+r.w/2;uy=r.y+r.h/2;
   tiles[ux + uy*w]=6;
   
   //add room information to Floor
   Floor *floor;
   floor = new Floor(name,tiles,w,h);
   floor->setRooms(rooms,generatedSoFar);
   //floor entities generation
   int ex,ey,ne;
   for(int i=0; i<generatedSoFar;i++){
      ne=rand()%3;//up to 3 enemies per room
      for(int ni=0;ni<ne;ni++){
         //random location
         ex=rooms[i].x+1+(rand()%(rooms[i].w-1));   
         ey=rooms[i].y+1+(rand()%(rooms[i].h-1));
         floor->addEntity((engen.genThief(level,ex,ey)));
      }   
   } 
   return floor; 

}




