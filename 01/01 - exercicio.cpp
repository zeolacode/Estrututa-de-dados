#include <iostream>
using namespace std;

int buscar ( string gts, char  x){
	for( int i = 0; i<= gts.size(); i++){
		if(gts[i]== x)
			return i;
	}
}
int main (){
	string frase = "pedro zeola zlopes";
	
	cout<< buscar(frase, 'z')<<endl;
}
