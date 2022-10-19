#include<stdio.h>
#include "math.h"

typedef struct {
    float average;
    float min;
    float max;
} Stats;

Stats compute_statistics(const float* numberset, int setlength);

typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats computedStats);

extern int emailAlertCallCount;
extern int ledAlertCallCount;
