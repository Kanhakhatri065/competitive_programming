#include <bits/stdc++.h>

#define ELEMENTS 110
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int>   vi;

vector<vi> opinionGraph;
int parent[ELEMENTS];
int ranks[ELEMENTS];

void make_sets(int number_of_elements)
{
    int i;
    for(i = 0; i < number_of_elements; i++)
    {
        parent[i] = i;
        ranks[i] = 1;
    }
}

int find_set(int element)
{
    if(element != parent[element])
        parent[element] = find_set(parent[element]);
    return parent[element];
}

void set_union(int x, int y)
{
    int rx, ry;
    rx = find_set(x);
    ry = find_set(y);
    if(rx == ry)
        return;
    if(ranks[rx] > ranks[ry])
    {
        ranks[rx] += ranks[ry];
        parent[ry] = rx;
    }
    else
    {
        ranks[ry] += ranks[rx];
        parent[rx] = ry;
    }
}

void read_graph()
{
    //opinionGraph.clear();
    string str;
    stringstream ss;
    int people, tree, data;

    while(getline(cin,str))
    {   int flag = 0;
        if(str.size() == 0)
           return;
        ss<<str;
        while(ss>>data)
        {
            if(!flag)
            {
                people = data;
                flag = 1;
            }
            else
                tree = data;
        }
        ss.clear();
        //cout<<people<<"  "<<tree <<people*2<<endl;
        opinionGraph[people-1].insert(tree-1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int casos,people, trees;
    string trash;

    scanf("%d", &casos);
    getline(cin,trash);//Reading until en of line after casos
    getline(cin,trash);//Reading the first empty line
    while(casos--)
    {
        scanf("%d %d",&people, &trees);
        opinionGraph.assign(people, vi());
        getline(cin,trash);
        read_graph();

        //Strating union find
        make_sets(people);
        for(int x=0 ; x<opinionGraph.size(); x++) {
            for(int y=x+1 ; y<opinionGraph.size(); y++) {
                if(opinionGraph[x] == opinionGraph[y]) {
                set_union(parent[x], parent[y]);
                }
            }
        }

        for(int g=0; g<people; g++)
            parent[g] = find_set(g);

        int total = 0;
        set<int>answer;
        for(int h=0; h<people; h++)
            answer.insert(parent[h]);

        printf("%d\n",answer.size());
        if(casos)
        printf("\n");
    }
    
    return 0;
}