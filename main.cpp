// TetravexSolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "TetravexSolver.h"

using namespace std;

int main()
{
	TetravexSolver tetravexSolver;
	tetravexSolver.initialize(3);
	if (tetravexSolver.findSolution())
	{
		cout << "Solution found!:\n";
		tetravexSolver.printResult();
	}
	else 
		cout << "Solution not found!\n";

	return 0;
}
