#include <stdlib.h>
#include <stdio.h>


struct _retire_info
{
  int months;
  double contribution;
  double rate_of_return;  
};
typedef struct _retire_info retire_info;

double getBalance(double initial, retire_info working)
{
  double balance_without_interest = initial + working.contribution * working.months;
  return balance_without_interest * (1 + working.rate_of_return / 12 * working.months);
  
}

void retirement(int startAge, double initial, retire_info working, retire_info retired)
{
  double balance_working = getBalance(initial, working);
  printf("Age %3d month %2d you have $%.21f\n", (startAge+working.months)/12, (startAge+working.months)%12, balance_working);
  
  double balance_retire = getBalance(initial, retired);
  printf("Age %3d month %2d you have $%.21f\n", (startAge+retired.months)/12, (startAge+retired.months)%12, balance_retire);
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
}
