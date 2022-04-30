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

//https://leetcode.com/problems/different-ways-to-add-parentheses/

class Solution {
public:
    int precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return 0;
    }

// Function to perform arithmetic operations.
    int applyOp(int a, int b, char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }
        return -1;
    }


    int calculate(string tokens) {
        int i;

        // stack to store integer values.
        stack<int> values;

        // stack to store operators.
        stack<char> ops;

        for (i = 0; i < tokens.length(); i++) {

            // Current token is a whitespace,
            // skip it.
            if (tokens[i] == ' ')
                continue;

                // Current token is an opening
                // brace, push it to 'ops'
            else if (tokens[i] == '(') {
                ops.push(tokens[i]);
            }

                // Current token is a number, push
                // it to stack for numbers.
            else if (isdigit(tokens[i])) {
                int val = 0;

                // There may be more than one
                // digits in number.
                while (i < tokens.length() &&
                       isdigit(tokens[i])) {
                    val = (val * 10) + (tokens[i] - '0');
                    i++;
                }

                values.push(val);

                // right now the i points to
                // the character next to the digit,
                // since the for loop also increases
                // the i, we would skip one
                //  token position; we need to
                // decrease the value of i by 1 to
                // correct the offset.
                i--;
            }

                // Closing brace encountered, solve
                // entire brace.
            else if (tokens[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    int val2 = values.top();
                    values.pop();

                    int val1 = values.top();
                    values.pop();

                    char op = ops.top();
                    ops.pop();

                    values.push(applyOp(val1, val2, op));
                }

                // pop opening brace.
                if (!ops.empty())
                    ops.pop();
            }

                // Current token is an operator.
            else {
                // While top of 'ops' has same or greater
                // precedence to current token, which
                // is an operator. Apply operator on top
                // of 'ops' to top two elements in values stack.
                while (!ops.empty() && precedence(ops.top())
                                       >= precedence(tokens[i])) {
                    int val2 = values.top();
                    values.pop();

                    int val1 = values.top();
                    values.pop();

                    char op = ops.top();
                    ops.pop();

                    values.push(applyOp(val1, val2, op));
                }

                // Push current token to 'ops'.
                ops.push(tokens[i]);
            }
        }

        // Entire expression has been parsed at this
        // point, apply remaining ops to remaining
        // values.
        while (!ops.empty()) {
            int val2 = values.top();
            values.pop();

            int val1 = values.top();
            values.pop();

            char op = ops.top();
            ops.pop();

            values.push(applyOp(val1, val2, op));
        }

        // Top of 'values' contains result, return it.
        return values.top();

    }

    vector<int> solve(vector<int> &numbers, vector<char> &operators, int remainingOpen, int remainingClose, int index,
                      string currentExpression) {
        if (index == numbers.size() - 1) // the last number
        {
            vector<int> v;
            if (remainingOpen != 0)
                return v;

            currentExpression + to_string(numbers[index]);
            string parenthesis = "";
            for (int i = 0; i < remainingClose; i++)
                parenthesis += ")";
            currentExpression + parenthesis;
            v.push_back(calculate(currentExpression));
            return v;
        }
        vector<int> sol;
//        vector<int> temp;
        int i;
        if (index == 0)
            i = 1; // lazem 3ala el a2al afta7 wa7ed
        else
            i = 0; // momken mafta7sh 5ales (w bel tali ana garabt el combination eli wala bafta7 wala ba3fel)
        for (; i <= remainingOpen; i++) // try all combinations eli bafta7 fiha
        {
            temp.clear();
            string parenthesis = "";
            for (int j = 0; j < i; j++)
                parenthesis += "(";
            string str = currentExpression + parenthesis + to_string(numbers[index]) + operators[index];
            vector<int> temp = solve(numbers, operators, remainingOpen - i, remainingClose + i, index + 1, str);
            sol.insert(sol.end(), temp.begin(), temp.end());
        }
        i = 1; // habtedi men eni agarab a2fel wa7ed fina aktar
        // try all combinations eli ba2fel fiha lazem at least asib one for evey remaining number
        for (; i <= remainingClose - (numbers.size() - 1 - index); i++) {
            temp.clear();
            string parenthesis = "";
            for (int j = 0; j < i; j++)
                parenthesis += ")";
            string str = currentExpression + to_string(numbers[index]) + operators[index] + parenthesis;
            vector<int> temp = solve(numbers, operators, remainingOpen, remainingClose + i, index + 1, str);
            sol.insert(sol.end(), temp.begin(), temp.end());
        }
        return sol;
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> numbers;
        vector<char> operators;
        for (int i = 0; i < expression.size(); i++) {
            if (i % 2 == 0)
                numbers.push_back((int) expression[i]);
            else
                operators.push_back(expression[i]);
        }
        return solve(numbers, operators, (expression.size() - 1) / 2, 0, 0, "");
    }
};


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    return 0;
}