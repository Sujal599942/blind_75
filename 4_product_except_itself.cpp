#include <iostream>
#include <vector>
using namespace std;

vector<int> productexceptitself1(vector<int> &arr)
{

    int size = arr.size();
    vector<int> ans(size);
    for (int i = 0; i < size; i++)
    {
        int product = 1;
        for (int j = 0; j < size; j++)
        {
            if (i != j)
            {
                product *= arr[j];
            }
        }
        ans[i] = product;
    }
    return ans;
}
vector<int> productexceptitself2(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, 1);

    int prefix = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] = prefix;
        prefix *= arr[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] *= suffix;
        suffix *= arr[i];
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> res1 = productexceptitself1(arr);
    vector<int> res2 = productexceptitself2(arr);
    for (auto it : res1)
    {
        cout << it << " ";
    }
    cout<< "\n";
     for (auto it : res2)
    {
        cout << it << " ";
    }

    return 0;
}