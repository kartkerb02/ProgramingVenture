for(auto x : link[root->data]){
            link[x->data].erase(find(link[x->data].begin(),link[x->data].end(),root->data));
        }