/**
 * Copyright (C) 2020 Tristan. All Rights Reserved.
 * See the COPYING file for license information.
 */

#include <iostream>

#include <cstdlib>

#include "base/application_info.hpp"
#include "engine.hpp"

int
main() {
    EngineCore engine;

    std::cout << "Running " << ApplicationInfo::name << " v" << ApplicationInfo::version << '\n';
    std::cout << "Using " << EngineInfo::name << " v" << EngineInfo::version << '\n';

    if (!engine.Setup()) {
        std::cerr << "Main: Setup failed!\n";
        return EXIT_FAILURE;
    }

    bool status = engine.Run();
    engine.Shutdown();

    return status ? EXIT_SUCCESS : EXIT_FAILURE;
}
