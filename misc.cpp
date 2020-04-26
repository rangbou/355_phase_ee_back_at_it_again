
#include "misc.h"

void printMe(string type){
    if (type == "banner"){
        char banner[] = \
"   ######## ########   #######        ##    ###    ##    ##         ########   #######   #######  ##    ## \n \
     ##    ##     ## ##     ##       ##   ## ##   ###   ##         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ## ##     ##       ##  ##   ##  ####  ##         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ########  ##     ##       ## ##     ## ## ## ## ####### ########  ##     ## ##     ## ##### \n \
     ##    ##   ##   ##     ## ##    ## ######### ##  ####         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ##    ##  ##     ## ##    ## ##     ## ##   ###         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ##  #######   ######  ##     ## ##    ##         ########   #######   #######  ##    ##\n";
        cout << endl << banner << endl << endl;
    }
}

string IDName(string str1, string str2){ // concat str1 and str2, remove spaces, make all letters lower case.
	string new_str = str2 + str1; //str1 is first name and str2 is last name
	int size = new_str.length();;
	char temp;

	for(int i = 0; i < size; i++){ //get rid of uppercase
		if(isupper(new_str[i])){
		temp = new_str[i] + 32;
		new_str[i] = temp;
		}
	}

	for(int x = 0; x < size; x++){ //get rid of spaces
		if(new_str[x] == ' '){
			new_str.erase(x,1);
		}
	}
	return new_str;
}