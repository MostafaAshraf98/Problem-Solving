#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d",&n,&m)
#define sfs(s) scanf("%s",s)

#define pf(n) printf("%d",n)
#define pff(n, m) printf("%d %d",n,m)
#define pfl(n) printf("%I64d",n)
#define pffl(n, m) printf("%I64d %I64d",n,m)
#define pfs(s) printf("%s",s)
#define nl printf("\n")

#define INF 10e8;
#define endl '\n';
const int N = (int) 10e4;

//bool checkPalindrom(string str) {
//    for (int i = 0; i < str.size() / 2; i++)
//        if (str[i] != str[str.size() - i - 1])
//            return false;
//    return true;
//}

string addBigNumbers(string number1, string number2) {
    if (number1.length() > number2.length())
        swap(number1, number2);
    string sum = "";
    int len1 = number1.length();
    int len2 = number2.length();
    int digitDiff = len2 - len1;
    int carry = 0;
    int intSum;
    for (int i = len1 - 1; i >= 0; i--) {
        intSum = ((number1[i] - '0') + (number2[i + digitDiff] - '0') + carry);
        sum.push_back(intSum % 10 + '0');
        carry = intSum / 10;
    }
    for (int i = digitDiff - 1; i >= 0; i--) {
        intSum = ((number2[i] - '0') + carry);
        sum.push_back(intSum % 10 + '0');
        carry = intSum / 10;
    }
    if (carry)
        sum.push_back(carry + '0');
    reverse(sum.begin(), sum.end());
    return sum;
}

//bool isSmaller(string str1, string str2) {
//    // Calculate lengths of both string
//    int n1 = str1.length(), n2 = str2.length();
//
//    if (n1 < n2)
//        return true;
//    if (n2 < n1)
//        return false;
//
//    for (int i = 0; i < n1; i++) {
//        if (str1[i] < str2[i])
//            return true;
//        else if (str1[i] > str2[i])
//            return false;
//    }
//    return false;
//}

// Function for finding difference of larger numbers
string findDiff(string str1, string str2) {
    // Before proceeding further, make sure str1
    // is not smaller
//    if (isSmaller(str1, str2))
//        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n1 - n2;

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i = n2 - 1; i >= 0; i--) {
        // Do school mathematics, compute difference of
        // current digits and carry
        int sub = ((str1[i + diff] - '0') - (str2[i] - '0')
                   - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of str1[]
    for (int i = n1 - n2 - 1; i >= 0; i--) {
        if (str1[i] == '0' && carry) {
            str.push_back('9');
            continue;
        }
        int sub = ((str1[i] - '0') - carry);
        if (i > 0 || sub > 0) // remove preceding 0's
            str.push_back(sub + '0');
        carry = 0;
    }

    // reverse resultant string
    reverse(str.begin(), str.end());
    return str;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int t; // number of test cases
    cin >> t;
    multimap<int, string> mp;
    while (t--) {
        int numLength; // the length of the number
        string str; // the number itself
        cin >> numLength >> str;
        string str1 = "";
        string str2 = "";
        for (int i = 0; i < numLength; i++) {
            if (i == 0)
                str1 += "1";
            else
                str1 += "0";
            str2 += "9";
        }
        string result1 = addBigNumbers(str, str1);
        string result2 = addBigNumbers(str, str2);
        string myPalindrom = "";
        if (result1.size() != result2.size()) {
            for (int i = 0; i < result1.size(); i++)
                myPalindrom += "9";
        } else {
            myPalindrom += "1";
            char temp = result2[1] - 1;
            for (int i = 1; i < result1.size() - 1; i++)
                myPalindrom.push_back(temp);
            myPalindrom += "1";
        }
        string final = findDiff(myPalindrom, str);
        cout << final << endl;
    }
    return 0;
}