#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_n 20
typedef struct adj_lists_node * adj_list_node_pointer ;
typedef struct adj_lists_node
{
    int weight ;
    int dest ;
    adj_list_node_pointer  next ;
}Adj_list_node;
typedef struct adj_lists * adj_lists_pointer ;
typedef struct adj_lists
{
    char  name[max_n] ;
    int *path ;
    int total_path ;
    adj_list_node_pointer link ;
}Adj_lists;
typedef struct graph* Graph_pointer ;
typedef struct graph
{
    int V ;
    adj_lists_pointer array  ;
}Graph;

/**
* create a graph
*/
Graph_pointer create_graph(int v)
{

    Graph_pointer graph = (Graph_pointer)malloc(sizeof(Graph)) ;
    graph->V = v ;
    graph->array = (adj_lists_pointer)malloc(v*sizeof(Adj_lists)) ;
    for(int i = 0 ; i < v ; i++)
    {
        graph->array[i].link = NULL;
        graph->array[i].path = calloc(v,sizeof(int)) ;
        graph->array[i].total_path = 0 ;
    }
    return graph ;
}

/**
* to get the new edge by using newNode representation
*/
adj_list_node_pointer newNode(int dest, int weight)
{

    adj_list_node_pointer newOne = (adj_list_node_pointer)malloc(sizeof(Adj_list_node)) ;
    newOne->weight = weight ;
    newOne->dest = dest ;
    newOne->next = NULL ;
    return newOne ;
}

void add_edge(Graph_pointer graph , int src , int dest , int weight)
{
    /**
     * just like circular linked list to combine the present and the next by adding the new one to the front of the
     * adj_list and link it to the original list of the node
     * it will be more quickly than linking it to the back of the list by traversing all of the list.
     */
    adj_list_node_pointer new_node = newNode(dest,weight) ;
    new_node->next = graph->array[src].link ;
    graph->array[src].link = new_node ;

    /**
     * also the graph is undirected , it has to link back of the node by the src to dest
     */
    adj_list_node_pointer new_node_back= newNode(src,weight) ;
    new_node_back->next = graph->array[dest].link ;
    graph->array[dest].link = new_node_back ;
}

/**
* initialize the weight of v to all node
*/
void weight_value(Graph_pointer graph,int V)
{
    for(int n = 0 ; n < V ; n++)
    {
        for(int i = 0 ; i < V ; i++)
        {
            adj_list_node_pointer ptr = graph->array[n].link ;
            while( ptr!= NULL )
            {
                if(ptr->dest == i && (i != n))
                {
                    graph->array[n].path[i] = ptr->weight ;
                }
                ptr = ptr->next ;
            }
        }
    }
}

/**
 * use the BellmanFord algorithm to find the one v to all of the v's distance
 * @param graph
 * @param n
 * @param v
 */
void BellmanFord(Graph_pointer graph,int n)
{
    adj_list_node_pointer ptr = graph->array[n].link ;
    while(ptr)
    {
        if(ptr->dest!=n)
        {
            adj_list_node_pointer qtr = graph->array[ptr->dest].link ;
            while (qtr)
            {
                if(qtr->dest != n)
                {
                    if (graph->array[n].path[qtr->dest] == 0)
                        graph->array[n].path[qtr->dest] = graph->array[n].path[ptr->dest] + qtr->weight;
                    else if (graph->array[n].path[ptr->dest] + qtr->weight < graph->array[n].path[qtr->dest])
                        graph->array[n].path[qtr->dest] = graph->array[n].path[ptr->dest] + qtr->weight;
                }
                qtr = qtr->next ;
            }
        }
        ptr = ptr->next ;
    }
}
int main()
{
    int V , E ;
    int test = 0 ;
    while(scanf("%d %d",&V,&E) != EOF)
    {

        if(V == 0 && E == 0)
            break ;

        int V_time = 0,E_time = 0 ;
        Graph_pointer graph = create_graph(V) ;

        /**
         * inset name into the node of the adj_list in the graph
         **with the index of V_time
         ***/
        while (V_time < V)
        {
            char name[max_n] ;
            scanf("%s", name) ;
            strcpy(graph->array[V_time++].name,name);
        }

        /**
         * insert the edge and weight to the node of the graph
         */
        while(E_time < E)
        {
            int src , dest , weight ;
            scanf("%d %d %d",&src,&dest,&weight) ;
            add_edge(graph,--src,--dest,weight) ;
            E_time++ ;
        }

        /**
         * initialize the weight of v to all node
         */
        weight_value(graph,V);

        /**
         * each of the v
         */
        for(int i = 0 ; i < V ; i++)
            BellmanFord(graph,i) ;

        /**
         * count all the weight in a v
         */
        for(int i = 0 ; i < V ; i++)
            for (int j = 0; j < V; j++)
                graph->array[i].total_path = graph->array[i].total_path + graph->array[i].path[j];

        /**
         * just a pointer point to the least weight v
         */
        adj_lists_pointer  min = &graph->array[0] ;

        /**
         * find least
         */
        for(int i = 0 ; i < V ; i++)
            if(min->total_path > graph->array[i].total_path)
                min = &graph->array[i];

        if(test>0)
            printf("\n");

        printf("Case #%d %s",++test,min->name);
    }
}
