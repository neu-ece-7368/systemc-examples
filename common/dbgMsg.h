#ifndef DBG_MSG_H
#define DBG_MSG_H

#include <systemc.h>
#include <stdio.h>
#include <string>

#define __DEBUG__ 
#ifdef __DEBUG__
#define dbgPrintf(...)              \
	do                                \
	{                                 \
        dbgHdr();                     \
		std::printf(__VA_ARGS__); \
	} while (false)
#else
#define dbgPrintf(...) \
	do                   \
	{                    \
	} while (false)
#endif

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


/// @brief print debug header in the format:
///        <now in ps>:<delta at time> <objectName> 
///        0:0 b.b2.main 
//         no user message to print, that one would follow next
void dbgHdr(void) {
    sc_object *pObj = sc_get_current_object();
    const char *pName;

    // only if there is an object (could be the main)
    if (pObj) {
        pName = pObj->name();
    } else {
        pName = "no_object";
    }
  std::printf("%4lld:%lld %s ", sc_time_stamp().value(), 
     sc_get_curr_simcontext()->delta_count_at_current_time(), // sc_delta_count() is monotonically increasing
     pName);
}


#endif