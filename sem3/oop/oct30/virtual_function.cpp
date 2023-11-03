// virtual destructor
#include <iostream>
using namespace std;

class DTU
{
public:
    static int cws;
    virtual void project() = 0;
    virtual void evaluate() = 0;
    virtual ~DTU() {}
    DTU() {
        cws = 0;
    }
};

class IT : public DTU
{
public:
    void project()
    {
        cout << "IT Project Submitted" << endl;
        cws = 20;
    }
    void evaluate() { cout << "You score from IT Department: " << cws << endl; }
};

class Mech : public DTU
{
public:
    void project()
    {
        cout << "Mech project Submitted" << endl;
        cws = 15;
    }
    void evaluate() { cout << "You score from Mech Department: " << cws << endl; }
};

int DTU::cws = 0;

int main()
{
    DTU *stream1 = new IT;
    stream1->project();
    stream1->evaluate();
    DTU *stream2 = new Mech;
    stream2->project();
    stream2->evaluate();
    delete stream1;
    delete stream2;
    return 0;
}