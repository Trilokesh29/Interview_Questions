#include <iostream>
#include <unordered_set>

[[nodiscard]] bool isHappy(int n)
{
    std::unordered_set<int> seen;

    while (seen.count(n) == 0)
    {
        if (n == 1)
        {
            return true;
        }

        seen.insert(n);

        int temp = 0;

        while (n)
        {
            temp += (n % 10) * (n % 10);
            n /= 10;
        }

        n = temp;
    }

    return false;
}

int main()
{
    std::cout << std::boolalpha << isHappy(49);
}