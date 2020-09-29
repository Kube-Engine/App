/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: Application class of Kube framework
 */

#pragma once

#include <memory>

#include <Kube/Graphics/Renderer.hpp>

#include "SDLInitializer.hpp"

namespace kF { class Application; }

/**
 * @brief Kube Application
 *
 * This class prepares and run at a high level of abstraction, a graphical application.
 * As the Kube framework aims to be cross-platform, only a signle surface window can be instantied with it.
 */
class kF::Application
{
public:
    Application(const char *name = "Kube Application", const Version version = Version(0, 1, 0));
    Application(const Application &other) = delete;
    Application(Application &&other) = default;
    virtual ~Application(void);

    void run(void);
    void tick(void);
    void stop(void);

    [[nodiscard]] Renderer &getRenderer(void) noexcept { return _renderer; }
    [[nodiscard]] const Renderer &getRenderer(void) const noexcept { return _renderer; }

protected:
    virtual void onAboutToRun(void);
    virtual void onAboutToClose(void);
    virtual void onAboutToRender(void);
    virtual void onRendered(void);

private:
    SDLInitializer _sdlInitializer;
    BackendWindow *_window = nullptr;
    Renderer _renderer;
    bool _running = false;

    void processEvents(void);

    [[nodiscard]] static BackendWindow *CreateBackendWindow(const char *applicationName);
};