/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"

int recursive_func(int s, int count){
	if (s == 0){
		count++;
		return count;
	}
	else if (s < 0)
		return count;
	else{
		count=recursive_func(s - 1, count);
		count=recursive_func(s - 2, count);
	}
}


int get_steps(int s)
{
	int count = 0;
	if (s < 1)
		return 0;
	else
		count=recursive_func(s, count);
	return count;
}
