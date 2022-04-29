#include <iostream>

using namespace std;

struct Node{
	int id;
	Node* next;
};
struct List {
	Node* first;
};
List* listCreate(){
	List* l = new List;
	l->first = NULL;
	return l;
}
int listSize(List* l){
	  Node* p = l->first;
	  int i=0;
    while (p != NULL) {
    p = p->next;
	i++;
	}
		//cout << i <<endl;
	return i;
}
void listPrint(List* l) {
    cout << "\nLISTA ENCADEADA" << endl;
    cout << "first -> ";

    Node* p = l->first;
    while (p != NULL) {
        cout << p->id << " -> ";
        p = p->next;
    }
    cout << endl;
};
List* listInsertAfter (List* l, int id){
	Node* n = new Node;
	Node* p = l->first;
	n->id = id;
	n->next = NULL;
	Node* antp = NULL;
	while(p != NULL){
		antp=p;
		p=p->next;
	}
	if(antp==NULL){
		l->first=n;
	}
	else{
		antp->next=n;
	}
	return l;
}

int listSum(List* l){
	Node* p = l->first;
	Node* antp = NULL;
	int x=0;
	while(p != NULL){
		antp=p;
		p=p->next;
		x+=antp->id;
		
	}
	return x;

}
int listMax(List* l){
	Node* n = l->first;
	int a= -9999999;
	while(n != NULL){
		if(n->id>a){
			a=n->id;
		}
	n=n->next;	
	}
	cout<< a <<endl;
}
int listHeight(List* l,int e){
	Node* n = l->first;
	int x=0;
	while(n !=NULL && x==0){
		if(n->id== e){
		   x++;	
		}
		n=n->next;
	}
	int t=0;
	while(n !=NULL){
		t++;
		n=n->next;	
	}
	
	return t;
}

int listDepth(List* l, int e){
	Node* n = l->first;
	int i=0;
	while(n != NULL){
		i++;
		if(n->id==e){
		break; 	
		}
		n=n->next;
	}
	
	return i;
	
}
List* ordena(List* l){
	List* lx = listCreate();
	Node* n = l->first;
	int t = listSize(l);
	//cout << t <<endl;
	int v[t];
	int c= 0;
	while(n != NULL){
		v[c]= n->id;
		c++;
		n=n->next;
	}
	int aux=0;
	for(int i= 0; i <t; i++){
		for(int y =i+1 ; y<t ; y++){
			if(v[i]< v[y]){
				aux=v[i];
				v[i]=v[y];
				v[y]=aux;	
			}
		}
	}
	for(int i =0; i<t; i++){
	listInsertAfter(lx,v[i]);
	}
	return lx;
}
void listInsertSortedDesc(List* l, int e){
/*	List* t = listInsertAfter(l , e);
	List* x = ordena(t);
	listPrint(x);*/



	List* t =ordena(l);
	Node* n = new Node;
	Node* p = t->first;
	n->id=e;
	n->next=NULL;
	Node* antp= NULL;
	cout<< "n"<<endl;
	
	
	while(p != NULL){
		if(p->id==e){
			cout<< "n"<<endl;
			break;
		}
		antp=p;
		p=p->next;	
	
	}
	listPrint(t);
	antp->next=n;
	n->next=p;
	listPrint(t);
}
void listRemove(List* l, int e){
	Node* n = l->first;
	Node* antn =NULL;
	if(n->id==e){
	l->first= n->next;
	delete n;
	listPrint(l);
	}
	else {
	
	while(n != NULL){
		if(n->id==e){
			break;
		}
		antn=n;
		n=n->next;
	}
	antn->next=n->next;
	delete n;
	listPrint(l);}
}
void listPrintCircular(List* l){
	Node* n = l->first;
	Node* p = n->next;
	Node* antp = NULL;
	cout<< n->id<<endl;
	while(p != n){
		antp=p;
		p=p->next;
		cout<<antp->id<< endl;
	}
	
	
}
List* listMakeCircular(List* l){
	Node* p = l->first;
	Node* antp=NULL;
	while(p != NULL){
		antp=p;
		p=p->next;
	}
	antp->next=l->first;
	//listPrint(l);
	//listPrintCircular(l);
	return l;
}
void listaN(List* l){
	Node* n = l->first;
	Node* p = n->next;
	Node* antp =NULL;
	while(p != l->first){
		antp=p;
		p=p->next;
	}
	antp->next=NULL;
	listPrint(l);
	
	
}
void listJoin(List* l1, List* l2){
	Node* n = l1->first;
	Node* z = l1->first;
	Node* t = l2->first;
	Node* antn=NULL;
	while(n != NULL){
		antn=n;
		n=n->next;
	}
	antn->next=t;
	l2->first=z;
	listPrint(l1);
	listPrint(l2);
	
	
}

List* listFromArray(int v[], int n){
	List* l = listCreate();
	Node* n = l->first;
	int i = 0;
	while(n != NULL){
		n->id=v[i];
		i++;
		n=n->next;
	}
	listPrint(l);
	
}
int main(){
	List* l1 = listCreate();
	List* l2 = listCreate();
	listInsertAfter(l1, 4);
	listInsertAfter(l1, 1);
	listInsertAfter(l1, 5);
	listInsertAfter(l2, 1);
	listInsertAfter(l2, 1);
	listInsertAfter(l2, 1);
//	listJoin(l1,l2);
	int v[]={1,2,3,4};
	int n = 4;
	listFromArray(v,n);	
//	List* x = listMakeCircular(l1);
//	listaN(x);
//	listInsertSortedDesc(l1, 7);
	
	
	//ordena(l1);
	//listRemove(l1,1);
	//listPrint(l1);
}
