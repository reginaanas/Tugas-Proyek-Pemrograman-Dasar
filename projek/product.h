#ifndef _PRODUCT_H
#define _PRODUCT_H
#include <iostream>
#include <vector>
#include <string>

class Product {
public:
    Product (std::string productName = "", int number = 0, int price = 0);
    int _price;
    int _number;
    static int count;
    static std::vector<Product> list;
    std::string getName() const;
    int getPrice() const;
    int getNumber() const;
    void newProduct();
    static void showAllProducts();
    static Product* getProduct(int number); 
    static void editProduct(int number);
    static void deleteProduct(int number);
    friend std::ostream& operator<<(std::ostream &os, const Product &p);

private:
    std::string _name;
};

#endif
