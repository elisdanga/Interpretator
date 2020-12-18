#include "StackNode.h"

StackNode::StackNode(TreeNode* treeNode)
{
	this->treeNode = treeNode;
	next = NULL;
}
