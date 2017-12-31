#include <iostream>
#include<string>
#include<time.h>
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
		Rope* deleteText(Rope*r,int start,int end);
		char ElementAtIndex(Rope*r,int index);
		void substring(Rope *rope,int start, int end);

};
void create(Rope*&node,Rope *root,char array[] ,int l,int r){
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

void print(Rope *node){ 	
	static int i=0;
    if (node==NULL)
        return;
    if (node->left==NULL && node->right==NULL)
        cout << node->value;
     cout<<node->leftCount;
    print(node->left);
    print(node->right);
}
Rope* concatenate(Rope *r1,Rope *r2,int n){
	Rope *r3 = new Rope();
	r3->root =NULL;
	r3->left = r1;
	r3->right = r2;
	r3->leftCount =n;
	return r3;
	
}
//This Function Deletes the characters in a string given the index by the user
Rope* deleteText(Rope*r,int start,int end){
	r->value = new char [end-start];
	if(start>r->leftCount)
		r->right = deleteText(r->right,start,end);
	else
		r->left = deleteText(r->left,start,end);
	for(int i=start;i<=end;i++)
		delete (r->value);
}
char ElementAtIndex(Rope*r,int index){
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
void substring(Rope *rope,int start, int end){
    static int j=0;
    if(rope->left){
        if(start<rope->leftCount && end<rope->leftCount){
        	substring(rope->left,start,end);
        }
        else if(start>=rope->leftCount && end>rope->leftCount){
        	substring(rope->right,start-rope->leftCount-1,end-rope->leftCount);
        }
        else {
        	if(start<rope->leftCount){
        		substring(rope->left,start,rope->leftCount);
        	}
        	if (end>rope->leftCount){
        		substring(rope->right,0,end-rope->leftCount-1);
        		}
        	}
        }
        else{
        	for(int i=start;i<=end;i++)
        		cout<< rope->value[i];
       }		
 }
int main(void){
   int start, end;
   Rope *root1 = NULL;
   char s1[] = "Hetlomyni 123";
   int size = sizeof(s1)/sizeof(char);
   create(root1, NULL, s1, 0, size-1);
   cout << "Enter the start of slice of string you want: ";
   cin >> start;
   cout << "Enter the end: ";
   cin >> end;
   if(end > size){
	   	cout << "The string length is: " << size << " and end value is: " << end << endl; 
	   	cout << "Exiting." << endl;
	   	exit(0);
   }
   else{
	   	cout << "The extracted string is: ";
	   substring(root1,start,end);
	   cout << endl;
	}
   return 0;
}
