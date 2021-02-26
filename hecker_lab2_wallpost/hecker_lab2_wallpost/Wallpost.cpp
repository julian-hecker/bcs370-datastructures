#include "Wallpost.h"

void Wallpost::addLike(string newLiker) {
	likes[likesCount] = newLiker;
	likesCount++;
}

void Wallpost::setName(string newName) {
	name = newName;
}

void Wallpost::setComment(string newComment) {
	comment = newComment;
}

string Wallpost::getName() {
	return name;
}

string Wallpost::getComment() {
	return comment;
}

Wallpost::Wallpost() {
	name = "Nameless";
	comment = "Commentless";
}

Wallpost::Wallpost(string newName, string newComment) {
	name = newName;
	comment = newComment;
}

Wallpost::Wallpost(const Wallpost &rhs) {
	name = rhs.name;
	comment = rhs.comment;
	likesCount = rhs.likesCount;
	for (int i = 0; i < rhs.likesCount; i++) {
		likes[i] = rhs.likes[i];
	}
}

ostream& operator<<(ostream& os, Wallpost& rhs) {
	os << rhs.name << ": " << rhs.comment << endl;
	for (int i = 0; i < rhs.likesCount; i++) {
		os << rhs.likes[i] << " ";
	}
	os << endl;
	return os;
}
