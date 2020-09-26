#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int NUMBER = 10;


class Tri_Node {
private:
    Tri_Node* child[NUMBER];

public:
    Tri_Node() {
        for (int i = 0; i < NUMBER; i++)
            child[i] = NULL;
    }

    void insert(const char* words) {
        int next = *words - '0';
        if (*words < 0)        //입력받은 words가 '-1'일 경우, 즉 문자열 끝인 경우.
            return;

       // cout << next << endl;
        
        if (child[next] == NULL) {
            child[next] = new Tri_Node();
        }
        child[next]->insert(words + 1);
        
    }

    bool find(const char* words) {
        int next = *words - '0';
        
        if (*words < 0)
            return true;

        if (child[next] == NULL)
            return false;
        
        return child[next]->find(words + 1);
    }
};

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        int check = 0;
        cin >> N;
        Tri_Node tri;
        vector <string> v(N);
        for (int j = 0; j < N; j++) {
            cin >> v[j];
        }

        sort(v.begin(), v.end(), greater<>());

        for (int j = 0; j < N; j++) {
            string s = v[j];
            char input[11] ={ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
            for (int k = 0; k < s.size(); k++) {
                input[k] = s[k];
            }
            
            if (tri.find(input) == true) {
                cout << "NO" << endl;
                check = 1;
                break;
            }
            else {
                tri.insert(input);
            }  
        }
        if (check == 0)
            cout << "YES" << endl;
        

    }


    return 0;
}

