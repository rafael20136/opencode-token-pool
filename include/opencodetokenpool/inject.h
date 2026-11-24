// inject — part of opencode-token-pool.

#pragma once

#include <string>
#include <vector>

namespace opencodetokenpool {

class Inject {
public:
    explicit Inject(const std::string& config_path);

    void configure(const std::string& key, const std::string& value);
    bool run();
    bool verbose() const { return verbose_; }

private:
    std::string config_path_;
    bool verbose_ = false;
};

}  // namespace opencodetokenpool
