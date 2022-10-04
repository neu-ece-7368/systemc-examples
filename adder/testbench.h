// file testbench.h
#include <systemc.h>
#include "adder.h"

SC_MODULE(Testbench)
{ 						// top level; no ports
  sc_signal<int> ch_x, ch_y, ch_s; 	// channels
  Adder uut;				// Adder instance
  sc_trace_file* pTracer;

  void stim();				// stimuli process
  void check();			// checking process

  SC_CTOR(Testbench)           	// constructor
  : uut("uut"), ch_x("ch_x"), ch_y("aDifferentName"), ch_s("ch_s")		// initializer list
  {
    SC_THREAD(stim);		// without sensitivity
    SC_METHOD(check);
    sensitive << ch_s;		// sensitivity for check
    uut.x(ch_x);		// port x of uut bound to ch_x
    uut.y(ch_y);		// port y of uut bound to ch_y
    uut.s(ch_s);		// port s of uut bound to ch_s

    pTracer = sc_create_vcd_trace_file("trace");
    sc_trace(pTracer, ch_x, "signal");
    sc_trace(pTracer, ch_y, "signal");
    sc_trace(pTracer, ch_s, "signal");

  }
  ~Testbench() {
    sc_close_vcd_trace_file(pTracer);
  }
};
