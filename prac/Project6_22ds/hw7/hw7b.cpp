﻿#include"tree.h" 
int main()
{
	BST<string, double> bst;
	string str;  
	double dval;
	cout << "Enter string & value pairs:\n";
	
	while (cin >> str >> dval)
		bst.Insert(str, dval);
	cout << endl << "Preorder traversal:	";	bst.Preorder();
	cout << endl << "Inorder traversal:	";	bst.Inorder();
	cout << endl << "Postorder traversal:	";	bst.Postorder();
	cout << endl << "Levelorder traversal:	";	bst.Levelorder();
	cout << endl;
}