#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
    int x,y;
    struct QueueNode* next; // con tro tro den phan tu tiep theo trong Queue
    struct QueueNode* parent;// con tro tro den trang thai sinh ra trang thai hien tai
}Node;

Node* head;
Node* tail;
Node* start;
Node* target;
int visited[1000][1000];
int a,b,c;

Node* makeNode(int x, int y, Node* par){
    Node* p = (Node*) malloc(sizeof(Node));
    p->x = x; p->y = y; p->next = NULL; p->parent = par;
    return p;
}
void push(Node* s){
    if(head == NULL && tail  == NULL){
        head = s; tail = s; return;
    }
    tail->next = s; tail = s;
}
Node* pop(){
    Node* r = head;
    head = head->next;
    if(head == NULL) tail = NULL;
    return r;
}
int empty(){
    // return 1 if the queue is empty
    return head == NULL && tail == NULL;
}
void printQueue(){
    for(Node* p = head; p != NULL; p = p->next){
        printf("(%d,%d) ",p->x,p->y);
    }
    printf("\n");
}
int checkFinal(Node* s){
    if(s ->x == c || s-> y == c) return 1;
    return 0;
}
void solve(){
    for(int i = 0; i < 1000; i++)
        for(int j = 0; j < 1000;  j++)
            visited[i][j] = 0;
    head = NULL; tail = NULL;
    start = makeNode(0,0,NULL);
    push(start);
    visited[0][0] = 1; target = NULL;

    //int cnt = 0;
    while(!empty()){
        //cnt ++; if(cnt > 100) break;
        //printf("prepare pop\n");
        Node* s = pop();// current state s->x, s->y
       // printf("pop (%d,%d)\n",s->x,s->y);

        Node* ns = NULL;// next state
        // fill jug 1, next state (a, s->y)
        if(visited[a][s->y] == 0){
            ns = makeNode(a,s->y,s);
            if(checkFinal(ns)){
                 target = ns;
                break;
            }
            push(ns);   visited[ns->x][ns->y] = 1;// danh dau trang thai da duoc sinh ra
            //printf("push (%d,%d)\n",ns->x,ns->y); printQueue();
        }

        // fill jug 2, next state s->x, b
        if(visited[s->x][b] == 0){
            ns = makeNode(s->x,b,s);
            if(checkFinal(ns)){
                target  = ns;
                break;
            }
            push(ns);   visited[ns->x][ns->y] = 1;
            //printf("push (%d,%d)\n",ns->x,ns->y); printQueue();
        }

        // empty jug 1, next state 0, s->y
        if(visited[0][s->y] == 0){
            ns = makeNode(0,s->y,s);
            push(ns);   visited[ns->x][ns->y] = 1;
           // printf("push (%d,%d)\n",ns->x,ns->y); printQueue();
        }
        // empty jug 2, next state s->x, 0
        if(visited[s->x][0]==0){
            ns = makeNode(s->x, 0,s);
            push(ns);    visited[ns->x][ns->y] = 1;
           // printf("push (%d,%d)\n",ns->x,ns->y); printQueue();
        }
        //printf("OK");

        // pour jug 1 -> jug 2
        int nx, ny;
        if(s->x + s->y >= b){ // next state s->x + s->y - b, b
            nx = s->x + s->y - b; ny = b;
        }else{
            nx = 0; ny = s->x + s->y;
        }
        if(visited[nx][ny] == 0){
            ns = makeNode(nx,ny,s);
            if(checkFinal(ns)){
                    target = ns;
                break;
            }
            push(ns);    visited[ns->x][ns->y] = 1;
            //printf("push (%d,%d)\n",ns->x,ns->y); printQueue();
        }
        //printf("OK 1 -> 2");

        // pour jug 2 --> 1
        if(s->x + s->y >= a){
            nx = a; ny = s->x + s->y -a;
        }else{
            nx = s->x + s->y ; ny = 0;
        }
        if(visited[nx][ny] == 0){
            ns = makeNode(nx,ny,s);
            if(checkFinal(ns)){
                    target = ns;
                break;
            }
            push(ns);    visited[ns->x][ns->y] = 1;
            //printf("push (%d,%d)\n",ns->x,ns->y); printQueue();
        }

        //printf("OK 2-> 1");
    }

    if(target == NULL){
        printf("NOT FOUND\n");
    }else{
        Node* s = target;
        while(s != NULL){
            printf("(%d,%d)\n",s->x,s->y);
            s = s->parent;
        }
    }
}
int main(){
    a = 6; b = 8; c = 4;
    solve();
    return 0;
}

