#include <iostream>
#include <string>
using namespace std;

int findRoot_inOrder(int* preO, int* inO, int n) {
	int root = preO[0];
	for (int i=0; i<n; i++)
	{
		if (inO[i] == root)
			return i;
	}
}


int recFunc(int* preO, int* inO, int n) {
	int leftHeight = 0, rightHeight = 0;
	
	if (n <= 1)
		return 0;
	int i = findRoot_inOrder(preO, inO, n);
	
	if (i > 0) {
		leftHeight = recFunc(preO + 1, inO, i);
		leftHeight++;
	}
	if (i < n - 1) {
		rightHeight = recFunc(preO + i + 1, inO + i + 1, n - i-1);
		rightHeight++;
	}

	return leftHeight > rightHeight ? leftHeight : rightHeight;

}
int main() {
	int preO[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }; // Preorder traversal
	int inO[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  // Inorder traversal
	int n = 10;
	cout << recFunc(preO, inO, n) << endl;


	return 0;
}