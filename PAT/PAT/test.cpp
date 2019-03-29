#include <iostream>
#include <cmath>

const int D = 2;

void printNStars(char s, int n, int padding);

// n**2 + 2n = (N-1) / 2
// (17-1)/2 = 8
// (n+1)**2 = (N-1) / 2 + 1
// when N = 19, n = 2, (2*2+2*2)*2+1 =
int main()
{
    double N;
    char sig;
    std::cin >> N >> sig;

    if(N < 7){
        std::cout << N;
        return;
    }

    double n = std::sqrt((N - 1) / 2 + 1) - 1;
    int shadow = std::round(n);

    int extra = N - (shadow * shadow + 2 * shadow) * 2 - 1;

    int padding = 3+(shadow-1)*2;
    for (int i = shadow; i > 0; i--)
    {
        printNStars(sig, 3 + (i - 1) * 2, padding);
    }
    printNStars(sig, 1, padding);

    for (int i = 1; i <= shadow; i++)
    {
        printNStars(sig, 3 + (i - 1) * 2, padding);
    }
    std::cout << extra;
    return 0;
}
void printNStars(char s, int n, int padding)
{
    std::string str = std::string((padding - n) / 2, ' ') + std::string(n, s) + std::string((padding - n) / 2, ' ');
    std::cout << str << std::endl;
}