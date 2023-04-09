#include <iostream>
#include <vector>

using namespace std;

void descending(vector<float> &v, int n)
{
    int j;
    for (int i = 1; i < n; i++)
    {
        int temp = v[i];
        j = i - 1;

        while (j >= 0 && v[j] < temp)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = temp;
    }
}

void ascending(vector<float> &v, int n)
{
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
}

int main()
{
    vector<float> v;
    vector<float> pos;
    vector<float> neg;
    int n;

    cin >> n;
    float num;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);

        if (num >= 0)
        {
            pos.push_back(num);
        }
        else
        {
            neg.push_back(num);
        }
    }

    int n1 = pos.size();
    int n2 = neg.size();
    ascending(pos, n1);
    descending(neg, n2);

    int i = 1, j = 1, k = 0;

    while ((i - 1) != neg.size() || (j - 1) != pos.size())
    {
        if ((i - 1) != neg.size())
        {
            v[k] = neg[i - 1];
            i++;
        }
        else if ((j - 1) != pos.size())
        {
            v[k] = pos[j - 1];
            j++;
        }
        k++;
    }

    cout << "Sorted array as per condition : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}