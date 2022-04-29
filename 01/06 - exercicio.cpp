#include <iostream>
using namespace std;

int* createVector(int n, bool value) {
    int* vet = new int[n];
	if(value==true){
	
    for (int i = 0; i < n; i++) {
        vet[i] = i;
    }
    return vet;}
    	else 
    		for(int x=0,j=n-1; x<n, j>=0; x++, j--){
    			vet[x]=j;			}
    			return vet;
} 
void printVector(int vet[], int n) {
    cout << "\nVECTOR" << endl;
    for (int i = 0; i < n; i++) {
        cout << vet[i] << " ";
    }
    cout << endl;
}

int main(){
	int* vec1 = createVector(10, false);
	printVector(vec1, 10);
	
}
