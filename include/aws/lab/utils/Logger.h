#pragma once

#include "spdlog/spdlog.h"

namespace Aws::Lab::Utils {
#define LOG_DEBUG spdlog::debug
#define LOG_INFO spdlog::info
#define LOG_ERROR spdlog::error
}  // namespace Aws::Lab::Utils
