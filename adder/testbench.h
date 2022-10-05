#ifndef TESTBENCH_H
#define TESTBENCH_H

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
  // initializer -- name all children
  : uut("uut"), ch_x("ch_x"), ch_y("ch_y"), ch_s("ch_s")		
  {
    SC_THREAD(stim);		// without sensitivity
    SC_METHOD(check);
    sensitive << ch_s;		// sensitivity for check
    uut.x(ch_x);		// port x of uut bound to ch_x
    uut.y(ch_y);		// port y of uut bound to ch_y
    uut.s(ch_s);		// port s of uut bound to ch_s

    // create VCD trace file
    pTracer = sc_create_vcd_trace_file("trace");
    // register signals to be traced (and their names)
    sc_trace(pTracer, ch_x, "ch_x");
    sc_trace(pTracer, ch_y, "ch_y");
    sc_trace(pTracer, ch_s, "ch_s");

  }
  ~Testbench() {
    // close VCD file to flush writing
    sc_close_vcd_trace_file(pTracer);
  }
};

#endif