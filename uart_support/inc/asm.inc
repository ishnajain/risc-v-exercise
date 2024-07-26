#pragma once

.macro function name
.global \name
.section .text.\name
.type \name, "function"
\name:
.endm

