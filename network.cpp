
#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}

//COMPLETED
Network::Network(string fileName){
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
    loadDB(fileName);
    head = NULL;
    tail = NULL;
    count = 0;
}

//COMPLETED
Network::~Network(){
    // TODO: Complete this method
    // Destructure delete all the Person
    Person* current = head; 
    Person* next;

    while(current != NULL){
        next = current->next;
        delete current;
        current = next; 
    }
}


void Network::push_front(Person* newEntry){
    // Adds a new Person (newEntry) to the front of LL
    newEntry->prev = NULL;
    newEntry->next = head;

    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;
    
    head = newEntry;
    count++;
}

//COMPLETED
void Network::push_back(Person* newEntry){
    // Complete : Complete this method!
    // Adds a new Person (newEntry) to the back of LL
    // TODO: Test
    newEntry->prev = tail;
    newEntry->next = NULL;

    if (tail != NULL)
        tail->prev = newEntry;
    else
        head = newEntry;
    
    tail = newEntry;
    count++;
}


void Network::printDB(){
    // Don't change this method
    // Note: Notice that we don't need to update this even after adding to Person attributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of persons: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}

//COMPELTED
void Network::saveDB(string filename){
    // TODO: Test
    // Saves the netwrok in file <filename>
    // Note: The format of the output file is very abstract, just raw data
    // Look at studentDB.db as a template
    // Note: notice the intentional flaw in this code, as compared to the note mentioned in printDB, 
    // now the one who is responsible for implementing Network should be aware of implementation of Person, not good! You will fix this in PA2. 

    // Possible use of iterator?
    ofstream write;
    write.open(filename.c_str());
    if(write.is_open()){
        Person *current;
        for(int i = 0; i < count; i++ ){
            if(i == 0){
                current = this->head;
            }
            else{
                current = current->next;
            }
        write << current->get_person();
        }
    }
    else{
        cout << "Could not open write file."<< endl;
    }
}

//COMPLETED
void Network::loadDB(string filename){
    // TODO: Test
    // Loads the netwrok from file <filename>
    // The format of the input file is similar to saveDB
    // Look at network studentDB.txt as a template
    // Phone number can be with dashes or without them
    // You need to use the following constructor of the Person class, Person::Person(fname, lname, bdate, email, phone)
    
    Person* ptr = head;
    while(head != NULL){
        ptr = head->next;
        delete head;
        head = ptr;
        count--;
    }
    head = NULL;
    tail = NULL;
    ifstream infile;
    infile.open(filename.c_str());
    string buff, fname, lname, bdate;

    // TODO: Decalre other vairiable if needed
    string type_em, type_ph, email, phone;

    while(getline(infile, buff)){
        lname = buff.substr(0, buff.find(','));
        fname = buff.substr(buff.find(',')+2);
        getline(infile, bdate);
        // TODO: read email and phone
        getline(infile,buff);
        type_em = buff.substr(buff.find('(')+1 , buff.find(')'));
        email = buff.substr(buff.find(')')+2);
        // Reading phone number
        getline(infile, buff);
        type_ph = buff.substr(buff.find('(')+1 , buff.find(')'));
        phone = buff.substr(buff.find(')')+2);
        // This line is to read the dash line
        getline(infile, buff);
        // TODO: use the constructor Person::Person(fname, lname, bdate, email, phone) to modify the following line
        Person newEntry(fname, lname, bdate, email, phone);
        // adding to linked list. increase count.
        this->push_back(&newEntry);
        count++;
    }
}

Person* Network::search(string fname, string lname, string bdate){
    // TODO: Complete this method!
    // Search the Network for the given fname, lname, bdate
    // You may create a new person, say searchEntry, with fname, lname and bdate. Think about what Person constructor will be helpful with these arguments.
    // And use == overloaded operator between two persons
    // if found, returns a pointer to it, else returns NULL
    // Don't forget to delete allocated memory.
}

bool Network::remove(string fname, string lname, string bdate){
    // TODO: Complete this method! Follow these steps:
    // Create a new person with the the give arguments as you do in search
    // Search if this person exists using search method. If it does not exist just return false! Else, remove the person from LL, make the other connections connected
    // Don't forget to delete allocated memory, change count and returning values!


}

void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you, 
    // You should add code before, between and after prompts!

    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library

        cout << "Select from below: \n";
        cout << "1. Load network database \n";
        cout << "2. Save network database \n";
        cout << "3. Add a new person \n";
        cout << "4. Search \n";
        cout << "5. Remove a person \n";
        cout << "6. Print database \n";
        
        cout << "\nSelect an option ... ";
        
        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }
        
        // You may need these variables! Add more if you want!
        string fname, lname, fileName, bdate;
        Person* search_result;
        int remove_result;
        cout << "\033[2J\033[1;1H";

        //COMPLETED
        if (opt==1){
            // TODO: Complete me!
            cout << "Loading network database \n";
            // TODO: print all the files in this same directory that have ".db" format
            // Take a look into sample_files.cpp 

            DIR *dir;
            struct dirent *ent;
            char targetFolderAddr[] = "./";

            if ((dir = opendir ("./")) != NULL) { 
                int flag = 0;
                char o = '.';
                char d = 'd';
                char b = 'b';

                while ((ent = readdir (dir)) != NULL) {
                string name = ent->d_name;
                int size = name.length();
                    if((name[size -3] == o) && (name[size -2] == d) && (name[size -1] == b)){
                    cout << name << endl;
                    flag = 1;
                    }
                }

                if(flag == 0){
                    cout << "Nothing here \n";
                }

                closedir (dir);
            } 

            else {
            /* could not open directory */
            perror ("No directory!");
            }

            cout << "Enter the name of the load file: ";
            cin >> fileName; 

            ifstream infile(fileName.c_str());

            // If file with name FILENAME does not exist: 
            if(!infile){
                cout << "File FILENAME does not exist!" << endl;
            }
            // If file is loaded successfully, also print the count of persons in it:
            else{
                loadDB(fileName);
                cout << "Network loaded from " << fileName << " with " << count << " persons \n";
            }
            
        }

        //COMPLETED
        else if (opt==2){
            // TODO: Complete me!
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            cin >> fileName;
            saveDB(fileName);
            cout << "Network saved in " << fileName << endl;
        }

        //COMPLETED
        else if (opt == 3){
            // TODO: Complete me!
            // TODO: use push_front, and not push_back 
            // Add a new person ONLY if it does not exists!
            string user_option;
            int flag = 1;
            int exist;

            cout << "We must verify if this Person exists first\n";
            cout << "First name: ";
            cin >> fname;
            cout << "Last name: ";
            cin >> lname;
            cout << "Birdate (M/D/YYYY): ";
            cin >> bdate;

            if(search(fname, lname, bdate) == NULL){
                exist = 1;
            } 
            else{
                exist = 0;
            }
            if(exist == 1){
                while(flag>0){
                    cout << "Enter 'manual' or 'filename'\n";
                    cin >> user_option;

                    if(user_option == "manual"){
                        flag = 0;
                        Person* newPerson_man;
                        push_front(newPerson_man);
                    }

                    else if(user_option == "filename"){
                        flag = 0;
                        cout << "What is the full filename?\n";
                        cin >> fileName;
                        Person newPerson_fil(fileName);
                        Person* newPerson_point = &newPerson_fil;
                        push_front(newPerson_point);
                    }

                    else{
                    flag = 1;
                    cout << "Incorrect input. Try again. ";      
                    }
                }
                cout << "Adding a new person \n";
            }

            else if(exist = 0){
                cout << "Person already exists\n";
            }
        }

        //COMPLETED
        else if (opt == 4){
            // TODO: Complete me!
            cout << "Searching: \n";
            cout << "First Name: ";
            cin >> fname;
            cout << "Last Name: ";
            cin >> lname;
            cout << "Birthdate (M/D/YYYY): ";
            cin >> bdate;
            // if found: print person's firstname, lastname, bdate, email, phone using print_person()
            // if not, cout << "Not found! \n";
            search_result = search(fname,lname,bdate);
            if(search_result == NULL){
                cout << "Not found! \n";
            }
            else{
                search_result->print_person();
            }
        }

        //COMPLETED    
        else if (opt==5){
            // TODO: Complete me!
            cout << "Removing a person \n";
            cout << "First name: ";
            cin >> fname;
            cout << "Last name: ";
            cin >> lname;
            cout << "Birthdate (M/D/YYYY): ";
            cin >> bdate;
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Person not found! \n";
            remove_result = remove(fname,lname,bdate);
            if(remove_result = 0){
                cout << "Person not found!\n";
            }
            else{
                cout << "Remove Sucessful!\n";
            }

        }
        else if (opt==6){
            // TODO: Complete me!
            cout << "Network Database: \n";

        }
        else
            cout << "Nothing matched!\n";
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}


