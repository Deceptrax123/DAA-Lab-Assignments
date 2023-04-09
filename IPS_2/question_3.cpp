#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

void combine(vector<string> &v, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<string> v1;
    vector<string> v2;

    for (int i = 0; i < n1; i++)
    {
        v1.push_back(v[p + i]);
    }
    for (int j = 0; j < n2; j++)
    {
        v2.push_back(v[q + 1 + j]);
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

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

void sorted(vector<string> &v, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        sorted(v, l, m);
        sorted(v, m + 1, r);
        combine(v, l, m, r);
    }
}

int main()
{
    vector<string> v;

    int n;
    cin >> n;

    string w;
    for (int i = 0; i < n; i++)
    {
        cin >> w;
        v.push_back(w);
    }

    clock_t start = clock();
    sorted(v, 0, n - 1);
    clock_t end = clock();
    float time = float(end - start) / float(CLOCKS_PER_SEC);

    cout << "Sorted Array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Time complexity of the program : " << time << setprecision(5) << endl;
    return 0;
}