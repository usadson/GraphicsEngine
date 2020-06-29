/**
 * Copyright (C) 2020 Tristan. All Rights Reserved.
 * See the COPYING file for license information.
 */

#include "core.hpp"

bool
VulkanCore::CheckSupport() {
    if (!glfwInit()) {
        return false;
    }

    // This function will check if Vulkan is supported, at least for compute.
    // This doesn't cover graphics, but Setup() will handle that.
    if (!glfwVulkanSupported()) {
        return false;
    }

    return true;
}

bool
VulkanCore::Setup() {
    return true;
}
