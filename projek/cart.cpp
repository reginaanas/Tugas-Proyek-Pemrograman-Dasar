#include "cart.h"
#include <iostream>
using namespace std;

void Cart::addToCart(Product p) {
    items.push_back(p);
    cout << "Produk ditambahkan ke keranjang.\n";
}

void Cart::showCart() {
    if (items.empty()) {
        cout << "Keranjang masih kosong.\n";
        return;
    }
    
    cout << "Keranjang\n";
    for (auto &x : items) cout << x << endl;
}

void Cart::removeFromCart(int productNumber) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->_number == productNumber) {
            items.erase(it);
            cout << "Produk dihapus dari keranjang.\n";
            return;
        }
    }
    cout << "Produk tidak ditemukan di keranjang.\n";
}

int Cart::totalPrice() const {
    int total = 0;
    for (auto &x : items) total += x._price;
    return total;
}