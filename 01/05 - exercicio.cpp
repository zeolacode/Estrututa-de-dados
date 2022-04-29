#include <iostream>
using namespace std;

int inverter(char s){
	int z=0;
	string minuscula = "abcdefghijklmnopqrstuvwxyz";
	string maiuscula = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(int i=0; i<= minuscula.size(); i++){
		if(minuscula[i]==s){
		z=i;	
}}
cout << maiuscula[z] << endl;
}
int main (){
	char t = 'j';
	//cout<< inverter(t) <<endl;
	inverter(t);
}
