void displayList() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}