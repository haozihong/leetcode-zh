CC = g++
ARGS = -std=c++2a -g
OBJS = leet_cpp.o leet_cpp_tools.o leet_cpp_inputs.cpp

leet_cpp : $(OBJS)
	$(CC) $(ARGS) -o $@ $(OBJS)
leet_cpp_tools.o: leet_cpp_tools.cpp leet_cpp_tools.h
	$(CC) $(ARGS) -c $(subst .o,.cpp,$@)
leet_cpp.o: leet_cpp.cpp leet_cpp_tools.h
	$(CC) $(ARGS) -c $(subst .o,.cpp,$@)

.PHONY : clean
clean :
	-del leet_cpp.exe $(subst .cpp,.o,$(OBJS))