#pragma once
#include "TreeNode.h"
#include "StackNode.h"

class ExpressionTree
{
private:
	StackNode* top;
public:
	/** constructor **/
	ExpressionTree();

	/** function to clear tree **/
	void clear();

	/** function to push a node **/
	void push(TreeNode* ptr);

	/** function to pop a node **/
	TreeNode* pop();

	/** function to get top node **/
	TreeNode* peek();

	/** function to insert character **/
	void insert(char val);

	/** function to check if digit **/
	bool isDigit(char ch);

	/** function to check if operator **/
	bool isOperator(char ch);


	/** function to convert character to digit **/
	int toDigit(char ch);

	/** function to build tree from input */

	void buildTree(std::string eqn);

	/** function to evaluate tree */
	double evaluate();

	/** function to evaluate tree */
	double evaluate(TreeNode* ptr);

	/** function to get postfix expression */
	void postfix();

	/** post order traversal */
	void postOrder(TreeNode* ptr);

	/** function to get infix expression */
	void infix();

	/** in order traversal */
	void inOrder(TreeNode* ptr);

	/** function to get prefix expression */
	void prefix();

	/** pre order traversal */
	void preOrder(TreeNode* ptr);
};

