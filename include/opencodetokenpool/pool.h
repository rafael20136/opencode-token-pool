// pool — part of opencode-token-pool.

#pragma once

#include <string>
#include <vector>

namespace opencodetokenpool {

class Pool {
public:
    explicit Pool(const std::string& config_path);

    void configure(const std::string& key, const std::string& value);
    bool run();
    bool verbose() const { return verbose_; }

private:
    std::string config_path_;
    bool verbose_ = false;
};

}  // namespace opencodetokenpool
