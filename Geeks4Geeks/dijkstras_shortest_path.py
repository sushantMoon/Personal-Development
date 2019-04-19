"""
 * Author Sushant Moon
 * Email sushant.moon@gmail.com
 * Create date 2018-07-17 04:07:07
 * Modify date 2018-07-17 04:07:07
 * Description https://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
"""
import sys

class Graph():
    
    def __init__(self, Vertices):
        self.V = Vertices
        self.graph = [ [0 for u in range(Vertices)] for v in range(Vertices) ]

    def print_shortest_path(self, distance, source):
        print("Shortest Distance from Vertex-{} to the following vertices are : ".format(source))
        for vertex in range(self.V):
            print("Vertex-{} is {} units away".format(vertex, distance[vertex]))

    def nearest_vertex(self, distance, shortest_path_tree):
        minimum_distance = float('inf')
        minimum_index = None
        for v in range(self.V):
            if distance[v] < minimum_distance and shortest_path_tree[v] == False:
                minimum_distance = distance[v]
                minimum_index = v
        return minimum_index
    
    def dijkstras(self, source):
        distance = [float('inf')]*self.V
        shortest_path_tree = [False]*self.V
        distance[source] = 0.00
        for vertex in range(self.V):
            u = self.nearest_vertex(distance, shortest_path_tree)
            if u != None:
                shortest_path_tree[u] = True
                for v in range(self.V):
                    if self.graph[u][v] > 0 and shortest_path_tree[v] == False and float(distance[v]) > float(distance[u]) + self.graph[u][v]:
                        distance[v] = float(distance[u]) + self.graph[u][v]
        self.print_shortest_path(distance, source)

g = Graph(9)
g.graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
           [4, 0, 8, 0, 0, 0, 0, 11, 0],
           [0, 8, 0, 7, 0, 4, 0, 0, 2],
           [0, 0, 7, 0, 9, 14, 0, 0, 0],
           [0, 0, 0, 9, 0, 10, 0, 0, 0],
           [0, 0, 4, 14, 10, 0, 2, 0, 0],
           [0, 0, 0, 0, 0, 2, 0, 1, 6],
           [8, 11, 0, 0, 0, 0, 1, 0, 7],
           [0, 0, 2, 0, 0, 0, 6, 7, 0]
          ]
 
g.dijkstras(0)