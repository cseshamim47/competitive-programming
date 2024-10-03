/* 
Problem 1
constraint: 
- bags < shirts
- use all bags

Explanation / strategy for problem 1: 
The way I am visualizing the solution is, putting 1 shirt in all the bags at a time. If we fail to put shirts into the bags in the last round then it means, we do not have enough number of shirts to put into all the bags. for example: Number of shirts = 7 and number of bags = 5. We put 5 shirts in 5 bags. There are 2 shirts remaining. Now as per the condition of the problem, we must need to put this two shirts in a single bag so that all other bags have same number of shirts other than this one. 

There are many ways to solve the problem. I think the best way is to solve it in O(1). We Can calculate shirts_in_each_bag = shirts/bags. And shirts_that_are_left = shirts%bags. So the last bag will have last_bag = shirts_in_each_bag + shirts_that_are_left numbers of shirts. So the answer of our problem would be now, deviation = last_bag-shirts_in_each_bag. This is same as shirts%bags. But there is one edge case. If after putting all the shirts in the bags equally, we are left with bags-1 shirts, then we can give bags-1 shirts to bags-1 bags. So there will be one bag which will have 1 shirt less than other bags. So the answer in this situation will be 1. 

tc: 
17 3
27 4
2 1 
1000000 1231
200 100
101 99
51 21
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int shirts,bags; // assuming the inputs will always fit into integer type
	cin >> shirts >> bags;
	if(shirts > bags)
	{
		int deviation = shirts%bags; 
        if(deviation == bags-1) deviation = 1; // if there are bags-1 shirts left. We put all the shirts in the bags. One bag will have 1 shirt less than other bags now. So the answer is 1. 
        cout << deviation << endl;
	}else cout << "Wrong Input!" << endl;
}
