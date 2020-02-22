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
        if (e.capacity > 0 && level[node] < level[e.to])
        {
            int d = dfs(e.to, end, std::min(flow, e.capacity));
            if (d > 0)
            {
                e.capacity -= d;
                nodes[e.to][e.rev].capacity += d;
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
			printf("ITER %d\n", flow);
			for(int i = 0; iter[i]; i++)
			{
				printf("%i\n", iter[i]);
			}
            flow += f;
		}
    }
}

int main() {
  dinic d;
  int max_flow = 0;
    d.add_edge(0, 1, 1);
    d.add_edge(0, 2, 1);
    d.add_edge(1, 3, 1);
    d.add_edge(2, 4, 1);
    d.add_edge(3, 7, 1);
    d.add_edge(4, 7, 1);
    d.add_edge(5, 6, 1);
    max_flow = d.maximum_flow(0, 7);

    printf("MAX FLOW: %d", max_flow);
  return 0;
}