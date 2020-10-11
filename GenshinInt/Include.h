#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdint.h>
#include <Psapi.h>
#include <stdlib.h>

typedef uint64_t QWORD;

using namespace std;

#pragma warning( disable : 6387) //Warning	'_Param_(4)' could be '0':  this does not adhere to the specification for the function 'VirtualProtect'
