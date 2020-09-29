/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: SDLInitializer
 */

#pragma once

namespace kF { class SDLInitializer; }

class kF::SDLInitializer
{
public:
    SDLInitializer(void);
    ~SDLInitializer(void);

    void quit(void);

private:
    bool _initialized = false;
};