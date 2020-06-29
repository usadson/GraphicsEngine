/**
 * Copyright (C) 2020 Tristan. All Rights Reserved.
 * See the COPYING file for license information.
 */

#pragma once

class EngineCore {
public:
    [[nodiscard]] bool
    Setup() noexcept;

    [[nodiscard]] bool
    Run() noexcept;

    void
    Shutdown() noexcept;
};
