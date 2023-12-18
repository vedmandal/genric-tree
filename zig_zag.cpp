#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
 void zig_zag(node*root){
    queue<node*>q;
    q.push(root);
    int level=1;
    while(q.size()>0){
        int s=q.size();
        while(s-->0){
            node*temp=q.front();
            q.pop();
            cout<<temp->val<<" ";
            if(level%2==1){
                for(node*child:temp->children){
                    q.push(child);
                }

            }else{
                for(int i=temp->children.size()-1;i>=0;i--){
                    q.push(temp->children[i]);
                }
            }
        }
        cout<<endl;
        level++;

    }


 }

int main(){
       vector <int> arr;
       arr.assign({10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1});
        
        node*root=construct_tree(arr);
       zig_zag(root);


}