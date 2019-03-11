
all: compile testing
	
compile: Fizz_Buzz.cpp main.cpp
	g++ Fizz_Buzz.cpp main.cpp -o main



testing: test1.cpp Fizz_Buzz.cpp
	g++ -o test1 test1.cpp Fizz_Buzz.cpp -lboost_unit_test_framework