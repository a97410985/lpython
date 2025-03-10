#ifndef LIBASR_PASS_FLIP_SIGN_H
#define LIBASR_PASS_FLIP_SIGN_H

#include <libasr/asr.h>
#include <libasr/utils.h>

namespace LFortran {

    void pass_replace_flip_sign(Allocator &al, ASR::TranslationUnit_t &unit,
                                const LCompilers::PassOptions& pass_options);

} // namespace LFortran

#endif // LIBASR_PASS_FLIP_SIGN_H
