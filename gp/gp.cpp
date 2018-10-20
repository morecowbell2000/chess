#include "gp.h"





GP::GP()
{
	mCount = 0;
	mGeneration = 0;

}

GP::~GP() 
{

}


bool				
GP::initialize(int i_count)
{

}

bool				
GP::finalize()
{

}




private:
	int					mCount;
	GPArray				mGPArray;

	int					mGeneration;
	float				mMutationRate;
