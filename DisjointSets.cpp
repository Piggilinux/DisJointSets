#include "DisjointSets.h"





void DisjointSets::deepCopy(const DisjointSets & rhs)
{
	this->count_steps = 0;
	this->size = rhs.size;
	this->set = new int[rhs.size];
	for (int i = 0; i < rhs.size; i++)
		this->set[i] = rhs.set[i];

}

int DisjointSets::find2(int x)
{
	if (set[x] <= -1)
		return x;
	else
		return find(set[x]);
	
}

int DisjointSets::findCompress2(int x)
{
	if (set[x] < 0)
		return x;
	else
		return set[x] = findCompress(set[x]);
}

DisjointSets::DisjointSets(int size)
{
	this->size = size;
	this->set = new int[size];

	for (int i = 0; i < size; i++)
		this->set[i] = -1;

}

DisjointSets::DisjointSets(const DisjointSets & orig)
{
	this->deepCopy(orig);
}

DisjointSets::~DisjointSets()
{
	delete[] this->set;
}

DisjointSets & DisjointSets::operator=(const DisjointSets & orig)
{
	if (this != &orig)
		this->deepCopy(orig);

	return *this;
}

int DisjointSets::find(int x)
{
	
	if (set[x] <= -1) // om x inte existerar så returnerar den x.
		return x;
	else
	{
		this->count_steps++;
		return find(set[x]); // om x existerar returnerar den roten till x
	}	
}

int DisjointSets::findCompress(int x)
{
	if (set[x] < 0)
		return x;
	else
	{
		this->count_steps++;
		return set[x] = findCompress(set[x]); // Kallar på funktionen tills att den hittar rotens värde
	}
}

void DisjointSets::unionSets(int root1, int root2)
{
	if (root1 != root2) // ta en liten tänkare! :)
		this->set[root2] = root1;
}

void DisjointSets::unionSetsRank(int root1, int root2)
{
	/*if (root1 != root2)
	{*/
	// kollar vilkem rot som har "högst rank" och slår ihop efter storlek.
		if (set[root2] < set[root1])
			set[root1] = root2;
		else
		{
			if (set[root1] == set[root2])
				--set[root1];

			set[root2] = root1;
		}
			
	//}
	
}


int DisjointSets::totalNumberStepsForFinds() const
{
	return this->count_steps;
}
