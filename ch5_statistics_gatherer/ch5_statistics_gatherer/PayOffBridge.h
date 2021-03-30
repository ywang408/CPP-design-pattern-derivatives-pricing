#ifndef __ch5_statistics_gatherer__PayOffBridge__
#define __ch5_statistics_gatherer__PayOffBridge__

#include "PayOff3.h"

class PayOffBridge
{
public:
    PayOffBridge(const PayOffBridge& original); // copy constructor
    PayOffBridge(const PayOff& innerPayOff);
    
    inline double operator()(double Spot) const;
    ~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);
    
private:
    PayOff* ThePayOffPtr;
};

inline double PayOffBridge::operator()(double Spot) const
{
    return ThePayOffPtr -> operator()(Spot); // call the method in PayOff class to get the payoff
}

#endif /* defined(__ch5_statistics_gatherer__PayOffBridge__) */
