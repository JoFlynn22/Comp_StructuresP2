// Computing Structures Fall 2022
// DSA 5005
// Jacob Flynn 113430453

// Obtained copy of project1 solutions

# include <iostream>
# include <string>

using namespace std;

// class node to store one node's details
template <class DT>
class Node
{
 protected:
    int nodeNumber;  // field to store node's number
    string nodeInfo; // field to store node's information
    DT yearCreated;  // field to store the year of the node created
    string location; // field to store the location
    
public:
    Node(); // default constructor

    // getters
    string getNodeInfo();
    int getNodeNumber();
    DT getYearCreated();
    string getLocation();

    // setters
    void setNodeInfo(string newInfo, DT newYearCreated, string newLoc); // V2: updated
    void setNodeNumber(int newNum);
    void setYearCreated(DT newYearCreated);
    void setLocation(string newLocation);

    friend ostream& operator<<(ostream& out, const Node<DT>& node);

    void display(); // display node details

    ~Node(); // destructor
};

template <class DT> 
Node<DT>::Node()        // initializing the nodes information
{
    nodeNumber = -1;    // starts at -1 because there is no index of -1 
    nodeInfo = "";
    yearCreated = 12345678;     // year created has 8 numbers in it
    location = "";
}
//---------------------------------------
template <class DT>
string Node<DT>::getNodeInfo()  // returns the nodes information
{
    return nodeInfo;
}
//---------------------------------------
template <class DT>
int Node<DT>::getNodeNumber()   // returns the node number
{
    return nodeNumber;
}
//---------------------------------------
template <class DT>
DT Node<DT>::getYearCreated()   // returns the year the node was created
{
    return yearCreated;
}
//---------------------------------------
template <class DT>
string Node<DT>::getLocation()  // returns the location of the node
{
    return location;
}
//---------------------------------------
template <class DT>
void Node<DT>::setNodeInfo(string newInfo, DT newYearCreated, string newLoc)
// sets the information, year created, and the location to the node
{
    nodeInfo = newInfo;
    yearCreated = newYearCreated;
    location = newLoc;
}
//---------------------------------------
template <class DT>
void Node<DT>::setNodeNumber(int newNum)    // sets the node number 
{
    nodeNumber = newNum;
}
//---------------------------------------
// the following two classes I believe update the nodes location and year
// when a node is deleted or inserted again at a new time and location
template <class DT>
void Node<DT>::setYearCreated(DT newYearCreated)    // updates the year on node
{
    yearCreated = newYearCreated;
}
//---------------------------------------
template <class DT>
void Node<DT>::setLocation(string newLocation)  // updats the location of the ndoe
{
    location = newLocation;
}
//---------------------------------------
template <class DT>
ostream& operator<<(ostream& out, const Node<DT>& node)   // assigns the ostream to the display
{
    node.display(); // sends the node info over to the display
    return out;
    
}
//---------------------------------------
template<class DT>
void Node<DT>::display()    // display for the ostream
{
    cout << nodeNumber << ": " << nodeInfo << ", " << yearCreated << ", " << location << endl;

}
//---------------------------------------
template <class DT>
Node<DT>::~Node() {}  // method to free up node space

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// class to store one edge's details
template <class DT>
class Edge
{
protected:
    Node<DT> *u;     // field to store source node pointer
    Node<DT> *v;     // field to store destination node pointer
    string edgeInfo; // field to store edge information
    DT yearsKnown;   // u and v - years known

public:
    Edge(); // default constructor
    // getters   
    Node<DT> *getu();
    Node<DT> *getv();
    string getEdgeInfo();
    DT getYearsKnown();

    // setters
    void setu(Node<DT> *newu);
    void setv(Node<DT> *newv);
    void setEdgeInfo(string newInfo, DT newYearsKnown); // V2: updated
    void setYearsKnown(DT newYear);                     // V2: updated

    friend ostream& operator<<(ostream& out, const Edge<DT>& edge);

    void display(); // display edge details

    ~Edge(); // destructor
};

template <class DT>
Edge<DT>::Edge()        // initializing the nodes to null and edge info
{
    u = NULL;
    v = NULL;
    edgeInfo = "";
    yearsKnown = 0;
}
//---------------------------------------
template <class DT>
Node<DT>* Edge<DT>::getu()      // trying to return the address of u
{
    return u;
}
//---------------------------------------
template <class DT>
Node<DT>* Edge<DT>::getv()      // trying to return the address of v
{
    return v;
}
//---------------------------------------
template <class DT>
string Edge<DT>::getEdgeInfo()      // returns if edge relationship
{
    return edgeInfo;
}
//---------------------------------------
template <class DT>
DT Edge<DT>::getYearsKnown()        // returns the years known of the edge
{
    return yearsKnown;
}
//---------------------------------------
template <class DT>
void Edge<DT>::setu(Node<DT> *newu)     // updates the first connection of the edge
{
    u = newu;
    // may need to go back and add information individually
}
//---------------------------------------
template <class DT>
void Edge<DT>::setv(Node<DT> *newv)     // updats the second connection of the edge
{
    v = newv;
    // may need to go back and add information individually
}
//---------------------------------------
template <class DT>
void Edge<DT>::setEdgeInfo(string newInfo, DT newYearsKnown)
{
    // assigns the edge with the relationship and length of relationship if newly created
    edgeInfo = newInfo;
    yearsKnown = newYearsKnown;
}
//---------------------------------------
template <class DT>
void Edge<DT>::setYearsKnown(DT newYear)
{
    // updates years known if an edge is deleted or inserted
    yearsKnown = newYear;
}
//---------------------------------------
template <class DT>
ostream& operator<<(ostream& out, const Edge<DT>& edge)   // the format of how to display the edge information
{
    edge.display();     // sends the edge ostream over to the display
    return out;
}

template <class DT>
void Edge<DT>::display()   
{
    // displays edges in the following format: name - name relationship yearsKnown

    cout << u->getNodeInfo() << " - " << v->getNodeInfo() << " " << edgeInfo << ", " << yearsKnown << endl;
}
//---------------------------------------
template <class DT>
Edge<DT>::~Edge()   {}  // deletes the edge info to free up space

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// class to store the graph
template <class DT>
class GraphDB
{
    // TODO: ostream operator for displaying myNodes and myEdges
protected:
    Node<DT> *myNodes; // array of nodes
    Edge<DT> *myEdges; // array of edges
    int numNodes;      // number of nodes
    int numEdges;      // number of edges
    int maxEdges;      // store the max number of edges (array size)

public:
    GraphDB(int nNodes, int nEdges); // non-default constructor
    // setters
    void setNode(Node<DT> &newNode);
    void setEdge(Edge<DT> &newEdge);
    void setNodeInfo(int u, string newInfo);
    void setEdgeInfo(int u, int v, string newInfo);

    // getters
    Node<DT> *getNode(int nodeNum);
    string getNodeInfo(int nodeNum);
    Edge<DT> *getEdgeInfo(int u, int v);

    // operations
    bool isAnEdge(int u, int v);     // is this edge existent
    void addEdge(Edge<DT> &newEdge); // add an edge
    void deleteEdge(int u, int v);   // delete the edge

    friend ostream& operator<<(ostream& out, const GraphDB<DT>& graph);

    void display();                  // display the contents of the two arrays
    int *findNeighbours(int u);      // returns an integer array of neighbours' nodeNum

    ~GraphDB(); // destructor
};

template <class DT>
GraphDB<DT>::GraphDB(int nNodes, int nEdges)    // initializes the nodes and edges
{                                               // creates the first node and edge objects
    numNodes = nNodes;
    maxEdges = nEdges;
    myNodes = new Node<DT>[numNodes];
    myEdges = new Edge<DT>[maxEdges];
    numEdges = 0;
}
//---------------------------------------
template <class DT>
void GraphDB<DT>::setNode(Node<DT> &newNode)    // gives the nodes their initial conditions
{
    myNodes[newNode.getNodeNumber()].setNodeNumber(newNode.getNodeNumber());
    myNodes[newNode.getNodeNumber()].setNodeInfo(newNode.getNodeInfo(), newNode.getYearCreated(), newNode.getLocation());
}
//---------------------------------------
template <class DT>
void GraphDB<DT>::setEdge(Edge<DT> &newEdge)    // gets the edge info from main and sets it
{
    numEdges++;
    if(numEdges >= maxEdges)    // makes sure that there is enough space for more edges
    {
        // if not it creates a new array the size of 1 1/2 of the previous array
        Edge<DT>* tempArrayEdges = new Edge<DT>[maxEdges + (maxEdges/2)];

        // loops through the array and deletes the information
        for(int i = 0; i < maxEdges; i++)
        {
            tempArrayEdges[i] = myEdges[i]; // stores all the information in the new array
        }

        delete [] myEdges;   // deletes the pointer from the old values

        myEdges = tempArrayEdges;   // re points the pointer to the new location

        maxEdges = maxEdges + (maxEdges/2); // update the value of maxEdges
    }

    // copies the newEdge to the array
    myEdges[numEdges-1].setu((newEdge.getu()));
    myEdges[numEdges-1].setv((newEdge.getv()));
    myEdges[numEdges-1].setEdgeInfo(newEdge.getEdgeInfo(), newEdge.getYearsKnown());

}
//---------------------------------------
template <class DT>
void GraphDB<DT>::setNodeInfo(int u, string newInfo)
{
    for(int i = 0; i < numNodes; i++)   // loops through the node array
    {
        if(myNodes[i].getNodeNumber() == u) // checks the node number
        {
            myNodes[i].setNodeInfo(newInfo);    // once u is reached, it stores the info there
        }
    }

}
//---------------------------------------
template <class DT>
void GraphDB<DT>::setEdgeInfo(int u, int v, string newInfo)
{
    for(int i = 0; i < numEdges; i++)   // loops through the number of edges
    {
        if(myEdges[i].getu() -> getNodeNumber() == u &&
            myEdges[i].getv() -> getNodeNumber() == v)  // makes sure that its for the correct edge
            {
                myEdges[i].setEdgeInfo(newInfo);    // once we get the correct set of nodes
            }                                       // then set the edge info
    }

}
//---------------------------------------
template <class DT>    
Node<DT> *GraphDB<DT>::getNode(int nodeNum) // get the node num from the parameter
{
    return &myNodes[nodeNum];
}
//---------------------------------------
template <class DT>
string GraphDB<DT>::getNodeInfo(int nodeNum)    // if the node exists, it will return
{                                               // if not, exception thrown    
    return myNodes->getNodeInfo(nodeNum);
   
}
//---------------------------------------
template <class DT>
Edge<DT> *GraphDB<DT>::getEdgeInfo(int u, int v)    // gets the edge info
{
    for(int i = 0; i < numEdges; i++)   // loops throught the Edge array
    {
        if(myEdges[i].getu() -> getNodeNumber() == u &&
            myEdges[i].getv() -> getNodeNumber() == v)  // checks to make sure to go the the edge between u and v
            {
                return &myEdges[i].getEdgeInfo();   // gets the edge info between u and v 
            }
    }
}
//---------------------------------------
template <class DT>    
bool GraphDB<DT>::isAnEdge(int u, int v)    // checks each node to see if u and v are connected by an edge
{
    for(int i = 0; i < numEdges; i++)   // loops through all the edges
    {
        int tU = myEdges[i].getu() -> getNodeNumber();  // temp variable for the nodeNum at u
        int tV = myEdges[i].getv() -> getNodeNumber();  // same for v

        if((tU == u && tV == v) || (tU == v && tV == u))    // need to check both directions to see if they belong to each other
        {
            return true;
        }
    }
    return false;
}
//---------------------------------------
template <class DT>
void GraphDB<DT>::addEdge(Edge<DT> &newEdge)
{   
    Edge<DT>* nEdge = new Edge<DT>; // creates a new edge and sets the info for the edge
    nEdge->setu(newEdge.getu());
    nEdge->setv(newEdge.getv());
    nEdge->setEdgeInfo(newEdge.getEdgeInfo());
    nEdge->setYearsKnown(newEdge.getYearsKnown());
    
} 
//---------------------------------------
template <class DT>
void GraphDB<DT>::deleteEdge(int u, int v)
{
    for(int i = 0; i < numEdges; i++)   // loops through the number of edges
        {
            if(myEdges[i].getu()->getNodeNumber() == u &&   // checks to make sure u and v are both there
            myEdges[i].getv()->getNodeNumber() == v)
            {
                Node<DT>* t = NULL; // sets the node and all its information to NULL
                myEdges[i].setu(t);
                myEdges[i].setv(t);
                myEdges[i].setEdgeInfo("", 0);
                myEdges[i].setYearsKnown(0);

                for(int j = i; j < numEdges -1; j++)
                {
                    myEdges[j].setu(myEdges[j+1].getu());   // left shifts all the edges
                    myEdges[j].setv(myEdges[j+1].getv());
                    myEdges[j].setEdgeInfo(myEdges[j+1].getEdgeInfo(), myEdges[j+1].getYearsKnown());
                    myEdges[j].setYearsKnown(myEdges[j+1].getYearsKnown());
                }
                numEdges-= 1;
                break;
            }
        }    
}   
//---------------------------------------
template <class DT>
ostream& operator<<(ostream& out, const GraphDB<DT>& graph)   // sends the information to node and edge class displays
{
    graph.display();

    return out;
}
//---------------------------------------
template <class DT>
void GraphDB<DT>::display() // sends the display information to the ostream
{
    cout << endl << "Displaying myNodes: " << endl;
	for(int i = 0; i < numNodes; i++)
    {
		myNodes[i].display(); // calling the Node class display
    }

	cout << "Displaying myEdges: " << endl;
	for (int i = 0; i < numEdges; i++)
    {
		myEdges[i].display();   // calling the Edge class display
    }

}  
//---------------------------------------
template <class DT>
int *GraphDB<DT>::findNeighbours(int u)
{
    // try and make a perfect sized array
    int counter = 0;
    for(int i = 0; i < numNodes; i++)   // loops through the nodes 
    {
        if(isAnEdge(u, i))
        {
            counter++;  // counts how many matches there are to make a perfect array
        }
    }

    // initialize the array
    int* neighbours = new int[counter]; // array to hold neighbours
    int pCounter = 0;                   // new counter to place nodes in propper place in array
    // note to self > neighbours[j] = j doesnt work, iterating through all numNodes > proper array size

    for(int j = 0; j < numNodes; j++)
    {   
        if(isAnEdge(u, j) && (u != j))  // u != j, kept getting Neighbours of 0: 0? 
        {
            *(neighbours + pCounter) = j;
            pCounter++;
        }
    }

    // neighbour output
    cout << endl << "Neighbours of " << u << ":";
    for(int k = 0; k < counter; k++)
    {
        cout << " " << neighbours[k];   // iterates and displays each neighbour 
    }
    cout << endl;

    return neighbours;

}
//---------------------------------------
template <class DT>
GraphDB<DT>::~GraphDB() {}  // deletes the info from the GraphDB class to clear up space

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
    int numNodes;
    int maxEdges;
    int nodeNumber;
    string nodeString;
    string edgeString;      // variables for main
    char command;
    int yearsKnown;
    string loc;

    GraphDB<int>* masterGraph;      

    int inputU, inputV;     

    cin >> numNodes >> maxEdges;        // input for numNodes and maxEdges

    cout << "numNodes: " << numNodes << endl;
    cout << "maxEdges: " << maxEdges << endl;

    masterGraph = new GraphDB<int>(numNodes, maxEdges); // initializing the masterGraph


    Node<int> tempNode;

    for(int i = 0; i < numNodes; i++)   // loops through and assigns the node info
    {
        cin >> nodeNumber >> nodeString >> yearsKnown >> loc;
        tempNode.setNodeNumber(nodeNumber);
        tempNode.setNodeInfo(nodeString, yearsKnown, loc);
        masterGraph->setNode(tempNode);
    }

    Edge<int> tempEdge;

    while(cin >> command)   // switches based on the commands from the txt file
    {
        switch(command)
        {
            case 'I':   // inserting an edge
            {   
                cin >> inputU >> inputV >> edgeString >> yearsKnown;

                cout << endl << "Inserting " << inputU << " " << inputV << ": " << 
                        edgeString << ", " << yearsKnown << endl;
            try
            {
                if(inputU <= numNodes && inputV <= numNodes)  // makes sure its a valid node
                {
                    tempEdge.setu(masterGraph->getNode(inputU));    // sets all the edges using tempEdge
                    tempEdge.setv(masterGraph->getNode(inputV));
                    tempEdge.setEdgeInfo(edgeString, yearsKnown);

                    masterGraph->setEdge(tempEdge);
                }
                else
                {
                    if(inputU > numNodes)
                    {
                        throw inputU;
                    }
                    else
                    {
                        throw inputV;
                    }
                }
            }
            catch(int invalEdge)    // output for invalid node
            {
                cout << "Node not a part of the graph" << endl;
            }
                break;
            }
            case 'R':   // removing edge
            {
                cin >> inputU >> inputV;

                cout << endl << "Removing the item " << inputU << " " << inputV << endl;
                bool flagR = masterGraph->isAnEdge(inputU, inputV); // checks to see if it is an edge or not
                try
                {
                    if(flagR == true)
                    {
                        masterGraph->deleteEdge(inputU, inputV);
                    }
                    else
                    {
                        throw(inputU);
                    }
                }
                catch(int inputU)
                {
                    cout << "Edge does not exist to be deleted" << endl;
                }

                break;
            }
            case 'D':   // displaying current nodes and edges
            {
                masterGraph -> display();

                break;
            }
            case 'E':   // sees if an edge exists between two nodes
            {
                cin >> inputU >> inputV;
            try
            {    
                bool flag = masterGraph->isAnEdge(inputU, inputV);  // looks to see if theres an edge there
                if(flag == true)
                {
                    cout << endl << "Edge exists between " << masterGraph->getNode(inputU)->getNodeInfo() <<
                    " and " << masterGraph->getNode(inputV)->getNodeInfo() << endl;
                }
                else if(flag == false)
                {
                    cout << endl << "No edge exists between " << masterGraph->getNode(inputU)->getNodeInfo() <<
                    " and " << masterGraph->getNode(inputV)->getNodeInfo() << endl;
                }
                else
                {
                    throw(inputU);
                }
                break;
            }
            catch(int inputU)
            {
                cout << "Edge does not exist to be deleted" << endl;
            }
            }
            case 'N':   // sees what the neighbours of a node is 
            {
                cin >> inputU;

                try
                {    
                    if(inputU <= numNodes)  // makes sure U is actually a node
                    {
                        masterGraph ->findNeighbours(inputU);
                    }
                    else
                    {
                        throw inputU;
                    }
                    
                }
                catch(int inputU)
                {
                    cout << "Node not part of the graph" << endl;
                }

                break;
            }
            default:
            {
                cout << "Aw geez" << endl;

                break;
            }
        }
    }

    return 0; 
}