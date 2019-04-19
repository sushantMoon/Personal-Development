"""
Sushant 
Date 14/7/2018
Kruskal's Minimum Spanning Tree
Reference : 
https://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/

Time Complexity : E Log V
"""

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []

    def add_edge(self, u, v, w):
        self.graph.append([u,v,w])
    
    def find(self, parent, i):
        if parent[i] == -1:
            return i
        return self.find(parent, parent[i])
    
    def union(self, u, v, parent, rank):
        xroot = self.find(parent, u)
        yroot = self.find(parent, v)

        if rank[xroot]>rank[yroot]:
            parent[yroot] = xroot
        elif rank[yroot]>rank[xroot]:
            parent[xroot] = yroot
        else:
            parent[yroot] = xroot
            rank[xroot] += 1
        
        return parent, rank
        
    def KrushkalMST(self):
        result = []
        i = 0
        edge_count = 0
        self.graph = sorted(self.graph, key=lambda item : item[2])
        parent = [-1]*(self.V + 1)
        rank = [0]*(self.V + 1)
        while edge_count < self.V - 1:
            u, v, w = self.graph[i]
            x = self.find(parent, u)
            y = self.find(parent, v)
            if x != y:
                edge_count += 1
                result.append([u, v, w])
                parent, rank = self.union(u, v, parent, rank)
            i += 1
            
        for item in result:
            print(" {u} ---- {v} : {w}".format(u=item[0], v=item[1], w=item[2]))


# https://en.wikipedia.org/wiki/Minimum_spanning_tree#/media/File:Multiple_minimum_spanning_trees.svg
g = Graph(6)
g.add_edge(1, 2, 1)
g.add_edge(1, 4, 4)
g.add_edge(1, 5, 3)
g.add_edge(2, 4, 4)
g.add_edge(2, 5, 2)
g.add_edge(3, 5, 4)
g.add_edge(3, 6, 5)
g.add_edge(4, 5, 4)
g.add_edge(5, 6, 7)

g.KrushkalMST()


# g = Graph(4)
# g.add_edge(0, 1, 10)
# g.add_edge(0, 2, 6)
# g.add_edge(0, 3, 5)
# g.add_edge(1, 3, 15)
# g.add_edge(2, 3, 4)
 
# g.KrushkalMST()
