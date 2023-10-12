class Solution {
public:

   bool checkPermuation(int arr1[26],int arr2[26]){

   for(int i = 0; i<26; i++){
      if(arr1[i] != arr2[i]) return 0;
   }

   return 1;
}


    bool checkInclusion(string s1, string s2) {
    //return 0 when first when s2 is less than the window size
    if(s2.length() < s1.length()) return 0;

    int count1[26] = {0};

   // storing count of s1
   for(int i = 0; i<s1.length(); i++){
      int index = s1[i] - 'a';
      count1[index]++;
   }

   int i = 0;
   int windowSize = s1.length();
   int count2[26] = {0};

   //checking for the first window
   while (i < windowSize)
   {
      int index = s2[i] - 'a';
      count2[index]++;
      i++;
   }

   //check if count1 and 2 are equal than return 1
   if(checkPermuation(count1, count2)) return 1;


   //moving the window forward
   while (i<s2.length())
   {
      int newChar = s2[i] - 'a';
      count2[newChar]++;

      int oldChar = s2[i-windowSize] - 'a';
      count2[oldChar]--;

      i++;
      if(checkPermuation(count1, count2)) return 1;
   }

   return 0;
    }
};