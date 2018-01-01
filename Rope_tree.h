#ifndef ROPE_TREE
#define ROPE_TREE
#include <iostream>
#include<string>
#include<time.h>
#include <cstring>


using namespace std;
class Rope{
	public:
		Rope *left,*right,*root;
		char *value;
		int leftCount;
	void create(Rope*&node, Rope*root, char[], int, int);
	void print(Rope*node);
	Rope* concatenate(Rope *, Rope *, int);
	void deleteText(Rope *rope, string s1, string s2, int start, int end, int size);
	char ElementAtIndex(Rope*r,int index);
	void substring(Rope *rope,int start, int end);
};
#endif
