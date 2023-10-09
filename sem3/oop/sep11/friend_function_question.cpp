#include <iostream>

using namespace std;

class Marksndancer;

class Eastside
{
    int kidsFurniture;
    int totalFurniture;
    float assets;
    float averageProductCost;
    friend void merger(Marksndancer, Eastside);
    friend void newStore(Marksndancer, Eastside);
    friend Marksndancer;

public:
    void transferKidsFurniture(Marksndancer md);

    Eastside(int kidsFurniture, int totalFurniture, float assets,
             float averageProductCost)
        : kidsFurniture(kidsFurniture), totalFurniture(totalFurniture),
          assets(assets), averageProductCost(averageProductCost)
    {}
};

class Marksndancer
{
    int productsInKids;
    int productsInMen;
    int productsInWomen;
    float assets;
    float averageProductCost;
    friend void merger(Marksndancer, Eastside);
    friend void newStore(Marksndancer, Eastside);
    friend void Eastside::transferKidsFurniture(Marksndancer);

    void transferClothesToEastside(Eastside es)
    {
        cout << "Transferring products to Eastside" << endl;
        es.totalFurniture += (productsInKids + productsInMen + productsInWomen);
        cout << "Eastside now has " << es.totalFurniture << " products" << endl;
        es.averageProductCost += 0.1 * es.averageProductCost;
        averageProductCost += 0.1 * averageProductCost;
        cout << "Average product cost in Eastside is now "
             << es.averageProductCost << endl;
        cout << "Average product cost in Marksndancer is now "
             << averageProductCost << endl;
    }

public:
    Marksndancer(int productsInKids, int productsInMen, int productsInWomen,
                 float assets, float averageProductCost)
        : productsInKids(productsInKids), productsInMen(productsInMen),
          productsInWomen(productsInWomen), assets(assets),
          averageProductCost(averageProductCost)
    {}
};

void Eastside::transferKidsFurniture(Marksndancer md)
{
    cout << "Transferring " << kidsFurniture << " to Marksndancer" << endl;
    md.productsInKids += kidsFurniture;
    cout << "Now Marksndancer has " << md.productsInKids << " kids products"
         << endl;
}

void merger(Marksndancer md, Eastside es)
{
    char option;
    cout << "Do you want to open a new store?(y/n)" << endl;
    cin >> option;
    if (option == 'y')
    {
        newStore(md, es);
    }
    cout << "Do you want to transfer furniture from Eastside to "
            "Marksndancer?(y/n)"
         << endl;
    cin >> option;
    if (option == 'y')
    {
        es.transferKidsFurniture(md);
    }
    cout
        << "Do you want to transfer clothes from Marksndancer to Eastside?(y/n)"
        << endl;
    cin >> option;
    if (option == 'y')
    {
        md.transferClothesToEastside(es);
    }
}

void newStore(Marksndancer md, Eastside es)
{
    cout << "Final assets: " << (md.assets + es.assets) << endl;
    cout << "Total products: "
         << (md.productsInKids + es.kidsFurniture + md.productsInMen +
             md.productsInWomen + es.totalFurniture)
         << endl;
}

Marksndancer getMarksndancer()
{
    cout << "Enter existing products in kids section: ";
    int productsInKids;
    cin >> productsInKids;
    cout << "Enter existing products in men section: ";
    int productsInMen;
    cin >> productsInMen;
    cout << "Enter existing products in women section: ";
    int productsInWomen;
    cin >> productsInWomen;
    cout << "Enter the assets: ";
    float assets;
    cin >> assets;
    cout << "Enter the average product cost: ";
    float averageProductCost;
    cin >> averageProductCost;
    Marksndancer md(productsInKids, productsInMen, productsInWomen, assets,
                    averageProductCost);
    return md;
}

Eastside getEastside()
{
    cout << "Enter existing products in kids section: ";
    int kidsFurniture;
    cin >> kidsFurniture;
    cout << "Enter total furniture: ";
    int totalFurniture;
    cin >> totalFurniture;
    cout << "Enter the assets: ";
    float assets;
    cin >> assets;
    cout << "Enter the average product cost: ";
    float averageProductCost;
    cin >> averageProductCost;
    Eastside es(kidsFurniture, totalFurniture, assets, averageProductCost);
    return es;
}

int main()
{
    cout << "Enter details for Marksndancer" << endl;
    Marksndancer md = getMarksndancer();
    cout << "Enter details for Eastside" << endl;
    Eastside es = getEastside();
    merger(md, es);
    return 0;
}
