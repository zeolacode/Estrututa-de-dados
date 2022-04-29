#include <iostream>

using namespace std;

struct Node {
    int id;
    Node* next;
};
struct List {
    Node* first;
};

List* listCreate() {
    List* l = new List;
    l->first = NULL;
    return l;
}

void listInsertFirst(List* l, int e) {
    Node* n = new Node;
    n->id = e;
    n->next = l->first;
    l->first = n;
}

bool listEmpty(List* l){
    if (l->first == NULL) {
        cout << "\nERRO: Lista vazia\n" << endl;
        return true;
    }
	else 
	return false;
};

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
Node* listFind(List* l, int id){
	Node*p = l->first;
	int i=0;
	while(p !=NULL && i< id ){
		i++;
		p=p->next;
		}
			if(p==NULL){
			return NULL;
	}else{
		return p;
	}}
void listInsertAfter (List* l, int id){
	Node* n = new Node; //CRIAR NÓ
	Node* p; // PONTEIRO AUX
	p=l->first; // AUX-> INICIO DA LISTA
	n->id = id; // O NO CRIADO RECEBE OVALOR DE ID
	n->next=NULL; // para dar continuidade atribuimos null no while caso 
	Node* antp=NULL; // OUTRO VETOR AUX PARA AUCILIAR AO PERCORRER A LISTA..
	while(p !=NULL){ // PERCORENDO A LISTA
		antp=p;     // VETOR AUX RECEBE A POSI ATUAL
		p=p->next;  // ANDANDO NA LISTA 
	}
	if(antp==NULL){
	l->first=n;	
	}else
	antp->next=n;  // antp e o ultimo no o ponteiro q esta dentro do no representado por next vai apontar para o novo nó criado (n)
	

};

Node* listRemoveLast(List* l){
	Node* p; 
	p=l->first;
	Node* antp=NULL;
	Node* antpp=NULL;
	if(l->first!=NULL){
	while(p !=NULL){ 
		antpp=antp;
		antp=p;    
		p=p->next;	}
	antpp->next=NULL;}
	else {
	return NULL;}
}
bool listEquals(List* l1, List* l2){
	Node* n1 = l1->first;
	Node* n2 = l2->first;
	int t =listSize(l1);
	int z =listSize(l2);
	if(z != t){
		return false;
	}
	while(n1->next!=NULL && n2->next){
		if(n1->id != n2->id){
			return false;
		}
	n1=n1->next;
	n2=n2->next;
	}
	return true;
}
bool listCheckSorted(List* l){
	Node* p= l->first;
	Node* n= p->next;
	
	while(n != NULL){
		if(n->id < p->id){
		return false;
	}
	return true;
}}

void listPrintReverse(List* l){
	Node* p = l->first;
	int t = listSize(l);
	int vet[t];
	int o = listSize(l);
	while(p !=NULL && t>0){
		vet[t-1] = p->id;
		t--;
		p = p->next;
	
}
	for(int i=0; i<o; i++){
		cout<<vet[i]<<" ";
	} cout <<endl;
}
void listInsertAll(List* l, int v[], int n){
	for (int i=0; i<n; i++){
		listInsertAfter(l,v[i]);
	
	}
}
void listReverse(List* l){
	Node* n= l->first;
	Node* p = l->first;
	int t=listSize(l);
	int x=0;
	int v[t];
	while(p != NULL){
	v[t-1]=p->id;
	t--;
	p=p->next;	
	}
	while(n!=NULL){
	n->id=v[x];
	cout<<"t"<<endl;
	n=n->next;
	x++;	
	}	
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
List* listClone(List* l){
	Node* p = l->first;
	List* l3 = listCreate();
	while(p!=NULL){	
	listInsertAfter(l3,p->id);
	p=p->next;
	}
	return l3;
}
List* listConcat(List* l1, List* l2){
	List* x= listClone(l1);
	List* y= listClone(l2);
	Node* n=x->first;
	Node* antn=NULL;
	while(n!=NULL){
		antn=n;
		n=n->next;
	}
	antn->next=y->first;
	return x;
}

List* listMerge(List* l1, List* l2){
	Node* x=l1->first;
	Node* y=l2->first;
	List* l4 = listCreate();
	while(x!=NULL && y!=NULL){
		if(x->id < y->id){
			listInsertAfter(l4, x->id);
			x=x->next;
		}
		else{
			listInsertAfter(l4, y->id);
			y=y->next;
		}
	}
	if(x==NULL){
		while(y != NULL){
			listInsertAfter(l4, y->id);
			y=y->next;
		}
	}
	else {
		while(x != NULL){
		listInsertAfter(l4, x->id);
		x=x->next;
		}
	}
	listPrint(l4);
	return l4;
}


int main() {
   
    List* l1 = listCreate();
   List* l2 = listCreate();


listInsertAfter(l1, 1);
listInsertAfter(l1, 2);
listInsertAfter(l1, 3);
listInsertAfter(l1, 4);

listInsertAfter(l2, 1);
listInsertAfter(l2, 2);
listInsertAfter(l2, 3);
listInsertAfter(l2, 4);

//listPrintReverse(l1);
int v[]={1,2,3,4,5,6};	
//listInsertAll(l1,v, 6);	
//listReverse(l1);
//listClone(l1);
//List* t = listConcat(l1,l2);
//	listPrint(t);
listMerge(l1,l2);	
	return 0;
}
