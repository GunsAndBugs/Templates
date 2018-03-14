
// trie code . modified from Shafaet's planet . 
// tested problems: UVA (UVA 11362 Phonebook), UVA 11488 Hyper prefix sets
class trie{
				public:
				struct node {
				    bool endmark; // kono word shesh hoise kina ei node e 
				    ll f; // ei node hoye koyta string geche.
				    node* next[26 + 1]; // ith character paoa gese kina
				    node()
				    {
				        endmark = false;
				        f = 0;
				        for (int i = 0; i < 26; i++)
				            next[i] = NULL;
				    }
				} *root;

				trie(){
					root = new node;
				}
				public:
				void insert(char* str)
				{
				    node* curr = root;
				    for (int i = 0;  str[i] ; i++) {
				        int id = str[i] - '0';
				        if (curr->next[id] == NULL)
				            curr->next[id] = new node();
				        curr = curr->next[id];
				        curr->f =  (curr->f) + 1; // koyta string gelo count rakhtesi
				    }
				    curr->endmark = true; // ei node e eshe ekta string shesh hoise
				}
				ll search(char* str, int prefixallow = 0 )
				{
				    node* curr = root;
				    ll mx = 0;
				    for (int i = 0;  str[i] ; i++) {
				        int id = str[i] - '0';
				        if (curr->next[id] == NULL)
				            return false;
				        curr = curr->next[id];
				        // if prefix allow then write here.....
				    }
				    
				    return curr->endmark;
				}

				//dfs can be operated in this style 
				void del(node* cur)
				{
				    for (int i = 0; i < 26; i++)
				        if (cur->next[i])
				            del(cur->next[i]);

				    delete (cur);
				}

				~trie(){
					del( root );
				}


		};
