#ifndef __ch5_statistics_gatherer__MCStatisitcs__
#define __ch5_statistics_gatherer__MCStatisitcs__

#include <vector>

class StatisticsMC
{
public:
    StatisticsMC(){}
    
    virtual void DumpOneResult(double result)=0; // a pure virtual function
    virtual std::vector<std::vector<double>> GetResultsSoFar()const=0;
    virtual StatisticsMC* clone()const=0;// possibility of virtual copy construction
    virtual ~StatisticsMC(){}//virtual destructor

private:
};


/*
 inherited from StatisticsMC, return mean of simulation
 */
class StatisticsMean:public StatisticsMC
{
public:
    StatisticsMean();
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar()const;
    virtual StatisticsMC* clone() const;
    
private:
    double RunningSum;
    unsigned long PathsDone;
};

class StatisticsFirst4thMoment: public StatisticsMC{
public:
    StatisticsFirst4thMoment();
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar()const;
    virtual StatisticsMC* clone() const;
private:
    double RunningSum;
    double RunningSum2;
    double RunningSum3;
    double RunningSum4;
    unsigned long PathsDone;
};

class StatisticsVaR: public StatisticsMC{
public:
    StatisticsVaR();
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar()const;
    virtual StatisticsMC* clone() const;
private:
    unsigned long PathDone;
    std::vector<double> VaR;
};
#endif /* defined(__ch5_statistics_gatherer__MCStatisitcs__) */
