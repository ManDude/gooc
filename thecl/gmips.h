/*
 * Redistribution and use in source and binary forms, with
 * or without modification, are permitted provided that the
 * following conditions are met:
 *
 * 1. Redistributions of source code must retain this list
 *    of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce this
 *    list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */
#ifndef GMIPS_H_
#define GMIPS_H_

#include <config.h>
#include <stdint.h>

typedef struct {
PACK_BEGIN
    union {
        struct {
            uint32_t addr:26;
            uint32_t opcode:6;
        } j;
        struct {
            uint32_t imm:16;
            uint32_t rt:5;
            uint32_t rs:5;
            uint32_t opcode:6;
        } i;
        struct {
            uint32_t funct:6;
            uint32_t shamt:5;
            uint32_t rd:5;
            uint32_t rt:5;
            uint32_t rs:5;
            uint32_t opcode:6;
        } r;
    };
PACK_END
} PACK_ATTRIBUTE mips_ins_t;

typedef struct {
    const char* name;
    const char fmt; /* R, I, J */
    const char* ops[6];
} mips_ins_fmt_t;

typedef enum {
    MREG_STATUS_RESERVED,
    MREG_STATUS_IN_USE,
    MREG_STATUS_FREE,
    MREG_STATUS_USED
} mips_reg_status;

typedef struct {
    int index;
    const char* name;
    mips_reg_status status;
    struct thecl_param_t* saved_param;
    struct expression_t* saved_expr;
} mips_reg_t;

typedef struct {
    mips_reg_t regs[32];
} mips_reg_block_t;

mips_reg_block_t* mips_reg_block_new(void);

#endif
