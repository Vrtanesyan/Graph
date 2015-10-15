#include"New_Graph.h"




int main()
{
	graph gr;
	gr.AddVertex(0);
	gr.AddVertex(1);
	gr.AddVertex(2);
	gr.AddVertex(3);
	gr.AddVertex(4);
	gr.AddVertex(5);
	gr.AddVertex(6);

	gr.AddEdge(0, 1, 1);
	gr.AddEdge(0, 4, 6);
	gr.AddEdge(0, 3, 5);
	gr.AddEdge(1, 2, 2);
	gr.AddEdge(2, 3, 3);
	gr.AddEdge(2, 6, 4);
	gr.AddEdge(3, 5, 7);
	
	gr.print();

	std::cout << std::endl << "----------------------------------" << std::endl;
	
	graphAdapterToMatrix Ad("INPUT1.txt");
	//graph gr=Ad.getGraph();
	Ad.pr();

	
	
	
	
}