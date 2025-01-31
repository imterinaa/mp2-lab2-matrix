// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
    const int SIZE = 3;

    TMatrix<int> a(SIZE), b(SIZE), c(SIZE);
    int i, j;

    setlocale(LC_ALL, "Russian");
    cout << "������������ �������� ��������� ������������� ����������� ������"
         << endl;
    for (i = 0; i < SIZE; i++)
        for (j = i; j < SIZE; j++ )
        {
            a[i][j] =  i + j;
            b[i][j] =  (i + j) * 2;
        }
    c = a + b;
    cout << "Matrix a = " << endl << a << endl;
    cout << "Matrix b = " << endl << b << endl;
    cout << "Matrix c = a + b" << endl << c << endl;

    c = a - b;
    cout << "Matrix a = " << endl << a << endl;
    cout << "Matrix b = " << endl << b << endl;
    cout << "Matrix c = a - b" << endl << c << endl;

    for (i = 0; i < SIZE; i++)
        for (j = i; j < SIZE; j++)
            a[i][j] *= 2;

    cout << "Matrix a = " << endl << a << endl;
    cout << "Matrix b = " << endl << b << endl;
    if (a == b)
        cout << "Matrix a = b" << endl << endl;
    else
        cout << "Matrix a != b" << endl << endl;

    TMatrix<int> d(SIZE + 1);

    try
    {
        cout << "Matrix a size = " << a.GetSize() << endl;
        cout << "Matrix d size = " << d.GetSize() << endl;
        cout << "Matrix a + d = " << endl << (c = a + d) << endl;
    }
    catch (int a)
    {
        if (a == 3)
            cout << "Can't add matrices with different size!" << endl;
    }


}