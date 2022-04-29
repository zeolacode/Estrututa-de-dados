#include <iostream>
using namespace std;

int* arrayConcat(int* v1, int n1, int* v2, int n2){
	int aux;
	int* v3 = new int [n1+n2];
	for(int i=0; i<n1; i++){
		v3[i]=v1[i];
	}
	for(int j=0; j<=(n1+n2); j++){
		v3[n1+j]=v2[j];
	}
	for( int i=0; i<n1+n2; i++ ){
                  for( int j=i+1; j<n1+n2; j++ ){
                       if( v3[i] > v3[j] ){
                           aux = v3[i];
                           v3[i] = v3[j];
                           v3[j] = aux;
                       }
                  }
           }
	
	
	
	for(int z=0; z<n1+n2; z++){
		cout << v3[z] <<endl;
	}
}


int main(){
	int v1[3]={10,9,6};
	int v2[4]={3,7,7,2};
	 arrayConcat(v1,3,v2,4);
	
}
