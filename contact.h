#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <bits/stdc++.h> 

// TODO: You may need to add other libraries here!
using namespace std;
// #include "contact.cpp"

// Completed
class Contact {
    // TODO: private or protected? Look at its children!
protected:	
	string type;
public:
    // the following functions are pure virtual functions
	virtual void print() = 0;
    virtual string get_contact(string style="full") = 0;
	virtual void set_contact() = 0;
};

// Completed
class Email: public Contact{
private:
    string email_addr;
public:
    Email(string type, string email_addr);
    // TODO: Complete me!
    void print();
    string get_contact(string style = "full");
    // string get_contact();
    void set_contact();
};

// Completed
class Phone: public Contact{
private:
    // Completed TODO: modify dataType! Can int store 10 digit phone-number? 
	string phone_num; 
public:
    Phone(string type, string phone_number);
    // TODO: Complete me!
    void print();
    string get_contact(string style = "full");
    // string get_contact();
    void set_contact();
};

#endif
