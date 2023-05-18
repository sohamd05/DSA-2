typedef struct node
{
    int data;
    int BF;
    struct node* parent, *left, *right;
} node;

typedef node* AVL;

void initAVL(AVL* t);
void insertToAVL(AVL *t, int data);
void inorder(AVL t);
void adjustTree(AVL *t, node* nn);
int height(AVL t);
void destroyTree(AVL *p);
node* FindImbalance(AVL t);
void updateBalanceFactor(AVL *t);
void deleteRecursive(AVL *t, int key);
void LLRotation(AVL* t, node *A);
void LRRotation(AVL* t, node *A);
void RLRotation(AVL* t, node *A);
void RRRotation(AVL* t, node *A);
