#include <iostream>

using namespace std;

int main(){
    int distance;
    cin >> distance;

    int oc, of, od;
    cin >> oc >> of >> od;

    int cs,cb,cm, cd;
    cin >> cs >>cb >> cm >> cd;

    int online_cost = oc + ((distance - of) * od);
    int classic_cost = cb + ((distance/ cs) * cm) + (distance * cd);

    if(online_cost <= classic_cost){
        cout << "Online Taxi" << endl;
    } else {
        cout << "Classic Taxi" << endl;
    }

    return 0;
}