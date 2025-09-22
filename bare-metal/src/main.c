#include <string.h>

extern unsigned int _sbss, _ebss, _sidata, _sdata, _edata;

void __attribute__((noreturn)) call_start_cpu0() {
    memset(&_sbss, 0, (&_ebss - &_sbss) * sizeof(_sbss));
    memmove(&_sdata, &_sidata, (&_edata - &_sdata) * sizeof(_sdata));

    main();
}

static volatile int a = 0;

int main(void) {
    while (1) {
        ++a;
    }
    return 0;
}
