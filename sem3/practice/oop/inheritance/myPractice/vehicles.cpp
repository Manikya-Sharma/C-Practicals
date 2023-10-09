#include <iostream>
#include <string>
using namespace std;

enum STATUS
{
    RUNNING,
    STOPPED
};

const float MAX_SPEED = 120;
const float AVERAGE_SPEED = 60;

class Vehicle
{
  protected:
    float speed;
    STATUS status;

  public:
    Vehicle() { status = STOPPED; }
    void stopVehicle()
    {
        cout << "Stopping!" << endl;
        status = STOPPED;
        speed = 0;
    }
    void startVehicle()
    {
        cout << "Starting!" << endl;
        status = RUNNING;
        speed = AVERAGE_SPEED;
    }
    void speedUp()
    {
        if (status == STOPPED)
        {
            cout << "Start your vehicle first..." << endl;
        }
        cout << "SPEED UP!!!" << endl;
        speed = MAX_SPEED;
    }
    void showStatus()
    {
        cout << "Vehicle status:" << (status == STOPPED ? "STOPPED" : "RUNNING")
             << endl;
    }
};

class Car : public Vehicle
{
};
class Bus : public Vehicle
{
};

int main()
{
    Car c1;
    c1.showStatus();
    c1.startVehicle();
    c1.showStatus();
    c1.speedUp();
    c1.showStatus();
    c1.stopVehicle();
    return 0;
}