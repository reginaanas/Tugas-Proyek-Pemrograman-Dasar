#include "receipt.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void Receipt::printReceipt(const Cart &cart, const string &customerName) {

    cout << "======================================\n";
    cout << "             ESVITI JUSTIPS           \n";
    cout << "======================================\n";
    cout << "Customer: " << customerName << "\n\n";

    cout << "--------------------------------------\n";
    cout << left << setw(5) << "No"
         << setw(20) << "Nama"
         << setw(10) << "Harga" << "\n";
    cout << "--------------------------------------\n";

    int index = 1;
    for (const auto &item : cart.items) {
        cout << left << setw(5) << index++
             << setw(20) << item.getName()
             << setw(10) << item.getPrice() << "\n";
    }

    cout << "--------------------------------------\n";
    cout << "Total: " << cart.totalPrice() << "\n";
    cout << "======================================\n";
    cout << "        Thank you for shopping!       \n";
    cout << "======================================\n";

    ofstream file("receipt.txt");
    if (file.is_open()) {
        file << "======================================\n";
        file << "             ESVITI JUSTIPS           \n";
        file << "======================================\n";
        file << "Customer: " << customerName << "\n\n";

        file << "--------------------------------------\n";
        file << left << setw(5) << "No"
             << setw(20) << "Nama"
             << setw(10) << "Harga" << "\n";
        file << "--------------------------------------\n";

        int index = 1;
        for (const auto &item : cart.items) {
            file << left << setw(5) << index++
                 << setw(20) << item.getName()
                 << setw(10) << item.getPrice() << "\n";
        }

        file << "--------------------------------------\n";
        file << "Total: " << cart.totalPrice() << "\n";
        file << "======================================\n";
        file << "        Thank you for shopping!       \n";
        file << "======================================\n";

        file.close();
        cout << "Receipt berhasil disimpan!\n\n";
    } else {
        cout << "Gagal menyimpan receipt.\n";
    }
}
