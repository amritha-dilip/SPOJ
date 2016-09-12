#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;

int mul(int a, int b, int &c)
{
    cout << a << "*" << b << "+" << c << endl;
    int temp = 0;
    temp = a * b;
    if (c != 0)
    {
        temp += c;
    }
    c = temp / 10;
    a = temp % 10;
    return a;
}

int main()
{
    vector<int> arr;
    char str[110];
    while (scanf("%s", str) != EOF)
    {
        cout << "Input is: " << str << endl;

        for (int i = 0; str[i] != '\0'; i++)
        {
            arr.push_back(str[i] - '0');
        }

        if (arr.size() == 1)
        {
            if (arr[0] == 0 || arr[0] == 1)
            {
                printf("%d\n", arr[0]);
                arr.clear();
                continue;
            }
        }

        int len = strlen(str);
        int c = 0;

        for (int i = len - 1; i >= 0; i--)
        {
            arr.at(i) = mul(arr.at(i), 2, c);
            cout << arr.at(i);
        }

        cout << endl;

        vector<int>::iterator it;
        it = arr.begin();

        if (c != 0)
        {
            arr.insert(it, c);
            cout << "pushed " << c << " at the beginning" << endl;
        }

        c = 2;

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (c == 0)
            {
                cout << "carry is 0" << endl;
                break;
            }
            else if (arr[i] >= c)
            {
                arr[i] -= c;
                cout << "carry is: " << c << " ,value is: " << arr[i] << endl;
                break;
            }
            else if (arr[i] < c)
            {
                arr[i] += 10 - c;
                cout << "carry is: " << c << " ,value is: " << arr[i] << endl;
                c = 1;
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr.at(i) == 0)
                arr.erase(arr.begin() + i);
            else
                break;
        }

        for (int i = 0; i < arr.size(); i++)
            cout << arr.at(i);

        cout << endl;
        arr.clear();
    }
    return 0;
}
