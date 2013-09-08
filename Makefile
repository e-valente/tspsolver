all: clean bestfirst.o hillclimbing.o main.o compile

compile:
	g++ main.o hillclimbing.o bestfirst.o -o t2
	
main.o:
	g++ -c main.cpp 

bestfirst.o:
	g++ -c bestfirst.cpp 
	
hillclimbing.o:
	g++ -c hillclimbing.cpp 
clean:
	@find -name '*~' | xargs rm -rf {}
	@find -name '*.o' | xargs rm -rf {}

targz:
	tar cvzf t2-ia-emanuel.tar.gz *.cpp *.h in.txt Makefile
