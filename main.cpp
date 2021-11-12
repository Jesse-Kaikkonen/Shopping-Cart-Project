#include <iostream>

#include "ShoppingCart.h"
#include "ItemToPurchase.h"
using namespace std;

void PrintMenu() {
    cout <<"MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout <<"q - Quit" << endl << endl;

}

void ExecuteMenu(char option, ShoppingCart& theCart) {
    if (option == 'a') {

        string itemName = "";
        string itemDescription;
        int itemQuantity;
        double itemPrice;

        cout << "ADD ITEM TO CART" << endl;
        cout << "Enter the item name:" << endl;
        cin.ignore();
        getline (cin, itemName);

        cout << "Enter the item description:" << endl;

        getline(cin, itemDescription);

        cout << "Enter the item price:" << endl;
        cin >> itemPrice;

        cout << "Enter the item quantity:" << endl << endl;
        cin >> itemQuantity;

        ItemToPurchase itemToAdd(itemName, itemDescription, itemPrice, itemQuantity);
        theCart.AddItem(itemToAdd);



    } else if (option == 'd') {

        string itemToRemove;

        cout << "REMOVE ITEM FROM CART" << endl ;
        cout << "Enter name of item to remove:" << endl;
        cin.ignore();
        getline(cin, itemToRemove);
        theCart.RemoveItem(itemToRemove);



    } else if (option == 'c') {
        string selectedItem;

        cout << "CHANGE ITEM QUANTITY" << endl;
        cout << "Enter the item name:" << endl;
        cin.ignore();
        getline(cin, selectedItem);
        theCart.ModifyItem(selectedItem);

    } else if (option == 'i') {

        cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
        theCart.PrintDescriptions();

    } else if (option == 'o') {

        cout <<"OUTPUT SHOPPING CART" << endl;
        theCart.PrintTotal();

    } //else if (option == 'q') {}

    PrintMenu();
}

int main() {
    string yourName;
    string todayDate;
    char option;

    cout << "Enter customer's name:\n";
    getline(cin, yourName);

    cout << "Enter today's date:" << endl << endl;

    getline(cin, todayDate);

    cout << "Customer name: " << yourName << endl;
    cout << "Today's date: " << todayDate << endl << endl;

    ShoppingCart theCart = ShoppingCart(yourName, todayDate);

    PrintMenu();
    while (option != 'q'){

        cout << "Choose an option:" << endl;
        cin >> option;
        if (option == 'a' || option == 'd' || option == 'c' || option == 'i' || option == 'o') {
            ExecuteMenu(option, theCart);
        }
    }

    return 0;
}