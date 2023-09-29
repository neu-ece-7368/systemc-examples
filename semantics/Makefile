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

# auto generate dependenices
#see: http://www.microhowto.info/howto/automatically_generate_makefile_dependencies.html
CPPFLAGS += -MMD -MP

# debug symbols 
CPPFLAGS += -g

# each source file is an own target and does not include other source files. 
SRCS := serial.cpp par-1.cpp par-2.cpp par-3.cpp event-1.cpp event-2.cpp event-3.cpp event-4.cpp event-5.cpp event-6.cpp event-7.cpp comm-1.cpp comm-2.cpp eventq-1.cpp eventq-2.cpp
TARGETS :=  $(SRCS:.cpp=)
OBJS := $(SRCS:.cpp=.o)


all: $(TARGETS)

# execute all targets
test: $(TARGETS)
	@for t in $(TARGETS); do echo $$t; ./$$t; done 
#	./$(TARGET)

clean:
	rm -rf $(SRCS:%.cpp=%.o) $(SRCS:%.cpp=%.d) $(TARGETS) trace.vcd

.PHONY: clean

# include generated dependencies (created upon first build)
-include $(SRCS:%.cpp=%.d)