#include <iostream>
using namespace std;

struct List{
	static const int MAX = 10;
	int data[MAX];
};

List* listCreate(){
	List *l = new List;
	for(int i=0; i < 10; i++){
		l->data[i] = -1;
		cout << " " << l->data[i];
	}
	cout << " " << endl ;
	return l;
};

int listSize(List* l){
	for(int i=0; i < l->MAX; i++){
		if(l->data[i]==-1){
			cout << "o tamanho da lista e: " << i <<endl;
		return 0;
		}
	}
	cout << "sua lista esta cheia e seu tamanho é: " << l->MAX << endl;
	return 0;
};

int listInsert(List* l, int e){
	for(int s= 0; s<l->MAX; s++){
		if(l->data[s] == -1){
			l->data[s]=e;
			return 0;
		}
	}
	return 0;
};

int listRemove(List* l, int e){
	for(int i = 0; i<l->MAX; i++){
		if(l->data[i]==e){
			l->data[i]=-1;
		}
	cout << " " << l->data[i];
	}
	cout << " " << endl;
	return 0;
};

void listPrint(List* l){
	for(int i=0; i<l->MAX; i++){
	 cout << l->data[i] << " ";	
	}
};

void listDefrag(List* l){
	for(int i=0; i>l->MAX; i++){
		if(l->data[i]==-1){
			l->data[i] = l->data[i+1];
		}
	cout << l->data << " ";
	}
}


int main(){
	
}
