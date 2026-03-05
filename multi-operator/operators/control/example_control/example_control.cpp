#include "operator_api/operator.h"

struct ExampleControl : vivid::OperatorBase {
    static constexpr const char* kName = "ExampleControl";
    static constexpr VividDomain kDomain = VIVID_DOMAIN_CONTROL;
    static constexpr bool kTimeDependent = false;

    void collect_params(std::vector<vivid::ParamBase*>& out) override { (void)out; }
    void collect_ports(std::vector<VividPortDescriptor>& out) override {
        out.push_back({"out", VIVID_PORT_CONTROL_FLOAT, VIVID_PORT_OUTPUT});
    }
    void process(const VividProcessContext* ctx) override {
        ctx->output_values[0] = 1.0f;
    }
};

VIVID_REGISTER(ExampleControl)
