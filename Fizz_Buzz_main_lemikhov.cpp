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
	//cin.getline(input,sizeof(input));
	string line=input;
	line="33";
	int len=line.length();
	cout <<len;
	cout << "= length \n";
	vector<string> token;// начинаем токенизировать
	stringstream ss(line);
	string temp;
	while( getline(ss,temp,' ') )
	{
        token.push_back(temp);
    }
	int token_amount=token.size();// разбили на токены
	for(int i=0; i<token_amount; i++)// редактируем токены
	{
		token[i]=fiz_buzz( token[i] );		
	}
	//теперь выводим
	string out="";
	int token_counter=0;
	while(token_counter<token_amount)
	{
		out+=token[token_counter];
		out+=" ";
		token_counter++;
	}
	cout << out;
	return 0;
}
