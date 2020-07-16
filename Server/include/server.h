#ifndef SERVER_H
#define SERVER_H

#include<iostream>
#include<ncurses.h>
#include"message.hpp"
#include"tcp.h"

class Server:public TCP{
public:
  message data;
  Server();
  void Update();
  void setupConnection();
  void sendMessage();
  void readMessage();
  void getPWMinput();
};

#endif
