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

/* IDEA
 *  if result from checkpos == -1 leave it be and go to the next one, but then iterator will not be good for the klucz...
 * */
std::string szyfrowanie(std::string tekst, std::string klucz){
	std::string szyfr= "";
		for(int i= 0; i< tekst.length(); i++){
				szyfr+= alftab[checkPos(tekst[i% tekst.length()])][checkPos(klucz[i% klucz.length()])];
		}
		return szyfr;
}
	
std::string deszyfrowanie(std::string szyfr, std::string klucz){
	//std::string deklucz= "";
	std::string deszyfr= "";
		/*for(int i= 0; i< klucz.length(); i++){
				deklucz+= alftab[checkPos(klucz[i% klucz.length()])][checkPos(szyfr[i% szyfr.length()])];
		}*/
	
	for(int i= 0; i< szyfr.length(); i++){
		int kpos= checkPos(klucz[i% klucz.length()]);
		for(int j= 0; j< 26; j++){
			if(alftab[kpos][j]== szyfr[i]){
			deszyfr+= alfabet[j];}
		}
	}
		
		/*for(int i= 0; i< szyfr.length(); i++){
				deszyfr+= alftab[checkPos(szyfr[i% szyfr.length()])][checkPos(klucz[i% klucz.length()])];
		}*/
		return deszyfr;
	}

int main() {
//Szyfr Viegenera

std::string klucz, szyfr, deszyfr, slowojawne;
klucz = slowojawne = szyfr = deszyfr = "";

//inicjalizacja tablicy Trithemiusa
for(int i= 0; i<26; i++){
	for(int j= 0; j<26; j++){
		alftab[i][j]=alfabet[(j+ i)% 26];
	}
}

/* SPRAWDZENIE POPRAWNOSCI TABLICY TRITHEMIUSA
 * for(int i= 0; i<26; i++){
	printf("Rzad %d: ", i);
	for(int j= 0; j<26; j++){
		printf("%c", alftab[i][j]);
	}
	printf("\n");
}*/


printf("Prosze podac tekst do zaszyfrowania: ");
std::cin>> slowojawne;

printf("Prosze podac klucz: ");
std::cin>> klucz;

szyfr= szyfrowanie(slowojawne, klucz);
deszyfr= deszyfrowanie(szyfr, klucz);

printf("Wynik szyfrowania to: %s\n", szyfr.c_str());
printf("Wynik deszyfrowania to: %s", deszyfr.c_str());

return 0;
}
