#ifndef ADDER_H
#define ADDER_H

// file adder.h
#include <systemc.h>

SC_MODULE(Adder)
{
  sc_in<int> x;
  sc_in<int> y;
  sc_out<int> s;

  void add();
  SC_CTOR(Adder)
  {
    SC_METHOD(add);
    sensitive << x << y;
  }
};

#endif