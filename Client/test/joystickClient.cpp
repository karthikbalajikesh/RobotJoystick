#include"client.h"

using std::cout;
using std::endl;

void test(){
  Client Joystick;
  while(1){
    Joystick.Update();
  }
}

int main(){
  test();
  return 0;
}
