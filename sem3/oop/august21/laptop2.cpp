#include <iostream>
using namespace std;

#define BASE_PRICE 50000

class Laptop
{
private:
    char model;
    float price;
    int ram;
    char graphic_card;

public:
    Laptop(char model, int ram, char graphic_card);
    void displayLaptop()
    {
        cout << "Laptop " << model << endl;
        cout << "Ram: " << ram << "bit" << endl;
        if (graphic_card == 'y')
        {
            cout << "With NextGen graphic card" << endl;
        }
        cout << "Price for laptop: " << price << "(Rs)" << endl
             << endl;
    }
};

Laptop::Laptop(char model, int ram, char graphic_card)
{
    this->model = model;
    this->ram = ram;
    this->graphic_card = graphic_card;
    this->price = BASE_PRICE + (model - 'A') * 3000 + ram * 400;
    if (graphic_card == 'y')
    {
        this->price += 35000;
    }
}

Laptop getLaptop()
{
    char model;
    int ram;
    char graphic_card;
    cout << "Enter the model for laptop (character): ";
    cin >> model;
    cout << "Enter the ram (8/16/32/64)";
    cin >> ram;
    cout << "Do you also want a graphic card? (y/n)";
    cin >> graphic_card;
    if (graphic_card >= 'A' && graphic_card <= 'Z')
    {
        graphic_card = graphic_card + 32;
    }
    Laptop lp(model, ram, graphic_card);
    return lp;
}

int main()
{
    cout << "Enter Laptop details:-" << endl;
    Laptop lp1 = getLaptop();
    cout << "\n\nYou laptop has following specificaions" << endl;
    lp1.displayLaptop();
    return 0;
}
