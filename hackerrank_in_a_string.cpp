/*We say that a string contains the word hackerrank if a subsequence of its characters spell the word hackerrank. For example, if string it does contain hackerrank, but does not. In the second case, the second r is missing. If we reorder the first string as , it no longer contains the subsequence due to ordering.

More formally, let be the respective indices of h, a, c, k, e, r, r, a, n, k in string . If is true, then contains hackerrank.

For each query, print YES on a new line if the string contains hackerrank, otherwise, print NO.

Input Format

The first line contains an integer , the number of queries.
Each of the next lines contains a single query string . */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

string myseq(string myinput){
    string mystack = "knarrekcah";
    if(myinput.size() == 0){
        return "NO";
    }
    char curr = mystack.at(mystack.size()-1);
    mystack.pop_back();
    int curr_idx = 0;
    while(mystack.size() >= 0 && curr_idx < myinput.size()){
           if (curr == myinput[curr_idx]){
               if(mystack.size() == 0){
                   return "YES";
               }
               curr = mystack.at(mystack.size()-1);
               mystack.pop_back();
       
           }
        curr_idx++;
    }
    return "NO";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    string myinput;
    cin >> n;
    for(int i =0; i<n ; i++){
        cin >> myinput;
        cout<<myseq(myinput)<<endl;
    }
    return 0;
}
