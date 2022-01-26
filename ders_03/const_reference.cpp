int main() {

	int a[] = { 0, 1, 3, };
	int(*p)[3] = &a; /*pointer to array. *p demek a dizisi demek*/
	int* ptr = a;	 /**ptr a dizisinin ilk eleman� */

	/*pointer aritmeti�ine bak�ld�g�nda ptr int kadar artarken p dizinin toplam boyutu kadar artar*/
	printf("%p %p\n", ptr, ptr + 1);
	printf("%p %p\n", p, p + 1);
}
/***********************************************************************************/
int main() {

	int a[] = { 1, 2, 3, 4 };
	int(*p)[4] = &a; /*pointer to array*/

	(*p)[2] = 99;
	int* ptr = *p;	//ptr demek a demek
}
/***********************************************************************************/
int main() {

	int a[] = { 1, 2, 3, 4 };
	int(*p)[4] = &a; /*pointer to array*/
	int* ptr;

	std::cout << "sizeof(*ptr) =" << sizeof(*ptr) << "\n";
	std::cout << "sizeof(*p) =" << sizeof(*p) << "\n";
}
/***********************************************************************************/

/***********************************************************************************/
					/*Const reference*/
/***********************************************************************************/
int main() {

	int x = 10;
	int* p = &x;

	const int* cp = &x;	//pointer to const int 
						//low level const 
	/* *cp'yi salt okuma ama�l� kullanabilirsiniz. */

	/*
		* void func(T *p);	mutater funtion, set function yada setter olarak adlanr�l�r bu fonksyionlar
		  out param

		* void foo(const T*p); accessor, getter, get function olarak adland�r�l�r bu fonksyionlar
		  input param
	*/
}
/***********************************************************************************/

#include <iostream>
/*const sol taraf referanslar�*/
/* const L value references*/
int main() {
	int x = 10;
	const int& r = x; //r demek x demek 

	int ival = r;	//r'yi set edilmedi, r salt access ama�l� kullan�ld�.
	ival = r + 3;

	r = 9;	//gecersiz r set edilemez.

}
/***********************************************************************************/

int main() {
	double d = 3.4;
	int x;
	x = d;	/*narrowing conversion deger kayb� yasanacakt�r.Derleyici uyar� mesaj� verir.*/

	int* p = &d; /*gecersiz. t�rlerin ayn� olmas� laz�m. C'de legal ancak yanl��*/
	int& r = d;	 /*gecersiz.*/
}
/***********************************************************************************/

int main() {

	int x = 10;
	double& r = x;	/*gecersiz. T�rlerin ayn� olmas� gerekir.*/

	const double& r = x;	//gecerli!!
	/*neden gecerli? derleyicinin �retti�i kod
	const double&r = x;
	{
		const double temp = x;
		const double &r = temp;
	}
	*/

}
/***********************************************************************************/

int main() {

	//L value reference'a R value expression ile ilk de�er verilmi�.
	//ancak biliyoruz ki reference nesneleri  l value expression ile ilk de�er verilir.
	int& r = 5;	//ge�ersiz

	const int& r = 5; //gecerli
	/*derleyicinin �retti�i kod.
	const int& r = 5;
	{
		const int temp = 5;
		const int &r = temp;
	}
	*/

}
/***********************************************************************************/

/*foo fonksiyonuna sadece L value  kategorisindeki ifadeler ile �a��rabilirim.*/
void foo(T&);

/*ancak bar fonksiyonunu hem L value hemde R value de�er kategorisindeki ifadeler ile �a��rabilirim.*/
void bar(const T&);

/***********************************************************************************/
void pswap(int** ptr1, int** ptr2)
{
	int* ptemp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = ptemp;
}

int main() {

	int x = 10, y = 20;
	int* p1 = &x, * p2 = &y;
	/*oyle bir fonksiyon olsun ki p1 ve p2 degiskenlerini swap etsin*/
	pswap(&p1, &p2);

}
/***********************************************************************************/
/*yukar�dak� kod blogunun reference semant�g� ile yaz�lmas�.*/
void pswap(int*& r1, int*& r2)
{
	int* ptemp = r1;
	r1 = r2;
	r2 = ptemp;
}

int main() {

	int x = 10, y = 20;
	int* p1 = &x, * p2 = &y;
	/*oyle bir fonksiyon olsun ki p1 ve p2 degiskenlerini swap etsin*/
	pswap(p1, p2);

}
/***********************************************************************************/
/*
Pointer semantigi ve reference semantigi farkl�l�klar�;
i) pointer to pointer var ancak reference to reference yok!
ii) pointer array olabilir ama reference array olamaz ileride bu ihtiyac�
C++ dilinde standart k�t�phanesi std::reference_wrapper bak�lacakt�r.
iii) nullptr var ancak null reference yok.
iv) referencelar rebindable de�ildir.referansa bir nesne bagland�g�nda scope boyunca baska bir nesne baglanamaz.
*/
/***********************************************************************************/
int foo(int);
int main() {
	/*fonksiyon pointer'�*/
	int (*fp)(int) = foo;

	/*fonksiyon reference'�*/
	int(&fpr)(int) = foo;
}
/***********************************************************************************/

int main() {

	int x = 10, y = 20;
	int* const p = &x; /*p baska bir nesneye baglanamaz.*/
	//p = &y; //gecersiz

}
/***********************************************************************************/
/*Eray �INAR*/