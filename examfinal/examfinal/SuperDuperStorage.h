#pragma once



struct SN {
	int data;
	SN* next;
	SN* prev;
};

class SuperDuperStorage {
private:
	SN* start;
	SN* end;
	SN* high;
	SN* iter;
public:
	SuperDuperStorage();
	SuperDuperStorage(const SuperDuperStorage& rhs);
	~SuperDuperStorage();
	void clear();
	void insert(int data);
	int getMax();
	void moveIterToStart();
	void moveIterToEnd();
	void moveIterForward();
	void moveIterBackward();
	bool isIterValid();
	int getIterData();
};
