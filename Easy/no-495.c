#include <stdio.h>
#include <stdlib.h>


int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int total_poision_effect_duration = 0; int interval;
    for(int i = 0; i < timeSeriesSize - 1; i++)
    {
        interval = *(timeSeries + i + 1) - *(timeSeries + i);
        total_poision_effect_duration += (interval < duration) ? interval : duration;
    }
    return total_poision_effect_duration + duration;
}



int main()
{

	int timeSeries[] = {1,4};
	int timeSeriesSize = sizeof(timeSeries) / sizeof(int);
	int duration = 2;
	printf("The total seconds of Ashe is poisioned is:%dS\n",findPoisonedDuration(timeSeries,timeSeriesSize,duration));
	return EXIT_SUCCESS;
}
