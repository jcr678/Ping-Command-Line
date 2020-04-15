#include "tclap/CmdLine.h"
#include <tclap/SwitchArg.h>
#include <map>
#include <iostream>
#include "headerForEnum.h"
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;
#define PORT_NO 0
map<int, string> getMap(int argc, char* argv[]);

char *dns_lookup(char *addr_host, struct sockaddr_in *addr_con)
{
    //just use nslookup, for example
    //  nslookup google.com  | tail -n 2

}
char reverse_lookup(){
  //host dns_lookup
  //like host 172.217.27.206
  
  //dig -x 172.217.27.206 +short
}
int main(int argc, char* argv[]){
  struct sockaddr_in addr_con;
  char *ip_addr;
  ip_addr = dns_lookup(argv[1], &addr_con);
  cout <<  ip_addr << endl;
  return 0;
}
