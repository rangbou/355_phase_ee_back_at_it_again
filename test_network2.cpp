#include "network.h"

int main(){
	Network a;
	string filename = "studentDB.db";
	string savefile = "save.txt";
	a.loadDB(filename);
	a.printDB();
	a.saveDB(savefile);
}