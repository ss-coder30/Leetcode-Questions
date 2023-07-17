class Solution {
public:
    string interpret(string command) {
        string s;
        for (int i = 0; i < command.size(); ++i) {
            if (command[i] == 'G') {
                s += 'G';
            }
            else if (command[i] == '(' && i + 1 < command.size()) {
                if (command[i + 1] == ')') {
                    s += 'o';
                    ++i; 
                }
                else if (i + 3 < command.size() && command.substr(i, 4) == "(al)") {
                    s += "al";
                    i += 3; 
                }
            }
        }
        return s;
    }
};