#ifndef CONSUMER_H
#define CONSUMER_H

#include <systemc.h>
#include "../common/dbgMsg.h"

SC_MODULE(Consumer){
   public:
     sc_in<uint32_t> in;

     SC_CTOR(Consumer) {
       SC_THREAD(main);
     }

     void main() {
       while (true) {
          wait(in.default_event());
          dbgPrintf("in=%u\n", (uint32_t) in);
       }
     }
};

#endif