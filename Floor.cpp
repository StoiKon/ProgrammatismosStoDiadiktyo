#include "include/Floor.hpp"

Floor::~Floor(){
   if(tiles != nullptr){
      delete[] tiles;
   }
   if(rooms !=nullptr){
     // delete rooms;
   }
   if(!entities.empty()){
      entities.clear();
   }
}
Floor::Floor(){
   name = "Null Floor ";
   tiles = nullptr;
   w=0;
   h=0;
}
Floor::Floor(char *name,int * tiles,int w,int h):name(name),tiles(tiles),w(w),h(h){
  std::cout<<"Floor "<<name<<" w: "<<w<<" h: "<<h<<" created"<<std::endl;
  rooms=nullptr;
}
void Floor::printTiles(){
  std::cout<<"printing Floor - "<<name<<std::endl; 
  if(tiles == nullptr){
     std::cout<<"error null Floor"<<std::endl;
     return;}
  for(int j=0;j<h;j++){
      for(int i=0;i<w;i++){
         //std::cout<<tiles[i+j*w];
         switch(tiles[i+j*w]){
           case 1:
             std::cout<<"#";break;
           case 2:
             std::cout<<" ";break;
           case 0:
             std::cout<<"'";break;
           case 4:
             std::cout<<"U";break;
           case 6:
             std::cout<<"D";break;
         }

      
      }
      std::cout<<"\n"; 
  }
}
void Floor::setRooms(Room *rooms,int nr){
   this->rooms=rooms;
   this->nr=nr;
}
int Floor::getWidth(){return w;}
int Floor::getHeight(){return h;}
Room Floor::getRoom(int index){
   if(rooms == nullptr){
     std::cout<<"rooms null"<<std::endl; 
     return Room();
   }
   if(index>nr){
      std::cout<<"index out of bounds"<<std::endl;
      return Room();
   }else{
      return rooms[index];
   } 
}
int Floor::getNumberOfRooms(){
   return nr;
}
int Floor::tileCollision(int x,int y){
   return (tiles[x +y*w]%2);
}
void Floor::addEntity(Entity *e){
  std::cout<<"adding entity"<<e->toString()<<std::endl; 
  entities.push_back(*e);

}
