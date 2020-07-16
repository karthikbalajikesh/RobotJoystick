#ifndef TCP_H
#define TCP_H


#include "message.hpp"
#include<iostream>
#include<boost/asio.hpp>
#include<string>
#include<vector>
#include<utility>

#define IOCONTEXT boost::asio::io_context
#define IPADDRESS boost::asio::ip::address
#define ENDPOINT boost::asio::ip::tcp::endpoint
#define SOCKET boost::asio::ip::tcp::socket


class TCP{
private:

public:
  // variables
  std::shared_ptr<IOCONTEXT> IO;
  std::shared_ptr<IPADDRESS> IP;
  std::shared_ptr<ENDPOINT> EP;
  std::shared_ptr<SOCKET> SOCK;


  TCP();   // Default constructor
  TCP(std::string& IP_ADDRESS, unsigned short port_number);




};
#endif
