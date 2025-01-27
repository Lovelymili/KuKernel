#include <stdint.h>
#include "interrupt.h"

uint16_t original_ds, kernel_ds;

void isr_handler(void) {
    uint64_t r0, r1, r2, r3, r4, r5, r6, r7;

    // ARM64 汇编：保存寄存器（r0-r7）
    asm volatile (
        "stp x0, x1, [sp, #-16]! \n"  // 将 x0 和 x1 存储到栈中
        "stp x2, x3, [sp, #-16]! \n"  // 将 x2 和 x3 存储到栈中
        "stp x4, x5, [sp, #-16]! \n"  // 将 x4 和 x5 存储到栈中
        "stp x6, x7, [sp, #-16]!"     // 将 x6 和 x7 存储到栈中
        : "=r" (r0), "=r" (r1), "=r" (r2), "=r" (r3), "=r" (r4), "=r" (r5), "=r" (r6), "=r" (r7)
        );

    // ARM 中没有类似 x86 的数据段寄存器，通常不需要操作 ds、es 等
    // 如果需要，可以保存和恢复其他状态寄存器或程序状态寄存器 CPSR

    // 加载内核数据段选择子（这里我们可以跳过，因为 ARM 不使用段寄存器）
    kernel_ds = 0x10;  // 内核数据段选择子（在 ARM 中没用）

    // 你可以在这里进行其他硬件相关操作，比如更改模式或中断状态等
    // 例如，ARM 通常使用控制寄存器来切换权限级别，设置中断屏蔽位等
}

void irs_exit(void) {
    // 恢复寄存器的值
    asm volatile (
        "ldp x0, x1, [sp], #16 \n"  // 恢复 x0 和 x1
        "ldp x2, x3, [sp], #16 \n"  // 恢复 x2 和 x3
        "ldp x4, x5, [sp], #16 \n"  // 恢复 x4 和 x5
        "ldp x6, x7, [sp], #16"     // 恢复 x6 和 x7
        );
}
