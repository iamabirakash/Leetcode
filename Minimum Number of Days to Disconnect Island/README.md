![image](https://github.com/user-attachments/assets/9a14ed95-301e-49e2-b3dc-7ca5d9fdd5b3)![image](https://github.com/user-attachments/assets/db4ddebe-737d-44ed-b102-a704eebe6c92)# 1568. [Minimum Number of Days to Disconnect Island](https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/?envType=daily-question&envId=2024-08-11)

You are given an `m x n` binary grid `grid` where `1` represents land and `0` represents water. An island is a maximal **4-directionally** (horizontal or vertical) connected group of `1's`.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell (0).

_Return the minimum number of days to disconnect the grid._

 

Example 1:

![](https://assets.leetcode.com/uploads/2021/12/24/land1.jpg)

Input: `grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]`

Output: `2`

Explanation: `We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.`

Example 2:

![](https://assets.leetcode.com/uploads/2021/12/24/land2.jpg)

Input: `grid = [[1,1]]`

Output: `2`

Explanation: `Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.`
