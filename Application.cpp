/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: Application sources
 */

#include <signal.h>

#include <SDL2/SDL.h>

#include <Kube/Core/StringLiteral.hpp>

#include "Application.hpp"

using namespace kF;
using namespace kF::Literal;

static bool Exited = false;

//  CTRL + C Catch callback
static void SigCallback(int)
{
    Exited = true;
}

Application::Application(const char *name, const Version version) :
    _window(CreateBackendWindow(name, 800, 400, false)),
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
    onAboutToRun();
    while (!Exited && _running) [[likely]] {
        tick();
    }
    onAboutToClose();
    renderer().logicalDevice().waitIdle();
}

void Application::stop(void)
{
    _running = false;
}

void Application::processEvents(void)
{
    ::SDL_Event event;

    while (::SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            stop();
            break;
        } else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED)
            _renderer->dispatchViewSizeChanged();
    }
}

Graphics::BackendWindow *Application::CreateBackendWindow(const char *applicationName,
        const std::uint32_t width, const std::uint32_t height, const bool resizable)
{
    return ::SDL_CreateWindow(
        applicationName,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        static_cast<int>(width), static_cast<int>(height),
        SDL_WINDOW_VULKAN | (resizable ? SDL_WINDOW_RESIZABLE : 0x0)
    );
}