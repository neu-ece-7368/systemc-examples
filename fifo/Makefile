
ifneq ($(SYSTEMC),)
# If SystemC is manually built, must match C++std
	SYSTEMC_LIBS ?= lib64
	SYSTEMC_CSTD ?= 14
	CFLAGS += -I$(SYSTEMC)/include -std=c++$(SYSTEMC_CSTD)
	LDFLAGS += -L$(SYSTEMC)/$(SYSTEMC_LIBS) -lsystemc
else
	LDFLAGS += $(shell pkg-config --libs systemc)
endif

TARGET := main
SRCS := main.cpp
OBJS := $(SRCS:.cpp=.o)

CFLAGS += -g

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $^ $(LDFLAGS) -o $@

all: $(TARGET)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -rf *.o $(TARGET) trace.vcd

.PHONY: clean
