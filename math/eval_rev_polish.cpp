class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            string ch=tokens[i];
            if(ch=="+"){
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                st.push(n2+n1);
            }else if(ch=="*"){
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                st.push(n1*n2);
            }else if(ch=="-"){
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                st.push(n2-n1);
            }else if(ch=="/"){
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                st.push(n2/n1);
            }else{
                int num = stoi(ch);
                st.push(num);
            }
        }

        return st.top();
    }
};