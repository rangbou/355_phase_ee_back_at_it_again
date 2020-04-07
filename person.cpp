
#include "person.h"
#include <bits/stdc++.h> 

Person::Person(){
    // I'm already done! 
    set_person();
    prev = NULL;
    next = NULL;
}

//COMPLETED
Person::~Person(){ 
    delete birthdate;
    delete email;
    delete phone;
    //Xuejing said we didn't need to delete prev or next
    //delete prev; 
    //delete next;
    // TODO: complete the method!
}

//COMPLETED
Person::Person(string fname, string lname, string bdate, string email1, string phone1){
    // TODO: Complete this method!
    string temp;
    string type; 

    f_name = fname;
    l_name = lname;
    birthdate = new Date(bdate);
    // phone and email strings are in full version
    stringstream read_email(email1);
    read_email >> type >> temp; 
    email = new Email(type,temp);

    stringstream read_phone(phone1);
    read_phone >> type >> temp;
    phone = new Phone(type,temp);

    prev = NULL;
    next = NULL;
}


Person::Person(string filename){
    set_person(filename);
    prev = NULL;
    next = NULL;
}

// COMPLETED
void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method! 
    
    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name); //set f_name

	cout << "Last Name: ";
    std::getline(std::cin,l_name); //set l_name

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);  // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp);  //set birthdate

    cout << "Type of email address: ";
    std::getline(std::cin,type);

    cout << "Email address: ";
    std::getline(std::cin,temp);
    email = new Email(type,temp); //set email

    cout << "Type of phone number: ";
    std::getline(std::cin,type);

    cout << "Phone number: ";
    std::getline(std::cin,temp);
    phone = new Phone(type,temp); //set phone
}

//COMPLETED
void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.     
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!
    string temp;
    string type;

    //from geeksforgeeks
    int size = filename.length();
    char char_filename[size + 1];
    strcpy(char_filename, filename.c_str());

    ifstream myfile(char_filename);
    getline(myfile, f_name);
    getline(myfile, l_name);
    getline(myfile, temp);

    birthdate = new Date(temp);

    myfile >> type >> temp;
    phone = new Phone(type, temp);

    myfile >> type >> temp;
    email = new Email(type, temp);

    myfile.close();
}

//COMPLETED
bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
    if((f_name == rhs.f_name) && (l_name == rhs.l_name) && (birthdate == rhs.birthdate)){
    	return true;
    }
    else{
    	return false;
    }
}

//COMPLETED
bool Person::operator!=(const Person& rhs){ 
    // TODO: Complete this method!
    if((f_name != rhs.f_name) || (l_name != rhs.l_name) || (birthdate != rhs.birthdate)){
    	return true;
    }
    else{
    	return false;
    }

}

void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    email->print();
    phone->print();
}

