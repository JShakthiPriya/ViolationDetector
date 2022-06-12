//queue

//linked list impl
//only front pointer
//enqueue - loop to get last node
//dequeue - l->head = l->head->next
//dequeue does not free, returns first node

struct Node{
    int val;
    struct Node* link;
};

struct Queue{
    struct Node* front;
};

struct Queue* createQueue(void){
    struct Queue* q = malloc(sizeof(struct Queue)); 
    if (q != NULL)
        q->front = NULL; 
    return q;        
}

void enQueue(struct Queue *q, int data){
	struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
	struct Node* cur = q->front;
	new_node->val = data;
	new_node->link = NULL;
	if(!q->front){
	    q->front = new_node; 
	}
	else{
	    while(cur->link){
	        cur = cur->link;
	    }
	    cur->link = new_node;
	}
}

struct Node* deQueue(struct Queue *q){
    struct Node* first = q->front;
    if(q->front){
        q->front = q->front->link;
    }
    return first;
}

void show_queue (struct Queue *q)
{
    struct Node *tmp;

    if (q != NULL)
    {
        for (tmp = q->front; tmp != NULL; tmp=tmp->link)
            printf ("%d ", tmp->val);
    }
    printf("\n");
}

int main(){
    struct Queue* q = createQueue();
    int val;
    
    printf("enqueue:\n");
    enQueue(q, 10);
    show_queue(q);
    enQueue(q, 5);
    show_queue(q);
    enQueue(q, 2);
    show_queue(q);
    enQueue(q, 15);
    show_queue(q);
    
    printf("dequeue:\n");
    deQueue(q);
    show_queue(q);
    deQueue(q);
    show_queue(q);
    deQueue(q);
    show_queue(q);
    deQueue(q);
    show_queue(q);
}

