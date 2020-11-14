/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: Application
 */

inline void kF::Application::tick(void)
{
    processEvents();
    if (_renderer->commandDispatcher().tryAcquireNextFrame()) {
        onRender();
        _renderer->commandDispatcher().presentFrame();
    }
    onRendered();
}
