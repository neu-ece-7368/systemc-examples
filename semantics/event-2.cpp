#include <systemc.h>
#include "../common/dbgMsg.h"

SC_MODULE(B){
   int x = 0, y = 0;
   sc_event e1,e2;
   public:
     SC_CTOR(B){
      SC_THREAD(b1);
      SC_THREAD(b2);
      SC_THREAD(b3);
     }
    void b1();
    void b2();
    void b3();
};

void B::b1() {
  dbgMsg("Start");
  x = 5; 
  e1.notify(SC_ZERO_TIME);
  dbgMsg("finish");
}

void B::b2() {
  dbgMsg("Start");
  wait(e1);
  dbgMsg("got e1");
  x= 6; 
  e2.notify(SC_ZERO_TIME);
  dbgMsg("finish");
}

void B::b3() {
  dbgMsg("Start");
  while(1) {
    wait(e1|e2);
    dbgMsg("got e1|e2, x= " 
    + std::to_string(y));
    y = y+x;
  }
}

int sc_main(int argc, char *argv[])  // cf. C++ main()
{
  B b("b");		// Elaboration (constructors)
  sc_start();
  dbgMsg("sim end. y= " + std::to_string(b.y)); 
  return 0;
}

