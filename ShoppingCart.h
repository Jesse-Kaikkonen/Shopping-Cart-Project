//
// Created by Jesse Kaikkonen on 11/1/21.
//

#ifndef ONLINESHOPPINGCART_SHOPPINGCART_H
#define ONLINESHOPPINGCART_SHOPPINGCART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"

using namespace std;

class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(string custName = "none", string currDate = "none");
    string GetCustomerName();
    string GetDate();
    void AddItem(ItemToPurchase item);
    void RemoveItem(string itemName);
    void ModifyItem(string name);
    int GetNumItemsInCart();
    double GetCostOfCart();
    void PrintTotal();
    void PrintDescriptions();
private:
    string customerName;
    string currentDate;
    vector <ItemToPurchase>cartItems;
};


#endif //ONLINESHOPPINGCART_SHOPPINGCART_H
