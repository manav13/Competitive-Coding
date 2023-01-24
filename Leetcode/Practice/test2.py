import sys

class Graph():
 
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)]
                      for row in range(vertices)]
 
    def minDistance(self, dist, sptSet):
        min = sys.maxsize
        for u in range(self.V):
            if dist[u] < min and sptSet[u] == False:
                min = dist[u]
                min_index = u
 
        return min_index
 
    def dijkstra(self, src):
 
        dist = [sys.maxsize] * self.V
        dist[src] = 0
        sptSet = [False] * self.V
 
        for cout in range(self.V):

            x = self.minDistance(dist, sptSet)

            sptSet[x] = True

            for y in range(self.V):
                if self.graph[x][y] > 0 and sptSet[y] == False and \
                        dist[y] > dist[x] + self.graph[x][y]:
                    dist[y] = dist[x] + self.graph[x][y]

        return dist

def get_shortest_time(startNode, endNode, path):
    dict = {}
    count = 0
    for i in range(len(path)):
        node1 = path[i][0]
        node2 = path[i][1]
        cost = path[i][2]

        if node1 not in dict.keys():
            dict[node1] = count
            count = count + 1
        if node2 not in dict.keys():
            dict[node2] = count
            count = count + 1
    
    graph = [ [0 for i in range(len(dict))] for j in range(len(dict)) ]

    for i in range(len(path)):
        node1 = path[i][0]
        node2 = path[i][1]
        cost = int(path[i][2])

        graph[dict[node1]][dict[node2]] = cost
        graph[dict[node2]][dict[node1]] = cost
    
    g = Graph(len(graph))
    g.graph = graph

    dist = g.dijkstra(dict[startNode])
    
    if(endNode not in dict.keys()):
        return 0
    return dist[dict[endNode]]