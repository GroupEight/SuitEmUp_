// stdafx.h//

// : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently

#pragma once

#include <SDKDDKVer.h>

#include <stdio.h>
#include <tchar.h>

#pragma warning(disable_4099)
#define SFML_STATIC
#if defined(_DEBUG)
#pragma comment(lib, "sfml-window-s-d.lib")
#pragma comment(lib, "sfml-graphics-s-d.lib")
#pragma comment(lib, "sfml-system-s-d.lib")
#pragma comment(lib, "sfml-audio-s-d.lib")
#else
#pragma comment(lib, "sfml-window-s.lib")
#pragma comment(lib, "sfml-graphics-s.lib")
#pragma comment(lib, "sfml-system-s.lib")
#pragma comment(lib, "sfml-audio-s.lib")
#endif

#pragma comment(lib, "Box2D.lib")

/*#if defined(_DEBUG)
#pragma comment(lib, "sfml-window-s-d12.lib")
#pragma comment(lib, "sfml-graphics-s-d12.lib")
#pragma comment(lib, "sfml-system-s-d12.lib")
#pragma comment(lib, "sfml-audio-s-d12.lib")
#else
#pragma comment(lib, "sfml-window-s12.lib")
#pragma comment(lib, "sfml-graphics-s12.lib")
#pragma comment(lib, "sfml-system-s12.lib")
#pragma comment(lib, "sfml-audio-s12.lib")
#endif*/

#include <iostream>

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>

#include <Box2D/Box2D.h>

#include "Box2D\Dynamics\b2World.h"