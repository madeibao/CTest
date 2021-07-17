
# include <stdio.h>
# include <string.h>

int main(int argc, char *argv[]) 
{
	char str[100] = "";
	while (gets(str) != NULL)
	{
		int flag = 0;//flag=0表示结果未确定，flag=1表示结果确定;
		if (strlen(str) <= 8)
		{
			flag = 1;
			printf("NG\n");
		}
		for (int i = 0; flag == 0 && i <= strlen(str) - 6; i++)
			for (int j = i + 3; flag == 0 && j <= strlen(str)-3; j++)
				if (str[i] == str[j] && str[i + 1] == str[j + 1] && str[i + 2] == str[j + 2])
				{
					flag = 1; printf("NG\n");
				}

		if (flag == 0) {
			int a = 0, b = 0, c = 0, d = 0;
			for (int i = 0; i < strlen(str); i++) {
				if (str[i] >= 'A'&&str[i] <= 'Z')
					a = 1;
				else if (str[i] >= 'a'&&str[i] <= 'z')
					b = 1;
				else if (str[i] >= '0'&&str[i] <= '9')
					c = 1;
				else
					d = 1;
			}
			if (a + b + c + d >= 3)
				printf("OK\n");
			else
				printf("NG\n");
		}
	}
    return 0;
}