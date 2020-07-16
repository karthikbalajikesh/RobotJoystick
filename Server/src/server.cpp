#include "server.h"
using namespace std;
Server::Server():TCP(){
  data = message();
  initscr();
  noecho();
	keypad(stdscr,TRUE);

}

void Server::getPWMinput(){
  char ch = getch();
  if ((int)ch == 3){
    cout<<"UP\n";
    if(data.pwmleft == 250 || data.pwmright == 250){

    } else{
      data.pwmleft += 10;
      data.pwmright += 10;
    }

  } else if ((int)ch == 2){
      cout<<"DOWN\n";
      if(data.pwmleft == 0 || data.pwmright == 0){

      } else{
        data.pwmleft -= 10;
        data.pwmright -= 10;
      }
  } else if ((int)ch == 4){
      cout<<"LEFT\n";
        data.pwmleft -= 10;
        if(data.pwmleft < 0){
          data.pwmleft = 0;
          data.pwmright += 10;
          if (data.pwmright >250){
            data.pwmright = 250;
          }
        }
  } else if ((int)ch == 5){
      cout<<"RIGHT\n";
        data.pwmright -= 10;
        if(data.pwmright < 0){
          data.pwmright = 0;
          data.pwmleft += 10;
          if (data.pwmleft >250){
            data.pwmleft = 250;
          }
        }
  }
}

void Server::setupConnection(){
  Acceptor->listen(BACKLOG_SIZE);
  SOCK = std::make_shared<SOCKET>(*IO);
  Acceptor->accept(*SOCK);
}

void Server::readMessage(){
  return;
}

void Server::sendMessage(){
  boost::asio::streambuf buf;
    std::ostream OutputStream(&buf);
    boost::archive::text_oarchive OutputArchive(OutputStream);
    // Perform Serialization
    OutputArchive & data;
    const size_t header = buf.size();
    vector<boost::asio::const_buffer> buffers;
    buffers.push_back(boost::asio::const_buffer(&header,
                        sizeof(header)));
    buffers.push_back(buf.data());
    boost::asio::write(*SOCK,buffers);

    SOCK->shutdown(boost::asio::socket_base::shutdown_send);
}

void Server::Update(){
  setupConnection();
  getPWMinput();
  //cout<<data.pwmleft<<"\t"<<data.pwmright<<endl;
  readMessage();
  sendMessage();
}
