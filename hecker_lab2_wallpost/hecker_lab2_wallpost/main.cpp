#include "Wallpost.h"

int main() {

	Wallpost post("Choolian", "I think that the world is pretty cool");
	post.addLike("Boolean");
	post.addLike("Roolian");

	cout << post;


	Wallpost post2(post);
	post2.addLike("Julian");
	cout << post2;

	return 0;
}
