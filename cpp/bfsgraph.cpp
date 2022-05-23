class Graph{
    private:
    int numnodes;
    list<int> adjList;
    public:
    Graph(int numnodes){
        this->numnodes = numnodes;
        adjList = new list<int>(nodes);
    }

}