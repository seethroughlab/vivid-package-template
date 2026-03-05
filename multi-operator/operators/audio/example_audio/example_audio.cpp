#include "operator_api/operator.h"

struct ExampleAudio : vivid::OperatorBase {
    static constexpr const char* kName = "ExampleAudio";
    static constexpr VividDomain kDomain = VIVID_DOMAIN_AUDIO;
    static constexpr bool kTimeDependent = true;

    void collect_params(std::vector<vivid::ParamBase*>& out) override { (void)out; }
    void collect_ports(std::vector<VividPortDescriptor>& out) override {
        out.push_back({"audio_out", VIVID_PORT_AUDIO, VIVID_PORT_OUTPUT});
    }
    void process(const VividProcessContext* ctx) override {
        if (!ctx->audio_out || !ctx->audio_out[0]) return;
        for (uint32_t i = 0; i < ctx->sample_frames; ++i) {
            ctx->audio_out[0][i] = 0.0f;
            if (ctx->audio_out_channels > 1 && ctx->audio_out[1]) ctx->audio_out[1][i] = 0.0f;
        }
    }
};

VIVID_REGISTER(ExampleAudio)
