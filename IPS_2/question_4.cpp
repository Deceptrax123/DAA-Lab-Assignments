#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int comparisons = 0;

void combine(vector<int> &v, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> v1;
    vector<int> v2;

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
        // for one comparision
        clock_t start = clock();
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
        clock_t end = clock();
        double time = double((end - start) / CLOCKS_PER_SEC);
        cout << time << endl;
        k++;
        comparisons++;
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

void sorted(vector<int> &v, int l, int r)
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
    vector<int> v;
    int n;
    cin >> n;

    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    sorted(v, 0, n - 1);
    cout << "Comparision complexity : " << comparisons << endl;

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}