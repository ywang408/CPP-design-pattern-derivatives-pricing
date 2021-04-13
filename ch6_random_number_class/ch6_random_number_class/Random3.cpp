//
// Created by YOU WANG on 4/11/21.
//

#include "Random3.h"
#include "boost/random.hpp"
#include "boost/random/random_device.hpp"

BoostRandom::BoostRandom(unsigned long Dimensionality, unsigned long Seed_):
RandomBase(Dimensionality), Seed(Seed_){}

RandomBase* BoostRandom::clone() const {
    return new BoostRandom(*this);
}

void BoostRandom::GetUniforms(MJArray &variates) {
    boost :: random_device dev;
    boost :: mt19937 rng(dev);
    boost :: uniform_01<> std;
//    boost :: variate_generator <boost :: mt19937 &, boost :: uniform_01<>> unstd ( rng , std);
    for (unsigned long j=0; j < GetDimensionality(); j++){
        variates[j] = std(rng);
    }
}

void BoostRandom::Skip(unsigned long numberOfPaths)
{
    MJArray tmp(GetDimensionality());
    for (unsigned long j=0; j < numberOfPaths; j++)
        GetUniforms(tmp);
}

void BoostRandom::SetSeed(unsigned long Seed_) {
    Seed = Seed_;
}

void BoostRandom::Reset() {
    Seed = 1;
}

void BoostRandom::GetGaussians(MJArray &variates) {
    boost :: random_device dev;
    boost :: mt19937 rng(dev);
    boost :: normal_distribution<> std(0,1);
    for (unsigned long j=0; j < GetDimensionality(); j++){
        variates[j] = std(rng);
    }
}