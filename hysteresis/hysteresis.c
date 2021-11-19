#include <stdio.h>

#define THRESHOLDS_MAX 4

struct Threshold {
  unsigned int mLow;
  unsigned int mHigh;
  unsigned int mLevel;
};

const struct Threshold gThresholds[THRESHOLDS_MAX] = {
    {10, 15, 1},
    {35, 40, 2},
    {60, 65, 3},
    {85, 90, 4},
};

unsigned int hysteresis(unsigned int input_percent) {
  static unsigned int discrete_level = 0;
  static unsigned int prev_input_precent = 0;

  if (input_percent >= prev_input_precent) {
    for (int thresholdIndex = 0; thresholdIndex < THRESHOLDS_MAX;
         ++thresholdIndex) {
      if (input_percent >= gThresholds[thresholdIndex].mHigh) {
        discrete_level = gThresholds[thresholdIndex].mLevel;
      }
    }
  } else {
    for (int thresholdIndex = (THRESHOLDS_MAX - 1); thresholdIndex >= 0;
         --thresholdIndex) {

      if (input_percent <= gThresholds[thresholdIndex].mLow) {
        discrete_level = gThresholds[thresholdIndex].mLevel - 1;
      }
    }
  }

  prev_input_precent = input_percent;

  return discrete_level;
}