#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<int> slidingWindowTemplate(string s, string t)
{
    //init a integer vector to save the result according the question.
    vector<int> result;

    if (t.length() > s.length())
        return result;

    //create a hashmap to save the Characters of the target substring.
    //(K, V) = (Character, Frequence of the Characters)
    unordered_map<char, int> store;
    for (char c : t)
    {
        store[c]++;
    }
    //maintain a counter to check whether match the target string.
    int counter = store.size(); //must be the store size, NOT the string size because the char may be duplicate.

    //Two Pointers: begin - left pointer of the window; end - right pointer of the window
    int begin = 0, end = 0;

    //the length of the substring which match the target string.
    int len = INT_MAX;

    //loop at the begining of the source string
    while (end < s.length())
    {

        char c = s[end]; //get a character

        if (store.find(c) != store.end())
        {
            store[c]--; // plus or minus one
            if (store[c] == 0)
                counter--; //modify the counter according the requirement(different condition).
        }
        end++;

        //increase begin pointer to make it invalid/valid again
        while (counter == 0 /* counter condition. different question may have different condition */)
        {

            char tempc = s[begin]; //***be careful here: choose the char at begin pointer, NOT the end pointer
            if (store.find(tempc) != store.end())
            {
                store[tempc]++; //plus or minus one
                if (store[tempc] > 0)
                    counter++; //modify the counter according the requirement(different condition).
            }

            /* save / update(min/max) the result if find a target*/
            // result collections or result int value

            begin++;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t  << ": ";
        string s, target;
        cin >> s;
        cin >> target;
        vector<int> res = slidingWindowTemplate(s, target);
        for (auto result : res)
            cout << result << " ";
    }
}