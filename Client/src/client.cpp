#include "client.h"

Client::Client():TCP(),COMPORT("/dev/ttyACM0"){
  //serial = SerialPort(COMPORT,BaudRate::B_115200);
  data = message();
  //serial.Open();
}

void Client::sendToServer(){

  // no message

  SOCK->shutdown(boost::asio::socket_base::shutdown_send);
}

void Client::receiveFromServer(){
  size_t header;
  boost::asio::read(*SOCK,
      boost::asio::buffer( &header, sizeof(header)));

  // Read the Body
  boost::asio::streambuf buf;
  boost::asio::read(*SOCK,buf.prepare(header));
  buf.commit(header);
  // Deserialization
  std::istream InputStream(&buf);
  boost::archive::text_iarchive InputArchive(InputStream);
  InputArchive & data;

}

void Client::parseSerialData(){
  pwm = std::make_pair(data.pwmleft,data.pwmright);
  string temp;
  temp = std::to_string(pwm.first);
  // perform padding
  if(temp.length()<3){
    if(temp.length()==1){
      SerialData = "00";
      SerialData.append(temp);
    } else if(temp.length()==2){
      SerialData ="0";
      SerialData.append(temp);
    }
  } else{
      SerialData = temp;
  }

  temp = std::to_string(pwm.second);
  if(temp.length()<3){
    if(temp.length()==1){
      SerialData.append("00");
      SerialData.append(temp);
    } else if(temp.length()==2){
      SerialData.append("0");
      SerialData.append(temp);
    }
  } else{
      SerialData.append(temp);
  }
}

void Client::sendOverSerial(){

  serial.Write(SerialData);
}

void Client::Update(){
  SOCK->connect(*EP);
  sendToServer();
  receiveFromServer();
  SOCK->close();
  parseSerialData();
  //sendOverSerial();
  std::cout<<data.pwmleft<<"\t"<<data.pwmright<<std::endl;
}
