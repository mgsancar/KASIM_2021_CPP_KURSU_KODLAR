/***********************************************************************************/
					/*reference semantic*/
/***********************************************************************************/

#include <iostream>
int main()
{
	int x = 10;
	int y = 45;

	int* p = &x;
	// *p demek x demek
	std::cout << "*p =" << *p << "	" << "x = " << x << "\n";

	int& r = x;
	// art�k r demek x demek
	std::cout << "r =" << r << "	" << "x = " << x << "\n";

	++r; //++x
	std::cout << "r =" << r << "	" << "x = " << x << "\n";

	r = y; //x = y ;
	std::cout << "r =" << r << "	" << "x = " << x << "\n";
}

/***********************************************************************************/

int main()
{
	int x = 10;
	int& r = x;	//copy initialization
	int& r1{ x };	//brace initialization
	int& r2(x);     //direct initialization

	/*dinamik �m�rl� nesnelerede referans al�nabilir. */
	int* p = new int;
	int& r = *p;

}
/***********************************************************************************/
int main()
{
	int x = 10;
	int& r = x;	//buradaki & bir operator degil declarator.

	int* p = &r; //buradaki * bir operator de�il bir declarator ve buradaki & bir operat�r(address of)

}
/***********************************************************************************/

int main()
{
	/*--------------------------------------------------------
	*	references must be initialized
	*	references cannot be default initialized
	---------------------------------------------------------*/

	double dval = 2.43;
	int& r = dval;	//gecersiz
	int* p = &dval; //ge�ersiz

	unsigned iny x = 10;
	int& r = x;	//ge�ersiz ayn� t�rden olmak zorunda 

	int& r = 10; //ge�ersiz	ilk de�er veren ifade L value expression olmak zorunda 10 bir PR value expression'd�r.

}

/***********************************************************************************/
int main()
{
	int a[]{ 1, 2, 3, 4 };
	int* p = a;		//ge�erli
	int& r1 = a[2];	//ge�erli
	int& r2 = *p;	//ge�erli		 
}

/***********************************************************************************/
#include <iostream>
int main()
{
	int x = 10;
	int* p{ &x };

	int*& r = p;	//r demek p demek. p'nin t�r� int* 

	++* r;
	std::cout << " x = " << x << '\n';
}

/***********************************************************************************/

int main()
{
	int x = 10;
	int* p = &x;
	int** ptr = &p;	/*pointer to pointer var.*/

	/*dogrudan reference to reference yok*/
	int y = 20;
	int& r1 = y;	//r1 demek y demek
	int& r2 = r1;   //r2 demek de y demek
}

/***********************************************************************************/

#include <iostream>
int main() {

	int x = 10;
	int& r1 = x;
	int& r2 = r1;
	int& r3 = r2;

	++r1;
	++r2;
	++r3;
	std::cout << " x = " << x << '\n';
}

/***********************************************************************************/
int main()
{
	/*bir diziye referans olu�turulabilir mi ?*/
	/* evet */
	int ar[]{ 1, 2, 3, 4, 5 }; // ar'nin t�r� ar[5]

	int(*p)[5] = &ar;	/*pointer to array*/
	/* (*p) demek a demek */

	int(&r)[5] = ar;
	/*r a'n�n yerine ge�en bir isim*/

	r[3] = 34; //ar[3] = 34;

	int* ptr = r;	//array decay	
	//int *ptr = a;	//array decay

}
/***********************************************************************************/
int main()
{
	int ar[]{ 1, 2, 3, 4, 5 }; // ar'nin t�r� ar[5]

	int(&r)[5] = ar;
	auto& r = ar;	//oto type deduction

}
/***********************************************************************************/
int main()
{
	int ar[]{ 1, 2, 3, 4, 5 }; // ar'nin t�r� ar[5]

	/*dizinin ilk elemanina pointer ve reference alma*/
	int* p = ar;
	int* p2 = &ar[0];
	int& r1 = *ar;
	int& r2 = ar[0];

	/*diziye reference alma*/
	int(&r3)[5] = ar;

}
/***********************************************************************************/
#include <iostream>
/*bir fonksiyonun parametresinin reference olmas� yada pointer olmas� assembly kodunu de�i�tirmez*/
/*call by reference*/

/*bir fonksiyonun parametresinin reference olmas�*/
void bar(int& r)
{
	r = 888;
}

/*bir fonksiyonun parametresinin pointer olmas�*/
void func(int* ptr)
{
	*ptr = 999;
}

int main()
{
	int ival{ 3 };
	std::cout << "ival = " << ival << '\n';
	func(&ival);
	std::cout << "ival = " << ival << '\n';

	int g{ 13 };
	std::cout << "ival = " << ival << '\n';
	bar(g);
	std::cout << "ival = " << ival << '\n';
}
/***********************************************************************************/
#include <iostream>
/*call by value*/
void foo(int x)
{
	x = 999;
}

/*call by reference*/
void bar(int& x)
{
	x = 888;
}
int main()
{
	int ival{ 3 };
	std::cout << "ival = " << ival << "\n";
	foo(ival);
	std::cout << "ival = " << ival << "\n";

	bar(ival);
	std::cout << "ival = " << ival << "\n";
}
/***********************************************************************************/
#include <iostream>
/*nesnelerin de�erlerini takas eden fonksiyonu pointer semantigi kullanarak yap�lmas�*/
void swap(int* p, int* q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}
int main()
{
	int a = 456, b = 678;
	std::cout << "a = " << a << "  b=" << b << "\n";
	swap(&a, &b);
	std::cout << "a = " << a << "  b=" << b << "\n";
}
/***********************************************************************************/
#include <iostream>
/*iki nesnenin degerini takas eden fonksiyonu reference semantigi kullanarak yapilmasi*/
void swap(int& p, int& q)
{
	int temp = p;
	p = q;
	q = temp;
}
int main()
{
	int a = 456, b = 678;
	std::cout << "a = " << a << "  b=" << b << "\n";
	swap(a, b);
	std::cout << "a = " << a << "  b=" << b << "\n";
}
/***********************************************************************************/

#include <iostream>
int g = 10;

int* foo(void)
{
	//code
	return &g;
}


int main()
{
	int* p = foo();
	std::cout << " g = " << g << "\n";

	*p = 999;

	std::cout << " g = " << g << "\n";
}
/***********************************************************************************/
#include <iostream>
int g = 10;

int* foo(void)
{
	//code
	return &g;
}


int main()
{
	int* p = foo();
	std::cout << " g = " << g << "\n";

	*foo() = 999;	//operator onceligi kurallar�na gore i�erik operatorun operan� foo() ifadeside g nesnesinin adresini dondurdugu i�in
					//*foo() adresindeki nesneye eri�mi� olduk

	std::cout << " g = " << g << "\n";
}
/***********************************************************************************/
int* scan_int(void)
{
	int x;
	printf("bir tam sayi giriniz: ");
	scanf("%d", &x);

	return &x; //hayat� biten bir nesnenin (x'in) adresini donduruyoruz undefined behavior
}

/***********************************************************************************/

#include <iostream>
int g = 10;

int& foo(void)
{
	//code
	return g;
}


int main()
{
	std::cout << " g = " << g << "\n";
	int x = foo(); // burada x demek g demek degil cunku x bir reference degil.
	x = 777;
	std::cout << " g = " << g << "\n";
	int& r = foo(); // fonksyion cagr� ifadesi bir L value expression (foo()) oldugundan bir reference baglayabildik
	/*c++ dilinde geri d�n�� t�r� bir sol taraf referans t�r� olan fonksiyonlara yap�lan cagr� ifadeleri L value expression'dir*/
	++r;
	std::cout << " g = " << g << "\n";
}

/***********************************************************************************/
/*otomatik omurlu bir nesnenin adresini degistirmek yanl�� ise, otomatik omurlu bir nesneye referans donen bir fonksiyonda
tamamen ayn� sek�lde yanl��. undefined behaviour*/
int& foo(int x)
{
	++x;
	return x;	//undefined behaviour. otomatik �m�rl� nesneni dondurmesi 
}

int* func(int x)
{
	++x;
	return &x; //undefined behaviour. otomatik �m�rl� nesneni dondurmesi 
}

/***********************************************************************************/
/*
fonksiyonun geri d�n�� de�eri L value reference(sol taraf referans) olacaksa a�a��daki senaryolardan birinin olmas� gerekir;
a ) statik �m�rl� bir nesneye referans d�nebilir.
i)global de�i�kenler
ii) statik yerel de�i�kenler
iii) string literalleri

b) dinamik �m�rl� bir nesneye referans d�nebilir.

c) ca��ran koddan ald��� nesneye referans d�nebilir.A��a��daki kod blo�unda oldugu gibi.
*/
#include <iostream>
int& foo(int& r)
{
	++r;
	return r;
}

int main() {
	int x = 20;
	int& r = foo(x);

	std::cout << " r = " << r << "\n";
	r *= 2;
	std::cout << " r = " << r << "\n";

}
/***********************************************************************************/
/* yukar�daki kod blogunun pointer semantigi kullan�larak yaz�lmas� */
#include <iostream>
int* foo(int* r)
{
	++* r;
	return r;
}

int main() {
	int x = 20;
	int* r = foo(&x);

	std::cout << " *r = " << *r << "\n";
	*r *= 2;
	std::cout << " r = " << *r << "\n";

}
/***********************************************************************************/
/*Eray �INAR*/