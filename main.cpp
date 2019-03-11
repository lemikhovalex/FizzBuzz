#include "Fizz_Buzz.h"

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include <vector>
#include <string.h>

using namespace std;
int main()
{
	char input[100];
	cin.getline(input,sizeof(input));
	string line=input;
	string out=total_fizz_buzz(line);
	cout << out;
}

