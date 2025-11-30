#ifndef _RECEIPT_H
#define _RECEIPT_H
#include "cart.h"
#include <string>

class Receipt {
public:
    static void printReceipt(const Cart &cart, const std::string &customerName);
};

#endif