/***********************************************************************************/
						/* Auto type deduction*/
/***********************************************************************************/
int main() {
	/*auto ile default initialization yap�lamaz.*/
	auto x; //gecersiz.

	auto y = 12;  //copy init
	auto z{ 12 }; //brace init
	auto c(12);  //direct init
}
/***********************************************************************************/
int main() {
	auto x1 = 12; /*x1 t�r� int*/
	auto x2 = 3.4; /*x2 t�r� double*/
	auto x3 = 3.4L; /* x3'�n t�r� long double*/
	auto x4 = 'A'; /*x4 t�r� char*/
	auto x5 = nullptr; /* x5 t�r� nullptr_t*/
	auto x6 = 10 > 5; /*bool*/
}
/***********************************************************************************/

int main() {
	char c = 'A';

	auto x1 = c; /*x1 t�r� char*/
	auto x2 = +c; /*x2 t�r� int*/

}
/***********************************************************************************/
int main() {
	int x = 10;
	double d = 3.4;

	auto x = x > 5 ? 3 : d;  /*x t�r� double*/
}
/***********************************************************************************/
int main() {
	int x = 10;
	int& r = x;

	auto a1 = r; /* r'nin t�r� int & olmas�na kar��n referansl�k d��er. a'n�n t�r� int'dir*/

	const int y = 10;
	auto a2 = y;	/*referansl�k gibi const'da d��er. a nin t�r� int */

	const int& cr = x;
	auto a3 = cr;  /*const ve ref d�ser a3 t�r� yine int*/

}
/***********************************************************************************/
int main() {
	int a[] = { 1, 2, 3 };

	auto b = a; /*array decay olur b'nin t�r� (int*) */

}
/***********************************************************************************/
int main() {
	const int a[] = { 1, 2, 3 };

	auto b = a; /*b'nin t�r� const int* */

}
/***********************************************************************************/
int main() {

	auto x = "mesut"; // x'in t�r� const char * 

}
/***********************************************************************************/
int foo(int);
int main() {

	auto x = foo; // x't�r� int (*)(int) fonksiyon adresi t�r�.
	auto y = &foo; // x ve y nin t�rleri ayn�d�r.

}
/***********************************************************************************/
int main() {

	int a[10][20];

	auto x = a; // x'in t�r� int (*)[20] 

}
/***********************************************************************************/
/* auto &  */

int main() {

	int ival{};

	auto& x = ival; // auto ya kar��l�k gelen t�r int. x'in t�r� int & 

	const int ivec{};

	/*constluk dusmez nedeni auto& */
	auto& c = ivec; // autoya kars�l�k gelen t�r const int. c nin t�r� const int& 
}
/***********************************************************************************/
int main() {

	int a[10]{};


	auto& x = a; // auto kars�l�g� int[10] bu durumda x'in t�r� int (&x)[10] 
}
/***********************************************************************************/

int main() {

	auto& r = "veysel"; //autoya kars�l�k gelen t�r const char[7], r'nin t�r� const char (&r)[7]

}
/***********************************************************************************/
/*Eray �INAR*/