#define MAX_SIZE 10000

struct Stack {
    char items[MAX_SIZE];
    int top;
};

typedef struct Stack stack;

void initializeStack(stack *s) {
    s->top = -1;
}

int isEmpty(stack *s) {
    return s->top == -1;
}

int isFull(stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(stack *s, char value) {
    if (isFull(s)) {
        printf("Stack is full\n");
    } else {
        s->items[++s->top] = value;
    }
}

char pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return '\0'; // Trả về ký tự null nếu stack rỗng
    } else {
        return s->items[s->top--];
    }
}

bool isValid(char* s) {
   stack parentheses;
   initializeStack(&parentheses);
   for(int i = 0; i < strlen(s); i++) {
       if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
           push(&parentheses, s[i]);
       } else if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
           if (isEmpty(&parentheses)) {
               return false; 
           }
           char check = pop(&parentheses);
           if ((s[i] == ')' && check != '(') ||
               (s[i] == '}' && check != '{') ||
               (s[i] == ']' && check != '[')) {
               return false; 
           }
       }
    }
    return isEmpty(&parentheses);
}
