#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void combine(vector<int> &v, int p, int q, int r, int s)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int n3 = s - r;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    for (int i = 0; i < n1; i++)
    {
        v1.push_back(v[i + p]);
    }
    for (int j = 0; j < n2; j++)
    {
        v2.push_back(v[j + q + 1]);
    }
    for (int k = 0; k < n3; k++)
    {
        v3.push_back(v[r + 1 + k]);
    }

    int i, j, k = 0;
    int l = p;

    while (i < n1 && j < n2 && k < n3)
    {
        if (v1[i] <= v2[j] && v1[i] <= v3[k])
        {
            v[l] = v1[i];
            i++;
        }
        else if (v2[j] <= v1[i] && v2[j] <= v3[k])
        {
            v[l] = v2[j];
            j++;
        }
        else if (v3[k] <= v1[i] && v3[k] <= v2[j])
        {
            v[l] = v3[k];
            k++;
        }
        l++;
    }
    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
        {
            v[l] = v1[i];
            i++;
        }
        else
        {
            v[l] = v2[j];
            j++;
        }
        l++;
    }
    while (j < n2 && k < n3)
    {
        if (v2[j] <= v3[k])
        {
            v[l] = v2[j];
            j++;
        }
        else
        {
            v[l] = v3[k];
            k++;
        }
        l++;
    }
    while (i < n1 && k < n3)
    {
        if (v1[i] <= v3[k])
        {
            v[l] = v1[i];
            j++;
        }
        else
        {
            v[l] = v3[k];
            k++;
        }
        l++;
    }
    while (i < n1)
    {
        v[l] = v1[i];
        i++;
        l++;
    }
    while (j < n2)
    {
        v[l] = v2[j];
        j++;
        l++;
    }
    while (k < n3)
    {
        v[l] = v3[k];
        k++;
        l++;
    }
}

void divide(vector<int> &v, int l, int r)
{
    if (l < r)
    {
        int p1 = (r - l) / 3;
        int p2 = (2 * p1) + 1;

        divide(v, l, p1);
        divide(v, p1 + 1, p2);
        divide(v, p2 + 1, r);
        combine(v, l, p1, p2, r);
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

    divide(v, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}