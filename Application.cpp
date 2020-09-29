/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: Application sources
 */

#include <signal.h>

#include <SDL2/SDL.h>

#include "Application.hpp"

using namespace kF;
using namespace kF::Literal;

static bool Exited = false;

/**
 * CTRL + C Catch callback
 */
static void SigCallback(int)
{
    Exited = true;
}

/**
 * Public interface
 */
Application::Application(const char *name, const Version version) :
    _window(CreateBackendWindow(name)),
    _renderer(_window, version)
{
    ::signal(SIGINT, &SigCallback);
}

Application::~Application(void)
{
    if (_window)
        ::SDL_DestroyWindow(_window);
}

void Application::run(void)
{
    _running = true;
    while (!Exited && _running) {
        tick();
    }
}

void Application::tick(void)
{
    processEvents();
    onAboutToRender();
    _renderer.getDrawer().draw();
    onRendered();
}

void Application::stop(void)
{
    _running = false;
}

/**
 * Virtual protected event callbacks
 */
void Application::onAboutToRun(void)
{

}

void Application::onAboutToClose(void)
{

}

void Application::onAboutToRender(void)
{

}

void Application::onRendered(void)
{

}

/**
 * Private functions
 */
void Application::processEvents(void)
{
    ::SDL_Event event;

    while (::SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            stop();
            break;
        } else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED)
            _renderer.onViewSizeChanged();
    }
}

BackendWindow *Application::CreateBackendWindow(const char *applicationName)
{
    return ::SDL_CreateWindow(
        applicationName,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE
    );
}