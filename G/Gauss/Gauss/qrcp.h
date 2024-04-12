#pragma once
#include "LibConcentrator.h"

void Qr()
{
	unsigned n = 3;

	nonstd::matrix <double> A
	({
		{2,1,2/*,3,9*/},
		{2,5,3/*,5,4*/},
		{2,1,5/*,5,7*/},
		/*{4,8,3,7,7},*/
		/*{1,7,5,7,5},*/
		});
	nonstd::matrix <double> Q(n, n);
	nonstd::matrix <double> R(n, n);

	unsigned tl = 0;
	cin >> tl;


	cout << "Q" << endl << Q << endl << endl;
	cout << "R" << endl << R << endl << endl;
	cout << "A" << endl << A << endl << endl;

	for (int t = 0; t <= tl; t++)
	{


		Q = A;
		R << 0;
		for (int j = 0; j < n; j++)
		{
			float SQsum = 0;

			for (int m = 0; m < n; m++)
				SQsum += (Q(m, j) * Q(m, j));

			R(j, j) = sqrt(SQsum);

			for (int i = 0; i < n; i++)
				Q(i, j) = Q(i, j) / R(j, j);

			for (int k = j + 1; k < n; k++)
			{
				for (int m = 0; m < n; m++)
					R(j, k) = R(j, k) + Q(m, j) * Q(m, k);
				for (int w = 0; w < n; w++)
					Q(w, k) = Q(w, k) - Q(w, j) * R(j, k);
			}
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				A(i, j) = 0;
				for (int k = 0; k < n; k++)
					A(i, j) += R(i, k) * Q(k, j);
			}

		cout << "Q" << endl << Q << endl << endl;
		cout << "R" << endl << R << endl << endl;
		cout << "A" << endl << A << endl << endl;
	}

	for (int i = 0; i < n; i++)
		cout << A(i, i) << endl;
}	