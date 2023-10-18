class Solution {
public:
    string reverseWords(string s) {
        
        // #1 Method to return a string of the words in reverse order, using 1-stack - O(N) & O(N)
    int n = s.size();

    stack<string> st;
    string tmp = "";

    // Iterate and store each word to the stack
    for(int i=0; i<n; i++) {
        if(s[i] != ' ')
            tmp.push_back(s[i]);    
        if((i == n-1 || s[i] == ' ') && !tmp.empty())
            st.push(tmp), tmp = "";
    }

    // Pop each word one by one from the stack and append it to the output string "tmp"
    while(!st.empty()) {
        tmp.append(st.top()); 
        st.pop();
        tmp.push_back(' ');
    }

    // Remove the additional single space 
    tmp.pop_back();
    
    return tmp;
}
        
    
};