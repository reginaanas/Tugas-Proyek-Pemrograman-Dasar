#ifndef _ADMIN_H
#define _ADMIN_H
#include <string>

class Admin{
	public:
		Admin(std::string emailAdmin = "", std::string passAdmin = "", int admin = 0);
	
		void addProduct();
		void showProduct();
		void editProduct();
		std::string getEmail() const { return _emailAdmin; }
		std::string getPass() const { return _passAdmin; }
	private:
		std::string _emailAdmin;
		std::string _passAdmin;
		int _admin;
};
#endif
