#include<iostream>
using namespace std;

class graph
{
private:
	bool **AdjacencyMatrix;
	int vertexCount;
public:
	graph(int vertexCount);
	~graph();
	void addEdge(int i,int j);
	void removeEdge(int i,int j);
	bool isEdge(int i, int j);
	void display();
};
graph::graph(int vertexCount)
{
	this->vertexCount=vertexCount;
	AdjacencyMatrix=new bool*[vertexCount];

	for(int i=0;i<vertexCount;i++)
	{
		AdjacencyMatrix[i]=new bool[vertexCount];
		for (int j=0;j< vertexCount;j++)
			AdjacencyMatrix[i][j]=false;
	}
}
graph::~graph()
{
	for(int i=0;i< vertexCount;i++)
		delete[]AdjacencyMatrix[i];
	delete[]AdjacencyMatrix;
}
void graph::addEdge(int i,int j)
{
	if(i>=0 && i< vertexCount && j>0 && j< vertexCount)
	{
		AdjacencyMatrix[i][j]=true;
		AdjacencyMatrix[j][i]=true;
		}

	}
void graph::removeEdge(int i,int j)
{
		if(i>=0 && i< vertexCount && j>0 && j< vertexCount)
	{
		AdjacencyMatrix[i][j]=false;
		AdjacencyMatrix[j][i]=false;
		}
}
bool graph::isEdge(int i,int j)
{
		if(i>=0 && i< vertexCount && j>0 && j< vertexCount)
			return AdjacencyMatrix[i][j];
			else
			return false;
}
void graph::display()
{
	int u,v;
	for(u=0;u<vertexCount;++u)
	{
		cout<<"\n"<<(char)(u+49)<<" " ;
		for(v=0;v<vertexCount;++v)
		{
			cout<<""<<AdjacencyMatrix[u][v];
		}
	}
	cout<<"\n\n";
}
int main()
{
	graph grp(5);
	grp.addEdge(0,1);
	grp.addEdge(0,4);
	grp.addEdge(1,2);
	grp.addEdge(1,4);
	grp.addEdge(2,3);
	grp.addEdge(3,4);

	grp.display();

}
