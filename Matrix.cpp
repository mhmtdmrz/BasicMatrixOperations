/*****************************************
* Matrix.cpp							 *
******************************************
* IDE : Visual Studio 2017				 *
* Yazar : Mehmet Demir�z				 *
* Deneyim 2: C++'a Giri� - II			 *
*****************************************/
#include "Matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;
/**
*\brief Matris Olu�turma Fonksiyonu
*@param matrix: olu�turmak istedi�imiz matrisi referans ediyor.
*@param rowSize: bellekte olu�turmak istedi�imiz matrisin sat�r say�s�
*@param columnSize: bellekte olu�turmak istedi�imiz matrisin kolon say�s�
*
*\brief (Matris verileri icin) �lk �nce i�leve g�nderilen sat�r say�s� kadar bellek ay�rd�k, sonra ayr�lan bellek i�in s�tun say�s�na g�re daha fazla bellek ay�rd�k. Son olarak, olu�turmak istedi�imiz matrisin sat�r ve s�tun say�s�ni istenen degerlere atadik.
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
*�lk �nce matrisin kolon kolonlar�ni sildiriyor daha sonra da sat�rlarini silme i�lemi yapiyor.
*\brief Matrisin kolon ve sat�r say�s�n� varsayilana yani -1'e datasini da 0 atiyor.
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
*\brief �stenen De�eri Matrise Atama Fonksiyonu
*@param matrix: elemanlari fonksiyona g�nderilen degere esit olacak matrisi referans ediyor.
*@param value: matrisin elemanlarini esitlemek istedi�imiz deger
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
*\brief Matrisi Random Matrisine E�itleme Fonksiyonu
*@param matrix: elemanlari fonksiyona g�nderilen dataya esit olacak matrisi referans ediyor.
*@param data: matrisin elemanlarini esitlemek istedi�imiz random sayilardan olusan matris.
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
*\brief Matris Yazd�rma Fonksiyonu
*@param matrix: Ekrana yazdirmak istedi�imiz matrisi referans ediyor.
*
*
*Fonksiyona g�nderilen matrisi ekrana yazdiriyor.
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
*@param matrix_left: i�lem yapacagimiz birinci matris
*@param matrix_right: i�lem yapacagimiz ikinci matris
*@param result: Toplama i�lemi yapildiktan sonra sonucun kaydedilecegi matris.
*
*\brief Fonksiyona g�nderilen iki matrisi toplayip sonucu sonuc matrisine atiyor.
*/
void Matrix_Addition(const Matrix & matrix_left, const Matrix & matrix_right, Matrix & result)
{
	Matrix_Allocate(result, matrix_left.rowSize, matrix_left.columnSize);
	for (int i = 0; i < result.rowSize; i++)
		for (int j = 0; j < result.columnSize; j++)
			result.data[i][j] = matrix_left.data[i][j] + matrix_right.data[i][j];
}
/**
*\brief Matris ��karma Fonksiyonu
*@param matrix_left: i�lem yapacagimiz birinci matris
*@param matrix_right: i�lem yapacagimiz ikinci matris
*@param result: Cikarma i�lemi yapildiktan sonra sonucun kaydedilecegi matris.
*
*\brief Fonksiyona g�nderilen iki matrisi cikartip sonucu sonuc matrisine atiyor.
*/
void Matrix_Substruction(const Matrix & matrix_left, const Matrix & matrix_right, Matrix & result)
{
	Matrix_Allocate(result, matrix_left.rowSize, matrix_left.columnSize);
	for (int i = 0; i < result.rowSize; i++)
		for (int j = 0; j < result.columnSize; j++)
			result.data[i][j] = matrix_left.data[i][j] - matrix_right.data[i][j];
}
/**
*\brief Matris �arp�m� Fonksiyonu
*@param matrix_left: i�lem yapacagimiz birinci matris
*@param matrix_right: i�lem yapacagimiz ikinci matris
*@param result: Carpma i�lemi yapildiktan sonra sonucun kaydedilecegi matris.
*
*\brief Fonksiyona g�nderilen iki matrisi carpip sonucu sonuc matrisine atiyor.
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
*\brief Matrisi Belirli Bir De�erle �arpma Fonksiyonu
*@param matrix_left: i�lem yapacagimiz matris
*@param scalarValue: Fonksiyona g�nderilen matrisle carpacagimiz skaler deger.
*@param result: Carpma i�lemi yapildiktan sonra sonucun kaydedilecegi matris.
*
*\brief Fonksiyona g�nderilen matris elemanlarini g�nderilen sayiyla carpip sonucu sonuc matrisine atiyor.
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
*\brief Matrisi Bir De�er �le B�lme Fonksiyonu
*@param matrix_left: i�lem yapacagimiz matris
*@param scalarValue: Fonksiyona g�nderilen matrisle bolecegimiz skaler deger.
*@param result: Bolme i�lemi yapildiktan sonra sonucun kaydedilecegi matris.
*
*\brief Fonksiyona g�nderilen matris elemanlarini g�nderilen sayiya bolup sonucu sonuc matrisine atiyor.
*/
void Matrix_Division(const Matrix & matrix_left, float scalarValue, Matrix & result)
{
	Matrix_Allocate(result, matrix_left.rowSize, matrix_left.columnSize);
	for (int i = 0; i < matrix_left.rowSize; i++)
		for (int j = 0; j < matrix_left.columnSize; j++)
			result.data[i][j] = matrix_left.data[i][j] / scalarValue;
}
/**
*\brief Matris Kolon Mod�l� Hesaplama Fonksiyonu
*@param matrix: Kolon modulu i�lemini uygulayacagimiz matrisi referans ediyor.
*@param result: Kolon modulu i�lemi sonucunu tutan matris.
*
*\brief Fonksiyona g�nderilen matrisin kolonlar�ndaki sayilari toplayip karekokunu hesaplayarak kolon modulunu buluyoruz.Sonucu result matrisine atiyoruz.
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
*@param matrix: i�lem uygulayacagimiz matrisi referans ediyor.
*@param power: kacinci dereceden kuvvet almak istedi�imizi belirtiyor.
*@param result: kuvvet alma i�lemi sonucunu tutan matris.
*
*\brief G�nderilen matrisin elemanlar�n�n istenen dereceden kuvvetini aldiriyor.
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
