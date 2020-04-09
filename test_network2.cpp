#include "network.h"

int main(){
	Network a;
	string filename = "studentDB.db";
	string savefile = "save.txt";
	a.loadDB(filename);
	a.printDB();
	// a.saveDB(savefile);
	string fname = "4293048";
	string lname = "3030ff";
	string bdate = "xhxhdo1";
	string arg = "no";
	// cout << "ptr@: "<<a.return_search(fname,lname,bdate)<< endl;
	a.return_search(fname,lname,bdate);
	// a.return_search("x","y","z");
	// Person b(fname,lname,bdate);
	// // cout << b.get_person(arg)<< endl;
	// cout << b.get_person("no")<< endl;
	// Person c("Darren","Hsu","02/18/99");
	// cout << c.get_person("no");

}