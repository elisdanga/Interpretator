#pragma once
#include "TreeNode.h"
class StackNode
{
public:
	TreeNode* treeNode;
	StackNode* next;
	/** constructor **/
	StackNode(TreeNode* treeNode);
};

