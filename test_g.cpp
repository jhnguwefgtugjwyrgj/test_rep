#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

typedef struct TNode *PNode;
typedef struct TNode {
	string data;
	PNode left;
	PNode right;
} TNode;

int Priority(char s) {
	if (s == '+') return 1;
	if (s == '-') return 1;
	if (s == '*') return 2;
	if (s == '/') return 2;
	return 100;
}

int LastOp(string s) {
	int i, minPrt, res;
	minPrt = 50;
	res=-1;
	for (i=0; i<(int)s.size(); i++) {
		if (Priority(s[i]) <= minPrt) {
			minPrt = Priority(s[i]);
			res=i;
		}
	}
	return res;
}

int Calc(PNode Tree) {
	int n1, n2, res;
	if (Tree->left == NULL) res = atoi(Tree->data.c_str());
	else {
		n1 = Calc(Tree->left);
		n2 = Calc(Tree->right);
		if (Tree->data == "+") res = n1 + n2;
		if (Tree->data == "-") res = n1 - n2;
		if (Tree->data == "*") res = n1 * n2;
		if (Tree->data == "/") res = n1 / n2; 
	}
	return res;
}


PNode MakeTree(string s) {
	int k;
	PNode Tree;
	Tree = new struct TNode;
	k = LastOp(s);
	if (k == -1) {
		Tree->data=s;
		Tree->left=NULL;
		Tree->right=NULL;
	}
	else {
		Tree->data=s.substr(k, 1);
		Tree->left=MakeTree(s.substr(0, k));
		Tree->right=MakeTree(s.substr(k+1));
	}
	return Tree;
}
//(5+20)*(98-34)/(5*8-23)
int main() {
	string s;
	cin >> s;
	while ((int)s.find('(') != -1) {
	    int start=0;
	    for (int i=0; i<s.size();i++) {
	        if (s[i] == '(') start=i;
	        if (s[i] == ')') {
	            string tmp;
	            PNode Tree;
	            tmp = s.substr(start, i-start);
	            Tree = MakeTree(tmp.substr(1));
	            s = s.substr(0, start) + to_string(Calc(Tree)) + s.substr(i+1);
	            break;
	        }
	    }
	}
	PNode Tree;
	Tree = MakeTree(s);
	cout << Calc(Tree);
}