/**
 * Copyright (C) 2020 Tristan. All Rights Reserved.
 * See the COPYING file for license information.
 */

#include "engine.hpp"

#include <iostream>

#include "graphics/vulkan/core.hpp"

bool
EngineCore::Setup() noexcept {
    if (!FindGraphicsCore()) {
        std::cout << "EngineCore: No GraphicsCore candidate found.\n";
        return false;
    }

    if (!graphicsCore->Setup()) {
        std::cout << "EngineCore: GraphicsCore candidate found, but setup failed.\n";
        return false;
    }

    return true;
}

bool
EngineCore::Run() noexcept {
    return true;
}

void
EngineCore::Shutdown() noexcept {

}

bool
EngineCore::FindGraphicsCore() noexcept {
    this->graphicsCore = std::make_unique<VulkanCore>();
    if (this->graphicsCore->CheckSupport()) {
        return true;
    }

    // Check for other candidates (GL, DX, etc.)

    return false;
}
