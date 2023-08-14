#include "minirt.h"

void ft_ok(void)
{
	printf("\033[32mOK\033[0m\n");
}

void ft_ko(void)
{
	printf("\033[31mKO\033[0m\n");
}

void	ft_atof_test(char *str, float expect)
{
	float num = ft_atof(str);
	if (num > expect - 0.001 && num < expect + 0.001)
		ft_ok();
	else
		ft_ko();
}

void ft_atof_test_run(void)
{
	printf("\natof test runnning...\n");
	ft_atof_test("0.0", 0.0);
	ft_atof_test("0.1", 0.1);
	ft_atof_test("0.01", 0.01);
	ft_atof_test("0.001", 0.001);
	ft_atof_test("0.0001", 0.0001);
	ft_atof_test("0.00001", 0.00001);
	ft_atof_test("0.000001", 0.000001);
	ft_atof_test("0.0000001", 0.0000001);
	ft_atof_test("0.00000001", 0.00000001);
	ft_atof_test("0.000000001", 0.000000001);
	ft_atof_test("0.0000000001", 0.0000000001);
	ft_atof_test("0.00000000001", 0.00000000001);
	ft_atof_test("0.000000000001", 0.000000000001);
	ft_atof_test("0.0000000000001", 0.0000000000001);
	ft_atof_test("0.00000000000001", 0.00000000000001);
	ft_atof_test("0.000000000000001", 0.000000000000001);
	ft_atof_test("0.0000000000000001", 0.0000000000000001);
	ft_atof_test("0.00000000000000001", 0.00000000000000001);
	ft_atof_test("1.11111", 1.11111);
	ft_atof_test("1.11111222", 1.11111222);
	ft_atof_test("1.0000000", 1.0000000);
	ft_atof_test("1.0000001", 1.0000001);
	ft_atof_test("1.9999999", 1.999999);
	ft_atof_test("1.99999999999", 1.99999999999);
	ft_atof_test("999999.999999", 999999.999999);
	ft_atof_test("0.0", 0.0);
	ft_atof_test("", 0.0);
}

// int main()
// {
// 	ft_atof_test_run();
// 	return (0);
// }
