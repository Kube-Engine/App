/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: Application class of Kube framework
 */

#pragma once

#include <memory>

#include <Kube/Core/Hash.hpp>
#include <Kube/Graphics/Renderer.hpp>
#include <Kube/ECS/Registry.hpp>

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
    /** @brief Construct the application */
    Application(const char *name = "Kube Application", const Version version = Version(0, 1, 0));

    /** @brief Move constructor */
    Application(Application &&other) = default;

    /** @brief Destroy the application */
    virtual ~Application(void);

    /** @brief Run the application in blocking mode */
    void run(void);

    /** @brief Tick the application */
    void tick(void);

    /** @brief Stop the application */
    void stop(void);

    /** @brief Get renderer */
    [[nodiscard]] Graphics::Renderer &renderer(void) noexcept { return *_renderer; }
    [[nodiscard]] const Graphics::Renderer &renderer(void) const noexcept { return *_renderer; }

protected:
    /** @brief Virtual callback when application is about to run */
    virtual void onAboutToRun(void) {}

    /** @brief Virtual callback when application is about to close */
    virtual void onAboutToClose(void) {}

    /** @brief Virtual callback when application is rendering a frame */
    virtual void onRender(void) {}

    /** @brief Virtual callback when application frame is rendered (but still not presented) */
    virtual void onRendered(void) {}

private:
    [[no_unique_address]] SDLInitializer _sdlInitializer;
    Graphics::BackendWindow *_window = nullptr;
    Graphics::Renderer::GlobalInstance _renderer;
    bool _running = false;

    /** @brief Process application events */
    void processEvents(void);

    /** @brief Create a backend window */
    [[nodiscard]] static Graphics::BackendWindow *CreateBackendWindow(const char *applicationName,
        const std::uint32_t width, const std::uint32_t height, const bool resizable);
};

#include "Application.ipp"