/*****************************************
* Matrix.h								 *
******************************************
* IDE : Visual Studio 2017				 *
* Yazar : Mehmet Demiröz				 *
* Deneyim 2: C++'a Giriþ - II			 *
*****************************************/
/**
*  \brief     Matris Ýþlemleri
*  \details   C++'a Giriþ - II
*  \author    Mehmet Demiröz
*  \version   1.2
*  \date      2017
*/
#pragma once
struct Matrix {
	int rowSize = -1;
	int columnSize = -1;
	float** data = 0;
};
void Matrix_Allocate(Matrix& matrix, int rowSize, int columnSize);
void Matrix_Free(Matrix& matrix);
void Matrix_FillByValue(Matrix& matrix, float value);
void Matrix_FillByData(Matrix& matrix, float** data);
void Matrix_Display(const Matrix& matrix);
void Matrix_Addition(const Matrix& matrix_left, const Matrix& matrix_right, Matrix& result);
void Matrix_Substruction(const Matrix& matrix_left, const Matrix& matrix_right, Matrix& result);
void Matrix_Multiplication(const Matrix& matrix_left, const Matrix& matrix_right, Matrix& result);
void Matrix_Multiplication(const Matrix& matrix_left, float scalarValue, Matrix& result);
void Matrix_Division(const Matrix& matrix_left, float scalarValue, Matrix& result);
void Matrix_Column_Module(const Matrix& matrix, Matrix& result);
void Matrix_ElementPower(const Matrix& matrix, double power, Matrix& result);




