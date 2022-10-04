# top level make 
DIRS = adder fifo

# just recurse into sub cirectories and make target there
all clean test: 
	@for d in $(DIRS); do $(MAKE) $(MFLAGS) -C $$d $@; done 