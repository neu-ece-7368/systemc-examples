#include <systemc.h>
#include "../common/dbgMsg.h"


SC_MODULE(B){
  int x; 
  SC_CTOR(B){SC_THREAD(main);}
  void b1();
  void b2();

  void main() {
    b1();
    b2();
  }
};

void B::b1() {
  dbgMsg("start");
  x=5;
  dbgMsg("finish");
}
void B::b2() {
  dbgMsg("start");
  x=6;
  dbgMsg("finish");
}


int sc_main(int argc, char *argv[])  // cf. C++ main()
{
  B b("b");		// Elaboration (constructors)
  sc_start();
  std::string msg = "sim end. x=" + std::to_string(b.x);
  dbgMsg(msg);
  return 0;
}

