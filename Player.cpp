#include "include/Player.hpp"

Player::Player(){
   playerEntity=new Entity("Player",1,0,0,Stats(10,10,10));
}
Player::~Player(){
   delete playerEntity;
}


