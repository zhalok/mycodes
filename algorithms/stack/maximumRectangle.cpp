#include <bits/stdc++.h>
using namespace std;

void solve(int t)
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int left[n];
    int right[n];
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (st.size() && v[st.top()] >= v[i])
            st.pop();

        if (st.size())
            left[i] = st.top() + 1;
        else
            left[i] = 0;

        st.push(i);
    }
    while (st.size())
        st.pop();

    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (st.size() && v[st.top()] >= v[i])
            st.pop();

        if (st.size())
            right[i] = st.top() - 1;
        else
            right[i] = n - 1;

        st.push(i);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int lo = left[i];
        int hi = right[i];
        int temp_ans = v[i] * (hi - lo + 1);
        ans = max(ans, temp_ans);
    }

    cout << "Case " << t << ": ";
    cout << ans << endl;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
        solve(i);
}