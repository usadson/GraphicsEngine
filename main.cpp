/**
 * Copyright (C) 2020 Tristan. All Rights Reserved.
 * See the COPYING file for license information.
 */

#include <iostream>

#include <cstdlib>

#include "engine.hpp"

int
main() {
    EngineCore engine;

    if (!engine.Setup()) {
        std::cerr << "Main: Setup failed!\n";
        return EXIT_FAILURE;
    }

    bool status = engine.Run();
    engine.Shutdown();

    return status ? EXIT_SUCCESS : EXIT_FAILURE;
}
