#ifndef YNILA_LOGGER_H
#define YNILA_LOGGER_H

#include "spdlog/spdlog.h"
#include "spdlog/spdlog.h"

namespace Ynila {

    class Logger
    {

    };
}

#define YNILA_LOGGER_INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define YNILA_LOGGER_WARN(...) SPDLOG_WARN(__VA_ARGS__)
#define YNILA_LOGGER_CRITICAL(...) SPDLOG_CRITICAL(__VA_ARGS__)
#define YNILA_LOGGER_ERROR(...) SPDLOG_ERROR(__VA_ARGS__)

#endif //YNILA_LOGGER_H
