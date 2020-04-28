#include "network.h"

int main(){
	// Network z;
	// Person a("a","a","02/18/1999");
	// Person b("b","b","02/18/1999");
	// Person c("c","c","02/18/1999");
	// Person d("d","d","02/18/1999");
	// Person e("e","e","02/18/1999");
	// Person f("f","f","02/18/1999");
	// Person g("g","g","02/18/1999");
	// Person h("h","h","02/18/1999");
	// a.mutualAddFriend(&c);
	// a.mutualAddFriend(&e);
	// c.mutualAddFriend(&b);
	// c.mutualAddFriend(&d);
	// c.mutualAddFriend(&g);
	// c.mutualAddFriend(&e);
	// e.mutualAddFriend(&f);
	// d.mutualAddFriend(&f);
	// f.mutualAddFriend(&g);
	// g.mutualAddFriend(&h);
	// h.mutualAddFriend(&b);

	// z.push_back(&a);
	// z.push_back(&b);
	// z.push_back(&c);
	// z.push_back(&d);
	// z.push_back(&e);
	// z.push_back(&f);
	// z.push_back(&g);
	// z.push_back(&h);

	// // z.printDB();
	// // z.friendRecommend();
	// z.saveDB("x.db");
	Network y;
	y.loadDB("this.db");
	y.friendRecommend(2);
	return 0;
}
