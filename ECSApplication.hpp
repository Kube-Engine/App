/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: ECS Application
 */

#pragma once

#include "Application.hpp"

namespace kF
{
    class ECSApplication;
}

class kF::ECSApplication : public Application
{
public:
    /** @brief Virtual destructor */
    virtual ~ECSApplication(void) override = default;

    /** @brief Virtual callback when application is about to run */
    virtual void onAboutToRun(void) {}

    /** @brief Virtual callback when application is about to close */
    virtual void onAboutToClose(void) {}

    /** @brief Virtual callback when application is rendering a frame */
    virtual void onRender(void) {}

    /** @brief Virtual callback when application frame is rendered (but still not presented) */
    virtual void onRendered(void) {}

private:
    // Core::Vector<HashedName, std::unique_ptr<ECS::Registry> _registries {};
};