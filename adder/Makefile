# if SYSTEMC is installed in non-standard location (and environment var set)
ifneq ($(SYSTEMC),)
    # If SystemC is manually built, must match C++std
	SYSTEMC_LIBS ?= lib64
	SYSTEMC_CSTD ?= 14
	CFLAGS += -I$(SYSTEMC)/include -std=c++$(SYSTEMC_CSTD)
	CPPFLAGS += -I$(SYSTEMC)/include -std=c++$(SYSTEMC_CSTD)
	LDFLAGS += -L$(SYSTEMC)/$(SYSTEMC_LIBS) -lsystemc
else
	# ask the system where installed
	LDFLAGS += $(shell pkg-config --libs systemc)
endif


TARGET := main
SRCS := adder.cpp testbench.cpp main.cpp
OBJS := $(SRCS:.cpp=.o)

# auto generate dependenices
#see: http://www.microhowto.info/howto/automatically_generate_makefile_dependencies.html
CPPFLAGS += -MMD -MP

# debug symbols 
CPPFLAGS += -g

#%.o: %.cpp
#	$(CXX) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $^ $(LDFLAGS) -o $@

all: $(TARGET)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(SRCS:%.cpp=%.o) $(SRCS:%.cpp=%.d) $(TARGET) trace.vcd

.PHONY: clean

# include generated dependencies (created upon first build)
-include $(SRCS:%.cpp=%.d)