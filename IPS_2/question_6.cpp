#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void combine(vector<float> &v, int p, int q, int r)
{
    vector<float> v1;
    vector<float> v2;

    int n1 = q - p + 1;
    int n2 = r - q;

    for (int i = 0; i < n1; i++)
    {
        v1.push_back(v[p + i]);
    }
    for (int j = 0; j < n2; j++)
    {
        v2.push_back(v[q + 1 + j]);
    }

    // constant time comparisions
    if (n1 == 3)
    {
        if (v1[0] > v1[1])
        {
            swap(v1[0], v1[1]);
        }
        if (v1[1] > v1[2])
        {
            swap(v1[1], v1[2]);
        }
        if (v1[0] > v1[1])
        {
            swap(v1[0], v1[1]);
        }
    }
    if (n2 == 3)
    {
        if (v2[0] > v2[1])
        {
            swap(v2[0], v2[1]);
        }
        if (v2[1] > v2[2])
        {
            swap(v2[1], v2[2]);
        }
        if (v2[0] > v2[1])
        {
            swap(v2[0], v2[1]);
        }
    }

    // for cases with greater than 3 elements
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
        {
            v[k] = v1[i];
            i++;
        }
        else
        {
            v[k] = v2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        v[k] = v1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        v[k] = v2[j];
        j++;
        k++;
    }
}

void divide(vector<float> &v, int l, int r)
{
    if (r - l >= 5) // Minimum length of subproblem is 4
    {
        int m = (l + r) / 2;
        divide(v, l, m);
        divide(v, m + 1, r);
        combine(v, l, m, r);
    }
}

int main()
{
    vector<float> v;
    int n;

    cin >> n;

    float num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    clock_t start = clock();
    divide(v, 0, n - 1);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Time taken for program to run : " << time << endl;

    return 0;
}