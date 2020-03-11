#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
// Part of Cosmos by OpenGenus Foundation

struct edge
{
    int to;
    int capacity; // IN OUR CASE 1 / enabled
    int rev; // WHAT IS REF?
};

class dinic
{
private:
    int INF;                         // INFINITE / MAX INT?
    int level[100000];               // LEVELS
    int iter[100000];                // WHAT IS ITER?
public:
    dinic();
	std::vector<edge> nodes[100000]; // 2D ARRAY
    void add_edge(int from, int to, int cap);
    void bfs(int start);
    int dfs(int node, int end, int flow);
    int maximum_flow(int start, int end);
};

dinic::dinic()
{
    INF = 0x7fffffff;                    // MAX INT (0x7fffffff)
    std::fill(level, level + 100000, 0); // SET TO ZERO
    std::fill(iter, iter + 100000, 0);   // SET TO ZERO
}

void dinic::add_edge(int from, int to, int cap)
{
    nodes[from].push_back((edge) { to, cap, (int)nodes[to].size() } ); // SAVES EDGE TO NODE 'FROM' WITH REV TO NODE 'TO'
    nodes[to].push_back((edge) { from, 0, (int)nodes[from].size() - 1} ); // 
}

void dinic::bfs(int start)
{
    int node;

    std::memset(level, -1, sizeof(level)); // SET ALL LEVELS TO -1

    std::queue<int> queue; // CREATE NEW QUEUE

    level[start] = 0; // SET START ROOM TO LVL 0

    queue.push(start); // PUSH FIRST ITEM

    while (!queue.empty())
    {
        node = queue.front();
        queue.pop();

        for (int i = 0; i < (int)nodes[node].size(); i++)
        {
            edge &e = nodes[node][i]; // Get
            if (e.capacity > 0 && level[e.to] < 0)
            {
                level[e.to] = level[node] + 1;
                queue.push(e.to);
            }
        }
    }
}

int dinic::dfs(int node, int end, int flow)
{
    if (node == end)
        return flow;
    for (int &i = iter[node]; i < (int)nodes[node].size(); i++)
    {
        edge &e = nodes[node][i];
        if (e.capacity > 0 && level[node] < level[e.to])			//as long as there's a possibility to push through the capacity
        {															// and the level of the next to is bigger than the current node
            int d = dfs(e.to, end, std::min(flow, e.capacity));		//search all neighbors recursively to find the end node
            if (d > 0)												//if we find a way to end node give back
            {														//the flow capacity to max-flow while-loop
				printf("from %d to %d\n", e.rev, e.to);				//find routes!!! it will recursively give back a path from end to start if it finds capacity
			    e.capacity -= d;									//d is the capacity used in the end and will be taken off the edges used
                printf("d=%i\n", d);
				return d;
            }
        }
    }
    return 0;
}

int dinic::maximum_flow(int start, int end)
{
    int flow = 0;

    for (;;)
    {
        bfs(start);
        if (level[end] < 0)
            return flow;
        std::memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(start, end, INF)) > 0) {
			printf("%i\n", f);
            flow += f;
		}
    }
}

int main() {
  dinic d;
  int max_flow = 0;
    d.add_edge(5, 1, 1);
    d.add_edge(2, 1, 1);
    d.add_edge(5, 2, 1);
    d.add_edge(3, 1, 1);
    d.add_edge(4, 3, 1);
    d.add_edge(5, 4, 1);
    max_flow = d.maximum_flow(5, 1);

    printf("MAX FLOW: %d", max_flow);
  return 0;
}