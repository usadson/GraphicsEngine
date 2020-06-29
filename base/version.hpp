/**
 * Copyright (C) 2020 Tristan. All Rights Reserved.
 * See the COPYING file for license information.
 */

#pragma once

#include <ostream>

struct Version {
    uint32_t major;
    uint32_t minor;
    uint32_t patch;

    #ifdef VK_MAKE_VERSION
    [[nodiscard]] inline constexpr uint32_t
    vkVersion() const noexcept {
        return VK_MAKE_VERSION(major, minor, patch);
    }
    #endif
};

inline std::ostream &
operator<<(std::ostream &stream, const Version &version) {
    return stream << version.major << '.' << version.minor << '.' << version.patch;
}
