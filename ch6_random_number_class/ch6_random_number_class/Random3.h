//
// Created by YOU WANG on 4/11/21.
//

#ifndef CLIONPROJECT_RANDOM3_H
#define CLIONPROJECT_RANDOM3_H

#include "Random2.h"
#include "Wrapper.h"

class BoostRandom:public RandomBase{
public:
    BoostRandom(unsigned long Dimensionality, unsigned long Seed=1);
    virtual RandomBase* clone() const;
    virtual void GetUniforms(MJArray& variates);
    virtual void Skip(unsigned long numberOfPaths);
    virtual void SetSeed(unsigned long Seed);
    virtual void Reset();
    virtual void GetGaussians(MJArray& variates);

private:
    unsigned long Seed;
};


#endif //CLIONPROJECT_RANDOM3_H
