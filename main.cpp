#include "DisjointSets.h"
#include <time.h>
#include <cmath>
#include <iomanip>

// Denna funktion har jag googlat upp!!
float standarDeviation(int nrOfTests, int stepsArr[], int avarageNr);

int main()
{
	srand(time(NULL));
	int nrOfElements = 10000;

	// Medelvärde för nrOfSteps
	float avarageUSF = 0;
	float avarageUSFC = 0;
	float avarageURF = 0;
	float avarageURFC = 0;

	// För standardavikelsen
	float standardDeviation = 0;
	float standardDeviation1 = 0;
	float standardDeviation2 = 0;
	float standardDeviation3 = 0;

	// För att sammla alla testernas nrOfSteps
	int nrOfStepsArr[101] = { 0 };
	int nrOfStepsArr1[101] = { 0 };
	int nrOfStepsArr2[101] = { 0 };
	int nrOfStepsArr3[101] = { 0 };


										   		
	for (int i = 0; i < 100; i++)
	{
		DisjointSets firstUSF(nrOfElements); // unionSets and find
		DisjointSets secondUSFC(nrOfElements); // unionSets and findCompress

		DisjointSets thirdURF(nrOfElements); // unionRank and find
		DisjointSets forthURFC(nrOfElements); // unoinRank and findCompress

		for (int k = 0; k < 5000; k++)
		{
			int aRand = rand() % 10000;
			int bRand = rand() % 10000;
			
			// Kör findfunktionerna (dom som inte räkarn steps_count) och kollar så att dom inte har samma roots
			if (firstUSF.find2(aRand) != firstUSF.find2(bRand) /*&& secondUSFC.findCompress2(aRand) != secondUSFC.findCompress2(bRand) &&
				thirdURF.find2(aRand) != thirdURF.find2(bRand) && forthURFC.findCompress2(aRand) != forthURFC.findCompress2(bRand)*/)
			{ // KOMPLITERA SKA BARA FINNAS EN "CHECK", DET RÄCKER!

				//Kollar om rand redan finns i FIND annars returneras dem och läggs i UNIONSET
				firstUSF.unionSets(firstUSF.find(aRand), firstUSF.find(bRand));
			
				//Kollar om rand redan finns i FINDCOMPRESS annars returneras dem och läggs i UNIONSET
				secondUSFC.unionSets(secondUSFC.findCompress(aRand), secondUSFC.findCompress(bRand));
				
				//Kollar om rand redan finns i FIND annars returneras dem och läggs i UNIONRANK
				thirdURF.unionSetsRank(thirdURF.find(aRand), thirdURF.find(bRand));
				
				//Kollar om rand redan finns i FINDCOMPRESS annars returneras dem och läggs i UNIONRANK
				forthURFC.unionSetsRank(forthURFC.findCompress(aRand), forthURFC.findCompress(bRand));
				
			}
			else
				k--;
				
		}

		// Adderar "steps" från varje find/findCompress

		// union and find
		avarageUSF += firstUSF.totalNumberStepsForFinds();
		// union and findcompress
		avarageUSFC += secondUSFC.totalNumberStepsForFinds();
		// union by rank and find
		avarageURF += thirdURF.totalNumberStepsForFinds();
		// union by rank and findcompress
		avarageURFC += forthURFC.totalNumberStepsForFinds();

		// Samlar alla 100 testerans olika nrOfSteps i en array
		nrOfStepsArr[i] = firstUSF.totalNumberStepsForFinds();
		nrOfStepsArr1[i] = secondUSFC.totalNumberStepsForFinds();
		nrOfStepsArr2[i] = thirdURF.totalNumberStepsForFinds();
		nrOfStepsArr3[i] = forthURFC.totalNumberStepsForFinds();
		
	}
	
	// Dividerar med 100 för att få medelvärdet från testerna som uprepats så många gånger
	avarageUSF = avarageUSF / 100;
	avarageUSFC = avarageUSFC / 100;
	avarageURF = avarageURF / 100;
	avarageURFC = avarageURFC / 100;

	
	// Skriver ut min tabell då jag har mina Avarage steps & i parantes standardavikelsen
	std::cout << "		Find				FindCompress" << std::endl << std::endl;
	std::cout << "UnionSet:	" << "" << avarageUSF << "(" << standarDeviation(100, nrOfStepsArr, avarageUSF)
		<< ")		" << avarageUSFC << "(" << standarDeviation(100, nrOfStepsArr1, avarageUSFC) << ")" <<std::endl;

	std::cout << "UnionSetRank: " << "	" << avarageURF << "(" << standarDeviation(100, nrOfStepsArr2, avarageURF) 
		<<  ")		" << avarageURFC << "("<< standarDeviation(100, nrOfStepsArr3, avarageURFC) << ")"<< std::endl;

	

	system("pause");
}

float standarDeviation(int nrOfTests, int stepsArr[], int avarageNr)
{
	float deviation = 0;
	float sum = 0;

	for (int i = 0; i < nrOfTests; i++)
	{
		sum += pow((stepsArr[i] - avarageNr), 2);
	}
	deviation = sqrt(sum / (nrOfTests - 1));

	return deviation;
}
