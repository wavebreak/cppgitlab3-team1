#include <iostream>
using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    currentDate = date;
}

string ShoppingCart::GetCustomerName() const {
    return customerName;
}

string ShoppingCart::GetDate() const {
    return currentDate;
}


void ShoppingCart::AddItem(ItemToPurchase item) {

}

void ShoppingCart::RemoveItem(string name) {

}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
bool ItemsModified = false;
for (int i = 0; i < cartItems.size(); i++){
if (cartItems.at(i).GetName() == item.GetName()){
cartItems.at(i).SetPrice(item.GetPrice());
cartItems.at(i).SetQuantity(item.GetQuantity());
cartItems.at(i).SetDescription(item.GetDescription());
ItemsModified = true;
}

}

if (ItemsModified == false)

cout << "Item not found in cart. Nothing modified." << endl;

}





int ShoppingCart::GetNumItemsInCart() {

    int x = cartItems.size();

return x;
    
     
}




double ShoppingCart::GetCostOfCart() {

    
    
double SHOPcartTOTAL=0;

for (unsigned int y = 0; y < cartItems.size(); y++) {
   
   SHOPcartTOTAL= SHOPcartTOTAL + (cartItems.at(y).GetPrice()*cartItems.at(y).GetQuantity());
   
}

return SHOPcartTOTAL;

    
    
    
    
}

void ShoppingCart::PrintTotal() {
    unsigned i;
    int totalCost;

    totalCost = 0;

    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;

    if(cartItems.size() > 0) {
        for(i = 0; i < cartItems.size(); ++i) {
            cartItems.at(i).PrintItemCost();
        }
    }

    else {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }

    totalCost = GetCostOfCart();

    cout << endl << "Total: $" << totalCost << endl;
}

void ShoppingCart::PrintDescriptions() {
    unsigned i;

    cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
    cout << "Item Descriptions" << endl;

    if(cartItems.size() > 0) {
        for(i = 0; i < cartItems.size(); ++i) {
            cartItems.at(i).PrintItemDescription();
        }
    }

    else {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
}
