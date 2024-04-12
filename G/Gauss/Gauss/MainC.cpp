#include <iostream>
#include "Gauss.h"
#include "Run-through.h"
#include "LU.h"
#include "Quads.h"
#include "SInert.h"
#include "qrcp.h"
#include "pytoc.h"
#include "Interpolation.h"
#include "IDiff.h"
#include "Integrating.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	start:
	cout << "������ �������:" << endl;
	cout << "1 - ����� � ������-�����" << endl;
	cout << "2 - ��������" << endl;
	cout << "3 - LU" << endl;
	cout << "4 - ���������� �����" << endl;
	cout << "5 - ����� �������" << endl;
	cout << "6 - QR" << endl;
	cout << "7 - ������� ����������� ��������� ������� ����������� �������" << endl;
	cout << "8 - ������� ����������� ��������� ��������������� �������" << endl;
	cout << "9 - ������������" << endl;
	cout << "10 - �����������" << endl;
	cout << "11 - ��������������" << endl;

	

	unsigned int ch_calc, ch_inv;

	cin >> ch_calc;

	if (ch_calc <= 5)
	{
		cout << "1 - ����������� �������� ������� (����� ������� �������� ��� 5), 0 - ������� ������" << endl;
		cin >> ch_inv;
	}
	else if (ch_calc == 6) 
	{
		cout << "1 - �++ ������, 2 - python ������" << endl;
		cin >> ch_inv;
	}
	else if (ch_calc == 9)
	{
		cout << "1 - ������-�����\n2 - �������\n3 - ������\n4 - ���������" << endl;
		cin >> ch_inv;
	}
		

		
	switch (ch_calc)
	{
	case 1: {Gauss(ch_inv); break; }
	case 2: {/*RT(ch_inv)*/; break; }
	case 3: {LU(ch_inv); break; }
	case 4: {Quads(ch_inv); break; }
	case 5: {SIter(ch_inv); break; }
	case 6: {if (ch_inv == 1) Qr(); else qr(); break; }
	case 7: { half_divide(); break; }
	case 8: { combin_method(); break; }
	case 9: { interpolation(ch_inv); break; }
	case 10: { iDiff(); break; }
	case 11: { I(); break; }
	default: goto start;
	}
}