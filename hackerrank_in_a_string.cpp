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
