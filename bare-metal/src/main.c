#include <string.h>

extern unsigned int _sbss, _ebss, _sidata, _sdata, _edata;

static volatile int a = 0;
int main(void) {
    // Increment a variable.
    while (1) {
        ++a;
    }
    return 0;
}

// Startup logic; this is the application entry point.
void __attribute__((noreturn)) call_start_cpu0() {
    // Clear BSS.
    memset(&_sbss, 0, (&_ebss - &_sbss) * sizeof(_sbss));
    // Copy initialized data.
    memmove(&_sdata, &_sidata, (&_edata - &_sdata) * sizeof(_sdata));

    // Done, branch to main
    main();
    // (Should never be reached)
    while (1) {
    }
}
