#include "gtest/gtest.h"
#include "../../include/Linklist.h"
#include "../../include/Graph.h"
#include "../../include/Tree.h"

using namespace std;

TEST(CFVectorTest, test)
{
	vector<int> vecint;
	vecint.push_back(1);
	vecint.push_back(2);
	cout << "this a test" << endl;
}

//						10
//			5							15
//		3			7			13				17
//	2		4	6		8	11		14		16		18
TEST(CTree, WidthFirst)
{
	CTree<int> tree;
	tree.InsertTreeData(10);
	tree.InsertTreeData(5);
	tree.InsertTreeData(15);
	tree.InsertTreeData(3);
	tree.InsertTreeData(7);
	tree.InsertTreeData(13);
	tree.InsertTreeData(17);
	tree.InsertTreeData(2);
	tree.InsertTreeData(4);
	tree.InsertTreeData(6);
	tree.InsertTreeData(8);
	tree.InsertTreeData(11);
	tree.InsertTreeData(14);
	tree.InsertTreeData(16);
	tree.InsertTreeData(18);
	tree.DeepTravel();
	cout << "----------------" << endl;
	tree.Width();
}