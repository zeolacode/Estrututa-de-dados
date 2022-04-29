#include <iostream>
using namespace std;

int buscar ( string gts, char  x){
	int z;
	for( int i = 0; i<= gts.size(); i++){
		if(gts[i]== x){
		z=+i;	
		}
	}
	return z;
}
	int main (){
	string frase = "pedro zeola zlopesz";
	
	cout<< buscar(frase, 'z')<<endl;
}
