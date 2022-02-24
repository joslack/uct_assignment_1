driver.exe: driver.o parser.o
	g++ parser.o driver.o -o parser.exe -std=c++2a
parser.exe: parser.cpp
	g++ -c parser.cpp -o parser.o -std=c++2a
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o -std=c++2a
clean:
	rm *.o parser.exe
