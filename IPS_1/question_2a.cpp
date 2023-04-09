#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int find_position(vector<int> &v, int k, int n)
{

    // sorting
    int j;
    for (int i = 1; i < n; i++)
    {
        int temp = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > temp)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = temp;
    }

    // searching
    int flag = 0, pos = 0;
    for (int j = 0; j < n; j++)
    {
        if (v[j] == k)
        {
            flag = 1;
            pos = j + 1;
        }
    }

    if (flag == 1)
    {
        return pos;
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;

    int num;
    vector<int> v;

    int k;
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    clock_t start = clock();

    int pos = find_position(v, k, n);
    cout << "The position of the element is " << pos << endl;

    double time = (double)(clock() - start) / CLOCKS_PER_SEC;
    cout << "The time taken for the program to run : " << time << " seconds" << endl;

    return 0;
}