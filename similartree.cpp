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

 bool similar_tree(node*root1,node*root2){

    if(root1->children.size()!=root2->children.size()){
        return false;
    }
    for(int i=0;i<root1->children.size();i++){
        node*c1=root1->children[i];
        node*c2=root2->children[i];
        bool ans=similar_tree(c1,c2);
        if(ans==false){
            return false;
        }

    }
    return true;
 }
int main(){
       vector <int> arr;
       vector<int>arr2;
       arr.assign({10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1});
         arr2.assign({10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1});
       
        node*root1=construct_tree(arr);
        node*root2=construct_tree(arr2);
       cout<<similar_tree(root1,root2);


}