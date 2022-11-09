#ifndef PRODUCER_H
#define PRODUCER_H

#include <systemc.h>
#include "../common/dbgMsg.h"

SC_MODULE(Producer){
  public:
     sc_out<uint32_t> out;

     SC_CTOR(Producer) {
       SC_THREAD(main);
     }

     void main() {
       for(uint32_t val=1; val<3; val++) {
        out = val;
        dbgPrintf("pre,  out=%u, val=%u\n", (uint32_t) out, (uint32_t) val);
        wait(1,SC_NS);
        dbgPrintf("post, out=%u, val=%u\n", (uint32_t) out, (uint32_t) val);
       }
     }
};

#endif
