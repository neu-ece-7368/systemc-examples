# top level make 
DIRS = adder fifo temporal_decoupling

# just recurse into sub cirectories and make target there
all clean test: 
	@for d in $(DIRS); do $(MAKE) $(MFLAGS) -C $$d $@; done 