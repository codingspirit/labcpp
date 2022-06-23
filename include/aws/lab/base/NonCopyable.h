#pragma once

namespace Aws::Lab::Base {

/**
 * @brief Helper class to disable copy.
 *
 */
class NonCopyable {
   protected:
    constexpr NonCopyable() = default;
    ~NonCopyable() = default;

    NonCopyable(const NonCopyable &) = delete;
    NonCopyable &operator=(const NonCopyable &) = delete;
};

}  // namespace Aws::Lab::Base
