#ifndef TIMERS_H
#define TIMERS_H

#include <stdint.h>

typedef struct {
    volatile uint8_t *counterTop;
    volatile uint8_t *count;
    void (*timerBegin)(void);
} timerdev8_t;

typedef struct {
    union {
        volatile uint16_t *counterTop;
        struct {
            volatile uint8_t *counterTopH;
            volatile uint8_t *counterTopL;
        };
    };
    union {
        volatile uint16_t *count;
        struct {
            volatile uint8_t *countH;
            volatile uint8_t *countL;
        };
    };
    union {
        volatile uint16_t *compare;
        struct {
            volatile uint8_t *compareH;
            volatile uint8_t *compareL;
        };
    };

    void (*timerBegin)(void);
    void (*timerInit)(void);
} timerdev16_t;


#endif