#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <stack>

using namespace std;

//=======================================================================================================
/**
 * ESTRUTURA DA LISTA
 * A lista apenas aponta para o primeito elemento (List->first)
 * Cada elemento (Node) aponta para o próximo pelo campo (Node->next)
 */

struct Node {
    int id;
    Node* next;
};

struct List {
    Node* first;
};

/**
 * OPERACOES DA LISTA
 */

List* listCreate(){
    List* l = new List;
    l->first = NULL;
    return l;
}

//INSERE ELEMENTOS NA LISTA ENCADEADA
void listInsertFirst(List* l, int e) {
    Node* n = new Node;
    n->id = e;
    n->next = l->first;
    l->first = n;
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
    /*
    for (Node* p = l->first; p != NULL; p = p->next) {
        cout << p->id << " ";
    }
    */
}
//=======================================================================================================


int buscaBinaria(string v[], int n, string target) {
    int i = 0;
    int f = n-1;
    while (i <= f) {
        int m = (i+f)/2; // meio
        if (target == v[m]) {
            return m; // devolve posicao do elemento
        } else {
            if (target > v[m]) {
                i = m + 1;
            } else {
                f = m - 1;
            }
        }
    }
    return -1; // nao encontrou o elemento
}

void selectionSort(int v[], int n) {
    for (int i = 0; i < n; i++) {
        int maior = v[i];
        for (int j = i+1; j < n; j++) {
            if (v[j] < v[maior]) {
                maior = j;
            }
        }
        // troca
        int temp = v[i];
        v[i] = v[maior];
        v[maior] = temp;
    }
}

void bubbleSort(string v[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (v[j] > v[j+1]) {
                string temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

template<typename T>
void printArray(T v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


//BUSCA BINÁRIA EM UM VECTOR DE INTEIROS
bool buscarBinaria(vector<int>& vec, int target){
     int i=0;
    int f=vec.size()-1;
    while(i<=f){
        int meio = (i+f)/2;
        if(target==vec[meio]){
            return meio;
        }else{
            if(target>vec[meio]){
                i = meio+1;
            }else{
                f = meio-1;
            }
        }

    }
    return false;

}

void selectionSortInt(int* v, int n, bool order){
    for(int i=0; i<n; i++){
        int maior=i;
        if(order){
                for (int j = i+1; j < n; j++){
                    if(v[j]<v[maior]){
                        maior=j;
                    }
                }
                //OCORRE A TROCA PARA ORDENAÇÃO NA ORDEM CRESCENTE O ARRAY
        }else{
            for (int d=i+1; d<n; d++){
                if(v[d]>v[maior]){
                    maior=d;
                }
            }
        }
        int temp = v[i];
        v[i] = v[maior];
        v[maior] = temp;
    }
}


//ORDENA QUALQUER TIPO DE VETOR
template<typename T>
void BubbleSortT(T vec[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(vec[j]>vec[j+1]){
                T temp=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]= temp;
            }
        }
    }
    printArray(vec, n);
}


int selectionFind(int* v, int n, int e){
    for(int i=0; i<n; i++){
        int maior=i;
        for(int j=i+1; j< n; j++){
            if(v[j]<v[j+1]){
                maior=j;
            }
        }
        // troca
        int temp = v[i];
        v[i] = v[maior];
        v[maior] = temp;

        int in=0;
        i= n-1;
        while(in<=i){
            int m= (in+i)/2;
            if(e==v[m]){return m; }
            else{
                if(e>v[m]){in= m+1;}
                else{i=m-1; }
            }
        }
    }
    return -1;
}

//SABERO O TAMANHO DA LISTA ENCADEADA
int listSize(List* l){
    int size=0;
    Node* p= l->first;
    while(p!=NULL){
        size++;
        p=p->next;
    }
    //cout<<"TAMANHO DA LISTA ENCADEADA:"<<size<<endl;
    return size;

}

//ORDENAR UMA LISTA ENCADEADA UTLLIZANDO OS ID'S
void listSelectionSort(List* l){

    Node* p= l->first;
    Node* prox= p->next;

    int posMenor=0;
    int tamLista=0;

    while(p!=NULL){
        tamLista++;
        p=p->next;
    }


    int pos=0;
    int menor = 19999999;
    for(int i = 0; i<tamLista; i++){
        pos=i;
        menor = 19999999;
//        p=l->first;

        p=l->first;
        for(int j=0; j<i; j++){
           p=p->next;
        }

        while(p!=NULL){
            if(p->id<menor){
                menor=p->id;
                posMenor=pos;

            }
            pos++;
           p=p->next;
        }
        cout<<"valor de menor:"<<menor<<"  posMeno:"<<posMenor<<endl;
        p=l->first;
        for(int j=0; j<i; j++){
           p=p->next;
        }

        int aux=p->id;
        p->id=menor;

        p=l->first;
        for(int x=0; x<posMenor; x++){
            p=p->next;
        }
        p->id=aux;

    }
}



// TESTES
int main () {
    cout<<"LISTA ENCADEADA"<<endl;
    List* l1=listCreate();

    listInsertFirst(l1, 6);
    listInsertFirst(l1, 5);
    listInsertFirst(l1, 7);
    listInsertFirst(l1, 3);
    listInsertFirst(l1, 1);

    listPrint(l1);
//    listSize(l1);
    listSelectionSort(l1);
    listPrint(l1);

//=======================================================================================================
    // BUBBLE SORT
    string v[] = {"John", "Ada", "Leon", "Mako", "Akira", "Barney", "Chris", "Han", "Zanty"};
    bubbleSort(v, 9);
    cout<<endl;
//=======================================================================================================

    cout << "BUBBLE SORT: ";
    printArray(v, 9);

    cout<<endl;
//=======================================================================================================

    // BUSCA BINÁRIA
    string target = "John";
    cout << "BINARY SEARCH FOR " << target << ": ";
    cout << buscaBinaria(v, 9, target) << endl;
    cout<<endl;
//=======================================================================================================
    cout<<"SELECTION SORTE CRESCENTE"<<endl;
    // SELECTION SORT
    int x[] = {6,5,4,3,2,1,0};
    selectionSort(x, 7);

    cout << "SELECTION SORT: ";
    printArray(x, 7);
    cout<<endl;
//=======================================================================================================
    //BUSCA BINARIA EM VECTOR DE INTEIROS
    int size = 10;
    vector<int> vec1;
    for (int i = 0; i < size; i++){vec1.push_back(i); }

    if(buscarBinaria(vec1, 6)){cout<<"NUMERO ENCONTRADO"<<endl; }
    else{ cout<<"NEMERO NAO ENCONTRADO"<<endl; }
//=======================================================================================================

    cout<<endl;
    int tam=5;
    int vetorParaOrdenacao[tam];
    cout<<"SELECTION SORTE CRESCENTE E DECRESCENTE"<<endl;
    for(int i=0; i<tam; i++){
        vetorParaOrdenacao[i]=rand()%10;
    }
    selectionSortInt(&vetorParaOrdenacao[0], tam, 0);
    //PRINT ARRAY ORDENADO DECRESCENTE
    printArray(vetorParaOrdenacao, tam);
    selectionSortInt(&vetorParaOrdenacao[0], tam, 1);
    //VETOR ORDENADO CRESCENTE
    printArray(vetorParaOrdenacao, tam);

//=======================================================================================================
    cout<<endl;
    cout<<"ORDENACAO DE QUALQUER TIPO DE VETOR"<<endl;
    string vetorString[]={"Lauriana\n", "Jhaspers\n", "Simone\n", "Haynara\n", "Francinete\n", "Airton\n"};
    int vetorInteiros[]={rand()%10, rand()%10, rand()%10, rand()%10, rand()%10, rand()%10};
    BubbleSortT(vetorInteiros, 6);//ORDENADO UM VETOR DE INTEIROS USANDO TEMPLATE
    BubbleSortT(vetorString, 6);// ORDENADO UM VETOR DE STRING USANDO TEMPLATE

//=======================================================================================================
    cout<<endl;
    cout<<"BUSCA EM VETOR ORDENADO POR SELECTION SORT"<<endl;
    int vetSelFin[tam];
    for(int i=0; i<tam; i++){
        vetSelFin[i]=rand()%10;
        cout<<vetSelFin[i]<<" ";
    }
    selectionSort(vetSelFin, tam);
    cout<<endl;
    int alvo=5;
    cout<<"ELEMENTO A SER BUSCADO:"<<alvo<<endl;
    cout<<selectionFind(&vetSelFin[0], tam, alvo)<<endl;
//=======================================================================================================

    return 0;
}
