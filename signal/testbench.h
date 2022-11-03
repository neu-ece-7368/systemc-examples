#ifndef TESTBENCH_H
#define TESTBENCH_H

// file testbench.h
#include <systemc.h>
#include "producer.h"
#include "consumer.h"

SC_MODULE(Testbench){
   public:
     sc_signal<uint32_t> mySignal;
     Producer   prod;
     Consumer   cons;

     SC_CTOR(Testbench): prod("prod"), cons("cons") {
       prod.out(mySignal);
       cons.in(mySignal);
     }
};

#endif