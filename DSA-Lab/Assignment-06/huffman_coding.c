// Program to implement huffman coding

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct huffmanTree {
    char ch;
    int freq;
    struct huffmanTree *left;
    struct huffmanTree *right;
} htree;

htree* heap[100];
int heapSize=0;
void insert(htree *);
htree* deleteMin();
void print(htree *, char *);

int main() {
    heap[0] = malloc(sizeof(htree));
    heap[0]->freq = 0;
    char str[100]; printf("Enter the message string (lowercase ASCII): ");
    scanf(" %s", str);
    int freq[26], dis = 0;
    memset(freq, 0, 26*sizeof(int));
    for(int i=0; str[i]!='\0'; ++i) { 
        ++freq[str[i]-'a']; 
        if(freq[str[i]-'a']==1) ++dis;    
    }

    for(int i=0; i<26; ++i) {
        if(!freq[i]) continue;
        printf("Char: %c Frequency: %d\n", i+'a', freq[i]);
        htree *temp = malloc(sizeof(htree));
        temp->ch = i+'a';
        temp->freq = freq[i];
        temp->left = temp->right = NULL;
        insert(temp);
    }
    if(dis==1) {
        printf("char %c code 0\n",str[0]);
        return 0;
    }
    for(int i=0;i<dis-1 ;i++) {
        htree *left = deleteMin();
        htree *right = deleteMin();
        htree *temp = malloc(sizeof(htree));
        temp->ch = 0;
        temp->left = left;
        temp->right = right;
        temp->freq = left->freq + right->freq;
        insert(temp);
    }
    htree *tree = deleteMin();
    char code[10] = "";
    puts("");
    print(tree,code);
    return 0;
}

void insert(htree *elem) {
    heapSize++;
    heap[heapSize] = elem;
    int cur = heapSize;
    while(heap[cur/2]->freq > elem->freq) {
        heap[cur] = heap[cur/2];
        cur/= 2;
    }
    heap[cur] = elem;
}

htree* deleteMin() {
    htree *min, *last;
    int child, cur;
    min = heap[1];
    last = heap[heapSize--];
    for(cur = 1; cur*2 <= heapSize; cur = child) {
        child = cur*2;
        if(child != heapSize && heap[child+1]->freq < heap[child]->freq)  ++child;
        if(last->freq > heap[child]->freq)   heap[cur] = heap[child];
        else    break;
    }
    heap[cur] = last;
    return min;
}

void print(htree *node, char *code) {
    if(node->left==NULL && node->right==NULL) {
        printf("Char: %c Code: %s\n", node->ch, code);
        return ;
    }
    char left[10],right[10];
    strcpy(left,code); strcat(left, "0");
    strcpy(right,code); strcat(right, "1");
    print(node->left,left);
    print(node->right,right);
}