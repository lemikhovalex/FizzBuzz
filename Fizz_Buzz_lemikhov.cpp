#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include <vector>
#include <string.h>


using namespace std;

int is_char_number(char a)
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
	for(; is_char_number( str[j] ) ==1 && j<len; j++)
	{
	}
	if(j==len)
	{
		return 1;
	}
	return 0;
}

int char_to_int(char a)
{
	if(a=='1')
	{
		return 1;
	}
	if(a=='2')
	{
		return 2;
	}
	if(a=='3')
	{
		return 3;
	}
	if(a=='4')
	{
		return 4;
	}
	if(a=='5')
	{
		return 5;
	}
	if(a=='6')
	{
		return 6;
	}
	if(a=='7')
	{
		return 7;
	}
	if(a=='8')
	{
		return 8;
	}
	if(a=='9')
	{
		return 9;
	}
	if(a=='0')
	{
		return 0;
	}
	return 0;
}

int is_5_div(string s)
{
	if(s[s.length()-1]=='5' || s[s.length()-1]=='0')
	{
		return 1;
	}
	return 0;
}

int is_3_div(string str)
{
	if(str=="")
	{
		return 0;
	}
	cout <<str;
	cout<<"string for check\n";
	int sum=0;
	int j=0;
	int len = str.length();
	if(str[0]=='-')
	{
		j++;
	}
	for (; j < len; j++)
	{
		sum+=char_to_int(str[j]);
	}
	if(sum%3==0)
	{
		return 1;
	}
	return 0;
}

string create_mul_space(int amount)
{
	string out="";
	for(int i=0;i<amount; i++)
	{
		out+=" ";
	}
	return out;
}

string fiz_buzz(string input)
{
	int is3, is5;
	if(is_token_number( input ) == 1)
	{// теперь там число, начинаем редактировать
		//cout << "lol /n";
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
	return input;
}

int main()
{
	char input[100];
	cin.getline(input,sizeof(input));
	string line=input;
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
		token[i]=fiz_buzz(token[i]);		
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
