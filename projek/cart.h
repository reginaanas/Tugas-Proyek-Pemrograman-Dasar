#ifndef _CART_H
#define _CART_H
#include "product.h"
#include <vector>

class Cart {
public: 
    void addToCart(Product p);
    void showCart();
    int totalPrice() const;
    std::vector<Product> items;
    void removeFromCart(int productNumber);

private:
    friend class receipt;
};

#endif