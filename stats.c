#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

Stats compute_statistics(const float* numberset, int setlength) {
    Stats stat;
    int index;
    float sum, current_num;

    //Init Check
    if (setlength <= 0) {
        
        stat.average = NAN;
        stat.min = NAN;
        stat.max = NAN;

        return stat;
    }

    //Initialization
    stat.average = 0;
    stat.min = +INFINITY;
    stat.max = -INFINITY;

    //Calculating the Stats
    for (index = 0; index < setlength; index++) {
        current_num = numberset[index];
        
        sum = sum + current_num;
        
        if (current_num > stat.max){
            stat.max = current_num;
        }

        if (current_num < stat.min){
            stat.min = current_num;
        }
    }

    stat.average = sum/(float)setlength;



    return stat;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats computedStats) {
    
    if (computedStats.average > maxThreshold) {
        (void) *(alerters[0]());
        (void) *(alerters[1]());
    }
}

