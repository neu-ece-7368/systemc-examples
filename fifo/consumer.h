#include <systemc.h>

SC_MODULE(Consumer){
   public:
     sc_fifo_in<char> in;

     SC_CTOR(Consumer) {
       SC_THREAD(main);
     }

     void main() {
       char c;

       while (true) {
         in->read(c);
         cout << c;
       }
     }
};
