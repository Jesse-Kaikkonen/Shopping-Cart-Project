//
// Created by Jesse Kaikkonen on 11/1/21.
//

#ifndef ONLINESHOPPINGCART_ITEMTOPURCHASE_H
#define ONLINESHOPPINGCART_ITEMTOPURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
private:
    string itemName;
    double itemPrice{};
    int itemQuantity{};
    string itemDescription;
public:
    ItemToPurchase();
    ItemToPurchase(string itemName, string itemDescription, double itemPrice = 0.0, int itemQuantity = 0);
    void SetName(string name);
    void SetPrice(double price);
    void SetQuantity(int quantity);
    string GetName();
    double GetPrice();
    int GetQuantity();
    void SetDescription(string description);
    string GetDescription();
    void PrintItemDescription();
    void PrintItemCost();
};


#endif //ONLINESHOPPINGCART_ITEMTOPURCHASE_H
