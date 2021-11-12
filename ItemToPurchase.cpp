//
// Created by Jesse Kaikkonen on 11/1/21.
//

#include "ItemToPurchase.h"
#include <iostream>

using namespace std;

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, string description, double price, int quantity) {
    SetName(name) ;
    SetDescription(description) ;
    SetPrice(price) ;
    SetQuantity(quantity);
}

void ItemToPurchase::SetName(string name) {
    itemName = name;
}

void ItemToPurchase::SetPrice(double price) {
    itemPrice = price;
}

void ItemToPurchase::SetQuantity(int quant) {
    itemQuantity = quant;
}

string ItemToPurchase::GetName() {
    return itemName;
}

double ItemToPurchase::GetPrice() {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}

void ItemToPurchase::SetDescription(string description) {
    itemDescription = description;
}

string ItemToPurchase::GetDescription() {
    return itemDescription;
}

void ItemToPurchase::PrintItemDescription() {
    cout << GetName() << ": " << GetDescription() << endl;
}

void ItemToPurchase::PrintItemCost() {
    cout << GetName() << " " << GetQuantity() << " @ $" << GetPrice() << " = $" << (GetPrice() * GetQuantity());
}
