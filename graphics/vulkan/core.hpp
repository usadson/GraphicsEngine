/**
 * Copyright (C) 2020 Tristan. All Rights Reserved.
 * See the COPYING file for license information.
 */

#pragma once

#include "graphics/base.hpp"

class VulkanCore : public GraphicsCoreBase {
public:
    [[nodiscard]] bool
    CheckSupport() override;

    [[nodiscard]] virtual bool
    Setup() override;
};
