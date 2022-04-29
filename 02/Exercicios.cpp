#include <iostream>
using namespace std;
struct List {
    static const int MAX = 10;
    int size = 0;
    int data[MAX];
};
int listInsertLast(List* l, int e) {
    if (l->size >= l->MAX) {
        cout << "Lista Cheia" << endl;
        return -1;
    }
    // insere o elemnto na ultima posicao da lista
    l->data[l->size] = e;
    l->size++;
    return 0;
}
List* listCreate() {
    List* l = new List;
    return l;
}
int listRemoveLast(List* l) {
    if (l->size <= 0) {
        cout << "Lista Vazia" << endl;
        return -1;
    }
    l->size=0;
    return 0;
}
int listRemoveLast(List* l, int n){
	if (l->size <= 0) {
        cout << "Lista Vazia" << endl;
        return 0;
    }
    l->size=l->size-n;
    return 0;
}
void listPrintReverse(List* l){
	cout << "LISTA SEQUENCIAL: " << l->size << endl;
		for (int i = l->size; i>0; i--){
			cout << l->data[i-1]<< " ";
		}
}
bool listContains(List* l, int e){
	//int a = l->size;
	for(int i =0; i<l->size; i++){
		if(l->data[i]==e){
		return true;	}
	}
	return false;
}
bool ListEquals(List* l1, List* l2){
	if(l1->size==l2->size){
		for(int p=0; p<= l1->size; p++){
		if(l1->data[p] == l2->data[p]){
		}
	else if(p == l1->size)
		return true;	
	} }
		else 
		 return false;
	
}
void ListInsertAll(List* l,int v [], int n){
	for(int i=0; i<n; i++){
		v[i]= rand() % 10;
	}
	for(int j = l->size; j< l->MAX; j++){
		int r = 0;
		l->data[j]= v[0];
		l->size++;
		r++;
	}
}
bool listCheckSorted(List* l){
	for(int i =0; i< l->size; i++){
		if(l->data[i]> l->data[i+1]){
			return false;
		}
		else if(l->data[i] < l->data[i-1]){
		} else if(i == l->size){
			return true;
		}
	}
}
//////////////////////////////////////////////////


////////////////////////////////////////////////
void listReverSelf(List* l){
	cout << "lista reversa 2:"<< ;
		for( int i= 0; i < l->size; i++){
			int aux = l->data[i];
			int t = l->data[l->size-i-1];
			l->data[l->size]=t;
		}
}
List* Concat(List* l1, List* l2){
	List* l3 = listCreate();
	if((l1->size+l2->size) < l3->MAX)
		for(i=0; i<= (l1->size+l2->size); i++){
			int b = l1->data[i];
			int c = l2->data[i];
			l3->data[l3->size] = b;
			l3->size++
			l3->data[l3->size] = c;
			l3->size++;
		}
}
List* listMerge(list* l1,list* l2){
	if(l1->size+l2->size > l1->MAX){
		return NULL;
		int i=0; j=0;
		list* l3 = listCreate();
	while(i< l1->size && j<l2->size){
		if(l1->data[i]<l2->data[j]){
			listInsortlast(l3,l1->data[i]);
			i++
		}else{
			listInsortlast(l3,l2->data[j])
			j++;
		}
		
	}
	while(i< l1->size){
		listInsortlast(l3,l1->data[i]);
		i++;
	}
	}
}


void listPrint(List* l) {
    cout << "LISTA SEQUENCIAL: " << l->size << endl;
    for (int i = 0; i < l->size; i++) {
        cout << l->data[i] << " ";
    }
    cout << endl;
}
int main (){
	List* l1 = listCreate();
    List* l2 = listCreate();
    
    listInsertLast(l1, 5);
    listInsertLast(l1, 10);
    listInsertLast(l1, 15);
	listInsertLast(l2, 2);
    listInsertLast(l2, 4);
    listInsertLast(l2, 6);
    ListEquals(l1, l2);
    


	//listPrint(l1);
    //listPrint(l2);
   
	
}

