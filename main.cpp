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
	int kit, kpos, tpos;
	kit= kpos= tpos= 0;
	
		for(int i= 0; i< tekst.length(); i++){
			kpos= checkPos(klucz[i% klucz.length()]);
			tpos= checkPos(tekst[i% tekst.length()]);
			
			if(tpos!= -1){
				szyfr+= alftab[tpos][kpos];
				kit++;
			}
			else{
				szyfr+= ' ';
				}
		}
		return szyfr;
}
	
std::string deszyfrowanie(std::string encode, std::string klucz){
	std::string deszyfr= "";
	for(int i= 0; i< encode.length(); i++){
		int kpos= checkPos(klucz[i% klucz.length()]);
		if(encode[i]!= ' '){
			for(int j= 0; j< 26; j++){
				if(alftab[kpos][j]== encode[i])
				deszyfr+= alfabet[j];
			}
		}
		else{
			deszyfr+= ' ';
		}
	}
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
std::getline(std::cin, slowojawne);

printf("Prosze podac klucz: ");
std::cin>> klucz;

szyfr= szyfrowanie(slowojawne, klucz);
deszyfr= deszyfrowanie(szyfr, klucz);

printf("Wynik szyfrowania to: %s\n", szyfr.c_str());
printf("Wynik deszyfrowania to: %s", deszyfr.c_str());

return 0;
}
