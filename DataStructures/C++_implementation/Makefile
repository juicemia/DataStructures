SRC=sources/testing.cpp

default: ${SRC}
	g++ $^ -o test

debug: ${SRC}
	g++ -g $^ -o gdb.out

clean: default 
	rm test

clean-debug: debug
	rm gdb.out
