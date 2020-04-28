#include "network.h"

int main(){
	Network z;
	Person a("a","a","02/18/1999");
	Person b("b","b","02/18/1999");
	Person c("c","c","02/18/1999");
	Person d("d","d","02/18/1999");
	Person e("e","e","02/18/1999");
	Person f("f","f","02/18/1999");
	Person g("g","g","02/18/1999");
	Person h("h","h","02/18/1999");
	a.addFriend(&c);
	a.addFriend(&e);
	c.addFriend(&b);
	c.addFriend(&d);
	c.addFriend(&g);
	c.addFriend(&e);
	e.addFriend(&f);
	d.addFriend(&f);
	f.addFriend(&g);
	g.addFriend(&h);
	h.addFriend(&b);

	z.push_back(&a);
	z.push_back(&b);
	z.push_back(&c);
	z.push_back(&d);
	z.push_back(&e);
	z.push_back(&f);
	z.push_back(&g);
	z.push_back(&h);

	// z.printDB();
	z.friendRecommend();
	return 0;
}
