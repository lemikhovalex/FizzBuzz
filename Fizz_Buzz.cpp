//#include "Fizz_Buzz.h"

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include <vector>
#include <string.h>

using namespace std;


int is_char_numeral(char a)
/*
 check if a char is a numeral
 */
{
	if(
	a=='1' ||
	a=='2' ||
	a=='3' ||
	a=='4' ||
	a=='5' ||
	a=='6' ||
	a=='7' ||
	a=='8' ||
	a=='9' ||
	a=='0'
	)
	{
		return 1;
	}
	return 0;
}

int is_token_number(string str)
/*
 *is this token a number
 */
{
	int len=str.length();
	if(len==1 && str[0]=='-')
	{
		return 0;
	}
	int j=0;
	if(str[0]=='-')
	{
		j++;
	}
	for(; is_char_numeral( str[j] ) ==1 && j<len; j++)
	{
	}
	if(j==len)
	{
		return 1;
	}
	return 0;
}

int char_to_int(char a)
/*
 * convert mumeral to int
 */
{
	int out;
	if(a=='1')
	{
		out= 1;
	}
	if(a=='2')
	{
		out= 2;
	}
	if(a=='3')
	{
		out= 3;
	}
	if(a=='4')
	{
		out= 4;
	}
	if(a=='5')
	{
		out= 5;
	}
	if(a=='6')
	{
		out= 6;
	}
	if(a=='7')
	{
		out= 7;
	}
	if(a=='8')
	{
		out= 8;
	}
	if(a=='9')
	{
		out= 9;
	}
	if(a=='0')
	{
		out= 0;
	}
	out=-1;
	return out;
}

int is_5_div(string s)
/*
 * checking if nuber can be divided by 5
 */
{
	int out=0;
	if(s[s.length()-1]=='5' || s[s.length()-1]=='0')
	{
		out= 1;
	}
	out=0;
	return out;
}

int is_3_div(string str)
/*
 * checking if nuber can be divided by 3
 */
{
	int out;
	if(str=="")
	{
		out= 0;
	}
	int sum=0;
	int j=0;
	int len = str.length();
	if(str[0]=='-')//check if muber is under zero
	{
		j++;
	}
	for (; j < len; j++)
	{
		sum+=char_to_int(str[j]);
	}//so we got a sum of numerals
	if(sum%3==0)
	{
		out= 1;
	}
	out= 0;
	return out;
}


string fiz_buzz(string input)
/*
 * fizz buzzing a token
 */
{
	int is3, is5;
	if(is_token_number( input ) == 1)
	{
		is5=is_5_div( input );
		is3=is_3_div( input );
		if(is3==1)
		{
			input="fizz";
			if(is5==1)
			{
				input+="buzz";
			}
		}
		if(is5==1 && is3==0)
		{
			input="buzz";
		}
	}
	else
	{
		input= "NOT_NUMBER";
	}
	return input;
}

string total_fizz_buzz(string line)
/*
 * fizz buzzing a whole line
 */
{
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
		if(token[i]=="NOT_NUMBER")
		{
			return "NOT_NUMBER";
		}
	}
	//теперь выводим
	string out="";
	int token_counter=0;
	while(token_counter<token_amount)
	{
		out+=token[token_counter];
		if(token_counter!=token_amount-1)
		{
			out+=" ";
		}
		token_counter++;
	}
	return out;
}




