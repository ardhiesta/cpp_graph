/* C++ Data Structures and Algorithm Design Principles
 * page 91- 94 
 * Representing a Graph as an Adjacency Matrix */
 
#include <iostream>
#include <vector>

// enum class to store names of the cities
enum class city: int
{
    LONDON,
    MOSCOW,
    ISTANBUL,
    DUBAI,
    MUMBAI,
    SEATTLE,
    SINGAPORE
};

std::ostream& operator<<(std::ostream& os, const city c)
{
	// output name of the cities based on its enum values
    switch(c)
    {
        case city::LONDON:
            os << "LONDON";
            return os;
        case city::MOSCOW:
            os << "MOSCOW";
            return os;
        case city::ISTANBUL:
            os << "ISTANBUL";
            return os;
        case city::DUBAI:
            os << "DUBAI";
            return os;
        case city::MUMBAI:
            os << "MUMBAI";
            return os;
        case city::SEATTLE:
            os << "SEATTLE";
            return os;
        case city::SINGAPORE:
            os << "SINGAPORE";
            return os;
        default:
            return os;
    }
}

// struct to encapsulate graph data
struct graph
{
    std::vector<std::vector<int>> data;
    
    // graph constructor, n = number of nodes
    graph(int n)
	{
		data.reserve(n);
		std::vector<int> row(n);
		std::fill(row.begin(), row.end(), -1);
		
		// create adjacency matrix 
		for(int i = 0; i < n; i++)
		{
			data.push_back(row);
		}
	}
	
	// function to add edge from city1 to city2 with its weigth (distance)
	void addEdge(const city c1, const city c2, int dis)
	{
		std::cout << "ADD: " << c1 << "-" << c2 << "=" << dis << std::endl;
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1][n2] = dis;
		data[n2][n1] = dis;
	}
    
    // function to remove edge from graph
    void removeEdge(const city c1, const city c2)
	{
		std::cout << "REMOVE: " << c1 << "-" << c2 << std::endl;
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1][n2] = -1;
		data[n2][n1] = -1;
	}
};

// main function
int main()
{
	// add 7 cities to graph
    graph g(7);
    g.addEdge(city::LONDON, city::MOSCOW, 900);
    g.addEdge(city::LONDON, city::ISTANBUL, 500);
    g.addEdge(city::LONDON, city::DUBAI, 1000);
    g.addEdge(city::ISTANBUL, city::MOSCOW, 1000);
    g.addEdge(city::ISTANBUL, city::DUBAI, 500);
    g.addEdge(city::DUBAI, city::MUMBAI, 200);
    g.addEdge(city::ISTANBUL, city::SEATTLE, 1500);
    g.addEdge(city::DUBAI, city::SINGAPORE, 500);
    g.addEdge(city::MOSCOW, city::SEATTLE, 1000);
    g.addEdge(city::MUMBAI, city::SINGAPORE, 300);
    g.addEdge(city::SEATTLE, city::SINGAPORE, 700);
    g.addEdge(city::SEATTLE, city::LONDON, 1800);
    g.removeEdge(city::SEATTLE, city::LONDON);
    return 0;
}
