#ifndef _ADC_H_
#define _ADC_H_


#include "main.h"

#define ADC_SAMPLES_SIZE 2000
double arr[ADC_SAMPLES_SIZE];
double max[ADC_SAMPLES_SIZE/5];

void takeADCSamples();

#endif
