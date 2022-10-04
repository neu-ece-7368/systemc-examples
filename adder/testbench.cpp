// file testbench.cpp
#include "testbench.h"

void Testbench::stim()  // SC_THREAD
{
  wait(10, SC_NS);      // wait for 10 ns
  ch_x = 3; ch_y = 4;   // first stimulus
  wait(10, SC_NS);      // wait for 10 ns
  ch_x = 5; ch_y = 0;   // second stimulus
  wait(10, SC_NS);      // wait (no sensitivity!)
}

void Testbench::check() // SC_METHOD
{
  cout << ch_x << ch_y << ch_s << endl;  // debug output
  if( ch_s != ch_x+ch_y ) sc_stop();     // stop simulation
  else cout << "-> OK" << endl;
}
