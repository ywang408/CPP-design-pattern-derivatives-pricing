#ifndef __ch5_statistics_gatherer__PayOff3__
#define __ch5_statistics_gatherer__PayOff3__

class PayOff
{
public:
    PayOff(){}
    
    virtual double operator()(double Spot) const = 0;
    virtual ~PayOff(){}
    virtual PayOff* clone() const = 0; // virtual copy constructor
    
private:
};


class PayOffCall: public PayOff
{
public:
    PayOffCall(double Strike_);
    
    virtual double operator()(double Spot) const;
    virtual ~PayOffCall(){}
    virtual PayOff* clone() const;
    
private:
    double Strike;
};

class PayOffPut: public PayOff
{
public:
    PayOffPut(double Strike_);
    
    virtual double operator()(double Spot) const;
    virtual ~PayOffPut(){}
    virtual PayOff* clone() const;
    
private:
    double Strike;
};


#endif /* defined(__ch5_statistics_gatherer__PayOff3__) */
