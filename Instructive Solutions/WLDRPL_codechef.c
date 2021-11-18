#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
  int maxvalue;
  int minvalue;
  int is_opening_bracket;
  int is_plus;
  int is_minus;
};

struct StackNode {
  struct Item* data;
  struct StackNode* next;
};

struct Item* newItem() {
  struct Item* current_item = (struct Item*) malloc(sizeof(struct Item));
  current_item->maxvalue = 0;
  current_item->minvalue = 0;
  current_item->is_opening_bracket = 0;
  current_item->is_plus = 0;
  current_item->is_minus = 0;
  return current_item;
}

struct StackNode* newStackNode(struct Item* data) {
  struct StackNode* stack_node = (struct StackNode*) malloc(sizeof(struct StackNode));
  stack_node->data = data;
  stack_node->next = NULL;
  return stack_node;
}

int isEmpty(struct StackNode* root) {
  return !root;
}

void push(struct StackNode** root, struct Item* data) {
  struct StackNode* stack_node = newStackNode(data);
  stack_node->next = *root;
  *root = stack_node;
}

void pop(struct StackNode** root) {
  if (isEmpty(*root)) return;
  struct StackNode* temp = *root;
  *root = (*root)->next;
  free(temp);
}

struct Item* top(struct StackNode* root) {
  if (isEmpty(root)) return NULL;
  return root->data;
}

char s[1000006];

void solve() {
  scanf("%s", s);
  int n = strlen(s);
  int* ans = (int*) malloc(sizeof(int) * n);
  struct StackNode* root = NULL;
  for (int i = 0; i < n; i++) {
    struct Item* current_item = newItem();
    if (s[i] == '?') {
      current_item->maxvalue = 1;
    } else if (s[i] == '(') {
      current_item->is_opening_bracket = 1;
    } else if (s[i] == '+') {
      current_item->is_plus = 1;
    } else if (s[i] == '-') {
      current_item->is_minus = 1;
    } else if (s[i] == ')') {
      struct Item* second_operand = top(root);
      pop(&root);
      struct Item* operator = top(root);
      pop(&root);
      struct Item* first_operand = top(root);
      pop(&root);
      pop(&root);
      if (operator->is_minus) {
        current_item->maxvalue = first_operand->maxvalue - second_operand->minvalue;
        current_item->minvalue = first_operand->minvalue - second_operand->maxvalue;
      } else {
        current_item->maxvalue = first_operand->maxvalue + second_operand->maxvalue;
        current_item->minvalue = first_operand->minvalue + second_operand->minvalue;
      }
      ans[i] = current_item->maxvalue;
    }
    push(&root, current_item);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    r--;
    if (l == r) {
      printf("1 ");
    } else {
      printf("%d ", ans[r]);
    }
  }
  printf("\n");
}

int main() {
  int test;
  scanf("%d", &test);
  while (test--) solve();
  return 0;
} 
