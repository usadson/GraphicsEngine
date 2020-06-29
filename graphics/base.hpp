/**
 * Copyright (C) 2020 Tristan. All Rights Reserved.
 * See the COPYING file for license information.
 */

#pragma once

class GraphicsCoreBase {
public:
    virtual
    ~GraphicsCoreBase() noexcept = default;

    [[nodiscard]] virtual bool
    CheckSupport() = 0;

    [[nodiscard]] virtual bool
    Setup() = 0;
};
