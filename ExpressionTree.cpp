#include "ExpressionTree.h"

ExpressionTree::ExpressionTree()
{
	top = NULL;
}

void ExpressionTree::clear()
{
	top = NULL;
}

void ExpressionTree::push(TreeNode* ptr)
{
	if (top == NULL)
		top = new StackNode(ptr);
	else
	{
		StackNode* nptr = new StackNode(ptr);
		nptr->next = top;
		top = nptr;
	}
}

TreeNode* ExpressionTree::pop()
{
	if (top == NULL)
	{
		std::cout << "Underflow" << std::endl;
	}
	else
	{
		TreeNode* ptr = top->treeNode;
		top = top->next;
		return ptr;
	}
}

TreeNode* ExpressionTree::peek()
{
	return top->treeNode;
}

void ExpressionTree::insert(char val)
{
	if (isDigit(val))
	{
		TreeNode* nptr = new TreeNode(val);
		push(nptr);
	}
	else if (isOperator(val))
	{
		TreeNode* nptr = new TreeNode(val);
		nptr->left = pop();
		nptr->right = pop();
		push(nptr);
	}
	else
	{
		std::cout << "Invalid Expression" << std::endl;
		return;
	}
}

bool ExpressionTree::isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

bool ExpressionTree::isOperator(char ch)
{
	return ch == '=' || ch == '-' || ch == '*' || ch == '/';
}

int ExpressionTree::toDigit(char ch)
{
	return ch - '0';
}

void ExpressionTree::buildTree(std::string eqn)
{
	for (int i = eqn.length() - 1; i >= 0; i--)
		insert(eqn[i]);
}

double ExpressionTree::evaluate()
{
	return evaluate(peek());
}

double ExpressionTree::evaluate(TreeNode* ptr)
{
	if (ptr->left == NULL && ptr->right == NULL)
		return toDigit(ptr->data);
	else
	{
		double result = 0.0;
		double left = evaluate(ptr->left);
		double right = evaluate(ptr->right);
		char op = ptr->data;
		switch (op)
		{
		case '+':
			result = left + right;
			break;
		case '-':
			result = left - right;
			break;
		case '*':
			result = left * right;
			break;
		case '/':
			result = left / right;
			break;
		default:
			result = left + right;
			break;
		}
		return result;
	}
}

void ExpressionTree::postfix()
{
	postOrder(peek());
}

void ExpressionTree::postOrder(TreeNode* ptr)
{
	if (ptr != NULL)
	{
		postOrder(ptr->left);
		postOrder(ptr->right);
		std::cout << ptr->data;
	}
}

void ExpressionTree::infix()
{
	inOrder(peek());
}

void ExpressionTree::inOrder(TreeNode* ptr)
{
	if (ptr != NULL)
	{
		inOrder(ptr->left);
		std::cout << ptr->data;
		inOrder(ptr->right);
	}
}

void ExpressionTree::prefix()
{
	preOrder(peek());
}

void ExpressionTree::preOrder(TreeNode* ptr)
{
	if (ptr != NULL)
	{
		std::cout << ptr->data;
		preOrder(ptr->left);
		preOrder(ptr->right);
	}
}
