#ifndef __ch5_statistics_gatherer__Vanilla3__
#define __ch5_statistics_gatherer__Vanilla3__

#include "PayOffBridge.h"

class VanillaOption
{
public:
    VanillaOption(const PayOffBridge& ThePayOff_,double Expiry);
    double OptionPayOff(double Spot) const;
    double GetExpiry() const;
    
private:
    double Expiry;
    PayOffBridge ThePayOff;
};

#endif /* defined(__ch5_statistics_gatherer__Vanilla3__) */
