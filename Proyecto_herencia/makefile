Compiler = g++
CFLAGS = -ggdb -Wno-deprecated

Objects = proyecto.o

exe: $(Objects)
	$(Compiler) -o $@ $^

proyecto.o: proyecto.cpp
	$(Compiler) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf test *.o
