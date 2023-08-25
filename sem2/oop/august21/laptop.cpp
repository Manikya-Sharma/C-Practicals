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
    void getData();
    void display();
    float retPrice()
    {
        return price;
    }
    char retModel()
    {
        return model;
    }
    int retRam()
    {
        return ram;
    }
    char retGraphicCard()
    {
        return graphic_card;
    }
};

void Laptop::display()
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

void Laptop::getData()
{
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
    cout << "Enter the price: ";
    cin >> price;
}

float resell(char model, int ram, char graphic_card, float price=BASE_PRICE)
{
    float new_price = price/50 + (model - 'A') * 30 + ram * 4;
    if (graphic_card == 'y')
    {
        new_price += 3500;
    }
    return new_price;
}

int main()
{
    Laptop lp;
    lp.getData();
    lp.display();

    float price = lp.retPrice();
    char model = lp.retModel();
    int ram = lp.retRam();
    char graphic_card = lp.retGraphicCard();

    cout
        << "If you want to resell this laptop, it will have price of " << resell(model, ram, graphic_card, price) << "Rs." << endl;

    return 0;
}
