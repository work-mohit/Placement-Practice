#include<queue>
class node
{
	public:
    	int data;
    	int i; 
    	int j;
    	
    	node(int data, int row , int col){
            this-> data = data;
            i = row;
            j = col;
        }
};

class Compare
{
public:
    bool operator()(node* a , node* b)
    {
        return a->data > b->data;
    }
};


vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node* , vector<node*> , Compare> minHeap;
    vector<int> ans;
    // step 1:
    // put all the first element in the heap 
    for(int i = 0; i< k ; i++){
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }
   	
    while(minHeap.size() > 0){
        node* temp = minHeap.top();
        minHeap.pop();
        ans.push_back(temp->data);
        int i = temp -> i;
        int j = temp -> j;
        
        if(j+1 < kArrays[i].size()){
            node* newnode = new node(kArrays[i][j+1] , i , j+1);
            minHeap.push(newnode);
        }
    }
    return ans;
    
    
    
}
