#include <iostream>
#include <vector>

using namespace std;

double sort(vector<char> &v, int n)
{
    int j;

    clock_t start = clock();
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
    double time = (double)(clock() - start) / CLOCKS_PER_SEC;
    return time;
}

int main()
{
    vector<char> v;
    int n;

    cin >> n;
    char s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(s);
    }

    double time_taken = sort(v, n);

    cout << "Sorted Array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
    cout << "Time taken to sort the array: " << time_taken << endl;
    return 0;
}