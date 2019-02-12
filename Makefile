run: suppword
	./suppword 8

suppword: main.cpp main.o
	g++ main.o -o suppword

div: divide.cpp
	g++ divide.cpp -o div
	./div
	rm div

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o
