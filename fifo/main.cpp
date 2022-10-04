#include <systemc.h>
#include "testbench.h"

// file main.cpp
int sc_main(int argc, char *argv[])  // cf. C++ main()
{
  Testbench tb("tb");		// Elaboration (constructors)
  sc_start();
  cout << "Simulation finished" << endl;

  return 0;
}
