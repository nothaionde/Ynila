#include "Ynila.h"

int main()
{
    auto application = std::make_unique<Sandbox::SandboxApplication>();
    application->Run();
}
