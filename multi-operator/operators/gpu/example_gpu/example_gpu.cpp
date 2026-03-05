#include "operator_api/operator.h"

struct ExampleGpu : vivid::OperatorBase {
    static constexpr const char* kName = "ExampleGpu";
    static constexpr VividDomain kDomain = VIVID_DOMAIN_GPU;
    static constexpr bool kTimeDependent = false;

    void collect_params(std::vector<vivid::ParamBase*>& out) override { (void)out; }
    void collect_ports(std::vector<VividPortDescriptor>& out) override {
        out.push_back({"tex", VIVID_PORT_TEXTURE, VIVID_PORT_OUTPUT});
    }
    void process(const VividProcessContext* ctx) override {
        (void)ctx;
    }
};

VIVID_REGISTER(ExampleGpu)
