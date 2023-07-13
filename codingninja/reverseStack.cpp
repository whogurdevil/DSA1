
void insertatbottom(stack<int>& st, int x){
    if(st.empty()){
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();

    insertatbottom(st, x);

    st.push(temp);
}

void reverseStack(stack<int> &stack) {
    if(stack.empty()) {
        return;
    }

    int temp = stack.top();
    stack.pop();

    reverseStack(stack);

    insertatbottom(stack, temp);
}