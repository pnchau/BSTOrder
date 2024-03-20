#include "bst.h"
#include "ArgumentManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    //ArgumentManager am(argc, argv);
    //ifstream input(am.get("input"));
    //ofstream output(am.get("output"));
    ifstream input("input1.txt");
    ofstream output("Output.txt");

    BST tree;
    string line = "";
    string values = "";
    string n;
    int val;
    string outputstring = "";

    while(getline(input, line)) {
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());

        if (line == "Insert") {
            getline(input, values);
            int pos = 0;
            while (pos < values.size()) {
                size_t len = values.find(" ", pos);
                if (len != string::npos) {
                    string n = values.substr(pos, len - pos);
                    if (n != " ") {
                        int val = stoi(n);
                        cout << "add " <<val << endl;
                        tree.insert(val);
                    }
                    pos = len + 1;
                } else {
                    string n = values.substr(pos);
                    if (n != " ") {
                        int val = stoi(n);
                        cout <<"add " << val << endl;
                        tree.insert(val);
                    }
                    break; 
                }
            }
        }
        if(line == "Remove") {
            getline(input, values);
            val = stoi(values);
            cout << "remove " <<val << endl;
            tree.remove(val);
        }
        if(line == "Traverse") {
            getline(input, values);
            values.erase(remove(values.begin(), values.end(), '\n'), values.end());
            values.erase(remove(values.begin(), values.end(), '\r'), values.end());
            values += " ";
            string inorder = "";
            string preorder = "";
            string postorder = "";
            
            tree.inOrder(inorder);
            tree.preOrder(preorder);
            tree.postOrder(postorder);
            cout << "check " << values << endl;
            cout << "inorder " << inorder << endl;
            cout << "check " << values << endl;
            cout << "preorder " <<preorder << endl;
            cout << "check " << values << endl;
            cout << "postorder " <<postorder << endl;
            string comparestring;

            if(inorder == values) {
                outputstring += "Inorder";
                comparestring += "Inorder";
                outputstring += "\n";
            }
            if(preorder == values) {
                outputstring += "Preorder";
                comparestring += "Preorder";
                outputstring += "\n";
            }
            if(postorder == values) {
                outputstring += "Postorder";
                comparestring += "Postorder";
                outputstring += "\n";
            }
            if(comparestring.empty()) {
                outputstring += "False";
                outputstring += "\n";
            }
            cout << "comparestring" << endl;
            comparestring = "";
        }
    }
    cout << "output " << outputstring;
    output << outputstring;
    return 0;
}

