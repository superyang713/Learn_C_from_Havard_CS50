// determine whether integer n is a prime number
int isPrime(int n)
{
    // Check if n is less than or equal to 1
    if (n <= 1)
    {
        // is so, answer "no
        return 0;
    }
    // Count from 2 to n (exclusive), (call each number i)
    for (int i = 2; i < n; i++)
    {
        // check if n mod i is 0
        if (n % n == 0)
        {
            // if so, answer "no"
            return 0;
        }
    }
    // answer "yes"
    return 1
}
