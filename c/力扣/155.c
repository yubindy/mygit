typedef struct MinStack { 
    int val;
    int min;
    struct MinStack * next;
} MinStack, *pMinStack;

MinStack* minStackCreate() {
    pMinStack stack = (pMinStack)malloc(sizeof(MinStack));
    stack->next = NULL;
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    pMinStack temp = (pMinStack)malloc(sizeof(MinStack));
    temp->val = x;
    if( obj->next == NULL){        
        temp->min = x;
        obj ->min = 0;
    }else {
        temp->min = ((temp->val) > (obj->next->min)) ? (obj->next->min) : (temp->val);
    }
    temp->next = obj->next; 
    obj->next = temp;
}

void minStackPop(MinStack* obj) {
    pMinStack temp = obj->next;
    obj->next = obj->next->next;
    free(temp);
    temp = NULL;
}

int minStackTop(MinStack* obj) {
    return obj->next->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->next->min;
}

void minStackFree(MinStack* obj) {
    free(obj);
    obj = NULL;
}

