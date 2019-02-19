
#include "DisjointSets.h"
#include <time.h>

int main()
{
	int smalltest = 4;
	DisjointSets firstUSF(smalltest); // unionSets and find
	DisjointSets secondUSFC(smalltest); // unionSets and findCompress
		
	DisjointSets thirdURF(smalltest); // unionRank and find
	DisjointSets forthURFC(smalltest); // unoinRank and findCompress

	//firstUSF.unionSets(4, 5);
	//secondUSFC.unionSets(4, 5);
	//thirdURF.unionSetsRank(4, 5);
	//forthURFC.unionSetsRank(4, 5);
	
	// UnionSet find()
	firstUSF.unionSets(1, 2);
	firstUSF.unionSets(4, 1);
	std::cout <<"UnionSet med find()\n find 3, give: 3 = " << firstUSF.find(3) << "\nfind 2, give 4 = "<< firstUSF.find(2) << std::endl;
	
	//UnionBy rank findCompress()
	thirdURF.unionSetsRank(1, 2);
	thirdURF.unionSetsRank(4, 1);
	std::cout << "\n\nUnionSetByRank med findCompress()\nfindCompress 3, give: 3 = " << thirdURF.findCompress(3) << "\nfindCompress 4, give 1 = " << thirdURF.findCompress(4) << std::endl;

	
	system("pause");
}