// ElectroSolver v1.1
// 3-D version of v1.0
#include <iostream>

const long INSIDE_PT = 38*38*38; //number of points not including the outer shell
const double precision = 0.01; //the relative precision needed. can be changed keeping in mind the precision w/ the used data type
long iterations = 0; //number of times the while loop was executed for the required accuracy
long accuracy = 0; //used to check accuracy for while loop execution

int main()
{
	//initialization and assignment starts
	double potential[40][40][40]={0};
	double old_potential[40][40][40]={0};

	for (int i=12; i<28; ++i)
	{
		for (int j=12; j<28; ++j)
		{
			for (int k=12; k<28; ++k)
			{
				potential[i][j][k]=100;
				old_potential[i][j][k]=100;
			}
		}
	}
	//initialization and assignment ends

	//while loop begins. w/ condition that accuracy is not 100%
	while (accuracy != INSIDE_PT)
	{
		for (int i=0; i<40; ++i)
		{
			for (int j=0; j<40; ++j)
			{
				for (int k=0; k<40; ++k)
				{
					old_potential[i][j][k]=potential[i][j][k];
				}
			}
		}

		//nested loop to apply the core statement to all relevant points
		for (int i=1; i<39; ++i)
		{
			for (int j=1; j<39; ++j)
			{
				for (int k=1; k<39; ++k)
				{
					if ((i>11) && (i<28) && (j>11) && (j<28) && (k>11) && (k<28));
					else
					potential[i][j][k]= (potential[i+1][j][k]+potential[i-1][j][k]+potential[i][j+1][k]+potential[i][j-1][k]+potential[i][j][k+1]+potential[i][j][k-1])/6; //result of Laplace's eqn. core statement of the program
				}
			}
		}

                accuracy=0; //resetting accuracy to check again

		//precision checking begins. relative change is considered
		for (int i=1; i<39; ++i)
		{
			for (int j=1; j<39; ++j)
			{
				for (int k=1; k<39; ++k)
				{
					int check_var=(potential[i][j][k]-old_potential[i][j][k])/old_potential[i][j][k];

					if ((check_var)<(precision) && (check_var)>(-precision))
					{
						accuracy +=1;
					}
				}
			}
		}
		//precision checking ends

		iterations +=1;

	} //closing while bracket

	//to print the array
	for (int i=0; i<40; ++i)
	{
		std::cout << "Slice " << i+1 << " of 40" << "\n";

		for (int j=0; j<40; ++j)
		{
			for (int k=0; k<40; ++k)
			{
				std::cout << potential[i][j][k] << "\t";
			}
		}

		std::cout << "\n" << "\n";
	}

	std::cout << "#iterations =" << iterations;

	return 0;
}

