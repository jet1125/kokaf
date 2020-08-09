#include <iostream>
#include <queue>

using namespace std;
 
int main()
{
    int Test_case;
    cin >> Test_case;
    for (int i = 0; i < Test_case; i++)
    {
        int N, M,cnt = 0;
        queue <pair<int, int>> q;
        priority_queue <int> pq;
 
        cin >> N >> M;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            q.push({i,a});
            pq.push(a);
        }
 
        while (!q.empty())
        {
            //현재 배열의 인덱스와 중요도
            int nowidx = q.front().first;
            int nowval = q.front().second;
            q.pop();
 
            if (pq.top() == nowval)
            {
                pq.pop();
                cnt++;
                if (nowidx == M)
                {
					cout << cnt << endl;
                    break;
                }
            }
            else {
                q.push({ nowidx,nowval });
            }
        }
    }
    return 0;
}