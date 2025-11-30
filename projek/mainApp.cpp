#include <iostream>
#include <string>
#include <vector>
#include "Admin.h"
#include "Customer.h"
#include "Product.h"
#include "Cart.h"
#include "Receipt.h"
using namespace std;

void adminMenu(Admin &admin);
void customerMenu();
vector<Admin> admins; 

void seedAdmin() {
    admins.push_back(Admin("minjust@kmail.com", "minjustips", 1));
}

Admin* loginAdmin(const string &email, const string &pass) {
    for (auto &adm : admins) {
        if (adm.getEmail() == email && adm.getPass() == pass) {
            return &adm;
        }
    }
    return nullptr;
}

int main() {
    seedAdmin();
    int pilihan;
    do {
        cout << "=======================================\n";
        cout << "             ESVITI JUSTIPS            \n";
        cout << "=======================================\n";
        cout << "1. Admin\n";
        cout << "2. Customer\n";
        cout << "3. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        system("cls");

        if (pilihan == 1) {
            string email;
            string pass;

            cout << "------LOGIN ADMIN------\n";
            cout << "Masukkan Email: ";
            cin >> email;
            cout << "Masukkan Password: ";
            cin >> pass;

            Admin* adminLogin = loginAdmin(email, pass);

            if (adminLogin == nullptr) {
                cout << "Email atau Password salah.\n\n";
            } else {
                cout << "Login Berhasil!\n";
                adminMenu(*adminLogin);
            }
        }
        else if (pilihan == 2) {
            customerMenu();
        }
        else if (pilihan != 3) {
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 3);

    cout << "Keluar...\n";
    return 0;
}

void adminMenu(Admin &admin) {
    int pilih;

    do {
        cout << "\n-----MENU ADMIN-----\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Lihat Produk\n";
        cout << "3. Edit Produk\n";
        cout << "4. Hapus Produk\n";
        cout << "5. kembali\n";
        cout << "Masukkan pilihan: ";
        cin >> pilih;

        system("cls");

        switch (pilih) {
    case 1:
        {
            Product p;
            p.newProduct();
        }
        break;

    case 2:
        Product::showAllProducts();
        break;

    case 3:
        {
            int nomor;
            Product::showAllProducts(); 
            cout << "Masukkan Nomor Produk yang ingin diedit: ";
            cin >> nomor;
            Product::editProduct(nomor);  
        }
        break;
    case 4:
        {
            int nomor;
            Product::showAllProducts();
            cout << "Masukkan Nomor Produk yang ingin dihapus: ";
            cin >> nomor;
            Product::deleteProduct(nomor);
        }
        break;
}
    } while (pilih != 5);
}

void customerMenu() {
    string nama, email, pass;
    cout << "---REGISTER CUSTOMER---\n";
    cout << "Masukkan Nama: ";
    getline(cin >> ws, nama);
    cout << "Masukkan Email: ";
    cin >> email;
    cout << "Masukkan Password: ";
    cin >> pass;

    customer c(nama, email, pass);
    c.newcust(c);

    Cart cart;

    int pilih;
    do {
        cout << "\n-------MENU CUSTOMER-------\n";
        cout << "1. Lihat Produk\n";
        cout << "2. Tambah ke Keranjang\n";
        cout << "3. Lihat Keranjang\n";
        cout << "4. Hapus dari Keranjang\n";
        cout << "5. Cetak Receipt\n";
        cout << "6. Kembali\n";
        cout << "Masukkan pilihan: ";
        cin >> pilih;

        system("cls");

        switch (pilih) {
            case 1:
                Product::showAllProducts(); 
                break;

            case 2: {
                int no;
                cout << "Masukkan nomor produk yang ingin dibeli: ";
                cin >> no;
                Product* p = Product::getProduct(no);

                if (p == nullptr || p->getName().empty()) {
                cout << "Produk tidak ditemukan!\n";
                } else {
                cart.addToCart(*p);
                }
                break;
            }
            case 3:
                cart.showCart();
                break;

            case 4:
            {
                int no;
                cout << "Masukkan nomor produk yang ingin dihapus dari keranjang: ";
                cin >> no;
                cart.removeFromCart(no);
                break;
            }   

            case 5:
                Receipt::printReceipt(cart, nama);
                break;

            case 6:
                return;

            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilih != 6);
}