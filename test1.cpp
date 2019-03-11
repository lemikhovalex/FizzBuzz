#include "Fizz_Buzz.h"

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include <vector>
#include <string.h>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE PulseTest
#include <boost/test/unit_test.hpp>
#include <exception>
#include <unistd.h>

using namespace std;


BOOST_AUTO_TEST_CASE( lol )
{
    BOOST_CHECK( total_fizz_buzz("1 7")=="1 7" );
}


