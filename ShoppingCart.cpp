//
// Created by Jesse Kaikkonen on 11/1/21.
//

#include "ShoppingCart.h"
#include <iostream>
#include <string>

using namespace std;

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string custName, string currDate) {
    customerName = custName;
    currentDate = currDate;

}

string ShoppingCart::GetCustomerName() {
    return customerName;
}

string ShoppingCart::GetDate() {
    return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string itemName) {
    int index = -1;

    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems[i].GetName().compare(itemName) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        cartItems.erase(cartItems.begin() + index);
        cout << endl;
    } else if (index == -1) {
        cout << "Item not found in cart. Nothing removed." << endl << endl;
    }

}

void ShoppingCart::ModifyItem(string name) {
    int quantity;
    int index = -1;

    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems[i].GetName().compare(name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        cout << "Enter the new quantity:" << endl;
        cin >> quantity;
        cartItems[index].SetQuantity(quantity);

    } else if (index == -1) {
        cout << "Enter the new quantity:" << endl;
        cout << "Item not found in cart. Nothing modified." << endl << endl;
    }
}

int ShoppingCart::GetNumItemsInCart() {
    int totalItems=0;
    for (auto & cartItem : cartItems){
        totalItems += cartItem.GetQuantity();
    }
    return totalItems;
}

double ShoppingCart::GetCostOfCart() {
    double totalCost = 0.0;
    for (auto & cartItem : cartItems){
        totalCost += ((cartItem.GetPrice()) * (cartItem.GetQuantity()));
    }
    return totalCost;
}

void ShoppingCart::PrintTotal() {
    double total = 0;

    cout << customerName << "'s Shopping Cart - " << currentDate << endl;

    if(cartItems.size() == 0){
        cout << "Number of Items: 0" << endl << endl;

        cout << "SHOPPING CART IS EMPTY" << endl << endl;

        cout << "Total: $0" << endl << endl;
    }

    else{

        cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;

        for(int i = 0; i < cartItems.size(); i++){

            cartItems.at(i).PrintItemCost();

            cout << endl;

            total += ((cartItems.at(i).GetPrice()) * (cartItems.at(i).GetQuantity()));

        }
        cout << endl;

        cout << "Total: $" << total << endl << endl ;

    }
}

void ShoppingCart::PrintDescriptions() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;

    cout << "Item Descriptions" << endl;

    for(int i = 0; i < cartItems.size(); i++){

        cartItems.at(i).PrintItemDescription();
    }
    cout << endl;
}






