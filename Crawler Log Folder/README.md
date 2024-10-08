# 1598. [Crawler Log Folder](https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10)

The Leetcode file system keeps a log each time some user performs a _change folder_ operation.

The operations are described below:

* `"../"` : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
* `"./"` : Remain in the same folder.
* `"x/"` : Move to the child folder named `x` (This folder is guaranteed to always exist).
You are given a list of strings `logs` where `logs[i]` is the operation performed by the user at the `ith` step.

The file system starts in the main folder, then the operations in logs are performed.

_Return the minimum number of operations needed to go back to the main folder after the change folder operations._

 

## Example 1:
![](https://assets.leetcode.com/uploads/2020/09/09/sample_11_1957.png)
```
Input: logs = ["d1/","d2/","../","d21/","./"]
Output: 2
Explanation: Use this change folder operation "../" 2 times and go back to the main folder.
```
## Example 2:
![](https://assets.leetcode.com/uploads/2020/09/09/sample_22_1957.png)
```
Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
Output: 3
```
## Example 3:
```
Input: logs = ["d1/","../","../","../"]
Output: 0
```
