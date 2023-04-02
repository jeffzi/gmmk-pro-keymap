BOOTMAGIC_ENABLE = yes
CONSOLE_ENABLE = false
DEFERRED_EXEC_ENABLE = yes
EXTRAKEY_ENABLE = yes
LTO_ENABLE = yes
MOUSEKEY_ENABLE = no # disable because it can break KVM switch
NKRO_ENABLE = yes
OS_DETECTION_ENABLE = yes
RGB_MATRIX_ENABLE = yes
# source: andrebait config
# The matrix scan frequency seems to be around 1820 Hz, so even sym_defer_g would perform ok,
# but the "defer" part would mean we would wait DEBOUNCE ms before sending any events.
# Using "asym_eager_defer_pk" does not seem to benefit us in anything.
# The GMMK Pro has more then enough system resources for a per-key algorithm.
# Using an "eager" algorithm leads to extremely low latency while also reducing the chances of chattering
# due to it's "post-event" debouncing (of sorts).
DEBOUNCE_TYPE = sym_eager_pk
