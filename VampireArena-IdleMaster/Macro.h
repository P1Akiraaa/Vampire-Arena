#pragma once
#pragma warning (disable : 4275)
#pragma warning (disable : 4244)

#define _USE_MATH_DEFINES

// STL
#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <typeindex>
#include <typeinfo>
#include <Windows.h>

// OLD
#include <math.h>
#include <conio.h>
#include <random>
#include <cassert>

// Collections
#include <vector>
#include <set>
#include <list>
#include <queue>
#include <map>

// SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

// Defines
#define DEBUG_PATH

#ifdef DEBUG_PATH 
#define PATH __FUNCTION__
#else
#define PATH __FILE__
#endif

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define SUPER __super
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define DEBUG_INFO "(File: " + CAST(string, PATH) + " | Line: " + to_string(__LINE__) + ") "
#define FORCEINLINE __forceinline
#define INLINE inline
#define CAST(_type, _value) static_cast<_type>(_value)
#define SLEEP(_duration) sleep(_duration)
#define NO_DISCARD _NODISCARD

using namespace std;
using namespace sf;

typedef unsigned short u_short;
typedef unsigned int u_int;
typedef long long l_long;