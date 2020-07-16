#include"server.h"

void testServer(){
  Server Joystick;
  while(1){
      Joystick.Update();
  }

}

int main(){
  testServer();
  return 0;
}
