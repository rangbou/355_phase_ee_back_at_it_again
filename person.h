
#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include "contact.h"
#include "fstream"
#include "misc.h"

class Person{
    friend class Network;

private:
	string f_name;
	string l_name;
	Date *birthdate;
    Email *email;
    Phone *phone;
    // the following to attributes are used in the linked list.
    Person* next;
    Person* prev;

public: 
    Person();
    ~Person();
    Person(string filename);
    Person(string f_name, string l_name, string bdate, string email = "N/A", string phone = "N/A");
	void print_person();
	void set_person();
	void set_person(string filename);
    bool operator==(const Person& rhs);
    bool operator!=(const Person& rhs);
    string get_person(const string& show_contact = "yes");
    //phase 2
    vector<Person*> friends;
    void addFriend(Person* newFriend);
    void mutualAddFriend(Person* newFriend);
    void save_person(ofstream &outfile);
    string getFname();
    string getLname();
    string getFriends();
    string get_id();
    int find_position();
};


#endif
