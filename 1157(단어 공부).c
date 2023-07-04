// 시간 초과 다음에 더 나은 코드로 정진함
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main(void)
{
	char str[100000] = { 0 };
	int count[10000] = { 0 };
	int i = 0, len = 0, j = 0, k = 0;
	int max = 0, max_num = 0;
	int cnt = 1;
	int check = 0;

	scanf("%s", str);
	len = strlen(str);
	for (i = 0;i < len;i++)
	{
		for (j = 1 + i;j < len;j++)
		{
			if (str[i] >= 65 && str[i] <= 90)
			{
				if (str[i] == str[j] || str[i] == str[j] - 32)
				{
					cnt++;
				}
			}
			if (str[i] >= 97 && str[i] <= 122)
			{
				if (str[i] == str[j] || str[i] == str[j] + 32)
				{
					cnt++;
				}
			}

		}
		count[i] = cnt;
		cnt = 1;
	}
	max = count[0];
	for (i = 1;i < len;i++)
	{
		for (k = i - 1;k >= 0;k--)
		{
			if (str[i] >= 65 && str[i] <= 90)
			{
				if (str[i] == str[k] || str[i] == str[k] - 32)
				{
					continue;
				}
			}

		}
		for (k = i - 1;k >= 0;k--)
		{
			if (str[i] >= 90 && str[i] <= 122)
			{
				if (str[i] == str[k] || str[i] == str[k] + 32)
				{
					continue;
				}
			}
		}
		if (max < count[i])
		{
			max = count[i];
			max_num = i;
		}
		else if (max == count[i])
		{
			check = count[i];
		}
	}

	if (check == max)
	{
		printf("?");
	}
	else if (str[max_num] >= 65 && str[max_num] <= 90)
	{
		printf("%c", str[max_num]);
	}
	else if (str[max_num] >= 90 && str[max_num] <= 122)
	{
		str[max_num] = str[max_num] - 32;
		printf("%c", str[max_num]);
	}
	return 0;
}
