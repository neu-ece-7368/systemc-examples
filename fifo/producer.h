#ifndef PRODUCER_H
#define PRODUCER_H

#include <systemc.h>
#include "../common/dbgMsg.h"
SC_MODULE(Producer){
  public:
     sc_fifo_out<char> out;

     SC_CTOR(Producer) {
       SC_THREAD(main);
     }

     void main() {
       char c = 'a';
       while (c != 'z') {
         dbgPrintf("write %c\n", c);
         out->write(c);
         c++;
        }
        dbgPrintf("finish\n");
     }
};

#endif
