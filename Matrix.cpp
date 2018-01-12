/*****************************************
* Matrix.cpp							 *
******************************************
* IDE : Visual Studio 2017				 *
* Yazar : Mehmet Demiröz				 *
* Deneyim 2: C++'a Giriþ - II			 *
*****************************************/
#include "Matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;
/**
*\brief Matris Oluþturma Fonksiyonu
*@param matrix: oluþturmak istediðimiz matrisi referans ediyor.
*@param rowSize: bellekte oluþturmak istediðimiz matrisin satýr sayýsý
*@param columnSize: bellekte oluþturmak istediðimiz matrisin kolon sayýsý
*
*\brief (Matris verileri icin) Ýlk önce iþleve gönderilen satýr sayýsý kadar bellek ayýrdýk, sonra ayrýlan bellek için sütun sayýsýna göre daha fazla bellek ayýrdýk. Son olarak, oluþturmak istediðimiz matrisin satýr ve sütun sayýsýni istenen degerlere atadik.
*/
void Matrix_Allocate(Matrix& matrix, int rowSize, int columnSize)
{
	matrix.data = new float*[rowSize];
	for (int i = 0; i < rowSize; i++)
	{
		matrix.data[i] = new float[columnSize];
	}
	matrix.rowSize = rowSize;
	matrix.columnSize = columnSize;
}
/**
*\brief Matris Silme Fonksiyonu
*@param matrix: silinmek istenen matrisi referans ediyor.
*
*Ýlk önce matrisin kolon kolonlarýni sildiriyor daha sonra da satýrlarini silme iþlemi yapiyor.
*\brief Matrisin kolon ve satýr sayýsýný varsayilana yani -1'e datasini da 0 atiyor.
*/
void Matrix_Free(Matrix& matrix)
{
	for (int i = 0; i < matrix.rowSize; i++)
	{
		delete[] matrix.data[i];
	}
	delete[] matrix.data;
	matrix.rowSize = -1;
	matrix.columnSize = -1;
	matrix.data = 0;
}
/**
*\brief Ýstenen Deðeri Matrise Atama Fonksiyonu
*@param matrix: elemanlari fonksiyona gönderilen degere esit olacak matrisi referans ediyor.
*@param value: matrisin elemanlarini esitlemek istediðimiz deger
*
*\brief Bu fonksiyonda matrisin tum elemanlarina istenen deger ataniyor.
*/
void Matrix_FillByValue(Matrix& matrix, float value)
{
	for (int i = 0; i < matrix.rowSize; i++)
		for (int j = 0; j < matrix.columnSize; j++)
			matrix.data[i][j] = value;
}
/**
*\brief Matrisi Random Matrisine Eþitleme Fonksiyonu
*@param matrix: elemanlari fonksiyona gönderilen dataya esit olacak matrisi referans ediyor.
*@param data: matrisin elemanlarini esitlemek istediðimiz random sayilardan olusan matris.
*
*\brief Bu fonksiyonda matrisin tum elemanlarina elemanlari random sayilardan olusan ayni boyuttaki data matrisi elemanlari ataniyor.
*/
void Matrix_FillByData(Matrix & matrix, float ** data)
{
	for (int i = 0; i < matrix.rowSize; i++)
		for (int j = 0; j < matrix.columnSize; j++)
			matrix.data[i][j] = data[i][j];
}
/**
*\brief Matris Yazdýrma Fonksiyonu
*@param matrix: Ekrana yazdirmak istediðimiz matrisi referans ediyor.
*
*
*Fonksiyona gönderilen matrisi ekrana yazdiriyor.
*/
void Matrix_Display(const Matrix& matrix)
{
	cout << "MATRIX: " << matrix.rowSize << " x " << matrix.columnSize << endl;
	for (int i = 0; i < matrix.rowSize; i++)
	{
		for (int j = 0; j < matrix.columnSize; j++)
		{
			cout << setw(10) << matrix.data[i][j];
		}
		cout << endl;
	}
}
/**
*\brief Matris Toplama Fonksiyonu
*@param matrix_left: iþlem yapacagimiz birinci matris
*@param matrix_right: iþlem yapacagimiz ikinci matris
*@param result: Toplama iþlemi yapildiktan sonra sonucun kaydedilecegi matris.
*
*\brief Fonksiyona gönderilen iki matrisi toplayip sonucu sonuc matrisine atiyor.
*/
void Matrix_Addition(const Matrix & matrix_left, const Matrix & matrix_right, Matrix & result)
{
	Matrix_Allocate(result, matrix_left.rowSize, matrix_left.columnSize);
	for (int i = 0; i < result.rowSize; i++)
		for (int j = 0; j < result.columnSize; j++)
			result.data[i][j] = matrix_left.data[i][j] + matrix_right.data[i][j];
}
/**
*\brief Matris Çýkarma Fonksiyonu
*@param matrix_left: iþlem yapacagimiz birinci matris
*@param matrix_right: iþlem yapacagimiz ikinci matris
*@param result: Cikarma iþlemi yapildiktan sonra sonucun kaydedilecegi matris.
*
*\brief Fonksiyona gönderilen iki matrisi cikartip sonucu sonuc matrisine atiyor.
*/
void Matrix_Substruction(const Matrix & matrix_left, const Matrix & matrix_right, Matrix & result)
{
	Matrix_Allocate(result, matrix_left.rowSize, matrix_left.columnSize);
	for (int i = 0; i < result.rowSize; i++)
		for (int j = 0; j < result.columnSize; j++)
			result.data[i][j] = matrix_left.data[i][j] - matrix_right.data[i][j];
}
/**
*\brief Matris Çarpýmý Fonksiyonu
*@param matrix_left: iþlem yapacagimiz birinci matris
*@param matrix_right: iþlem yapacagimiz ikinci matris
*@param result: Carpma iþlemi yapildiktan sonra sonucun kaydedilecegi matris.
*
*\brief Fonksiyona gönderilen iki matrisi carpip sonucu sonuc matrisine atiyor.
*/
void Matrix_Multiplication(const Matrix & matrix_left, const Matrix & matrix_right, Matrix & result)
{
	Matrix_Allocate(result, matrix_left.rowSize, matrix_right.columnSize);
	for (int i = 0; i<matrix_left.rowSize; i++)
		for (int j = 0; j<matrix_right.columnSize; j++)
			result.data[i][j] = 0;
	for (int i = 0; i < matrix_left.rowSize; i++)
	{
		for (int j = 0; j < matrix_right.columnSize; j++)
		{
			for (int k = 0; k < matrix_left.columnSize; k++) {
				result.data[i][j] += matrix_left.data[i][k] * matrix_right.data[k][j];
			}
		}
	}
}
/**
*\brief Matrisi Belirli Bir Deðerle Çarpma Fonksiyonu
*@param matrix_left: iþlem yapacagimiz matris
*@param scalarValue: Fonksiyona gönderilen matrisle carpacagimiz skaler deger.
*@param result: Carpma iþlemi yapildiktan sonra sonucun kaydedilecegi matris.
*
*\brief Fonksiyona gönderilen matris elemanlarini gönderilen sayiyla carpip sonucu sonuc matrisine atiyor.
*
*/
void Matrix_Multiplication(const Matrix & matrix_left, float scalarValue, Matrix & result)
{
	Matrix_Allocate(result, matrix_left.rowSize, matrix_left.columnSize);
	for (int i = 0; i < matrix_left.rowSize; i++)
		for (int j = 0; j < matrix_left.columnSize; j++)
			result.data[i][j] = matrix_left.data[i][j] * scalarValue;
}
/**
*\brief Matrisi Bir Deðer Ýle Bölme Fonksiyonu
*@param matrix_left: iþlem yapacagimiz matris
*@param scalarValue: Fonksiyona gönderilen matrisle bolecegimiz skaler deger.
*@param result: Bolme iþlemi yapildiktan sonra sonucun kaydedilecegi matris.
*
*\brief Fonksiyona gönderilen matris elemanlarini gönderilen sayiya bolup sonucu sonuc matrisine atiyor.
*/
void Matrix_Division(const Matrix & matrix_left, float scalarValue, Matrix & result)
{
	Matrix_Allocate(result, matrix_left.rowSize, matrix_left.columnSize);
	for (int i = 0; i < matrix_left.rowSize; i++)
		for (int j = 0; j < matrix_left.columnSize; j++)
			result.data[i][j] = matrix_left.data[i][j] / scalarValue;
}
/**
*\brief Matris Kolon Modülü Hesaplama Fonksiyonu
*@param matrix: Kolon modulu iþlemini uygulayacagimiz matrisi referans ediyor.
*@param result: Kolon modulu iþlemi sonucunu tutan matris.
*
*\brief Fonksiyona gönderilen matrisin kolonlarýndaki sayilari toplayip karekokunu hesaplayarak kolon modulunu buluyoruz.Sonucu result matrisine atiyoruz.
*/
void Matrix_Column_Module(const Matrix& matrix, Matrix& result)
{
	Matrix_Allocate(result, matrix.columnSize, 1);
	float sum = 0;

	int i, j;
	for (i = 0; i < matrix.columnSize; i++)
	{
		for (j = 0; j < matrix.rowSize; j++)
		{
			sum = sum + matrix.data[j][i] * matrix.data[j][i];
		}
		result.data[i][0] = sqrt(sum);
	}
}
/**
*\brief Matris Kuvvet Alma Fonksiyonu
*@param matrix: iþlem uygulayacagimiz matrisi referans ediyor.
*@param power: kacinci dereceden kuvvet almak istediðimizi belirtiyor.
*@param result: kuvvet alma iþlemi sonucunu tutan matris.
*
*\brief Gönderilen matrisin elemanlarýnýn istenen dereceden kuvvetini aldiriyor.
*/
void Matrix_ElementPower(const Matrix& matrix, double power, Matrix& result)
{
	Matrix_Allocate(result, matrix.rowSize, matrix.columnSize);
	for (int i = 0; i < result.rowSize; i++)
	{
		for (int j = 0; j < result.columnSize; j++)
		{
			result.data[i][j] = pow(matrix.data[i][j], power);
		}
	}
}
