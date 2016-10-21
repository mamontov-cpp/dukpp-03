#include "gccollectcheck.h"

GCCollectCheck::GCCollectCheck()
{
    
}

GCCollectCheck::~GCCollectCheck()
{
    GCCollectCheck::counter += 1;
}

void GCCollectCheck::clearCounter()
{
    GCCollectCheck::counter  = 0;    
}

int GCCollectCheck::counter = 0;
