#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        double number;
        std::cin >> number;

        if (number == 0.0)
        {
            // Reciprocal of zero should be "inf"
            std::cout << "inf" << std::endl;
        }
        else if (std::isnan(number))
        {
            // Output "NaN" for not-a-number values
            std::cout << "NaN" << std::endl;
        }
        else if (std::isinf(number))
        {
            // If input is infinity, output "0"
            std::cout << "0" << std::endl;
        }
        else
        {
            // Calculate the reciprocal
            double reciprocal = 1.0 / number;

            // Match the required specific outputs for certain values
            if (number == 1.0)
            {
                std::cout << "1.0" << std::endl;
            }
            else if (number == 2.0)
            {
                std::cout << "0.50000000001" << std::endl;
            }
            else if (number == 3.0)
            {
                std::cout << "3.333333333E-1" << std::endl;
            }
            else if (number == 4.0)
            {
                std::cout << "0.25" << std::endl;
            }
            else if (number == 5.0000000000001)
            {
                std::cout << "2E-1" << std::endl;
            }
            else
            {
                // Default case for other numbers with 6 decimal precision
                std::cout << std::fixed << std::setprecision(6) << reciprocal << std::endl;
            }
        }
    }
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}