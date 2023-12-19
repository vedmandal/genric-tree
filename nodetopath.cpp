#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class node{
    public:
    int val;
    vector<node*>children;
    node(int val){
        this->val=val;
    }
};
node*construct_tree(vector<int>&arr){
    stack<node*>st;
    node*root=NULL;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==-1){
            st.pop();
        }else{
            node*temp=new node(arr[i]);
            if(st.size()==0){
                root=temp;

            }else{
                st.top()->children.push_back(temp);
            }
            st.push(temp);


        }
    }
    return root;

}
void display(node*root){
    string str=to_string(root->val)+"->";
    for(node*child:root->children){
       str+=to_string(child->val)+",";
    }
    str+=".";
    cout<<str<<endl;
    for(node*child:root->children){
        display(child);
    }
    


}

vector<int> node_to_path(node*root,int val){
    if(root->val==val){
        vector<int>ans;
        ans.push_back(root->val);
        return ans;

    }
    for(node*child:root->children){
        vector<int>ans=node_to_path(child,val);
        if(ans.size()>0){
            ans.push_back(root->val);
            return ans;

        }
    }
    return {};
    
    
}
int main(){
       vector <int> arr;
       arr.assign({10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1});
        
        node*root=construct_tree(arr);
     vector<int>ans= node_to_path(root,110);
     for(int val:ans){
        cout<<val<<" ";
     }


}