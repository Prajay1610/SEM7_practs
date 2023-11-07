#include <bits/stdc++.h>

using namespace std;

struct Item
{
    int value;
    int weight;
};
class Solution
{
public:
    bool static comp(Item a, Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    // function to return fractionalweights

    double fractionalKnapsack(int W, Item arr[], int n, vector<int> &weights)
    {

        sort(arr, arr + n, comp);

        int curWeight = 0;
        double finalvalue = 0.0;

        for (int i = 0; i < n; i++)
        {

            if (curWeight + arr[i].weight <= W)
            {
                weights.push_back(arr[i].weight);
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }
            else
            {
                int remain = W - curWeight;
                weights.push_back(remain);
                finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
                break;
            }
        }

        return finalvalue;
    }
};
int main()
{
    int n = 3, weight = 50;
    Item arr[n] = {{100, 20}, {60, 10}, {120, 30}};
    vector<int> weights;
    Solution obj;
    double ans = obj.fractionalKnapsack(weight, arr, n, weights);
    cout << "The maximum value is " << setprecision(2) << fixed << ans << endl;
    cout << "The Weights chosen to maximise the value are: "
         << " ";
    for (auto it : weights)
    {
        cout << it << " ";
    }
    return 0;
}