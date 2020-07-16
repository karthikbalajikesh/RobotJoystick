#ifndef CLIENT_H
#define CLIENT_H

#include "tcp.h"
#include "message.hpp"
#include "serial/SerialPort.hpp"

using namespace mn::CppLinuxSerial;
using std::vector;
using std::pair;
using std::string;

class Client:public TCP{
public:
  SerialPort serial;
  message data;
  string COMPORT;
  pair<int,int> pwm;
  string SerialData;
  Client();

  void sendToServer();
  void receiveFromServer();
  void sendOverSerial();
  void parseSerialData();
  void Update();

};
#endif
