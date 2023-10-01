#include<bits/stdc++.h>
using namespace std;
#define BASE_PRICE 50000

class laptop_details{
    private:
        string brand;
        int price;
        int model;
        int storage;
        string processor;
        // private constructor
        laptop_details(string brand, int model, int storage, string processor): brand(brand), model(model), storage(storage), processor(processor){

            price = BASE_PRICE + 3*model + 2*storage;
            if (brand == "Dell")
            {
                price += 5000;
            }
            else if (brand == "HP")
            {
                price += 3000;
            }
        }
    public:
        static laptop_details new_laptop()
        {
            string brand; int model; int storage; string processor;
            cout << "Enter the brand";
            cin >> brand;
            cout << "Enter the model";
            cin>> model;
            cout << "Enter the storage";
            cin >> storage;
            cout << "Enter the processor";
            cin >> processor;
            laptop_details new_laptop(brand, model, storage, processor);
            return new_laptop;
        }
        void display_data();
};


void laptop_details::display_data(){
    cout << "Laptop with model : "<< model << "\n";
    cout << "Laptop with brand : "<< brand << "\n";
    cout << "Laptop with price : "<< price << "\n";
    cout << "Storage : "<< storage << "\n";
    cout << "Processor : "<< processor << "\n";
}
   
int main(){
    laptop_details l1 = laptop_details::new_laptop();
    l1.display_data();

    return 0;
}

