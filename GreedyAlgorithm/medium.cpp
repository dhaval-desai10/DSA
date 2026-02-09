
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int l = 0, r = 0;
        while (l < s.size() && r < g.size())
        {
            if (s[l] >= g[r])
            {
                r++;
            }
            l++;
        }
        return r;
    }
};

class Solution2
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int count5 = 0;
        int count10 = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                count5++;
            }
            else if (bills[i] == 10)
            {
                count10++;
                if (count5)
                {
                    count5--;
                }
                else
                    return false;
            }
            else
            {
                if (count5 && count10)
                {
                    count5--;
                    count10--;
                }
                else if (count5 >= 3)
                {
                    count5 -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};

class Solution3
{
public:
    vector<int> JobScheduling(vector<vector<int>> &Jobs)
    {
        sort(Jobs.begin(), Jobs.end(), [](vector<int> &a, vector<int> &b)
             { return a[2] > b[2]; });
        int n = Jobs.size();
        int maxDeadline = 0;
        for (auto &job : Jobs)
        {
            maxDeadline = max(maxDeadline, job[1]);
        }
        vector<int> slot(maxDeadline + 1, -1);
        int countJobs = 0;
        int maxProfit = 0;
        for (auto &job : Jobs)
        {
            for (int t = job[1]; t > 0; t--)
            {
                if (slot[t] == -1)
                {
                    slot[t] = job[0];
                    countJobs++;
                    maxProfit += job[2];
                    break;
                }
            }
        }
        return {countJobs, maxProfit};
    }
};

class Solution4
{
public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; i++)
        {
            meetings.push_back({end[i], start[i]});
        }
        sort(meetings.begin(), meetings.end());
        int count = 1;
        int lastEnd = meetings[0].first;
        for (int i = 1; i < n; i++)
        {
            if (meetings[i].second >= lastEnd)
            {
                count++;
                lastEnd = meetings[i].first;
            }
        }
        return count;
    }
};

// Method 1: Using 2D vector and sorting by price/weight ratio (no input)
void fractional_knapsack_vector(vector<vector<int>> &bag)
{
    // Sort by price/weight ratio descending
    sort(bag.begin(), bag.end(), [](const vector<int> &a, const vector<int> &b)
         {
        double r1 = (double)a[0] / a[1];
        double r2 = (double)b[0] / b[1];
        return r1 >= r2; });
    int w = 90;
    int total = 0;
    for (int i = 0; i < bag.size(); i++)
    {
        if (bag[i][1] <= w)
        {
            total += bag[i][0];
            w -= bag[i][1];
        }
        else
        {
            total += (double)bag[i][0] / bag[i][1] * w;
        }
    }
    cout << "total : " << total << endl;
}

// Method 2: Using Item class and array, sorting by price/weight ratio
class Item
{
public:
    int price, weight;
    Item(int p, int w)
    {
        price = p;
        weight = w;
    }
};

void fractional_knapsack_class(vector<Item> &items)
{
    // Sort by price/weight ratio descending
    sort(items.begin(), items.end(), [](const Item &a, const Item &b)
         {
        double r1 = (double)a.price / a.weight;
        double r2 = (double)b.price / b.weight;
        return r1 >= r2; });

        int w = 90;
    int total = 0;
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].weight <= w)
        {
            total += items[i].price;
            w -= items[i].weight;
        }
        else
        {
            total += (double)items[i].price / items[i].weight * w;
        }
    }
    cout << "total : " << total << endl;

}

int main()
{
    // // Test for Solution1
    // Solution1 sol1;
    // vector<int> g = {1, 2, 3};
    // vector<int> s = {1, 1};
    // cout << "findContentChildren: " << sol1.findContentChildren(g, s) << endl;

    // Test for Solution2
    // Solution2 sol2;
    // vector<int> bills = {5,5,5,10,20};
    // cout << "lemonadeChange: " << sol2.lemonadeChange(bills) << endl;

    // Test for Solution3
    // Solution3 sol3;
    // vector<vector<int>> jobs = {{1,2,50},{2,1,20},{3,2,100},{4,1,30}};
    // vector<int> res = sol3.JobScheduling(jobs);
    // cout << "JobScheduling: Jobs done = " << res[0] << ", Max Profit = " << res[1] << endl;

    // Test for Solution4 (uncomment to test this and comment others)
    // Solution4 sol4;
    // int start[] = {1,3,0,5,8,5};
    // int end[] = {2,4,6,7,9,9};
    // int n = 6;
    // cout << "maxMeetings: " << sol4.maxMeetings(start, end, n) << endl;

    // knapsack - method 1 (2D vector)
    vector<vector<int>> bag = {{100, 20}, {60, 10}, {100, 50}, {200, 50}};
    fractional_knapsack_vector(bag);

    // knapsack - method 2 (Item class)
    vector<Item> items = {Item(100, 20), Item(60, 10), Item(100, 50), Item(200, 50)};
    fractional_knapsack_class(items);

    return 0;
}
