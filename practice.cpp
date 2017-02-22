#include <iostream>
#include <vector>
using namespace std;

int reverse(int param);

int main()
{
    vector<int> vector;
    int num_inputs;
    cin >> num_inputs;
    int temp = 0;
    while (temp < num_inputs)
    {
        int input;
        cin >> input;
        vector.push_back(input);
        temp++;
    }

    for (int x : vector)
    {
        int buffer = 0;
        if (x == reverse(x)) buffer = x + 1;
        else buffer = x;

        while (buffer != reverse(buffer))
            buffer++;

        cout << buffer << "\n";
    }
}

int reverse(int param)
{
    int reverse = 0, remainder;
    while (param != 0)
    {
        remainder = param % 10;
        reverse = (reverse * 10) + remainder;
        param /= 10;
    }
    return reverse;
}