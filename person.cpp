
#include "person.h"
#include <bits/stdc++.h> 
#include "date.h"
#include "contact.h"

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
    // cout << "person destructor"<< endl;
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

    ifstream myfile(filename.c_str());
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
    //print out the id of friends 
    int size = friends.size();
    for(int i = 0; i < size; i++){
        cout << IDName(friends[i]->f_name,friends[i]->l_name) << endl;
    }
}

// Implementation for saveDB in network.cpp
string Person::get_person(const string& show_contact){
    if(show_contact == "yes"){
        // return l_name + ", " + f_name + "\n" + birthdate->get_date() +"\n"+ email->get_contact()+"\n"+ phone->get_contact()+ "\n--------------------\n";
        return l_name + ", " + f_name + "\n" + birthdate->get_date() +"\n"+ email->get_contact()+"\n"+ phone->get_contact()+ "\n";
    }
    else{
        return l_name + ", " + f_name + " born on " + birthdate->get_date();
    }
} 

void Person::addFriend(Person* newFriend){
    friends.push_back(newFriend);
}
void Person::mutualAddFriend(Person* newFriend){
    friends.push_back(newFriend);
    newFriend->friends.push_back(this);
}
string Person::getFriends(){
    string a;
    for(int i =0; i < friends.size(); i++){
        // a = a + IDName(friends[i].getFname(),friends[i].getLname())+ "\n"; 
        a.append(friends[i]->get_id());
        a.append("\n"); 
    }
    return a;
}

string Person::getFname(){
    return f_name;
}
string Person::getLname(){
    return l_name;
}

string Person::get_id(){
    return IDName(f_name,l_name);
}

void Person::save_person(ofstream &outfile){
    string save_write = get_person();
    outfile << save_write;

    int size = friends.size();
    for(int i = 0; i < size; i++){
        outfile << IDName(friends[i]->f_name,friends[i]->l_name) << endl;
    }
    outfile << "--------------------\n";
}

int Person::find_position(){
    Person* ptr;
    ptr = this;
    int count = 0;
    while(ptr != NULL){
        count++;
        ptr = ptr->prev;
    }
    return count;
}