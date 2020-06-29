/**
 * Copyright (C) 2020 Tristan. All Rights Reserved.
 * See the COPYING file for license information.
 */

#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "graphics/base.hpp"

class VulkanCore : public GraphicsCoreBase {
public:
    ~VulkanCore() noexcept;

    [[nodiscard]] bool
    CheckSupport() noexcept override;

    [[nodiscard]] virtual bool
    Setup() noexcept override;

private:
    VkAllocationCallbacks *allocationCallbacks;
    VkInstance instance;

    void
    Clean() noexcept;

    [[nodiscard]] bool
    CreateInstance() noexcept;
};
