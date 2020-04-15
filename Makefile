# compiler
CXX = g++
# pre processor flags
CPPFLAGS = -Iinclude
# compiler flags
CXXFLAGS = -Wall
# objects
SRCS = getMap.cc mainProgram.cc
# excecutable
EXEC = a.out

OBJS = $(SRCS:cc=o)

.PHONY: all clean

all: $(EXEC)
clean:
	rm -f $(OBJS) $(EXEC)
# Pattern for .d files.
%.d:%.cc
	@echo Updating .d Dependency File
	@set -e; rm -f $@; \
	$(CXX) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

#  This is a rule to link the files.  Pretty standard
$(EXEC): $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(CPPFLAGS) $(CXXFLAGS)
