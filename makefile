Project1: ALUSimulator.o ALUSimulator_Main.o RegisterFile_01.o 
	g++ -std=c++11 -g -Wall ALUSimulator.o ALUSimulator_Main.o RegisterFile_01.o -o Project1
ALUSimulator_Main.o: ALUSimulator_Main.c
	g++ -std=c++11 -g -Wall -c ALUSimulator_Main.c
ALUSimulator.o: ALUSimulator.cpp
	g++ -std=c++11 -g -Wall -c ALUSimulator.cpp
RegisterFile_01.o: RegisterFile_01.c
	g++ -std=c++11 -g -Wall -c RegisterFile_01.c
clean:
	rm *.o Project1