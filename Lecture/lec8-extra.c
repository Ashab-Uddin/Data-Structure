
struct Item {
    int data;
    struct Item *next;
}; 


int main () {
    struct Item it, it1;
    it.data = 24;
    it.next = &it1;
    
    printf ("%d \n", it.data);
    
    (it.next)->data = 45;
    
    printf ("%d %d\n", it1.data, (it.next)->data);
    
    return 0;
}
