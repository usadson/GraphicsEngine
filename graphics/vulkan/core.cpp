/**
 * Copyright (C) 2020 Tristan. All Rights Reserved.
 * See the COPYING file for license information.
 */

#include "core.hpp"

#include "base/application_info.hpp"


VulkanCore::~VulkanCore() noexcept {
    Clean();
}

bool
VulkanCore::CheckSupport() noexcept {
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

void
VulkanCore::Clean() noexcept {
    vkDestroyInstance(instance, allocationCallbacks);
    glfwTerminate();
}

bool
VulkanCore::CreateInstance() noexcept {
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = ApplicationInfo::name;
    appInfo.applicationVersion = ApplicationInfo::version.vkVersion();
    appInfo.pEngineName = EngineInfo::name;
    appInfo.engineVersion = EngineInfo::version.vkVersion();
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    return vkCreateInstance(&createInfo, allocationCallbacks, &instance) == VK_SUCCESS;
}

bool
VulkanCore::Setup() noexcept {
    if (!CreateInstance()) {
        return false;
    }

    return true;
}
