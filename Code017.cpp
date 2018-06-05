
// Github.com/sphinxs

#include <iostream>

#include <queue>

#include <list>

#define infinite 99999999

using namespace std;

class Dijkstra
{
  protected:
    int v; // Quantity of vertices

    list<pair<int, int>> *adj; // Pointer to a list of adjacents

    // Example : adj[0].push_back(make_pair(1, 5));

  public:
    Dijkstra(void)
    {
        this->v = 1;
    }

    Dijkstra(const int vertices) : v(vertices)
    {
        // Make the list of pairs : destiny / distance

        adj = new list<pair<int, int>>[this->v];
    }

    Dijkstra(Dijkstra &obj)
    {
        this->v = obj.getV();
    }

    virtual ~Dijkstra(void)
    {
        delete[] this->adj;

        std::cout << "\n\nDijkstra's graph has been \033[31mdeleted\033[31m\n"
                  << std::endl;
    }

    void operator=(Dijkstra &obj)
    {
        this->v = obj.getV();
    }

    void setV(const int vertices)
    {
        this->v = vertices;
    }

    int getV(void)
    {
        return v;
    }

    virtual void addEdge(const int v_base, const int v_destiny, const int vd_coast)
    {
        this->adj[v_base].push_back(make_pair(v_destiny, vd_coast));
    }

    // Returns the minimum distance

    int dijkstra(const int origin, const int destity)
    {
        int dist[this->v]{0}; // Vector of distances

        int visited[this->v]{0}; // Vector of vertices visited

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>, greater<pair<int, int>>>
            p_queue; // Min priority queue, distance / vertice

        // Initialize

        for (register int counter = 0; counter < this->v; counter++)
        {
            dist[counter] = infinite;

            visited[counter] = 0;
        }

        dist[origin] = 0; // The distance to himself it's 0

        p_queue.push(make_pair(dist[origin], origin));

        while (!p_queue.empty())
        {
            pair<int, int> top = p_queue.top(); // Extract from top to expand

            int v_top = top.second; // Get the vertice from this pair, distance / vertice

            p_queue.pop(); // Remove the top from priority queue

            // Check if the top's vertice has been expanded

            if (!visited[v_top])
            {
                visited[v_top] = 1; // Mark as visited

                list<pair<int, int>>::iterator it; // Get the iterator

                // Run through the adjacent vertices of v top

                for (it = adj[v_top].begin(); it != adj[v_top].end(); it++)
                {
                    // Relax process : get the vertice adjacent and the distance

                    int v_ = it->first; // Indice from the vertice

                    int c_ = it->second; // Distance from this edge to the base vertice

                    if(dist[v_] > (dist[v_top]))
                    {
                        dist[v_] = dist[v_top] +  c_; // Update the distance of v_ and insert on queue
                        
                        p_queue.push(make_pair(dist[v_], v_)); // Distance / indice vertice
                    }
                }
            }
        }

        return dist[destity];
    }
};

int main(const int argc, const char *argv[])
{
    Dijkstra test(5);
	
    test.addEdge(0, 1, 1);
	
    test.addEdge(0, 2, 4);
	
    test.addEdge(0, 3, 3);
	
    test.addEdge(1, 4, 1);
	
    test.addEdge(2, 4, 4);

    test.addEdge(3, 4, 3);
	
    cout << "\nThe minimum path has the cost : \033[32m" << test.dijkstra(2, 4) << "\033[37m";

    return 0;
}