typedef struct node
{
    int x;
    int y;
    int value;
    struct node* right;
    struct node* down;
}node;

typedef struct queue
{
    int x;
    int y;
    struct node *first, *last;   
}queue;

queue* create_queue();
void rightNode(node**, int, int, int);
void downNode(node* );
node* calc(node*, int[][10]);
queue* find(node*, queue*, int[][10]);
void store(queue*);