
#include"Rope_tree.h"
//Rope Data Structure Class


void Rope:: create(Rope*&node,Rope *root,char array[] ,int l,int r){

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


void Rope::print(Rope *node){ 	

	static int i=0;
    if (node==NULL)
        return;
    if (node->left==NULL && node->right==NULL)
        cout << node->value;
     //cout<<node->leftCount;
    print(node->left);
    print(node->right);
}

Rope* Rope::concatenate(Rope *r1,Rope *r2,int n){


	Rope *r3 = new Rope();
	r3->root =NULL;
	r3->left = r1;
	r3->right = r2;
	r1->root=r2->root=r3;
	r3->leftCount =n;
	return r3;
	
}


char Rope::ElementAtIndex(Rope*r,int index){
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

void Rope::substring(Rope *rope,int start, int end){

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
void Rope::deleteText(Rope *rope, string a1, string a2, int start, int end, int size){
	string s1="",s2 ="",s="";
	s=a1+a2;
	for(int i=0;i<start;i++)
	{
		s1 += s[i];
	}
	for(int i=end+1;i<=s.length();i++)
	{
		s2 += s[i];
	}
	//cout<<a1;
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

int main()
{
	Rope *r1,*r2,*r3 = NULL;
	char a1[]="Khaadim Hussein ",a2[]="Rizvi";
	int size1 = sizeof(a1)/sizeof(char), size2=sizeof(size2)/sizeof(char);
	cout<<"\n---------Creating first Rope---------\n";
	r1->create(r1,NULL,a1,0,size1);
	r1->print(r1);
	cout<<"\n---------Creating second Rope--------\n";
	r2->create(r2,NULL,a2,0,size2);
	r2->print(r2);
	cout<<"\n------------Concatenating------------\n";
	r3 = r3->concatenate(r1,r2,size1+size2);
	r3->print(r3);
	cout<<"\n------------Deleting text------------ \n";
	r3->deleteText(r3,"Khaadim Hussein","Rizvi",15,19,size1+size2);
	cout<<"\n-------Retrieving text at index------ \n";
	cout<<r3->ElementAtIndex(r3,1);

	return 0;
}