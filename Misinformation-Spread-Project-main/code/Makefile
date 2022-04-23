EXENAME = misinfo_spread
TEST = test

EXE_OBJ = main.o
OBJS = main.o Graph.o BFS.o Prim.o SCC.o
OBJS_TEST += $(filter-out $(EXE_OBJ), $(OBJS))
CPP_TEST = test.o catchmain.o
OBJS_TEST += $(CPP_TEST)

DEPFILE_FLAGS = -MMD -MP
WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function

CXX = clang++
CXXFLAGS = -std=c++14 -stdlib=libc++ -O2 $(WARNINGS) $(DEPFILE_FLAGS) -g -c
LD = clang++
LDFLAGS = -std=c++14 -stdlib=libc++ -lc++abi

all: $(EXENAME)

test: $(OBJS_TEST)
	$(LD) $^ $(LDFLAGS) -o $@

test.o: test.cpp catchmain.o $(filter-out $(EXE_OBJ), $(OBJS))
	$(CXX) $(CXXFLAGS) $< -o $@

catchmain.o: catchmain.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

BFS.o: BFS.cpp BFS.h Graph.o
	$(CXX) $(CXXFLAGS) $< -o $@

Prim.o: Prim.cpp Prim.h SCC.o
	$(CXX) $(CXXFLAGS) $< -o $@

SCC.o: SCC.cpp SCC.h Graph.o
	$(CXX) $(CXXFLAGS) $< -o $@

Graph.o: Graph.cpp Graph.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	-rm -f *.o *.d $(EXENAME)