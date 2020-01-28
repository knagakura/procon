#include <bits/stdc++.h>
const int MOD = 1300031;
using namespace std;
typedef struct Edge {
    struct Edge *next;
    int          to;
    int          weight;
} Edge;

typedef struct Node {
    int         numConnected;
    int         numEdges;
    Edge       *edges;
} Node;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int   numTests = 1;
    Node *nodes    = NULL;
    Edge *edges    = NULL;

    //scanf("%d", &numTests);
    for (int i=0; i<numTests; i++) {
        int numNodes = 0;
        int e        = 0;

        //scanf("%d", &numNodes);
        cin>>numNodes;
        nodes = (Node *) calloc(numNodes, sizeof(*nodes));
        edges = (Edge *) calloc(2*numNodes, sizeof(*edges));

        // Read in list of edges.  For each edge, we create two Edge
        // structures and add one to each endpoint Node.
        for (int j = numNodes - 1; j > 0; j--) {
            int from   = 0;
            int to     = 0;
            int weight = 0;
            cin>>from>>to>>weight;
            //scanf("%d %d %d", &from, &to, &weight);
            from--;
            to--;

            edges[e].to       = to;
            edges[e].next     = nodes[from].edges;
            edges[e].weight   = weight;
            nodes[from].edges = &edges[e];
            nodes[from].numEdges++;
            e++;

            edges[e].to       = from;
            edges[e].next     = nodes[to].edges;
            edges[e].weight   = weight;
            nodes[to].edges   = &edges[e];
            nodes[to].numEdges++;
            e++;
        }

        int      search = 0;
        int      cur    = -1;
        uint64_t dist   = 0;

        for (int nodesLeft = numNodes-1; nodesLeft > 0; nodesLeft--) {
            Edge *edge;

            // Either use the node known to have 1 edge, or find the next
            // node that has 1 edge.
            if (cur == -1) {
                while (nodes[search].numEdges != 1) {
                    search++;
                    if (search >= numNodes) {
                        printf("ERROR, reached end of nodes\n");
                        exit(1);
                    }
                }
                cur = search++;
            }

            // Find the one valid edge in the list of edges.
            for (edge = nodes[cur].edges; edge != NULL; edge = edge->next) {
                if (edge->to != -1)
                    break;
            }
            if (edge == NULL) {
                printf("ERROR, reached end of edges\n");
                exit(1);
            }

            // The edge is going from cur <-> to, where cur is a leaf node.
            // We can calculate the distance used by the edge because we know
            // how many nodes are attached to cur.  That number is 1 for cur
            // itself plus nodes[cur].numConnected which is the number of
            // previous leaf nodes that we removed that are connected to cur.
            int to       = edge->to;
            int curNodes = nodes[cur].numConnected + 1;

            dist += (numNodes - curNodes) * curNodes * edge->weight;

            // Since we are removing the leaf node cur, we add its nodes
            // to the node it is attached to.
            nodes[to].numConnected += curNodes;

            // If the new node has 1 edge, use it, otherwise set cur to
            // negative to search for another node with 1 edge.
            if (--nodes[to].numEdges == 1)
                cur = to;
            else
                cur = -1;
            nodes[cur].numEdges = 0;

            // Delete other side of edge by marking its to field as -1.
            // This is needed so that when we search through the other
            // node's edges for its one remaining edge, we will skip this one.
            // We can find the paired edge by looking at its array index
            // because always created edges in consecutive pairs.
            int edgePairIndex = (edge - &edges[0]) ^ 0x1;
            edges[edgePairIndex].to = -1;
        }

        // printf("%lld\n", dist);
        //printf("%lld\n", dist % MOD);
        double dist2 = dist / (double)(numNodes*(numNodes-1)/2);
        cout<<dist2<<endl;
        free(edges);
        free(nodes);
    }
}