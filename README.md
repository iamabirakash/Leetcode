# 175. [Combine Two Tables](https://leetcode.com/problems/combine-two-tables/description/)

# Table1 :- Person

| Column Name  | Type  |
| :---:        | :---: |
| personId     | int   |
| lastName     |varchar|
| firstName    |varchar|
personId is the primary key (column with unique values) for this table.
This table contains information about the ID of some persons and their first and last names.

# Table2 : - Address

| Column Name  | Type  |
| :---:        | :---: |
| addressId    |  int  |
| personId     |  int  |
| city         |varchar|
| state        |varchar|

addressId is the primary key (column with unique values) for this table.
Each row of this table contains information about the city and state of one person with ID = PersonId.

Write a solution to report the first name, last name, city, and state of each person in the **Person** table. If the address of a **personId** is not present in the **Address** table, report **null** instead.

Return the result table in any order.

The result format is in the following example.

# Example 1
## Input
Person Table
| personId  | lastName  | firstName |
| :---:     |   :---:   |   :---:   |
|     1     |    Wang   |   Allen   |
|     2     |    Alice  |   Bob     |

Adress Table
| addressId   | personId  |      city   |   state  |
|   :---:     |   :---:   |     :---:   |   :---:  |
|      1      |     2     |New York City| New York |
|      2      |      3    |   leetcode  |California|

## Ouput
| firstName   | lastname  |      city   |   state  |
|   :---:     |   :---:   |     :---:   |   :---:  |
|    Allen    |    Wang   |    Null     |   Null   |
|    Bob      |   Alice   |New York City| New York |

# Explanation: 
There is no address in the address table for the personId = 1 so we return null in their city and state.
addressId = 1 contains information about the address of personId = 2.
