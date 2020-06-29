/**
 * Copyright (C) 2020 Tristan. All Rights Reserved.
 * See the COPYING file for license information.
 */

#pragma once

#include <memory>

#include "graphics/base.hpp"

class EngineCore {
public:

    [[nodiscard]] bool
    Run() noexcept;

    [[nodiscard]] bool
    Setup() noexcept;

    void
    Shutdown() noexcept;

private:
    std::unique_ptr<GraphicsCoreBase> graphicsCore;

    [[nodiscard]] bool
    FindGraphicsCore() noexcept;
};
