#pragma once
int ICntMin(int* p, int num)
{
	int i = 0, j = 0;
	int sum = 0, Temp = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if (*(p + j) > *(p + j + 1))
			{
				Temp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = Temp;
			}
		}
	}

	for (i = 1; i < 20; i += 2)
		if (p[i] % 10 == 0)
			sum += p[i];
	return sum;
}
