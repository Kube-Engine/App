/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: SDLInitializer
 */

#include "SDLInitializer.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

using namespace kF;

SDLInitializer::SDLInitializer(void)
{
    ::SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    _initialized = true;
}

SDLInitializer::~SDLInitializer(void)
{
    quit();
}

void SDLInitializer::quit(void)
{
    if (_initialized)
        ::SDL_Quit();
    _initialized = false;
}
