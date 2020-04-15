#include "tclap/CmdLine.h"
#include <tclap/SwitchArg.h>
#include <map>
#include <iostream>
#include "headerForEnum.h"
using namespace std;
map<int, string> getMap(int argc, char* argv[]);

int main(int argc, char* argv[]){
  map<int, string> map = getMap(argc, argv);
  return 0;
}
