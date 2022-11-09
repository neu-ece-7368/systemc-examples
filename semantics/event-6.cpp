#include <systemc.h>
#include "../common/dbgMsg.h"

SC_MODULE(B){
   int x = 0;
   sc_event e;
   public:
     SC_CTOR(B){
      SC_THREAD(b1);
      SC_THREAD(b2);
     }
    void b1();
    void b2();
};

void B::b1() {
  dbgMsg("Start");
  x = 5; 
  e.notify(SC_ZERO_TIME);
  dbgMsg("finish");
}

void B::b2() {
  dbgMsg("Start");
  wait(10,SC_PS);
  dbgMsg("wait done");
  wait(e);
  dbgMsg("got e");
  x= 6; 
  dbgMsg("finish");
}

int sc_main(int argc, char *argv[])  // cf. C++ main()
{
  B b("b");		// Elaboration (constructors)
  sc_start();
  dbgMsg("sim end. x= " + std::to_string(b.x)); 
  return 0;
}

