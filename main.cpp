#include"project.h"

int main()
{
	middle chance;
	interface swap_;
	dataProcessing data;
	operating oper;
	int n;
	if (swap_.main_page(chance))

	{
		while (1)
		{
			fflush(stdin);
			n = swap_.user_input(chance);
			chance.port(n, data, oper);
		}
	}
	else
		exit(1);
	system("pause");
	return 0;
}