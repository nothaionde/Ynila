#include "Application.h"
#include "Logger.h"

namespace Ynila {

    Application::Application()
    {
        YNILA_LOGGER_INFO("Info {}", 123);
        YNILA_LOGGER_WARN("Warn {}", 123);
        YNILA_LOGGER_ERROR("Error {}", 123);
        YNILA_LOGGER_CRITICAL("Critical {}", 123);
    }
}