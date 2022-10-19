#include "stats.h"
#include "math.h"
#include <stdio.h>

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    unsigned int index = 0;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    
    for (index = 0; index < setlength; index++) {
        
    }
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
