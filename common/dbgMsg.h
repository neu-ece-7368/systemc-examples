#ifndef DBG_MSG_H
#define DBG_MSG_H

#include <systemc.h>
#include <stdio.h>
#include <string>

/// @brief print debug message in the format:
///        <now in ps>:<delta at time> <objectName> <msg>
///        0:0 b.b2.main Start
/// @param msg user message to print
void dbgMsg(std::string msg) {
    sc_object *pObj = sc_get_current_object();
    const char *pName;

    // only if there is an object (could be the main)
    if (pObj) {
        pName = pObj->name();
    } else {
        pName = "no_object";
    }
  std::printf("%4lld:%lld %s %s\n", sc_time_stamp().value(), 
     sc_get_curr_simcontext()->delta_count_at_current_time(), // sc_delta_count() is monotonically increasing
     pName, msg.c_str()  );
}

#endif