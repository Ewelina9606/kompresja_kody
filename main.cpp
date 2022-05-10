#include <iostream>
#include <string>

int main() {

	std::string tab[15] = { "0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111" };
	std::string tab2[15] = { "1","10","11","100","101","110","111","1000","1001","1010","1011","1100","1101","1110","1111" };
	std::string tab_C1[15] = { "1","01","001","101","0001","1001","0101","00001","10001","01001","00101","10101","000001","100001","010001" };
	std::string slowo;
	std::string znak;
	std::string alf;
	std::string ciag;
	std::string kod;

	int ilosc_jedynek = 0;
	char znak2;
	int liczba;
	int ilosc_bitow = 0;
	bool flag = 0;
	int funkcja;
	int kodowanie;
	std::cout << "Typ kodowania:" << std::endl;
	std::cout << "1. kod unarny" << std::endl;
	std::cout << "2. kod binarny" << std::endl;
	std::cout << "3. kod gamma-Eliasa" << std::endl;
	std::cout << "4. kod Frankela-Kleina C1" << std::endl;
	std::cin >> kodowanie;
	std::cout << "Chcesz kodowac (1) czy dekodowac (2) ?" << std::endl;
	std::cin >> funkcja;
	std::cout << "Podaj ciag znakow" << std::endl;
	std::cin >> alf;
	
	int N = alf.length();
	
	// kod unarny
	if (kodowanie == 1) {
		if (funkcja == 1) {
			for (int i = 0; i < N; i++) {
				if (alf[i] == 'A' || alf[i] == 'B' || alf[i] == 'C' || alf[i] == 'D' || alf[i] == 'E' || alf[i] == 'F') {
					znak2 = alf[i];
					liczba = (int)znak2;
					liczba = liczba - 55;
					for (int j = 0; j < liczba - 1; j++) {
						kod += '1';
					}
					kod += '0';
				}
				else {
					znak = alf[i];
					liczba = std::stoi(znak);
					for (int j = 0; j < liczba - 1; j++) {
						kod += '1';
					}
					kod += '0';
				}
			}
			std::cout << kod;
		}
		else {
			for (int i = 0; i < N; i++) {
				if (alf[i] != '0') {
					ilosc_jedynek++;
				}
				else {
					if (ilosc_jedynek >= 9) {
						ciag += (char)(ilosc_jedynek + 1 + 55);
						ilosc_jedynek = 0;
					}
					else {
						ciag += std::to_string(ilosc_jedynek + 1);
						ilosc_jedynek = 0;
					}
				}
			}
			std::cout << ciag;
		}
	}
	// kod binarny
	if (kodowanie == 2) {
		if (funkcja == 1) {
			for (int i = 0; i < N; i++) {
				if (alf[i] == 'A' || alf[i] == 'B' || alf[i] == 'C' || alf[i] == 'D' || alf[i] == 'E' || alf[i] == 'F') {
					znak2 = alf[i];
					liczba = (int)znak2;
					liczba = liczba - 55;
					kod += tab[liczba-1];
				}
				else {
					znak = alf[i];
					liczba = std::stoi(znak);
					kod += tab[liczba-1];
				}
			}
			std::cout << kod << std::endl;
		}

		if (funkcja == 2) {
			for (int i = 0; i < N; i++) {
				if (slowo.length() != 4) {
					slowo += alf[i];
				}
				if(slowo.length()==4) {
					for (int z = 0; z < 15; z++) {
						if (slowo == tab[z]) {
							if (z >= 9) {
								ciag += (char)(z+1+55);
								slowo = "";
							}
							else {
								ciag += std::to_string(z + 1);
								slowo = "";
							}
						}
					}
				}
			}
			std::cout << ciag << std::endl;
		}
	}
	// kod gamma-eliasa
	if (kodowanie == 3) {
		if (funkcja == 1) {
			for (int i = 0; i < N; i++) {
				if (alf[i] == 'A' || alf[i] == 'B' || alf[i] == 'C' || alf[i] == 'D' || alf[i] == 'E' || alf[i] == 'F') {
					znak2 = alf[i];
					liczba = (int)znak2;
					liczba = liczba - 55;
				}
				else {
					znak = alf[i];
					liczba = std::stoi(znak);				
				}
				ilosc_bitow = tab2[liczba - 1].length() -1 ;
				for (int z = 0; z < ilosc_bitow; z++) {
					kod += '0';
				}
				kod += tab2[liczba - 1];
			}
			std::cout << kod << std::endl;
		}
		if (funkcja == 2) {
			for (int i = 0; i < N; i++) {
				if (alf[i] == '0' && flag==0) {
					ilosc_bitow++;
				}
				else {
					flag = 1;
					if (slowo.length() != (ilosc_bitow + 1)) {
						slowo += alf[i];
					}
					if(slowo.length()== (ilosc_bitow + 1)) {
						for (int z = 0; z < 15; z++) {
							if (slowo == tab2[z]) {
								if (z >= 9) {
									ciag += (char)(z + 1 + 55);
									slowo = "";
									ilosc_bitow = 0;
									flag = 0;
								}
								else {
									ciag += std::to_string(z + 1);
									slowo = "";
									ilosc_bitow = 0;
									flag = 0;
								}
							}
						}
					}
				}
			}
			std::cout << ciag;
		}
	}
	// kod frankela-kleina C1
	if (kodowanie == 4) {
		if (funkcja == 1) {
			for (int i = 0; i < N; i++) {
				if (alf[i] == 'A' || alf[i] == 'B' || alf[i] == 'C' || alf[i] == 'D' || alf[i] == 'E' || alf[i] == 'F') {
					znak2 = alf[i];
					liczba = (int)znak2;
					liczba = liczba - 55;
				}
				else {
					znak = alf[i];
					liczba = std::stoi(znak);
				}
				kod += tab_C1[liczba - 1];
				kod += "1";
			}
			std::cout << kod << std::endl;
		}
		if (funkcja == 2) {
			for (int i = 0; i < N; i++) {
				if (alf[i] == '1' && alf[i + 1] == '1') {
					slowo += alf[i];
					for (int z = 0; z < 15; z++) {
						if (slowo == tab_C1[z]) {
							if (z >= 9) {
								ciag += (char)(z + 1 + 55);
								slowo = "";
							}
							else {
								ciag += std::to_string(z + 1);
								slowo = "";
							}
						}
					}
					i++;
				}
				else {
					slowo += alf[i];
				}
			}
			std::cout << ciag;
		}
	}
	return 0;
}