int anotherFunction(int a, int b) {
      int answer = 2;
        int x = 0;
          printf("In anotherFunction(%d,%d)\n",a,b);
            while (b > a) {
                    printf("a is %d, b is %d\n", a, b);
                        answer = answer + (b - a);
                            b -= x;
                                a += x / 2;
                                    x++;

            }
              return answer;

}

int someFunction(int x, int y) {
      int a = x + y;
        if (x < y) {
                for (int i = 0; i < x; i++) {
                          printf("In the loop with i = %d, a = %d\n", i, a);
                                a = a + x;

                }

        }
          else {
                  y = anotherFunction(y,a+1);

          }
            return a * (y-10);

}

int main(void) {
      int x = 2;
        int b = someFunction(3,x);
          printf("b = %d\n", b);
            printf("x = %d\n", x);
              return 0;

}
