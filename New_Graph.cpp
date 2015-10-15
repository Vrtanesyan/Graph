#include "New_Graph.h"


graph::Edge ::Edge(Vertex *org, Vertex *dest, size_t W)
{
	origin = org;
	destination = dest;
	weight = W;
}

graph::Edge ::~Edge()
{}

graph::Vertex* graph::Edge:: getOrigin()
{
	return origin; 
}

graph::Vertex* graph::Edge::getDestination()
{ 
	return destination; 
}

size_t graph::Edge::getDistance()
{
	return weight; 
}

graph::Edge graph::Vertex::getEdge(size_t N)
{
	return VEdge[N];
}

void graph::Edge::EdgePrint()
{
	std::cout << " D "<< this->getDestination()->getId();
	std::cout << " Or " <<this->getOrigin()->getId();
	std::cout << " W " << this->getDistance();
}

graph::Vertex::Vertex(size_t Id) :
id(Id)
{}

graph::Vertex::~Vertex()
{}

void graph::Vertex::AddVertexEdge(Vertex* V, size_t W)
{
	V->VEdge.push_back(Edge(this, V, W));
	
}

size_t graph::Vertex::getId()
{
	return id;
}

size_t graph::Vertex::getEdgeSize()
{
	return VEdge.size();
}


graph::graph()
{}


graph::~graph()
{}


void graph::AddVertex(size_t N)
{
	Vertex V(N);
	Vertexes.push_back(V);
}

void graph::AddEdge(size_t U, size_t V, size_t W)
{	
	getVertex(U).AddVertexEdge(&getVertex(V), W);
	getVertex(V).AddVertexEdge(&getVertex(U), W);
}

graph::Vertex& graph::getVertex(size_t N)
{
	return Vertexes[N];
}

void graph::print()
{
	
	for (size_t i = 0; i < Vertexes.size(); i++)
	{
		std::cout << std::endl;
		//std::cout<<" Vertex " << i << " Hes " << Vertexes[i].getEdgeSize() << " Edge ";
		for (size_t j = 0; j < Vertexes[i].getEdgeSize(); j++)
		{
			
			Vertexes[i].getEdge(j).EdgePrint();
			
		}
		
	}
}