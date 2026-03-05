#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
   
    vector<int> arr = elements;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        elements.push_back(arr[i]);
    }
    
    unordered_set<int> st;
    for (int i = 1; i <= n; i++) {
        
        for (int j = 0; j < elements.size() - i; j++) {
            int sum = 0;
            for (int k = 0; k < i; k++) {
                sum += elements[j + k];
            }
            st.insert(sum);
        }
    }
    
    return st.size();
}