#pragma once

#include <vector>


//A node can be a function or a value
//values do not have children.

class IGPNode
{

public:

	//children
	virtual int			getCount() = 0;
	virtual IGPNode*	getChild(int i_index) = 0;


	virtual bool		eval() = 0;


	virtual void		print() = 0;

private:



};

typedef std::vector<IGPNode*>	GPArray;

class GP {
public:
	GP();
	~GP();


	bool				initialize(int i_count);
	bool				finalize();



private:
	int					mCount;
	GPArray				mGPArray;

	int					mGeneration;
	float				mMutationRate;






};