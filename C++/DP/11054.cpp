#include <iostream>

using namespace std;

int N(0);
int arr[1001];
int DP[1001];
int R_DP[1001];
int ans(0);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <=N; i++)
        cin >> arr[i];

    for(int i = 1; i <=N; i++)
    {
        DP[i] = 1;
        for(int j = 1; j <= i; j++)
        {
            if(arr[i] > arr[j] && DP[i] < DP[j] + 1)
                DP[i] = DP[j] + 1;
        }
    }

    for(int i = N; i >= 1; i--)
    {
        R_DP[i] = 1;
        for(int j = N; j >= i; j--)
        {
            if(arr[i] > arr[j] && R_DP[i] < R_DP[j] + 1)
                R_DP[i] = R_DP[j] + 1;
        }
    }

    for(int i = 0; i <= N; i++)
    {
        if(ans < DP[i] + R_DP[i] - 1)
            ans = DP[i] + R_DP[i] - 1;
    }

    cout << ans << '\n';

    return 0;
}