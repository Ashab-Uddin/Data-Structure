void DeleteAny() {
    struct node *temp;
    int pos, i = 1;

    // Prompt the user for the position
    printf("Enter the position you want to delete: ");
    scanf("%d", &pos);

    // Check if the position is valid
    if (pos < 1) {
        printf("Invalid position. Please enter a position greater than 0.\n");
        return;
    }

    // If deleting the first node
    if (pos == 1) {
        DeleteFromBeg();
        return;
    }

    // Initialize temp to head
    temp = head;

    // Traverse to the desired position
    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }

    // If temp is NULL, it means the position is out of range
    if (temp == NULL) {
        printf("Position out of range. Unable to delete.\n");
        return;
    }

    // If the position corresponds to the last node, delete it using DeleteEnd
    if (temp->next == NULL) {
        DeleteEnd();
        return;
    }

    // General case: Deleting a node that is not the first or last
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
