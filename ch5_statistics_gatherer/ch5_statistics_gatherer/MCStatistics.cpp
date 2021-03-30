#include "MCStatistics.h"
#include <cmath>
using namespace std;

StatisticsMean::StatisticsMean(): RunningSum(0.0),PathsDone(0)
{
    
}

// collect one result from one path
// called every path
void StatisticsMean::DumpOneResult(double result)
{
    PathsDone++;
    RunningSum += result;
}

// called only once per simulation
vector<vector<double>> StatisticsMean::GetResultsSoFar()const
{
    vector<vector<double>> Results(1);
    
    Results[0].resize(1); // first vector length = 1
    Results[0][0]=RunningSum/PathsDone; // store mean
    
    return Results;
}

StatisticsMC* StatisticsMean::clone()const
{
    return new StatisticsMean(*this);
}

StatisticsFirst4thMoment::StatisticsFirst4thMoment():RunningSum(0.0), PathsDone(0) {}

void StatisticsFirst4thMoment::DumpOneResult(double result) {
    RunningSum += result;
    PathsDone++;
    RunningSum2 += pow(result - RunningSum/PathsDone,2);
    RunningSum3 += pow(result - RunningSum/PathsDone,3);
    RunningSum4 += pow(result - RunningSum/PathsDone,4);
}

vector<vector<double>> StatisticsFirst4thMoment::GetResultsSoFar() const {
    vector<vector<double>> Results(1);
    Results[0].resize(4); // first vector length = 4
    double mean, var, skew, kurt;
    mean = RunningSum/PathsDone;
    var = RunningSum2/PathsDone;
    skew = RunningSum3/PathsDone / pow(var, 1.5);
    kurt = RunningSum4/PathsDone / pow(var, 2);
    Results[0][0] = mean;
    Results[0][1] = var;
    Results[0][2] = skew;
    Results[0][3] = kurt;
    return Results;
}

StatisticsMC * StatisticsFirst4thMoment::clone() const {
    return new StatisticsFirst4thMoment(*this);
}

StatisticsVaR::StatisticsVaR() {
    PathDone = 0;
    VaR.push_back(1000000);
}

void StatisticsVaR::DumpOneResult(double result) {
    PathDone++;
    unsigned long n;
    n = ceil(0.2*PathDone);
    if (VaR.size()< n){
        VaR.push_back(result);
    }
    else if (VaR.back() > result){
        VaR[VaR.size()-1] = result;
    }
    sort(VaR.begin(), VaR.end());
}

vector<vector<double>>StatisticsVaR::GetResultsSoFar() const {
    vector<vector<double>> Results(1);

    Results[0].resize(1); // first vector length = 1
    Results[0][0]=VaR.back(); // store value at risk

    return Results;
}

StatisticsMC * StatisticsVaR::clone() const {
    return new StatisticsVaR(*this);
}
