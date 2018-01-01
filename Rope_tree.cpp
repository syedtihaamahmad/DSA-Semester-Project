<<<<<<< HEAD
#include"Rope_tree.h"
//Rope Data Structure Class
using namespace std;

void Rope::create(Rope*&node,Rope *root,char array[] ,int l,int r){
=======
#include <iostream>
#include<string>
#include<time.h>
#include <cstring>
using namespace std;
//Rope Data Structure Class

class Rope{
	public:
		Rope *left,*right,*root;
		char *value;
		int leftCount;
	void create(Rope*&node, Rope*root, char[], int, int);
	void print(Rope*node);
	Rope* concatenate(Rope *, Rope *, int);
	void deleteText(Rope*r,int start,int end, int size);
	char ElementAtIndex(Rope*r,int index);
	void substring(Rope *rope,int start, int end);
};
void create(Rope*&node,Rope *root,char array[] ,int l,int r){
>>>>>>> a5688d025d324a928cc9615d853842a113cac1de
			Rope *s3 = new Rope();
			s3->left = s3->right = NULL;
			s3->root = root;
			if(r-l <= 2){
				node = s3;
				s3->leftCount = r-l;
				//s3 = s3->left;
				s3->value = new char[2];
				int j =0;
				for(int i=l;i<=(r);i++){
					s3->value[j++] = array[i]; 
				}
			}
			else{
				s3->value = NULL;
				int m = (l+r)/2;
				s3->leftCount = (r-l)/2;
				node = s3;
				create(node->left,node,array,l,m);
				create(node->right,node,array,m+1,r);
			}
			
		}

<<<<<<< HEAD
void Rope::print(Rope *node){ 	
=======
void print(Rope *node){ 	
>>>>>>> a5688d025d324a928cc9615d853842a113cac1de
	static int i=0;
    if (node==NULL)
        return;
    if (node->left==NULL && node->right==NULL)
        cout << node->value;
     //cout<<node->leftCount;
    print(node->left);
    print(node->right);
}
<<<<<<< HEAD
Rope* Rope::concatenate(Rope *r1,Rope *r2,int n){
=======
Rope* concatenate(Rope *r1,Rope *r2,int n){
>>>>>>> a5688d025d324a928cc9615d853842a113cac1de
	Rope *r3 = new Rope();
	r3->root =NULL;
	r3->left = r1;
	r3->right = r2;
	r1->root=r2->root=r3;
	r3->leftCount =n;
	return r3;
	
}
<<<<<<< HEAD

char Rope::ElementAtIndex(Rope*r,int index){
=======
//This Function Deletes the characters in a string given the index by the user
void deleteText(Rope *rope,int start, int end, int size){
    static int j=0;
    Rope *r1=NULL,*r2=NULL;


    //int s1Size = sizeof(s1)/sizeof(char);
    //for(int i = 0; i < s1Size; i++)
    //	cout << s1[i];
    /*
    for(int i = 0; i < size-1; i++)
    	strcat(s1, 0, start-1);
    	strcat(s2, end, size-1);
	*/
    /*
    if(rope->left){
        if(start<rope->leftCount && end<rope->leftCount){
        	deleteText(rope->left,start,end,size);
        }
        else if(start>rope->leftCount && end>rope->leftCount){
        	deleteText(rope->right,start-rope->leftCount-1,end-rope->leftCount,size);
        }

        else {
        	if(start<=rope->leftCount){
        		//cout<<"c";
        		deleteText(rope->left,start,rope->leftCount,size);
        	}
        	if (end>rope->leftCount){
        		//cout<<"d";
        		deleteText(rope->right,0,end-rope->leftCount-1,size);
        		}
        	}
        }
        else{
        	for(int i=start;i<=end;i++)
        	{
        		//cout<<rope->value[i];
        	}
        	//substring(r)
        	 create(r1, NULL,s1, 0, start-2);
        	 create(r2, NULL, s2, end+1, size-1);
        	 rope =concatenate(r1,r2,4+size-1-end);
        	 print(rope);
        	//strcat(s,rope->value);	
        	//cout << s;
        	//create(rope, NULL, s, end, size-1);
        	//print(rope);
       }*/
 }
char ElementAtIndex(Rope*r,int index){
>>>>>>> a5688d025d324a928cc9615d853842a113cac1de
	if(index >r->leftCount){	
		index -= r->leftCount;
		ElementAtIndex(r->right,index-1);
	}
	else{
		if(r->left){
			ElementAtIndex(r->left,index);
		}
		else
			return r->value[index];
	}	
}
<<<<<<< HEAD
void Rope::substring(Rope *rope,int start, int end){
=======
void substring(Rope *rope,int start, int end){
>>>>>>> a5688d025d324a928cc9615d853842a113cac1de
    static int j=0;
    if(rope->left){
        if(start<rope->leftCount && end<rope->leftCount){
        	//cout<<"a";
        	substring(rope->left,start,end);
        }
        else if(start>rope->leftCount && end>rope->leftCount){
        	//cout<<"b";
        	substring(rope->right,start-rope->leftCount-1,end-rope->leftCount);
        }
		
        else {
        	if(start<=rope->leftCount){
        		//cout<<"c";
        		substring(rope->left,start,rope->leftCount);
        	}
        	if (end>rope->leftCount){
        		//cout<<"d";
        		substring(rope->right,0,end-rope->leftCount-1);
        		}
        	}
        }
        else{
        	for(int i=start;i<=end;i++)
        		cout<<rope->value[i];
        	
       }	
 }
<<<<<<< HEAD
void Rope::deleteText(Rope *rope, string s1, string s2, int start, int end, int size){
=======
void deleteTree(Rope *rope, string s1, string s2, int start, int end, int size){
>>>>>>> a5688d025d324a928cc9615d853842a113cac1de
	
	int n1 = s1.length();
	int n2 = s2.length();
	char char_s1[n1];
	char char_s2[n2];
	strcpy(char_s1, s1.c_str());
	strcpy(char_s2, s2.c_str()); 
	Rope *r1 = NULL, *r2 = NULL;
	create(r1, NULL,char_s1, 0, start);
    create(r2, NULL, char_s2, 0, n2);
   // print(r1);
    if(!(start==0||end==size-1))
    {
    rope = concatenate(r1,r2,2);
    print(rope);
    }
   if(start==0)
    print(r2);
    //if(end==size-1)
    //	print(r1);
	
}
<<<<<<< HEAD
/*int main(void){
=======
int main(void){
>>>>>>> a5688d025d324a928cc9615d853842a113cac1de
   int start = 2, end = 9;
   Rope *root1 = NULL;
   char s1[] = "1234567890";
    Rope *root2 = NULL;
   char s2[] = "abcd";
   //char first[100];
   string first="";
   string second="";
   int size = sizeof(s1)/sizeof(char);
   int size2 = sizeof(s2)/sizeof(char);
   create(root1, NULL, s1, 0, size-1);
   create(root2, NULL, s2, 0, size2-1);
   Rope *r3 =NULL;
   r3 = concatenate(root1,root2,size+size2-2);
 //  print(r3);
   for(int i = 0; i <= start-1; i++)
   		first += s1[i];
   for(int i = end+1; i <= size-1; i++)
   		second += s1[i];
<<<<<<< HEAD
	deleteText(root1, first, second,start, end, size);
   return 0;
}
*/
=======
	deleteTree(root1, first, second,start, end, size);
   return 0;
}
>>>>>>> a5688d025d324a928cc9615d853842a113cac1de
