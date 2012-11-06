// Code for fractional knapsack

#include<iostream>
#include<stdio.h>
#include<utility>
#include<algorithm>

using namespace std;
typedef struct item
{
    int weight;
    int value;
}item;  
int compare(const void *x, const void *y)
{
    item *i1 = (item *)x, *i2 = (item *)y;
    double ratio1 = (*i1).value*1.0 / (*i1).weight;
    double ratio2 = (*i2).value*1.0 / (*i2).weight;
    if(ratio1 < ratio2) return 1;
    else if(ratio1 > ratio2) return -1;
    else return 0;
}


int main(){
    int max_weight=0,i=0,j=0,size=0,ratio[100];
    float value = 0;
    cout<<"\nEnter number of items : ";
    cin>>size;
    item item_[size];
    cout<<"\nEnter Item weights and values:\n";
    for(i=0;i<size;i++){
        cin>>item_[i].weight;
        cin>>item_[i].value;
        // ratio[i] = (item_value[i]/item_weight[i]);
    }
    qsort(item_,size,sizeof(item_),compare);
    cout<<"\nEnter max weight of the knapsack :";
    cin>>max_weight;
    cout<<endl;
    int current_weight=0,remaining_weight=0;
    for(i=0;i<size;i++) {
        if((current_weight+=item_[i].weight) < max_weight) {
            value += item_[i].value;
        }
        else {
            current_weight-= item_[i].weight;
            remaining_weight = max_weight - current_weight;
            int flag = 0;
            while(flag < item_[i].weight && current_weight < max_weight) {
                value += (remaining_weight * item_[i].value * 1.0)/item_[i].weight;
                current_weight++;
                remaining_weight--;
                flag++;
            }
            break;

        }
    }
    cout<<"Max value possible is : " <<value<<endl;

    return 0;
}
