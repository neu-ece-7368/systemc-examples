#include <systemc.h>
#include "../common/dbgMsg.h"

SC_MODULE(B){
   sc_signal<int> x;

   public:
     SC_CTOR(B){
      SC_THREAD(b1);
      SC_THREAD(b2);
      x = 0;
     }
    void b1();
    void b2();
};

void B::b1() {
  dbgMsg("Start");
  x = 5; 
  dbgMsg("finish");
}

void B::b2() {
  int y, z;
  dbgMsg("Start");
  y = x;
  wait(x.default_event());
  dbgMsg("got x");
  z = x;
  dbgMsg("finish");
}

int sc_main(int argc, char *argv[])  // cf. C++ main()
{
  B b("b");		// Elaboration (constructors)
  sc_start();
  dbgMsg("sim end. x= " + std::to_string(b.x)); 
  return 0;
}

