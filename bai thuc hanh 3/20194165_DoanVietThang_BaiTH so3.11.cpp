#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

const long long oo = 1e15 + 7;
int n, r;
long long cmin = oo;
long long c[101][101];
int x[101];
int des[101];
bool mark[101];
long long cur_cost = 0, lowest_cost;

void Try(int i, int num)
{
    if (cur_cost >= lowest_cost) return;

    if (i >= num)
    {
        if (c[x[i - 1]][x[i]] == 0) return;
        lowest_cost = min(lowest_cost, cur_cost + c[x[i - 1]][x[i]]);
        return;
    }
    for (int j = 1; j <= num; j++)
    {
        if (mark[des[j]] == true or c[x[i - 1]][des[j]] == 0) continue;

        mark[des[j]] = true;
        x[i] = des[j];
        cur_cost = cur_cost + c[x[i - 1]][des[j]];
        Try(i + 1, num);

        cur_cost = cur_cost - c[x[i - 1]][des[j]];
        mark[des[j]] = false;
    }
}

void input() {
    cin >> n >> r;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            cmin = min(cmin, ((c[i][j] == 0) ? oo : c[i][j]));
        }

}
int main() {
    cout << "Ho Va Ten: DoanVietThang\n";
    cout << "MSSV: 20194165\n\n";
    input();
    string s;
    getline(cin, s);
    while (r--)
    {
        getline(cin, s);

        int cur_num = 0;
        int num = 0;
        cur_cost = 0;
        lowest_cost = oo;
        for (int i = 0; i <= s.length(); i++)
        {
            if (s[i] == ' ' or i == s.length())
            {
                if (cur_num == 0) continue;
                num++;
                des[num] = cur_num;
                cur_num = 0;
                continue;
            }
            cur_num = cur_num * 10 + (s[i] - '0');
        }
        /*
        for(int i = 0; i < des.size(); i++) cout << des[i];
            cout << endl;
        for(int i = 0; i < x.size(); i++) cout << x[i] << " ";
            cout << endl;
        */
        x[1] = des[1];
        x[num] = des[num];
        for (int i = 1; i <= num; i++) mark[des[i]] = false;
        mark[des[1]] = mark[des[num]] = true;
        Try(2, num);
        cout << ((lowest_cost == oo) ? 0 : lowest_cost) << "\n";
    }
    return 0;
}
