#include "network.h"
int main(){
	Person a;
	Person b;
	Network x;
	x.push_front(&a);
	x.push_back(&b);
	x.printDB();
}