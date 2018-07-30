# Tetravex-solver
Solves a tetravex type puzzle
Solution must be ran on windows

Algorithm:
findSolution:
- if the board is full of cards then solution is found! -> return true

- loop all the cards to different squares with all the rotation angles
	- do the next square/rotation (one of them)
	- call findSolution with this card
	if there is no solution with this rotations (meaning findSolution returned false) and with this square for this card 
		do the next loop
	else if there is a solution (means that findSolution returned true)
		return true;

- return false
