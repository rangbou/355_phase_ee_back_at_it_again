#include "contact.h"
// #include "contact.cpp"
int main(){
	string type1 = "USC";
	string email = "ducky400@...com";
	string type2 = "Home";
	string phone = "909-909-9099"; 
	Email a(type1, email);
	Phone b(type2, phone);
	// Email(type,email) a;
	// Phone(type,phone) b;
	a.set_contact();
	a.get_contact();
	b.set_contact();
	b.get_contact();
}