#ifndef PRODUCER_H
#define PRODUCER_H

#include <systemc.h>
SC_MODULE(Producer){
  public:
     sc_out<uint32_t> out;

     SC_CTOR(Producer) {
       SC_THREAD(main);
     }

     void main() {
       for(uint32_t val=1; val<3; val++) {
        out = val;
        cout << "P pre,  " << sc_time_stamp() << ", out: " << out << ", val: " << val << endl;
        wait(1,SC_NS);
        cout << "P post, " << sc_time_stamp() << ", out: " << out << ", val: " << val << endl;
       }
     }
};

#endif
