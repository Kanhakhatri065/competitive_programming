#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

/*----------------------------------------------------------------*/
#define TEMP 0
#define PERM 1
#define infinity 9999

struct node
{
	int predecessor;
	int dist; 
	int status;
};

int findpath(int s,int d,int path[],int *sdist, int n, vector<vector<int>> adj)
{
	struct node state[n + 1];
	int i,min,count=0,current,newdist,u,v;
	*sdist=0;
	for(i=1;i<=n;i++)
	{
		state[i].predecessor=0;
		state[i].dist = infinity;
		state[i].status = TEMP;
	}

	state[s].predecessor=0;
	state[s].dist = 0;
	state[s].status = PERM;

	current=s;
	while(current!=d)
	{
		for(i=1;i<=n;i++)
		{
			if ( adj[current][i] > 0 && state[i].status == TEMP )
			{
				newdist=state[current].dist + adj[current][i];
				
				if( newdist < state[i].dist )
				{
					state[i].predecessor = current;
					state[i].dist = newdist;
				}
			}
		}

		
		min=infinity;
		current=0;
		for(i=1;i<=n;i++)
		{
			if(state[i].status == TEMP && state[i].dist < min)
			{
				min = state[i].dist;
				current=i;
			}
		}

		if(current==0) 
			return 0;
		state[current].status=PERM;
	}

	while( current!=0 )
	{
		count++;
		path[count]=current;
		current=state[current].predecessor;
	}

	for(i=count;i>1;i--)
	{
		u=path[i];
		v=path[i-1];
		*sdist+= adj[u][v];
	}
	return (count);
}

ll power(ll a, ll n, ll p) 
{ 
    int res = 1; 
    a = a % p;   
  
    while (n > 0) 
    { 
        if (n & 1) 
            res = (res*a) % p; 
  
        n = n>>1;  
        a = (a*a) % p; 
    } 
    return res; 
} 
  
ll gcd(ll a, ll b) 
{ 
    if(a < b) 
        return gcd(b, a); 
    else if(a%b == 0) 
        return b; 
    else return gcd(b, a%b);   
} 
  
bool isPrime(ll n, int k) { 
   if (n <= 1 || n == 4)  return false; 
   if (n <= 3) return true; 
  
   while (k>0) { 
       int a = 2 + rand()%(n-4);   
  
       if (gcd(n, a) != 1) 
          return false; 
   
       if (power(a, n-1, n) != 1) 
          return false; 
  
       k--; 
    } 
  
    return true; 
} 

ll minPrime(ll number, ll lastPrime) {
    for(ll i = lastPrime + 1;i <= sqrt(number);i++) {
        if(isPrime(i,2)) {
            return i;
        }
    }
    
    return number;
}

vector<ll> check(ll x) {
    int temp = x;
    vector<ll> counts;
    int counter = 0;
    int pr = 2;
    while(temp != 1) {
        if(temp % pr == 0) {
            temp /= pr;
            counter++;
        } else {
            pr = minPrime(temp, pr);
            counts.push_back(counter);
            counter = 0;
        }
    }

    if(counter != 0) {
        counts.push_back(counter);
    }
    
    return counts;
}

int main() {
    FAST_IO

    int testcases;
    scanf("%d", &testcases);

    int number, queries;
    while(testcases--) {

        cin >> number;

        
        vector<vector<int>> graph(number + 1, vector<int>(number + 1, 0));


        int city_a, city_b;
        for(int i = 1;i < number;i++) {
            scanf("%d", &city_a);
            scanf("%d", &city_b);
            graph[city_a][city_b] = 1;
            graph[city_b][city_a] = 1;
        }

        vector<ll> cost(number, 0);
        for(int i = 0;i < number;i++) {
            scanf("%lld", &cost[i]);
        }

        map<pair<int,int>, vector<int>> m;
        for(int i = 1;i < number;i++) {
            for(int j = i + 1;j <= number;j++) {
                int path[number + 1];
                int shortestdistance, count;
                count = findpath(i, j, path, &shortestdistance, number, graph);
                vector<int> temp;
                for(int k = count;k >=1;k--) {
                    temp.push_back(path[k]);
                }
                m[make_pair(i, j)] = temp;
            }
        }

        cin >> queries;
        for(int i = 0;i < queries;i++) {
            cin >> city_a >> city_b;
            ll product = 1;

            if(city_a != city_b) {
                int first;
                int second;
                if(city_a > city_b) {
                    first = city_a;
                    second = city_b;
                } else {
                    first = city_b;
                    second = city_a;
                }

                map<pair<int,int>, vector<int>>::iterator it;
                it = m.find(make_pair(first, second));
                if(it != m.end()) {
                    if(it->second.empty()) {
                    cout << "0" << endl;
                    } else {
                        cout << it->second.size() << endl;
                        for(int j = 0;j < it->second.size();j++) {
                            cout << it->second[j] << " ";
                            product *= cost[it->second[j] - 1];
                        }
                    }
                } else {
                    cout << "NO SUCH PATH" << endl;
                }
            } else {
                product *= cost[city_a - 1];
            }
            
            vector<ll> counts = check(product);
            ll factors = 1;
            for(ll j = 0;j < counts.size();j++) {
                factors *= (counts[j] + 1);
            }

            printf("%lld\n", (factors % 1000000007));
        }
    } 
    return 0;
}