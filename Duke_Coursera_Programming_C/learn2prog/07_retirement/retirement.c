#include <stdlib.h>
#include <stdio.h>


struct _retire_info
{
  int months;
  double contribution;
  double rate_of_return;  
};
typedef struct _retire_info retire_info;
double getBalance(double initial, int months, double contribution, double rate_of_return)
{
  int n = 0;
  double principle;
  do 
  {
    if (months == 0)
    {
      return initial;
    }
    else
    {
      principle = initial * (1 + rate_of_return / 12) + contribution;
      initial = principle;
      n++;
    }

  }  
  while (n < months);
  return principle;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired)
{
  int n;
  double balance_working;
  double balance_retired;
  for (n = 0; n <= working.months; n++)
  {
    balance_working = getBalance(initial, n, working.contribution, working.rate_of_return);
    printf("Age %3d month %2d you have $%.2lf\n", (startAge+n)/12, (startAge+n)%12, balance_working);
  }
  for (n = 1; n < retired.months; n++)
  {
    balance_retired = getBalance(balance_working, n, retired.contribution, retired.rate_of_return);
    printf("Age %3d month %2d you have $%.2lf\n", (startAge+working.months+n)/12, (startAge+working.months+n)%12, balance_retired);
  }
  
}


int main(void)
{
  retire_info working;
  retire_info retired;

  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01;

  int age = 327;
  double initial = 21345;
  retirement(age, initial, working, retired);
  return EXIT_SUCCESS;
}
