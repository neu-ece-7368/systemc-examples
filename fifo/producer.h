#ifndef PRODUCER_H
#define PRODUCER_H

#include <systemc.h>
SC_MODULE(Producer){
  public:
     sc_fifo_out<char> out;

     SC_CTOR(Producer) {
       SC_THREAD(main);
     }

     void main() {
       char c = 'a';
       while (c != 'z') {
         out->write(c);
         c++;
        }
     }
};

#endif
