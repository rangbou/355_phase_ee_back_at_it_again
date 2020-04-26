#include "network.h"

int main(){
	Person a("a","a","a");
	Person b("b","b","b");
	Person c("c","c","b");
	a.addFriend(&b);
	b.addFriend(&c);
	c.addFriend(&b);
	cout << a.getFriends()<< b.getFriends()<<c.getFriends();
}