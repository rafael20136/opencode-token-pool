// main.cpp — entry point. Wires config and subsystems together.

#include "opencodetokenpool/settings.h"
#include "opencodetokenpool/pool.h"
#include "opencodetokenpool/rotate.h"
#include "opencodetokenpool/inject.h"
#include "opencodetokenpool/cli.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    opencodetokenpool::Settings settings = opencodetokenpool::Settings::load_default();
    opencodetokenpool::Pool pool(settings.store_path);
    opencodetokenpool::Rotate rotate(settings.store_path);
    opencodetokenpool::Inject inject(settings.store_path);
    opencodetokenpool::Cli cli(settings.store_path);
    std::fprintf(stderr, "[opencode-token-pool] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
