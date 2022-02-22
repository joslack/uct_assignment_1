parser: driver.cpp parser.cpp
	g++ -o parser driver.cpp parser.cpp -I.

# #driver.exe: factorial.o driver.o
# 	g++ factorial.o driver.o -o driver.exe -std=c++20
# factorial.o: factorial.cpp
# 	g++ -c factorial.cpp -o factorial.o -std=c++20
# driver.o: driver.cpp
# 	g++ -c driver.cpp -o driver.o -std=c++20
# clean:
# 	rm *.o driver.exe
# #