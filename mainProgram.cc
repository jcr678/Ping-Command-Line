#include "tclap/CmdLine.h"
#include <tclap/SwitchArg.h>
#include <map>
#include <iostream>
#include "headerForEnum.h"
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
map<int, string> getMap(int argc, char* argv[]);

void
write_data (FILE * stream)
{
  int i;
  for (i = 0; i < 100; i++)
    fprintf (stream, "%d\n", i);
  if (ferror (stream))
    {
      fprintf (stderr, "Output to stream failed.\n");
      exit (1);
    }
}
string dns_lookup(const char *address)
{    std::stringstream ss;
     ss << "dig +short " << address;
     //use popen
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(ss.str().c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
     result.erase(std::remove(result.begin(), result.end(), '\n'), result.end());
     return result;

}
string reverse_dns_lookup(const char *address){
  std::stringstream ss;
  ss << "dig -x " << address<< " +short";
  //cout << ss.str() << endl;
  char buffer[128];
  std::string result = "";
  FILE* pipe = popen(ss.str().c_str(), "r");
  if (!pipe) throw std::runtime_error("popen() failed!");
  try {
      while (fgets(buffer, sizeof buffer, pipe) != NULL) {
          result += buffer;
      }
  } catch (...) {
      pclose(pipe);
      throw;
  }
  pclose(pipe);
  //only get first returned value, if we need more just return result.
  stringstream ssin(result);
  ssin >> result;
  return result;
}
int main(int argc, char* argv[]){
  string dns = dns_lookup(argv[1]);
  cout  << dns  << endl;
  string rev_dns = reverse_dns_lookup(dns.c_str());
  cout  << rev_dns  << endl;
  return 0;
}
