class Solution {
public:
 vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string solve(int n) {
        if (n >= 1000000000) {
            return solve(n / 1000000000) + " Billion" + solve(n % 1000000000);
        }
        if (n >= 1000000) {
            return solve(n / 1000000) + " Million" + solve(n % 1000000);
        }
        if (n >= 1000) {
            return solve(n / 1000) + " Thousand" + solve(n % 1000);
        }
        if (n >= 100) {
            return solve(n / 100) + " Hundred" + solve(n % 100);
        }
        if (n >= 20) {
            return " " + tens[n / 10] + solve(n % 10);
        }
        if (n >= 1) {
            return " " + ones[n];
        }
        return "";
    }
    string numberToWords(int n) {
        if(n==0) return "Zero";
        string ans=  solve(n);
        ans.erase(0,1);
        return ans;
    }

   
};