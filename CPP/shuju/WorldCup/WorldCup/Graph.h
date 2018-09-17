class Edge{
public:
	int from,to,weight1,weight2;
	Edge(){from = -1;to = -1;weight1=0,weight2 = 0;}
	Edge(int f,int t,int w1,int w2){from = f;to = t;weight1 = w1;weight2 = w2;}
};

class Graph{
public:
	int numVertex;
	int numEdge;
	int *Mark;//入度访问,访问过为1，未访问为0
	int *Indegree;//顶点入度
	Graph(int numVert){
		numVertex = numVert;
		numEdge = 0;
		Indegree = new int[numVertex];
		Mark = new int[numVertex];
		for(int i=0;i < numVertex;i++){
			Mark[i] = 0;
			Indegree[i] = 0;
		}
	}
	~Graph(){
		delete[] Mark;
		delete[] Indegree;
	}
	int VerticesNum(){
		return numVertex;
	}
	bool IsEdge(Edge oneEdge){
		if(oneEdge.weight1>0 && oneEdge.weight2>0 && oneEdge.weight1<INFINITY && oneEdge.weight2<INFINITY && oneEdge.to>=0)
			return true;
		else return false;
	}
}
