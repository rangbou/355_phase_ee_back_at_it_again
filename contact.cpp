#include "contact.h"
// TODO: Add needed libraries! 
#define CONTACT_H

Email::Email(string type, string email_addr){
    // Complete TODO: Complete me!
    this->type = type;
    this->email_addr = email_addr;
}


void Email::set_contact(){
    // Complete TODO: Do not change the prompts!
	
    cout << "Enter the type of email address: ";
    cin >> type;
    cout << "Enter email address: ";
    cin >> email_addr;
}


string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    // emaple: Email (USC): tommytrojan@usc.edu
    if (style=="full")
	    return "Email (" + type + "): " + email_addr;
    else 
        return email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}


Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it! 222-444-7898
    // TODO: Complete this method!

     // Note: Modify the following code can help you implementing this function
     // * This code has a bug, can you understand why?
    // long int area_code = atoi(num.substr(0, 3).c_str());
    // long int  number = atoi(num.substr(3).c_str()); 
    // this->phone_num = area_code*10000000 + number; 
    this->type = type;
    string area_code, buff;
  	// Iterate through num.
  	// Copy whatever characters are not '-' to buff
  	// Copy the first 3 to area_code (we don't use this later. I just doing it cause sample code has area code).
  	for(int i = 0; i<num.size(); i++){
  		if(num[i]!= '-'){
  			buff.push_back(num[i]);
	  		if(i < 3){
	  			area_code.push_back(num[i]);
	  		}
	  	}
  	}
  	this->phone_num = buff;
    
}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
	cout <<"Enter the type of phone number: ";
	cin >> type;
	cout << "Enter the phone number: ";
	cin >> phone_num;
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email 
    // follow the format of this example: Phone (Office): 310-192-2847

     // Note: Modify the following code can help you implementing this function
     // * This code has a bug, can you understand it？
    string phone_num_formatted = phone_num.substr(0,3)+ "-"+phone_num.substr(2,3)+"-"+phone_num.substr(5,4);
    if (style=="full")
	    return "Phone (" + type + "): " + phone_num_formatted;
    else 
        return phone_num_formatted; 
}


void Phone::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}


