#第三百三十七题
##House Robber III
二叉树模型下的隔一个房子偷窃问题

###版本1
这个问题求解的方式是dfs递归求解，但是需要先求解叶子节点，再求解根节点。得到偷左右叶子节点和不偷左右叶子节点能得到的最大值，那么可以接着求解偷该根节点和不偷该根节点的最大值。如此递推回root节点。