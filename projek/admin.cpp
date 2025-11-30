#include "admin.h"
#include "product.h"
#include <string>
#include <sstream>
using namespace std;

Admin::Admin(string emailAdmin, string passAdmin, int admin)
        : _emailAdmin(emailAdmin),_passAdmin(passAdmin), _admin(admin){}
		
void Admin::addProduct(){
	Product p;
	p.newProduct();
}

void Admin::showProduct() {
    Product::showAllProducts();
}

void Admin::editProduct() {
    Product::showAllProducts();
}

