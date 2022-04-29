#include <iostream>
using namespace std;

bool verifica (char c){
	string letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(int i=0; i<= letras.size(); i++){
		if(letras[i]==c){
			return true;
		}
		else 
		return false;
	}
	

}



int main (){
	char a = 'a';
	cout<<  verifica(a)<<endl;
}
