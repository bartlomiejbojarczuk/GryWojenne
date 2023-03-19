#ifndef CPOCISK_H
#define CPOCISK_H


class CPocisk
{
public:
    CPocisk();
    virtual ~CPocisk();
    virtual int obrazenia(){};
protected:
    int sila_razenia;
    bool niewypal;


};

#endif // CPOCISK_H
