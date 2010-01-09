// Author: yi.wang.2005@gmail.com (Yi Wang)

#include "check_log.h"

void GenerateSegmentationFault() {
  static char* kSegmentFaultCauser = "Used to cause segmentation fault";
  *(char*)((unsigned long)kSegmentFaultCauser << 5) = '\0';
}

