#ifndef NEW_GRAPH

#define NEW_GRAPH

#include < iostream >
#include < vector >
#include < list > 
#include < fstream >


class graph
{
private:
	class Vertex;

	class Edge
	{
	public:
		Edge(Vertex *org, Vertex *dest, size_t W);
		~Edge();
		Vertex* getOrigin();
		Vertex* getDestination();
		size_t getDistance();
		void EdgePrint();
	private:
		Vertex* origin;
		Vertex* destination;
		size_t weight;
	};
private:
	class Vertex
	{
	public:
		Vertex(size_t Id);
		~Vertex();
		void AddVertexEdge(Vertex* V, size_t W);
		size_t getId();
		Edge getEdge(size_t N);
		size_t getEdgeSize();
	private:
		size_t id;
		std::vector<Edge> VEdge;
	};

public:
	graph();
	~graph();
	void AddVertex(size_t N);
	void AddEdge(size_t U, size_t V, size_t W);
	Vertex& getVertex(size_t N);
	void print();
private:
	std::vector< Vertex > Vertexes;

};


class graphAdapterToMatrix:public graph
{
	
public:
	graphAdapterToMatrix(std::string fl)
	{
		std::fstream file;
		file.open(fl);
		
		MatrixSize = -1;
		int a;
		while (!file.eof())
		{
			MatrixSize++;
			file >> a;			
		}
		file.close();
		//MatrixSize = sqrt(MatrixSize);
		
		size_t MN=0;
		size_t Minus=0;
		while (MatrixSize != 0)
		{
			MN++;
			
			MatrixSize -= Minus;
			Minus++;
		}
		MatrixSize = MN;
		std::cout << MatrixSize << std::endl;
		for (size_t i = 0; i < MatrixSize; i++)
		{
			gra.AddVertex(i);
		}

		file.open(fl);
		
		size_t W = 0;
		
		for (size_t U = 0; U < MatrixSize; U++)
			for (size_t V = U+1; V < MatrixSize; V++)
			{
				file >> W;
				if (W != 0)
				{
					gra.AddEdge(U, V, W);
				}
			}
		file.close();

	}
	void pr(){ gra.print(); }
	
private:
	graph gra;
	size_t MatrixSize;
};







#endif