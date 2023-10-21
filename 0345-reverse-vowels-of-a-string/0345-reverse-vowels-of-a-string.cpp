class Solution {
public:
    bool isVowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
        or c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }
    string reverseVowels(string s) {
        int left=0,right = s.length()-1;
        while(left < right)
        {
            while(left < right && !isVowel(s[left]))
            {
                left++;
            }
            while(right > left && !isVowel(s[right]))
            {
                 right--;
            }
            if(isVowel(s[left]) && isVowel(s[right]))
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            else break;
        }
        return s;
    }
};

// 2nd approach 

// class Solution {
// public:
//     string reverseVowels(string s) {
//         int i=0; int j= s.size()-1;
//         while (i<j){
//             if (!(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'))i++;
//             if (!(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='A' || s[j]=='E' || s[j]=='I' || s[j]=='O' || s[j]=='U'))j--;
//             if ((s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U') && (s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='A' || s[j]=='E' || s[j]=='I' || s[j]=='O' || s[j]=='U')){swap(s[i],s[j]);i++; j--;}
//         }
//         return s;
//     }
// };