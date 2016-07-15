#include <iostream>
#include <string>

//Tablica z alfabetem
char alftab[26][26];
std::string alfabet= "abcdefghijklmnopqrstuvwxyz";

int checkPos(char k) {
	for(int i= 0;i< alfabet.length(); i++){
		if(k == alfabet[i]){
			return i;
		}
	}
	return -1;
}

std::string szyfrowanie(std::string tekst, std::string klucz){
	std::string szyfr= "";
		for(int i= 0; i< tekst.length(); i++){
			//if(i== 0){
			//	szyfr+= alftab[checkPos(tekst[0])][checkPos(klucz[0])];
			//}
			//else{
				szyfr+= alftab[checkPos(tekst[i% tekst.length()])][checkPos(klucz[i% klucz.length()])];
			//}
		}
		//printf("Szyfr maybe: %s\n", szyfr.c_str());
		return szyfr;
	}

int main() {
	
	//Now, what do I do...
	
	/*
	 * Pomysly na program
	 * - szyfr jakiegos rodzaju popatrz stare zadania
	 * 
	 * */
	
/*int i;

scanf("%d", &i);
printf("LOL: %d\n",i* 1000);
printf("Wow\n");
*/

//Szyfr Viegenera

std::string klucz, szyfr, deszyfr, slowojawne;
klucz = slowojawne = szyfr = deszyfr = "";

//inicjalizacja tablicy Trithemiusa
for(int i= 0; i<26; i++){
	for(int j= 0; j<26; j++){
		alftab[i][j]=alfabet[(j+ i)% 26];
	}
}

/*for(int i= 0; i<26; i++){
	printf("Rzad %d: ", i);
	for(int j= 0; j<26; j++){
		printf("%c", alftab[i][j]);
	}
	printf("\n");
}*/

//printf("Wynik to: %d", checkPos('s'));

printf("Prosze podac tekst do zaszyfrowania: ");
std::cin>> slowojawne;

printf("Prosze podac klucz: ");
std::cin>> klucz;

szyfr= szyfrowanie(slowojawne, klucz);

printf("Wynik szyfrowania to: %s\n", szyfr.c_str());
printf("Wynik deszyfrowania to: %s", deszyfr.c_str());

return 0;
}
